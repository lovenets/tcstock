/********************************************************************************
** Form generated from reading ui file 'ui_stocklistfavtwgt.ui'
**
** Created: Sun Dec 24 19:24:32 2006
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STOCKLISTFAVTWGT_H
#define UI_STOCKLISTFAVTWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_tcStockListFavouriteWidget
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QComboBox *cbo1;
    QToolButton *btn1;
    QTableWidget *tbl1;

    void setupUi(QWidget *tcStockListFavouriteWidget)
    {
    tcStockListFavouriteWidget->setObjectName(QString::fromUtf8("tcStockListFavouriteWidget"));
    vboxLayout = new QVBoxLayout(tcStockListFavouriteWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    cbo1 = new QComboBox(tcStockListFavouriteWidget);
    cbo1->setObjectName(QString::fromUtf8("cbo1"));

    hboxLayout->addWidget(cbo1);

    btn1 = new QToolButton(tcStockListFavouriteWidget);
    btn1->setObjectName(QString::fromUtf8("btn1"));

    hboxLayout->addWidget(btn1);


    vboxLayout->addLayout(hboxLayout);

    tbl1 = new QTableWidget(tcStockListFavouriteWidget);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout->addWidget(tbl1);


    retranslateUi(tcStockListFavouriteWidget);

    QSize size(185, 300);
    size = size.expandedTo(tcStockListFavouriteWidget->minimumSizeHint());
    tcStockListFavouriteWidget->resize(size);


    QMetaObject::connectSlotsByName(tcStockListFavouriteWidget);
    } // setupUi

    void retranslateUi(QWidget *tcStockListFavouriteWidget)
    {
    tcStockListFavouriteWidget->setWindowTitle(QApplication::translate("tcStockListFavouriteWidget", "Favourite Stocks", 0, QApplication::UnicodeUTF8));
    btn1->setText(QApplication::translate("tcStockListFavouriteWidget", "...", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcStockListFavouriteWidget);
    } // retranslateUi

};

namespace Ui {
    class tcStockListFavouriteWidget: public Ui_tcStockListFavouriteWidget {};
} // namespace Ui

#endif // UI_STOCKLISTFAVTWGT_H
