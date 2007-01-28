#include "tcfavouritestockdlt.h"

#include <QtCore/QModelIndex>

#include "tcfavouritestockmdl.h"

tcFavouriteStockDelegate::tcFavouriteStockDelegate(QObject *pParent)
	: QItemDelegate(pParent)
{
}

#ifdef WIN32
	#include "moc_tcfavouritestockdlt.cpp"
#endif
