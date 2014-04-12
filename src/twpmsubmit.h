#ifndef TWPMSUBMIT_H
#define TWPMSUBMIT_H

#include <QDialog>
#include <QTime>
#include <QPointer>
#include <QHash>
#include <QMessageBox>
#include "ui_twpmsubmit.h"
#include "twpmproject.h"
#include "twpmassigntask.h"


class TwpmSubmit : public QDialog {
   Q_OBJECT

public:
   TwpmSubmit( QWidget *parent = 0 );
   ~TwpmSubmit();

   QString strDesc;
   int idProject;
   int idTask;
   int iHours;
   int iMinutes;
   bool bIsBillable;
   bool bSubmit;

   void SetText( QString strText );
   void SetTime( QTime timeElapsed );

private:
   Ui::TwpmSubmit ui;

   bool bTimeUpdatedManually;

   void ParseTimeAndUpdate( QTime timeElapsed );

private slots:
   void CancelSubmission();
   void AssignTask();
   void SubmitToTwpm();

   void TimeUpdatedManually();
};

#endif // TWPMSUBMIT_H
