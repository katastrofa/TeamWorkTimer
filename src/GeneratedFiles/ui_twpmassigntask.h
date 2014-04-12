/********************************************************************************
** Form generated from reading UI file 'twpmassigntask.ui'
**
** Created: Tue May 21 13:17:21 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWPMASSIGNTASK_H
#define UI_TWPMASSIGNTASK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "ktooltiplineedit.h"

QT_BEGIN_NAMESPACE

class Ui_TwpmAssignTask
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    KTooltipLineEdit *txtProject;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    KTooltipLineEdit *txtTask;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cmdAssign;
    QSpacerItem *horizontalSpacer;
    QPushButton *cmdCancel;

    void setupUi(QDialog *TwpmAssignTask)
    {
        if (TwpmAssignTask->objectName().isEmpty())
            TwpmAssignTask->setObjectName(QString::fromUtf8("TwpmAssignTask"));
        TwpmAssignTask->setWindowModality(Qt::ApplicationModal);
        TwpmAssignTask->resize(546, 150);
        TwpmAssignTask->setMinimumSize(QSize(200, 150));
        TwpmAssignTask->setMaximumSize(QSize(16777215, 150));
        verticalLayout = new QVBoxLayout(TwpmAssignTask);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(TwpmAssignTask);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 10, -1, 8);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 0));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        txtProject = new KTooltipLineEdit(frame);
        txtProject->setObjectName(QString::fromUtf8("txtProject"));
        txtProject->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(txtProject);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(TwpmAssignTask);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, 8);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        txtTask = new KTooltipLineEdit(frame_2);
        txtTask->setObjectName(QString::fromUtf8("txtTask"));

        horizontalLayout->addWidget(txtTask);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(TwpmAssignTask);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 40));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cmdAssign = new QPushButton(frame_3);
        cmdAssign->setObjectName(QString::fromUtf8("cmdAssign"));
        cmdAssign->setMinimumSize(QSize(80, 24));
        cmdAssign->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(cmdAssign);

        horizontalSpacer = new QSpacerItem(333, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cmdCancel = new QPushButton(frame_3);
        cmdCancel->setObjectName(QString::fromUtf8("cmdCancel"));
        cmdCancel->setMinimumSize(QSize(80, 24));
        cmdCancel->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(cmdCancel);


        verticalLayout->addWidget(frame_3);


        retranslateUi(TwpmAssignTask);
        QObject::connect(cmdAssign, SIGNAL(clicked()), TwpmAssignTask, SLOT(AssignTask()));
        QObject::connect(cmdCancel, SIGNAL(clicked()), TwpmAssignTask, SLOT(CancelTask()));
        QObject::connect(txtProject, SIGNAL(KFocusIn()), TwpmAssignTask, SLOT(ProjectFocus()));
        QObject::connect(txtTask, SIGNAL(KFocusIn()), TwpmAssignTask, SLOT(TaskFocus()));
        QObject::connect(txtProject, SIGNAL(textChanged(QString)), TwpmAssignTask, SLOT(ProjectEdited(QString)));
        QObject::connect(txtTask, SIGNAL(textChanged(QString)), TwpmAssignTask, SLOT(TaskEdited(QString)));
        QObject::connect(txtProject, SIGNAL(KSelectedText(QString,int)), TwpmAssignTask, SLOT(ProjectSelected(QString,int)));
        QObject::connect(txtTask, SIGNAL(KSelectedText(QString,int)), TwpmAssignTask, SLOT(TaskSelected(QString,int)));

        QMetaObject::connectSlotsByName(TwpmAssignTask);
    } // setupUi

    void retranslateUi(QDialog *TwpmAssignTask)
    {
        TwpmAssignTask->setWindowTitle(QApplication::translate("TwpmAssignTask", "Assign Task to time", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TwpmAssignTask", "Project", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TwpmAssignTask", "Task", 0, QApplication::UnicodeUTF8));
        cmdAssign->setText(QApplication::translate("TwpmAssignTask", "Assign", 0, QApplication::UnicodeUTF8));
        cmdCancel->setText(QApplication::translate("TwpmAssignTask", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TwpmAssignTask: public Ui_TwpmAssignTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWPMASSIGNTASK_H
