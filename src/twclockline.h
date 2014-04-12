#ifndef TWCLOCKLINE_H
#define TWCLOCKLINE_H

#include <QObject>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QLineEdit>
#include <QFrame>
#include <QTime>
#include <QMainWindow>
#include <QPointer>
#include <QHash>
#include <QMessageBox>
#include "twpmproject.h"
#include "twpmsubmit.h"


class TwClockLine : public QWidget
{
	Q_OBJECT

public:
	QFrame *frmWrapper;
	QPushButton *cmdSubmit;
	QPushButton *cmdStartPause;
	QPushButton *cmdDelete;
	QLCDNumber *tmDisplay;
	QLineEdit *txtText;
	QTime timeElapsed;

   QPointer<TwpmSubmit> pobjSubmit;

	TwClockLine(QWidget *parent);
	~TwClockLine();

	void InitializeUi(
		QFrame *frmText, 
		QVBoxLayout *layText, 
		QFrame *frmControl, 
		QVBoxLayout *layControl,
		QMainWindow *wndMain,
		int iSize = 24
	);
   void DestroyTimer( QVBoxLayout *layText, QVBoxLayout *layControl, QMainWindow *wndMain );
   void UpdateClock( int iMiliseconds );
   void UpdateClock( QTime time );
   void SetCmdLabel( bool bResume );

signals:
   void SubmitTimeToTwpm( QString strDesc, int iHours, int iMinutes, int idProject, int idTask, bool bIsBillable );

private:
	
private slots:
	void StopSubmitTimer();
};

#endif // TWCLOCKLINE_H
