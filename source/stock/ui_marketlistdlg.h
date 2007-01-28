/********************************************************************************
** Form generated from reading ui file 'ui_marketlistdlg.ui'
**
** Created: Thu Dec 7 08:50:24 2006
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MARKETLISTDLG_H
#define UI_MARKETLISTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

class Ui_tcMarketListDialog
{
public:
    QVBoxLayout *vboxLayout;
    QTableWidget *tbl1;
    QHBoxLayout *hboxLayout;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QSpacerItem *spacerItem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcMarketListDialog)
    {
    tcMarketListDialog->setObjectName(QString::fromUtf8("tcMarketListDialog"));
    vboxLayout = new QVBoxLayout(tcMarketListDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    tbl1 = new QTableWidget(tcMarketListDialog);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout->addWidget(tbl1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    btn1 = new QPushButton(tcMarketListDialog);
    btn1->setObjectName(QString::fromUtf8("btn1"));

    hboxLayout->addWidget(btn1);

    btn2 = new QPushButton(tcMarketListDialog);
    btn2->setObjectName(QString::fromUtf8("btn2"));

    hboxLayout->addWidget(btn2);

    btn3 = new QPushButton(tcMarketListDialog);
    btn3->setObjectName(QString::fromUtf8("btn3"));

    hboxLayout->addWidget(btn3);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    vboxLayout->addLayout(hboxLayout);

    buttonBox = new QDialogButtonBox(tcMarketListDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Close);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcMarketListDialog);

    QSize size(498, 245);
    size = size.expandedTo(tcMarketListDialog->minimumSizeHint());
    tcMarketListDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcMarketListDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcMarketListDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcMarketListDialog);
    } // setupUi

    void retranslateUi(QDialog *tcMarketListDialog)
    {
    tcMarketListDialog->setWindowTitle(QApplication::translate("tcMarketListDialog", "Market List...", 0, QApplication::UnicodeUTF8));
    btn1->setText(QApplication::translate("tcMarketListDialog", "Add Market", 0, QApplication::UnicodeUTF8));
    btn2->setText(QApplication::translate("tcMarketListDialog", "Modify Market", 0, QApplication::UnicodeUTF8));
    btn3->setText(QApplication::translate("tcMarketListDialog", "Remove Market", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcMarketListDialog);
    } // retranslateUi

};

namespace Ui {
    class tcMarketListDialog: public Ui_tcMarketListDialog {};
} // namespace Ui

#endif // UI_MARKETLISTDLG_H
