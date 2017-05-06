
#include <string>

#include <SBW/SBW.h>
#include <SBW/portableOS.h>
#include <SBW/DataBlockReader.h>

#include "SBWSimulatorData.h"
#include "Simulate3D.h"
#include "edu_kgi_roadRunner_sim.h"
//#include "Jarnac_sim.h"




//using namespace Jarnac;
using namespace edu_kgi_roadRunner;
using namespace std;
using namespace SystemsBiologyWorkbench;
using namespace simulate;

double SBWSimulatorData::getNext(double dTime)
{
	double dResult = dTime;
	if (_bPaused)
	{
		return dResult;
	}
	else
	{
		SBWThread::sleep(Simulate3D::SleepFactor);
		{
			SBWOSMutexLock lock(_mutex);
			dResult = sim::oneStep(dTime, Simulate3D::TimeStep);
		}
		UPDATE_TIME(dResult);
		return dResult;
	}
}
bool SBWSimulatorData::canSimulate()
{
	return _bCanSimulate;
}
vector<string> SBWSimulatorData::getFloatingSpeciesNames() 
{
	vector<string> _oFloatingSpecies;
	string sTemp;
	try
	{
		SBWOSMutexLock lock(_mutex);
		DataBlockReader oFloatingSpecies = sim::getFloatingSpeciesNames();
		while (oFloatingSpecies.getNextType() != TerminateType)
		{
			oFloatingSpecies >> sTemp;
			_oFloatingSpecies.push_back(sTemp);
		}
	}
	catch(...)
	{
	}
	return _oFloatingSpecies;

}
void SBWSimulatorData::setMode(string sMode)
{
	if (sMode == "pause")
	{
		NOTIFY("Paused Simulator", SIMULATE3D_DELAY);
		_bPaused = true;
		_bUpdateOnce = true;
	}
	else if (sMode == "stop")
	{
		_bPaused = true;
		_bUpdateOnce = true;

		Simulate3D::TimeStep = 0.05;		
		Simulate3D::TimeStart = 0.0;
		reset();
		UPDATE_TIME(Simulate3D::TimeStart);
		SimulationThread::setTimeStart(Simulate3D::TimeStart);
		NOTIFY("Stopped and Reset Simulator (Timestep=0.05)", SIMULATE3D_DELAY);
	}
	else if (sMode == "next" || sMode == "fastNext")
	{
		Simulate3D::TimeStep *= 1.2;
		NOTIFY("Time step: " << Simulate3D::TimeStep, SIMULATE3D_DELAY);
	}
	else if (sMode == "back" || sMode == "fastBack")
	{
		Simulate3D::TimeStep *= 0.8;
		NOTIFY("Time step: " << Simulate3D::TimeStep, SIMULATE3D_DELAY);
	}
	else if (sMode == "play")
	{
		NOTIFY("Started / Resumed Simulator", SIMULATE3D_DELAY);
		_bPaused = false;
	}
}
vector<string> SBWSimulatorData::getBoundarySpeciesNames() 
{
	vector<string> _oBoundarySpecies;
	try
	{
		string sTemp;
		SBWOSMutexLock lock(_mutex);
		DataBlockReader oBoundarySpecies = sim::getBoundarySpeciesNames();
		while (oBoundarySpecies.getNextType() != TerminateType)
		{
			oBoundarySpecies >> sTemp;
			_oBoundarySpecies.push_back(sTemp);
		}
	}
	catch(...)
	{
	}
	return _oBoundarySpecies;
}

void SBWSimulatorData::getSpeciesConcentrations()
{
	if (!_bUpdateOnce && _bPaused) return;
	try
	{
		SBWOSMutexLock lock(_mutex);
		vector<double> oFloating = sim::getFloatingSpeciesConcentrations();
		vector<double> oBounday  = sim::getBoundarySpeciesConcentrations();
		vector<double> oRates	 = sim::getReactionRates();
		vector<double> oChange	 = sim::getRatesOfChange();

		double dTemp  = oRates[0];
		for (unsigned int i = 1; i < oRates.size(); i++)
		{
			if (oRates[i] > dTemp) dTemp = oRates[i];
		}

		for (unsigned int i = 0; i < Simulate3D::_species.size(); i++)
		{
			if (Simulate3D::_species[i].IsBoundary)
			{
				if ( Simulate3D::_species[i].Concentration != oBounday[Simulate3D::_species[i].Index])
				{
					Simulate3D::_species[i].Concentration = oBounday[Simulate3D::_species[i].Index];
					Simulate3D::_species[i].Dirty = true; 
				}
			}
			else
			{
				if ( Simulate3D::_species[i].Concentration != oFloating[Simulate3D::_species[i].Index])
				{
					Simulate3D::_species[i].Concentration = oFloating[Simulate3D::_species[i].Index];
					Simulate3D::_species[i].Dirty = true; 
				}
			}
		}
		for (unsigned int i = 0; i < Simulate3D::_reactions.size(); i++)
		{
			Simulate3D::_reactions[i].Rate = oRates[Simulate3D::_reactions[i].Index];
			//Simulate3D::_reactions[i].RateOfChange = oChange[Simulate3D::_reactions[i].Index];
			Simulate3D::_reactions[i].Dirty = true;
		}
		Simulate3D::MaxRate = dTemp;
		if (_bPaused) _bUpdateOnce = false;
	}
	catch(...)
	{
	}
}

double SBWSimulatorData::getSpeciesConcentration(int index, bool bIsBoundary) 
{
	double dResult = -1.0;
	try
	{
		if (bIsBoundary)
		{
			SBWOSMutexLock lock(_mutex);
			dResult	= sim::getBoundarySpeciesByIndex(index);
		}
		else
		{
			SBWOSMutexLock lock(_mutex);
			dResult	= sim::getFloatingSpeciesByIndex(index);
		}
	}
	catch(...)
	{
	}

	return dResult;
}

void SBWSimulatorData::reset()
{
	try
	{
		SBWOSMutexLock lock(_mutex);
		sim::reset();
	}
	catch(...)
	{
	}
}

void SBWSimulatorData::init()
{
	SBWOSMutexLock lock(_mutex);
	_bUpdateOnce = false;
	try
	{
		sim::loadSBML(_sModel);
		_bCanSimulate = true;
	}
	catch(...)
	{
		_bCanSimulate = false;
	}
	_bIsInitialized = true;
}
void SBWSimulatorData::changeValue(simulate::SpeciesCoordinates oSpeciesInfo, double dNewValue)
{
	try
	{
		SBWOSMutexLock lock(_mutex);
		if (oSpeciesInfo.IsBoundary)
		{
			sim::setBoundarySpeciesByIndex(oSpeciesInfo.Index, dNewValue);
		}
		else
		{
			sim::setFloatingSpeciesByIndex(oSpeciesInfo.Index, dNewValue);
		}
	}
	catch(...)
	{
	}
}
void SBWSimulatorData::changeValue(simulate::ParameterInfo oParameterInfo, double dNewValue)
{
	try
	{
		SBWOSMutexLock lock(_mutex);
		sim::setValue(oParameterInfo.ID, dNewValue);
	}
	catch(...)
	{
	}
}


