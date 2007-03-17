/********************************************************************************
** Form generated from reading ui file 'ui_favouritegroupinfodlg.ui'
**
** Created: Sat Mar 17 20:49:30 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FAVOURITEGROUPINFODLG_H
#define UI_FAVOURITEGROUPINFODLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

class Ui_tcFavouriteGroupInfoDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *grp1;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *lbl1;
    QLabel *lbl2;
    QVBoxLayout *vboxLayout2;
    QLineEdit *edt1;
    QLineEdit *edt2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcFavouriteGroupInfoDialog)
    {
    tcFavouriteGroupInfoDialog->setObjectName(QString::fromUtf8("tcFavouriteGroupInfoDialog"));
    vboxLayout = new QVBoxLayout(tcFavouriteGroupInfoDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    grp1 = new QGroupBox(tcFavouriteGroupInfoDialog);
    grp1->setObjectName(QString::fromUtf8("grp1"));
    hboxLayout = new QHBoxLayout(grp1);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(9);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    lbl1 = new QLabel(grp1);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    vboxLayout1->addWidget(lbl1);

    lbl2 = new QLabel(grp1);
    lbl2->setObjectName(QString::fromUtf8("lbl2"));

    vboxLayout1->addWidget(lbl2);


    hboxLayout->addLayout(vboxLayout1);

    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    edt1 = new QLineEdit(grp1);
    edt1->setObjectName(QString::fromUtf8("edt1"));

    vboxLayout2->addWidget(edt1);

    edt2 = new QLineEdit(grp1);
    edt2->setObjectName(QString::fromUtf8("edt2"));

    vboxLayout2->addWidget(edt2);


    hboxLayout->addLayout(vboxLayout2);


    vboxLayout->addWidget(grp1);

    buttonBox = new QDialogButtonBox(tcFavouriteGroupInfoDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcFavouriteGroupInfoDialog);

    QSize size(336, 130);
    size = size.expandedTo(tcFavouriteGroupInfoDialog->minimumSizeHint());
    tcFavouriteGroupInfoDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcFavouriteGroupInfoDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcFavouriteGroupInfoDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcFavouriteGroupInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *tcFavouriteGroupInfoDialog)
    {
    tcFavouriteGroupInfoDialog->setWindowTitle(QApplication::translate("tcFavouriteGroupInfoDialog", "Favourite Group...", 0, QApplication::UnicodeUTF8));
    grp1->setTitle(QApplication::translate("tcFavouriteGroupInfoDialog", "Info:", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcFavouriteGroupInfoDialog", "Group Name:", 0, QApplication::UnicodeUTF8));
    lbl2->setText(QApplication::translate("tcFavouriteGroupInfoDialog", "Description:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcFavouriteGroupInfoDialog);
    } // retranslateUi

};

namespace Ui {
    class tcFavouriteGroupInfoDialog: public Ui_tcFavouriteGroupInfoDialog {};
} // namespace Ui

#endif // UI_FAVOURITEGROUPINFODLG_H
