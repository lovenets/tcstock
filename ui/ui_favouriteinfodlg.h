/********************************************************************************
** Form generated from reading ui file 'ui_favouriteinfodlg.ui'
**
** Created: Tue Jan 9 09:52:44 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FAVOURITEINFODLG_H
#define UI_FAVOURITEINFODLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

class Ui_tcFavouriteInfoDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QComboBox *cbo1;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QSpacerItem *spacerItem;
    QTableView *tbl1;
    QHBoxLayout *hboxLayout1;
    QPushButton *btn4;
    QPushButton *btn5;
    QSpacerItem *spacerItem1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcFavouriteInfoDialog)
    {
    tcFavouriteInfoDialog->setObjectName(QString::fromUtf8("tcFavouriteInfoDialog"));
    vboxLayout = new QVBoxLayout(tcFavouriteInfoDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    cbo1 = new QComboBox(tcFavouriteInfoDialog);
    cbo1->setObjectName(QString::fromUtf8("cbo1"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(cbo1->sizePolicy().hasHeightForWidth());
    cbo1->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(cbo1);

    btn1 = new QPushButton(tcFavouriteInfoDialog);
    btn1->setObjectName(QString::fromUtf8("btn1"));

    hboxLayout->addWidget(btn1);

    btn2 = new QPushButton(tcFavouriteInfoDialog);
    btn2->setObjectName(QString::fromUtf8("btn2"));

    hboxLayout->addWidget(btn2);

    btn3 = new QPushButton(tcFavouriteInfoDialog);
    btn3->setObjectName(QString::fromUtf8("btn3"));

    hboxLayout->addWidget(btn3);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    vboxLayout->addLayout(hboxLayout);

    tbl1 = new QTableView(tcFavouriteInfoDialog);
    tbl1->setObjectName(QString::fromUtf8("tbl1"));

    vboxLayout->addWidget(tbl1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    btn4 = new QPushButton(tcFavouriteInfoDialog);
    btn4->setObjectName(QString::fromUtf8("btn4"));

    hboxLayout1->addWidget(btn4);

    btn5 = new QPushButton(tcFavouriteInfoDialog);
    btn5->setObjectName(QString::fromUtf8("btn5"));

    hboxLayout1->addWidget(btn5);

    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);


    vboxLayout->addLayout(hboxLayout1);

    buttonBox = new QDialogButtonBox(tcFavouriteInfoDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Close);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcFavouriteInfoDialog);

    QSize size(565, 420);
    size = size.expandedTo(tcFavouriteInfoDialog->minimumSizeHint());
    tcFavouriteInfoDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcFavouriteInfoDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcFavouriteInfoDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcFavouriteInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *tcFavouriteInfoDialog)
    {
    tcFavouriteInfoDialog->setWindowTitle(QApplication::translate("tcFavouriteInfoDialog", "Favourite Info...", 0, QApplication::UnicodeUTF8));
    btn1->setText(QApplication::translate("tcFavouriteInfoDialog", "Add Group", 0, QApplication::UnicodeUTF8));
    btn2->setText(QApplication::translate("tcFavouriteInfoDialog", "Edit Group", 0, QApplication::UnicodeUTF8));
    btn3->setText(QApplication::translate("tcFavouriteInfoDialog", "Remove Group", 0, QApplication::UnicodeUTF8));
    btn4->setText(QApplication::translate("tcFavouriteInfoDialog", "Append Stock", 0, QApplication::UnicodeUTF8));
    btn5->setText(QApplication::translate("tcFavouriteInfoDialog", "Remove Stock", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcFavouriteInfoDialog);
    } // retranslateUi

};

namespace Ui {
    class tcFavouriteInfoDialog: public Ui_tcFavouriteInfoDialog {};
} // namespace Ui

#endif // UI_FAVOURITEINFODLG_H
