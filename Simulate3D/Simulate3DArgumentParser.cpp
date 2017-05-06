#include "Simulate3DArgumentParser.h"
#include "Simulate3D.h"

#include <SBW/SBWApplicationException.h>
#include <SBW/portableOS.h>

#include <time.h>
#include <stdio.h>
#include <sstream>

#ifdef WIN32
#include <io.h>
void GetConfig();		
#endif

using namespace simulate;
using namespace SystemsBiologyWorkbench;
using namespace std;


int		nScale;
int		nSleep;
double	dStep;
std::string fileName;

Simulate3DArgumentParser::Simulate3DArgumentParser(int argc, char*argv[])
{
	bool bScreenSaver = false;
	bool bPreview = false;
	bool bConfigure = false;	
	_bRenderReactions = false;
	_bUseWhite = false;
	
	srand( (unsigned)time( NULL ) );
	rand();
	
	for (int i = 1; i < argc; i++)
	{
		string sParameter(argv[i]);
		if ((sParameter == "--config" || sParameter == "-C") && i < argc)
		{
			_sConfigFile = argv[i+1];
			i++;
		}
		else if ((sParameter == "--model" || sParameter == "-m") && i < argc)
		{
			_sModelFile = argv[i+1];
			i++;
		}
		else if ((sParameter == "--scale" || sParameter == "-s") && i < argc)
		{
			Simulate3D::ScaleFactor =  atof (argv[i+1]);
			i++;
		}
		else if ((sParameter == "--start" || sParameter == "-t") && i < argc)
		{
			Simulate3D::TimeStart =  atof (argv[i+1]);
			i++;
		}	
		else if ((sParameter == "--step" || sParameter == "-d") && i < argc)
		{
			Simulate3D::TimeStep =  atof (argv[i+1]);
			i++;
		}
		else if ((sParameter == "--delay" || sParameter == "-D") && i < argc)
		{
			Simulate3D::SleepFactor =  atoi (argv[i+1]);
			i++;
		}
		else if ((sParameter == "--size" || sParameter == "-S") && i < argc)
		{
			Simulate3D::TextureSize =  atof (argv[i+1]);
			i++;
		}		
		else if ((sParameter == "--multi" || sParameter == "-ms") && i < argc)
		{
			string sTemp(argv[i+1]);
			if (sTemp == "ON")
			{
				Simulate3D::MultiScreen = true;
			}
			i++;
		}
		else if ((sParameter == "--texture" || sParameter == "-f") && i < argc)
		{
			_sTextureFile = string(argv[i+1]);
			i++;
		}
		else if ((sParameter == "--data" || sParameter == "-l") && i < argc)
		{
			_sDataFile = string(argv[i+1]);
			i++;
		}
		else if (sParameter == "--white" || sParameter == "-w") 
		{
			_bUseWhite = true;
		}
		else if (sParameter == "--reactions" || sParameter == "-rr") 
		{
			_bRenderReactions = true;
		}
		else if (sParameter == "--help" || sParameter == "-h") 
		{
			cout << Simulate3DArgumentParser::getUsage(argv[0]);
			//return 0;
		}
#ifdef WIN32
		
		else if (sParameter.find("/c") != sParameter.npos)
		{
			//			cout << "configure mode" << endl;
			bConfigure = true;
		}
		else if (sParameter.find("/s") != sParameter.npos)
		{
			//			cout << "fullscreen mode" << endl;
			bScreenSaver = true;
		}		
		else if (sParameter.find("/p") != sParameter.npos)
		{
			//			cout << "preview mode" << endl;
			bPreview = true;
		}		
		//		cout << "argv: " << argv[i] << endl;
		
#endif
	}
	
#ifdef WIN32
	
	if (bPreview)
	{
		// screen saver preview not supported;
		exit(0);
	}
	if (bConfigure)
	{
		SystemsBiologyWorkbench::SBWOS::startProcess("SimScreenSaverDLG.exe");
		exit(0);
	}
	
	if (bScreenSaver)
	{
		GetConfig();
		_sModelFile = fileName;
		Simulate3D::ScaleFactor =  nScale;
		Simulate3D::TimeStep =  dStep;
		Simulate3D::SleepFactor = nSleep;
		Simulate3D::ScreenSaverMode = true;
		Simulate3D::MultiScreen = true;
	}
#endif
	
	if (_sModelFile == "" && _sConfigFile == "")
	{
		throw new SBWApplicationException("No model file given ... use -m or --model to specify model to use.", Simulate3DArgumentParser::getUsage(argv[0]));
	}
	
}

#ifdef WIN32
void GetConfig()
{
	
	HKEY hKey;
	
	if (RegOpenKeyEx( HKEY_CURRENT_USER,
					 "Software\\Simulate3DSaver", //lpctstr
					 0,			//reserved
					 KEY_QUERY_VALUE,
					 &hKey) == ERROR_SUCCESS)	
	{
		
		DWORD dwType = REG_SZ;
		DWORD dwSize = 512;
		BYTE arRegData[512];
		
		std::string sTemp;
		
		if (ERROR_SUCCESS == RegQueryValueEx(hKey, "random", NULL, &dwType, arRegData, &dwSize)
			&& dwType == REG_SZ)
		{
			sTemp = (LPCTSTR) arRegData;				
		}
		
		dwSize = 512;
		if (ERROR_SUCCESS == RegQueryValueEx(hKey, "file", NULL, &dwType, arRegData, &dwSize)
			&& dwType == REG_SZ)
		{
			fileName = (LPCTSTR) arRegData;
			if (sTemp == "True")
			{
				std::vector<std::string> oFiles;
				// doh ... now we have to find a file ...
				struct _finddata_t c_file;
				long hFile;
				
				/* Find first SBML model */
				if( (hFile = _findfirst( (fileName + "\\*.xml").c_str(), &c_file )) == -1L )
					fileName = "";
				else
				{
					oFiles.push_back(c_file.name);
					/* Find the rest of the SBML files */
					while( _findnext( hFile, &c_file ) == 0 )
					{
						oFiles.push_back(c_file.name);						
					}
					_findclose( hFile );
					
					int nPos = ((double)rand()/(double)RAND_MAX) * oFiles.size()-1;
					fileName += "\\" + oFiles[nPos];
					
				}
				
			}
		}
		
		dwSize = 512;
		if (ERROR_SUCCESS == RegQueryValueEx(hKey, "delay", NULL, &dwType, arRegData, &dwSize)
			&& dwType == REG_SZ)
		{
			sTemp = (LPCTSTR) arRegData;
			stringstream sStream(sTemp);
			sStream >> nSleep;
			
		}
		
		dwSize = 512;
		if (ERROR_SUCCESS == RegQueryValueEx(hKey, "scale", NULL, &dwType, arRegData, &dwSize)
			&& dwType == REG_SZ)
		{
			sTemp = (LPCTSTR) arRegData;
			stringstream sStream(sTemp);
			sStream >> nScale;
			
		}
		
		dwSize = 512;
		if (ERROR_SUCCESS == RegQueryValueEx(hKey, "step", NULL, &dwType, arRegData, &dwSize)
			&& dwType == REG_SZ)
		{
			sTemp = (LPCTSTR) arRegData;
			stringstream sStream(sTemp);
			sStream >> dStep;
			
		}
		
		//Finished with key
		RegCloseKey(hKey);
	}
}
#endif

std::string Simulate3DArgumentParser::getUsage(const char* argv0)
{
	stringstream stream;
	
	stream << endl << "Simulate3D: Visualizes continuous Timecourse simulations of SBML models";
	stream << endl << "Author:     Frank Bergmann";
	stream << endl << "URL:        http://public.kgi.edu/~fbergman" << endl;
	stream << endl << "usage: " << argv0 << endl;
	stream << endl <<"\t --config      | -C\t Read values from Configuration file";
	stream << endl <<"\t --model       | -m\t SBML file";
	stream << endl <<"\t --scale       | -s\t initial Scale factor";
	stream << endl <<"\t --start       | -t\t time start";
	stream << endl <<"\t --step        | -d\t initial step size";
	stream << endl <<"\t --delay       | -D\t initial delay";
	stream << endl <<"\t --size        | -S\t texture size";
	stream << endl <<"\t --multi       | -ms\t toggle multiscreen usage, value ON/OFF";
	stream << endl <<"\t --texture     | -t\t texture file";
	stream << endl <<"\t --data        | -l\t CSV / BioSPICE timeseries file to load";
	stream << endl <<"\t --white       | -w\t Use white background" << endl << endl;
	stream << endl <<"\t --reactions   | -rr\t Render Reactions" << endl << endl;
	
	return stream.str();
	
}


