/********************************************************************************
** Form generated from reading ui file 'ui_dataimptsetupdlg.ui'
**
** Created: Thu Mar 22 15:32:57 2007
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DATAIMPTSETUPDLG_H
#define UI_DATAIMPTSETUPDLG_H

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
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

class Ui_tcDataImporterSetupDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QGroupBox *gbx1;
    QVBoxLayout *vboxLayout1;
    QTableWidget *tbl1_1;
    QHBoxLayout *hboxLayout1;
    QPushButton *btn1_1;
    QPushButton *btn1_2;
    QSpacerItem *spacerItem;
    QGroupBox *gbx2;
    QVBoxLayout *vboxLayout2;
    QRadioButton *rdo2_1;
    QRadioButton *rdo2_2;
    QHBoxLayout *hboxLayout2;
    QLabel *lbl2_1;
    QLabel *lbl2_2;
    QLineEdit *edt2_1;
    QSpacerItem *spacerItem1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcDataImporterSetupDialog)
    {
    tcDataImporterSetupDialog->setObjectName(QString::fromUtf8("tcDataImporterSetupDialog"));
    vboxLayout = new QVBoxLayout(tcDataImporterSetupDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    gbx1 = new QGroupBox(tcDataImporterSetupDialog);
    gbx1->setObjectName(QString::fromUtf8("gbx1"));
    vboxLayout1 = new QVBoxLayout(gbx1);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    tbl1_1 = new QTableWidget(gbx1);
    tbl1_1->setObjectName(QString::fromUtf8("tbl1_1"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(7));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(tbl1_1->sizePolicy().hasHeightForWidth());
    tbl1_1->setSizePolicy(sizePolicy);

    vboxLayout1->addWidget(tbl1_1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    btn1_1 = new QPushButton(gbx1);
    btn1_1->setObjectName(QString::fromUtf8("btn1_1"));

    hboxLayout1->addWidget(btn1_1);

    btn1_2 = new QPushButton(gbx1);
    btn1_2->setObjectName(QString::fromUtf8("btn1_2"));

    hboxLayout1->addWidget(btn1_2);

    spacerItem = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);


    vboxLayout1->addLayout(hboxLayout1);


    hboxLayout->addWidget(gbx1);

    gbx2 = new QGroupBox(tcDataImporterSetupDialog);
    gbx2->setObjectName(QString::fromUtf8("gbx2"));
    vboxLayout2 = new QVBoxLayout(gbx2);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(9);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    rdo2_1 = new QRadioButton(gbx2);
    rdo2_1->setObjectName(QString::fromUtf8("rdo2_1"));
    rdo2_1->setChecked(true);

    vboxLayout2->addWidget(rdo2_1);

    rdo2_2 = new QRadioButton(gbx2);
    rdo2_2->setObjectName(QString::fromUtf8("rdo2_2"));

    vboxLayout2->addWidget(rdo2_2);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    lbl2_1 = new QLabel(gbx2);
    lbl2_1->setObjectName(QString::fromUtf8("lbl2_1"));

    hboxLayout2->addWidget(lbl2_1);

    lbl2_2 = new QLabel(gbx2);
    lbl2_2->setObjectName(QString::fromUtf8("lbl2_2"));

    hboxLayout2->addWidget(lbl2_2);

    edt2_1 = new QLineEdit(gbx2);
    edt2_1->setObjectName(QString::fromUtf8("edt2_1"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(edt2_1->sizePolicy().hasHeightForWidth());
    edt2_1->setSizePolicy(sizePolicy1);

    hboxLayout2->addWidget(edt2_1);


    vboxLayout2->addLayout(hboxLayout2);

    spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout2->addItem(spacerItem1);


    hboxLayout->addWidget(gbx2);


    vboxLayout->addLayout(hboxLayout);

    buttonBox = new QDialogButtonBox(tcDataImporterSetupDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Close);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcDataImporterSetupDialog);

    QSize size(574, 326);
    size = size.expandedTo(tcDataImporterSetupDialog->minimumSizeHint());
    tcDataImporterSetupDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcDataImporterSetupDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcDataImporterSetupDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcDataImporterSetupDialog);
    } // setupUi

    void retranslateUi(QDialog *tcDataImporterSetupDialog)
    {
    tcDataImporterSetupDialog->setWindowTitle(QApplication::translate("tcDataImporterSetupDialog", "Data Import Setup...", 0, QApplication::UnicodeUTF8));
    gbx1->setTitle(QApplication::translate("tcDataImporterSetupDialog", "Source List:", 0, QApplication::UnicodeUTF8));
    btn1_1->setText(QApplication::translate("tcDataImporterSetupDialog", "Setting...", 0, QApplication::UnicodeUTF8));
    btn1_2->setText(QApplication::translate("tcDataImporterSetupDialog", "Import Now", 0, QApplication::UnicodeUTF8));
    gbx2->setTitle(QApplication::translate("tcDataImporterSetupDialog", "Setup:", 0, QApplication::UnicodeUTF8));
    rdo2_1->setText(QApplication::translate("tcDataImporterSetupDialog", "Do not Auto Import", 0, QApplication::UnicodeUTF8));
    rdo2_2->setText(QApplication::translate("tcDataImporterSetupDialog", "Auto Import", 0, QApplication::UnicodeUTF8));
    lbl2_1->setText(QString());
    lbl2_2->setText(QApplication::translate("tcDataImporterSetupDialog", "Interval (minutes):", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcDataImporterSetupDialog);
    } // retranslateUi

};

namespace Ui {
    class tcDataImporterSetupDialog: public Ui_tcDataImporterSetupDialog {};
} // namespace Ui

#endif // UI_DATAIMPTSETUPDLG_H
