#ifndef MAINAPP_H
#define MAINAPP_H

#include <QMainWindow>
#include <osg/ref_ptr>
#include <osg/Node>
#include <osgDB/ReadFile>
#include "QOsgWidget.h"
#include <osgGA/TrackballManipulator>
#include "generatedfiles/ui_mainapp.h"
#define _WINSOCK2API_
#include <Simulate3D.h>

class MainApp : public QMainWindow
{
    Q_OBJECT

public:
    MainApp(QWidget *parent = 0);
    ~MainApp();
	void loadModel(osg::ref_ptr<osg::Node> node);
	void loadFile();

public slots:

	void load();
	void quit();

private:
    Ui::MainAppClass ui;
	QOsgWidget *osgWidget;
	QString _sDir;
	simulate::Simulate3D *_oInstance;

};

#endif // MAINAPP_H
