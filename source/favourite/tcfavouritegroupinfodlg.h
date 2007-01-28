#ifndef tcfavouritegroupinfodlg_h

#define tcfavouritegroupinfodlg_h

#include <QtCore/QVariant>
#include <QtGui/QDialog>
#include "ui_favouritegroupinfodlg.h"

#include "tcfavouritegrp.h"

/*! \brief tcFavouriteGroupInfoDialog
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.25
 	
	自选股票组编辑对话框。
*/
class tcFavouriteGroupInfoDialog : public QDialog, private Ui_tcFavouriteGroupInfoDialog
{
	Q_OBJECT

public:
	tcFavouriteGroupInfoDialog(QWidget *pParent);

	bool LoadFromFavouriteGroup(tcFavouriteGroup *pFavouriteGroup);

	bool SaveToFavouriteGroup(tcFavouriteGroup *pFavouriteGroup);

protected slots:
	void DoOk();

};

#endif //tcfavouritegroupinfodlg_h
