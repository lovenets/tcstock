/********************************************************************************
** Form generated from reading ui file 'ui_stockdatainfodlg.ui'
**
** Created: Sat Mar 17 21:11:56 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STOCKDATAINFODLG_H
#define UI_STOCKDATAINFODLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

class Ui_tcStockDataInfoDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QGroupBox *gbx1;
    QHBoxLayout *hboxLayout1;
    QDateEdit *cld1;
    QGroupBox *gbx2;
    QHBoxLayout *hboxLayout2;
    QLabel *lbl1;
    QComboBox *cbo1;
    QLabel *lbl2;
    QLineEdit *edt1;
    QLabel *lbl3;
    QLineEdit *edt2;
    QSpacerItem *spacerItem;
    QTableView *tbl1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcStockDataInfoDialog)
    {
    tcStockDataInfoDialog->setObjectName(QString::fromUtf8("tcStockDataInfoDialog"));
    vboxLayout = new QVBoxLayout(tcStockDataInfoDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    gbx1 = new QGroupBox(tcStockDataInfoDialog);
    gbx1->setObjectName(QString::fromUtf8("gbx1"));
    hboxLayout1 = new QHBoxLayout(gbx1);
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(9);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    cld1 = new QDateEdit(gbx1);
    cld1->setObjectName(QString::fromUtf8("cld1"));
    cld1->setCalendarPopup(true);

    hboxLayout1->addWidget(cld1);


    hboxLayout->addWidget(gbx1);

    gbx2 = new QGroupBox(tcStockDataInfoDialog);
    gbx2->setObjectName(QString::fromUtf8("gbx2"));
    hboxLayout2 = new QHBoxLayout(gbx2);
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(9);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    lbl1 = new QLabel(gbx2);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    hboxLayout2->addWidget(lbl1);

    cbo1 = new QComboBox(gbx2);
    cbo1->setObjectName(QString::fromUtf8("cbo1"));

    hboxLayout2->addWidget(cbo1);

    lbl2 = new QLabel(gbx2);
    lbl2->setObjectName(QString::fromUtf8("lbl2"));

    hboxLayout2->addWidget(lbl2);

    edt1 = new QLineEdit(gbx2);
    edt1->setObjectName(QString::fromUtf8("edt1"));

    hboxLayout2->addWidget(edt1);

    lbl3 = new QLabel(gbx2);
    lbl3->setObjectName(QString::fromUtf8("lbl3"));

    hboxLayout2->addWidget(lbl3);

    edt2 = new QLineEdit(gbx2);
    edt2->setObjectName(QString::fromUtf8("edt2"));

    hboxLayout2->addWidget(edt2);


    hboxLayout->addWidget(gbx2);

    spacerItem = new QSpacerItem(281, 56, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    vboxLayout->addLayout(hboxLayout);

    tbl1 = new QTableView(tcStockDataInfoDialog);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout->addWidget(tbl1);

    buttonBox = new QDialogButtonBox(tcStockDataInfoDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Close);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcStockDataInfoDialog);

    QSize size(872, 536);
    size = size.expandedTo(tcStockDataInfoDialog->minimumSizeHint());
    tcStockDataInfoDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcStockDataInfoDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcStockDataInfoDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcStockDataInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *tcStockDataInfoDialog)
    {
    tcStockDataInfoDialog->setWindowTitle(QApplication::translate("tcStockDataInfoDialog", "Stock Data...", 0, QApplication::UnicodeUTF8));
    gbx1->setTitle(QApplication::translate("tcStockDataInfoDialog", "Date:", 0, QApplication::UnicodeUTF8));
    gbx2->setTitle(QApplication::translate("tcStockDataInfoDialog", "Filter:", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcStockDataInfoDialog", "Group:", 0, QApplication::UnicodeUTF8));
    lbl2->setText(QApplication::translate("tcStockDataInfoDialog", "Stock Code:", 0, QApplication::UnicodeUTF8));
    lbl3->setText(QApplication::translate("tcStockDataInfoDialog", "Name:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcStockDataInfoDialog);
    } // retranslateUi

};

namespace Ui {
    class tcStockDataInfoDialog: public Ui_tcStockDataInfoDialog {};
} // namespace Ui

#endif // UI_STOCKDATAINFODLG_H
