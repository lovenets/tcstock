#ifndef tcfavouritestockinfo_h

#define tcfavouritestockinfo_h

#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

#include "../stock/tcstockpack.h"

/*! \brief tcFavouriteStockInfo
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.24

 	自选股票信息类，每个对象用于指定一个股票作为自选股。
	为了实现对股票的绑定，该类从 tcStockInfo 类继承。
*/
class tcFavouriteStockInfo : public tcStockInfo
{
	Q_OBJECT

public:
	tcFavouriteStockInfo(int pMarketIndex, const QString &pStockCode);

	/*!
		initialize by read from xml.
	*/
	tcFavouriteStockInfo(const QDomElement &pElement);

	tcFavouriteStockInfo(const tcStockInfo &pStockInfo);

	~tcFavouriteStockInfo();

	bool SaveToXml(QDomDocument &pDoc, QDomElement &pElement);

private:

};

#endif //tcfavouritestockinfo_h
