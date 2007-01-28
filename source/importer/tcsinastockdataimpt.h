#ifndef tcsinastockdataimpt_h

#define tcsinastockdataimpt_h

#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtNetwork/QHttp>

/*! \brief tcSinaStockDataImporter
 	\author tony (http://www.tonixsoft.com)
 	\version 0.01
 	\date 2006.12.29

	新浪数据导入类，通过直接访问新浪的股票数据网页来获得每日数据。
	数据来自：http://stock.sina.com.cn/stock/quote/sha0.html 之类的网页。
	目前开发中。
*/
class tcSinaStockDataImporter : public QObject
{
	Q_OBJECT

public:
	tcSinaStockDataImporter();

	~tcSinaStockDataImporter();

	int LoadStockData();

protected slots:
	void DoRequestFinished(int pId, bool pError);

	void DoDone(bool pError);

private:
	QHttp mHttp;

};

#endif //tcsinastockdataimpt_h
