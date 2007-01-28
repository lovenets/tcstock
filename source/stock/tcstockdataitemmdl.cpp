#include "tcstockdataitemmdl.h"

#include <QtGui/QTableWidgetItem>

#include "../service/tcsvcpack.h"
#include "../favourite/tcfavouritepack.h"

tcStockDataItemModel::tcStockDataItemModel(QObject *pParent)
	: QStandardItemModel(0, 8, pParent)
{
	setHeaderData(0, Qt::Horizontal, tr("Stock Code"));
	setHeaderData(1, Qt::Horizontal, tr("Name"));
	setHeaderData(2, Qt::Horizontal, tr("Open Price"));
	setHeaderData(3, Qt::Horizontal, tr("Close Price"));
	setHeaderData(4, Qt::Horizontal, tr("Max Price"));
	setHeaderData(5, Qt::Horizontal, tr("Min Price"));
	setHeaderData(6, Qt::Horizontal, tr("Total Price"));
	setHeaderData(7, Qt::Horizontal, tr("Quantity"));
}

void tcStockDataItemModel::CreateStockList(int pGroupIndex, const QString &pStockCodeFilter, const QString &pStockNameFilter)
{
	mViewStockInfoList.clear();
	if (pGroupIndex >= 500) {	//favourite group's index
		tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
		if (! favouritemanager->GetStockInfoListFilter(pGroupIndex - 500, &mViewStockInfoList, pStockCodeFilter, pStockNameFilter)) {
			tcLogService::CreateLog(this, "Error when get favourite stock list.");
			return;
		}
	}
	else {	//market's index
		tcMarketManager *marketmanager = tcObjService::GetMarketManager();
		if (! marketmanager->GetStockInfoListFilter(pGroupIndex, &mViewStockInfoList, pStockCodeFilter, pStockNameFilter)) {
			tcLogService::CreateLog(this, "Error when get stock list.");
			return;
		}
	}

	//show stock in the tableview
	setRowCount(0);
	foreach(tcStockInfo info, mViewStockInfoList) {
		int row = rowCount();
		insertRow(row);
		setItem(row, 0, new QStandardItem(info.GetStockCode()));
		setItem(row, 1, new QStandardItem(info.GetStockName()));
	}
}

void tcStockDataItemModel::LoadStockData(const QDate &pDate)
{
	//fill the data of stock
	mEditDate = pDate;
	int i=0;
	foreach(tcStockInfo info, mViewStockInfoList) {
		tcStock *stock = info.GetStock();
		if (stock == NULL) {
			tcLogService::CreateLog(this, "Error when get stock from stock info.");
			continue;
		}
		tcStockDailyData *data = stock->ReadData(pDate);
		QString floatstr;
		floatstr.setNum(data->OpenPrice, 'F', 2);
		setItem(i, 2, new QStandardItem(floatstr));
		floatstr.setNum(data->ClosePrice, 'F', 2);
		setItem(i, 3, new QStandardItem(floatstr));
		floatstr.setNum(data->MaxPrice, 'F', 2);
		setItem(i, 4, new QStandardItem(floatstr));
		floatstr.setNum(data->MinPrice, 'F', 2);
		setItem(i, 5, new QStandardItem(floatstr));
		floatstr.setNum(data->TotalPrice);
		setItem(i, 6, new QStandardItem(floatstr));
		floatstr.setNum(data->Quantity);
		setItem(i, 7, new QStandardItem(floatstr));
		i++;
	}
}

tcStockDailyData* tcStockDataItemModel::ReadData(int pRow)
{
	if (pRow < 0 || pRow >= mViewStockInfoList.count()) {
		tcLogService::CreateLog(this, "Wrong index for read data.");
		return NULL;
	}
	tcStockInfo info = mViewStockInfoList[pRow];
	tcStock *stock = info.GetStock();
	if (stock == NULL) {
		tcLogService::CreateLog(this, "Erro rwhen get stock from stock info.");
		return NULL;
	}
	return stock->ReadData(mEditDate);
}

bool tcStockDataItemModel::WriteData(int pRow, tcStockDailyData* pStockDailyData)
{
	if (pRow < 0 || pRow >= mViewStockInfoList.count()) {
		tcLogService::CreateLog(this, "Wrong index for write data.");
		return false;
	}
	tcStockInfo info = mViewStockInfoList[pRow];
	tcStock *stock = info.GetStock();
	if (stock == NULL) {
		tcLogService::CreateLog(this, "Error when get stock from stock info.");
		return false;
	}
	if (! stock->WriteData(mEditDate, pStockDailyData)) {
		tcLogService::CreateLog(this, "Error when write data.");
		return false;
	}
	QString floatstr;
	floatstr.setNum(pStockDailyData->OpenPrice, 'F', 2);
	setItem(pRow, 2, new QStandardItem(floatstr));
	floatstr.setNum(pStockDailyData->ClosePrice, 'F', 2);
	setItem(pRow, 3, new QStandardItem(floatstr));
	floatstr.setNum(pStockDailyData->MaxPrice, 'F', 2);
	setItem(pRow, 4, new QStandardItem(floatstr));
	floatstr.setNum(pStockDailyData->MinPrice, 'F', 2);
	setItem(pRow, 5, new QStandardItem(floatstr));
	floatstr.setNum(pStockDailyData->TotalPrice);
	setItem(pRow, 6, new QStandardItem(floatstr));
	floatstr.setNum(pStockDailyData->Quantity);
	setItem(pRow, 7, new QStandardItem(floatstr));
	return true;
}

bool tcStockDataItemModel::AppendStock(QWidget *pParent)
{
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket *market = marketmanager->GetMarket(pParent);
	if (market == NULL) {
		return false;
	}
	tcStock *stock = market->AppendStock(pParent);
	return (stock != NULL);
}

bool tcStockDataItemModel::ModifyStock(QWidget *pParent, int pIndex)
{
	if (pIndex < 0 || pIndex >= mViewStockInfoList.count()) {
		return false;
	}
	tcStockInfo info = mViewStockInfoList[pIndex];
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket *market = marketmanager->GetMarket(info.GetMarketIndex());
	if (market == NULL) {
		return false;
	}
	tcStock *stock = market->ModifyStock(pParent, info.GetStockCode());
	return (stock != NULL);
}

bool tcStockDataItemModel::RemoveStock(QWidget *pParent, int pIndex)
{
	if (pIndex < 0 || pIndex >= mViewStockInfoList.count()) {
		return false;
	}
	tcStockInfo info = mViewStockInfoList[pIndex];
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	tcMarket *market = marketmanager->GetMarket(info.GetMarketIndex());
	if (market == NULL) {
		return false;
	}
	return market->RemoveStock(pParent, info.GetStockCode());
}

#ifdef WIN32
	#include "moc_tcstockdataitemmdl.cpp"
#endif
