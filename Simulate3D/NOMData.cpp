
#include "NOMData.h"
#include "Simulate3D.h"
#include "edu_caltech_NOMClipboard_NOM.h"

#include <SBW/SBW.h>
#include <SBW/portableOS.h>

using namespace SystemsBiologyWorkbench;
using namespace edu_caltech_NOMClipboard;
using namespace std;
using namespace simulate;

double NOMData::getNext(double dTime) 
{
	//for (int i = 0; i < 10; i++)
	SBWThread::sleep(Simulate3D::SleepFactor);///10);

	return dTime;
}

void NOMData::init()
{
	NOM::loadSBML(_sModel);
	_bIsInitialized = true;
}
void NOMData::getSpeciesConcentrations()
{
	double dValue;
	for (unsigned int i = 0; i < Simulate3D::_species.size(); i++)
	{
		dValue = NOM::getValue( Simulate3D::_species[i].SpeciesName );
		if ( Simulate3D::_species[i].Concentration != dValue )
		{
			Simulate3D::_species[i].Concentration = dValue ;
			Simulate3D::_species[i].Dirty = true; 
		}
	}
}
double NOMData::getSpeciesConcentration(int index, bool bIsBoundary)
{
	if (bIsBoundary)
	{
		return NOM::getValue(NOM::getNthBoundarySpeciesId(index));
	}
	else
	{
		return NOM::getValue(NOM::getNthFloatingSpeciesId(index));
	}
}

vector<string> NOMData::getFloatingSpeciesNames()
{
	vector<string> _oFloatingSpecies;
	string sTemp;
	DataBlockReader oFloatingSpecies = NOM::getListOfFloatingSpeciesIds();
	while (oFloatingSpecies.getNextType() != TerminateType)
	{
		oFloatingSpecies >> sTemp;
		_oFloatingSpecies.push_back(sTemp);
	}
	return _oFloatingSpecies;
}

bool NOMData::canSimulate()
{
	return false;
}

vector<string> NOMData::getBoundarySpeciesNames()
{
	vector<string> _oBoundarySpecies;
	string sTemp;
	DataBlockReader oBoundarySpecies = NOM::getListOfBoundarySpeciesIds();
	while (oBoundarySpecies.getNextType() != TerminateType)
	{
		oBoundarySpecies >> sTemp;
		_oBoundarySpecies.push_back(sTemp);
	}
	return _oBoundarySpecies;
}
