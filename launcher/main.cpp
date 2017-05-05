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
	//QString _sFileName;

	//if(argc != 2)
	//{
	//	//std::cout << "Usage: qt4osg <model.osg>" << std::endl;
	//	 _sFileName = QFileDialog::getOpenFileName(
 //                   NULL,
 //                   "Choose a file to open",
 //                   ".",
 //                   "OSG Files (*.osg)");
	//	//return EXIT_FAILURE;
	//} 
	//else
	//{
	//	_sFileName = argv[1];
	//}

	//
	//// Load Model
	//osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(_sFileName.toLocal8Bit().constData());
	//loadedModel.get();
	//if(!loadedModel)
	//{
	//    //std::cout << "Cannot load model" << std::endl;
	//	QMessageBox::critical(NULL,"Model could not be loaded", "The specified model could not be loaded. This application will quit", QMessageBox::Abort,QMessageBox::NoButton);
	//    return EXIT_FAILURE;
	//}

	MainApp oWindow;



//	oWindow.loadModel(loadedModel.get());
	
		
	// Show widget
	oWindow.showNormal();

	
	

	// Main loop
	return app.exec();
}
