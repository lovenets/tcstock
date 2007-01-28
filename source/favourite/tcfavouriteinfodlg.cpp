#include "tcfavouriteinfodlg.h"

#include <QtGui/QHeaderView>

#include "../service/tcsvcpack.h"
#include "tcfavouritemgr.h"

tcFavouriteInfoDialog::tcFavouriteInfoDialog(QWidget *pParent, int pGroupIndex)
	: QDialog(pParent)
{
	setupUi(this);
	connect(cbo1, SIGNAL(currentIndexChanged(int)), this, SLOT(DoFavouriteGroupIndexChanged(int)));
	connect(btn1, SIGNAL(clicked()), this, SLOT(DoAppendFavouriteGroup()));
	connect(btn2, SIGNAL(clicked()), this, SLOT(DoModifyFavouriteGroup()));
	connect(btn3, SIGNAL(clicked()), this, SLOT(DoRemoveFavouriteGroup()));
	connect(btn4, SIGNAL(clicked()), this, SLOT(DoAppendFavouriteStock()));
	connect(btn5, SIGNAL(clicked()), this, SLOT(DoRemoveFavouriteStock()));

	tbl1->verticalHeader()->hide();
	tbl1->setSelectionMode(QAbstractItemView::SingleSelection);
	tbl1->setSelectionBehavior(QAbstractItemView::SelectRows);

	mDataModel = new tcFavouriteStockModel(this);
	tbl1->setModel(mDataModel);

	mDataDelegate = new tcFavouriteStockDelegate(this);
	tbl1->setItemDelegate(mDataDelegate);

	LoadFavouriteGroupList();
	if (pGroupIndex >= 0) {
		cbo1->setCurrentIndex(pGroupIndex);
	}
}

void tcFavouriteInfoDialog::LoadFavouriteGroupList()
{
	QString groupname = cbo1->currentText();
	cbo1->clear();
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	int i;
	for (i=0; i<favouritemanager->GetFavouriteGroupCount(); i++) {
		tcFavouriteGroup *group = favouritemanager->GetFavouriteGroup(i);
		cbo1->addItem(group->GetGroupName());
	}
	//restore the last selected group in to combo
	int index = cbo1->findText(groupname);
	if (index >= 0) {
		cbo1->setCurrentIndex(index);
	}
}

void tcFavouriteInfoDialog::DoFavouriteGroupIndexChanged(int pIndex)
{
	mDataModel->LoadFavouriteStockList(cbo1->currentIndex());
}

void tcFavouriteInfoDialog::DoAppendFavouriteGroup()
{
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	tcFavouriteGroup *group = favouritemanager->AppendFavouriteGroup(this);
	if (group == NULL) {
		return;
	}
	cbo1->addItem(group->GetGroupName());
	cbo1->setCurrentIndex(cbo1->count()-1);
}

void tcFavouriteInfoDialog::DoModifyFavouriteGroup()
{
	if (cbo1->currentIndex() < 0) {
		return;
	}
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	tcFavouriteGroup *group = favouritemanager->ModifyFavouriteGroup(this, cbo1->currentIndex());
	if (group == NULL) {
		return;
	}
	cbo1->setItemText(cbo1->currentIndex(), group->GetGroupName());
}

void tcFavouriteInfoDialog::DoRemoveFavouriteGroup()
{
	if (cbo1->currentIndex() < 0) {
		return;
	}
	tcFavouriteManager *favouritemanager = tcObjService::GetFavouriteManager();
	if (! favouritemanager->RemoveFavouriteGroup(this, cbo1->currentIndex())) {
		return;
	}
	cbo1->removeItem(cbo1->currentIndex());
}

void tcFavouriteInfoDialog::DoAppendFavouriteStock()
{
	mDataModel->AppendFavouriteStock(this, cbo1->currentIndex());
}

void tcFavouriteInfoDialog::DoRemoveFavouriteStock()
{
	mDataModel->RemoveFavouriteStock(this, cbo1->currentIndex(), tbl1->currentIndex().row());
}

#ifdef WIN32
	#include "moc_tcfavouriteinfodlg.cpp"
#endif
