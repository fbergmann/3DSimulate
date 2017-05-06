#include "Configuration.h"
#include "Util.h"

#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include <SBW/SBWApplicationException.h>
#include <SBW/portableOS.h>

using namespace simulate;
using namespace std;


Configuration::Configuration (string sConfigFile) : _nNumSpecies(0)
{
	_sConfigFile = sConfigFile;
	_sConfigPath = Util::getPath(sConfigFile);
	string sLine;
	int nMode = 0; // 0 - nothing , 1 - properties, 2 - species
	ifstream oFile(sConfigFile.c_str());
	if (!oFile.is_open())
		throw new SBWApplicationException("The Configuration file could not be found.", std::string("The Configuration file: '" + sConfigFile + "'could not be found.").c_str());
	try{
		while (!oFile.eof()) 
		{	
			getline(oFile,sLine,'\n');
			sLine = Util::trim(sLine);
			if (isComment(sLine))
			{
				continue;
			}
			if (sLine == "[properties]")
			{
				nMode = 1;
				continue;
			} 
			else if (sLine == "[species]")
			{
				nMode = 2;
				continue;
			}

			if (nMode == 1)
				readProperty(sLine);
			if (nMode == 2)
				readSpecies(sLine);			
		}
		oFile.close();
	} 
	catch(SBWApplicationException *)
	{
		throw;
	}
	catch (...)
	{
		return;
	}	

}

bool Configuration::isComment(string &sLine)
{	
	return (sLine.find("//") != sLine.npos);
}

void Configuration::readSpecies(string &sLine)
{
	stringstream sTemp(sLine);
	string sId; sTemp >> sId;
	double dX = 0, dY = 0, dW = 0, dH = 0, dA = 0, dR = 0, dG = 0, dB = 0;
	sTemp >> dX >> dY >> dW >> dH >> dA >> dR >>dG >>dB ;
	string sKind; sTemp >> sKind;
	double dConcentration = 0; sTemp >> dConcentration;

	SpeciesCoordinates oNew;

	oNew.Color.push_back (dA);
	oNew.Color.push_back (dR);
	oNew.Color.push_back (dG);
	oNew.Color.push_back (dB);

	oNew.Concentration = dConcentration;

	oNew.Dimension.push_back(dW);
	oNew.Dimension.push_back(dH);

	oNew.Dirty = true;

	oNew.Index = -1;

	oNew.IsBoundary = (sKind == "boundary");

	oNew.Position.push_back(dX);
	oNew.Position.push_back(dY);

	oNew.SpeciesName = sId;

	_oSpecies.push_back(oNew);


}

std::string Configuration::getInfo ()
{
	stringstream sResult;
	sResult << "configfile = " << _sConfigFile << endl;
	sResult << "configpath = " << _sConfigPath << endl;
	sResult << "sbmlfile = " << _sSBMLFile << endl;
	sResult << "texture = " << _sTextureFile << endl;
	sResult << "timeseries = " << _sTimeSeriesFile << endl;

	return sResult.str();
}

void Configuration::readProperty(string &sLine)
{
	int nIndex = sLine.find('=');
	string sName = Util::lowerCase( sLine.substr(0,nIndex));
	stringstream sTemp (sLine.substr(nIndex+1));

	if (sName.find("sbmlmodel") != sName.npos)
	{
		_sSBMLFile= Util::getFullName( Util::trim(sLine.substr(nIndex+1)), _sConfigPath );
		return;
	}
	else if (sName.find("texture") != sName.npos)
	{
		_sTextureFile= Util::getFullName( Util::trim(sLine.substr(nIndex+1)), _sConfigPath );
		return;
	}
	else if (sName.find("timeseries") != sName.npos)
	{
		_sTimeSeriesFile= Util::getFullName( Util::trim(sLine.substr(nIndex+1)), _sConfigPath );
		return;
	}
	else if (sName.find("numspecies") != sName.npos)
	{
		sTemp >> _nNumSpecies;
		return;
	}
	else if (sName.find("dimensions") != sName.npos)
	{		
		double dX = 0.0; sTemp >> dX;
		double dY = 0.0; sTemp >> dY;
		_oDimensions.push_back(dX);
		_oDimensions.push_back(dY);
		return;
	}

}

