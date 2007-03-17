#ifndef tcstocklistallwgt_h

#define tcstocklistallwgt_h

#include <QtCore/QVariant>
#include <QtGui/QWidget>
#include "ui_stocklistallwgt.h"

#include "../stockinfo/tcstockinfopack.h"

/*! \brief tcStockListAllWidget
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.03
 	
	所有股票列表面板。
*/
class tcStockListAllWidget : public QWidget, private Ui_tcStockListAllWidget
{
	Q_OBJECT

public:
	tcStockListAllWidget(QWidget *pParent);

	~tcStockListAllWidget();

protected:

protected slots:
	/*!
		notified by tcMarketManager
	*/
	void DoMarketModified();

	/*!
		notified by tcMarketManager
	*/
	void DoStockModified(tcMarket *pMarket);

	void DoMarketIndexChanged(int pIndex);

	void DoFilterTextChanged(const QString &pText);

	void DoStockSelectionChanged();

private:
	tcStockInfoList mViewStockInfoList;

signals:
	void OnStockSelected(tcStockInfoList *pStockInfoList);

};

#endif //tcstocklistallwgt_h

