#include "RotateHandler.h"

#include <osg/MatrixTransform>
#include <osg/Matrix>

using namespace osg;
using namespace simulate;

RotateCallback::RotateCallback() : osg::NodeCallback(), enabled_(true)
{
}

void RotateCallback::operator()(osg::Node* node, osg::NodeVisitor *nv)
{
	osg::MatrixTransform *xform = dynamic_cast<osg::MatrixTransform *>(node);
	if (xform && enabled_) {
		double t = nv->getFrameStamp()->getReferenceTime();
		Matrix mTemp;
		mTemp.makeTranslate(-bb.center());
		mTemp.postMult(osg::Matrix::rotate(t, osg::Vec3(0, 0.5, -1)));
		xform->setMatrix(mTemp);
	}
	traverse(node, nv);
}


RotateCallback *RotateCallback::rotate_cb = NULL;
osg::BoundingBox RotateCallback::bb;

