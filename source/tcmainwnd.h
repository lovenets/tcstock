#ifndef mainwnd_h

#define mainwnd_h

#include <QtCore/QVariant>
#include <QtGui/QWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QDockWidget>

#include "stockinfo/tcstockinfopack.h"
#include "viewmodel/tcviewmodelpack.h"
#include "stockview/tcstockviewpack.h"
#include "stocklistwgt/tcstocklistwgtpack.h"
#include "tcdailyviewwgt.h"
#include "tcweeklyviewwgt.h"

/*! \brief tcMainWindow
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.02
 	
	系统主界面。
*/
class tcMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	tcMainWindow(QWidget *pParent);

	~tcMainWindow();

protected:
	void CreateMenusAndToolbar();

protected slots:
	void DoModifyMarket();

	void DoInputStockData();

	void DoEditFavouriteStock();

	void DoExit();

	void DoViewStockList();

	void DoViewWeeklyView();

	void DoAbout();

	void mytest();

	void DoStockSelected(tcStockInfoList *pStockInfoList);

private:
	tcDailyViewWidget *mDailyViewWidget;

	tcWeeklyViewWidget *mWeeklyViewWidget;

	QDockWidget *mWeeklyDock;

	tcStockListWidget *mStockListWidget;

	QDockWidget *mStockListDock;

};


#endif //mainwnd_h
