/********************************************************************************
** Form generated from reading ui file 'ui_marketselectdlg.ui'
**
** Created: Sun Dec 3 19:49:42 2006
**      by: Qt User Interface Compiler version 4.2.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MARKETSELECTDLG_H
#define UI_MARKETSELECTDLG_H

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
#include <QtGui/QVBoxLayout>

class Ui_tcMarketSelectDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbx1;
    QHBoxLayout *hboxLayout;
    QLabel *lbl1;
    QComboBox *cbo1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tcMarketSelectDialog)
    {
    tcMarketSelectDialog->setObjectName(QString::fromUtf8("tcMarketSelectDialog"));
    vboxLayout = new QVBoxLayout(tcMarketSelectDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    gbx1 = new QGroupBox(tcMarketSelectDialog);
    gbx1->setObjectName(QString::fromUtf8("gbx1"));
    hboxLayout = new QHBoxLayout(gbx1);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(9);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    lbl1 = new QLabel(gbx1);
    lbl1->setObjectName(QString::fromUtf8("lbl1"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(5));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(lbl1->sizePolicy().hasHeightForWidth());
    lbl1->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(lbl1);

    cbo1 = new QComboBox(gbx1);
    cbo1->setObjectName(QString::fromUtf8("cbo1"));

    hboxLayout->addWidget(cbo1);


    vboxLayout->addWidget(gbx1);

    buttonBox = new QDialogButtonBox(tcMarketSelectDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    retranslateUi(tcMarketSelectDialog);

    QSize size(292, 101);
    size = size.expandedTo(tcMarketSelectDialog->minimumSizeHint());
    tcMarketSelectDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), tcMarketSelectDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), tcMarketSelectDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(tcMarketSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *tcMarketSelectDialog)
    {
    tcMarketSelectDialog->setWindowTitle(QApplication::translate("tcMarketSelectDialog", "Select Market...", 0, QApplication::UnicodeUTF8));
    gbx1->setTitle(QApplication::translate("tcMarketSelectDialog", "Info:", 0, QApplication::UnicodeUTF8));
    lbl1->setText(QApplication::translate("tcMarketSelectDialog", "Market:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcMarketSelectDialog);
    } // retranslateUi

};

namespace Ui {
    class tcMarketSelectDialog: public Ui_tcMarketSelectDialog {};
} // namespace Ui

#endif // UI_MARKETSELECTDLG_H
