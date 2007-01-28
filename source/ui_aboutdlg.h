/********************************************************************************
** Form generated from reading ui file 'ui_aboutdlg.ui'
**
** Created: Mon Jan 1 19:05:11 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUTDLG_H
#define UI_ABOUTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_tcAboutDialog
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *tab1;
    QWidget *tab;
    QVBoxLayout *vboxLayout1;
    QTextBrowser *txt1_1;
    QWidget *tab_2;
    QVBoxLayout *vboxLayout2;
    QTextBrowser *txt1_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcAboutDialog)
    {
    tcAboutDialog->setObjectName(QString::fromUtf8("tcAboutDialog"));
    vboxLayout = new QVBoxLayout(tcAboutDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    tab1 = new QTabWidget(tcAboutDialog);
    tab1->setObjectName(QString::fromUtf8("tab1"));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    vboxLayout1 = new QVBoxLayout(tab);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    txt1_1 = new QTextBrowser(tab);
    txt1_1->setObjectName(QString::fromUtf8("txt1_1"));

    vboxLayout1->addWidget(txt1_1);

    tab1->addTab(tab, QApplication::translate("tcAboutDialog", "About", 0, QApplication::UnicodeUTF8));
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    vboxLayout2 = new QVBoxLayout(tab_2);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(9);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    txt1_2 = new QTextBrowser(tab_2);
    txt1_2->setObjectName(QString::fromUtf8("txt1_2"));

    vboxLayout2->addWidget(txt1_2);

    tab1->addTab(tab_2, QApplication::translate("tcAboutDialog", "Release Notes", 0, QApplication::UnicodeUTF8));

    vboxLayout->addWidget(tab1);

    buttonBox = new QDialogButtonBox(tcAboutDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Close);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcAboutDialog);

    QSize size(510, 306);
    size = size.expandedTo(tcAboutDialog->minimumSizeHint());
    tcAboutDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcAboutDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcAboutDialog, SLOT(reject()));

    tab1->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(tcAboutDialog);
    } // setupUi

    void retranslateUi(QDialog *tcAboutDialog)
    {
    tcAboutDialog->setWindowTitle(QApplication::translate("tcAboutDialog", "About...", 0, QApplication::UnicodeUTF8));
    tab1->setTabText(tab1->indexOf(tab), QApplication::translate("tcAboutDialog", "About", 0, QApplication::UnicodeUTF8));
    tab1->setTabText(tab1->indexOf(tab_2), QApplication::translate("tcAboutDialog", "Release Notes", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcAboutDialog);
    } // retranslateUi

};

namespace Ui {
    class tcAboutDialog: public Ui_tcAboutDialog {};
} // namespace Ui

#endif // UI_ABOUTDLG_H
