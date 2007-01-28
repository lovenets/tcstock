/********************************************************************************
** Form generated from reading ui file 'ui_weeklyviewwgt.ui'
**
** Created: Thu Dec 28 09:51:35 2006
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WEEKLYVIEWWGT_H
#define UI_WEEKLYVIEWWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_tcWeeklyViewWidget
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QSpacerItem *spacerItem;
    //QWidget *wgt1;

    void setupUi(QWidget *tcWeeklyViewWidget)
    {
    tcWeeklyViewWidget->setObjectName(QString::fromUtf8("tcWeeklyViewWidget"));
    vboxLayout = new QVBoxLayout(tcWeeklyViewWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    btn1 = new QPushButton(tcWeeklyViewWidget);
    btn1->setObjectName(QString::fromUtf8("btn1"));

    hboxLayout->addWidget(btn1);

    btn2 = new QPushButton(tcWeeklyViewWidget);
    btn2->setObjectName(QString::fromUtf8("btn2"));

    hboxLayout->addWidget(btn2);

    btn3 = new QPushButton(tcWeeklyViewWidget);
    btn3->setObjectName(QString::fromUtf8("btn3"));

    hboxLayout->addWidget(btn3);

    btn4 = new QPushButton(tcWeeklyViewWidget);
    btn4->setObjectName(QString::fromUtf8("btn4"));

    hboxLayout->addWidget(btn4);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    vboxLayout->addLayout(hboxLayout);

    //wgt1 = new QWidget(tcWeeklyViewWidget);
    //wgt1->setObjectName(QString::fromUtf8("wgt1"));

    //vboxLayout->addWidget(wgt1);


    retranslateUi(tcWeeklyViewWidget);

    QSize size(494, 300);
    size = size.expandedTo(tcWeeklyViewWidget->minimumSizeHint());
    tcWeeklyViewWidget->resize(size);


    QMetaObject::connectSlotsByName(tcWeeklyViewWidget);
    } // setupUi

    void retranslateUi(QWidget *tcWeeklyViewWidget)
    {
    tcWeeklyViewWidget->setWindowTitle(QApplication::translate("tcWeeklyViewWidget", "Stock Weekly View...", 0, QApplication::UnicodeUTF8));
    btn1->setText(QApplication::translate("tcWeeklyViewWidget", "Weekly View", 0, QApplication::UnicodeUTF8));
    btn2->setText(QApplication::translate("tcWeeklyViewWidget", "Double Week View", 0, QApplication::UnicodeUTF8));
    btn3->setText(QApplication::translate("tcWeeklyViewWidget", "Month View", 0, QApplication::UnicodeUTF8));
    btn4->setText(QApplication::translate("tcWeeklyViewWidget", "Nothing", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcWeeklyViewWidget);
    } // retranslateUi

};

namespace Ui {
    class tcWeeklyViewWidget: public Ui_tcWeeklyViewWidget {};
} // namespace Ui

#endif // UI_WEEKLYVIEWWGT_H
