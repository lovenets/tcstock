#ifndef tcstocklistfavtwgt_h

#define tcstocklistfavtwgt_h

#include <QtCore/QVariant>
#include <QtGui/QWidget>
#include "ui_stocklistfavtwgt.h"

#include "../stockinfo/tcstockinfopack.h"

/*! \brief tcStockListFavouriteWidget
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.24
 	
	关注股票列表面板。
*/
class tcStockListFavouriteWidget : public QWidget, private Ui_tcStockListFavouriteWidget
{
	Q_OBJECT

public:
	tcStockListFavouriteWidget(QWidget *pParent);

	~tcStockListFavouriteWidget();

protected slots:
	void DoEditFavourite();

	/*!
		notified by tcFavouriteManager
	*/
	void DoFavouriteGroupModified();

	/*!
		notified by tcFavouriteManager
	*/
	void DoFavouriteStockModified(tcFavouriteGroup *pFavouriteGroup);

	void DoFavouriteGroupIndexChanged(int pIndex);

	void DoStockSelectionChanged();

private:
	tcStockInfoList mViewStockInfoList;

signals:
	void OnStockSelected(tcStockInfoList *pStockInfoList);

};

#endif //tcstocklistfavtwgt_h

