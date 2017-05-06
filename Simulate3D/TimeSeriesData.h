#ifndef TIME_SERIES_DATA_H
#define TIME_SERIES_DATA_H

#include <vector>
#include <string>

#include "NOMData.h"

using namespace std;

namespace simulate
{
	class TimeSeriesData : public NOMData
	{

	public:

		TimeSeriesData()
		{
			_bIsInitialized = true;
			_bPaused = false;
		}
		TimeSeriesData (string sModel) : NOMData(sModel)
		{
			_bIsInitialized=false;
			_bPaused = false;
		}

		virtual void setMode(string sMode);

		void readDataFile(string &sFileName);

		virtual double getNext(double dTime);

		virtual void reset();

		virtual void init();

		virtual double getSpeciesConcentration(int index, bool bIsBoundary);

		virtual void getSpeciesConcentrations();


		virtual bool canSimulate();

		virtual void syncSpecies(); 

		virtual string getName() { return "TimeSeriesData"; }
	private:

		void parseLine(string &sLine);

		void parseHeaders(string &sLine);

		vector<string>					_oColumnHeaders;

		vector< vector<double> >		_oDataColumns;

		int								_nCurrentRow;
		int								_nUpdate;

		int								_nTotalRows;

		int								_nTimeCol;
		double							_dTimeEnd;
		double							_dDelta;

	};
}
#endif
