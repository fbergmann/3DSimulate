#include "DataProvider.h"
#include "Simulate3D.h"

using namespace std;
using namespace simulate;

void DataProvider::syncSpecies() 
{
	vector<string> oFloatingSpecies = getFloatingSpeciesNames();
	vector<string> oBoundarySpecies = getBoundarySpeciesNames();

	for (unsigned int i = 0; i <  Simulate3D::_species.size(); i++)
	{
		if (Simulate3D::_species[i].IsBoundary)
		{
			for (unsigned int k = 0; k < oBoundarySpecies.size(); k++)
			{
				if (oBoundarySpecies[k] == Simulate3D::_species[i].SpeciesName)
				{
					Simulate3D::_species[i].Index = k;
					Simulate3D::_species[i].Concentration = getSpeciesConcentration(k, true);
					Simulate3D::_species[i].Dirty = true;
				}
			}
		}
		else
		{
			for (unsigned int k = 0; k < oFloatingSpecies.size(); k++)
			{
				if (oFloatingSpecies[k] == Simulate3D::_species[i].SpeciesName)
				{
					Simulate3D::_species[i].Index = k;
					Simulate3D::_species[i].Concentration = getSpeciesConcentration(k, false);
					Simulate3D::_species[i].Dirty = true;
				}
			}
		}
	}
}

