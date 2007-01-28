/********************************************************************************
** Form generated from reading ui file 'ui_stocklistwgt.ui'
**
** Created: Tue Jan 9 09:52:44 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STOCKLISTWGT_H
#define UI_STOCKLISTWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_tcStockListWidget
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *tab1;
    QWidget *tab;
    QVBoxLayout *vboxLayout1;
    QPushButton *pushButton;
    QWidget *tab_2;
    QVBoxLayout *vboxLayout2;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QVBoxLayout *vboxLayout3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *tcStockListWidget)
    {
    tcStockListWidget->setObjectName(QString::fromUtf8("tcStockListWidget"));
    vboxLayout = new QVBoxLayout(tcStockListWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    tab1 = new QTabWidget(tcStockListWidget);
    tab1->setObjectName(QString::fromUtf8("tab1"));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    vboxLayout1 = new QVBoxLayout(tab);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    pushButton = new QPushButton(tab);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    vboxLayout1->addWidget(pushButton);

    tab1->addTab(tab, QApplication::translate("tcStockListWidget", "Favourite", 0, QApplication::UnicodeUTF8));
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    vboxLayout2 = new QVBoxLayout(tab_2);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(9);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    pushButton_2 = new QPushButton(tab_2);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    vboxLayout2->addWidget(pushButton_2);

    tab1->addTab(tab_2, QApplication::translate("tcStockListWidget", "All", 0, QApplication::UnicodeUTF8));
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    vboxLayout3 = new QVBoxLayout(tab_3);
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(9);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    pushButton_3 = new QPushButton(tab_3);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

    vboxLayout3->addWidget(pushButton_3);

    tab1->addTab(tab_3, QApplication::translate("tcStockListWidget", "Search", 0, QApplication::UnicodeUTF8));

    vboxLayout->addWidget(tab1);


    retranslateUi(tcStockListWidget);

    QSize size(283, 300);
    size = size.expandedTo(tcStockListWidget->minimumSizeHint());
    tcStockListWidget->resize(size);


    tab1->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(tcStockListWidget);
    } // setupUi

    void retranslateUi(QWidget *tcStockListWidget)
    {
    tcStockListWidget->setWindowTitle(QApplication::translate("tcStockListWidget", "Stock List", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("tcStockListWidget", "PushButton", 0, QApplication::UnicodeUTF8));
    tab1->setTabText(tab1->indexOf(tab), QApplication::translate("tcStockListWidget", "Favourite", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("tcStockListWidget", "PushButton", 0, QApplication::UnicodeUTF8));
    tab1->setTabText(tab1->indexOf(tab_2), QApplication::translate("tcStockListWidget", "All", 0, QApplication::UnicodeUTF8));
    pushButton_3->setText(QApplication::translate("tcStockListWidget", "PushButton", 0, QApplication::UnicodeUTF8));
    tab1->setTabText(tab1->indexOf(tab_3), QApplication::translate("tcStockListWidget", "Search", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcStockListWidget);
    } // retranslateUi

};

namespace Ui {
    class tcStockListWidget: public Ui_tcStockListWidget {};
} // namespace Ui

#endif // UI_STOCKLISTWGT_H
