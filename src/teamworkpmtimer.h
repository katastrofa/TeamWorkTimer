#ifndef TEAMWORKPMTIMER_H
#define TEAMWORKPMTIMER_H

#include <QtGui/QMainWindow>
#include "ui_teamworkpmtimer.h"
#include <QList>
#include <QTime>
#include <QTimer>
#include <QSettings>
#include <QMessageBox>
#include "twpmproject.h"
#include "teamworkapi.h"
#include "twclockline.h"
#include "twpmapisetup.h"

class TeamWorkPmTimer : public QMainWindow
{
	Q_OBJECT

public:
	QList<TwClockLine *> aClocks;
	QTime timeMain;
   QTimer timerUpdater;
   QTimer timerSettings;
   int iRunningTimer;

	TeamWorkPmTimer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TeamWorkPmTimer();

   void StartUpdater( int iIndex );
   void StopUpdater();

   void SaveSettings();
   void LoadSettings();

   void RefreshProject();
   void RefreshProjectTasks( int idProject );
   void RefreshTwpmData();

private:
   QList<int> aProjectsToRefresh;
   bool bReachedLimit;
   bool bApiCall;
   bool bRefreshProjects;
   TeamWorkApi objApi;
   int iSubmittedTimer;

	Ui::TeamWorkPmTimerClass ui;
   
   void ClearProjects();
   int GetClockPosition( QObject *objUi );
   void SetResumeText();
   void AddTimer( QTime timeSet = QTime( 0, 0 ), QString strText = QString( "" ), bool bResume = false );

   void DeleteTimer( int iPosition );

private slots:
	void TwpmApiError( QString strError );
   void ReceiveProjects( QHash<int,TwpmProject *> aProjects );
   void ReceiveTasks( int idProject, QHash<int,TwpmTask *> aTasks );
   void ReceivePostedTime( bool bSent );
   void TwpmRateLimit( int iLeft );
   void TwpmUpdateRateLimit( int iLeft );
   void TwpmRequestFinished();
   
   void AddNewTimer();
	void StartPause();
	void DeleteTimer();
   void TwpmSubmitTime( QString strDesc, int iHours, int iMinutes, int idProject, int idTask, bool bIsBillable );

   void SaveCurrentStatus();
   void SaveAndExit();
   void ShowApiDialog();

   void UpdateClock();
   void AutomaticStoreSettings();
};

#endif // TEAMWORKPMTIMER_H
