#include "tcimptprogressdlg.h"

tcImportProgressDialog::tcImportProgressDialog(QWidget *pParent, tcImportSource *pImportSource)
	: QDialog(pParent)
{
	setupUi(this);
	this->setWindowModality(Qt::WindowModal);
	connect(pImportSource, SIGNAL(OnUpdateProgress(int)), this, SLOT(DoUpdateProgress(int)));
	connect(pImportSource, SIGNAL(OnAppendMessage(const QString &, bool)), this, SLOT(DoAppendMessage(const QString &, bool)));
}

tcImportProgressDialog::~tcImportProgressDialog()
{
}

void tcImportProgressDialog::DoUpdateProgress(int pProgress)
{
	pgs1->setValue(pProgress);
}

void tcImportProgressDialog::DoAppendMessage(const QString &pMessage, bool pSuccess)
{
	if (pSuccess) {
		edt1->append("<font color=blue>" + pMessage + "</font>");
	}
	else {
		edt1->append("<font color=red>" + pMessage + "</font>");
	}
}

#include "moc_tcimptprogressdlg.cpp"
