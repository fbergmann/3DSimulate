#ifndef SBW_SIMULATOR_DATA_H
#define SBW_SIMULATOR_DATA_H

#include <string>

#include <SBW/DataBlockReader.h>
#include <SBW/portableOS.h>


#include "DataProvider.h"
#include "edu_kgi_roadRunner_sim.h"
//#include "Jarnac_sim.h"

//using namespace Jarnac;
using namespace edu_kgi_roadRunner;
using namespace std;
using namespace SystemsBiologyWorkbench;

namespace simulate
{
	class SBWSimulatorData : public DataProvider
	{
	private:

		string _sModel;

		bool _bCanSimulate;
		bool _bUpdateOnce;

		SBWOSMutex _mutex;


	public:

		SBWSimulatorData (string sModel) : _sModel(sModel), _mutex("SBWSimulatorDataMutex")
		{
			_bIsInitialized=false;
			_bPaused = false;
		}

		virtual double getNext(double dTime);

		virtual string getName() { return "SBWSimulatorData"; }

		virtual vector<string> getFloatingSpeciesNames();

		virtual vector<string> getBoundarySpeciesNames();

		virtual void setMode(string sMode);

		virtual double getSpeciesConcentration(int index, bool bIsBoundary);

		virtual void getSpeciesConcentrations();

		virtual void reset();

		virtual void init();

		virtual bool canSimulate();

		virtual bool supportsChange() { return true; }
		virtual void changeValue(simulate::SpeciesCoordinates oSpeciesInfo, double dNewValue);
		virtual void changeValue(simulate::ParameterInfo oParameterInfo, double dNewValue);

	};
}
#endif
