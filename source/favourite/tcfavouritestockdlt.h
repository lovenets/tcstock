#ifndef tcfavouritestockdlt_h

#define tcfavouritestockdlt_h

#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtGui/QItemDelegate>

/*! \brief tcFavouriteStockDelegate
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.26
 	
	自选股票列表显示用Delegate。被 tcFavouriteInfoDialog 使用。
*/
class tcFavouriteStockDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	tcFavouriteStockDelegate(QObject *pParent);

};

#endif //tcfavouritestockdlt_h


