#include "tcstockinfo.h"

#include "../service/tcsvcpack.h"
#include "tcstockmgr.h"

tcStockInfo::tcStockInfo()
{
	mStockCode = "";
}

tcStockInfo::tcStockInfo(const QString &pStockCode)
{
	mStockCode = pStockCode;
}

tcStockInfo::tcStockInfo(const tcStockInfo &pInfo)
{
	mStockCode = pInfo.mStockCode;
}

tcStock* tcStockInfo::GetStock()
{
	tcStockManager *stockmanager = tcObjService::GetStockManager();
	tcStock *stock = stockmanager->GetStockByCode(mStockCode);
	if (stock == NULL) {
		tcLogService::CreateLog(this, "Error when get stock.");
		return stock;
	}
	return stock;
}

QString tcStockInfo::GetStockCode()
{
	return mStockCode;
}

tcStockInfo& tcStockInfo::operator=(const tcStockInfo &pInfo)
{
	mStockCode = pInfo.mStockCode;
	return *this;
}

bool tcStockInfo::operator==(const tcStockInfo &pInfo)
{
	if (mStockCode != pInfo.mStockCode) {
		return false;
	}
	return true;
}

QString tcStockInfo::GetStockName()
{
	tcStock *stock = GetStock();
	if (stock == NULL) {
		return "";
	}
	return stock->GetStockName();
}

QString tcStockInfo::GetDescription()
{
	tcStock *stock = GetStock();
	if (stock == NULL) {
		return "";
	}
	return stock->GetDescription();
}

#include "moc_tcstockinfo.cpp"
