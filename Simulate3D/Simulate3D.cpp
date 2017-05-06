
#include "Simulate3D.h"
#include "PickEventHandler.h"
#include "RotateHandler.h"
#include "UpdateGeodeCallback.h"
#include "Simulate3DArgumentParser.h"
#include "Configuration.h"
#include "Util.h"

#include "SBWSimulatorData.h"
#include "TimeSeriesData.h"
#include "NOMData.h"

#include <sstream>
#include <fstream>
#include <stdio.h>

// SBW modules
#include "BROKER_BROKER.h"
#include "DrawNetwork_network.h"
#include "SBMLLayoutModule_reader.h"
#include "edu_caltech_NOMClipboard_NOM.h"

#include <osg/Vec2>
#include <osg/Node>
#include <osg/Geode>
#include <osg/Group>
#include <osg/Light>
#include <osg/LightSource>
#include <osg/ref_ptr>
#include <osg/Geometry>
#include <osg/Material>
#include <osg/StateSet>
#include <osg/Texture2D>
#include <osg/LineWidth>
#include <osg/NodeVisitor>
#include <osg/LineSegment>
#include <osg/NodeCallback>
#include <osg/AnimationPath>
#include <osg/ShapeDrawable>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/StateAttribute>
#include <osg/StateSet>


#include <osgGA/GUIEventAdapter>

#include <osgUtil/Optimizer>

#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgDB/ReaderWriter>

#include <osgViewer/Viewer>
#include <osgViewer/ViewerBase>

using namespace std;
using namespace simulate;
using namespace BROKER1;
using namespace DrawNetwork;
using namespace SBMLLayoutModule;
using namespace edu_caltech_NOMClipboard;

#ifdef WIN32
unsigned int getNumberOfScreens()
{
	unsigned int nNumDisplays = 0;

	DISPLAY_DEVICE oDisplayDevice;
	DISPLAY_DEVICE oMonitor;

	DWORD nDevices		= 0; 	
	DWORD nMonitors		= 0;
	ZeroMemory (&oDisplayDevice, sizeof(oDisplayDevice));
	oDisplayDevice.cb	= sizeof(oDisplayDevice);	

	while (EnumDisplayDevices(0, nDevices, &oDisplayDevice, 0))
	{
		// don't count mirroring devices
		if (!(oDisplayDevice.StateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER) )
		{			
			// don't count disabled devices
			if (oDisplayDevice.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP)
			{
				ZeroMemory	(&oMonitor, sizeof(oMonitor));
				nMonitors   = 0;
				oMonitor.cb	= sizeof(oMonitor);

				while (EnumDisplayDevices(oDisplayDevice.DeviceName, nMonitors, &oMonitor, 0))
				{
					if (oMonitor.StateFlags & DISPLAY_DEVICE_ACTIVE )
					{
						// only count active displays
						nNumDisplays ++;
						break;
					}
					nMonitors	++;
				}
			}
		}
		nDevices++;
	}

	// fall back ... somehow detection of horizontal / vertical span does not quite work
	// also it is reasonable to assume that a user has at least one display ... 
	if (nNumDisplays == 0) 
		nNumDisplays = 1;
	return nNumDisplays ;
}
#endif


Simulate3D::Simulate3D (Simulate3DArgumentParser& oArguments)
{
	_bRenderReactions = oArguments.renderReactions();
	if ( oArguments.hasConfigFile() )
	{
		initFromConfig(oArguments.getConfigFile());		
	}
	else
	{
		_bWhite = oArguments.useWhite();
		_sTexture  = oArguments.getTextureFile();
		_sFileName = oArguments.getModelFile();
		_sCSVFile = oArguments.getDataFile();

		initCommon();
		initModel();
	}
}
Simulate3D::Simulate3D(string sConfigFile)
{
	initFromConfig(sConfigFile);
}

/**
* Constructor ... initializes the scene
*
* \param sFileName SBML model file
* \param sTexture Texture file (optional)
* \param sCSVFile CSV Data file (optional)
*
* \return new Simulate3D object
*/
Simulate3D::Simulate3D(string sFileName, string sTexture, string sCSVFile)
{	
	_bWhite = false;
	_sTexture  = sTexture;
	_sFileName = sFileName;
	_sCSVFile = sCSVFile;

	initCommon();
	initModel();
}
void Simulate3D::initFromConfig(std::string sConfigFile)
{
	initCommon();

	Configuration oConfig(sConfigFile);

	_bWhite = false;
	_sTexture = oConfig.getTextureFile();
	_sTextureFilename = oConfig.getTextureFile();
	_sFileName = oConfig.getSBMLFile();

	if (_sTexture == "")
		throw new SBWApplicationException("Texture could not be created, verify your config file");

	if (_sFileName == "")
		cerr << endl << "Warning: could not read SBML file ..." << endl;

	readFile();
	TimeSeriesData *oData = new TimeSeriesData();

	_sCSVFile = oConfig.getTimeSeriesFile();
	if (_sCSVFile == "") 
	{	
		cerr << endl << "Warning: could not read time series file ..." << endl;
	}
	else
	{
		oData->readDataFile(_sCSVFile);
		oData->syncSpecies();
	}

	_dimensions = oConfig.getDimensions();

	_species = oConfig.getSpecies();
	_oSpeciesMap.clear();
	for (unsigned int i = 0; i < _species.size(); i++)
	{
		_oSpeciesMap[_species[i].SpeciesName] = i;
	}

	_oData = oData;

	DataProviders.push_back(oData);
	switchDataProvider(0,false);

}

void Simulate3D::initCommon()
{
	_oInfoText		= new osgText::Text;
	_oCurrentText	= new osgText::Text;
	_oUpdateText	= new osgText::Text;
	_oControlGroup	= new osg::Group;
	_oHelpGroup		= new osg::Group;

	_nInfoDelay = SIMULATE3D_DELAY * 3 ;

#ifdef WIN32
	_sTempDir = getenv("TEMP");
#else
	_sTempDir = "/tmp/";
#endif

	osgDB::Registry::instance()->getDataFilePathList().push_back(_sTempDir  );
	osgDB::Registry::instance()->getDataFilePathList().push_back( Util::getPath( Simulate3D::_sPath ));

#ifdef WIN32
	osgDB::Registry::instance()->getDataFilePathList().push_back("c:\\");
#endif

}
Simulate3D::~Simulate3D()
{
	try
	{
		try
		{
			stop();
		}
		catch(...)
		{
		}
		for (unsigned int i = DataProviders.size() ; i > 0 ; i--)
		{
			DataProvider *oTemp  = DataProviders.back();			
			DataProviders.pop_back();
			free(oTemp);
		}

		for (unsigned int i = _species.size() ; i > 0; i--)
		{
			_species.pop_back();
		}

		for (unsigned int i = _reactions.size() ; i > 0; i--)
		{
			_reactions.pop_back();
		}

	}
	catch(...)
	{
	}
}

/**
* Causes all columns to be re-adjusted
*/
void Simulate3D::setDirty()
{
	for (unsigned int i = 0; i < _species.size(); i++)
	{
		_species[i].Dirty				= true;
	}
}
/**
* Requests new data points from the current DataProvider. If these values differ from the previous values
* the corresponding colums will be readjusted.
*/
void Simulate3D::updateSpecies()
{
	_oData->getSpeciesConcentrations();
}
/**
* Reads in the SBML file ...
* \param sFileName the SBML filename
*/
void Simulate3D::readFile()
{
	// read model
	string buffer;	
	ifstream oFile(_sFileName.c_str());
	if (!oFile.is_open())
		throw new SBWApplicationException("error reading file", "an error occured while trying to read: '" + _sFileName + "'");
	try{
		while (!oFile.eof()) 
		{
			getline(oFile, buffer);
			_sSBML+=buffer;
		}
		oFile.close();
	} catch (...)
	{
		throw new SBWApplicationException("error reading file", "an error occured while trying to read: '" + _sFileName + "'");
	}	

	// validate the SBML and promote local to global parameters
	try
	{
		_sSBML = NOM::getParamPromotedSBML(_sSBML);
	}
	catch(...)
	{
	}

}

/**
* Initializes the available DataProviders
*/
void Simulate3D::initDataProviders()
{
	try
	{			
		if (!_sCSVFile.empty())
		{
			TimeSeriesData *oTS = new TimeSeriesData (_sSBML);
			oTS->readDataFile(_sCSVFile);
			Simulate3D::DataProviders.push_back(oTS);				
		}
		else
		{
			Simulate3D::DataProviders.push_back(new NOMData (_sSBML));
		}
		DataProviders[0]->init();
	}
	catch(...)
	{
	}
	try
	{
		Simulate3D::DataProviders.push_back(new SBWSimulatorData(_sSBML));
		DataProviders[1]->init();
	}
	catch(...)
	{
	}
	try
	{
		Simulate3D::DataProviders.push_back(new NOMData(_sSBML));
		DataProviders[2]->init();
	}
	catch(...)
	{
	}

	if (!_sCSVFile.empty())
		_oData  = DataProviders[0];
	else
		_oData  = DataProviders[2];
	//switchDataProvider(2,false);

}

void Simulate3D::initTexture()
{
	if (_sTexture == "")
	{
		// load into simulator and layout tool
		reader::loadSBML(_sSBML);
		if (!reader::hasLayout())
		{
			cerr << "Model contains neither JD nor SBML Layout Extension Annotations. Try to generate layout." << endl;
			/// ok ... in this case take ana's tool and try and create a layout for it ...
			// turn viewer invisible
			reader::setVisible(false);
			network::doAnalysis(_sSBML);
			_sSBML = network::getSBML();
			reader::loadSBML(_sSBML);
			if (!reader::hasLayout())
			{
				//cerr << "Couldn't generate a layout for the model."<< endl;
				//exit(-1);
				throw new SBWApplicationException("Couldn't generate a layout for the model.");
			}				
		}
		// get dimensions of the layout
		_dimensions = reader::getDimensions();
		try
		{
			unsigned char* array;
			int length = 0;
			double dScale = MY_MIN((double)(TextureSize / _dimensions[0]), (double)(TextureSize / _dimensions[1]));         
			reader::getImage(dScale,length,array);


			_sTextureFilename = _sTempDir + SBWOS::DirectorySeparator() + "texture.jpg";


			// writing the texture
			FILE *texture = fopen( _sTextureFilename.c_str(),"wb+");
			fwrite(array, sizeof(unsigned char) , length-1, texture);
			fflush(texture);
			fclose(texture);

			free(array);
		}
		catch(...)
		{
			//HACK: will fail on OSX ... so let's forget about it for now ...

		}

	}
	else
	{
		_sTextureFilename = _sTexture;
		// get dimensions of the layout
		_dimensions = reader::getDimensions();
	}
}

void Simulate3D::initSpecies()
{
	// read boundary and floating species from simulator 
	// we have to match the id's for later use

	readSpecies();

	_oSpeciesMap.clear();

	// read all positions for species
	for (int i = 0; i < reader::getNumberOfSpeciesGlyphs(); i++)
	{
		DataBlockReader oSpeciesReader = reader::getSpeciesGlyph(i);
		SpeciesCoordinates oSpecies;
		oSpeciesReader >> oSpecies.SpeciesName;
		oSpeciesReader >> oSpecies.SpeciesName;
		oSpeciesReader >> oSpecies.Position;
		oSpeciesReader >> oSpecies.Dimension;
		oSpecies.Color = reader::getSpeciesGlyphColor(i);
		if (IsFloating(oSpecies.SpeciesName))
		{
			oSpecies.IsBoundary		= false;
			oSpecies.Index			= getFloatingIndex(oSpecies.SpeciesName);
			oSpecies.Concentration	= _oData->getSpeciesConcentration(oSpecies.Index, false);			
		}
		else
		{
			oSpecies.IsBoundary		= true;
			oSpecies.Index			= getBoundaryIndex(oSpecies.SpeciesName);
			oSpecies.Concentration	= _oData->getSpeciesConcentration(oSpecies.Index, true);
		}
		oSpecies.BaseConcentration = oSpecies.Concentration;
		oSpecies.Dirty					= true;
		_species.push_back(oSpecies);
		_oSpeciesMap[oSpecies.SpeciesName] = i;

	}


	if (!_sCSVFile.empty())
		switchDataProvider(0,false);
	else
		switchDataProvider(1,false);
}

/**
* Initializes the model, generates a texture and sets up the species objects needed.
*
* \param sFileName the SBML file 
*/
void Simulate3D::initModel()
{
	try
	{
		reader::setVisible(false);

		//read raw SBML
		readFile();

		// initialize DataProviders
		initDataProviders();

		// init base texture
		initTexture();

		// init species
		initSpecies();

	}
	catch(SBWException *e)
	{
		cerr << e->getMessage() << endl << endl << e->getDetailedMessage() << endl;
	}
	catch(...)
	{
	}
}
bool Simulate3D::IsFloating(string &sName)
{
	return getFloatingIndex(sName) != -1;
}

int  Simulate3D::getFloatingIndex(string &sName)
{
	for (unsigned int i=0; i < _oFloatingSpecies.size(); i++)
	{
		if (_oFloatingSpecies[i] == sName)
			return i;
	}
	return -1;
}

int	 Simulate3D::getBoundaryIndex(string &sName)
{
	for (unsigned int i=0; i < _oBoundarySpecies.size(); i++)
	{
		if (_oBoundarySpecies[i] == sName)
			return i;
	}
	return -1;
}

void Simulate3D::readSpecies()
{
	_oFloatingSpecies = _oData->getFloatingSpeciesNames();
	_oBoundarySpecies = _oData->getBoundarySpeciesNames();
}

osg::ref_ptr<osg::Node> Simulate3D::createModelPlane(osg::BoundingBox bb,const std::string filename)
{
	osg::ref_ptr<osg::Group> group = new osg::Group;

	// left hand side of bounding box.
	osg::Vec3 top_left(bb.xMin(),bb.yMax(),bb.zMin());
	osg::Vec3 bottom_left(bb.xMin(),bb.yMin(),bb.zMin());
	osg::Vec3 bottom_right(bb.xMax(),bb.yMin(),bb.zMin());
	osg::Vec3 top_right(bb.xMax(),bb.yMax(),bb.zMin());
	osg::Vec3 center((bb.xMin()+bb.xMax())*0.5f,(bb.yMin()+bb.yMax())*0.5f,bb.zMin());    
	float height = bb.yMax()-bb.yMin();

	// create the geometry for the wall.
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(4);
	(*vertices)[0] = top_left;
	(*vertices)[1] = bottom_left;
	(*vertices)[2] = bottom_right;
	(*vertices)[3] = top_right;
	geom->setVertexArray(vertices.get());

	osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array(4);
	(*texcoords)[0].set(0.0f,1.0f);
	(*texcoords)[1].set(0.0f,0.0f);
	(*texcoords)[2].set(1.0f,0.0f);
	(*texcoords)[3].set(1.0f,1.0f);
	geom->setTexCoordArray(0,texcoords.get());

	osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(1);
	(*normals)[0].set(0.0f,0.0f,1.0f);
	geom->setNormalArray(normals.get());
	geom->setNormalBinding(osg::Geometry::BIND_OVERALL);

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0].set(1.0f,1.0f,1.0f,1.0f);
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);

	geom->addPrimitiveSet(new osg::DrawArrays(GL_QUADS,0,4));

	osg::ref_ptr<osg::Geode> geom_geode = new osg::Geode;
	geom_geode->addDrawable(geom.get());
	group->addChild(geom_geode.get());


	// set up the texture state.    
	osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	texture->setResizeNonPowerOfTwoHint(true);
	texture->setFilter(osg::Texture2D::MIN_FILTER,osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	texture->setFilter(osg::Texture2D::MAG_FILTER,osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	texture->setDataVariance(osg::Object::DYNAMIC); // protect from being optimized away as static state.

	texture->setImage(osgDB::readImageFile(filename));

	texture->setMaxAnisotropy(16.0f);

	osg::StateSet* stateset = geom->getOrCreateStateSet();
	stateset->setTextureAttributeAndModes(0,texture.get(),osg::StateAttribute::ON);

	return group.get();

}

osg::ref_ptr<osg::Group> Simulate3D::createColumns()
{
	osg::ref_ptr<osg::Group> model = new osg::Group;
	for ( unsigned int i = 0; i < _species.size(); i++)
	{
		SpeciesCoordinates oCoord = _species[i];

		osg::ref_ptr<osg::Box> oBox = new osg::Box(
			osg::Vec3(	oCoord.Position[0]+(oCoord.Dimension[0]/2.0f),
			-1.0F*oCoord.Position[1]-(oCoord.Dimension[1]/2.0f),
			0.5f /*oCoord.Concentration*Simulate3D::ScaleFactor + SIMULATE3D_SPACER*/),
			oCoord.Dimension[0],
			oCoord.Dimension[1],
			1.0f /*oCoord.Concentration*Simulate3D::ScaleFactor + SIMULATE3D_SPACER*/);

		osg::ref_ptr<osg::Geode> geodeCube = new osg::Geode();
		geodeCube->setName( oCoord.SpeciesName );		
		osg::ref_ptr<osg::ShapeDrawable> oShape = new osg::ShapeDrawable(oBox.get());		

		oShape->setColor(
			osg::Vec4(
			osg::Vec3(
			oCoord.Color[1], 
			oCoord.Color[2],
			oCoord.Color[3]
			),
				oCoord.Color[0]*0.5f
				)
				);

			geodeCube->addDrawable(oShape.get());		
			geodeCube->setUpdateCallback(new SpeciesCallback());
			osg::ref_ptr<osg::MatrixTransform> matrixTransform = new osg::MatrixTransform();
			matrixTransform->setName( oCoord.SpeciesName );
			matrixTransform->addChild(geodeCube.get());
			model->addChild(matrixTransform.get());	

	}
	osg::ref_ptr<osg::StateSet> stateset = model->getOrCreateStateSet();
	stateset->setMode((osg::StateAttribute::GLMode)GL_LIGHTING,osg::StateAttribute::ON);
	stateset->setMode((osg::StateAttribute::GLMode)GL_BLEND,osg::StateAttribute::ON);
	//stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
	stateset->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	//stateset->setRenderingHint(osg::StateSet::RenderingHint::TRANSPARENT_BIN);
	model->setStateSet(stateset.get());

	return model;
}

osg::ref_ptr<osg::Group> Simulate3D::createReactions()
{
	osg::ref_ptr<osg::Group> reactions = new osg::Group;
	try
	{
		if (_sSBML.empty()) return reactions;
		reader::loadSBML(_sSBML);
		if (!reader::hasLayout()) return reactions;

		_oReactionCurves.clear();
		_reactions.clear();
		_oAnimationCallbacks.clear();

		vector<double> oReactionRates = sim::getReactionRates();
		vector<double> oRatesOfChange = sim::getRatesOfChange();

		vector<string> oRectionNames;

		DataBlockReader oReader = sim::getReactionNames();
		while (oReader.getNextType() != SystemsBiologyWorkbench::TerminateType)
		{	
			string sName; oReader >> sName;
			oRectionNames.push_back(sName);
		}

		int nReactions = reader::getNumberOfReactionGlyphs();

		_oReactionMap.clear();

		for (int i = 0; i < nReactions; i++)
		{
			string sId; string sReference; int nSpeciesReferences;
			DataBlockReader oReader	= reader::getReactionGlyph(i);
			oReader >> sId >> sReference >> nSpeciesReferences;

			vector<double> oInfo	= reader::getReactionGlyphRenderInfoGL(i);

			ReactionInfo oReactionInfo; 
			oReactionInfo.ID = sReference;
			oReactionInfo.Color = oInfo;
			oReactionInfo.LineWidth = oInfo[0];

			for (unsigned int l = 0; l < oRectionNames.size(); l++)
			{
				if (oRectionNames[l] == oReactionInfo.ID)
				{
					oReactionInfo.Index			= l;
					oReactionInfo.Rate			= oReactionRates[l];
					//oReactionInfo.RateOfChange	= oRatesOfChange[l];
					oReactionInfo.Dirty			= true;
				}
			}

			_reactions.push_back(oReactionInfo);
			_oReactionMap[oReactionInfo.ID] = i;

			osg::ref_ptr < osg::Geode >		oGeode		= new osg::Geode();
			osg::ref_ptr < osg::StateSet >	stateset	= new osg::StateSet();
			osg::ref_ptr < osg::LineWidth >	lineWidth	= new osg::LineWidth();

			lineWidth->setWidth(oInfo[0]);

			stateset->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);
			stateset->setMode((osg::StateAttribute::GLMode)GL_LINE_SMOOTH,osg::StateAttribute::ON);
			stateset->setMode((osg::StateAttribute::GLMode)GL_DEPTH_TEST,osg::StateAttribute::OFF);
			stateset->setMode((osg::StateAttribute::GLMode)GL_LIGHTING,osg::StateAttribute::OFF);

			oGeode->setStateSet( stateset.get() );

			oGeode->setName( sReference );
			oGeode->setUpdateCallback( new SpeciesCallback() );

			vector<DataBlockReader> oCurve = reader::getReactionCurve(i);			

			_oReactionCurves.clear();

			for (unsigned int j = 0; j < oCurve.size(); j ++)
			{
				string sType; 
				vector<double> oStart; vector<double> oEnd; 
				vector<double> oBase1; vector<double> oBase2;
				oCurve[j] >> sType;
				if (sType == "LineSegment")
				{	
					oCurve[j] >> oStart >> oEnd;
					oGeode->addDrawable( drawLine( oStart,oEnd,oInfo ).get() );
				}
				else
				{
					oCurve[j] >> oStart >> oEnd >> oBase1 >> oBase2;
					oGeode->addDrawable( drawLine( oStart,oEnd,oBase1,oBase2,oInfo ).get() );
				}
			}

			for (int k = 0; k < nSpeciesReferences; k ++)
			{
				string sRole;
				DataBlockReader oSpeciesReference = reader::getSpeciesReference(i, k);			
				oSpeciesReference >> sRole >> sRole >> sRole >> sRole;
				
				if (sRole != "product" && sRole != "substrate" && sRole != "sidesubstrate" && sRole != "sideproduct")
				continue;

				vector<DataBlockReader> oSpeciesCurve = reader::getSpeciesReferenceCurve(i, k);			
				for (unsigned int j = 0; j < oSpeciesCurve.size(); j ++)
				{

					string sType; 
					vector<double> oStart; vector<double> oEnd; 
					vector<double> oBase1; vector<double> oBase2;
					oSpeciesCurve[j] >> sType;

					if (sType == "LineSegment")
					{	
						oSpeciesCurve[j] >> oStart >> oEnd;
						oGeode->addDrawable( drawLine( oStart,oEnd,oInfo ).get() );
					}
					else
					{
						oSpeciesCurve[j] >> oStart >> oEnd >> oBase1 >> oBase2;
						oGeode->addDrawable( drawLine( oStart,oEnd,oBase1,oBase2,oInfo ).get() );
					}
				}
			}



			// by now all the neccessary data about the reactionCurves is in the buffer, so we now need
			// to extract them from the buffer, form appropriate animationpaths and objects with position-
			// attitudeTransforms ... 

			vector < osg::ref_ptr < osg::AnimationPathCallback > > oAnimCallbacks;

			for (unsigned int k = 0; k < _oReactionCurves.size(); k++)
			{
				osg::ref_ptr < osg::Vec3Array > oVertices = _oReactionCurves[k];

				// first construct the animation path
				osg::ref_ptr < osg::AnimationPath > animationPath = new osg::AnimationPath;
				animationPath -> setLoopMode (osg::AnimationPath::LOOP);
				double time = 0.0;
				double time_delta = 1.0/(double)oVertices->size();

				for (unsigned int j = 0; j < oVertices->size(); j++)
				{
					animationPath->insert( time, osg::AnimationPath::ControlPoint(oVertices->at(j)));
					time += time_delta;
				}

				// next generate an object, giving it a position attitude transform that should move it around

				{

					// first create a sphere					
					osg::ref_ptr<osg::Sphere> oSphere = new osg::Sphere(osg::Vec3(), MY_MAX( oInfo[0]*1.5f, 0.75) );
					osg::ref_ptr<osg::Geode> geodeSphere = new osg::Geode();
					geodeSphere->setName( sReference );		
					osg::ref_ptr<osg::ShapeDrawable> oShape = new osg::ShapeDrawable(oSphere.get());		
					oShape->setColor( osg::Vec4( osg::Vec3(0.5, 0.5, 0.5),0.5));

					osg::ref_ptr<osg::Material> mat = new osg::Material();

					mat->setColorMode	( osg::Material::EMISSION );
					mat->setAmbient		( osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1) );
					mat->setSpecular	( osg::Material::FRONT_AND_BACK, osg::Vec4(1, 1, 1, 1) );
					mat->setEmission	( osg::Material::FRONT_AND_BACK, osg::Vec4(1, 1, 1, 1) );
					mat->setShininess	( osg::Material::FRONT_AND_BACK, 64.0f );

					geodeSphere->getOrCreateStateSet()->setAttributeAndModes(mat.get(),osg::StateAttribute::ON);

					geodeSphere->addDrawable(oShape.get());		

					//// how about adding a light at the position of the sphere, might look ok.
					//osg::ref_ptr< osg::Light > oLight = new osg::Light;
					////oLight->setLightNum(i);
					////oLight->setPosition(osg::Vec3(), 1.0f);
					////oLight->setAmbient(osg::Vec4(0.0f,0.0f,1.0f,1.0f));
					//oLight->setDiffuse(osg::Vec4(0.0f,0.0f,1.0f,1.0f));					
					//oLight->setConstantAttenuation(1.0f/_dimensions[0]/2);
					//oLight->setLinearAttenuation(2.0f/_dimensions[0]);
					//oLight->setQuadraticAttenuation(2.0f/osg::square(_dimensions[0]));					

					//osg::ref_ptr< osg::LightSource > oLightSource = new osg::LightSource;
					//oLightSource->setLight(oLight.get());
					//oLightSource->setLocalStateSetModes(osg::StateAttribute::ON);

					// next create a transform node for sphere
					osg::ref_ptr<osg::MatrixTransform> matrixTransform = new osg::MatrixTransform();
					matrixTransform->setName( sReference );

					//matrixTransform->addChild(oLightSource.get());
					matrixTransform->addChild(geodeSphere.get());

					// finally make our marker move where it should :) 
					osg::ref_ptr < osg::PositionAttitudeTransform > xForm = new osg::PositionAttitudeTransform;
					osg::ref_ptr < osg::AnimationPathCallback >  oCallback = new osg::AnimationPathCallback(animationPath.get(), 0.0, 1.0);
					oAnimCallbacks.push_back( oCallback );
					xForm->setUpdateCallback ( oCallback.get() );
					xForm->addChild(matrixTransform.get());

					reactions->addChild( xForm.get() );	

				}



			}

			_oAnimationCallbacks.push_back ( oAnimCallbacks );
			// finally add the reactionShape

			reactions->addChild(oGeode.get());        

		}
	}
	catch(SBWException *e)
	{
		cerr << "Couldn't generate Lines for reactions. Is SBW installed and working properly?" << endl
			<< "Error message: " << e->getMessage() << endl
			<< "Detailed Error message: " << e->getDetailedMessage() << endl << endl;
	}

	try
	{
		// read the global parameters next:
		DataBlockReader oReader = sim::getAllGlobalParameterTupleList();
		_parameters.clear();
		while (oReader.getNextType() != SystemsBiologyWorkbench::TerminateType)
		{	
			ParameterInfo oInfo;
			DataBlockReader oTemp; oReader >> oTemp;

			oTemp >> oInfo.ID;
			oTemp >> oInfo.Value;
			_parameters.push_back(oInfo);
		}
	}
	catch(...)
	{
	}

	return reactions;

}

osg::Vec2 Simulate3D::getNormal (std::vector<double> oStart, std::vector<double> oEnd)
{
	osg::Vec2 p1 (oStart[0], oStart[1]); osg::Vec2 p2 (oEnd[0], oEnd[1]);
	osg::Vec2 result = p1 - p2;	
	bool bTemp = abs(result.x()) > abs(result.y());
	osg::Vec2 dTemp  ( (bTemp ? -result.x():result.x()), (bTemp? result.y():-result.y()));
	result = dTemp;
	result.normalize();
	return result;
}


osg::ref_ptr< osg::Geometry > Simulate3D::drawLine( std::vector<double> oStart, std::vector<double> oEnd, 
												   std::vector<double> oBase1, std::vector<double> oBase2,
												   std::vector<double> oColor )
{
	osg::ref_ptr< osg::Geometry > result = new osg::Geometry();

	// set up vertices
	osg::ref_ptr< osg::Vec3Array > vertices = new osg::Vec3Array();
	osg::ref_ptr< osg::Vec3Array > reverseBuffer = new osg::Vec3Array();
	osg::ref_ptr< osg::Vec3Array > forwardBuffer = new osg::Vec3Array();
	osg::ref_ptr< osg::Vec3Array > curveVertices = new osg::Vec3Array();

	double m_dTension = 0.0;
	double P[4][2] = {
		{oStart[0],-oStart[1]}, 
		{oBase1[0],-oBase1[1]}, 
		{oBase2[0],-oBase2[1]}, 
		{oEnd  [0],-oEnd  [1]}
	}; 
	double StartPoint[2]	= {oStart[0],-oStart[1]};
	double EndPoint[2]		= {  oEnd[0],-  oEnd[1]};

	double vv[2];
	double tangent1, tangent2, t;

	double dRange = MY_MAX(0.5 * oColor[0],0.5);
	osg::Vec2 oOffset = getNormal(oStart, oEnd);
	oOffset.set(Util::sign(oOffset.x())*dRange, Util::sign(oOffset.y())*dRange);

	for(t=0; t<=1; t+=0.001)
	{
		for(int i=0; i<2; i++)
		{

			tangent1 = ( 3 * (1 - m_dTension)*(P[1][i] - P[0][i]) );
			tangent2 = ( 3 * (1 - m_dTension)*(P[3][i] - P[2][i]) );

			vv[i] = ((2*t*t*t)-(3*t*t)+1)*StartPoint[i]
			+ ((-2*t*t*t)+(3*t*t))*EndPoint[i]
			+ ((t*t*t)-(2*t*t)+t)*tangent1
				+ ((t*t*t)-(t*t))*tangent2;
		}

		curveVertices->push_back( osg::Vec3(vv[0],vv[1],0.001) );
		forwardBuffer->push_back( osg::Vec3(vv[0]+oOffset.x(),vv[1]-oOffset.y(),0.001) );
		reverseBuffer->push_back( osg::Vec3(vv[0]-oOffset.x(),vv[1]+oOffset.y(),0.001) );
	}

	while (forwardBuffer->size() >= 2)
	{		
		vertices->push_back( forwardBuffer->back() );
		forwardBuffer->pop_back();
		osg::Vec3 dTemp = forwardBuffer->back();
		vertices->push_back( dTemp  );
		vertices->push_back( reverseBuffer->back() );
		vertices->push_back( reverseBuffer->back() );
		reverseBuffer->pop_back();
		vertices->push_back( reverseBuffer->back() );
		vertices->push_back( dTemp  );		
	}

	_oReactionCurves.push_back(curveVertices);
	result->setVertexArray( vertices.get() );

	// set up colours
	osg::ref_ptr< osg::Vec4Array > oColorArray = new osg::Vec4Array();
	oColorArray->push_back( osg::Vec4(oColor[1], oColor[2], oColor[3], oColor[4]) );
	result->setColorArray	( oColorArray.get() );
	result->setColorBinding	( osg::Geometry::BIND_OVERALL );


	// set up the primitive set to draw lines
	//osg::ref_ptr < osg::DrawArrays > oArrays = new osg::DrawArrays( GL_LINE_STRIP, 0, vertices->size() );
	osg::ref_ptr < osg::DrawArrays > oArrays = new osg::DrawArrays( GL_TRIANGLE_STRIP, 0, vertices->size() );
	result->addPrimitiveSet	( oArrays.get() );

	return result.get();
}
osg::ref_ptr< osg::Geometry > Simulate3D::drawLine(std::vector<double> oStart, std::vector<double> oEnd,
												   std::vector<double> oColor)
{
	osg::ref_ptr< osg::Geometry > result = new osg::Geometry();

	// set up vertices	
	double dRange = MY_MAX(0.5 * oColor[0],0.5);
	osg::Vec2 oOffset = getNormal(oStart, oEnd);
	oOffset.set(Util::sign(oOffset.x())*dRange, Util::sign(oOffset.y())*dRange);
	osg::ref_ptr< osg::Vec3Array > vertices = new osg::Vec3Array( );
	vertices -> push_back( osg::Vec3(oStart[0]+oOffset.x(),-oStart[1]-oOffset.y(),0.001f) );
	vertices -> push_back( osg::Vec3(oEnd[0]+oOffset.x(),-oEnd[1]-oOffset.y(),0.001f) );
	vertices -> push_back( osg::Vec3(oEnd[0]-oOffset.x(),-oEnd[1]+oOffset.y(),0.001f) );
	vertices -> push_back( osg::Vec3(oStart[0]-oOffset.x(),-oStart[1]+oOffset.y(),0.001f) );

	result->setVertexArray( vertices.get() );

	// set up colours
	osg::ref_ptr< osg::Vec4Array > oColorArray = new osg::Vec4Array();
	oColorArray->push_back( osg::Vec4(oColor[1],oColor[2],oColor[3],oColor[4]) );
	result->setColorArray	( oColorArray.get() );
	result->setColorBinding	( osg::Geometry::BIND_OVERALL );
	osg::ref_ptr < osg::DrawArrays > oArrays = new osg::DrawArrays(GL_POLYGON,0,vertices->size());

	// set up the primitive set to draw lines
	result->addPrimitiveSet	( oArrays.get() );

	// generate points for animation path
	osg::ref_ptr< osg::Vec3Array > curveVertices = new osg::Vec3Array( );
	curveVertices -> push_back( osg::Vec3(oStart[0],-oStart[1],0.001f) );
	curveVertices -> push_back( osg::Vec3(oEnd[0],-oEnd[1],0.001f) );

	_oReactionCurves.push_back(curveVertices);

	return result.get();
}


osg::ref_ptr<osg::Node> Simulate3D::createModel()
{	
	if (_dimensions.size() < 2) throw new SBWApplicationException("Fatal Error", "The dimensions of the model are still unknown in createModel.");
	osg::ref_ptr<osg::Group> root = new osg::Group;

	// turn off lighting 
	root->getOrCreateStateSet()->setMode((osg::StateAttribute::GLMode)GL_LIGHTING,osg::StateAttribute::OFF);

	osg::ref_ptr<osg::Material> mat = new osg::Material();

	mat->setColorMode	( osg::Material::DIFFUSE );
	mat->setAmbient		( osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1) );
	mat->setSpecular	( osg::Material::FRONT_AND_BACK, osg::Vec4(1, 1, 1, 1) );
	mat->setShininess	( osg::Material::FRONT_AND_BACK, 64.0f );

	root->getOrCreateStateSet()->setAttributeAndModes(mat.get(),osg::StateAttribute::ON);

	osg::BoundingBox bb(0.0f,-1.0f*_dimensions[1],0.0f,_dimensions[0],0.0f,0.0f);
	// add the model background
	root->addChild(createModelPlane(bb,_sTextureFilename.c_str()).get());

	// add the bars representing species concentrations
	_oColumns = createColumns().get();
	root->addChild(_oColumns.get());


	// add reactions ...
	if (_bRenderReactions)
	{
		_oReactions = createReactions().get();
		if (_oReactions->getNumChildren() > 0)
			root->addChild(_oReactions.get());
	}

	// add HUD
	root->addChild(createHUD(_oUpdateText.get()).get());

	root->addChild(createInfo(_oInfoText.get()).get());


	try
	{
		_oLogoGroup = createHelp(
			osg::BoundingBox(0.0f,0.0f,0.0f, 1280.0f,1024.0f,0.0f),
			string("Simulate3DLogo.png")).get();	
	} 
	catch (...)
	{
		///
	}

	_oLogoGroup->setNodeMask(0);
	root->addChild(_oLogoGroup.get());

	createControls(root.get());

	try
	{
		_oHelpGroup = createHelp(
			osg::BoundingBox(0.0f,0.0f,0.0f, 1280.0f,1024.0f,0.0f),
			string("help_screen.png")).get();	
	} 
	catch (...)
	{
		///
	}

	_oHelpGroup->setNodeMask(0);
	root->addChild(_oHelpGroup.get());

	return root.get();
}

void Simulate3D::createControls(osg::Group* oControl)
{
	float dWidth = 305.0f/2.5;
	float dHeight = 203.0f/2.5;

	_oControlGroup->setName("");
	_oControlGroup->addChild(createHelp(
		osg::BoundingBox(0.0f,0.0f,0.0f, 1280.0f,dHeight/2.0,0.0f),
		string("white.png"),"").get());

	if (CreateControls)
	{
		_oControlGroup->addChild(createHelp(
			osg::BoundingBox(0.0f,0.0f,0.0f, dWidth/2.0,dHeight/2.0,0.0f),
			string("cmdFastBack.png"),"fastBack").get());

		_oControlGroup->addChild(createHelp(
			osg::BoundingBox(dWidth/2.0,0.0f,0.0f, dWidth,dHeight/2,0.0f),
			string("cmdBack.png"),"back").get());

		_oControlGroup->addChild(createHelp(
			osg::BoundingBox(dWidth,0.0f,0.0f, dWidth*1.5,dHeight/2,0.0f),
			string("cmdPlay.png"),"play").get());

		_oControlGroup->addChild(createHelp(
			osg::BoundingBox(dWidth*1.5,0.0f,0.0f, dWidth*2,dHeight/2,0.0f),
			string("cmdPause.png"),"pause").get());

		_oControlGroup->addChild(createHelp(
			osg::BoundingBox(dWidth*2,0.0f,0.0f, dWidth*2.5,dHeight/2,0.0f),
			string("cmdNext.png"),"next").get());

		_oControlGroup->addChild(createHelp(
			osg::BoundingBox(dWidth*2.5,0.0f,0.0f, dWidth*3,dHeight/2,0.0f),
			string("cmdFastNext.png"),"fastNext").get());

		_oControlGroup->addChild(createHelp(
			osg::BoundingBox(dWidth*3,0.0f,0.0f, dWidth*3.5,dHeight/2,0.0f),
			string("cmdStop.png"),"stop").get());
	}

	_oControlGroup->addChild(createCurrent(_oCurrentText.get()).get());

	oControl->addChild(_oControlGroup.get());

}

osg::ref_ptr<osg::Node> Simulate3D::createHelp(osg::BoundingBox bb,const std::string filename, string sName)
{    // create the hud. derived from osgHud.cpp
	// adds a set of quads, each in a separate Geode - which can be picked individually
	// eg to be used as a menuing/help system!
	// Can pick texts too!
	osg::ref_ptr<osg::MatrixTransform> modelview_abs = new osg::MatrixTransform;
	modelview_abs->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	modelview_abs->setMatrix(osg::Matrix::identity());
	//modelview_abs->setName(sName);

	//	// create the geometry for the wall.
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	//geom->setName(sName);
	osg::ref_ptr<osg::Projection> projection = new osg::Projection;
	//projection->setName(sName);
	projection->setMatrix(osg::Matrix::ortho2D(0,1280,0,1024));
	projection->addChild(modelview_abs.get());


	osg::ref_ptr<osg::Group> group = new osg::Group;
	//group->setName(sName);

	// left hand side of bounding box.
	osg::Vec3 top_left(bb.xMin(),bb.yMax(),bb.zMin());
	osg::Vec3 bottom_left(bb.xMin(),bb.yMin(),bb.zMin());
	osg::Vec3 bottom_right(bb.xMax(),bb.yMin(),bb.zMin());
	osg::Vec3 top_right(bb.xMax(),bb.yMax(),bb.zMin());
	osg::Vec3 center((bb.xMin()+bb.xMax())*0.5f,(bb.yMin()+bb.yMax())*0.5f,bb.zMin());    
	float height = bb.yMax()-bb.yMin();


	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(4);
	(*vertices)[0] = top_left;
	(*vertices)[1] = bottom_left;
	(*vertices)[2] = bottom_right;
	(*vertices)[3] = top_right;
	geom->setVertexArray(vertices.get());

	osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array(4);
	(*texcoords)[0].set(0.0f,1.0f);
	(*texcoords)[1].set(0.0f,0.0f);
	(*texcoords)[2].set(1.0f,0.0f);
	(*texcoords)[3].set(1.0f,1.0f);
	geom->setTexCoordArray(0,texcoords.get());

	osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(1);
	(*normals)[0].set(0.0f,0.0f,1.0f);
	geom->setNormalArray(normals.get());
	geom->setNormalBinding(osg::Geometry::BIND_OVERALL);

	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0].set(1.0f,1.0f,1.0f,1.0f);
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);

	geom->addPrimitiveSet(new osg::DrawArrays(GL_QUADS,0,4));
	//geom->setName(sName);
	osg::ref_ptr<osg::Geode> geom_geode = new osg::Geode;
	geom_geode->addDrawable(geom.get());
	geom_geode->setName(sName);
	group->addChild(geom_geode.get());
	//group->setName(sName);


	// set up the texture state.    
	osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	texture->setResizeNonPowerOfTwoHint(true);
	//texture->setName(sName);
	texture->setFilter(osg::Texture2D::MIN_FILTER,osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	texture->setFilter(osg::Texture2D::MAG_FILTER,osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	texture->setDataVariance(osg::Object::DYNAMIC); // protect from being optimized away as static state.


	//texture->setImage(_oImage.get());
	texture->setImage(osgDB::readImageFile(filename));

	//texture->setMaxAnisotropy(16.0f);

	osg::StateSet* stateset = geom->getOrCreateStateSet();
	stateset->setTextureAttributeAndModes(0,texture.get(),osg::StateAttribute::ON);
	stateset->setMode((osg::StateAttribute::GLMode)GL_LIGHTING,osg::StateAttribute::OFF);
	stateset->setMode((osg::StateAttribute::GLMode)GL_DEPTH_TEST,osg::StateAttribute::OFF);

	modelview_abs->addChild(group.get());

	return projection.get();

} // end create HUD

osg::ref_ptr<osg::Node> Simulate3D::createHUD(osgText::Text* updateText)
{    // create the hud. derived from osgHud.cpp
	// adds a set of quads, each in a separate Geode - which can be picked individually
	// eg to be used as a menuing/help system!
	// Can pick texts too!
	osg::ref_ptr<osg::MatrixTransform> modelview_abs = new osg::MatrixTransform;
	modelview_abs->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	modelview_abs->setMatrix(osg::Matrix::identity());

	osg::ref_ptr<osg::Projection> projection = new osg::Projection;
	projection->setMatrix(osg::Matrix::ortho2D(0,1280,0,1024));
	projection->addChild(modelview_abs.get());

	std::string timesFont("fonts/courbd.ttf");

	// turn lighting off for the text and disable depth test to ensure its always ontop.
	osg::Vec3 position(0.0f,1000.0f,0.0f);
	osg::Vec3 delta(0.0f,-120.0f,0.0f);

	{ // this displays what has been selected
		osg::ref_ptr<osg::Geode> geode = new osg::Geode();
		osg::StateSet* stateset = geode->getOrCreateStateSet();
		stateset->setMode((osg::StateAttribute::GLMode)GL_LIGHTING,osg::StateAttribute::OFF);
		stateset->setMode((osg::StateAttribute::GLMode)GL_DEPTH_TEST,osg::StateAttribute::OFF);
		geode->setName("update");
		geode->addDrawable( updateText );
		geode->setUpdateCallback(new SpeciesCallback());
		modelview_abs->addChild(geode.get());


		updateText->setCharacterSize(30.0f);		
		updateText->setFont(timesFont);		
		updateText->setColor(osg::Vec4(1.0f,1.0f,0.0f,1.0f));
		updateText->setText("");
		updateText->setPosition(position);
		updateText->setName("update");


		position += delta;
	}    
	if (CreateControls)
	{
		osg::ref_ptr<osg::Geode> geode = new osg::Geode();
		osg::StateSet* stateset = geode->getOrCreateStateSet();
		stateset->setMode((osg::StateAttribute::GLMode)GL_LIGHTING,osg::StateAttribute::OFF);
		stateset->setMode((osg::StateAttribute::GLMode)GL_DEPTH_TEST,osg::StateAttribute::OFF);
		geode->setName("HELP Text");

		osg::ref_ptr<osgText::Text> text= new osgText::Text();

		geode->addDrawable( text.get() );
		modelview_abs->addChild(geode.get());

		text->setCharacterSize(20.0f);
		text->setFont(timesFont);		
		if (!_bWhite)
			text->setColor(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
		else
			text->setColor(osg::Vec4(0.0f,0.0f,0.0f,1.0f));
		text->setText("<H>   - Help\n<ESC> - Quit");
		text->setPosition(osg::Vec3(1100.0f,1004.0f,0.0f));

	}

	return projection.get();


} // end create HUDf


osg::ref_ptr<osg::Node> Simulate3D::createCurrent(osgText::Text* currentText)
{
	osg::ref_ptr<osg::MatrixTransform> modelview_abs = new osg::MatrixTransform;
	modelview_abs->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	modelview_abs->setMatrix(osg::Matrix::identity());

	osg::ref_ptr<osg::Projection> projection = new osg::Projection;
	projection->setMatrix(osg::Matrix::ortho2D(0,1280,0,1024));
	projection->addChild(modelview_abs.get());


	std::string timesFont("fonts/lcd.ttf");

	// turn lighting off for the text and disable depth test to ensure its always ontop.
	osg::Vec3 position(1200.0f,10.0f,0.0f);
	osg::Vec3 delta(0.0f,10.0f,0.0f);

	{ // this displays what has been selected
		osg::ref_ptr<osg::Geode> geode = new osg::Geode();
		osg::StateSet* stateset = geode->getOrCreateStateSet();
		stateset->setMode((osg::StateAttribute::GLMode)GL_LIGHTING,(osg::StateAttribute::GLModeValue)osg::StateAttribute::OFF);
		stateset->setMode((osg::StateAttribute::GLMode)GL_DEPTH_TEST,(osg::StateAttribute::GLModeValue)osg::StateAttribute::OFF);
		geode->setName("current");
		geode->addDrawable( currentText );
		geode->setUpdateCallback(new SpeciesCallback());
		modelview_abs->addChild(geode.get());

		currentText->setCharacterSize(30.0f);
		currentText->setFont(timesFont);		
		currentText->setAlignment(osgText::Text::RIGHT_BOTTOM);
		currentText->setColor(osg::Vec4(0.0f,0.0f,0.0f,1.0f));
		currentText->setText("Time");
		currentText->setPosition(position);
		currentText->setName("current");

		position += delta;
	}    

	return projection.get();
}
osg::ref_ptr<osg::Node> Simulate3D::createInfo(osgText::Text* infoText)
{    // create the hud. derived from osgHud.cpp
	// adds a set of quads, each in a separate Geode - which can be picked individually
	// eg to be used as a menuing/help system!
	// Can pick texts too!
	osg::ref_ptr<osg::MatrixTransform> modelview_abs = new osg::MatrixTransform;
	modelview_abs->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	modelview_abs->setMatrix(osg::Matrix::identity());

	osg::ref_ptr<osg::Projection> projection = new osg::Projection;
	projection->setMatrix(osg::Matrix::ortho2D(0,1280,0,1024));
	projection->addChild(modelview_abs.get());


	std::string timesFont("fonts/courbd.ttf");

	// turn lighting off for the text and disable depth test to ensure its always ontop.
	osg::Vec3 position(0.0f,60.0f,0.0f);
	osg::Vec3 delta(0.0f,60.0f,0.0f);

	{ // this displays what has been selected
		osg::ref_ptr<osg::Geode> geode = new osg::Geode();
		osg::StateSet* stateset = geode->getOrCreateStateSet();
		stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
		stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
		geode->setName("info");
		geode->addDrawable( infoText );
		geode->setUpdateCallback(new SpeciesCallback());
		modelview_abs->addChild(geode.get());

		infoText->setCharacterSize(30.0f);
		infoText->setFont(timesFont);		
		infoText->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
		infoText->setText("");
		infoText->setPosition(position);
		infoText->setName("info");

		position += delta;
	}    

	return projection.get();

} // end create HUD

void Simulate3D::startProducer(osg::ArgumentParser arguments)
{
	startProducer(arguments, false);
}
void Simulate3D::clearLists()
{
	stop();
	_oBoundarySpecies.clear();
	_oFloatingSpecies.clear();
	_species.clear();	
	DataProviders.clear();
	if (_oColumns != NULL)
		_oColumns->removeChildren(0,_oColumns->getNumChildren());
	if (_oReactions != NULL)
		_oReactions->removeChildren(0,_oReactions->getNumChildren());
	_oData = NULL;
	_rootnode = new osg::MatrixTransform();
	CanSimulate=false;
	//unlink(_sTextureFilename.c_str());
	_sTextureFilename = "";
	_sTexture = "";
	_sSBML = "";
	_sCSVFile = "";
	_sFileName = "";

}
void Simulate3D::startProducer(osg::ArgumentParser arguments, bool bWhite)
{
	try
	{
		_bWhite = bWhite;
		// initialize the viewer.
		osgViewer::Viewer viewer(arguments);

//#if defined (DEBUG) || defined (_DEBUG)
//		viewer.setUpViewer(osgProducer::Viewer::STANDARD_SETTINGS);
//#else
//		// set up the value with sensible default event handlers.
//		viewer.setUpViewer(
//			osgProducer::Viewer::TRACKBALL_MANIPULATOR|
//			osgProducer::Viewer::DRIVE_MANIPULATOR |
//			osgProducer::Viewer::FLIGHT_MANIPULATOR |
//			osgProducer::Viewer::TERRAIN_MANIPULATOR |
//			osgProducer::Viewer::HEAD_LIGHT_SOURCE |
//			osgProducer::Viewer::ESCAPE_SETS_DONE
//			);
//#endif
//		if (bWhite)
//			viewer.setClearColor(osg::Vec4(osg::Vec3(1.0f,1.0f,1.0f),0.0f));
//		else
//			viewer.setClearColor(osg::Vec4(osg::Vec3(0.0f,0.0f,0.0f),0.0f));		
//
//		viewer
		
		osgDB::ReaderWriter::Options* options = new osgDB::ReaderWriter::Options;
		options->setObjectCacheHint(osgDB::ReaderWriter::Options::CACHE_IMAGES);
		osgDB::Registry::instance()->setOptions(options);


		// get details on keyboard and mouse bindings used by the viewer.
		viewer.getUsage(*arguments.getApplicationUsage());
		PickHandler *handler = new PickHandler(&viewer);
		viewer.addEventHandler(handler);

//		viewer.getEventHandlerList().push_front(handler);

//		if (MultiScreen)
//		{
//			Producer::RenderSurface* oSurface = viewer.getCamera(0)->getRenderSurface();
//
//			unsigned int nWidth;
//			unsigned int nHeight;
//			oSurface->getScreenSize( nWidth, nHeight );			
//			unsigned int nNumDisplay;
//#ifdef WIN32
//			nNumDisplay = getNumberOfScreens();
//#else
//			nNumDisplay = oSurface->getNumberOfScreens();
//#endif
//
//			oSurface->setCustomFullScreenRectangle(0,0
//				, nWidth*nNumDisplay, nHeight);
//		}

		// load the nodes from the commandline arguments.
		osg::ref_ptr<osg::Node> model = createModel();
		if (!model)
		{
			return;
		}
		srand( (unsigned)time( NULL ) );

		// tilt the scene so the default eye position is looking down on the model.
		_rootnode =  new osg::MatrixTransform;
		_rootnode -> setMatrix(osg::Matrix::rotate(osg::inDegrees(30.0f),1.0f,0.0f,0.0f));
		_rootnode -> addChild(model.get());		

		// run optimization over the scene graph
		//osgUtil::Optimizer optimzer;
		//optimzer.optimize(rootnode.get());

		if (ScreenSaverMode)
		{						
			RotateCallback::bb = osg::BoundingBox(0.0f,-1.0f*_dimensions[1],0.0f,_dimensions[0],0.0f,0.0f);

			// set up a transform to rotate the model
			osg::Matrix oTemp;			
			oTemp.makeTranslate(-RotateCallback::bb.center());
			osg::ref_ptr<osg::MatrixTransform> xform = new osg::MatrixTransform(oTemp);
			RotateCallback::rotate_cb = new RotateCallback;
			xform->setUpdateCallback(RotateCallback::rotate_cb);
			xform->addChild(_rootnode.get());

			// set the scene to render
			viewer.setSceneData(xform.get());	
		}
		else
		{
			viewer.setSceneData(_rootnode.get());	
		}

		// create the windows and run the threads.
		viewer.realize();

		//Simulate3D::setText( "Frank Bergmann" );
		Simulate3D::setInfo( "Simulate 3D version 2.0" );

		startThread();
		
		viewer.setThreadingModel(osgViewer::ViewerBase::SingleThreaded);
		viewer.run();

		SleepFactor = 0;
		stop();

	}
	catch (...)
	{
	}
}


bool Simulate3D::switchDataProvider(int nProvider, bool bStopThread )
{

	DataProvider *oTemp = NULL;
	bool bError = false;
	try
	{
		if ((int)DataProviders.size() >  nProvider)
		{
			oTemp = DataProviders[nProvider];
		}
		else
		{
			oTemp = _oData;
		}

		oTemp->reset();
	}
	catch(...)
	{
		bError = true;
	}
	if (!bError)
	{
		if (bStopThread) Simulate3D::stop();

		Simulate3D::TimeStart = 0.0;
		Simulate3D::SleepFactor = 4;
		Simulate3D::_oData = oTemp;			
		Simulate3D::_oData->syncSpecies();
		CanSimulate = _oData->canSimulate();

		if (bStopThread) Simulate3D::startThread();

		if (_oData->getName() == "TimeSeriesData")
		{
			_oControlGroup->setNodeMask(1);
		}
		else
		{
			_oControlGroup->setNodeMask(0);
		}
	}
	return bError;

}


bool						Simulate3D::CanSimulate		= true;
bool						Simulate3D::_bCurrentSet	= false;
bool						Simulate3D::CreateControls	= true;
bool						Simulate3D::ScreenSaverMode = false;
bool						Simulate3D::MultiScreen		= false;
bool						Simulate3D::_bBufferSet		= false;
bool						Simulate3D::_bInfoSet		= false;
bool						Simulate3D::_bRenderReactions = false;
int							Simulate3D::SleepFactor		= 50;
int							Simulate3D::_nInfoDelay		= 0;
double						Simulate3D::TextureSize		= 1024.0;
double						Simulate3D::ScaleFactor		= 30.0;
double						Simulate3D::TimeStart		= 0.0;
double						Simulate3D::TimeStep		= 0.05;
double						Simulate3D::MaxRate			= 1.0;
string						Simulate3D::_sSBML			= "";
string						Simulate3D::_sBuffer		= "";
string						Simulate3D::_sPath			= "";
string						Simulate3D::_sInfo			= "";
string						Simulate3D::_sTempDir		= "";
string						Simulate3D::_sCurrent		= "";
DataProvider				*Simulate3D::_oData			= NULL;
SimulationThread			Simulate3D::_oTread;
osg::ref_ptr<osgText::Text>	Simulate3D::_oInfoText		= NULL;
osg::ref_ptr<osgText::Text>	Simulate3D::_oCurrentText	= NULL;
osg::ref_ptr<osgText::Text>	Simulate3D::_oUpdateText	= NULL;
osg::ref_ptr<osg::Node>		Simulate3D::_oHelpGroup		= NULL;
osg::ref_ptr<osg::Node>		Simulate3D::_oLogoGroup		= NULL;
osg::ref_ptr<osg::Group>	Simulate3D::_oControlGroup	= NULL;
osg::ref_ptr<osg::Group>	Simulate3D::_oColumns		= NULL;
osg::ref_ptr<osg::Group>	Simulate3D::_oReactions		= NULL;
vector<double>				Simulate3D::_dimensions;
vector<SpeciesCoordinates>	Simulate3D::_species;
vector<DataProvider*>		Simulate3D::DataProviders;
vector<ReactionInfo>		Simulate3D::_reactions;
vector<ParameterInfo>		Simulate3D::_parameters;

vector < osg::ref_ptr< osg::Vec3Array > > Simulate3D::_oReactionCurves;
vector < vector < osg::ref_ptr < osg::AnimationPathCallback > > > Simulate3D::_oAnimationCallbacks;
hash_map< string, int >		Simulate3D::_oSpeciesMap;
hash_map< string, int >		Simulate3D::_oReactionMap;


