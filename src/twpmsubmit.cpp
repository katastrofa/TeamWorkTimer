#include "twpmsubmit.h"

TwpmSubmit::TwpmSubmit( QWidget *parent )
    : QDialog( parent )
{
   ui.setupUi( this );

   bTimeUpdatedManually = false;
   idProject = 0;
   idTask = 0;
   bSubmit = false;
}

TwpmSubmit::~TwpmSubmit()
{

}



void TwpmSubmit::SetText( QString strText ){
   ui.txtDescription->setText( strText );
}

void TwpmSubmit::SetTime( QTime timeElapsed ){
   ui.lcdTimeInfo->display( timeElapsed.toString( "hh:mm:ss" ) );
   ParseTimeAndUpdate( timeElapsed );
}


void TwpmSubmit::ParseTimeAndUpdate( QTime timeElapsed ){
   if( bTimeUpdatedManually )
      return;

   ui.txtHours->setText( QString( "%1" ).arg( timeElapsed.hour() ) );
   ui.txtMinutes->setText( QString( "%1" ).arg( timeElapsed.minute() ) );
}



void TwpmSubmit::CancelSubmission(){
   this->close();
}

void TwpmSubmit::AssignTask(){
   TwpmAssignTask dlgAssign( this );
   dlgAssign.exec();

   if( dlgAssign.idProject )
      idProject = dlgAssign.idProject;
   if( dlgAssign.idTask )
      idTask = dlgAssign.idTask;

   QString strText = "";
   QString strAuthor = "";
   
   if( idProject && TwpmProject::hashProjects.contains( idProject ) ){
      TwpmProject *pProj = TwpmProject::hashProjects[idProject];
      strText += pProj->strName + ": ";
      if( idTask && pProj->hashTasks.contains( idTask ) ){
         strText += pProj->hashTasks[idTask]->strContent;
         strAuthor += pProj->hashTasks[idTask]->strAuthor;
      }
   }

   ui.lblOwner->setText( strAuthor );
   ui.lblTask->setText( strText );
}

void TwpmSubmit::SubmitToTwpm(){
   QString strError = "";
   if( !idProject )
      strError += "Select a project!\n";

   strDesc = ui.txtDescription->toPlainText();
   if( 0 >= strDesc.length() )
      strError += "Write a description!\n";

   bool bSuccess = true;
   iHours = ui.txtHours->text().toInt( &bSuccess );
   if( !bSuccess )
      strError += "Set correct time!\n";

   iMinutes = ui.txtMinutes->text().toInt( &bSuccess );
   if( !bSuccess )
      strError += "Set correct time!\n";

   if( 0 < strError.length() ){
      QMessageBox msgError;
      msgError.setText( strError );
      msgError.exec();

      return;
   }

   bIsBillable = (Qt::Checked == ui.chkBillable->checkState())
      ? true
      : false;

   bSubmit = true;
   close();
}


void TwpmSubmit::TimeUpdatedManually(){
   bTimeUpdatedManually = true;
}