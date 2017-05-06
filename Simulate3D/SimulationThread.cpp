#include <iostream>
#include <sstream>

#include "SimulationThread.h"
#include "Simulate3D.h"

#include <SBW/SBW.h>
#include <SBW/portableOS.h>

using namespace SystemsBiologyWorkbench;
using namespace simulate;
using namespace std;

void SimulationThread::setOperational(bool bIsOperational)
{
	operational = bIsOperational;
}
void SimulationThread::continueThread()
{
	if (Simulate3D::CanSimulate)
	{
		operational = true;

		start();
	}
}

void SimulationThread::startThread(double dTimeStart)
{
	if (Simulate3D::CanSimulate)
	{
		_dTimeStart = dTimeStart;
		Simulate3D::_oData->reset();		
		operational = true;

		start();
	}
}
void SimulationThread::stop()
{
	operational = false;
	join();
}
void SimulationThread::run()
{
	sleep(1000);
	if (Simulate3D::CanSimulate)
	{
		try
		{
			while(operational)
			{
				_dTimeStart = Simulate3D::_oData->getNext(_dTimeStart);
				if (_bUpdateSpecies) Simulate3D::updateSpecies();
			}
		}
		catch(SBWException *e)
		{
			stringstream sTemp; 
			sTemp << "An Exception occured during simulation: " << endl << e->getMessage() << endl << e->getDetailedMessage() << endl <<"\0";
			cerr << sTemp.str();
			Simulate3D::setInfo(sTemp.str());
			Simulate3D::_nInfoDelay = SIMULATE3D_DELAY*10;
		}
		catch(...)
		{
		}
	}
	operational = false;
}

void SimulationThread::setTimeStart(double dStartTime)
{
	_dTimeStart = dStartTime;
}

double SimulationThread::_dTimeStart = 0.0;
bool SimulationThread::_bUpdateSpecies = true;
