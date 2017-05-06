#include <osg/ArgumentParser>

#include "Simulate3D.h"
#include "Simulate3DArgumentParser.h"
#include "SBW/ModuleImpl.h"

#include <SBW/SBW.h>

using namespace simulate;
using namespace SystemsBiologyWorkbench;
using namespace std;

int main( int argc, char *argv[] )
{
	try
	{
		// use an ArgumentParser object to manage the program arguments.
		Simulate3DArgumentParser oArgs(argc,argv);
		osg::ArgumentParser arguments(&argc,argv);
		Simulate3D::_sPath = argv[0];

		Simulate3D *oSimulator  = new Simulate3D (oArgs);
		oSimulator->startProducer(arguments,oArgs.useWhite());	
		oSimulator->stop();
		delete (oSimulator);
	}
	catch(SBWException *ex)
	{
		cerr << "Exception occured: " << ex->getMessage() << std::endl 
			<< "Details: " << ex->getDetailedMessage() << std::endl;
	}
	catch(...)
	{
	}
	return (0);
}


