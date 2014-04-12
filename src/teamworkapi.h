#ifndef TEAMWORKAPI_H
#define TEAMWORKAPI_H

#include <QObject>
#include <QPointer>
#include <QtNetwork>
#include <QSslConfiguration>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QHash>
#include <QtXml>
#include <QDomDocument>
#include <QMessageBox>
#include <QFuture>
#include <QDate>

#include "twpmtask.h"
#include "twpmproject.h"


class TeamWorkApi : public QObject
{
   Q_OBJECT

public:
   enum TypeOfRequest {
      TmpmGetProjects,
      TmpmGetTaskLists,
      TmpmGetCurrentUser,
      TmpmPostTime
   };

   QString strMainUrl;
   QString strToken;
   int idPerson;
   
   QString strSomeError;

   TeamWorkApi( QObject *parent );
   ~TeamWorkApi();

   void LoadPersonId();
   void GetProjects();
   void GetTasks( int idProject, int iPage = 1 );
   void PostTime( QString strDesc, int iHours, int iMinutes, int idProject, int idTask, bool bIsBillable );

   QDomDocument* ParseResponse( QString strName, QString strXml );

signals:
   void ReturnProjects( QHash<int,TwpmProject *> );
   void ReturnTasks( int, QHash<int,TwpmTask *> );
   void PostedTime( bool );

   void TmpmApiError( QString );
   void ClosingToRateLimit( int );
   void TwpmRateLimit( int );
   void TwpmRequestFinished();

private:
   QNetworkAccessManager objNetwork;
   QPointer<QNetworkReply> pobjReply;

   QString strCurrentRequest;
   TypeOfRequest typeCurrentRequest;
   int idCurrent;

   QHash<int,TwpmProject *> hashTempProjects;
   QHash<int,TwpmTask *> hashTempTasks;
   bool bMultiPage;

   void IssueRequest( QString strUrl, QString strData = "" );
   QNetworkRequest CreateRequestObject( QString strUrl );

   QDomDocument* FutureParseResponse( QString strName, QString strXml );
   void ParseUser();
   void ParseProjects();
   void ParseTasks( int iFollowupPage = 0 );
   void ParsePostedTime( int iStatusCode );

private slots:
   void ReadHttpData();
   void RequestFinished();
   void HandleHttpError( QNetworkReply::NetworkError code );

   #ifndef QT_NO_OPENSSL
      void DealWithSslErrors( QNetworkReply *pReply, QList<QSslError> aErrors );
   #endif

};

#endif // TEAMWORKAPI_H
