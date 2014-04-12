#include "twpmproject.h"

QHash<int, TwpmProject *> TwpmProject::hashProjects;

TwpmProject::TwpmProject() {

}

TwpmProject::~TwpmProject()
{
   ClearTasks();
}


void TwpmProject::ClearTasks(){
   QList<int> aKeys = hashTasks.keys();

   for( int i = 0; i < aKeys.length(); ++i ){
      TwpmTask *pTask = hashTasks[aKeys[i]];
      delete pTask;
   }

   hashTasks.clear();
}



QList<TwpmTask *> TwpmProject::SearchFor( QString strPhrase ){
   QList<TwpmTask *> aTasks;

   QList<int> aKeys = hashTasks.keys();
   for( int i = 0; i < aKeys.length(); ++i ){
      TwpmTask *pTask = hashTasks[aKeys[i]];
      if( pTask->strAuthor.contains( strPhrase, Qt::CaseInsensitive ) 
         || pTask->strContent.contains( strPhrase, Qt::CaseInsensitive )
      ){
         aTasks.append( pTask );
      }
   }

   return aTasks;
}


QList<TwpmProject *> TwpmProject::SearchProjects( QString strPhrase ){
   QList<TwpmProject *> aProjects;

   QList<int> aKeys = hashProjects.keys();
   for( int i = 0; i < aKeys.length(); ++i ){
      TwpmProject *pProject = hashProjects.value( aKeys[i] );
      if( pProject->strName.contains( strPhrase, Qt::CaseInsensitive ) )
         aProjects.append( pProject );
   }

   return aProjects;
}