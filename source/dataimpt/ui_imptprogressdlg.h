/********************************************************************************
** Form generated from reading ui file 'ui_imptprogressdlg.ui'
**
** Created: Mon Mar 19 17:17:07 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_IMPTPROGRESSDLG_H
#define UI_IMPTPROGRESSDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QProgressBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

class Ui_tcImportProgressDialog
{
public:
    QVBoxLayout *vboxLayout;
    QProgressBar *pgs1;
    QTextEdit *edt1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcImportProgressDialog)
    {
    tcImportProgressDialog->setObjectName(QString::fromUtf8("tcImportProgressDialog"));
    vboxLayout = new QVBoxLayout(tcImportProgressDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    pgs1 = new QProgressBar(tcImportProgressDialog);
    pgs1->setObjectName(QString::fromUtf8("pgs1"));
    pgs1->setValue(0);
    pgs1->setOrientation(Qt::Horizontal);

    vboxLayout->addWidget(pgs1);

    edt1 = new QTextEdit(tcImportProgressDialog);
    edt1->setObjectName(QString::fromUtf8("edt1"));
    edt1->setReadOnly(true);

    vboxLayout->addWidget(edt1);

    buttonBox = new QDialogButtonBox(tcImportProgressDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Abort|QDialogButtonBox::Close|QDialogButtonBox::NoButton);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcImportProgressDialog);

    QSize size(599, 343);
    size = size.expandedTo(tcImportProgressDialog->minimumSizeHint());
    tcImportProgressDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcImportProgressDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcImportProgressDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcImportProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *tcImportProgressDialog)
    {
    tcImportProgressDialog->setWindowTitle(QApplication::translate("tcImportProgressDialog", "Import Progress...", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcImportProgressDialog);
    } // retranslateUi

};

namespace Ui {
    class tcImportProgressDialog: public Ui_tcImportProgressDialog {};
} // namespace Ui

#endif // UI_IMPTPROGRESSDLG_H
