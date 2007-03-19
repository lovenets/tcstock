#ifndef tcsinawebimptsource_h

#define tcsinawebimptsource_h

#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtNetwork/QHttp>

#include "tcimptsource.h"

/*! \brief tcSinaWebImportSource
 	\author tony (http://www.tonixsoft.com)
 	\version 0.02
 	\date 2007.03.18
 	
	从新浪网站导入股票每日数据。
	http://stock.sina.com.cn/stock/quote/sha0.html
*/
class tcSinaWebImportSource : public tcImportSource
{
	Q_OBJECT

public:
	tcSinaWebImportSource();

	QString GetDescription();

	bool HaveSettingDialog();

	void ShowSettingDialog(QWidget *pParent);

	bool Import();

protected:
	bool ProcessForOnePage(const QString &pPageUrl);

	void ProcessForOneStock(const QString &pText);

protected slots:
	void DoHttpDone(bool pError);

private:
	QHttp *mHttp;

	bool mIsReceiving;

	QString mReceivedData;

};

#endif //tcsinawebimptsource_h
