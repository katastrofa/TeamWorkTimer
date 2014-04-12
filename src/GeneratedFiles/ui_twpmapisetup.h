/********************************************************************************
** Form generated from reading UI file 'twpmapisetup.ui'
**
** Created: Tue May 21 13:17:21 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWPMAPISETUP_H
#define UI_TWPMAPISETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TwpmApiSetupClass
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *txtUrl;
    QLineEdit *txtToken;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cmdSave;

    void setupUi(QDialog *TwpmApiSetupClass)
    {
        if (TwpmApiSetupClass->objectName().isEmpty())
            TwpmApiSetupClass->setObjectName(QString::fromUtf8("TwpmApiSetupClass"));
        TwpmApiSetupClass->setWindowModality(Qt::ApplicationModal);
        TwpmApiSetupClass->resize(400, 112);
        TwpmApiSetupClass->setMinimumSize(QSize(300, 112));
        verticalLayout = new QVBoxLayout(TwpmApiSetupClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout_2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
#endif
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        txtUrl = new QLineEdit(TwpmApiSetupClass);
        txtUrl->setObjectName(QString::fromUtf8("txtUrl"));

        verticalLayout_2->addWidget(txtUrl);

        txtToken = new QLineEdit(TwpmApiSetupClass);
        txtToken->setObjectName(QString::fromUtf8("txtToken"));

        verticalLayout_2->addWidget(txtToken);

        frame_2 = new QFrame(TwpmApiSetupClass);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(276, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cmdSave = new QPushButton(frame_2);
        cmdSave->setObjectName(QString::fromUtf8("cmdSave"));
        cmdSave->setMinimumSize(QSize(0, 24));

        horizontalLayout->addWidget(cmdSave);


        verticalLayout_2->addWidget(frame_2);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(TwpmApiSetupClass);
        QObject::connect(cmdSave, SIGNAL(clicked()), TwpmApiSetupClass, SLOT(CloseOnSave()));

        QMetaObject::connectSlotsByName(TwpmApiSetupClass);
    } // setupUi

    void retranslateUi(QDialog *TwpmApiSetupClass)
    {
        TwpmApiSetupClass->setWindowTitle(QApplication::translate("TwpmApiSetupClass", "TeamWorkPM API Setup", 0, QApplication::UnicodeUTF8));
        cmdSave->setText(QApplication::translate("TwpmApiSetupClass", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TwpmApiSetupClass: public Ui_TwpmApiSetupClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWPMAPISETUP_H
