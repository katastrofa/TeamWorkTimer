#ifndef KTOOLTIPLINEEDIT_H
#define KTOOLTIPLINEEDIT_H

#include <QPoint>
#include <QRect>
#include <QLineEdit>
#include <QList>
#include <QListWidgetItem>
#include <QListWidget>
#include <QFocusEvent>
#include <QDesktopWidget>
#include <QApplication>

class TooltipItem {

public:
   TooltipItem(){}
   TooltipItem( int id, QString strText );
   ~TooltipItem(){}

   QString strText;
   int id;
};

class KTooltipLineEdit : public QLineEdit
{
   Q_OBJECT

public:
   KTooltipLineEdit(QWidget *parent);
   ~KTooltipLineEdit();

   int iTooltipHeight;
   int iSelected;
   int iSelectedRow;
   bool bTooltipVisible;
   bool bSelectFromList;

   void SetTooltip( QList<TooltipItem> aItems );
   int ItemsCount();

signals:
   void KFocusOut();
   void KFocusIn();
   void KSelectedText( QString, int );

protected:
   void focusInEvent( QFocusEvent *evt );
   void focusOutEvent( QFocusEvent *evt );

   void mousePressEvent( QMouseEvent *evt );
   void keyPressEvent( QKeyEvent * evt );

   bool eventFilter( QObject *pObject, QEvent *evt );

private:
   QListWidget *listTooltip;

   void ShowTooltip();
   void HideTooltip();

   void KeyDown();
   void KeyUp();
   void FinishSelection();
};

#endif // KTOOLTIPLINEEDIT_H
