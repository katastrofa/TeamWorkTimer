#include "twpmapisetup.h"

TwpmApiSetup::TwpmApiSetup(QWidget *parent)
    : QDialog(parent)
{
   ui.setupUi(this);

   strUrl.clear();
   strToken.clear();
}

TwpmApiSetup::~TwpmApiSetup()
{

}


void TwpmApiSetup::SetInputBoxes( QString strUrl, QString strToken ){
   this->strUrl = strUrl;
   this->strToken = strToken;

   ui.txtUrl->setText( strUrl );
   ui.txtToken->setText( strToken );
}



void TwpmApiSetup::CloseOnSave(){
   strUrl = ui.txtUrl->text();
   strToken = ui.txtToken->text();

   this->close();
}