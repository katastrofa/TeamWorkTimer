/********************************************************************************
** Form generated from reading UI file 'twpmsubmit.ui'
**
** Created: Tue May 21 13:17:21 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWPMSUBMIT_H
#define UI_TWPMSUBMIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TwpmSubmit
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdTimeInfo;
    QGroupBox *groupBox;
    QLineEdit *txtHours;
    QLineEdit *txtMinutes;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *chkBillable;
    QSpacerItem *verticalSpacer;
    QLabel *lblOwner;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *cmdSubmit;
    QPushButton *cmdAssignTask;
    QSpacerItem *horizontalSpacer;
    QPushButton *cmdCancel;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTextEdit *txtDescription;
    QLabel *lblTask;

    void setupUi(QDialog *TwpmSubmit)
    {
        if (TwpmSubmit->objectName().isEmpty())
            TwpmSubmit->setObjectName(QString::fromUtf8("TwpmSubmit"));
        TwpmSubmit->setWindowModality(Qt::ApplicationModal);
        TwpmSubmit->resize(500, 225);
        TwpmSubmit->setMinimumSize(QSize(500, 225));
        gridLayout = new QGridLayout(TwpmSubmit);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_2 = new QFrame(TwpmSubmit);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(200, 0));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lcdTimeInfo = new QLCDNumber(frame_2);
        lcdTimeInfo->setObjectName(QString::fromUtf8("lcdTimeInfo"));
        lcdTimeInfo->setFrameShadow(QFrame::Raised);
        lcdTimeInfo->setLineWidth(1);
        lcdTimeInfo->setNumDigits(8);
        lcdTimeInfo->setSegmentStyle(QLCDNumber::Filled);
        lcdTimeInfo->setProperty("value", QVariant(0));

        verticalLayout_2->addWidget(lcdTimeInfo);

        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 40));
        txtHours = new QLineEdit(groupBox);
        txtHours->setObjectName(QString::fromUtf8("txtHours"));
        txtHours->setGeometry(QRect(12, 16, 40, 20));
        txtMinutes = new QLineEdit(groupBox);
        txtMinutes->setObjectName(QString::fromUtf8("txtMinutes"));
        txtMinutes->setGeometry(QRect(102, 16, 40, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 18, 26, 13));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 18, 22, 13));

        verticalLayout_2->addWidget(groupBox);

        chkBillable = new QCheckBox(frame_2);
        chkBillable->setObjectName(QString::fromUtf8("chkBillable"));
        QFont font;
        font.setPointSize(10);
        chkBillable->setFont(font);

        verticalLayout_2->addWidget(chkBillable);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        lblOwner = new QLabel(frame_2);
        lblOwner->setObjectName(QString::fromUtf8("lblOwner"));
        lblOwner->setMinimumSize(QSize(0, 24));

        verticalLayout_2->addWidget(lblOwner);


        gridLayout->addWidget(frame_2, 0, 2, 1, 1);

        frame_3 = new QFrame(TwpmSubmit);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setMinimumSize(QSize(0, 40));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cmdSubmit = new QPushButton(frame_3);
        cmdSubmit->setObjectName(QString::fromUtf8("cmdSubmit"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cmdSubmit->sizePolicy().hasHeightForWidth());
        cmdSubmit->setSizePolicy(sizePolicy2);
        cmdSubmit->setMinimumSize(QSize(80, 24));

        horizontalLayout->addWidget(cmdSubmit);

        cmdAssignTask = new QPushButton(frame_3);
        cmdAssignTask->setObjectName(QString::fromUtf8("cmdAssignTask"));
        sizePolicy2.setHeightForWidth(cmdAssignTask->sizePolicy().hasHeightForWidth());
        cmdAssignTask->setSizePolicy(sizePolicy2);
        cmdAssignTask->setMinimumSize(QSize(80, 24));

        horizontalLayout->addWidget(cmdAssignTask);

        horizontalSpacer = new QSpacerItem(201, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cmdCancel = new QPushButton(frame_3);
        cmdCancel->setObjectName(QString::fromUtf8("cmdCancel"));
        sizePolicy2.setHeightForWidth(cmdCancel->sizePolicy().hasHeightForWidth());
        cmdCancel->setSizePolicy(sizePolicy2);
        cmdCancel->setMinimumSize(QSize(80, 24));

        horizontalLayout->addWidget(cmdCancel);


        gridLayout->addWidget(frame_3, 1, 0, 1, 3);

        frame = new QFrame(TwpmSubmit);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtDescription = new QTextEdit(frame);
        txtDescription->setObjectName(QString::fromUtf8("txtDescription"));

        verticalLayout->addWidget(txtDescription);

        lblTask = new QLabel(frame);
        lblTask->setObjectName(QString::fromUtf8("lblTask"));
        lblTask->setMinimumSize(QSize(0, 24));

        verticalLayout->addWidget(lblTask);


        gridLayout->addWidget(frame, 0, 0, 1, 2);


        retranslateUi(TwpmSubmit);
        QObject::connect(cmdAssignTask, SIGNAL(clicked()), TwpmSubmit, SLOT(AssignTask()));
        QObject::connect(cmdCancel, SIGNAL(clicked()), TwpmSubmit, SLOT(CancelSubmission()));
        QObject::connect(cmdSubmit, SIGNAL(clicked()), TwpmSubmit, SLOT(SubmitToTwpm()));
        QObject::connect(txtHours, SIGNAL(textEdited(QString)), TwpmSubmit, SLOT(TimeUpdatedManually()));
        QObject::connect(txtMinutes, SIGNAL(textEdited(QString)), TwpmSubmit, SLOT(TimeUpdatedManually()));

        QMetaObject::connectSlotsByName(TwpmSubmit);
    } // setupUi

    void retranslateUi(QDialog *TwpmSubmit)
    {
        TwpmSubmit->setWindowTitle(QApplication::translate("TwpmSubmit", "Submit your time to TeamWorkPM", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TwpmSubmit", "Time to submit:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TwpmSubmit", "hour", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TwpmSubmit", "min", 0, QApplication::UnicodeUTF8));
        chkBillable->setText(QApplication::translate("TwpmSubmit", "Is Billable", 0, QApplication::UnicodeUTF8));
        lblOwner->setText(QString());
        cmdSubmit->setText(QApplication::translate("TwpmSubmit", "Submit", 0, QApplication::UnicodeUTF8));
        cmdAssignTask->setText(QApplication::translate("TwpmSubmit", "Assign Task", 0, QApplication::UnicodeUTF8));
        cmdCancel->setText(QApplication::translate("TwpmSubmit", "Cancel", 0, QApplication::UnicodeUTF8));
        lblTask->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TwpmSubmit: public Ui_TwpmSubmit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWPMSUBMIT_H
