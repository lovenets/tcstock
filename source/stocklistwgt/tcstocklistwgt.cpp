#include "tcstocklistwgt.h"

#include "../service/tcsvcpack.h"
#include "../stock/tcstockpack.h"

tcStockListWidget::tcStockListWidget(QWidget *pParent)
	: QWidget(pParent)
{
	setupUi(this);

	mFavouriteWidget = new tcStockListFavouriteWidget(this);
	connect(mFavouriteWidget, SIGNAL(OnStockSelected(tcStockInfoList *)), this, SLOT(DoTabStockSelected(tcStockInfoList *)));
	vboxLayout1->setMargin(0);
	vboxLayout1->addWidget(mFavouriteWidget);

	mAllWidget = new tcStockListAllWidget(this);
	connect(mAllWidget, SIGNAL(OnStockSelected(tcStockInfoList *)), this, SLOT(DoTabStockSelected(tcStockInfoList *)));
	vboxLayout2->setMargin(0);
	vboxLayout2->addWidget(mAllWidget);
}

tcStockListWidget::~tcStockListWidget()
{

}

void tcStockListWidget::DoTabStockSelected(tcStockInfoList *pStockInfoList)
{
	emit OnStockSelected(pStockInfoList);
}

#ifdef WIN32
	#include "moc_tcstocklistwgt.cpp"
#endif
