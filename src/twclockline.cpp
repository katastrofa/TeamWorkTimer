#include "twclockline.h"

TwClockLine::TwClockLine(QWidget *parent)
	: QWidget( parent )
{
	timeElapsed.setHMS( 0, 0, 0 );
}

TwClockLine::~TwClockLine()
{

}



void TwClockLine::InitializeUi(
	QFrame *frmText, 
	QVBoxLayout *layText, 
	QFrame *frmControl, 
	QVBoxLayout *layControl, 
	QMainWindow *wndMain,
	int iSize
){
	frmWrapper = new QFrame( frmControl );
	frmWrapper->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	frmWrapper->setMinimumSize( QSize( 0, 24 ) );
	frmWrapper->setObjectName( QString::fromUtf8( "frmWrapper" ) );
	
	layControl->insertWidget( layControl->count() - 1, frmWrapper );

   txtText = new QLineEdit( frmText );
	txtText->setObjectName( QString::fromUtf8( "txtText" ) );
	txtText->setMinimumSize( QSize( 10, 24 ) );
	txtText->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
	
	layText->insertWidget( layText->count() - 1, txtText );

	cmdSubmit = new QPushButton( frmWrapper );
	cmdSubmit->setGeometry( 0, 0, 60, iSize );
	cmdSubmit->setObjectName( QString::fromUtf8( "cmdSubmit" ) );
	cmdSubmit->setText( QString::fromUtf8( "Submit" ) );
	cmdSubmit->show();

	tmDisplay = new QLCDNumber( frmWrapper );
	tmDisplay->setGeometry( 64, 0, 100, iSize );
	tmDisplay->setObjectName( QString::fromUtf8( "tmDisplay" ) );
	tmDisplay->setNumDigits( 8 );
	tmDisplay->display( timeElapsed.toString( "hh:mm:ss" ) );
	tmDisplay->show();

	cmdStartPause = new QPushButton( frmWrapper );
	cmdStartPause->setGeometry( 168, 0, 48, iSize );
	cmdStartPause->setObjectName( QString::fromUtf8( "cmdStartPause" ) );
	cmdStartPause->setText( QString::fromUtf8( "Pause" ) );
	cmdStartPause->show();

	cmdDelete = new QPushButton( frmWrapper );
	cmdDelete->setGeometry( 216, 0, 20, iSize );
	cmdDelete->setObjectName( QString::fromUtf8( "cmdDelete" ) );
	cmdDelete->setText( QString::fromUtf8( "X" ) );
	cmdDelete->show();


	QObject::connect( cmdSubmit, SIGNAL( clicked() ), this, SLOT( StopSubmitTimer() ) );
	QObject::connect( cmdStartPause, SIGNAL( clicked() ), wndMain, SLOT( StartPause() ) );
	QObject::connect( cmdDelete, SIGNAL( clicked() ), wndMain, SLOT( DeleteTimer() ) );
   QObject::connect(
      this,
      SIGNAL( SubmitTimeToTwpm( QString, int, int, int, int, bool ) ),
      wndMain,
      SLOT( TwpmSubmitTime( QString, int, int, int, int, bool ) )
   );
}

void TwClockLine::DestroyTimer( QVBoxLayout *layText, QVBoxLayout *layControl, QMainWindow *wndMain ){
   layText->removeWidget( txtText );
   layControl->removeWidget( frmWrapper );

   QObject::disconnect( cmdSubmit, SIGNAL( clicked() ), this, SLOT( StopSubmitTimer() ) );
	QObject::disconnect( cmdStartPause, SIGNAL( clicked() ), wndMain, SLOT( StartPause() ) );
	QObject::disconnect( cmdDelete, SIGNAL( clicked() ), wndMain, SLOT( DeleteTimer() ) );
   QObject::disconnect(
      this,
      SIGNAL( SubmitTimeToTwpm( QString, int, int, int, int, bool ) ),
      wndMain,
      SLOT( TwpmSubmitTime( QString, int, int, int, int, bool ) )
   );

   frmWrapper->setParent( NULL );
   txtText->setParent( NULL );
   cmdSubmit->setParent( NULL );
   cmdStartPause->setParent( NULL );
   cmdDelete->setParent( NULL );
   tmDisplay->setParent( NULL );

   delete frmWrapper;
   delete txtText;
   delete cmdSubmit;
   delete cmdStartPause;
   delete cmdDelete;
   delete tmDisplay;

   if( pobjSubmit ){
      pobjSubmit->setParent( NULL );
      pobjSubmit->deleteLater();
   }
}

void TwClockLine::UpdateClock( int iMiliseconds ){
   timeElapsed = timeElapsed.addMSecs( iMiliseconds );
   tmDisplay->display( timeElapsed.toString( "hh:mm:ss" ) );
   if( pobjSubmit )
      pobjSubmit->SetTime( timeElapsed );
}

void TwClockLine::UpdateClock( QTime time ){
   timeElapsed = time;
   tmDisplay->display( timeElapsed.toString( "hh:mm:ss" ) );
   if( pobjSubmit )
      pobjSubmit->SetTime( timeElapsed );
}

void TwClockLine::SetCmdLabel( bool bResume ){
   if( bResume )
      cmdStartPause->setText( QString::fromUtf8( "Resume" ) );
   else
      cmdStartPause->setText( QString::fromUtf8( "Pause" ) );
}



void TwClockLine::StopSubmitTimer(){
   if( !pobjSubmit )
      pobjSubmit = new TwpmSubmit( this );

   pobjSubmit->SetText( txtText->text() );
   pobjSubmit->SetTime( timeElapsed );
   pobjSubmit->exec();

   if( pobjSubmit->bSubmit ){
      emit SubmitTimeToTwpm(
         pobjSubmit->strDesc,
         pobjSubmit->iHours,
         pobjSubmit->iMinutes,
         pobjSubmit->idProject,
         pobjSubmit->idTask,
         pobjSubmit->bIsBillable
      );
   }
}