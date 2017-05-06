#include "Util.h"
#include "SBW/portableOS.h"
#include <SBW/SBWApplicationException.h>

using namespace std;
using namespace simulate;
using namespace SystemsBiologyWorkbench;

string Util::upperCase(string s) {
	char* buf = new char[s.length()];
	s.copy(buf, s.length());
	for(unsigned int i = 0; i < s.length(); i++)
		buf[i] = toupper(buf[i]);
	string r(buf, s.length());
	delete buf;
	return r;
}

std::string Util::getPath(std::string sFile)
{
	string sName;
	char cSep = SBWOS::DirectorySeparator();
	if ( sFile.rfind( cSep ) == sFile.npos )
		cSep = '/';
	int nIndex = sFile.rfind( cSep );
	if (nIndex != sFile.npos)
		sName = sFile.substr(0, nIndex);
	else
		sName = sFile;
	return sName;
}

bool Util::fileExists(const char* sFile)
{

	FILE *oFile = fopen(sFile,"r");

	// Do some sanity checking on the value before returning it.

	if (oFile!= NULL)
	{
		fclose(oFile);
		return true;

	}

	return false;

}

string Util::getFullName(string sFile, string sBasePath)
{
	string sResult(sFile);
	if (!Util::fileExists(sResult.c_str()))
	{		
		// doh! ...now try getting the fileName from sFile and 
		// path from _sConfigFile
		char cSep = SBWOS::DirectorySeparator();
		string sName = sBasePath + cSep + Util::getName(sFile);
		if ( fileExists( sName.c_str()) )
		{
			return sName;
		}
		else
		{
			// ok we are nearly out of luck ... lets try one last thing ...
			string sName = sBasePath + cSep + sFile;
			if ( fileExists( sName.c_str()) )
			{
				return sName;
			}
			else
			{
				// i give up
				throw new SBWApplicationException("could not find file " + sFile + " ... even tried " + sName);
			}
		}
	}
	return sResult;
}

double Util::abs(double dValue)
{
	if (dValue < 0)
		return -dValue;
	return dValue;
}

double Util::sign(double dValue)
{
	if (dValue >= 0)
		return 1.0;
	else
		return -1.0;
}

std::string Util::getName(std::string sFile)
{
	string sName;
	char cSep = SBWOS::DirectorySeparator();

	if ( sFile.rfind( cSep ) == sFile.npos )
		cSep = '/';
	int nIndex = sFile.rfind( cSep );
	if (nIndex != sFile.npos)
		sName = sFile.substr(nIndex+1, sFile.npos);
	else
		sName = sFile;
	return sName;
}
// Make a lowercase copy of s:
string Util::lowerCase(string s) 
{
	char* buf = new char[s.length()];
	s.copy(buf, s.length());
	for(unsigned int i = 0; i < s.length(); i++)
		buf[i] = tolower(buf[i]);
	string r(buf, s.length());
	delete buf;
	return r;
}

