#include "tcstockselectdlg.h"

#include <QtGui/QHeaderView>
#include <QtGui/QTableWidgetItem>
#include <QtGui/QMessageBox>

#include "../tcdefine.h"
#include "../service/tcsvcpack.h"
#include "tcmarketmgr.h"

tcStockSelectDialog::tcStockSelectDialog(QWidget *pParent)
	: QDialog(pParent)
{
	setupUi(this);
    QStringList titles;
    titles<<tr("StockCode")<<tr("Name");
    tbl1->setColumnCount(2);
    tbl1->setHorizontalHeaderLabels(titles);
    tbl1->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    tbl1->verticalHeader()->hide();
    tbl1->setSelectionMode(QAbstractItemView::SingleSelection);
    tbl1->setSelectionBehavior(QAbstractItemView::SelectRows);
	tbl1->setEditTriggers(QAbstractItemView::NoEditTriggers);

	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	connect(marketmanager, SIGNAL(OnMarketModified()), this, SLOT(DoMarketModified()));
	connect(marketmanager, SIGNAL(OnStockModified()), this, SLOT(DoStockModified()));
	connect(cbo1, SIGNAL(currentIndexChanged(int)), this, SLOT(DoMarketIndexChanged(int)));
	connect(edt1, SIGNAL(textChanged(const QString &)), this, SLOT(DoFilterTextChanged(const QString &)));
	connect(edt2, SIGNAL(textChanged(const QString &)), this, SLOT(DoFilterTextChanged(const QString &)));
	disconnect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(DoOk()));

	DoMarketModified();
}

bool tcStockSelectDialog::GetSelectedStockInfoList(tcStockInfoList &pStockInfoList)
{
	int i;
	for (i=0; i<tbl1->rowCount(); i++) {
		QTableWidgetItem *item = tbl1->item(i, 0);
		Q_ASSERT(item);
		if (item->checkState() == Qt::Checked) {
			tcStockInfo info = mViewStockInfoList[i];
			pStockInfoList.append(info);
		}
	}
	return true;
}

void tcStockSelectDialog::DoMarketModified()
{
	QString marketname = cbo1->currentText();
	cbo1->clear();
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

void tcStockSelectDialog::DoStockModified()
{
	//get the filted stock list
	mViewStockInfoList.clear();
	tcMarketManager *marketmanager = tcObjService::GetMarketManager();
	if (! marketmanager->GetStockInfoListFilter(cbo1->currentIndex(), mViewStockInfoList, edt1->text(), edt2->text())) {
		tcLogService::CreateLog(this, "Error when get stock info list.");
		return;
	}

	//show stock in the tableview
	setUpdatesEnabled(false);
	tbl1->setRowCount(0);
	foreach(tcStockInfo info, mViewStockInfoList) {
		int row = tbl1->rowCount();
		tbl1->insertRow(row);
		QTableWidgetItem *item = new QTableWidgetItem(info.GetStockCode());
		item->setCheckState(Qt::Unchecked);
		tbl1->setItem(row, 0, item);
		tbl1->setItem(row, 1, new QTableWidgetItem(info.GetStockName()));
	}
	setUpdatesEnabled(true);
}

void tcStockSelectDialog::DoMarketIndexChanged(int pIndex)
{
	DoStockModified();
}

void tcStockSelectDialog::DoFilterTextChanged(const QString &pText)
{
	DoStockModified();
}

void tcStockSelectDialog::DoOk()
{
	//check if none item been selected
	bool haschecked = false;
	int i;
	for (i=0; i<tbl1->rowCount(); i++) {
		QTableWidgetItem *item = tbl1->item(i, 0);
		Q_ASSERT(item);
		if (item->checkState() == Qt::Checked) {
			haschecked = true;
			break;
		}
	}
	if (! haschecked) {
		QMessageBox::warning(this, SYSTEM_NAME, tr("You must select some stock from the list."));
		return;
	}

	accept();
}

#include "moc_tcstockselectdlg.cpp"
