#include "tcstockdatainfodlg.h"

#include <QtGui/QHeaderView>

#include "../service/tcsvcpack.h"
#include "../favourite/tcfavouritepack.h"

tcStockDataInfoDialog::tcStockDataInfoDialog(QWidget *pParent)
	: QDialog(pParent)
{
	setupUi(this);

	int i;
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	for (i=0; i<favouritemanager->GetFavouriteGroupCount(); i++) {
		tcFavouriteGroup *group = favouritemanager->GetFavouriteGroup(i);
		cbo1->addItem(group->GetGroupName());
	}
	cbo1->addItem("-----------------");
	cbo1->addItem(tr("All Markets"));
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	for (i=0; i<marketmanager->GetMarketCount(); i++) {
		tcMarket *market = marketmanager->GetMarket(i);
		cbo1->addItem(market->GetName());
	}

	tbl1->verticalHeader()->hide();
    tbl1->setSelectionMode(QAbstractItemView::SingleSelection);
    tbl1->setSelectionBehavior(QAbstractItemView::SelectRows);

	mDataModel = new tcStockDataItemModel(this);
	tbl1->setModel(mDataModel);

	mDataDelegate = new tcStockDataItemDelegate(this);
	tbl1->setItemDelegate(mDataDelegate);

	mDataModel->CreateStockList(cbo1->currentIndex(), edt1->text(), edt2->text());

	cld1->setDate(QDate::currentDate());

	connect(cld1, SIGNAL(dateChanged(const QDate &)), this, SLOT(DoDateChanged(const QDate &)));
	connect(cbo1, SIGNAL(currentIndexChanged(int)), this, SLOT(DoGroupChanged(int)));
	connect(edt1, SIGNAL(textChanged(const QString &)), this, SLOT(DoFilterTextChanged(const QString &)));
	connect(edt2, SIGNAL(textChanged(const QString &)), this, SLOT(DoFilterTextChanged(const QString &)));
	connect(btn1, SIGNAL(clicked()), this, SLOT(DoAppendStock()));
	connect(btn2, SIGNAL(clicked()), this, SLOT(DoModifyStock()));
	connect(btn3, SIGNAL(clicked()), this, SLOT(DoRemoveStock()));

	DoGroupChanged(-1);
}

void tcStockDataInfoDialog::DoDateChanged(const QDate &pDate)
{
	mDataModel->LoadStockData(pDate);
}

void tcStockDataInfoDialog::DoGroupChanged(int pIndex)
{
	int groupindex = cbo1->currentIndex();
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	if (groupindex == favouritemanager->GetFavouriteGroupCount()) {	//selected the "------"
		return;
	}
	else if (groupindex < favouritemanager->GetFavouriteGroupCount()) {
		groupindex = groupindex + 500;
	}
	else {
		groupindex = groupindex - favouritemanager->GetFavouriteGroupCount() - 2;
	}

	mDataModel->CreateStockList(groupindex, edt1->text(), edt2->text());
	mDataModel->LoadStockData(cld1->date());
}

void tcStockDataInfoDialog::DoFilterTextChanged(const QString &pText)
{
	DoGroupChanged(-1);
}

void tcStockDataInfoDialog::DoAppendStock()
{
	if (mDataModel->AppendStock(this)) {
		DoGroupChanged(-1);
	}
}

void tcStockDataInfoDialog::DoModifyStock()
{
	if (mDataModel->ModifyStock(this, tbl1->currentIndex().row())) {
		DoGroupChanged(-1);
	}
}

void tcStockDataInfoDialog::DoRemoveStock()
{
	if (mDataModel->RemoveStock(this, tbl1->currentIndex().row())) {
		DoGroupChanged(-1);
	}
}

#ifdef WIN32
	#include "moc_tcstockdatainfodlg.cpp"
#endif
