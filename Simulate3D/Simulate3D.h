#ifndef SIMULATE3D_H
#define SIMULATE3D_H

#include "SimulationThread.h"
#include "DataProvider.h"
#include "SimulateDataTypes.h"

#include <osg/AnimationPath>
#include <osg/BoundingBox>
#include <osg/Node>
#include <osg/Group>
#include <osg/ref_ptr>
#include <osgText/Text>
#include <osg/MatrixTransform>

#include <osgViewer/Viewer>

#include <vector>
#include <string>
#ifdef WIN32
#include <hash_map>
#else
#include <ext/hash_map>
#ifndef STRING_HASH
#define STRING_HASH
namespace __gnu_cxx
{
	template<> struct hash<std::string>
	{
			size_t operator() (std::string __s) const
			{ return hash < const char* > () (__s.c_str()); }
	};
}
#endif
#endif

#define SIMULATE3D_DELAY		10

#define NOTIFY(message,delay)\
	{\
	Simulate3D::_nInfoDelay		= delay;\
	stringstream sTemp; sTemp << message;\
	Simulate3D::_sInfo = sTemp.str();\
	Simulate3D::_bInfoSet = true;\
	}

#define UPDATE_TIME(message)\
	{\
	stringstream sTemp; \
	sTemp.setf(ios::fixed,ios::floatfield);\
	sTemp.precision(4);\
	sTemp << message;\
	Simulate3D::_sCurrent = sTemp.str();\
	Simulate3D::_bCurrentSet = true;\
	}

#define SIMULATE3D_SPACER		0.1F

#define MY_MIN(x,y) 			(x < y ? (x) : (y))
#define MY_MAX(x,y) 			(x > y ? (x) : (y))


using namespace SystemsBiologyWorkbench;

using namespace std;

#ifdef WIN32
using namespace stdext;
#else 
using namespace __gnu_cxx;
#endif

namespace simulate
{

	class Simulate3DArgumentParser;

	class Simulate3D
	{
	private:

		string								_sFileName;
		string								_sCSVFile;
		string								_sTexture;
		static string						_sTempDir;
		bool								_bWhite; 
		static vector<double>				_dimensions;
		vector<string>						_oFloatingSpecies;
		vector<string>						_oBoundarySpecies;
		osg::ref_ptr<osg::MatrixTransform>  _rootnode;

		static vector < osg::ref_ptr< osg::Vec3Array > > _oReactionCurves;


		static SimulationThread				_oTread;

		//osg::ref_ptr<osg::Image>			_oImage;
		string								_sTextureFilename;

		bool IsFloating(string &sName);

		int  getFloatingIndex(string &sName);
		int	 getBoundaryIndex(string &sName);

		void readSpecies();
		void readFile();
		void initCommon();
		void initFromConfig(std::string sConfigFile);
		void initDataProviders();
		void initTexture();
		void initSpecies();

		static osg::ref_ptr< osg::Geometry > drawLine(std::vector<double> oStart, std::vector<double> oEnd, std::vector<double> oBase1, std::vector<double> oBase2,std::vector<double> oColor);
		static osg::ref_ptr< osg::Geometry > drawLine(std::vector<double> oStart, std::vector<double> oEnd, std::vector<double> oColor);
		static osg::Vec2 getNormal (std::vector<double> oStart, std::vector<double> oEnd);


	public:

		static bool							_bInfoSet;
		static bool							_bCurrentSet;
		static bool							_bBufferSet;
		static bool							ScreenSaverMode;
		static bool							MultiScreen;
		static bool							CanSimulate;
		static bool							CreateControls;
		static bool							_bRenderReactions; 

		static int							_nInfoDelay;
		static int							SleepFactor;

		static double						ScaleFactor;
		static double						TimeStart;
		static double						TimeStep;
		static double						TextureSize;
		static double						MaxRate;

		static string						_sSBML;		
		static string						_sPath;
		static string						_sBuffer;
		static string						_sInfo;
		static string						_sCurrent;

		static DataProvider					*_oData;
		static vector<DataProvider*>		DataProviders;

		static vector<SpeciesCoordinates>	_species;
		static vector<ReactionInfo>			_reactions;
        static vector<ParameterInfo>		_parameters;
		static vector < vector < osg::ref_ptr < osg::AnimationPathCallback > > > _oAnimationCallbacks;

		static osg::ref_ptr<osgText::Text>	_oUpdateText;
		static osg::ref_ptr<osgText::Text>	_oInfoText;
		static osg::ref_ptr<osgText::Text>	_oCurrentText;
		static osg::ref_ptr<osg::Node>		_oHelpGroup;
		static osg::ref_ptr<osg::Node>		_oLogoGroup;
		static osg::ref_ptr<osg::Group>		_oControlGroup;
		static osg::ref_ptr<osg::Group>		_oColumns;
		static osg::ref_ptr<osg::Group>		_oReactions;

		static hash_map< string, int >		_oSpeciesMap;
		static hash_map< string, int >		_oReactionMap;

		static void setText(string sText)
		{			
			if (_sBuffer == sText)
				return;
			_sBuffer = sText.c_str();
			_bBufferSet = true;
		}

		static void setInfo(string sText)
		{
			if (sText == _sInfo)
				return;
			_sInfo = sText.c_str();
			_bInfoSet = true;
		}

		static void startThread()
		{
			if (CanSimulate)
			{			
				_oTread.startThread(TimeStart);
			}
		}

		static void continueThread()
		{
			if (CanSimulate)
				_oTread.continueThread();
		}

		static void stop()
		{
			try { _oTread.stop(); } catch(...) {}
		}

		static vector<SpeciesCoordinates> getSpecies()
		{
			return _species;
		}

		static bool switchDataProvider(int nProvider, bool bStopThread = true);

		static int getSpeciesIndex(string &sName)
		{
			int nResult = (int)_oSpeciesMap[sName];
			if (_species.size() == 0 || (nResult == 0 && _species[0].SpeciesName != sName))
				return -1;
			return nResult;
			//if (_oSpeciesMap)
			//for (unsigned int i=0; i < _species.size(); i++)
			//{
			//	if (_species[i].SpeciesName == sName)
			//		return i;
			//}

			//return -1;
		}

		static int getReactionIndex(string &sName)
		{
			int nResult = (int)_oReactionMap[sName];
			if (_reactions.size() == 0 || (nResult == 0 && _reactions[0].ID != sName))
				return -1;
			return nResult;

			//return (int) _oReactionMap[sName];
			//for (unsigned int i=0; i < _reactions.size(); i++)
			//{
			//	if (_reactions[i].ID == sName)
			//		return i;
			//}

			//return -1;
		}

		static string getSpeciesString(string sName)
		{
			for (unsigned int i=0; i < _species.size(); i++)
			{
				if (_species[i].SpeciesName == sName)
				{
					SpeciesCoordinates oCoord = _species[i];
					if (oCoord.SpeciesName != "NONE")
					{
						stringstream sStream;
						sStream.setf(ios::fixed,ios::floatfield);
						sStream.precision(7);
						sStream << "Name:          " << oCoord.SpeciesName << "\n"
							<< "Concentration: " << oCoord.Concentration << "\n" 
							<< "Type:         ";
						if (oCoord.IsBoundary)
							sStream << " Boundary\0";
						else
							sStream << " Floating\0";

						sStream.flush();
						return sStream.str();
					}
					else
					{
						return "" ;
					}
				}
			}
			return "";
		}
		static string getReactionString(string sName)
		{
			for (unsigned int i=0; i < _reactions.size(); i++)
			{
				ReactionInfo oInfo = _reactions[i];
				if (oInfo.ID == sName)
				{					
					stringstream sStream;
					sStream.setf(ios::fixed,ios::floatfield);
					sStream.precision(7);
					sStream 
						<< "Name:           " << oInfo.ID << "\n"
						<< "ReactionRate:   " << oInfo.Rate << "\0"; 
					//<< "Rate of Change: " << oInfo.RateOfChange << "\0";

					sStream.flush();
					return sStream.str();
				}
			}
			return "";
		}
		static SpeciesCoordinates getSpecies(string &sName)
		{
			for (unsigned int i=0; i < _species.size(); i++)
			{
				if (_species[i].SpeciesName == sName)
					return _species[i];
			}
			SpeciesCoordinates oCoord;
			oCoord.SpeciesName = "NONE";
			return oCoord;
		}

		static SpeciesCoordinates getSpecies(int nIndex)
		{
			return _species[nIndex];
		}

		static void setSpecies(int nIndex, SpeciesCoordinates oCoords)
		{
			_species[nIndex] = oCoords;
		}

		static void updateSpecies();

		static void setDirty();

		/**
		* Initializes the simulator for the given sbml model. 
		* the model will be read ... loaded into the simulator 
		* and the layout will be extracted.
		* \param sFileName The SBML (level 1 or 2 file to be read. 
		*				    Note this file has to be with absolute path. 
		*/

		Simulate3D									(string sConfigFile); 
		Simulate3D									(string sFileName, string sTexture, string sCSVFile = "");
		Simulate3D									(Simulate3DArgumentParser& oArguments);
		~Simulate3D();

		void initModel								();
		osg::ref_ptr<osg::Node>	 createModel		();
		osg::ref_ptr<osg::Group> createColumns		();
		osg::ref_ptr<osg::Group> createReactions	();

		osg::ref_ptr<osg::Node>  createModelPlane	(osg::BoundingBox bb, const std::string filename);		
		osg::ref_ptr<osg::Node>  createHUD			(osgText::Text* updateText);
		osg::ref_ptr<osg::Node>  createHelp			(osg::BoundingBox bb, const std::string filename, string sName = "");
		osg::ref_ptr<osg::Node>  createInfo			(osgText::Text* infoText);
		osg::ref_ptr<osg::Node>  createCurrent		(osgText::Text* infoText);
		void					 createControls		(osg::Group*	oControl);

		void		startProducer					(osg::ArgumentParser arguments);

		void		startProducer					(osg::ArgumentParser arguments, bool bWhite);

		void		clearLists						();
	};
}
#endif
