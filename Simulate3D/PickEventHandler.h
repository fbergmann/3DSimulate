#ifndef	PICKEVENT_HANDLER_H
#define PICKEVENT_HANDLER_H

//#include <osgProducer/Viewer>
#include <osgViewer/Viewer>
#include <osgGA/GUIEventAdapter>

#include <string>

namespace simulate
{

	class PickHandler : public osgGA::GUIEventHandler
	{
	public:

		PickHandler(osgViewer::Viewer* viewer) : _viewer(viewer) {}

		~PickHandler();

		virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& us);

		std::string pick(float x, float y);

		void execute(const std::string &picked_name);

		void highlight(const std::string& name);

	protected:

		osgViewer::Viewer* _viewer;
	};
}
#endif
