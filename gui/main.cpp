#include <QApplication>
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <osgDB/ReadFile>
#include "QOsgWidget.h"
#include <osgGA/TrackballManipulator>
#include "mainapp.h"
#include <iostream>

int main(int argc, char *argv[])
{

	// Create application
	QApplication app(argc, argv);
	
	MainApp oWindow;

	// Show widget
	oWindow.showNormal();

	// Main loop
	return app.exec();
}
