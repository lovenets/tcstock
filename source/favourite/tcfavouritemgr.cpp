#include "tcfavouritemgr.h"

#include <QtCore/QTextStream>
#include <QtGui/QMessageBox>

#include "../tcdefine.h"
#include "../service/tcsvcpack.h"

#include "tcfavouriteinfodlg.h"
#include "tcfavouritegroupinfodlg.h"

#define FAVOURITES_XML_FILE "favourites.xml"

tcFavouriteManager::tcFavouriteManager(const QDir &pPath)
{
	mPath = pPath;
}

tcFavouriteManager::~tcFavouriteManager()
{
	ClearAllFavouriteGroups();
}

bool tcFavouriteManager::LoadFromFile()
{
	ClearAllFavouriteGroups();

	QFileInfo fileinfo(mPath, FAVOURITES_XML_FILE);
	QFile file(fileinfo.filePath());
	if (! file.open(QIODevice::ReadOnly)) {
		tcLogService::CreateLog(this, "Can not open favourites file.");
		return false;
	}
	
	QDomDocument doc;
	if (! doc.setContent(&file, true)) {
		file.close();
		tcLogService::CreateLog(this, "Can not load favorites file.");
		return false;
	}
	file.close();

	QDomElement element = doc.documentElement();
	QDomNode node = element.namedItem("Favourites");
	if (! node.isElement()) {
		tcLogService::CreateLog(this, "Favourites file format error.");
		return false;
	}
	QDomElement favouriteselement = node.toElement();

	int count, i;
	count = favouriteselement.attribute("Count").toInt();
	QString nodename = "Favourite_%1";
	for (i=0; i<count; i++) {
		node = favouriteselement.namedItem(nodename.arg(i));
		if (! node.isElement()) {
			tcLogService::CreateLog(this, "Favourites file format error.");
			return false;
		}
		QDomElement felement = node.toElement();
		tcFavouriteGroup *group = new tcFavouriteGroup();
		if (! group->LoadFromXml(felement)) {
			delete group;
			tcLogService::CreateLog(this, "Can not load favourite group.");
			return false;
		}
		connect(group, SIGNAL(OnFavouriteStockModified()), this, SLOT(DoFavouriteStockModified()));
		mFavouriteGroupList.append(group);
	}
	return true;
}

bool tcFavouriteManager::SaveToFile()
{
	QFileInfo fileinfo(mPath, FAVOURITES_XML_FILE);
	QFile file(fileinfo.filePath());
	if (! file.open(QIODevice::WriteOnly)) {
		tcLogService::CreateLog(this, "Can not open favourites file.");
		return false;
	}

	QDomDocument doc;

	QDomElement syselement = doc.createElement(SYSTEM_NAME);
	doc.appendChild(syselement);

	QDomElement groupelement = doc.createElement("Favourites");
	syselement.appendChild(groupelement);
	groupelement.setAttribute("Count", mFavouriteGroupList.count());
	QString nodename = "Favourite_%1";
	int index = 0;
	foreach (tcFavouriteGroup *group, mFavouriteGroupList) {
		QDomElement selement = doc.createElement(nodename.arg(index));
		groupelement.appendChild(selement);
		if (! group->SaveToXml(doc, selement)) {
			tcLogService::CreateLog(this, "Can not save favourite group.");
			return false;
		}
		index ++;
	}

	QTextStream stream(&file);
	doc.save(stream, 4);
	file.close();
	return true;
}

bool tcFavouriteManager::CreateDefaultFile()
{
	if (mFavouriteGroupList.count() == 0) {
		tcFavouriteGroup *group = AppendFavouriteGroup(tr("Default Group"));
		if (group == NULL) {
			tcLogService::CreateLog(this, "Error when create defult group.");
			return false;
		}
	}
	if (! SaveToFile()) {
		tcLogService::CreateLog(this, "Error when save favourite file.");
		return false;
	}
	return true;
}

tcFavouriteGroup* tcFavouriteManager::GetFavouriteGroup(int pIndex)
{
	if (pIndex < 0 || pIndex >= mFavouriteGroupList.count()) {
		return NULL;
	}
	return mFavouriteGroupList[pIndex];
}

int tcFavouriteManager::GetFavouriteGroupCount()
{
	return mFavouriteGroupList.count();
}

bool tcFavouriteManager::EditFavouriteStock(QWidget *pParent, int pGroupIndex)
{
	tcFavouriteInfoDialog dlg(pParent, pGroupIndex);
	dlg.exec();
	if (! SaveToFile()) {
		tcLogService::CreateLog(this, "Error when save favourite file.");
		return false;
	}
	return true;
}

tcFavouriteGroup* tcFavouriteManager::AppendFavouriteGroup(const QString &pGroupName)
{
	tcFavouriteGroup *group = new tcFavouriteGroup();
	group->SetGroupName(pGroupName);
	connect(group, SIGNAL(OnFavouriteGroupModified()), this, SLOT(DoFavouriteStockModified()));
	mFavouriteGroupList.append(group);
	return group;
}

tcFavouriteGroup* tcFavouriteManager::AppendFavouriteGroup(QWidget *pParent)
{
	tcFavouriteGroupInfoDialog dlg(pParent);
	if (dlg.exec() != QDialog::Accepted) {
		return NULL;
	}
	tcFavouriteGroup *group = AppendFavouriteGroup("");
	if (! group) {
		tcLogService::CreateLog(this, "Error when create favourite group.");
		return NULL;
	}
	if (! dlg.SaveToFavouriteGroup(group)) {
		delete group;
		tcLogService::CreateLog(this, "Error when save favourite group info.");
		return NULL;
	}
	emit OnFavouriteGroupModified();
	return group;
}

tcFavouriteGroup* tcFavouriteManager::ModifyFavouriteGroup(QWidget *pParent, int pGroupIndex)
{
	if (pGroupIndex < 0 || pGroupIndex >= mFavouriteGroupList.count()) {
		tcLogService::CreateLog(this, "Wrong favourite group index.");
		return NULL;
	}
	tcFavouriteGroup *group = mFavouriteGroupList[pGroupIndex];
	tcFavouriteGroupInfoDialog dlg(pParent);
	if (! dlg.LoadFromFavouriteGroup(group)) {
		tcLogService::CreateLog(this, "Error when load favourite group info.");
		return NULL;
	}
	if (dlg.exec() != QDialog::Accepted) {
		return NULL;
	}
	if (! dlg.SaveToFavouriteGroup(group)) {
		tcLogService::CreateLog(this, "Error when save favourite group info.");
		return NULL;
	}
	emit OnFavouriteGroupModified();
	return group;
}

bool tcFavouriteManager::RemoveFavouriteGroup(QWidget *pParent, int pGroupIndex)
{
	if (pGroupIndex < 0 || pGroupIndex >= mFavouriteGroupList.count()) {
		tcLogService::CreateLog(this, "Wrong favourite group index.");
		return false;
	}
	if (QMessageBox::question(pParent, SYSTEM_NAME, tr("Are you sure to remove this favourite group?"), QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel) {
		return false;
	}
	mFavouriteGroupList.removeAt(pGroupIndex);
	emit OnFavouriteGroupModified();
	return true;
}

bool tcFavouriteManager::GetStockInfoList(int pGroupIndex, tcStockInfoList *pStockInfoList)
{
	if (pGroupIndex < 0) {	//get all group's stocks
		foreach (tcFavouriteGroup *group, mFavouriteGroupList) {
			if (! group->GetStockInfoList(pStockInfoList)) {
				tcLogService::CreateLog(this, "Error when get stock info list.");
				return false;
			}
		}
		return true;
	}
	if (pGroupIndex >= 0 && pGroupIndex < mFavouriteGroupList.count()) {
		tcFavouriteGroup *group = mFavouriteGroupList[pGroupIndex];
		if (! group->GetStockInfoList(pStockInfoList)) {
			tcLogService::CreateLog(this, "Error when get stock info list.");
			return false;
		}
		return true;
	}
	return false;
}

bool tcFavouriteManager::GetStockInfoListFilter(int pGroupIndex, tcStockInfoList *pStockInfoList, const QString &pStockCodeFilter, const QString &pStockNameFilter)
{
	if (pGroupIndex < 0) {	//get all group's stocks
		foreach (tcFavouriteGroup *group, mFavouriteGroupList) {
			if (! group->GetStockInfoListFilter(pStockInfoList, pStockCodeFilter, pStockNameFilter)) {
				tcLogService::CreateLog(this, "Error when get stock info list.");
				return false;
			}
		}
		return true;
	}
	if (pGroupIndex >= 0 && pGroupIndex < mFavouriteGroupList.count()) {
		tcFavouriteGroup *group = mFavouriteGroupList[pGroupIndex];
		if (! group->GetStockInfoListFilter(pStockInfoList, pStockCodeFilter, pStockNameFilter)) {
			tcLogService::CreateLog(this, "Error when get stock info list.");
			return false;
		}
		return true;
	}
	return false;
}

void tcFavouriteManager::ClearAllFavouriteGroups()
{
	foreach (tcFavouriteGroup *group, mFavouriteGroupList) {
		delete group;
	}
	mFavouriteGroupList.clear();
}

void tcFavouriteManager::DoFavouriteStockModified()
{
	emit OnFavouriteStockModified((tcFavouriteGroup*)sender());
}

#ifdef WIN32
	#include "moc_tcfavouritemgr.cpp"
#endif
