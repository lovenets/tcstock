#include "tcstock.h"

tcStock::tcStock(tcStockDataCache *pStockDataCache)
{
	mStockDataCache = pStockDataCache;
	mStockCode = -1;
}

tcStock::~tcStock()
{
}

bool tcStock::LoadFromXml(const QDomElement &pElement)
{
	mStockCode = pElement.attribute("StockCode");
	mStockName = pElement.attribute("StockName");
	mDescription = pElement.attribute("Description");
	return true;
}

bool tcStock::SaveToXml(QDomDocument &pDoc, QDomElement &pElement)
{
	pElement.setAttribute("StockCode", mStockCode);
	pElement.setAttribute("StockName", mStockName);
	pElement.setAttribute("Description", mDescription);
	return true;
}

QString tcStock::GetStockCode()
{
	return mStockCode;
}

void tcStock::SetStockCode(const QString &pStockCode)
{
	mStockCode = pStockCode;
}

QString tcStock::GetStockName()
{
	return mStockName;
}

void tcStock::SetStockName(const QString &pStockName)
{
	mStockName = pStockName;
}

QString tcStock::GetDescription()
{
	return mDescription;
}

void tcStock::SetDescription(const QString &pDescription)
{
	mDescription = pDescription;
}

tcStock::tcStock()
{
}

#include "moc_tcstock.cpp"
