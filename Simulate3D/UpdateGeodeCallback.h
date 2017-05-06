#ifndef	UPDATE_GEODE_CALLBACK_H
#define UPDATE_GEODE_CALLBACK_H

#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/NodeCallback>


namespace simulate
{

	class SpeciesCallback :  public osg::NodeCallback 
	{ 
	private:
		//some values for performing update, for example position 
	public: 
		SpeciesCallback(); 

		virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
	}; 

}
#endif
