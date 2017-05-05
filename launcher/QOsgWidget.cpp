/***************************************************************************
* QT Widget to pass events to OSG                                         *
*  by Antoine Hue on August 2006, based on:                               *
* - Some early work by Gazihan Alankus    (gazihan@cse.wustl.edu)         *
* - Open Scene Graph examples: osgsimplepage, osgkeyboardmouse            *
* - Open Scene Graph source code of osgProducer::Viewer                   *
***************************************************************************/

#include "QOsgWidget.h"

#include <QKeyEvent>
#include <GL/gl.h>
#include <osgGA/GUIEventAdapter>
#include <osgGA/MatrixManipulator>
#include <osg/AlphaFunc>
#include <osgDB/Registry>
#include <osgGA/TrackballManipulator>

#if defined QOSG_DEBUG
# include <iostream>
#endif

osg::Timer QOsgWidget::_osgTimer;
const osg::Timer_t QOsgWidget::_initialTick = QOsgWidget::_osgTimer.tick();

QOsgWidget::QOsgWidget(QWidget *parent, bool forceContinuousUpdate) :
QGLWidget(parent), 
osgGA::GUIActionAdapter(), 
_qtimer(NULL),
_forceContinuousUpdate(forceContinuousUpdate),
_continuousUpdateNeeded(false)
{
	_databasePager = osgDB::Registry::instance()->getOrCreateDatabasePager();

	_sceneView = new osgUtil::SceneView;

	_eventQueue = new osgGA::EventQueue(osgGA::GUIEventAdapter::Y_INCREASING_UPWARDS);
	_eventQueue->setStartTick(_initialTick);

	// add either a headlight or sun light to the scene.
	osg::ref_ptr<osg::LightSource> lightSource = new osg::LightSource;
	_sceneDecorator = lightSource.get();
	_sceneView->setSceneData(_sceneDecorator.get());
	_databasePager->registerPagedLODs(_sceneDecorator.get());

	osg::Light* light = new osg::Light;
	lightSource->setLight(light);
	// 	lightSource->setReferenceFrame(osg::LightSource::ABSOLUTE_RF); // headlight.
	lightSource->setReferenceFrame(osg::LightSource::RELATIVE_RF); // skylight
	lightSource->setLocalStateSetModes(osg::StateAttribute::ON);

	_frameStamp = new osg::FrameStamp;

	_sceneView->setDefaults();
	_sceneView->setFrameStamp(_frameStamp.get());
	_sceneView->getCullVisitor()->setDatabaseRequestHandler(_databasePager.get());

	//global stateset
	osg::StateSet* globalStateset = _sceneView->getGlobalStateSet();
	globalStateset->setGlobalDefaults();
	globalStateset->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);

	// set up an alphafunc by default to speed up blending operations.
	osg::ref_ptr<osg::AlphaFunc> alphafunc = new osg::AlphaFunc;
	alphafunc->setFunction(osg::AlphaFunc::GREATER, 0.0f);
	globalStateset->setAttributeAndModes(alphafunc.get(), osg::StateAttribute::ON);

	// enable lighting by default
	globalStateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);

	_eventVisitor = new osgGA::EventVisitor;
	_eventVisitor->setActionAdapter(this);

	_keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;
	_keyswitchManipulator->setNode(_sceneDecorator.get());
	_eventHandlerList.push_back(_keyswitchManipulator.get());

	getTimer()->start(1000/200); // timer period in ms
}

QOsgWidget::~QOsgWidget()
{
	// clear the database pager so its starts a fresh 
	// on the next update/cull/draw traversals    
	_databasePager->clear();

	// release the GL objects stored in the scene graph.
	_sceneView->releaseAllGLObjects();

	// do a flush to delete all the OpenGL objects that have been deleted 
	// or released from the scene graph.
	_sceneView->flushAllDeletedGLObjects();
}

unsigned int QOsgWidget::addCameraManipulator(osgGA::MatrixManipulator* cm)
{
	if (!cm) return 0xfffff;

	unsigned int num = _keyswitchManipulator->getNumMatrixManipulators();
	_keyswitchManipulator->addNumberedMatrixManipulator(cm);

	return num;
}

void QOsgWidget::initializeGL( )
{
	if(!isValid()){
		return;
	}

	_keyswitchManipulator->setNode(_sceneDecorator.get());

	if (_keyswitchManipulator.valid() && 
		_keyswitchManipulator->getCurrentMatrixManipulator())
	{     
		osgGA::GUIEventAdapter* dummyEvent = new  osgGA::GUIEventAdapter();
		dummyEvent->setEventType(osgGA::GUIEventAdapter::FRAME);
		dummyEvent->setTime(0.0);
		_keyswitchManipulator->home(*dummyEvent,*this);
		_keyswitchManipulator->setNode(_sceneDecorator.get());
	}
}

void QOsgWidget::resizeGL( int w, int h )
{
	if(!isValid())
	{
		return;
	}

	_sceneView->setViewport(0,0,w,h);

	// Set the appropriate aspect ratio on the scene view's projection matrix
	osg::Matrix projection;
	projection.makePerspective(30.0f, w/static_cast<float>(h), 1.0f, 10000.0f);

	_sceneView->setProjectionMatrix(projection);
}

void QOsgWidget::paintGL( )
{
	if(!isValid()){
		return;
	}

	_frameStamp->setFrameNumber(_frameStamp->getFrameNumber()+1);
	_frameStamp->setReferenceTime(_osgTimer.delta_s(_initialTick,
		_osgTimer.tick()));

	_eventQueue->frame(_frameStamp->getReferenceTime());

	if (_eventVisitor.valid())
	{
		_eventVisitor->setTraversalNumber(_frameStamp->getFrameNumber());
	}

	// pass frame stamp to the SceneView so that the update, cull 
	// and draw traversals all use the same FrameStamp
	_sceneView->setFrameStamp(_frameStamp.get());


	_databasePager->signalBeginFrame(_frameStamp.get());
	_databasePager->updateSceneGraph(_frameStamp->getReferenceTime());   

	// do the update traversal the scene graph - such as updating animations
	_sceneView->update();

	// do the cull traversal, collect all objects in the view frustum 
	// into a sorted set of rendering bins
	_sceneView->cull();

	// draw the rendering bins.
	_sceneView->draw();

	_databasePager->signalEndFrame();

	// clean up  and compile gl objects with a specified limit       
	double availableTime = 1000/60; 

	// compile any GL objects that are required.
	_databasePager->compileGLObjects(*(_sceneView->getState()),availableTime);
}

void QOsgWidget::requestRedraw( )
{
#ifdef QOSG_DEBUG
	std::cout << "requestRedraw called" << std::endl;
#endif
	//paintGL(); slowing down refresh!
}

void QOsgWidget::requestContinuousUpdate( bool needed )
{
#if defined QOSG_DEBUG
	std::cout << "requestContinuousUpdate called " << needed << "\n";
#endif
	_continuousUpdateNeeded = needed;
}

void QOsgWidget::requestWarpPointer( float x, float y )
{
#if defined QOSG_DEBUG
	std::cout << "requestWarpPointer called " << x << " " << y << std::endl;
#endif
	// QT Move
	move((int)x, (int)y);
}

void QOsgWidget::setSceneData( osg::Node * scene )
{
	_sceneDecorator->addChild(scene);

	if (_keyswitchManipulator.valid() && 
		_keyswitchManipulator->getCurrentMatrixManipulator())
	{     
		osgGA::GUIEventAdapter* dummyEvent = new  osgGA::GUIEventAdapter();
		dummyEvent->setEventType(osgGA::GUIEventAdapter::FRAME);
		_keyswitchManipulator->home(*dummyEvent,*this);
		_keyswitchManipulator->setNode(_sceneDecorator.get());
	}
}

void QOsgWidget::replaceSceneData( osg::Node * scene )
{
	//_sceneDecorator = new osg::Group();
	_sceneDecorator->addChild(scene);

	if (_keyswitchManipulator.valid() && 
		_keyswitchManipulator->getCurrentMatrixManipulator())
	{     
		osgGA::GUIEventAdapter* dummyEvent = new  osgGA::GUIEventAdapter();
		dummyEvent->setEventType(osgGA::GUIEventAdapter::FRAME);
		_keyswitchManipulator->home(*dummyEvent,*this);
		_keyswitchManipulator->setNode(_sceneDecorator.get());
	}
}


QTimer *QOsgWidget::getTimer()
{
	if(!_qtimer){
		_qtimer = new QTimer(this);
		connect(_qtimer, SIGNAL(timeout()), 
			this, SLOT(doIdleAnimationFrame()));
	}
	return _qtimer;
}

void QOsgWidget::doIdleAnimationFrame( )
{
	//dispatch events
#if QOSG_DEBUG
	std::cout << "QOsgWidget::doIdleAnimationFrame( ) at frame " 
		<< _frameStamp->getFrameNumber() 
		<< "Time=" << _frameStamp->getReferenceTime() << "\n";
#endif 
	update();

	if(_forceContinuousUpdate || _continuousUpdateNeeded)
	{    
		updateGL();
	}
}

void QOsgWidget::update()
{
	// create an event to signal the new frame.
	getEventQueue()->frame(_frameStamp->getReferenceTime());

	// get the event since the last frame.
	osgGA::EventQueue::Events events;
	getEventQueue()->takeEvents(events);

	if (_eventVisitor.valid())
	{
		_eventVisitor->setTraversalNumber(_frameStamp->getFrameNumber());
	}

	// dispatch the events in order of arrival.
	for(osgGA::EventQueue::Events::iterator event_itr=events.begin();
		event_itr!=events.end();
		++event_itr)
	{
		bool handled = false;

		if (_eventVisitor.valid())
		{
			_eventVisitor->reset();
			_eventVisitor->addEvent(event_itr->get());
			getSceneData()->accept(*_eventVisitor);
			if (_eventVisitor->getEventHandled())
				handled = true;
		}

		for(EventHandlerList::iterator handler_itr=_eventHandlerList.begin();
			handler_itr!=_eventHandlerList.end() && !handled;
			++handler_itr)
		{   
			handled = (*handler_itr)->handle(*(*event_itr),*this,0,0);
		}

	}

	if (osgDB::Registry::instance()->getDatabasePager())
	{
		// update the scene graph by remove expired subgraphs 
		// and merge newly loaded subgraphs
		_databasePager->updateSceneGraph(_frameStamp->getReferenceTime());
	}    

	if (_updateVisitor.valid())
	{
		_updateVisitor->setTraversalNumber(_frameStamp->getFrameNumber());

		// update the scene by traversing it 
		// with the the update visitor which will
		// call all node update callbacks and animations.
		getSceneData()->accept(*_updateVisitor);
	}


	// update the main producer camera
	if (osgGA::MatrixManipulator* mm 
		= _keyswitchManipulator->getCurrentMatrixManipulator()) 
	{
		_sceneView->setViewMatrix( mm->getInverseMatrix() );
	}
}


void QOsgWidget::keyPressEvent( QKeyEvent * e )
{
	_eventQueue->keyPress(qtKeyToOsg(e->key()));
}

void QOsgWidget::keyReleaseEvent( QKeyEvent * e )
{
	_eventQueue->keyRelease(qtKeyToOsg(e->key()));
}


void QOsgWidget::mouseMoveEvent( QMouseEvent * e )
{
	_eventQueue->mouseMotion(qtMouseXToOsg(e->x()), qtMouseYToOsg(e->y()));
}


void QOsgWidget::mousePressEvent( QMouseEvent * e )
{
	switch(e->button())
	{
	case Qt::LeftButton:
		_eventQueue->mouseButtonPress(qtMouseXToOsg(e->x()), 
			qtMouseYToOsg(e->y()), 1);
		break;
	case Qt::MidButton:
		_eventQueue->mouseButtonPress(qtMouseXToOsg(e->x()), 
			qtMouseYToOsg(e->y()), 2);
		break;
	case Qt::RightButton:
		_eventQueue->mouseButtonPress(qtMouseXToOsg(e->x()), 
			qtMouseYToOsg(e->y()), 3);
		break;
	default:
		break;
	}
}

void QOsgWidget::mouseReleaseEvent( QMouseEvent * e )
{
	switch(e->button())
	{
	case Qt::LeftButton:
		_eventQueue->mouseButtonRelease(qtMouseXToOsg(e->x()), 
			qtMouseYToOsg(e->y()), 1);
		break;
	case Qt::MidButton:
		_eventQueue->mouseButtonRelease(qtMouseXToOsg(e->x()),
			qtMouseYToOsg(e->y()), 2);
		break;
	case Qt::RightButton:
		_eventQueue->mouseButtonRelease(qtMouseXToOsg(e->x()), 
			qtMouseYToOsg(e->y()), 3);
		break;
	default:
		break;
	}
}

void QOsgWidget::wheelEvent ( QWheelEvent * e )
{
	if (e->delta() > 0)
		_eventQueue->mouseScroll(osgGA::GUIEventAdapter::SCROLL_UP);
	else if(e->delta() < 0)
		_eventQueue->mouseScroll(osgGA::GUIEventAdapter::SCROLL_DOWN);
	else
		_eventQueue->mouseScroll(osgGA::GUIEventAdapter::SCROLL_NONE);
}

void QOsgWidget::moveEvent ( QMoveEvent * event )
{
	_eventQueue->mouseWarp(event->pos().x(),
		event->pos().y());
}

float QOsgWidget::qtMouseXToOsg( int x )
{
	return x / (float)width();
}

float QOsgWidget::qtMouseYToOsg( int y )
{
	return (height() - y) / (float)height();
}

osgGA::GUIEventAdapter::KeySymbol QOsgWidget::qtKeyToOsg(int qtKey)
{
	if(qtKey >= Qt::Key_A && qtKey <= Qt::Key_Z)
		return (osgGA::GUIEventAdapter::KeySymbol)(qtKey-Qt::Key_A + 'a');
	else
		return (osgGA::GUIEventAdapter::KeySymbol)(qtKey);
}

bool QOsgWidget::computeIntersections(float x,float y,
									  osg::Node* node,
									  osgUtil::IntersectVisitor::HitList& hits,
									  osg::Node::NodeMask traversalMask)
{
#if 1 // Work on going to determine the hitlist
	return false;
#else
	float pixel_x,pixel_y;
	if (node && computePixelCoords(x, y, pixel_x, pixel_y))
	{
		osgUtil::SceneView* sv = _sceneView;
		osg::Matrixd proj;
		osg::Matrixd view;
		const osg::Viewport* viewport = 0;
		osg::Node* rootNode = 0; 

		viewport = sv->getViewport();
		proj = sv->getProjectionMatrix();
		view = sv->getViewMatrix();
		rootNode = sv->getSceneData();

		unsigned int numHitsBefore = hits.size();

		osg::NodePathList parentNodePaths = node->getParentalNodePaths(rootNode);
		for(unsigned int i=0;i<parentNodePaths.size();++i)
		{
			osg::NodePath& nodePath = parentNodePaths[i];

			// remove the intersection node from the nodePath as it'll be accounted for
			// in the PickVisitor traversal, so we don't double account for its transform.
			if (!nodePath.empty()) nodePath.pop_back();  

			osg::Matrixd modelview(view);
			// modify the view matrix so that it accounts for this nodePath's accumulated transform
			if (!nodePath.empty()) modelview.preMult(computeLocalToWorld(nodePath));

			osgUtil::PickVisitor pick(viewport, proj, modelview, pixel_x, pixel_y);
			pick.setTraversalMask(traversalMask);
			node->accept(pick);

			// copy all the hits across to the external hits list
			for(osgUtil::PickVisitor::LineSegmentHitListMap::iterator itr 
				= pick.getSegHitList().begin();
				itr != pick.getSegHitList().end();
			++itr)
			{
				hits.insert(hits.end(),itr->second.begin(), itr->second.end());
			} 
		}

		// return true if we now have more hits than before
		return hits.size()>numHitsBefore;
	}
	return false;
#endif
}

/*
osg::NodePath QOsgWidget::getCoordinateSystemNodePath() const
{
osg::NodePath nodePath;
for(ObserveredNodePath::const_iterator itr = _coordinateSystemNodePath.begin();
itr != _coordinateSystemNodePath.end();
++itr)
{
nodePath.push_back(const_cast<osg::Node*>(itr->get()));
}
return nodePath;
}

void Viewer::computeActiveCoordinateSystemNodePath()
{
// now search for CoordinateSystemNode's for which we want to track.
osg::Node* subgraph = getSceneData();

if (subgraph)
{
CollectedCoordinateSystemNodesVisitor ccsnv;
subgraph->accept(ccsnv);

if (!ccsnv._pathToCoordinateSystemNode.empty())
{
setCoordinateSystemNodePath(ccsnv._pathToCoordinateSystemNode);
return;
}
}  
// otherwise no node path found so reset to empty.
setCoordinateSystemNodePath(osg::NodePath());
}
*/
//         void initializeGL()
// {
//             // Set up the rendering context, define display lists etc.:
// 	...
// 			glClearColor(0.0, 0.0, 0.0, 0.0);
// 	glEnable(GL_DEPTH_TEST);
// 	...
// }
// 
//         void resizeGL(int w, int h)
// {
//             // setup viewport, projection etc.:
// 	glViewport(0, 0, (GLint)w, (GLint)h);
// 	...
// 			glFrustum(...);
// 	...
// }
// 
//         void paintGL()
// {
//             // draw the scene:
// 	...
// 			glRotatef(...);
// 	glMaterialfv(...);
// 	glBegin(GL_QUADS);
// 	glVertex3f(...);
// 	glVertex3f(...);
// 	...
// 			glEnd();
// 	...
// }
