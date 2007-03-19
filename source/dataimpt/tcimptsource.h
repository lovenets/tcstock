#ifndef tcimptsource_h

#define tcimptsource_h

#include <QtCore/QVariant>
#include <QtCore/QObject>

/*! \brief tcImportSource
 	\author tony (http://www.tonixsoft.com)
 	\version 0.02
 	\date 2007.03.18
 	
	数据导入源的基类。
*/
class tcImportSource : public QObject
{
	Q_OBJECT

public:
	tcImportSource();

	~tcImportSource();

	virtual QString GetDescription();

	virtual bool HaveSettingDialog();

	virtual void ShowSettingDialog(QWidget *pParent);

	virtual bool Import();

signals:
	void OnUpdateProgress(int pProgress);

	void OnAppendMessage(const QString &pMessage, bool pSuccess);

};

#endif //tcimptsource_h
