#include "tcfavouritegrp.h"

#include <QtGui/QMessageBox>

#include "../tcdefine.h"
#include "../service/tcsvcpack.h"

tcFavouriteGroup::tcFavouriteGroup()
{
}

tcFavouriteGroup::~tcFavouriteGroup()
{
	ClearAllFavouriteStocks();
}

bool tcFavouriteGroup::LoadFromXml(const QDomElement &pElement)
{
	mGroupName = pElement.attribute("GroupName");

	QDomNode node = pElement.namedItem("Stock");
	if (! node.isElement()) {
		tcLogService::CreateLog(this, "xml file format error.");
		return false;
	}
	QDomElement stockelement = node.toElement();

	int count, i;
	count = stockelement.attribute("Count").toInt();
	QString nodename = "Stock_%1";
	for (i=0; i<count; i++) {
		node = stockelement.namedItem(nodename.arg(i));
		if (! node.isElement()) {
			tcLogService::CreateLog(this, "xml file format error.");
			return false;
		}
		QDomElement selement = node.toElement();
		tcFavouriteStockInfo *favourite = new tcFavouriteStockInfo(selement);	//initialize it by reading from xml file.
		mFavouriteStockList.append(favourite);
	}
	return true;
}

bool tcFavouriteGroup::SaveToXml(QDomDocument &pDoc, QDomElement &pElement)
{
	pElement.setAttribute("GroupName", mGroupName);

	QDomElement stockelement = pDoc.createElement("Stock");
	pElement.appendChild(stockelement);

	stockelement.setAttribute("Count", mFavouriteStockList.count());
	QString nodename = "Stock_%1";
	int index = 0;
	foreach (tcFavouriteStockInfo *favourite, mFavouriteStockList) {
		QDomElement selement = pDoc.createElement(nodename.arg(index));
		stockelement.appendChild(selement);
		if (! favourite->SaveToXml(pDoc, selement)) {
			tcLogService::CreateLog(this, "Can not save favourite stock.");
			return false;
		}
		index ++;
	}
	return true;
}

tcFavouriteStockInfo* tcFavouriteGroup::GetFavouriteStock(int pIndex)
{
	if (pIndex < 0 || pIndex >= mFavouriteStockList.count()) {
		return NULL;
	}
	return mFavouriteStockList[pIndex];
}

int tcFavouriteGroup::GetFavouriteStockCount()
{
	return mFavouriteStockList.count();
}

bool tcFavouriteGroup::IsFavouriteStockExists(const tcStockInfo &pStockInfo)
{
	foreach (tcFavouriteStockInfo *favourite, mFavouriteStockList) {
		if ((*favourite) == pStockInfo) {
			return true;
		}
	}
	return false;
}

tcFavouriteStockInfo* tcFavouriteGroup::AppendFavouriteStock(const tcStockInfo &pStockInfo)
{
	if (IsFavouriteStockExists(pStockInfo)) {	//not add twice if this stock alread exists
		return NULL;
	}
	tcFavouriteStockInfo *favourite = new tcFavouriteStockInfo(pStockInfo);
	mFavouriteStockList.append(favourite);
	return favourite;
}

bool tcFavouriteGroup::AppendFavouriteStock(QWidget *pParent)
{
	tcStockInfoList stockinfolist;
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	if (! marketmanager->SelectStock(pParent, &stockinfolist)) {	//show select stock dialog
		return false;
	}
	foreach (tcStockInfo info, stockinfolist) {
		if (IsFavouriteStockExists(info)) {	//not add twice if this stock alread exists
			continue;
		}
		tcFavouriteStockInfo *favourite = new tcFavouriteStockInfo(info);
		mFavouriteStockList.append(favourite);
	}
	emit OnFavouriteStockModified();
	return true;
}

bool tcFavouriteGroup::RemoveFavouriteStock(QWidget *pParent, int pIndex)
{
	if (pIndex < 0 || pIndex >= mFavouriteStockList.count()) {
		tcLogService::CreateLog(this, "Wrong favourite stock index.");
		return false;
	}
	//if (QMessageBox::question(pParent, SYSTEM_NAME, tr("Are you sure to remove this favourite stock?"), QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel) {
	//	return false;
	//}
	tcFavouriteStockInfo *favourite = mFavouriteStockList[pIndex];
	delete favourite;
	mFavouriteStockList.removeAt(pIndex);
	emit OnFavouriteStockModified();
	return true;
}

bool tcFavouriteGroup::GetStockInfoList(tcStockInfoList *pStockInfoList)
{
	foreach (tcFavouriteStockInfo *favourite, mFavouriteStockList) {
		tcStockInfo info(*favourite);
		pStockInfoList->append(info);
	}
	return true;
}

bool tcFavouriteGroup::GetStockInfoListFilter(tcStockInfoList *pStockInfoList, const QString &pStockCodeFilter, const QString &pStockNameFilter)
{
	foreach (tcFavouriteStockInfo *favourite, mFavouriteStockList) {
		if (pStockCodeFilter.length() > 0 && favourite->GetStockCode().indexOf(pStockCodeFilter) < 0) {
			continue;
		}
		if (pStockNameFilter.length() > 0 && favourite->GetStockName().indexOf(pStockNameFilter) < 0) {
			continue;
		}
		tcStockInfo info(*favourite);
		pStockInfoList->append(info);
	}
	return true;
}

QString tcFavouriteGroup::GetGroupName()
{
	return mGroupName;
}

void tcFavouriteGroup::SetGroupName(const QString &pValue)
{
	mGroupName = pValue;
}

QString tcFavouriteGroup::GetDescription()
{
	return mDescription;
}

void tcFavouriteGroup::SetDescription(const QString &pValue)
{
	mDescription = pValue;
}

void tcFavouriteGroup::ClearAllFavouriteStocks()
{
	foreach (tcFavouriteStockInfo *favourite, mFavouriteStockList) {
		delete favourite;
	}
	mFavouriteStockList.clear();
}

#ifdef WIN32
	#include "moc_tcfavouritegrp.cpp"
#endif
