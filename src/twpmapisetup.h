#ifndef TWPMAPISETUP_H
#define TWPMAPISETUP_H

#include <QDialog>
#include "ui_twpmapisetup.h"

class TwpmApiSetup : public QDialog {
   Q_OBJECT

public:
   TwpmApiSetup(QWidget *parent = 0);
   ~TwpmApiSetup();

   QString strUrl;
   QString strToken;

   void SetInputBoxes( QString strUrl, QString strToken );

private:
   Ui::TwpmApiSetupClass ui;

private slots:
   void CloseOnSave();
};

#endif // TWPMAPISETUP_H
