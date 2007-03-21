/********************************************************************************
** Form generated from reading ui file 'ui_sinawebimptsourcedlg.ui'
**
** Created: Wed Mar 21 09:51:13 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SINAWEBIMPTSOURCEDLG_H
#define UI_SINAWEBIMPTSOURCEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

class Ui_tcSinaWebImportSourceDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *grp1;
    QVBoxLayout *vboxLayout1;
    QTableWidget *tbl1;
    QLabel *lbl1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcSinaWebImportSourceDialog)
    {
    tcSinaWebImportSourceDialog->setObjectName(QString::fromUtf8("tcSinaWebImportSourceDialog"));
    vboxLayout = new QVBoxLayout(tcSinaWebImportSourceDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    grp1 = new QGroupBox(tcSinaWebImportSourceDialog);
    grp1->setObjectName(QString::fromUtf8("grp1"));
    vboxLayout1 = new QVBoxLayout(grp1);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    tbl1 = new QTableWidget(grp1);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout1->addWidget(tbl1);

    lbl1 = new QLabel(grp1);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    vboxLayout1->addWidget(lbl1);


    vboxLayout->addWidget(grp1);

    buttonBox = new QDialogButtonBox(tcSinaWebImportSourceDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcSinaWebImportSourceDialog);

    QSize size(493, 254);
    size = size.expandedTo(tcSinaWebImportSourceDialog->minimumSizeHint());
    tcSinaWebImportSourceDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcSinaWebImportSourceDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcSinaWebImportSourceDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcSinaWebImportSourceDialog);
    } // setupUi

    void retranslateUi(QDialog *tcSinaWebImportSourceDialog)
    {
    tcSinaWebImportSourceDialog->setWindowTitle(QApplication::translate("tcSinaWebImportSourceDialog", "Sina Web Import Source Setting...", 0, QApplication::UnicodeUTF8));
    grp1->setTitle(QApplication::translate("tcSinaWebImportSourceDialog", "Setting:", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcSinaWebImportSourceDialog", "Thanks http://stock.sina.com.cn for it's stock data.", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcSinaWebImportSourceDialog);
    } // retranslateUi

};

namespace Ui {
    class tcSinaWebImportSourceDialog: public Ui_tcSinaWebImportSourceDialog {};
} // namespace Ui

#endif // UI_SINAWEBIMPTSOURCEDLG_H
