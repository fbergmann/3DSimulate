#include "UpdateGeodeCallback.h"
#include "Simulate3D.h"
#include "Util.h"

#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/Drawable>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/NodeCallback>
#include <osg/MatrixTransform>

#include <string>

using namespace osg;
using namespace simulate;
using namespace std;


SpeciesCallback::SpeciesCallback()  : osg::NodeCallback() 
{

}

void SpeciesCallback::operator() (osg::Node *node, osg::NodeVisitor *nv)
{
	Geode* geode = dynamic_cast<Geode*>(node); 		
	if( geode!=NULL ) 
	{ 
		std::string sGeodeName = geode->getName();
		if (sGeodeName == "update")
		{
			// update update text
			if (Simulate3D::_bBufferSet)
			{
				try
				{
					Simulate3D::_oUpdateText->setText(Simulate3D::_sBuffer.c_str());
				}
				catch(...)
				{
					///
				}
				Simulate3D::_bBufferSet = false;
			}
		}
		else if (sGeodeName == "info")
		{
			// update info text
			if (Simulate3D::_nInfoDelay > 0)
			{
				Simulate3D::_nInfoDelay-=1;
				if (Simulate3D::_nInfoDelay == 0)
				{
					Simulate3D::_oInfoText->setText("");
				}
			}
			if (Simulate3D::_bInfoSet)
			{
				try
				{
					Simulate3D::_oInfoText->setText(Simulate3D::_sInfo.c_str());
				}
				catch(...)
				{
					///
				}
				Simulate3D::_bInfoSet = false;
			}

		}
		else if (sGeodeName == "current")
		{
			// update current text
			if (Simulate3D::_bCurrentSet)
			{
				try
				{
					Simulate3D::_oCurrentText->setText(Simulate3D::_sCurrent.c_str());
				}
				catch(...)
				{
				}
				Simulate3D::_bCurrentSet = false;
			}
		}		
		else
		{
			int nIndex = Simulate3D::getSpeciesIndex(sGeodeName);
			if (nIndex != -1)
			{
				SpeciesCoordinates oCoord = Simulate3D::getSpecies(nIndex);
				if (oCoord.Dirty)
				{
					double dConcentration = oCoord.Concentration;
					if (dConcentration <= SIMULATE3D_SPACER && dConcentration >= SIMULATE3D_SPACER *-1) 
						dConcentration = SIMULATE3D_SPACER;
					MatrixTransform *parent = (MatrixTransform *)geode->getParent(0);
					Matrix oMatrix;
					oMatrix.makeIdentity();
					Matrix oTemp;
					float scale = dConcentration*Simulate3D::ScaleFactor/2;
					if (dConcentration == SIMULATE3D_SPACER)
						oTemp.makeScale(
						osg::Vec3(1.0f,1.0f,
						1.0f));
					else
						oTemp.makeScale(
						osg::Vec3(1.0f,1.0f,
						MY_MAX(1.0f,MY_MIN(1000,scale))));
					Matrix oTrans;

					float d = Simulate3D::ScaleFactor;
					if (d > 0 && d < 1)
						d = 1.0f;
					float z = dConcentration/d;
					z = MY_MIN(1.0,z);
					if (dConcentration == SIMULATE3D_SPACER)
						oTrans.makeTranslate(osg::Vec3(0.0f,0.0f, 	
						SIMULATE3D_SPACER));
					else if  (oCoord.Concentration > 0)
					{
						oTrans.makeTranslate(osg::Vec3(0.0f,0.0f, 	
							z + SIMULATE3D_SPACER ));
					}
					else
					{
						oTrans.makeTranslate(osg::Vec3(0.0f,0.0f, 	
							z - SIMULATE3D_SPACER ));
					}

					oMatrix.postMult(oTrans);
					oMatrix.preMult(oTemp);					
					parent->setMatrix(oMatrix);
					geode->dirtyBound();
					oCoord.Dirty = false;
					Simulate3D::setSpecies(nIndex, oCoord);
				}
			}
			if (Simulate3D::_bRenderReactions)
			{
				nIndex = Simulate3D::getReactionIndex(sGeodeName);
				if (nIndex != -1 && nIndex < (int)(Simulate3D::_oAnimationCallbacks.size()))
				{

					if (Simulate3D::_reactions[nIndex].Dirty)
					{
						// OK here the plan, if dirty, find the animation path in the list and try to mess with 
						// it to have it execute slower / faster as needed.

						// let's try the rate first ... 
						double dValue =   Simulate3D::_reactions[nIndex].Rate  / Simulate3D::MaxRate;
						if (Simulate3D::MaxRate == 0.0) dValue = 0.0;

						vector < osg::ref_ptr < osg::AnimationPathCallback > > oCallbacks = Simulate3D::_oAnimationCallbacks[nIndex];

						for (unsigned int i = 0; i < oCallbacks.size(); i++)
						{
							osg::ref_ptr < osg::AnimationPathCallback > oPath = oCallbacks[i];						
							if ( Util::abs( oPath->getTimeMultiplier() - dValue ) < 0.05) break;
							oPath->setTimeMultiplier(dValue);
						}

						Simulate3D::_reactions[nIndex].Dirty = false;					
					}


				}
			}
		}
	} 
	traverse(node,nv); 
}

