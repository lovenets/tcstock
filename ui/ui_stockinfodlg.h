/********************************************************************************
** Form generated from reading ui file 'ui_stockinfodlg.ui'
**
** Created: Sat Mar 17 20:49:30 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STOCKINFODLG_H
#define UI_STOCKINFODLG_H

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

class Ui_tcStockInfoDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbx1;
    QGridLayout *gridLayout;
    QLineEdit *edt1;
    QLineEdit *edt2;
    QLineEdit *edt3;
    QLabel *lbl1;
    QLabel *lbl2;
    QLabel *lbl3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcStockInfoDialog)
    {
    tcStockInfoDialog->setObjectName(QString::fromUtf8("tcStockInfoDialog"));
    vboxLayout = new QVBoxLayout(tcStockInfoDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    gbx1 = new QGroupBox(tcStockInfoDialog);
    gbx1->setObjectName(QString::fromUtf8("gbx1"));
    gridLayout = new QGridLayout(gbx1);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    edt1 = new QLineEdit(gbx1);
    edt1->setObjectName(QString::fromUtf8("edt1"));

    gridLayout->addWidget(edt1, 0, 1, 1, 1);

    edt2 = new QLineEdit(gbx1);
    edt2->setObjectName(QString::fromUtf8("edt2"));

    gridLayout->addWidget(edt2, 1, 1, 1, 1);

    edt3 = new QLineEdit(gbx1);
    edt3->setObjectName(QString::fromUtf8("edt3"));

    gridLayout->addWidget(edt3, 2, 1, 1, 1);

    lbl1 = new QLabel(gbx1);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    gridLayout->addWidget(lbl1, 0, 0, 1, 1);

    lbl2 = new QLabel(gbx1);
    lbl2->setObjectName(QString::fromUtf8("lbl2"));

    gridLayout->addWidget(lbl2, 1, 0, 1, 1);

    lbl3 = new QLabel(gbx1);
    lbl3->setObjectName(QString::fromUtf8("lbl3"));

    gridLayout->addWidget(lbl3, 2, 0, 1, 1);


    vboxLayout->addWidget(gbx1);

    buttonBox = new QDialogButtonBox(tcStockInfoDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcStockInfoDialog);

    QSize size(400, 155);
    size = size.expandedTo(tcStockInfoDialog->minimumSizeHint());
    tcStockInfoDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcStockInfoDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcStockInfoDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcStockInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *tcStockInfoDialog)
    {
    tcStockInfoDialog->setWindowTitle(QApplication::translate("tcStockInfoDialog", "Stock Info...", 0, QApplication::UnicodeUTF8));
    gbx1->setTitle(QApplication::translate("tcStockInfoDialog", "Info:", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcStockInfoDialog", "Stock Code:", 0, QApplication::UnicodeUTF8));
    lbl2->setText(QApplication::translate("tcStockInfoDialog", "Name:", 0, QApplication::UnicodeUTF8));
    lbl3->setText(QApplication::translate("tcStockInfoDialog", "Description:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcStockInfoDialog);
    } // retranslateUi

};

namespace Ui {
    class tcStockInfoDialog: public Ui_tcStockInfoDialog {};
} // namespace Ui

#endif // UI_STOCKINFODLG_H
