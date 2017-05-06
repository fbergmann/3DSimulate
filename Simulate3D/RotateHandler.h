#ifndef ROTATE_HANDLER_H
#define ROTATE_HANDLER_H

#include <osg/NodeCallback>
#include <osg/NodeVisitor>
#include <osg/Node>
#include <osg/BoundingBox>

namespace simulate
{

	class RotateCallback: public osg::NodeCallback {
	public:
		RotateCallback();

		virtual void operator()(osg::Node* node, osg::NodeVisitor *nv);

		bool enabled_;
		static RotateCallback *rotate_cb;
		static osg::BoundingBox bb;

	};

}

#endif
