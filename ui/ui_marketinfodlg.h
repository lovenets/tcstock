/********************************************************************************
** Form generated from reading ui file 'ui_marketinfodlg.ui'
**
** Created: Sat Mar 17 21:11:56 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MARKETINFODLG_H
#define UI_MARKETINFODLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

class Ui_tcMarketInfoDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbx1;
    QGridLayout *gridLayout;
    QLineEdit *edt1;
    QLabel *lbl2;
    QLabel *lbl1;
    QLineEdit *edt2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcMarketInfoDialog)
    {
    tcMarketInfoDialog->setObjectName(QString::fromUtf8("tcMarketInfoDialog"));
    vboxLayout = new QVBoxLayout(tcMarketInfoDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    gbx1 = new QGroupBox(tcMarketInfoDialog);
    gbx1->setObjectName(QString::fromUtf8("gbx1"));
    gridLayout = new QGridLayout(gbx1);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    edt1 = new QLineEdit(gbx1);
    edt1->setObjectName(QString::fromUtf8("edt1"));

    gridLayout->addWidget(edt1, 0, 1, 1, 1);

    lbl2 = new QLabel(gbx1);
    lbl2->setObjectName(QString::fromUtf8("lbl2"));

    gridLayout->addWidget(lbl2, 1, 0, 1, 1);

    lbl1 = new QLabel(gbx1);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    gridLayout->addWidget(lbl1, 0, 0, 1, 1);

    edt2 = new QLineEdit(gbx1);
    edt2->setObjectName(QString::fromUtf8("edt2"));

    gridLayout->addWidget(edt2, 1, 1, 1, 1);


    vboxLayout->addWidget(gbx1);

    buttonBox = new QDialogButtonBox(tcMarketInfoDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcMarketInfoDialog);

    QSize size(321, 128);
    size = size.expandedTo(tcMarketInfoDialog->minimumSizeHint());
    tcMarketInfoDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcMarketInfoDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcMarketInfoDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcMarketInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *tcMarketInfoDialog)
    {
    tcMarketInfoDialog->setWindowTitle(QApplication::translate("tcMarketInfoDialog", "Market Info...", 0, QApplication::UnicodeUTF8));
    gbx1->setTitle(QApplication::translate("tcMarketInfoDialog", "Info:", 0, QApplication::UnicodeUTF8));
    lbl2->setText(QApplication::translate("tcMarketInfoDialog", "Description:", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcMarketInfoDialog", "Name:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcMarketInfoDialog);
    } // retranslateUi

};

namespace Ui {
    class tcMarketInfoDialog: public Ui_tcMarketInfoDialog {};
} // namespace Ui

#endif // UI_MARKETINFODLG_H
