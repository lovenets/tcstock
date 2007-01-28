#include "tcfavouritestockinfo.h"

#include "../service/tcsvcpack.h"

tcFavouriteStockInfo::tcFavouriteStockInfo(int pMarketIndex, const QString &pStockCode)
	: tcStockInfo(pMarketIndex, pStockCode)
{
}

tcFavouriteStockInfo::tcFavouriteStockInfo(const QDomElement &pElement)
{
	mMarketIndex = pElement.attribute("MarketIndex").toInt();
	mStockCode = pElement.attribute("StockCode");
}

tcFavouriteStockInfo::tcFavouriteStockInfo(const tcStockInfo &pStockInfo)
	: tcStockInfo(pStockInfo)
{
}

tcFavouriteStockInfo::~tcFavouriteStockInfo()
{
}

bool tcFavouriteStockInfo::SaveToXml(QDomDocument &pDoc, QDomElement &pElement)
{
	pElement.setAttribute("MarketIndex", mMarketIndex);
	pElement.setAttribute("StockCode", mStockCode);
	return true;
}

#ifdef WIN32
	#include "moc_tcfavouritestockinfo.cpp"
#endif
