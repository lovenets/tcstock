/********************************************************************************
** Form generated from reading ui file 'ui_stockselectdlg.ui'
**
** Created: Tue Dec 26 17:37:40 2006
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STOCKSELECTDLG_H
#define UI_STOCKSELECTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

class Ui_tcStockSelectDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QGroupBox *grp1;
    QVBoxLayout *vboxLayout1;
    QComboBox *cbo1;
    QGroupBox *grp2;
    QHBoxLayout *hboxLayout1;
    QLabel *lbl1;
    QLineEdit *edt1;
    QLabel *lbl2;
    QLineEdit *edt2;
    QSpacerItem *spacerItem;
    QTableWidget *tbl1;
    QCheckBox *chk1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcStockSelectDialog)
    {
    tcStockSelectDialog->setObjectName(QString::fromUtf8("tcStockSelectDialog"));
    vboxLayout = new QVBoxLayout(tcStockSelectDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    grp1 = new QGroupBox(tcStockSelectDialog);
    grp1->setObjectName(QString::fromUtf8("grp1"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(5));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(grp1->sizePolicy().hasHeightForWidth());
    grp1->setSizePolicy(sizePolicy);
    vboxLayout1 = new QVBoxLayout(grp1);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    cbo1 = new QComboBox(grp1);
    cbo1->setObjectName(QString::fromUtf8("cbo1"));

    vboxLayout1->addWidget(cbo1);


    hboxLayout->addWidget(grp1);

    grp2 = new QGroupBox(tcStockSelectDialog);
    grp2->setObjectName(QString::fromUtf8("grp2"));
    hboxLayout1 = new QHBoxLayout(grp2);
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(9);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    lbl1 = new QLabel(grp2);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    hboxLayout1->addWidget(lbl1);

    edt1 = new QLineEdit(grp2);
    edt1->setObjectName(QString::fromUtf8("edt1"));

    hboxLayout1->addWidget(edt1);

    lbl2 = new QLabel(grp2);
    lbl2->setObjectName(QString::fromUtf8("lbl2"));

    hboxLayout1->addWidget(lbl2);

    edt2 = new QLineEdit(grp2);
    edt2->setObjectName(QString::fromUtf8("edt2"));

    hboxLayout1->addWidget(edt2);


    hboxLayout->addWidget(grp2);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    vboxLayout->addLayout(hboxLayout);

    tbl1 = new QTableWidget(tcStockSelectDialog);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout->addWidget(tbl1);

    chk1 = new QCheckBox(tcStockSelectDialog);
    chk1->setObjectName(QString::fromUtf8("chk1"));

    vboxLayout->addWidget(chk1);

    buttonBox = new QDialogButtonBox(tcStockSelectDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcStockSelectDialog);

    QSize size(664, 437);
    size = size.expandedTo(tcStockSelectDialog->minimumSizeHint());
    tcStockSelectDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcStockSelectDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcStockSelectDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcStockSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *tcStockSelectDialog)
    {
    tcStockSelectDialog->setWindowTitle(QApplication::translate("tcStockSelectDialog", "Select Stock...", 0, QApplication::UnicodeUTF8));
    grp1->setTitle(QApplication::translate("tcStockSelectDialog", "Market:", 0, QApplication::UnicodeUTF8));
    grp2->setTitle(QApplication::translate("tcStockSelectDialog", "Filter:", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcStockSelectDialog", "Stock Code:", 0, QApplication::UnicodeUTF8));
    lbl2->setText(QApplication::translate("tcStockSelectDialog", "Name:", 0, QApplication::UnicodeUTF8));
    chk1->setText(QApplication::translate("tcStockSelectDialog", "Select All Stocks", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcStockSelectDialog);
    } // retranslateUi

};

namespace Ui {
    class tcStockSelectDialog: public Ui_tcStockSelectDialog {};
} // namespace Ui

#endif // UI_STOCKSELECTDLG_H
