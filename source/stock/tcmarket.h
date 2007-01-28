#ifndef tcmarket_h

#define tcmarket_h

#include <QtCore/QVariant>
#include <QtCore/QObject>

#include "tcstock.h"
#include "tcstockinfo.h"
#include "tcstockdatacache.h"

/*! \brief tcMarket
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.02
 	
	股市定义类，负责加载和管理该股市下的所有股票信息。
*/
class tcMarket : public QObject
{
	Q_OBJECT

public:
	tcMarket(const QDir &pPath);

	~tcMarket();

	bool LoadFromFile();

	bool SaveToFile();

	bool SaveAllStockData();

	tcStock* GetStockByCode(const QString &pStockCode);

	tcStock* AppendStock(const QString &pStockCode, const QString &pStockName);

	tcStock* AppendStock(QWidget *pParent);

	tcStock* ModifyStock(QWidget *pParent, const QString &pStockCode);

	bool RemoveStock(QWidget *pParent, const QString &pStockCode);

	bool GetStockInfoList(tcStockInfoList *pStockInfoList);

	bool GetStockInfoListFilter(tcStockInfoList *pStockInfoList, const QString &pStockCodeFilter, const QString &pStockNameFilter);

	void ClearAllStocks();

	int GetIndex();

	void SetIndex(int pValue);

	QString GetName();

	void SetName(const QString pName);

	QString GetDescription();

	void SetDescription(const QString &pDescription);

private:
	QDir mPath;

	QMap<QString, tcStock*> mStockMap;

	tcStockDataCache *mStockDataCache;

	int mIndex;

	QString mName;

	QString mDescription;

signals:
	/*!
		notify the tcStockInfo when the market's index changed, so the tcStockInfo can still point to the same tcMarket.
	*/
	void OnIndexModified(int pNewIndex);

	void OnStockModified();

};

inline tcStock* tcMarket::GetStockByCode(const QString &pStockCode)
{
	if (! mStockMap.contains(pStockCode)) {
		return NULL;
	}
	return mStockMap[pStockCode];
}

#endif //tcmarket_h
