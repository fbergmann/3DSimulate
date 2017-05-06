#ifndef DATA_PROVIDER_H
#define DATA_PROVIDER_H

#include <vector>
#include <string>
#include "SimulateDataTypes.h"

using namespace std;

namespace simulate
{
	class DataProvider
	{
	protected:
		bool _bIsInitialized;
		bool _bPaused;
	public: 
		virtual ~DataProvider() {}
		virtual double getNext(double dTime) = 0;
		virtual void reset() = 0;
		virtual void init() = 0;
		virtual void syncSpecies(); 
		virtual void setMode(string /*sMode*/) {}
		virtual double getSpeciesConcentration(int index, bool bIsBoundary) = 0;
		virtual void getSpeciesConcentrations() = 0;
		virtual string getName() = 0;
		virtual vector<string> getFloatingSpeciesNames() = 0 ;
		virtual vector<string> getBoundarySpeciesNames() = 0 ;

		virtual bool canSimulate() = 0;

		virtual bool supportsChange() { return false; }
		virtual void changeValue(simulate::SpeciesCoordinates , double ) {}
		virtual void changeValue(simulate::ParameterInfo , double ) {}
	};
}
#endif 
