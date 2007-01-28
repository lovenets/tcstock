#ifndef tcmarketlistdlg_h

#define tcmarketlistdlg_h

#include <QtCore/QVariant>
#include <QtGui/QDialog>
#include "ui_marketlistdlg.h"

#include "tcmarketmgr.h"

/*! \brief tcMarketListDialog
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.03
 	
	股市列表显示窗口，同时支持对股市的增加和删除。
*/
class tcMarketListDialog : public QDialog, private Ui_tcMarketListDialog
{
	Q_OBJECT

public:
	tcMarketListDialog(QWidget *pParent, tcMarketManager *pMarketManager);

protected:
	void LoadMarketList();

protected slots:
	void DoAppendMarket();

	void DoModifyMarket();

	void DoRemoveMarket();

private:
	tcMarketManager *mMarketManager;

};

#endif //tcmarketlistdlg_h

