/********************************************************************************
** Form generated from reading UI file 'teamworkpmtimer.ui'
**
** Created: Tue May 21 13:17:18 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMWORKPMTIMER_H
#define UI_TEAMWORKPMTIMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeamWorkPmTimerClass
{
public:
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QFrame *frmRight;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *layRight;
    QFrame *frame_2;
    QFrame *frmBottom;
    QPushButton *cmdAdd;
    QLabel *lblInfo;
    QFrame *frmMain;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layMain;
    QFrame *frame3;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *TeamWorkPmTimerClass)
    {
        if (TeamWorkPmTimerClass->objectName().isEmpty())
            TeamWorkPmTimerClass->setObjectName(QString::fromUtf8("TeamWorkPmTimerClass"));
        TeamWorkPmTimerClass->resize(511, 424);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(TeamWorkPmTimerClass->sizePolicy().hasHeightForWidth());
        TeamWorkPmTimerClass->setSizePolicy(sizePolicy);
        TeamWorkPmTimerClass->setMinimumSize(QSize(400, 300));
        actionSave = new QAction(TeamWorkPmTimerClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(TeamWorkPmTimerClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(TeamWorkPmTimerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frmRight = new QFrame(centralWidget);
        frmRight->setObjectName(QString::fromUtf8("frmRight"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frmRight->sizePolicy().hasHeightForWidth());
        frmRight->setSizePolicy(sizePolicy1);
        frmRight->setMinimumSize(QSize(260, 0));
        frmRight->setFrameShape(QFrame::StyledPanel);
        frmRight->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frmRight);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        layRight = new QVBoxLayout();
        layRight->setSpacing(8);
        layRight->setObjectName(QString::fromUtf8("layRight"));
        layRight->setContentsMargins(8, 8, 8, -1);
        frame_2 = new QFrame(frmRight);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        layRight->addWidget(frame_2);


        verticalLayout_3->addLayout(layRight);


        gridLayout->addWidget(frmRight, 0, 1, 1, 1);

        frmBottom = new QFrame(centralWidget);
        frmBottom->setObjectName(QString::fromUtf8("frmBottom"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frmBottom->sizePolicy().hasHeightForWidth());
        frmBottom->setSizePolicy(sizePolicy2);
        frmBottom->setMinimumSize(QSize(0, 40));
        frmBottom->setFrameShape(QFrame::StyledPanel);
        frmBottom->setFrameShadow(QFrame::Raised);
        cmdAdd = new QPushButton(frmBottom);
        cmdAdd->setObjectName(QString::fromUtf8("cmdAdd"));
        cmdAdd->setGeometry(QRect(24, 8, 100, 24));
        lblInfo = new QLabel(frmBottom);
        lblInfo->setObjectName(QString::fromUtf8("lblInfo"));
        lblInfo->setGeometry(QRect(132, 8, 168, 24));
        lblInfo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(frmBottom, 1, 0, 1, 2);

        frmMain = new QFrame(centralWidget);
        frmMain->setObjectName(QString::fromUtf8("frmMain"));
        verticalLayout_2 = new QVBoxLayout(frmMain);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        layMain = new QVBoxLayout();
        layMain->setSpacing(8);
        layMain->setObjectName(QString::fromUtf8("layMain"));
        layMain->setContentsMargins(8, 8, 8, -1);
        frame3 = new QFrame(frmMain);
        frame3->setObjectName(QString::fromUtf8("frame3"));
        frame3->setFrameShape(QFrame::StyledPanel);
        frame3->setFrameShadow(QFrame::Raised);

        layMain->addWidget(frame3);


        verticalLayout_2->addLayout(layMain);


        gridLayout->addWidget(frmMain, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        TeamWorkPmTimerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TeamWorkPmTimerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 511, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        TeamWorkPmTimerClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);

        retranslateUi(TeamWorkPmTimerClass);
        QObject::connect(actionExit, SIGNAL(triggered()), TeamWorkPmTimerClass, SLOT(SaveAndExit()));
        QObject::connect(actionSave, SIGNAL(triggered()), TeamWorkPmTimerClass, SLOT(SaveCurrentStatus()));
        QObject::connect(cmdAdd, SIGNAL(clicked()), TeamWorkPmTimerClass, SLOT(AddNewTimer()));

        QMetaObject::connectSlotsByName(TeamWorkPmTimerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TeamWorkPmTimerClass)
    {
        TeamWorkPmTimerClass->setWindowTitle(QApplication::translate("TeamWorkPmTimerClass", "TeamWorkPmTimer", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("TeamWorkPmTimerClass", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("TeamWorkPmTimerClass", "Exit", 0, QApplication::UnicodeUTF8));
        cmdAdd->setText(QApplication::translate("TeamWorkPmTimerClass", "Add Timer", 0, QApplication::UnicodeUTF8));
        lblInfo->setText(QString());
        menuFile->setTitle(QApplication::translate("TeamWorkPmTimerClass", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TeamWorkPmTimerClass: public Ui_TeamWorkPmTimerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMWORKPMTIMER_H
