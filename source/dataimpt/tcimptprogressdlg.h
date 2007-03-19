#ifndef tcimptprogressdlg_h

#define tcimptprogressdlg_h

#include <QtCore/QVariant>
#include <QtGui/QDialog>
#include "ui_imptprogressdlg.h"

#include "tcimptsource.h"

/*! \brief tcImportProgressDialog
 	\author tony (http://www.tonixsoft.com)
 	\version 0.02
 	\date 2007.03.19
*/
class tcImportProgressDialog : public QDialog, private Ui_tcImportProgressDialog
{
	Q_OBJECT

public:
	tcImportProgressDialog(QWidget *pParent, tcImportSource *pImportSource);

	~tcImportProgressDialog();

protected slots:
	void DoUpdateProgress(int pProgress);

	void DoAppendMessage(const QString &pMessage, bool pSuccess);

};

#endif //tcimptprogressdlg_h
