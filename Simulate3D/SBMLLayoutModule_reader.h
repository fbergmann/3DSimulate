#ifndef SBMLLAYOUT_MODULE_READER_H
#define SBMLLAYOUT_MODULE_READER_H

#include "SBW/SBW.h"

#include <string>
#include <vector>

using namespace std;
using namespace SystemsBiologyWorkbench;

namespace SBMLLayoutModule 
{ 
	class reader  
	{ 
	public: 
		reader (){}

		//<summary>
		//Returns the currently loaded image as byte-stream
		//</summary>
		static void getImage(double dScale, int &length, unsigned char* &array)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(dScale);
				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result = oService.getMethod("byte[] getScaledImage(double)").call(oArguments);
				result.get(length, array);
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//SBML Layout Viewer/Manipulator version 0.2
		//</summary>
		static string getVersion()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				string result;
				oService.getMethod("string getVersion()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Hides/Shows the Form
		//</summary>
		static void setVisible(bool  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setVisible(boolean)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Renders the layout of the given SBML model
		//</summary>
		static void doAnalysis(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void doAnalysis(string)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Loads a new SBML model
		//</summary>
		static void loadSBML(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0.c_str());

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void loadSBML(string)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the original model
		//</summary>
		static string getSBML()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				string result;
				oService.getMethod("string getSBML()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Test's whether the loaded SBML has Layout Information
		//</summary>
		static bool hasLayout()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				bool result;
				oService.getMethod("boolean hasLayout()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns information about the currently loaded Layout
		//</summary>
		static vector< string > getInfo()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				vector< string > result;
				oService.getMethod("string[] getInfo()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of compartment glyphs in default layout
		//</summary>
		static int getNumberOfCompartmentGlyphs()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int getNumberOfCompartmentGlyphs()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of reaction glyphs in default layout
		//</summary>
		static int getNumberOfReactionGlyphs()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int getNumberOfReactionGlyphs()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of species glyphs in default layout
		//</summary>
		static int getNumberOfSpeciesGlyphs()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int getNumberOfSpeciesGlyphs()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of alias nodes for the given species glyph id in default layout
		//</summary>
		static int getNumberOfAliasNodes(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int getNumberOfAliasNodes(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of text glyphs in default layout
		//</summary>
		static int getNumberOfTextGlyphs()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int getNumberOfTextGlyphs()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the dimension of the default layout (Format: width, height, depth)
		//</summary>
		static vector< double > getDimensions()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				vector< double > result;
				oService.getMethod("double[] getDimensions()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the dimension of the default layout (Format: width, height, depth)
		//</summary>
		static vector< double > getReactionGlyphRenderInfoGL(int nIndex)
		{
			try
			{
				DataBlockWriter oArguments; oArguments << nIndex;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				vector< double > result;
				oService.getMethod("double[] getReactionGlyphRenderInfoGL(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}


		//<summary>
		//Sets the Id and dimension of the current layout
		//</summary>
		static void setLayout(string  var0,vector< double >  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setLayout(string,double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Layout information for the compartment glyph at the given index position. (Format: id, reference, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getCompartmentGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getCompartmentGlyph(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Layout information for the Compartment Glyph with the given id (sbml level2) or name (sbml level1). (Format: id, reference, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getCompartmentGlyphById(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getCompartmentGlyphById(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the index for the Compartment Glyph with the given id (sbml level2) or name (sbml level1). 
		//</summary>
		static int getCompartmentGlyphIndexById(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int getCompartmentGlyphIndexById(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets id, reference and bounding box of the i-th compartment glyph. (Format: index, id, reference, double[] position, double[] dimension)
		//</summary>
		static void setCompartmentGlyph(int  var0,string  var1,string  var2,vector< double >  var3,vector< double >  var4)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setCompartmentGlyph(int,string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Adds a new Compartment Glyph. (Format: index, id, reference, double[] position, double[] dimension)
		//</summary>
		static void addCompartmentGlyph(string  var0,string  var1,vector< double >  var2,vector< double >  var3)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void addCompartmentGlyph(string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Removes the i-th Compartment Glyph.
		//</summary>
		static void removeCompartmentGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void removeCompartmentGlyph(int)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Layout information for the Species Glyph at the given index position. (Format: id, reference, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getSpeciesGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getSpeciesGlyph(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Returns the currently used Color for the SpeciesGlyph with the given index (Format: alpha,red,green,blue)
		//</summary>
		static vector< double > getSpeciesGlyphColor(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				vector< double > result;
				oService.getMethod("double[] getSpeciesGlyphColor(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Layout information for the Species Glyph with the given id (sbml level2) or name (sbml level1). (Format: id, reference, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getSpeciesGlyphById(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getSpeciesGlyphById(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the index for the Species Glyph with the given id (sbml level2) or name (sbml level1). 
		//</summary>
		static int getSpeciesGlyphIndexById(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int getSpeciesGlyphIndexById(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the i-th Species Glyph (Format: index, id, reference, double[] position, double[] dimension)
		//</summary>
		static void setSpeciesGlyph(int  var0,string  var1,string  var2,vector< double >  var3,vector< double >  var4)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setSpeciesGlyph(int,string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Adds a new Species Glyph (Format: id, reference, double[] position, double[] dimension)
		//</summary>
		static void addSpeciesGlyph(string  var0,string  var1,vector< double >  var2,vector< double >  var3)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void addSpeciesGlyph(string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Removes the i-th Species Glyph
		//</summary>
		static void removeSpeciesGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void removeSpeciesGlyph(int)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the Alias node for the given SpeciesGlyphId and index (Format: aliasId, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getAliasNode(string  var0,int  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getAliasNode(string,int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//sets the aliasnode with the given id (Format: aliasId, double[] position, double[] dimension)
		//</summary>
		static void setAliasNode(string  var0,vector< double >  var1,vector< double >  var2)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setAliasNode(string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//adds a new alias node (Format: aliasId, reference, double[] position, double[] dimension)
		//</summary>
		static void addAliasNode(string  var0,string  var1,vector< double >  var2,vector< double >  var3)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void addAliasNode(string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Layout information for the TextGlyph at the given position. (Format: id, reference,  text, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getTextGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getTextGlyph(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the i-th TextGlyph (Format: index, id, reference, text, double[] position, double[] dimension)
		//</summary>
		static void setTextGlyph(int  var0,string  var1,string  var2,string  var3,vector< double >  var4,vector< double >  var5)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);
				oArguments.add(var5);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setTextGlyph(int,string,string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Adds a new TextGlyph (Format: index, id, reference, text, double[] position, double[] dimension)
		//</summary>
		static void addTextGlyph(string  var0,string  var1,string  var2,vector< double >  var3,vector< double >  var4)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void addTextGlyph(string,string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Removes the i-th Text Glyph
		//</summary>
		static void removeTextGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void removeTextGlyph(int)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Layout information on the ReactionGlyph at the given position. (Format: id, reference, numberOfSpeciesReferences, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getReactionGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getReactionGlyph(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns Layout information on the ReactionGlyph with the given id (sbml level2) or name (sbml level1). (Format: id, reference, numberOfSpeciesReferences, double[] position, double[] dimension)
		//</summary>
		static DataBlockReader getReactionGlyphById(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getReactionGlyphById(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Set's the i-th ReactionGlyph (Format: index, id, reference, double[] position, double[] dimension)
		//</summary>
		static void setReactionGlyph(int  var0,string  var1,string  var2,vector< double >  var3,vector< double >  var4)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setReactionGlyph(int,string,string,double[],double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Adds a new ReactionGlyph and returns the id. (Format: id, reference, double[] position, double[] dimension)
		//</summary>
		static int addReactionGlyph(int  var0,string  var1,string  var2,vector< double >  var3,vector< double >  var4)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int addReactionGlyph(int,string,string,double[],double[])").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Removes the i-th Reaction Glyph.
		//</summary>
		static void removeReactionGlyph(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void removeReactionGlyph(int)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the curve description for the ith reaction glyph. (Format: array of (type, double[] start, double[] end, double[] base1, double[] base2))
		//</summary>
		static vector< DataBlockReader > getReactionCurve(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				vector< DataBlockReader > result;
				oService.getMethod("{}[] getReactionCurve(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the curve description for the i-th reaction glyph. (Format: index,  array of (type, double[] start, double[] end, double[] base1, double[] base2))
		//</summary>
		static void setReactionCurve(int  var0,vector< DataBlockReader >  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setReactionCurve(int,{}[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the SpeciesReference for the i-th reaction and j-th species reference. (Format: id, reference, speciesglyph, role)
		//</summary>
		static DataBlockReader getSpeciesReference(int  var0,int  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				DataBlockReader result;
				oService.getMethod("{} getSpeciesReference(int,int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//sets the SpeciesReference for the i-th reaction and j-th species reference. (Format: reaction index, reference index, id, reference, speciesglyph, role)
		//</summary>
		static void setSpeciesReference(int  var0,int  var1,string  var2,string  var3,string  var4,string  var5)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);
				oArguments.add(var5);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setSpeciesReference(int,int,string,string,string,string)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Adds a new Species reference and returns the handle. (Format: reaction index, id, reference, speciesglyph, role)
		//</summary>
		static int addSpeciesReference(int  var0,string  var1,string  var2,string  var3,string  var4)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);
				oArguments.add(var3);
				oArguments.add(var4);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				int result;
				oService.getMethod("int addSpeciesReference(int,string,string,string,string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Removes the SpeciesReference for the i-th reaction and j-th species reference.
		//</summary>
		static void removeSpeciesReference(int  var0,int  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void removeSpeciesReference(int,int)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the SpeciesReference Curve for the i-th reaction and j-th species reference. (Format: array of (type, double[] start, double[]end, double[] base1, double[] base2))
		//</summary>
		static vector< DataBlockReader > getSpeciesReferenceCurve(int  var0,int  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				vector< DataBlockReader > result;
				oService.getMethod("{}[] getSpeciesReferenceCurve(int,int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the SpeciesReference Curve for the i-th reaction and j-th species reference. (Format: reaction index,  reference index, array of (type, double[] start, double[] end, double[] base1, double[] base2))
		//</summary>
		static void setSpeciesReferenceCurve(int  var0,int  var1,vector< DataBlockReader >  var2)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				oService.getMethod("void setSpeciesReferenceCurve(int,int,{}[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns a new SBML document with the SBML Layout Extension
		//</summary>
		static string writeSBML()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("SBMLLayoutModule");
				Service oService = oModule.findServiceByName("reader");
				string result;
				oService.getMethod("string writeSBML()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

	};
}
#endif
