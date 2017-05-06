#include "PickEventHandler.h"
#include "RotateHandler.h"
#include "Simulate3D.h"

#include <osg/ApplicationUsage>
#include <osgGA/GUIEventAdapter>
//#include <osgProducer/Viewer>
#include <osgViewer/Viewer>

#include <string>

using namespace simulate;

PickHandler::~PickHandler() 
{
}

/**
* This function handles the keyboard / mouse input ...
* \param ea  gui event adapter
* \param osgGA::GUIActionAdapter& action adapter
* \return flag indicating whether the event was handled
*/
bool PickHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter&)
{
	switch(ea.getEventType())
	{
	case(osgGA::GUIEventAdapter::KEYUP):
		switch(ea.getKey())
		{
		case('r'):
			{
				if (Simulate3D::ScreenSaverMode)
					RotateCallback::rotate_cb->enabled_ = !RotateCallback::rotate_cb->enabled_;
				return true;
			}
		case ('c'):
			{
				int nMask = (int)Simulate3D::_oControlGroup->getNodeMask();
				if (nMask == 0)
				{
					Simulate3D::_oControlGroup->setNodeMask(1);
				}
				else
				{
					Simulate3D::_oControlGroup->setNodeMask(0);
				}
				return true;
			}
		case ('h'):
			{
				try
				{
					int nMask = (int)Simulate3D::_oHelpGroup->getNodeMask();

					if (nMask == 0)
					{

						Simulate3D::_oColumns->setNodeMask(0);
						Simulate3D::_oControlGroup->setNodeMask(0);
						Simulate3D::_oHelpGroup->setNodeMask(1);						
					}
					else
					{
						Simulate3D::_oHelpGroup->setNodeMask(0);
						Simulate3D::_oColumns->setNodeMask(1);

						if (Simulate3D::_oData->getName() == "TimeSeriesData")
						{
							Simulate3D::_oControlGroup->setNodeMask(1);
						}
						else
						{
							Simulate3D::_oControlGroup->setNodeMask(0);
						}
					}
				}
				catch(...)
				{
					///
				}
				return true;
			}
		case(osgGA::GUIEventAdapter::KEY_Page_Down):
			{
				Simulate3D::ScaleFactor*=0.8;
				NOTIFY("Scalefactor: " << Simulate3D::ScaleFactor, SIMULATE3D_DELAY);
				Simulate3D::setDirty();
				return true;
			}
		case (osgGA::GUIEventAdapter::KEY_Page_Up):
			{
				Simulate3D::ScaleFactor*=1.2;
				NOTIFY("Scalefactor: " << Simulate3D::ScaleFactor, SIMULATE3D_DELAY);
				Simulate3D::setDirty();
				return true;
			}
		case(osgGA::GUIEventAdapter::KEY_Home):
			{
				Simulate3D::TimeStep *= 1.2;
				NOTIFY("Time step: " << Simulate3D::TimeStep, SIMULATE3D_DELAY);
				return true;
			}
		case(osgGA::GUIEventAdapter::KEY_End):
			{
				Simulate3D::TimeStep *= 0.8;
				NOTIFY("Time step: " << Simulate3D::TimeStep, SIMULATE3D_DELAY);
				return true;
			}
		case((int)'9'):
			{
				if (!Simulate3D::switchDataProvider(1))
				{
					NOTIFY("Switched to provider: " << Simulate3D::_oData->getName(), SIMULATE3D_DELAY * 20);
				}
				return true;
			}
		case((int)'0'):
			{
				if (!Simulate3D::switchDataProvider(0))
				{
					NOTIFY("Switched to provider: " << Simulate3D::_oData->getName(), SIMULATE3D_DELAY * 20);
				}
				return true;
			}
		case((int)'.'):
			{
				Simulate3D::SleepFactor *= 2;
				if (Simulate3D::SleepFactor > 3600)
					Simulate3D::SleepFactor = 3600;

				NOTIFY("Sleep: " << Simulate3D::SleepFactor, SIMULATE3D_DELAY);

				return true;
			}
		case((int)','):
			{
				Simulate3D::SleepFactor = Simulate3D::SleepFactor/2;
				if (Simulate3D::SleepFactor < 1)
					Simulate3D::SleepFactor = 1;

				NOTIFY("Sleep: " << Simulate3D::SleepFactor, SIMULATE3D_DELAY);

				return true;
			}
		case(osgGA::GUIEventAdapter::KEY_Insert):
			{
				Simulate3D::ScaleFactor		= 1.0;
				Simulate3D::TimeStep		= 0.05;

				NOTIFY("reset Time step: " << Simulate3D::TimeStep << " and Scalefactor: " << Simulate3D::ScaleFactor, SIMULATE3D_DELAY);

				Simulate3D::setDirty();
				return true;
			}
		case(osgGA::GUIEventAdapter::KEY_Delete):
			if (Simulate3D::CanSimulate)
			{

				try
				{				
					Simulate3D::stop();
					Simulate3D::TimeStart = 0.0;
					Simulate3D::_oData->reset();					
					Simulate3D::startThread();
				}
				catch(...)
				{
					try
					{
						Simulate3D::stop();
						Simulate3D::TimeStart = 0.0;											
						Simulate3D::_oData->init();
						Simulate3D::_oData->reset();
						Simulate3D::startThread();
					}
					catch(...)
					{
					}
				}

				NOTIFY("Simulator reset", SIMULATE3D_DELAY);

			}
		default:
			return false;
		}
	case(osgGA::GUIEventAdapter::FRAME):
	case(osgGA::GUIEventAdapter::MOVE):
		{
			std::string picked_name = pick(ea.getX(),ea.getY());
			highlight(picked_name);
			if (!picked_name.empty())
			{
				if (ea.getButtonMask() == 1) // leftmouse pressed
				{
					execute(picked_name);
				}
			}
			return false;
		}
	case(osgGA::GUIEventAdapter::PUSH):
		{
			std::string picked_name = pick(ea.getX(),ea.getY());			
			if (!picked_name.empty())
			{

				execute(picked_name);				
				return true;
			}
#ifndef WIN32	// start hack
			else
			{
				if (Simulate3D::CreateControls)
				{
					// bloody linux hack ... as the damn buttons don't work let's force it
					float dWidth = 305.0f/2.5;
					float dHeight = 203.0f/2.5;
					double x = ((ea.getX()+1.0f)/2)*(1280);
					double y = 0.0;
					if (ea.getMouseYOrientation()==osgGA::GUIEventAdapter::Y_INCREASING_UPWARDS)
					{
						y = ((ea.getY()+1.0f)/2)*(1024);
					}
					else
					{
						y = ((ea.getY()+1.0f)/(-2))*(1024);
					}

					if ((x >= 0 && x <= dWidth/2.0) && (y >= 0 && y <=dHeight/2))
					{
						execute("fastBack");				
						return true;

					} 
					else if ((x >= dWidth/2.0 && x <= dWidth) && (y >= 0 && y <=dHeight/2))
					{
						execute("back");				
						return true;		
					}
					else if ((x >= dWidth && x <= dWidth*1.5) && (y >= 0 && y <=dHeight/2))
					{
						execute("play");				
						return true;		
					}
					else if ((x >= dWidth*1.5 && x <= dWidth*2.0) && (y >= 0 && y <=dHeight/2))
					{
						execute("pause");				
						return true;		
					}
					else if ((x >= dWidth*2.0 && x <= dWidth*2.5) && (y >= 0 && y <=dHeight/2))
					{
						execute("next");				
						return true;		
					}
					else if ((x >= dWidth*2.5 && x <= dWidth*3.0) && (y >= 0 && y <=dHeight/2))
					{
						execute("fastNext");				
						return true;		
					}
					else if ((x >= dWidth*3.0 && x <= dWidth*3.5) && (y >= 0 && y <=dHeight/2))
					{
						execute("stop");				
						return true;		
					}
				}
			}

#endif		// end hack
			return false;
		}
	default:
		return false;
	}
}


/**
* This function tests whether a named element exists at the given normalized coordinates. 
* If so the name of the first object picked will be returned. 
*
* \param x normalized x coordinate
* \param y normalized y coordinate
* 
* \return name of the first picked element
*/
std::string PickHandler::pick(float x, float y)
{
	std::string sResult = "";
	 osgUtil::LineSegmentIntersector::Intersections intersections;
	if (_viewer->computeIntersections(x,y,intersections))
    {
        for(osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
            hitr != intersections.end();
            ++hitr)
        {
			if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
			{
				sResult = hitr->nodePath.back()->getName();
				return sResult;				
			}
		}
	}
			
//	osgUtil::IntersectVisitor::HitList hlist;	
//	if (_viewer->computeIntersections(x, y, hlist))
//	{
//		for(osgUtil::IntersectVisitor::HitList::iterator hitr=(hlist).begin();
//			hitr!=(hlist).end();
//			++hitr)
//		{
//			if (hitr->_geode.valid() && !hitr->_geode->getName().empty()) 
//			{
//				sResult = hitr->_geode->getName();
//				return sResult;				
//			}
//			//			else if (hitr->_drawable.valid())
//			//			{
//			//				sResult = hitr->_drawable->getName();
//			//				break;
//			//			}
//		}
//	}
	return sResult;
}

void PickHandler::highlight(const std::string& name)
{

	if (name.empty()) 
	{
		Simulate3D::setText("");
		return;
	}
	else 
	{
		string sTemp = Simulate3D::getSpeciesString(name);
		if (sTemp.empty())
		{
			if (Simulate3D::_bRenderReactions) sTemp = Simulate3D::getReactionString(name);
			if (sTemp.empty())
				Simulate3D::setText(name);
			else
				Simulate3D::setText(sTemp);
		}
		else
			Simulate3D::setText(sTemp);
		return;
	}
}

void PickHandler::execute(const std::string &picked_name)
{
	if (!picked_name.empty())
	{
		Simulate3D::_oData->setMode(picked_name);
	}
}

