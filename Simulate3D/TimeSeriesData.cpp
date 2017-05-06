#include "TimeSeriesData.h"
#include "Simulate3D.h"

#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>

#include <SBW/SBW.h>
#include <SBW/portableOS.h>

#include "Util.h"

using namespace SystemsBiologyWorkbench;
using namespace std;
using namespace simulate;

void TimeSeriesData::readDataFile(string &sFileName)
{
	// read model
	string buffer;	
	ifstream oFile(sFileName.c_str());
	if (!oFile.is_open())
		throw new SBWApplicationException("error reading file", "an error occured while trying to read: '" + sFileName + "'");
	try{
		if (!oFile.eof())
		{
			char cTemp = oFile.peek();
			if (cTemp == '(')
			{
				// we have BIOSPICE TIME SERIES
				// i think for now just transform the bloody thing into CSV
				string sTempFile = sFileName + ".csv";
				ofstream oCSVFile( sTempFile.c_str());
				while (! oFile.eof())
				{
					cTemp = oFile.get();
					if (cTemp == '(' || cTemp == '"'  || cTemp == '\\' )
					{
						continue;
					}
					else if (cTemp == ')')
					{
						oFile.get();
						oCSVFile << endl; 
					}
					else
					{
						oCSVFile << cTemp;
					}
				}
				oCSVFile.close();
				oFile.close();
				readDataFile(sTempFile);				
				return;
			}
			else
			{
				_nTimeCol  = -1;
				_dTimeEnd = -1.0;
				_dDelta = -1.0;
				getline(oFile, buffer);
				parseHeaders(buffer);		// read in CSV Headers
				while (!oFile.eof()) 
				{
					getline(oFile, buffer);
					parseLine(buffer);		// read in data points					
				}
			}
		}
		oFile.close();

		_nCurrentRow = 0;
		_nUpdate = 1;
		_nTotalRows = (int)_oDataColumns.size()-1;
		if (_nTimeCol != -1 && _nTotalRows > 2 )
		{
			_dDelta = _oDataColumns[1][_nTimeCol];
		}
		_bCanSimulate = true;

	} 
	catch (...)
	{
		throw new SBWApplicationException("error reading file", "an error occured while trying to read: '" + sFileName + "'");
	}	
}

void TimeSeriesData::setMode(string sMode)
{

	if (sMode == "play")
	{
		NOTIFY("Playback started (Speed: x" << _nUpdate << ")", SIMULATE3D_DELAY);
		_nUpdate = 1;
		_bPaused = false;
	}
	else if (sMode == "pause")
	{
		NOTIFY("Playback paused", SIMULATE3D_DELAY);
		_nUpdate = 0;
		_bPaused = true;
	}
	else if (sMode == "back")
	{
		if (_bPaused)
		{
			if (_nCurrentRow > 0)
				_nCurrentRow--;
			else
				_nCurrentRow = _nTotalRows;

			if (_nTimeCol != -1)
			{		
				NOTIFY("Seeking Backward: (Position: t=" << _nCurrentRow*_dDelta << ")", SIMULATE3D_DELAY);
			}
			else
			{
				NOTIFY("Seeking Backward...", SIMULATE3D_DELAY);
			}
		}
		else
		{
			if (_nUpdate < 0)
				_nUpdate -=1;
			else _nUpdate = -1;

			NOTIFY("Reversed Playback (Speed x" << _nUpdate<< ")", SIMULATE3D_DELAY);
		}
	}
	else if (sMode == "fastBack")
	{
		if (_bPaused)
		{
			if (_nCurrentRow > 10)
				_nCurrentRow-=10;
			else
				_nCurrentRow = _nTotalRows;
			if (_nTimeCol != -1)
			{		
				NOTIFY("Seeking Backward: (Position: t=" << _nCurrentRow*_dDelta << ")", SIMULATE3D_DELAY);
			}
			else
			{
				NOTIFY("Seeking Backward...", SIMULATE3D_DELAY);
			}
		}
		else
		{
			if (_nUpdate < 0)
				_nUpdate -=10;
			else _nUpdate = -10;
		}


		NOTIFY("Reversed Playback (Speed x" << _nUpdate<< ")", SIMULATE3D_DELAY);
	}
	else if (sMode == "next")
	{
		if (_bPaused)
		{
			if (_nCurrentRow < _nTotalRows-1)
				_nCurrentRow++;
			else
				_nCurrentRow = 0;

			if (_nTimeCol != -1)
			{		
				NOTIFY("Seeking Forward: (Position: t=" << _nCurrentRow*_dDelta << ")", SIMULATE3D_DELAY);
			}
			else
			{
				NOTIFY("Seeking Forward...", SIMULATE3D_DELAY);
			}
		}
		else
		{
			if (_nUpdate > 0)
				_nUpdate +=1;
			else _nUpdate = 1;

			NOTIFY("Faster Playback (Speed x" << _nUpdate<< ")", SIMULATE3D_DELAY);
		}
	}
	else if (sMode == "fastNext")
	{
		if (_bPaused)
		{
			if (_nCurrentRow < _nTotalRows-11)
				_nCurrentRow+=10;
			else
				_nCurrentRow = 0;
			if (_nTimeCol != -1)
			{		
				NOTIFY("Seeking Forward: (Position: t=" << _nCurrentRow*_dDelta << ")", SIMULATE3D_DELAY);
			}
			else
			{
				NOTIFY("Seeking Forward...", SIMULATE3D_DELAY);
			}
		}
		else
		{
			if (_nUpdate > 0)
				_nUpdate +=10;
			else _nUpdate = +10;
			NOTIFY("Faster Playback (Speed x" << _nUpdate<< ")", SIMULATE3D_DELAY);
		}
	}
	else if (sMode == "stop")
	{

		_nUpdate = 0;
		_nCurrentRow = 0;
		_bPaused = true;
		NOTIFY("Stopped Playback", SIMULATE3D_DELAY);

	}

}

double TimeSeriesData::getNext(double dTime)
{
	//for (int i = 0; i < 10; i++)
	SBWThread::sleep(Simulate3D::SleepFactor);

	_nCurrentRow+=_nUpdate;

	if (_nCurrentRow < 0 && _nUpdate < 0)
		_nCurrentRow = _nTotalRows;
	if (_nCurrentRow > _nTotalRows )
		_nCurrentRow = 0;

	if (_nTimeCol != -1)
	{		
		UPDATE_TIME( _nCurrentRow*_dDelta << " / " << _dTimeEnd); 
		return _nCurrentRow*_dDelta;
	}
	else
	{
		UPDATE_TIME( _nCurrentRow << " / " << _nTotalRows); 
		return _nCurrentRow;
	}
}


void TimeSeriesData::reset()
{
	_nCurrentRow = 0;
}


void TimeSeriesData::init()
{
	if (!_bIsInitialized)
	{
		NOMData::init();
	}
}

void TimeSeriesData::getSpeciesConcentrations()
{
	double dValue; int index;
	for (unsigned int i = 0; i < Simulate3D::_species.size(); i++)
	{
		index = Simulate3D::_species[i].Index;
		if (index > 0 && index < (int)_oDataColumns.size() && _nCurrentRow < _nTotalRows)
		{
			dValue = _oDataColumns[_nCurrentRow][index];
			if ( Simulate3D::_species[i].Concentration != dValue )
			{
				Simulate3D::_species[i].Concentration = dValue ;
				Simulate3D::_species[i].Dirty = true; 
			}
		}
		else
		{
			continue;
		}
	}

}
double TimeSeriesData::getSpeciesConcentration(int index, bool bIsBoundary)
{
	if (index > 0 && index < (int)_oDataColumns.size() && _nCurrentRow < _nTotalRows)
		return _oDataColumns[_nCurrentRow][index];
	return -1.0;
}


bool TimeSeriesData::canSimulate()
{
	return _bCanSimulate;
}


void TimeSeriesData::parseLine(string &sLine)
{
	vector<double> oTemp;
	double dTemp = 0.0;
	char* token;
	char seps[] = ",";
	bool bHaveToken = false;
	token = strtok( const_cast<char*>(sLine.c_str()), seps );
	while( token != NULL )
	{		
		stringstream sTemp(token); sTemp >> dTemp;
		oTemp.push_back(dTemp);
		bHaveToken = true;
		token = strtok( NULL, seps );		
	}
	if (bHaveToken)
	{
		if (_nTimeCol != -1)
		{
			try
			{
				_dTimeEnd = oTemp[_nTimeCol];
			}
			catch(...)
			{
			}
		}
		_oDataColumns.push_back(oTemp);
	}
}


void TimeSeriesData::parseHeaders(string &sLine)
{
	char* token;
	char seps[] = ",";
	token = strtok( const_cast<char*>(sLine.c_str()), seps );
	while( token != NULL )
	{		
		_oColumnHeaders.push_back(token);
		if ( Util::lowerCase( string(token) ) == "time")
			_nTimeCol = _oColumnHeaders.size()-1;
		token = strtok( NULL, seps );
	}
}


void TimeSeriesData::syncSpecies() 
{
	for (unsigned int i = 0; i <  Simulate3D::_species.size(); i++)
	{
		Simulate3D::_species[i].Index = -1;
		for (unsigned int k = 0; k < _oColumnHeaders .size(); k++)
		{
			if (_oColumnHeaders[k] == Simulate3D::_species[i].SpeciesName)
			{
				Simulate3D::_species[i].Index = k;
				Simulate3D::_species[i].Concentration = getSpeciesConcentration(k, true);
				Simulate3D::_species[i].Dirty = true;
			}
		}
	}
}
