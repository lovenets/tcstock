#include "tcstocklistallwgt.h"

#include <QtCore/QList>
#include <QtGui/QHeaderView>

#include "../service/tcsvcpack.h"
#include "../stockinfo/tcstockinfopack.h"

tcStockListAllWidget::tcStockListAllWidget(QWidget *pParent)
	: QWidget(pParent)
{
	setupUi(this);
    QStringList titles;
    titles<<tr("StockCode")<<tr("Name");
    tbl1->setColumnCount(2);
    tbl1->setHorizontalHeaderLabels(titles);
    tbl1->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    tbl1->verticalHeader()->hide();
    //tbl1->setSelectionMode(QAbstractItemView::SingleSelection);
    tbl1->setSelectionBehavior(QAbstractItemView::SelectRows);
	tbl1->setEditTriggers(QAbstractItemView::NoEditTriggers);

	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	connect(marketmanager, SIGNAL(OnMarketModified()), this, SLOT(DoMarketModified()));
	connect(marketmanager, SIGNAL(OnStockModified(tcMarket *)), this, SLOT(DoStockModified(tcMarket *)));
	connect(cbo1, SIGNAL(currentIndexChanged(int)), this, SLOT(DoMarketIndexChanged(int)));
	connect(edt1, SIGNAL(textChanged(const QString &)), this, SLOT(DoFilterTextChanged(const QString &)));
	connect(edt2, SIGNAL(textChanged(const QString &)), this, SLOT(DoFilterTextChanged(const QString &)));
	connect(tbl1, SIGNAL(itemSelectionChanged()), this, SLOT(DoStockSelectionChanged()));

	DoMarketModified();
}

tcStockListAllWidget::~tcStockListAllWidget()
{
}

void tcStockListAllWidget::DoMarketModified()
{
	QString marketname = cbo1->currentText();
	cbo1->clear();
	cbo1->addItem(tr("All Markets"));
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	int i;
	for (i=0; i<marketmanager->GetMarketCount(); i++) {
		tcMarket *market = marketmanager->GetMarket(i);
		Q_ASSERT(market);
		cbo1->addItem(market->GetName());
	}
	//restore the last selected market in the combo
	int index = cbo1->findText(marketname);
	if (index >= 0) {
		cbo1->setCurrentIndex(index);
	}
}

void tcStockListAllWidget::DoStockModified(tcMarket *pMarket)
{
	int index = cbo1->currentIndex();
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	if (index == 0 || marketmanager->GetMarket(index) == pMarket) {
		DoMarketIndexChanged(cbo1->currentIndex());
	}
}

void tcStockListAllWidget::DoMarketIndexChanged(int pIndex)
{
	mViewStockInfoList.clear();
	tbl1->setRowCount(0);

	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	marketmanager->GetStockInfoListFilter(pIndex-1, mViewStockInfoList, edt1->text(), edt2->text());
	foreach (tcStockInfo info, mViewStockInfoList) {
		tcStock *stock = info.GetStock();
		if (stock == NULL) {
			tcLogService::CreateLog(this, "Error when get stock from stock code.");
			continue;
		}
		int row = tbl1->rowCount();
		tbl1->insertRow(row);
		tbl1->setItem(row, 0, new QTableWidgetItem(stock->GetStockCode()));
		tbl1->setItem(row, 1, new QTableWidgetItem(stock->GetStockName()));
	}
}

void tcStockListAllWidget::DoFilterTextChanged(const QString &pText)
{
	DoMarketIndexChanged(-1);
}

void tcStockListAllWidget::DoStockSelectionChanged()
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

#include "moc_tcstocklistallwgt.cpp"
