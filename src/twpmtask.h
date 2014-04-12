#ifndef TWPMTASK_H
#define TWPMTASK_H

#include <QString>

class TwpmTask {

public:
   TwpmTask();
   ~TwpmTask();

   int id;
   int idTaskList;
   QString strContent;
   QString strAuthor;

};

#endif // TWPMTASK_H
