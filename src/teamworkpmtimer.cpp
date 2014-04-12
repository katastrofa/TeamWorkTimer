#include "teamworkpmtimer.h"

TeamWorkPmTimer::TeamWorkPmTimer(QWidget *parent, Qt::WFlags flags)
   : QMainWindow(parent, flags), objApi( this )
{
	ui.setupUi(this);
   iRunningTimer = -1;
   iSubmittedTimer = -1;
   bReachedLimit = false;
   bApiCall = false;
   bRefreshProjects = false;

   QObject::connect( &timerSettings, SIGNAL( timeout() ), this, SLOT( AutomaticStoreSettings() ) );
   QObject::connect( &timerUpdater, SIGNAL( timeout() ), this, SLOT( UpdateClock() ) );

   QObject::connect( &objApi, SIGNAL( TmpmApiError( QString ) ), this, SLOT( TwpmApiError( QString ) ) );
   QObject::connect( &objApi, SIGNAL( ClosingToRateLimit( int ) ), this, SLOT( TwpmRateLimit( int ) ) );
   QObject::connect( &objApi, SIGNAL( TwpmRateLimit( int ) ), this, SLOT( TwpmUpdateRateLimit( int ) ) );
   QObject::connect( &objApi, SIGNAL( PostedTime( bool ) ), this, SLOT( ReceivePostedTime( bool ) ) );
   QObject::connect( &objApi, SIGNAL( TwpmRequestFinished() ), this, SLOT( TwpmRequestFinished() ) );
   QObject::connect(
      &objApi,
      SIGNAL( ReturnProjects( QHash<int,TwpmProject *> ) ),
      this,
      SLOT( ReceiveProjects( QHash<int,TwpmProject *> ) )
   );
   QObject::connect(
      &objApi,
      SIGNAL( ReturnTasks( int, QHash<int,TwpmTask *> ) ),
      this,
      SLOT( ReceiveTasks( int, QHash<int,TwpmTask *> ) )
   );

   LoadSettings();

   //objApi.strMainUrl = "https://devfolio.teamworkpm.net";
   //objApi.strToken = "wing841forget";
   //objApi.strMainUrl = "http://clients.foliovision.com";
   //objApi.strToken = "horse260radio";

   ShowApiDialog();

   bApiCall = true;
   objApi.LoadPersonId();
   RefreshProject();

   timerSettings.start( 60000 );
}

TeamWorkPmTimer::~TeamWorkPmTimer()
{
	//aClocks.clear();
   SaveSettings();
   ClearProjects();
}


void TeamWorkPmTimer::StartUpdater( int iIndex ){
   iRunningTimer = iIndex;
   timeMain.start();
   timerUpdater.start( 1000 );
}

void TeamWorkPmTimer::StopUpdater(){
   timerUpdater.stop();
   int iMili = timeMain.elapsed();

   if( 0 <= iRunningTimer )
      aClocks[iRunningTimer]->UpdateClock( iMili );
   iRunningTimer = -1;
}

void TeamWorkPmTimer::SaveSettings(){
   QSettings setStore( QSettings::UserScope, QString( "Katastrofa" ), QString( "TeamWorkPmTimer" ) );

   setStore.setValue( "twpm-api-url", objApi.strMainUrl );
   //setStore.setValue( "twpm-api-person", objApi.idPerson );

   setStore.beginWriteArray( "timers" );
   for( int i = 0; i < aClocks.size(); ++i ){
      setStore.setArrayIndex( i );
      setStore.setValue( "timer-time", aClocks[i]->timeElapsed );
      setStore.setValue( "timer-text", aClocks[i]->txtText->text() );
   }
   setStore.endArray();
}

void TeamWorkPmTimer::LoadSettings(){
   StopUpdater();
   iRunningTimer = -1;

   foreach( TwClockLine *pClock, aClocks )
      pClock->DestroyTimer( ui.layMain, ui.layRight, this );
   aClocks.clear();

   QSettings setLoad( QSettings::UserScope, QString( "Katastrofa" ), QString( "TeamWorkPmTimer" ) );

   objApi.strMainUrl = setLoad.value( "twpm-api-url" ).toString();
   //objApi.idPerson = setLoad.value( "twpm-api-person" ).toInt();

   int iSize = setLoad.beginReadArray( "timers" );
   for( int i = 0; i < iSize; ++i ){
      setLoad.setArrayIndex( i );
      QTime timeLoad = setLoad.value( "timer-time" ).toTime();
      QString strLoad = setLoad.value( "timer-text" ).toString();

      AddTimer( timeLoad, strLoad, true );
   }
   setLoad.endArray();
}

void TeamWorkPmTimer::RefreshProject(){
   if( bApiCall ){
      bRefreshProjects = true;
      return;
   }
   if( 0 < aProjectsToRefresh.length() )
      return;

   try{
      bApiCall = true;
      objApi.GetProjects();
   }catch( QString strError ){}
}

void TeamWorkPmTimer::RefreshProjectTasks( int idProject ){
   if( bApiCall )
      return;

   try{
      bApiCall = true;
      objApi.GetTasks( idProject );
   }catch( QString strError ){}
}

void TeamWorkPmTimer::RefreshTwpmData(){
   if( bApiCall )
      return;

   if( !bReachedLimit && 0 < aProjectsToRefresh.length() ){
      int idProject = aProjectsToRefresh[0];
      aProjectsToRefresh.removeFirst();
      objApi.GetTasks( idProject );
   }

   if( bRefreshProjects ){
      bRefreshProjects = false;
      RefreshProject();
   }

   bReachedLimit = false;
}




void TeamWorkPmTimer::ClearProjects(){
   QList<int> aKeys = TwpmProject::hashProjects.keys();

   for( int i = 0; i < aKeys.length(); ++i ){
      TwpmProject *pProject = TwpmProject::hashProjects[aKeys[i]];
      delete pProject;
   }

   TwpmProject::hashProjects.clear();
}

int TeamWorkPmTimer::GetClockPosition( QObject *objUi ){
   int iCount = aClocks.size();
   for( int i = 0; i < iCount; i++ ){
      if( objUi == aClocks[i]->cmdDelete )
         return i;
      else if( objUi == aClocks[i]->cmdStartPause )
         return i;
      else if( objUi == aClocks[i]->cmdSubmit )
         return i;
      else if( objUi == aClocks[i] )
         return i;
   }

   throw QString( "Cannot find index" );
}

void TeamWorkPmTimer::SetResumeText(){
   foreach( TwClockLine *pClock, aClocks )
      pClock->SetCmdLabel( true );
}




void TeamWorkPmTimer::TwpmApiError( QString strError ){
   QMessageBox msgError;
   msgError.setText( strError );
   msgError.exec();
}

void TeamWorkPmTimer::ReceiveProjects( QHash<int,TwpmProject *> hashProjects ){
   ClearProjects();
   aProjectsToRefresh.clear();

   TwpmProject::hashProjects = hashProjects;
   aProjectsToRefresh = hashProjects.keys();
}

void TeamWorkPmTimer::ReceiveTasks( int idProject, QHash<int,TwpmTask *> hashTasks ){
   if( TwpmProject::hashProjects.contains( idProject ) ){
      TwpmProject::hashProjects[idProject]->ClearTasks();
      TwpmProject::hashProjects[idProject]->hashTasks = hashTasks;
   }
}

void TeamWorkPmTimer::ReceivePostedTime( bool bSent ){
   if( bSent && -1 < iSubmittedTimer && aClocks.length() > iSubmittedTimer )
      DeleteTimer( iSubmittedTimer );
   else{
      QMessageBox msgError;
      msgError.setText( "Error in sending time to TeamWorkApi!" );
      msgError.exec();
   }
}

void TeamWorkPmTimer::TwpmRateLimit( int iLeft ){
   bReachedLimit = true;
}

void TeamWorkPmTimer::TwpmUpdateRateLimit( int iLeft ){
   QString strInfo = QString( "Projects: %1, To refresh: %2,\nRate Limit: %3" )
      .arg( TwpmProject::hashProjects.count() )
      .arg( aProjectsToRefresh.length() )
      .arg( iLeft );

   ui.lblInfo->setText( strInfo );
}

void TeamWorkPmTimer::TwpmRequestFinished(){
   bApiCall = false;
   RefreshTwpmData();
}



void TeamWorkPmTimer::AddTimer( QTime timeSet, QString strText, bool bResume ){
   TwClockLine *pClock = new TwClockLine( this );
	pClock->InitializeUi( ui.frmMain, ui.layMain, ui.frmRight, ui.layRight, this );

   pClock->UpdateClock( timeSet );
   pClock->txtText->setText( strText );
   if( bResume )
      pClock->SetCmdLabel( true );

	aClocks << pClock;
}

void TeamWorkPmTimer::AddNewTimer(){
   SetResumeText();

   AddTimer();

   if( 0 > iRunningTimer )
      StartUpdater( aClocks.size() - 1 );
   iRunningTimer = aClocks.size() - 1;
}

void TeamWorkPmTimer::StartPause(){
   QObject *cmdDelete = this->sender();
	if( !cmdDelete )
		return;

   int iIndex = GetClockPosition( cmdDelete );
   if( iIndex == iRunningTimer ){
      SetResumeText();
      StopUpdater();
   }else{
      SetResumeText();
      if( 0 > iRunningTimer )
         StartUpdater( iIndex );

      iRunningTimer = iIndex;
      aClocks[iIndex]->SetCmdLabel( false );
   }
}

void TeamWorkPmTimer::DeleteTimer( int iPosition ){
   if( iPosition < iRunningTimer )
      iRunningTimer--;
   else if( iPosition == iRunningTimer )
      StopUpdater();

   aClocks[iPosition]->DestroyTimer( ui.layMain, ui.layRight, this );
   aClocks.removeAt( iPosition );
}

void TeamWorkPmTimer::DeleteTimer(){
	QObject *cmdDelete = this->sender();
	if( !cmdDelete )
		return;

   int iIndex = GetClockPosition( cmdDelete );
   DeleteTimer( iIndex );
}

void TeamWorkPmTimer::TwpmSubmitTime( QString strDesc, int iHours, int iMinutes, int idProject, int idTask, bool bIsBillable ){
   bApiCall = true;
   objApi.PostTime( strDesc, iHours, iMinutes, idProject, idTask, bIsBillable );

   QObject *objTimer = this->sender();
   iSubmittedTimer = GetClockPosition( objTimer );
}



void TeamWorkPmTimer::SaveCurrentStatus(){
	SaveSettings();
}

void TeamWorkPmTimer::SaveAndExit(){
   SaveSettings();
   close();
}

void TeamWorkPmTimer::ShowApiDialog(){
   TwpmApiSetup dlgSetup( this );
   dlgSetup.SetInputBoxes( objApi.strMainUrl, objApi.strToken );
   dlgSetup.exec();

   objApi.strMainUrl = dlgSetup.strUrl;
   objApi.strToken = dlgSetup.strToken;
}


void TeamWorkPmTimer::UpdateClock(){
   if( 0 > iRunningTimer )
      StopUpdater();

   int iMili = timeMain.elapsed();
   aClocks[iRunningTimer]->UpdateClock( iMili );
   timeMain.start();
}

void TeamWorkPmTimer::AutomaticStoreSettings(){
   SaveSettings();
}
