/***************************************************************************
* QT Widget to pass events to OSG                                         *
*  by Antoine Hue on August 2006, based on:                               *
* - Some early work by Gazihan Alankus    (gazihan@cse.wustl.edu)         *
* - Open Scene Graph examples: osgsimplepage, osgkeyboardmouse            *
* - Open Scene Graph source code of osgProducer::Viewer                   *
***************************************************************************/


#ifndef QOSGWIDGET_H
#define QOSGWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include <osgGA/GUIActionAdapter>
#include <osgGA/EventQueue>
#include <osgGA/EventVisitor>
#include <osgUtil/SceneView>
#include <osg/Timer>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osg/observer_ptr>
#include <osgDB/Registry>
#include <osgUtil/IntersectVisitor>


class QOsgWidget : public QGLWidget, public osgGA::GUIActionAdapter
{
	Q_OBJECT
public:
	typedef std::list< osg::ref_ptr<osgGA::GUIEventHandler> > EventHandlerList;

public:
	///\param forceContinuousUpdate force continuous update, needed or not
	QOsgWidget(QWidget *parent, 
		bool forceContinuousUpdate = true);

	~QOsgWidget();


	void setSceneData( osg::Node *scene );
	void replaceSceneData( osg::Node * scene );
	inline osg::Node *getSceneData() { return _sceneDecorator.get();}

	void requestRedraw();
	void requestContinuousUpdate(bool needed=true);
	void requestWarpPointer(float x,float y);

	unsigned int addCameraManipulator(osgGA::MatrixManipulator* cm);

	EventHandlerList& getEventHandlerList()
	{ return _eventHandlerList;}
	const EventHandlerList& getEventHandlerList() const 
	{ return _eventHandlerList; }

	inline osgUtil::SceneView * getSceneView()
	{return _sceneView.get();}

	inline osg::StateSet* getGlobalStateSet() 
	{return _sceneView->getGlobalStateSet();}

	osgGA::KeySwitchMatrixManipulator* getKeySwitchMatrixManipulator()
	{return _keyswitchManipulator.get();}

	osgGA::EventQueue *getEventQueue()
	{ return _eventQueue.get();}

	void update();


	bool computeIntersections(float x,float y,
		osg::Node* node,
		osgUtil::IntersectVisitor::HitList& hits,
		osg::Node::NodeMask traversalMask);
protected:
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();

	QTimer *getTimer();

	virtual void keyPressEvent(QKeyEvent *e);
	virtual void keyReleaseEvent(QKeyEvent *e);
	virtual void mouseMoveEvent(QMouseEvent *e);
	virtual void mousePressEvent(QMouseEvent *e);
	virtual void mouseReleaseEvent(QMouseEvent *e);
	virtual void wheelEvent ( QWheelEvent * e );
	virtual void moveEvent ( QMoveEvent * event );
private:
	QTimer *_qtimer;	

	osg::ref_ptr<osgGA::EventQueue>    _eventQueue;
	osg::ref_ptr<osgUtil::SceneView>   _sceneView;

	osg::ref_ptr<osg::Group>           _sceneDecorator;

	osg::ref_ptr<osg::FrameStamp>      _frameStamp;

	osg::ref_ptr<osgGA::EventVisitor>  _eventVisitor;
	osg::ref_ptr<osg::NodeVisitor>     _updateVisitor;

	osg::ref_ptr<osgDB::DatabasePager> _databasePager;

	/// property to force continuous update 
	/// whatever the value of _continuousUpdate
	bool _forceContinuousUpdate;
	/// Continuous update needed
	bool _continuousUpdateNeeded;

	static osg::Timer _osgTimer;
	static const osg::Timer_t _initialTick;

	osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> _keyswitchManipulator;
	EventHandlerList _eventHandlerList;

protected:	
	float qtMouseXToOsg(int);
	float qtMouseYToOsg(int);
	osgGA::GUIEventAdapter::KeySymbol qtKeyToOsg(int qtKey);

protected slots:
	void doIdleAnimationFrame();

};

#endif
