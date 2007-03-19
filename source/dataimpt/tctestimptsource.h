#ifndef tctestimptsource_h

#define tctestimptsource_h

#include <QtCore/QVariant>
#include <QtCore/QObject>

#include "tcimptsource.h"

/*! \brief tcTestImportSource
 	\author tony (http://www.tonixsoft.com)
 	\version 0.02
 	\date 2007.03.19

*/
class tcTestImportSource : public tcImportSource
{
	Q_OBJECT

public:
	tcTestImportSource();

	~tcTestImportSource();

	QString GetDescription();

	bool Import();

};

#endif //tctestimptsource_h
