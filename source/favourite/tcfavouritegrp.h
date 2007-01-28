#ifndef tcfavouritegrp_h

#define tcfavouritegrp_h

#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

#include "tcfavouritestockinfo.h"

typedef QList<tcFavouriteStockInfo> tcFavouriteInfoList;

/*! \brief tcFavouriteGroup
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.24

 	自选股票组管理类。
*/
class tcFavouriteGroup : public QObject
{
	Q_OBJECT

public:
	tcFavouriteGroup();

	~tcFavouriteGroup();

	bool LoadFromXml(const QDomElement &pElement);

	bool SaveToXml(QDomDocument &pDoc, QDomElement &pElement);

	tcFavouriteStockInfo* GetFavouriteStock(int pIndex);

	int GetFavouriteStockCount();

	bool IsFavouriteStockExists(const tcStockInfo &pStockInfo);

	tcFavouriteStockInfo* AppendFavouriteStock(const tcStockInfo &pStockInfo);

	bool AppendFavouriteStock(QWidget *pParent);

	bool RemoveFavouriteStock(QWidget *pParent, int pIndex);

	bool GetStockInfoList(tcStockInfoList *pStockInfoList);

	bool GetStockInfoListFilter(tcStockInfoList *pStockInfoList, const QString &pStockCodeFilter, const QString &pStockNameFilter);

	QString GetGroupName();

	void SetGroupName(const QString &pValue);

	QString GetDescription();

	void SetDescription(const QString &pValue);

protected:
	void ClearAllFavouriteStocks();

private:
	QList<tcFavouriteStockInfo*> mFavouriteStockList;

	QString mGroupName;

	QString mDescription;

signals:
	void OnFavouriteStockModified();

};

#endif //tcfavouritegrp_h
