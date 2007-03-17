#include "tcstocklistfavtwgt.h"

#include <QtCore/QList>
#include <QtGui/QHeaderView>

#include "../service/tcsvcpack.h"

tcStockListFavouriteWidget::tcStockListFavouriteWidget(QWidget *pParent)
	: QWidget(pParent)
{
	setupUi(this);
	connect(btn1, SIGNAL(clicked()), this, SLOT(DoEditFavourite()));

	QStringList titles;
	titles<<tr("StockCode")<<tr("Name");
    tbl1->setColumnCount(2);
    tbl1->setHorizontalHeaderLabels(titles);
    tbl1->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    tbl1->verticalHeader()->hide();
    //tbl1->setSelectionMode(QAbstractItemView::SingleSelection);
    tbl1->setSelectionBehavior(QAbstractItemView::SelectRows);
	tbl1->setEditTriggers(QAbstractItemView::NoEditTriggers);

	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	connect(favouritemanager, SIGNAL(OnFavouriteGroupModified()), this, SLOT(DoFavouriteGroupModified()));
	connect(favouritemanager, SIGNAL(OnFavouriteStockModified(tcFavouriteGroup *)), this, SLOT(DoFavouriteStockModified(tcFavouriteGroup *)));
	connect(cbo1, SIGNAL(currentIndexChanged(int)), this, SLOT(DoFavouriteGroupIndexChanged(int)));
	connect(tbl1, SIGNAL(itemSelectionChanged()), this, SLOT(DoStockSelectionChanged()));

	DoFavouriteGroupModified();
}

tcStockListFavouriteWidget::~tcStockListFavouriteWidget()
{
}

void tcStockListFavouriteWidget::DoEditFavourite()
{
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	favouritemanager->EditFavouriteList(this, cbo1->currentIndex());
}

void tcStockListFavouriteWidget::DoFavouriteGroupModified()
{
	QString groupname = cbo1->currentText();
	cbo1->clear();
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	int i;
	for (i=0; i<favouritemanager->GetFavouriteGroupCount(); i++) {
		tcFavouriteGroup *group = favouritemanager->GetFavouriteGroup(i);
		Q_ASSERT(group);
		cbo1->addItem(group->GetName());
	}
	//restore the last selected group in the combo
	int index = cbo1->findText(groupname);
	if (index >= 0) {
		cbo1->setCurrentIndex(index);
	}
}

void tcStockListFavouriteWidget::DoFavouriteStockModified(tcFavouriteGroup *pFavouriteGroup)
{
	int index = cbo1->currentIndex();
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	if (favouritemanager->GetFavouriteGroup(index) == pFavouriteGroup) {
		DoFavouriteGroupIndexChanged(cbo1->currentIndex());
	}
}

void tcStockListFavouriteWidget::DoFavouriteGroupIndexChanged(int pIndex)
{
	mViewStockInfoList.clear();
	tbl1->setRowCount(0);

	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	tcFavouriteGroup *group = favouritemanager->GetFavouriteGroup(pIndex);
	if (group == NULL) {
		tcLogService::CreateLog(this, "Error when get favourite group.");
		return;
	}
	if (! group->GetStockInfoList(mViewStockInfoList)) {
		tcLogService::CreateLog(this, "Error when get stock info list.");
		return;
	}
	foreach (tcStockInfo stockinfo, mViewStockInfoList) {
		int row = tbl1->rowCount();
		tbl1->insertRow(row);
		tbl1->setItem(row, 0, new QTableWidgetItem(stockinfo.GetStockCode()));
		tbl1->setItem(row, 1, new QTableWidgetItem(stockinfo.GetStockName()));
	}
}

void tcStockListFavouriteWidget::DoStockSelectionChanged()
{
	tcStockInfoList list;
	QList<QTableWidgetItem*> sellist = tbl1->selectedItems();
	foreach(QTableWidgetItem *item, sellist) {
		tcStockInfo info = mViewStockInfoList[item->row()];
		list.append(info);
		break;
	}
	emit OnStockSelected(&list);
}

#include "moc_tcstocklistfavtwgt.cpp"
