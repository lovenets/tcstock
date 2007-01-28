/********************************************************************************
** Form generated from reading ui file 'ui_stocklistallwgt.ui'
**
** Created: Tue Jan 9 09:52:44 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STOCKLISTALLWGT_H
#define UI_STOCKLISTALLWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_tcStockListAllWidget
{
public:
    QVBoxLayout *vboxLayout;
    QComboBox *cbo1;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *lbl1;
    QLabel *lbl2;
    QVBoxLayout *vboxLayout2;
    QLineEdit *edt1;
    QLineEdit *edt2;
    QTableWidget *tbl1;

    void setupUi(QWidget *tcStockListAllWidget)
    {
    tcStockListAllWidget->setObjectName(QString::fromUtf8("tcStockListAllWidget"));
    vboxLayout = new QVBoxLayout(tcStockListAllWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    cbo1 = new QComboBox(tcStockListAllWidget);
    cbo1->setObjectName(QString::fromUtf8("cbo1"));

    vboxLayout->addWidget(cbo1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    lbl1 = new QLabel(tcStockListAllWidget);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    vboxLayout1->addWidget(lbl1);

    lbl2 = new QLabel(tcStockListAllWidget);
    lbl2->setObjectName(QString::fromUtf8("lbl2"));

    vboxLayout1->addWidget(lbl2);


    hboxLayout->addLayout(vboxLayout1);

    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    edt1 = new QLineEdit(tcStockListAllWidget);
    edt1->setObjectName(QString::fromUtf8("edt1"));

    vboxLayout2->addWidget(edt1);

    edt2 = new QLineEdit(tcStockListAllWidget);
    edt2->setObjectName(QString::fromUtf8("edt2"));

    vboxLayout2->addWidget(edt2);


    hboxLayout->addLayout(vboxLayout2);


    vboxLayout->addLayout(hboxLayout);

    tbl1 = new QTableWidget(tcStockListAllWidget);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout->addWidget(tbl1);


    retranslateUi(tcStockListAllWidget);

    QSize size(188, 300);
    size = size.expandedTo(tcStockListAllWidget->minimumSizeHint());
    tcStockListAllWidget->resize(size);


    QMetaObject::connectSlotsByName(tcStockListAllWidget);
    } // setupUi

    void retranslateUi(QWidget *tcStockListAllWidget)
    {
    tcStockListAllWidget->setWindowTitle(QApplication::translate("tcStockListAllWidget", "All Stocks", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcStockListAllWidget", "Stock Code:", 0, QApplication::UnicodeUTF8));
    lbl2->setText(QApplication::translate("tcStockListAllWidget", "Stock Name:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcStockListAllWidget);
    } // retranslateUi

};

namespace Ui {
    class tcStockListAllWidget: public Ui_tcStockListAllWidget {};
} // namespace Ui

#endif // UI_STOCKLISTALLWGT_H
