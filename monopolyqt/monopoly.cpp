//monopoly.cpp
#include <QApplication>

#include "mainwindow.h"
#include <ctime>

int main (int argv, char* argc[]) {
	QApplication app (argv, argc);

	srand(time(0));

	//show main board window;
	MainWindow mw;
	mw.setFixedSize(1855,930);
	mw.show();

	return app.exec();
} 