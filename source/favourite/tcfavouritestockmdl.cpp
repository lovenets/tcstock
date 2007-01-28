#include "tcfavouritestockmdl.h"

#include <QtGui/QTableWidgetItem>

#include "../service/tcsvcpack.h"
#include "tcfavouritemgr.h"
#include "tcfavouritegrp.h"

tcFavouriteStockModel::tcFavouriteStockModel(QObject *pParent)
	: QStandardItemModel(0, 3, pParent)
{
	setHeaderData(0, Qt::Horizontal, tr("Stock Code"));
	setHeaderData(1, Qt::Horizontal, tr("Name"));
	setHeaderData(2, Qt::Horizontal, tr("Level"));
}

void tcFavouriteStockModel::LoadFavouriteStockList(int pFavouriteGroupIndex)
{
	setRowCount(0);

	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	tcFavouriteGroup *group = favouritemanager->GetFavouriteGroup(pFavouriteGroupIndex);
	if (group == NULL) {
		tcLogService::CreateLog(this, "Error when get favourite group.");
		return;
	}
	int i;
	for (i=0; i<group->GetFavouriteStockCount(); i++) {
		tcFavouriteStockInfo *favourite = group->GetFavouriteStock(i);
		Q_ASSERT(favourite);
		int row = rowCount();
		insertRow(row);
		setItem(row, 0, new QStandardItem(favourite->GetStockCode()));
		setItem(row, 1, new QStandardItem(favourite->GetStockName()));
		setItem(row, 2, new QStandardItem("*****"));
	}
}

bool tcFavouriteStockModel::AppendFavouriteStock(QWidget *pParent, int pFavouriteGroupIndex)
{
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	tcFavouriteGroup *group = favouritemanager->GetFavouriteGroup(pFavouriteGroupIndex);
	if (group == NULL) {
		tcLogService::CreateLog(this, "Error when get favourite group.");
		return false;
	}
	if (! group->AppendFavouriteStock(pParent)) {
		return false;
	}
	//refresh the dialog
	LoadFavouriteStockList(pFavouriteGroupIndex);
	return true;
}

bool tcFavouriteStockModel::RemoveFavouriteStock(QWidget *pParent, int pFavouriteGroupIndex, int pIndex)
{
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	tcFavouriteGroup *group = favouritemanager->GetFavouriteGroup(pFavouriteGroupIndex);
	if (group == NULL) {
		tcLogService::CreateLog(this, "Error when get favourite group.");
		return false;
	}
	if (! group->RemoveFavouriteStock(pParent, pIndex)) {
		tcLogService::CreateLog(this, "Error when remove favourite stock.");
		return false;
	}
	//refresh the dialog
	LoadFavouriteStockList(pFavouriteGroupIndex);
	return true;
}

#ifdef WIN32
	#include "moc_tcfavouritestockmdl.cpp"
#endif
