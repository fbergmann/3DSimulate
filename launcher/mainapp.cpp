#include "mainapp.h"
#include <QtGui>
#define _WINSOCK2API_
#include <Simulate3D.h>

MainApp::MainApp(QWidget *parent)
    : QMainWindow(parent)
{
	_oInstance = NULL;
	//ui.setupUi(this);
	QMenuBar *oMenuBar = new QMenuBar(this);	
	QMenu *oMenu = oMenuBar->addMenu("F&ile");
	oMenu->addAction("&Load", this, SLOT(load()),QKeySequence("Ctrl+O") );
	oMenu->addSeparator();
	oMenu->addAction("&Exit", this, SLOT(quit()),QKeySequence("Ctrl+X"));

	this->setMenuBar(oMenuBar);
// Create widget with no parent
	// 2nd parameter: force or not continuous update
	QGridLayout oLayout;
	osgWidget = new QOsgWidget(this, true);
	oLayout.addWidget(osgWidget);
	this->setLayout(&oLayout);
	this->setCentralWidget(	osgWidget);


	this->setWindowTitle("QOsgWidget test application");

	// Add one or more camera manipulator
	this->osgWidget->addCameraManipulator(new osgGA::TrackballManipulator);
	// Link scene graph to Widget
}
void MainApp::quit()
{
	QApplication::exit(0);
}
void MainApp::load()
{
	loadFile();
}
void MainApp::loadFile()
{
	QString _sFileName = QFileDialog::getOpenFileName(
                    NULL,
                    "Choose a file to open",
                    NULL,
                    "Config3D Files (*.config3D)");
	if (!_sFileName.isEmpty())
	{
		_oInstance = new simulate::Simulate3D(_sFileName.toLocal8Bit().constData());
		
		osg::ref_ptr<osg::Node> loadedModel = _oInstance->createModel();
		//loadedModel.get();
		if(!loadedModel)
		{
			//std::cout << "Cannot load model" << std::endl;
			QMessageBox::critical(NULL,"Model could not be loaded", "The specified model could not be loaded. This application will quit", QMessageBox::Abort,QMessageBox::NoButton);
			QApplication::exit(0);
		}
		else
		{
			loadModel(loadedModel);
		}
	}

}
void MainApp::loadModel(osg::ref_ptr<osg::Node> loadedModel)
{
	
	osgWidget->replaceSceneData(loadedModel.get());
}
MainApp::~MainApp()
{

}
