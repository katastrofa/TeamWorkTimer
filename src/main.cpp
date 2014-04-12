#include "teamworkpmtimer.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TeamWorkPmTimer w;
	w.show();
	return a.exec();
}
