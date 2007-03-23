/********************************************************************************
** Form generated from reading ui file 'ui_fxjfileimptsourcedlg.ui'
**
** Created: Fri Mar 23 12:19:27 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FXJFILEIMPTSOURCEDLG_H
#define UI_FXJFILEIMPTSOURCEDLG_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

class Ui_tcFxjFileImportSourceDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbx1;
    QVBoxLayout *vboxLayout1;
    QRadioButton *rdo1;
    QHBoxLayout *hboxLayout;
    QLabel *lbl1;
    QLabel *lbl2;
    QLineEdit *edt1;
    QRadioButton *rdo2;
    QHBoxLayout *hboxLayout1;
    QLabel *lbl3;
    QLabel *lbl4;
    QLineEdit *edt2;
    QToolButton *btn1;
    QSpacerItem *spacerItem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcFxjFileImportSourceDialog)
    {
    tcFxjFileImportSourceDialog->setObjectName(QString::fromUtf8("tcFxjFileImportSourceDialog"));
    vboxLayout = new QVBoxLayout(tcFxjFileImportSourceDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    gbx1 = new QGroupBox(tcFxjFileImportSourceDialog);
    gbx1->setObjectName(QString::fromUtf8("gbx1"));
    vboxLayout1 = new QVBoxLayout(gbx1);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    rdo1 = new QRadioButton(gbx1);
    rdo1->setObjectName(QString::fromUtf8("rdo1"));
    rdo1->setChecked(true);

    vboxLayout1->addWidget(rdo1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    lbl1 = new QLabel(gbx1);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));

    hboxLayout->addWidget(lbl1);

    lbl2 = new QLabel(gbx1);
    lbl2->setObjectName(QString::fromUtf8("lbl2"));

    hboxLayout->addWidget(lbl2);

    edt1 = new QLineEdit(gbx1);
    edt1->setObjectName(QString::fromUtf8("edt1"));

    hboxLayout->addWidget(edt1);


    vboxLayout1->addLayout(hboxLayout);

    rdo2 = new QRadioButton(gbx1);
    rdo2->setObjectName(QString::fromUtf8("rdo2"));

    vboxLayout1->addWidget(rdo2);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    lbl3 = new QLabel(gbx1);
    lbl3->setObjectName(QString::fromUtf8("lbl3"));

    hboxLayout1->addWidget(lbl3);

    lbl4 = new QLabel(gbx1);
    lbl4->setObjectName(QString::fromUtf8("lbl4"));

    hboxLayout1->addWidget(lbl4);

    edt2 = new QLineEdit(gbx1);
    edt2->setObjectName(QString::fromUtf8("edt2"));

    hboxLayout1->addWidget(edt2);

    btn1 = new QToolButton(gbx1);
    btn1->setObjectName(QString::fromUtf8("btn1"));

    hboxLayout1->addWidget(btn1);


    vboxLayout1->addLayout(hboxLayout1);

    spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout1->addItem(spacerItem);


    vboxLayout->addWidget(gbx1);

    buttonBox = new QDialogButtonBox(tcFxjFileImportSourceDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcFxjFileImportSourceDialog);

    QSize size(473, 217);
    size = size.expandedTo(tcFxjFileImportSourceDialog->minimumSizeHint());
    tcFxjFileImportSourceDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcFxjFileImportSourceDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcFxjFileImportSourceDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcFxjFileImportSourceDialog);
    } // setupUi

    void retranslateUi(QDialog *tcFxjFileImportSourceDialog)
    {
    tcFxjFileImportSourceDialog->setWindowTitle(QApplication::translate("tcFxjFileImportSourceDialog", "Fxj File Import Source Setting...", 0, QApplication::UnicodeUTF8));
    gbx1->setTitle(QApplication::translate("tcFxjFileImportSourceDialog", "Setup:", 0, QApplication::UnicodeUTF8));
    rdo1->setText(QApplication::translate("tcFxjFileImportSourceDialog", "Auto download daily file (ZIP format) from http://www.fxj.net.cn", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QString());
    lbl2->setText(QApplication::translate("tcFxjFileImportSourceDialog", "URL:", 0, QApplication::UnicodeUTF8));
    rdo2->setText(QApplication::translate("tcFxjFileImportSourceDialog", "Use the daily files (ZIP or DAD format) on local system", 0, QApplication::UnicodeUTF8));
    lbl3->setText(QString());
    lbl4->setText(QApplication::translate("tcFxjFileImportSourceDialog", "Path:", 0, QApplication::UnicodeUTF8));
    btn1->setText(QApplication::translate("tcFxjFileImportSourceDialog", "...", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcFxjFileImportSourceDialog);
    } // retranslateUi

};

namespace Ui {
    class tcFxjFileImportSourceDialog: public Ui_tcFxjFileImportSourceDialog {};
} // namespace Ui

#endif // UI_FXJFILEIMPTSOURCEDLG_H
