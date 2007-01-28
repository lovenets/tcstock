#include "tcmarket.h"

#include <QtCore/QTextStream>
#include <QtGui/QMessageBox>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

#include "../tcdefine.h"
#include "../service/tcsvcpack.h"
#include "tcstockinfodlg.h"

#define STOCKS_XML_FILE "stocks.xml"

tcMarket::tcMarket(const QDir &pPath)
{
	mPath = pPath;
	mStockDataCache = new tcStockDataCache(pPath);
	mIndex = -1;
}

tcMarket::~tcMarket()
{
	ClearAllStocks();
	delete mStockDataCache;
}

bool tcMarket::LoadFromFile()
{
	ClearAllStocks();

	QFileInfo fileinfo(mPath, STOCKS_XML_FILE);
	QFile file(fileinfo.filePath());
	if (! file.open(QIODevice::ReadOnly)) {
		tcLogService::CreateLog(this, "Can not open stocks file.");
		return false;
	}

	QDomDocument doc;
	if (! doc.setContent(&file, true)) {
		file.close();
		tcLogService::CreateLog(this, "Can not load stocks file.");
		return false;
	}
	file.close();

	QDomElement element = doc.documentElement();
	//load marker info
	QDomNode node = element.namedItem("Market");
	if (! node.isElement()) {
		tcLogService::CreateLog(this, "Stocks file format error.");
		return false;
	}
	QDomElement marketelement = node.toElement();
	mName = marketelement.attribute("Name");
	mDescription = marketelement.attribute("Description");

	//load stock info
	node = element.namedItem("Stocks");
	if (! node.isElement()) {
		tcLogService::CreateLog(this, "Stocks file format error.");
		return false;
	}
	QDomElement stockselement = node.toElement();

	int count, i;
	count = stockselement.attribute("Count").toInt();
	QString nodename = "Stock_%1";
	for (i=0; i<count; i++) {
		node = stockselement.namedItem(nodename.arg(i));
		if (! node.isElement()) {
			tcLogService::CreateLog(this, "Stocks file format error.");
			return false;
		}
		QDomElement selement = node.toElement();
		tcStock *stock = new tcStock(mStockDataCache);
		if (! stock->LoadFromXml(selement)) {
			delete stock;
			tcLogService::CreateLog(this, "Can not load stock.");
			return false;
		}
		if (mStockMap.contains(stock->GetStockCode())) {
			delete stock;
			tcLogService::CreateLog(this, "The same code of stock already exists.");
			return false;
		}
		mStockMap.insert(stock->GetStockCode(), stock);
	}
	return true;
}

bool tcMarket::SaveToFile()
{
	QFileInfo fileinfo(mPath, STOCKS_XML_FILE);
	QFile file(fileinfo.filePath());
	if (! file.open(QIODevice::WriteOnly)) {
		tcLogService::CreateLog(this, "Can not open stocks file.");
		return false;
	}

	QDomDocument doc;
	//QDomNode node = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"GB2312\"");
	//doc.appendChild(node);

	QDomElement syselement = doc.createElement(SYSTEM_NAME);
	doc.appendChild(syselement);

	//save market info
	QDomElement marketelement = doc.createElement("Market");
	syselement.appendChild(marketelement);
	marketelement.setAttribute("Name", mName);
	marketelement.setAttribute("Description", mDescription);

	//save stock info
	QDomElement stockselement = doc.createElement("Stocks");
	syselement.appendChild(stockselement);
	stockselement.setAttribute("Count", mStockMap.count());
	QString nodename = "Stock_%1";
	int index = 0;
	foreach (tcStock *stock, mStockMap) {
		QDomElement selement = doc.createElement(nodename.arg(index));
		stockselement.appendChild(selement);
		if (! stock->SaveToXml(doc, selement)) {
			tcLogService::CreateLog(this, "Can not save stock.");
			return false;
		}
		index ++;
	}

	QTextStream stream(&file);
	doc.save(stream, 4);
	file.close();
	return true;
}

bool tcMarket::SaveAllStockData()
{
	return mStockDataCache->SaveAllStockData();
}

tcStock* tcMarket::AppendStock(const QString &pStockCode, const QString &pStockName)
{
	if (mStockMap.contains(pStockCode) != NULL) {
		tcLogService::CreateLog(this, "The stock code already exists.");
		return NULL;
	}
	tcStock *stock = new tcStock(mStockDataCache);
	stock->SetStockCode(pStockCode);
	stock->SetStockName(pStockName);
	mStockMap.insert(pStockCode, stock);
	return stock;
}

tcStock* tcMarket::AppendStock(QWidget *pParent)
{
	tcStockInfoDialog dlg(pParent, this, true);
	if (dlg.exec() != QDialog::Accepted) {
		return NULL;
	}
	tcStock *stock = new tcStock(mStockDataCache);
	if (! dlg.SaveToStock(stock)) {
		delete stock;
		tcLogService::CreateLog(this, "Error when save stock info.");
		return NULL;
	}
	if (mStockMap.contains(stock->GetStockCode())) {
		delete stock;
		tcLogService::CreateLog(this, "The sotck with the same code already exists.");
		return NULL;
	}
	mStockMap.insert(stock->GetStockCode(), stock);
	emit OnStockModified();
	return stock;
}

tcStock* tcMarket::ModifyStock(QWidget *pParent, const QString &pStockCode)
{
	tcStock *stock = GetStockByCode(pStockCode);
	if (stock == NULL) {
		tcLogService::CreateLog(this, "Not found the stock.");
		return NULL;
	}
	tcStockInfoDialog dlg(pParent, this, false);
	if (! dlg.LoadFromStock(stock)) {
		tcLogService::CreateLog(this, "Error when load stock info.");
		return NULL;
	}
	if (dlg.exec() != QDialog::Accepted) {
		return NULL;
	}
	if (! dlg.SaveToStock(stock)) {
		tcLogService::CreateLog(this, "Error when save stock info.");
		return NULL;
	}
	emit OnStockModified();
	return stock;
}

bool tcMarket::RemoveStock(QWidget *pParent, const QString &pStockCode)
{
	tcStock *stock = GetStockByCode(pStockCode);
	if (stock == NULL) {
		tcLogService::CreateLog(this, "Not found the stock.");
		return false;
	}
	if (QMessageBox::question(pParent, SYSTEM_NAME, tr("Are you sure to remove this stock?"), QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel) {
		return false;
	}
	delete stock;
	mStockMap.remove(pStockCode);
	emit OnStockModified();
	return true;
}

bool tcMarket::GetStockInfoList(tcStockInfoList *pStockInfoList)
{
	foreach (tcStock *stock, mStockMap) {
		tcStockInfo info(mIndex, stock->GetStockCode());
		pStockInfoList->append(info);
	}
	return true;
}

bool tcMarket::GetStockInfoListFilter(tcStockInfoList *pStockInfoList, const QString &pStockCodeFilter, const QString &pStockNameFilter)
{
	foreach (tcStock *stock, mStockMap) {
		if (pStockCodeFilter.length() > 0 && stock->GetStockCode().indexOf(pStockCodeFilter) < 0) {
			continue;
		}
		if (pStockNameFilter.length() > 0 && stock->GetStockName().indexOf(pStockNameFilter) < 0) {
			continue;
		}
		tcStockInfo info(mIndex, stock->GetStockCode());
		pStockInfoList->append(info);
	}
	return true;
}

void tcMarket::ClearAllStocks()
{
	foreach (tcStock *stock, mStockMap) {
		delete stock;
	}
	mStockMap.clear();
}

int tcMarket::GetIndex()
{
	return mIndex;
}

void tcMarket::SetIndex(int pValue)
{
	mIndex = pValue;
	emit OnIndexModified(mIndex);
}

QString tcMarket::GetName()
{
	return mName;
}

void tcMarket::SetName(const QString pName)
{
	mName = pName;
}

QString tcMarket::GetDescription()
{
	return mDescription;
}

void tcMarket::SetDescription(const QString &pDescription)
{
	mDescription = pDescription;
}

#ifdef WIN32
	#include "moc_tcmarket.cpp"
#endif
