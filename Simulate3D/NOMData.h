#ifndef NOM_DATA_H
#define NOM_DATA_H

#include <vector>
#include <string>

#include "DataProvider.h"

using namespace std;

namespace simulate
{
	class NOMData : public DataProvider
	{
	protected:

		string _sModel;

		bool _bCanSimulate;

	public:
		NOMData () {}

		NOMData (string sModel) : _sModel(sModel)
		{
			_bIsInitialized=false;
		}

		virtual double getNext(double dTime) ;

		virtual void reset() {};

		virtual void init();

		virtual string getName() { return "NOMData"; }

		virtual double getSpeciesConcentration(int index, bool bIsBoundary);

		virtual void getSpeciesConcentrations();

		virtual vector<string> getFloatingSpeciesNames();

		virtual vector<string> getBoundarySpeciesNames();

		virtual bool canSimulate();
	};
}
#endif
