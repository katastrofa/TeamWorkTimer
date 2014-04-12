#ifndef TWPMPROJECT_H
#define TWPMPROJECT_H

#include "twpmtask.h"
#include <QString>
#include <QList>
#include <QHash>

class TwpmProject {

public:
   TwpmProject();
   ~TwpmProject();

   int id;
   QString strName;
   QHash<int,TwpmTask *> hashTasks;

   void ClearTasks();
   QList<TwpmTask *> SearchFor( QString strPhrase );


   static QHash<int, TwpmProject *> hashProjects;

   static QList<TwpmProject *> SearchProjects( QString strPhrase );
};

#endif // TWPMPROJECT_H
