#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Simulate3D.h"

#include <vector>
#include <string>

namespace simulate
{
	class Configuration
	{
	public:
		Configuration (std::string sConfigFile);

		std::string getTextureFile()				{ return _sTextureFile;		} 
		std::string getSBMLFile()					{ return _sSBMLFile;		}
		std::string getTimeSeriesFile()				{ return _sTimeSeriesFile;	}

		int getNumSpecies()							{ return _nNumSpecies;		}

		std::vector<double> getDimensions()			{ return _oDimensions;		}
		std::vector<SpeciesCoordinates> getSpecies() { return _oSpecies;			}

		std::string getInfo ();


	private:

		void readSpecies(std::string &sLine);
		void readProperty(std::string &sLine);
		bool isComment(std::string &sLine);

		std::string _sTextureFile;
		std::string _sSBMLFile;
		std::string _sTimeSeriesFile;
		std::string	_sConfigFile;
		std::string	_sConfigPath;

		std::vector<SpeciesCoordinates> _oSpecies;

		int _nNumSpecies;

		std::vector<double> _oDimensions;

	};
}

#endif
