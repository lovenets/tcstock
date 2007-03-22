#ifndef tcfxjfileimptsource_h

#define tcfxjfileimptsource_h

#include <QtCore/QVariant>
#include <QtCore/QObject>

#include "tcimptsource.h"

typedef struct {
	bool DownloadZipFile;
	QString ZipFileUrl;
	QString DataFilePath;
} tcFxjFileImportSourceOption;

/*! \brief tcFxjFileImportSource
 	\author tony (tonixinot@gmail.com)
 	\version 0.02
 	\date 2007.03.22
 	
	http://www.fxj.net.cn
*/
class tcFxjFileImportSource : public tcImportSource
{
	Q_OBJECT

public:
	tcFxjFileImportSource();

	virtual QString GetDescription();

	virtual bool HaveSettingDialog();

	virtual void ShowSettingDialog(QWidget *pParent);

protected:
	virtual bool ImportProcess();

	virtual void CancelImportProcess();

	void GetOptions(tcFxjFileImportSourceOption &pOption);

	void SetOptions(const tcFxjFileImportSourceOption &pOption);

	bool ProcessOneFile(const QDate &pDate, const QString &pFileName);

private:
	bool mIsCanceling;
};

#endif //tcfxjfileimptsource_h
