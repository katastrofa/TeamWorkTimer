#include "ktooltiplineedit.h"

TooltipItem::TooltipItem( int id, QString strText ){
   this->id = id;
   this->strText = strText;
}


KTooltipLineEdit::KTooltipLineEdit(QWidget *parent)
   : QLineEdit(parent) 
{
   listTooltip = new QListWidget( 0 );
   listTooltip->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
   listTooltip->setWindowFlags( Qt::ToolTip );

   bTooltipVisible = false;
   iSelectedRow = -1;
   iSelected = 0;
   bSelectFromList = false;

   //this->setFocusPolicy( Qt::StrongFocus );

   /*QDesktopWidget* desktopWidget = QApplication::desktop();
   desktopWidget->installEventFilter( this );*/

   QWidget *windowOwner = this->window();
   windowOwner->installEventFilter( this );

   iTooltipHeight = 300;
}

KTooltipLineEdit::~KTooltipLineEdit()
{
   listTooltip->clear();
   delete listTooltip;
}


void KTooltipLineEdit::SetTooltip( QList<TooltipItem> aItems ){
   listTooltip->clear();
   int iCount = aItems.length();

   for( int i = 0; i < iCount; i++ ){
      QListWidgetItem *pItem = new QListWidgetItem( aItems[i].strText, listTooltip );
      pItem->setData( Qt::ToolTipRole, QString( "%1" ).arg( aItems[i].id ) );

      listTooltip->addItem( pItem );
   }

   iSelectedRow = -1;
   ShowTooltip();
}

int KTooltipLineEdit::ItemsCount(){
   return listTooltip->count();
}



void KTooltipLineEdit::focusInEvent( QFocusEvent *evt ){
   if( evt->gotFocus() ){
      emit KFocusIn();
      ShowTooltip();
   }

   QLineEdit::focusInEvent( evt );
}

void KTooltipLineEdit::focusOutEvent( QFocusEvent *evt ){
   if( evt->lostFocus() ){
      emit KFocusOut();
      HideTooltip();
   }

   QLineEdit::focusOutEvent( evt );
}

void KTooltipLineEdit::mousePressEvent( QMouseEvent *evt ){
   ShowTooltip();

   QLineEdit::mousePressEvent( evt );
}

void KTooltipLineEdit::keyPressEvent( QKeyEvent * evt ){
   if( Qt::Key_Down == evt->key() )
      KeyDown();
   if( Qt::Key_Up == evt->key() )
      KeyUp();

   if( Qt::Key_Return == evt->key() || Qt::Key_Enter == evt->key() ){
      evt->accept();
      FinishSelection();
      return;
   }
   if( Qt::Key_Escape == evt->key() ){
      this->setText( "" );
      HideTooltip();
   }

   QLineEdit::keyPressEvent( evt );
}

bool KTooltipLineEdit::eventFilter( QObject *pObject, QEvent *evt ){
   if( QEvent::MouseButtonPress == evt->type() )
      HideTooltip();

   return false;
}




void KTooltipLineEdit::ShowTooltip(){
   int iHeight = iTooltipHeight;
   if( 0 >= listTooltip->count() )
      return;
   else{
      int iRowHeight = listTooltip->sizeHintForRow( listTooltip->count() - 1 );
      if( iHeight > iRowHeight * listTooltip->count() + 5 )
         iHeight = iRowHeight * listTooltip->count() + 5;
   }

   QPoint ptTopLeft( 0, 0 );
   ptTopLeft = this->mapToGlobal( ptTopLeft );
   ptTopLeft.setY( ptTopLeft.y() + size().height() );

   QDesktopWidget* desktopWidget = QApplication::desktop();
   QRect screenSize = desktopWidget->screenGeometry();

   if( iHeight > screenSize.height() - ptTopLeft.y() - 20 )
      iHeight = screenSize.height() - ptTopLeft.y() - 20;

   listTooltip->setGeometry( ptTopLeft.x(), ptTopLeft.y(), size().width(), iHeight );
   listTooltip->show();
   bTooltipVisible = true;
}

void KTooltipLineEdit::HideTooltip(){
   listTooltip->hide();
   bTooltipVisible = false;
}


void KTooltipLineEdit::KeyDown(){
   if( 0 >= listTooltip->count() )
      return;

   if( listTooltip->count() <= iSelectedRow + 1 )
      iSelectedRow = 0;
   else
      iSelectedRow++;

   listTooltip->setCurrentRow( iSelectedRow );
}

void KTooltipLineEdit::KeyUp(){
   if( 0 >= listTooltip->count() )
      return;

   if( 0 > iSelectedRow - 1 )
      iSelectedRow = listTooltip->count() - 1;
   else
      iSelectedRow--;

   listTooltip->setCurrentRow( iSelectedRow );
}

void KTooltipLineEdit::FinishSelection(){
   if( -1 == iSelectedRow && 1 == listTooltip->count() && bSelectFromList )
      iSelectedRow = 0;

   if( -1 != iSelectedRow ){
      QListWidgetItem *pItem = listTooltip->item( iSelectedRow );
      if( !pItem )
         return;

      QString strText = pItem->text();
      int id = pItem->data( Qt::ToolTipRole ).toInt();

      emit KSelectedText( strText, id );
      this->setText( strText );
      HideTooltip();
   }else if( bSelectFromList )
      this->setText( "" );
   else
      HideTooltip();
}

