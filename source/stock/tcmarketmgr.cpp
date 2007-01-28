#include "tcmarketmgr.h"

#include <QtCore/QTextStream>
#include <QtGui/QMessageBox>
#include <QtXml/QDomDocument>

#include "../tcdefine.h"
#include "../service/tcsvcpack.h"
#include "tcmarketlistdlg.h"
#include "tcmarketinfodlg.h"
#include "tcmarketselectdlg.h"
#include "tcstockselectdlg.h"
#include "tcstockdatainfodlg.h"

#define MARKETS_XML_FILE "markets.xml"

tcMarketManager::tcMarketManager(const QDir &pPath)
{
	mPath = pPath.absolutePath() + "/markets";
}

tcMarketManager::~tcMarketManager()
{
	ClearAllMarkets();
}

bool tcMarketManager::LoadFromFile()
{
	ClearAllMarkets();

	QFileInfo fileinfo(mPath, MARKETS_XML_FILE);
	QFile file(fileinfo.filePath());
	if (! file.open(QIODevice::ReadOnly)) {
		tcLogService::CreateLog(this, "Can not open markets file.");
		return false;
	}

	QDomDocument doc;
	if (! doc.setContent(&file, true)) {
		file.close();
		tcLogService::CreateLog(this, "Can not load markets file.");
		return false;
	}
	file.close();

	QDomElement element = doc.documentElement();
	QDomNode node = element.namedItem("Markets");
	if (! node.isElement()) {
		tcLogService::CreateLog(this, "Markets file format error.");
		return false;
	}
	QDomElement marketselement = node.toElement();

	int count, i;
	count = marketselement.attribute("Count").toInt();
	QString nodename = "Market_%1";
	for (i=0; i<count; i++) {
		QString pathstr = "%1/%2";
		QDir path(pathstr.arg(mPath.absolutePath()).arg(i));
		tcMarket *market = new tcMarket(path);
		market->SetIndex(i);
		if (! market->LoadFromFile()) {
			delete market;
			tcLogService::CreateLog(this, "Can not load market.");
			return false;
		}
		connect(market, SIGNAL(OnStockModified()), this, SLOT(DoStockModified()));
		mMarketList.append(market);
	}
	return true;
}

bool tcMarketManager::SaveToFile()
{
	QFileInfo fileinfo(mPath, MARKETS_XML_FILE);
	QFile file(fileinfo.filePath());
	if (! file.open(QIODevice::WriteOnly)) {
		tcLogService::CreateLog(this, "Can not open markets file.");
		return false;
	}

	QDomDocument doc;
	//QDomNode node = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"GB2312\"");
	//doc.appendChild(node);

	QDomElement syselement = doc.createElement(SYSTEM_NAME);
	doc.appendChild(syselement);

	QDomElement marketselement = doc.createElement("Markets");
	syselement.appendChild(marketselement);
	int count, i;
	count = mMarketList.count();
	marketselement.setAttribute("Count", count);
	QString nodename = "Market_%1";
	for (i=0; i<count; i++) {
		QDomElement melement = doc.createElement(nodename.arg(i));
		marketselement.appendChild(melement);
		tcMarket *market = mMarketList[i];
		melement.setAttribute("Name", market->GetName());
		if (! market->SaveToFile()) {
			tcLogService::CreateLog(this, "Can not save market.");
			return false;
		}
	}

	QTextStream stream(&file);
	doc.save(stream, 4);
	file.close();
	return true;
}

tcMarket* tcMarketManager::GetMarket(QWidget *pParent)
{
	tcMarketSelectDialog dlg(pParent);
	if (! dlg.LoadMarketList(this)) {
		tcLogService::CreateLog(this, "can not load market list.");
		return NULL;
	}
	if (dlg.exec() != QDialog::Accepted) {
		return NULL;
	}
	int index = dlg.GetSelectedMarketIndex();
	return GetMarket(index);
}

bool tcMarketManager::EditMarketList(QWidget *pParent)
{
	tcMarketListDialog dlg(pParent, this);
	dlg.exec();
	if (! SaveToFile()) {
		tcLogService::CreateLog(this, "Error when save market manager.");
		return false;
	}
	return true;
}

bool tcMarketManager::EditStockData(QWidget *pParent)
{
	tcStockDataInfoDialog dlg(pParent);
	dlg.exec();
	foreach (tcMarket *market, mMarketList) {
		if (! market->SaveAllStockData()) {
			tcLogService::CreateLog(this, "Error when save stock data.");
			return false;
		}
		if (! market->SaveToFile()) {
			tcLogService::CreateLog(this, "Error when save stock info.");
			return false;
		}
	}
	return true;
}

int tcMarketManager::GetMarketCount()
{
	return mMarketList.count();
}

tcMarket* tcMarketManager::AppendMarket(const QString &pName)
{
	QString pathstr = "%1/%2";
	QDir path(pathstr.arg(mPath.absolutePath()).arg(mMarketList.count()));
	if (! path.exists()) {
		if (! path.mkdir(path.absolutePath())) {
			tcLogService::CreateLog(this, "Can not create the path of market.");
			return NULL;
		}
	}
	tcMarket *market = new tcMarket(path);
	market->SetIndex(mMarketList.count());
	market->SetName(pName);
	connect(market, SIGNAL(OnStockModified()), this, SLOT(DoStockModified()));
	mMarketList.append(market);
	return market;
}

tcMarket* tcMarketManager::AppendMarket(QWidget *pParent)
{
	tcMarketInfoDialog dlg(pParent);
	if (dlg.exec() != QDialog::Accepted) {
		return NULL;
	}
	tcMarket *market = AppendMarket("");
	if (! market) {
		tcLogService::CreateLog(this, "Error when create market.");
		return NULL;
	}
	if (! dlg.SaveToMarket(market)) {
		delete market;
		tcLogService::CreateLog(this, "Error when save market info.");
		return NULL;
	}
	emit OnMarketModified();
	return market;
}

tcMarket* tcMarketManager::ModifyMarket(QWidget *pParent, int pIndex)
{
	tcMarket *market = GetMarket(pIndex);
	if (! market) {
		tcLogService::CreateLog(this, "Wrong market index.");
		return NULL;
	}
	tcMarketInfoDialog dlg(pParent);
	if (! dlg.LoadFromMarket(market)) {
		tcLogService::CreateLog(this, "Error when load market info.");
		return NULL;
	}
	if (dlg.exec() != QDialog::Accepted) {
		return NULL;
	}
	if (! dlg.SaveToMarket(market)) {
		tcLogService::CreateLog(this, "Error when save market info.");
		return NULL;
	}
	emit OnMarketModified();
	return market;
}

bool tcMarketManager::RemoveMarket(QWidget *pParent, int pMarketIndex)
{
	if (pMarketIndex < 0 || pMarketIndex >= mMarketList.count()) {
		tcLogService::CreateLog(this, "Wrong market index.");
		return false;
	}
	if (QMessageBox::question(pParent, SYSTEM_NAME, tr("Are you sure to remove this market?"), QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel) {
		return false;
	}
	tcMarket *market = mMarketList[pMarketIndex];
	market->SetIndex(-1);
	mMarketList.removeAt(pMarketIndex);
	//modify the other market's index.
	int index = 0;
	foreach (tcMarket *market, mMarketList) {
		market->SetIndex(index);
		index ++;
	}
	emit OnMarketModified();
	return true;
}

bool tcMarketManager::SelectStock(QWidget *pParent, tcStockInfoList *pStockInfoList)
{
	tcStockSelectDialog dlg(pParent);
	if (dlg.exec() != QDialog::Accepted) {
		return false;
	}
	if (! dlg.GetSelectedStockInfoList(pStockInfoList)) {
		tcLogService::CreateLog(this, "Error when get selected stock list.");
		return false;
	}
	return true;
}

bool tcMarketManager::GetStockInfoList(int pMarketIndex, tcStockInfoList *pStockInfoList)
{
	if (pMarketIndex < 0) {	//get all market's stocks
		foreach (tcMarket *market, mMarketList) {
			if (! market->GetStockInfoList(pStockInfoList)) {
				tcLogService::CreateLog(this, "Error when get stock info list.");
				return false;
			}
		}
		return true;
	}
	if (pMarketIndex >=0 && pMarketIndex < mMarketList.count()) {
		tcMarket *market = mMarketList[pMarketIndex];
		if (! market->GetStockInfoList(pStockInfoList)) {
			tcLogService::CreateLog(this, "Error when get stock info list.");
			return false;
		}
		return true;
	}
	return false;
}

bool tcMarketManager::GetStockInfoListFilter(int pMarketIndex, tcStockInfoList *pStockInfoList, const QString &pStockCodeFilter, const QString &pStockNameFilter)
{
	if (pMarketIndex < 0) {	//get all market's stocks
		foreach (tcMarket *market, mMarketList) {
			if (! market->GetStockInfoListFilter(pStockInfoList, pStockCodeFilter, pStockNameFilter)) {
				tcLogService::CreateLog(this, "Error when get stock info list.");
				return false;
			}
		}
		return true;
	}
	if (pMarketIndex >=0 && pMarketIndex < mMarketList.count()) {
		tcMarket *market = mMarketList[pMarketIndex];
		if (! market->GetStockInfoListFilter(pStockInfoList, pStockCodeFilter, pStockNameFilter)) {
			tcLogService::CreateLog(this, "Error when get stock info list.");
			return false;
		}
		return true;
	}
	return false;
}

void tcMarketManager::ClearAllMarkets()
{
	foreach(tcMarket* market, mMarketList) {
		delete market;
	}
	mMarketList.clear();
}

void tcMarketManager::DoStockModified()
{
	emit OnStockModified((tcMarket*)sender());
}

#ifdef WIN32
	#include "moc_tcmarketmgr.cpp"
#endif
