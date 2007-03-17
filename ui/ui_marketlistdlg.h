/********************************************************************************
** Form generated from reading ui file 'ui_marketlistdlg.ui'
**
** Created: Sat Mar 17 21:11:56 2007
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

class Ui_tcMarketListDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbx1;
    QHBoxLayout *hboxLayout;
    QLabel *lbl1_1;
    QComboBox *cbo1_1;
    QPushButton *btn1_1;
    QPushButton *btn1_2;
    QPushButton *btn1_3;
    QSpacerItem *spacerItem;
    QTableWidget *tbl1;
    QHBoxLayout *hboxLayout1;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QSpacerItem *spacerItem1;
    QPushButton *btn4;
    QPushButton *btn5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcMarketListDialog)
    {
    tcMarketListDialog->setObjectName(QString::fromUtf8("tcMarketListDialog"));
    vboxLayout = new QVBoxLayout(tcMarketListDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    gbx1 = new QGroupBox(tcMarketListDialog);
    gbx1->setObjectName(QString::fromUtf8("gbx1"));
    hboxLayout = new QHBoxLayout(gbx1);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(9);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    lbl1_1 = new QLabel(gbx1);
    lbl1_1->setObjectName(QString::fromUtf8("lbl1_1"));

    hboxLayout->addWidget(lbl1_1);

    cbo1_1 = new QComboBox(gbx1);
    cbo1_1->setObjectName(QString::fromUtf8("cbo1_1"));

    hboxLayout->addWidget(cbo1_1);

    btn1_1 = new QPushButton(gbx1);
    btn1_1->setObjectName(QString::fromUtf8("btn1_1"));

    hboxLayout->addWidget(btn1_1);

    btn1_2 = new QPushButton(gbx1);
    btn1_2->setObjectName(QString::fromUtf8("btn1_2"));

    hboxLayout->addWidget(btn1_2);

    btn1_3 = new QPushButton(gbx1);
    btn1_3->setObjectName(QString::fromUtf8("btn1_3"));

    hboxLayout->addWidget(btn1_3);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    vboxLayout->addWidget(gbx1);

    tbl1 = new QTableWidget(tcMarketListDialog);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout->addWidget(tbl1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    btn1 = new QPushButton(tcMarketListDialog);
    btn1->setObjectName(QString::fromUtf8("btn1"));

    hboxLayout1->addWidget(btn1);

    btn2 = new QPushButton(tcMarketListDialog);
    btn2->setObjectName(QString::fromUtf8("btn2"));

    hboxLayout1->addWidget(btn2);

    btn3 = new QPushButton(tcMarketListDialog);
    btn3->setObjectName(QString::fromUtf8("btn3"));

    hboxLayout1->addWidget(btn3);

    spacerItem1 = new QSpacerItem(41, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);

    btn4 = new QPushButton(tcMarketListDialog);
    btn4->setObjectName(QString::fromUtf8("btn4"));

    hboxLayout1->addWidget(btn4);

    btn5 = new QPushButton(tcMarketListDialog);
    btn5->setObjectName(QString::fromUtf8("btn5"));

    hboxLayout1->addWidget(btn5);


    vboxLayout->addLayout(hboxLayout1);

    buttonBox = new QDialogButtonBox(tcMarketListDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Close);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcMarketListDialog);

    QSize size(643, 439);
    size = size.expandedTo(tcMarketListDialog->minimumSizeHint());
    tcMarketListDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcMarketListDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcMarketListDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcMarketListDialog);
    } // setupUi

    void retranslateUi(QDialog *tcMarketListDialog)
    {
    tcMarketListDialog->setWindowTitle(QApplication::translate("tcMarketListDialog", "Market List...", 0, QApplication::UnicodeUTF8));
    gbx1->setTitle(QApplication::translate("tcMarketListDialog", "Markets:", 0, QApplication::UnicodeUTF8));
    lbl1_1->setText(QApplication::translate("tcMarketListDialog", "Market:", 0, QApplication::UnicodeUTF8));
    btn1_1->setText(QApplication::translate("tcMarketListDialog", "Add Market", 0, QApplication::UnicodeUTF8));
    btn1_2->setText(QApplication::translate("tcMarketListDialog", "Modify Market", 0, QApplication::UnicodeUTF8));
    btn1_3->setText(QApplication::translate("tcMarketListDialog", "Remove Market", 0, QApplication::UnicodeUTF8));
    btn1->setText(QApplication::translate("tcMarketListDialog", "Add Stock", 0, QApplication::UnicodeUTF8));
    btn2->setText(QApplication::translate("tcMarketListDialog", "Modify Stock", 0, QApplication::UnicodeUTF8));
    btn3->setText(QApplication::translate("tcMarketListDialog", "Remove Stock", 0, QApplication::UnicodeUTF8));
    btn4->setText(QApplication::translate("tcMarketListDialog", "Import From CVS File", 0, QApplication::UnicodeUTF8));
    btn5->setText(QApplication::translate("tcMarketListDialog", "Export To CSV File", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcMarketListDialog);
    } // retranslateUi

};

namespace Ui {
    class tcMarketListDialog: public Ui_tcMarketListDialog {};
} // namespace Ui

#endif // UI_MARKETLISTDLG_H
