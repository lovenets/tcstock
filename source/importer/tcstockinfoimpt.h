#ifndef tcstockinfoimpt_h

#define tcstockinfoimpt_h

#include <QtCore/QVariant>
#include <QtCore/QObject>

/*! \brief tcStockInfoImporter
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.28

	股票信息导入类，可以从CSV格式的文件导入股票信息。

	文件格式如下：
	[stock code],[stock name],[UNKNOWN],[stock pinyin],[stock english name]
	...
*/
class tcStockInfoImporter : public QObject
{
	Q_OBJECT

public:
	tcStockInfoImporter();

	~tcStockInfoImporter();

	int LoadFromFile(const QString &pFileName, int pMarketIndex);

};

#endif //tcstockinfoimpt_h


