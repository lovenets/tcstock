#ifndef tcstockinfo_h

#define tcstockinfo_h

#include <QtCore/QVariant>
#include <QtCore/QObject>

#include "tcstock.h"

class tcStockInfo;

typedef QList<tcStockInfo> tcStockInfoList;

/*! \brief tcStockInfo
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.26
 	
	类似于Handle的一个类，用来指向系统中的某个 tcStock ，
	其同时包含股市编号和股票代码，因此系统中要保存某个股票指针时，一般不要直接使用 tcstock 的指针，
	而应该使用该类，当该类指向的 tcStock 对象被删除时，该类可以自适应，保证不会访问到非法地址。
*/
class tcStockInfo : public QObject
{
	Q_OBJECT

public:
	tcStockInfo(int pMarketIndex, const QString &pStockCode);

	tcStockInfo(const tcStockInfo &pInfo);

	tcStock* GetStock();

	int GetMarketIndex();

	QString GetStockCode();

	void ConnectMarketIndexModifiedSignal();

	tcStockInfo& operator=(const tcStockInfo &pInfo);

	bool operator==(const tcStockInfo &pInfo);

	QString GetMarketName();

	QString GetStockName();

protected:
	tcStockInfo();

protected slots:
	/*!
		notify by tcMarket when the market's index changed.
	*/
	void DoMarketIndexModified(int pNewIndex);

protected:
	int mMarketIndex;

	QString mStockCode;

};

#endif //tcstockinfo_h
