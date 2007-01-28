#include "tcfavouritestock.h"

#include "../service/tcsvcpack.h"

tcFavouriteStock::tcFavouriteStock()
{
	mMarketIndex = -1;

	mBindedStock = NULL;
}

tcFavouriteStock::~tcFavouriteStock()
{
}

bool tcFavouriteStock::LoadFromXml(const QDomElement &pElement)
{
	int marketindex = pElement.attribute("MarketIndex").toInt();
	QString stockcode = pElement.attribute("StockCode");
	if (! BindToStock(marketindex, stockcode)) {
		tcLogService::CreateLog(this, "Error when bind to stock.");
		return false;
	}
	return true;
}

bool tcFavouriteStock::SaveToXml(QDomDocument &pDoc, QDomElement &pElement)
{
	pElement.setAttribute("MarketIndex", mMarketIndex);
	pElement.setAttribute("StockCode", mStockCode);
	return true;
}

bool tcFavouriteStock::BindToStock(int pMarketIndex, const QString &pStockCode)
{
	mMarketIndex = -1;
	mStockCode = "";
	mBindedStock = NULL;

	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket *market = marketmanager->GetMarket(pMarketIndex);
	if (market == NULL) {
		tcLogService::CreateLog(this, "Wrong market index.");
		return false;
	}
	tcStock *stock = market->GetStockByCode(pStockCode);
	if (stock == NULL) {
		tcLogService::CreateLog(this, "Not found the stock.");
		return false;
	}
	mMarketIndex = pMarketIndex;
	mStockCode = pStockCode;
	mBindedStock = stock;
	return true;
}

bool tcFavouriteStock::IsBinded()
{
	return (mBindedStock != NULL);
}

#ifdef WIN32
	#include "moc_tcfavouritestock.cpp"
#endif
