#include "tcmarketlistdlg.h"

#include <QtGui/QHeaderView>

tcMarketListDialog::tcMarketListDialog(QWidget *pParent, tcMarketManager *pMarketManager)
	: QDialog(pParent)
{
	mMarketManager = pMarketManager;
	setupUi(this);
    QStringList titles;
    titles<<tr("Market")<<tr("Description");
    tbl1->setColumnCount(2);
    tbl1->setHorizontalHeaderLabels(titles);
    tbl1->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    tbl1->verticalHeader()->hide();
    tbl1->setSelectionMode(QAbstractItemView::SingleSelection);
    tbl1->setSelectionBehavior(QAbstractItemView::SelectRows);
	tbl1->setEditTriggers(QAbstractItemView::NoEditTriggers);
	connect(btn1, SIGNAL(clicked()), this, SLOT(DoAppendMarket()));
	connect(btn2, SIGNAL(clicked()), this, SLOT(DoModifyMarket()));
	connect(btn3, SIGNAL(clicked()), this, SLOT(DoRemoveMarket()));

	LoadMarketList();
}

void tcMarketListDialog::LoadMarketList()
{
	tbl1->setRowCount(0);
	int i;
	for (i=0; i<mMarketManager->GetMarketCount(); i++) {
		tcMarket *market = mMarketManager->GetMarket(i);
		Q_ASSERT(market);
		int row = tbl1->rowCount();
		tbl1->insertRow(row);
		tbl1->setItem(row, 0, new QTableWidgetItem(market->GetName()));
		tbl1->setItem(row, 1, new QTableWidgetItem(market->GetDescription()));
	}
}

void tcMarketListDialog::DoAppendMarket()
{
	tcMarket *market = mMarketManager->AppendMarket(this);
	if (! market) {
		return;
	}
	int row = tbl1->rowCount();
	tbl1->insertRow(row);
	tbl1->setItem(row, 0, new QTableWidgetItem(market->GetName()));
	tbl1->setItem(row, 1, new QTableWidgetItem(market->GetDescription()));
}

void tcMarketListDialog::DoModifyMarket()
{
	QModelIndex index = tbl1->currentIndex();
	if (index.row() < 0) {
		return;
	}
	tcMarket *market = mMarketManager->ModifyMarket(this, index.row());
	if (! market) {
		return;
	}
	int row = index.row();
	tbl1->setItem(row, 0, new QTableWidgetItem(market->GetName()));
	tbl1->setItem(row, 1, new QTableWidgetItem(market->GetDescription()));
}

void tcMarketListDialog::DoRemoveMarket()
{
	QModelIndex index = tbl1->currentIndex();
	if (index.row() < 0) {
		return;
	}
	if (! mMarketManager->RemoveMarket(this, index.row())) {
		return;
	}
	tbl1->removeRow(index.row());
}

#ifdef WIN32
	#include "moc_tcmarketlistdlg.cpp"
#endif
