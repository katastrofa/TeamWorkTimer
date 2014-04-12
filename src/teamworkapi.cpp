#include "teamworkapi.h"

TeamWorkApi::TeamWorkApi(QObject *parent)
   : QObject(parent)
{
   #ifndef QT_NO_OPENSSL
      QObject::connect(
         &objNetwork,
         SIGNAL( sslErrors( QNetworkReply *, QList<QSslError> ) ),
         this,
         SLOT( DealWithSslErrors( QNetworkReply *, QList<QSslError> ) )
      );
   #endif

   bMultiPage = false;
   strMainUrl = "";
   strToken = "";
   idPerson = 0;
}

TeamWorkApi::~TeamWorkApi()
{
   if( pobjReply ){
      pobjReply->close();
      pobjReply->deleteLater();
   }
}



void TeamWorkApi::LoadPersonId(){
   typeCurrentRequest = TypeOfRequest::TmpmGetCurrentUser;

   IssueRequest( "/me.xml" );
}

void TeamWorkApi::GetProjects(){
   typeCurrentRequest = TypeOfRequest::TmpmGetProjects;
   if( !bMultiPage )
      hashTempProjects.clear();

   IssueRequest( "/projects.xml" );
}

void TeamWorkApi::GetTasks( int idProject, int iPage ){
   typeCurrentRequest = TypeOfRequest::TmpmGetTaskLists;
   idCurrent = idProject;
   if( !bMultiPage )
      hashTempTasks.clear();

   QString strRequest = QString( "/projects/%1/todo_lists.xml?status=all" ).arg( idProject );
   if( 1 < iPage )
      strRequest += QString( "&page=%1" ).arg( iPage );

   IssueRequest( strRequest );
}

void TeamWorkApi::PostTime( QString strDesc, int iHours, int iMinutes, int idProject, int idTask, bool bIsBillable ){
   typeCurrentRequest = TypeOfRequest::TmpmPostTime;

   QString strData = QString( "<request><time-entry><description>%1</description><person-id>%2</person-id><date>%3</date><hours>%4</hours><minutes>%5</minutes><time>%6</time><isbillable type=\"boolean\">%7</isbillable></time-entry></request>" )
      .arg( strDesc )
      .arg( idPerson )
      .arg( QDate::currentDate().toString( "yyyyMMdd" ) )
      .arg( iHours )
      .arg( iMinutes )
      .arg( "08:00" )
      .arg( bIsBillable ? "yes" : "no" );

   QString strRequest;
   if( idTask )
      strRequest = QString( "/todo_items/%1/time_entries.xml" ).arg( idTask );
   else
      strRequest = QString( "/projects/%1/time_entries.xml" ).arg( idProject );

   IssueRequest( strRequest, strData );
}



QDomDocument* TeamWorkApi::ParseResponse( QString strName, QString strXml ){
   QDomDocument *domResponse = new QDomDocument( strName );
   QString strError;
   strError.clear();

   if( !domResponse->setContent( strXml, &strError ) ){
      delete domResponse;
      strSomeError = "Error while parsing XML: " + strError + "\n\n" + strXml;

      return NULL;
   }

   return domResponse;
}




void TeamWorkApi::IssueRequest( QString strUrl, QString strData ){
   strCurrentRequest.clear();

   QNetworkRequest objRequest = CreateRequestObject( strUrl );
   if( 0 < strData.length() )
      pobjReply = objNetwork.post( objRequest, strData.toAscii() );
   else
      pobjReply = objNetwork.get( objRequest );

   QObject::connect( pobjReply, SIGNAL( error( QNetworkReply::NetworkError ) ), this, SLOT( HandleHttpError( QNetworkReply::NetworkError ) ) );
   QObject::connect( pobjReply, SIGNAL( finished() ), this, SLOT( RequestFinished() ) );
   QObject::connect( pobjReply, SIGNAL( readyRead() ), this, SLOT( ReadHttpData() ) );
}


QNetworkRequest TeamWorkApi::CreateRequestObject( QString strUrl ){
   if( 7 >= strMainUrl.length() ){
      emit TmpmApiError( QString( "URL for TeamWorkPm is not set!" ) );
      throw QString( "URL for TeamWorkPm is not set!" );
   }
   if( 2 >= strToken.length() ){
      emit TmpmApiError( QString( "Please set your TeamWorkPm token!" ) );
      throw QString( "Please set your TeamWorkPm token!" );
   }
   
   QByteArray strbaToken( strToken.toAscii() );
   strbaToken += ":xxx";

   QNetworkRequest objRequest( strMainUrl + strUrl );
   objRequest.setHeader( QNetworkRequest::ContentTypeHeader, QString( "application/xml" ) );
   objRequest.setRawHeader( QByteArray( "Accept" ), QByteArray( "application/xml" ) );
   objRequest.setRawHeader( QByteArray( "Accept-Charset" ), QByteArray( "utf-8" ) );
   objRequest.setRawHeader( QByteArray( "Authorization" ), QByteArray( "Basic " ) + strbaToken.toBase64() );
   objRequest.setRawHeader( QByteArray( "Connection" ), QByteArray( "keep-alive" ) );
   objRequest.setRawHeader( QByteArray( "Keep-Alive" ), QByteArray( "60" ) );

   if( strMainUrl.startsWith( "https" ) ){
      #ifndef QT_NO_OPENSSL
         objRequest.setSslConfiguration( QSslConfiguration::defaultConfiguration() );
      #else
         emit TmpmApiError( QString( "Unable to login via https, OpenSSL not installed!" ) );
      #endif
   }

   return objRequest;
}


QDomDocument* TeamWorkApi::FutureParseResponse( QString strName, QString strXml ){
   strSomeError.clear();
   
   QFuture<QDomDocument*> objFuture = QtConcurrent::run( this, &TeamWorkApi::ParseResponse, strName, strXml );
   while( !objFuture.isFinished() )
      QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );

   QDomDocument *pdomResult = objFuture.result();
   if( 0 < strSomeError.length() ){
      emit TmpmApiError( strSomeError );
      return NULL;
   }

   return pdomResult;
}

void TeamWorkApi::ParseUser(){
   QScopedPointer<QDomDocument> pdomUser( FutureParseResponse( "person", strCurrentRequest ) );
   if( !pdomUser )
      return;

   QDomElement domId = pdomUser->firstChildElement( "person" ).firstChildElement( "id" );
   if( !domId.isNull() )
      idPerson = domId.firstChild().nodeValue().toInt();
}

void TeamWorkApi::ParseProjects(){
   QScopedPointer<QDomDocument> pdomProjects( FutureParseResponse( "projects", strCurrentRequest ) );
   if( !pdomProjects )
      return;
   
   QHash<int,TwpmProject *> hashProjects;
   QDomNodeList alProjects = pdomProjects->elementsByTagName( "project" );
   int iSize = alProjects.size();

   for( int i = 0; i < iSize; ++i ){
      if( !alProjects.at( i ).isElement() )
         continue;

      TwpmProject *pProject = new TwpmProject;
      pProject->id = alProjects.at( i ).namedItem( "id" ).firstChild().nodeValue().toInt();
      pProject->strName = alProjects.at( i ).namedItem( "name" ).firstChild().nodeValue();

      hashTempProjects.insert( pProject->id, pProject );
   }

   emit ReturnProjects( hashTempProjects );
}

void TeamWorkApi::ParseTasks( int iFollowupPage ){
   QScopedPointer<QDomDocument> pdomTaskLists( FutureParseResponse( "task-lists", strCurrentRequest ) );
   if( !pdomTaskLists )
      return;
   
   QDomElement domTaskList = pdomTaskLists->firstChildElement( "todo-lists" ).firstChildElement( "todo-list" );
   int i = 0;

   while( !domTaskList.isNull() ){
      int idTaskList = domTaskList.namedItem( "id" ).firstChild().nodeValue().toInt();
      QDomElement domTask = domTaskList.namedItem( "todo-items" ).firstChildElement( "todo-item" );

      while( !domTask.isNull() ){
         TwpmTask *pTask = new TwpmTask();
         pTask->strAuthor = domTask.namedItem( "responsible-party-names" ).firstChild().nodeValue();
         pTask->strContent = domTask.namedItem( "content" ).firstChild().nodeValue();
         pTask->idTaskList = idTaskList;
         pTask->id = domTask.namedItem( "id" ).firstChild().nodeValue().toInt();

         hashTempTasks.insert( pTask->id, pTask );

         domTask = domTask.nextSiblingElement( "todo-item" );
      }

      domTaskList = domTaskList.nextSiblingElement( "todo-list" );
      i++;

      if( 0 == i % 10 )
         QCoreApplication::processEvents();
   }

   if( bMultiPage )
      GetTasks( idCurrent, iFollowupPage );
   else
      emit ReturnTasks( this->idCurrent, hashTempTasks );
}

void TeamWorkApi::ParsePostedTime( int iStatusCode ){
   if( 201 == iStatusCode )
      emit PostedTime( true );
   else
      emit PostedTime( false );
}




void TeamWorkApi::ReadHttpData(){
   if( QIODevice::NotOpen != pobjReply->openMode() ){
      strCurrentRequest += pobjReply->readAll();
      QCoreApplication::processEvents( QEventLoop::ExcludeSocketNotifiers );
   }
}

void TeamWorkApi::RequestFinished(){
   QIODevice::OpenMode eOpen = pobjReply->openMode();
   bMultiPage = false;

   int iStatusCode = pobjReply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt();

   bool bPages = false;
   if( pobjReply->hasRawHeader( "X-Pages" ) )
      bPages = true;

   int iPages = 1;
   int iPage = 1;

   if( bPages ){
      iPages = pobjReply->rawHeader( "X-Pages" ).toInt();
      iPage = pobjReply->rawHeader( "X-Page" ).toInt();
      if( iPage < iPages )
         bMultiPage = true;
   }

   int iRemaining = 100;
   if( pobjReply->hasRawHeader( "X-RateLimit-Remaining" ) )
      iRemaining = pobjReply->rawHeader( "X-RateLimit-Remaining" ).toInt();
   emit TwpmRateLimit( iRemaining );
   if( 15 > iRemaining )
      emit ClosingToRateLimit( iRemaining );

   pobjReply->deleteLater();

   if( QIODevice::NotOpen == eOpen )
      return;

   switch( typeCurrentRequest ){
      case TypeOfRequest::TmpmGetProjects:
         ParseProjects();
         break;
      case TypeOfRequest::TmpmGetTaskLists:
         ParseTasks( iPage + 1 );
         break;
      case TypeOfRequest::TmpmGetCurrentUser:
         ParseUser();
         break;
      case TypeOfRequest::TmpmPostTime:
         ParsePostedTime( iStatusCode );
         break;
   }

   emit TwpmRequestFinished();
}

void TeamWorkApi::HandleHttpError( QNetworkReply::NetworkError code ){
   emit TmpmApiError( pobjReply->errorString() );
}



#ifndef QT_NO_OPENSSL

   void TeamWorkApi::DealWithSslErrors( QNetworkReply *pReply, QList<QSslError> aErrors ){
      QString strError = "";
      foreach( const QSslError &objError, aErrors )
         strError += objError.errorString();

      emit TmpmApiError( strError );
   }

#endif
