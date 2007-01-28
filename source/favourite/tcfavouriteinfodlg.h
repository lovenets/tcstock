#ifndef tcfavouriteinfodlg_h

#define tcfavouriteinfodlg_h

#include <QtCore/QVariant>
#include <QtGui/QDialog>
#include "ui_favouriteinfodlg.h"

#include "tcfavouritestockmdl.h"
#include "tcfavouritestockdlt.h"

/*! \brief tcFavouriteInfoDialog
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.25
 	
	自选股票信息显示对话框，包括编辑自选股，添加删除自选股票功能。
*/
class tcFavouriteInfoDialog : public QDialog, private Ui_tcFavouriteInfoDialog
{
	Q_OBJECT

public:
	tcFavouriteInfoDialog(QWidget *pParent, int pGroupIndex);

protected:
	void LoadFavouriteGroupList();

protected slots:
	void DoFavouriteGroupIndexChanged(int pIndex);

	void DoAppendFavouriteGroup();

	void DoModifyFavouriteGroup();

	void DoRemoveFavouriteGroup();

	void DoAppendFavouriteStock();

	void DoRemoveFavouriteStock();

private:
	tcFavouriteStockModel *mDataModel;

	tcFavouriteStockDelegate *mDataDelegate;

};

#endif //tcfavouriteinfodlg_h

