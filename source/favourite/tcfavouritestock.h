#ifndef tcfavouritestock_h

#define tcfavouritestock_h

#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

#include "../stock/tcstockpack.h"

/*! \brief tcFavouriteStock
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.24

 	wrap of the tcStock for the favourite stock.
*/
class tcFavouriteStock : public QObject
{
	Q_OBJECT

public:
	tcFavouriteStock();

	~tcFavouriteStock();

	bool LoadFromXml(const QDomElement &pElement);

	bool SaveToXml(QDomDocument &pDoc, QDomElement &pElement);

	bool BindToStock(int pMarketIndex, const QString &pStockCode);

	bool IsBinded();

private:
	int mMarketIndex;

	QString mStockCode;

	tcStock *mBindedStock;

};

#endif //tcfavouritestock_h
