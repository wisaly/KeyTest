#include "keytest.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KeyTest w;
	w.show();
	return a.exec();
}
