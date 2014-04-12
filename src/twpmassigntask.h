#ifndef TWPMASSIGNTASK_H
#define TWPMASSIGNTASK_H

#include <QDialog>
#include <QPoint>
#include <QRect>
#include <QListView>
#include <QDesktopWidget>
#include <QFocusEvent>
#include <QCompleter>
#include "ktooltiplineedit.h"
#include "twpmproject.h"
#include "ui_twpmassigntask.h"

class TwpmAssignTask : public QDialog {
   Q_OBJECT

public:
   TwpmAssignTask(QWidget *parent = 0);
   ~TwpmAssignTask();

   int idProject;
   int idTask;

protected:

private:
   Ui::TwpmAssignTask ui;

   bool bBlockProject;
   bool bBlockTask;

   void LoadProjects( QString strText );
   void LoadTasks( int idProject, QString strText );

private slots:
   void ProjectFocus();
   void TaskFocus();
   void ProjectEdited( QString strProject );
   void TaskEdited( QString strTask );

   void ProjectSelected( QString strProject, int idProject );
   void TaskSelected( QString strTask, int idTask );

   void AssignTask();
   void CancelTask();
};

#endif // TWPMASSIGNTASK_H
