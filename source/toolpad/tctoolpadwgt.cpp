#include "tctoolpadwgt.h"

#include "../service/tcsvcpack.h"
#include "../stockinfo/tcstockinfopack.h"

tcToolPadWidget::tcToolPadWidget(QWidget *pParent)
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

tcToolPadWidget::~tcToolPadWidget()
{

}

void tcToolPadWidget::DoTabStockSelected(tcStockInfoList *pStockInfoList)
{
	emit OnStockSelected(pStockInfoList);
}

#include "moc_tctoolpadwgt.cpp"
