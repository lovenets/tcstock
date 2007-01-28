#ifndef tcstocklistwgt_h

#define tcstocklistwgt_h

#include <QtCore/QVariant>
#include <QtGui/QWidget>
#include "ui_stocklistwgt.h"

#include "../stock/tcstockpack.h"
#include "tcstocklistfavtwgt.h"
#include "tcstocklistallwgt.h"
class tcMarketManager;

/*! \brief tcStockListWidget
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.03
 	
	股票列表组面板。
*/
class tcStockListWidget : public QWidget, private Ui_tcStockListWidget
{
	Q_OBJECT

public:
	tcStockListWidget(QWidget *pParent);

	~tcStockListWidget();

protected slots:
	void DoTabStockSelected(tcStockInfoList *pStockInfoList);

private:
	tcStockListFavouriteWidget *mFavouriteWidget;

	tcStockListAllWidget *mAllWidget;

signals:
	void OnStockSelected(tcStockInfoList *pStockInfoList);

};

#endif //tcstocklistwgt_h
