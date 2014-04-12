#include "twpmassigntask.h"

TwpmAssignTask::TwpmAssignTask(QWidget *parent)
    : QDialog(parent)
{
   ui.setupUi(this);

   idProject = 0;
   idTask = 0;
   bBlockProject = false;
   bBlockTask = false;

   ui.txtProject->bSelectFromList = true;
   ui.txtTask->bSelectFromList = true;

   ui.txtProject->setFocus();

   /*QStringList aStrings;
   aStrings << "kokot" << "pica" << "cista jebnutost" << "kokotonosic";
   QCompleter *complete = new QCompleter( aStrings, this );
   complete->setCaseSensitivity( Qt::CaseInsensitive );
   ui.txtTest->setCompleter( complete );*/
}

TwpmAssignTask::~TwpmAssignTask()
{

}



void TwpmAssignTask::LoadProjects( QString strText ){
   QList<TwpmProject *> aProjects = TwpmProject::SearchProjects( strText );
   QList<TooltipItem> aItems;

   for( int i = 0; i < aProjects.length(); ++i ){
      TooltipItem objItem( aProjects[i]->id, aProjects[i]->strName );
      aItems.append( objItem );
   }

   idProject = 0;
   ui.txtProject->SetTooltip( aItems );
}

void TwpmAssignTask::LoadTasks( int idProject, QString strText ){
   if( !TwpmProject::hashProjects.contains( idProject ) )
      return;

   int iIndex = strText.indexOf( ":" );
   if( -1 != iIndex )
      strText = strText.mid( iIndex + 1 );

   strText = strText.trimmed();

   QList<TwpmTask *> aTasks = TwpmProject::hashProjects[idProject]->SearchFor( strText );
   QList<TooltipItem> aItems;

   for( int i = 0; i < aTasks.length(); ++i ){
      TooltipItem objItem( aTasks[i]->id, aTasks[i]->strAuthor + ": " + aTasks[i]->strContent );
      aItems.append( objItem );
   }

   idTask = 0;
   ui.txtTask->SetTooltip( aItems );
}



void TwpmAssignTask::ProjectFocus(){
   if( !ui.txtProject->ItemsCount() ){
      QString strText = ui.txtProject->text();
      LoadProjects( strText );
   }
}

void TwpmAssignTask::TaskFocus(){
   if( !idProject )
      return;

   QString strText = ui.txtTask->text();
   LoadTasks( idProject, strText );
}

void TwpmAssignTask::ProjectEdited( QString strProject ){
   if( !bBlockProject )
      LoadProjects( strProject );
   bBlockProject = false;
}

void TwpmAssignTask::TaskEdited( QString strTask ){
   if( idProject && !bBlockTask )
      LoadTasks( idProject, strTask );
   bBlockTask = false;
}

void TwpmAssignTask::ProjectSelected( QString strProject, int idProject ){
   this->idProject = idProject;
   bBlockProject = true;
}

void TwpmAssignTask::TaskSelected( QString strTask, int idTask ){
   this->idTask = idTask;
   bBlockTask = true;
}







void TwpmAssignTask::AssignTask(){
   if( !idProject )
      idTask = 0;
   close();
}

void TwpmAssignTask::CancelTask(){
   idProject = 0;
   idTask = 0;
   close();
}