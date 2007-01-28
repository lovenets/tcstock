#include "tcstockinfo.h"

#include "../service/tcsvcpack.h"
#include "tcmarketmgr.h"

tcStockInfo::tcStockInfo(int pMarketIndex, const QString &pStockCode)
{
	mMarketIndex = pMarketIndex;
	mStockCode = pStockCode;

	ConnectMarketIndexModifiedSignal();
}

tcStockInfo::tcStockInfo(const tcStockInfo &pInfo)
{
	mMarketIndex = pInfo.mMarketIndex;
	mStockCode = pInfo.mStockCode;

	ConnectMarketIndexModifiedSignal();
}

tcStockInfo::tcStockInfo()
{
	mMarketIndex = -1;
	mStockCode = -1;
}

tcStock* tcStockInfo::GetStock()
{
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket *market = marketmanager->GetMarket(mMarketIndex);
	if (market == NULL) {
		tcLogService::CreateLog(this, "Error when get market.");
		return NULL;
	}
	tcStock *stock = market->GetStockByCode(mStockCode);
	if (stock == NULL) {
		tcLogService::CreateLog(this, "Error when get stock.");
		return stock;
	}
	return stock;
}

int tcStockInfo::GetMarketIndex()
{
	return mMarketIndex;
}

QString tcStockInfo::GetStockCode()
{
	return mStockCode;
}

void tcStockInfo::ConnectMarketIndexModifiedSignal()
{
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket *market = marketmanager->GetMarket(mMarketIndex);
	if (market) {
		connect(market, SIGNAL(OnIndexModified(int)), this, SLOT(DoMarketIndexModified(int)));
	}
}

tcStockInfo& tcStockInfo::operator=(const tcStockInfo &pInfo)
{
	mMarketIndex = pInfo.mMarketIndex;
	mStockCode = pInfo.mStockCode;

	ConnectMarketIndexModifiedSignal();
	return *this;
}

bool tcStockInfo::operator==(const tcStockInfo &pInfo)
{
	if (mMarketIndex != pInfo.mMarketIndex) {
		return false;
	}
	if (mStockCode != pInfo.mStockCode) {
		return false;
	}
	return true;
}

QString tcStockInfo::GetMarketName()
{
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket *market = marketmanager->GetMarket(mMarketIndex);
	if (market == NULL) {
		tcLogService::CreateLog(this, "Error when get market.");
		return "";
	}
	return market->GetName();
}

QString tcStockInfo::GetStockName()
{
	tcStock *stock = GetStock();
	if (stock == NULL) {
		return "";
	}
	return stock->GetStockName();
}

void tcStockInfo::DoMarketIndexModified(int pNewIndex)
{
	mMarketIndex = pNewIndex;
}

#ifdef WIN32
	#include "moc_tcstockinfo.cpp"
#endif
