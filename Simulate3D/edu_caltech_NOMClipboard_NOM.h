#ifndef EDU_CALTECH_NOM_CLIPBOARD_H
#define EDU_CALTECH_NOM_CLIPBOARD_H


#include "SBW/SBW.h"

#include <string>
#include <vector>

using namespace std;
using namespace SystemsBiologyWorkbench;

namespace edu_caltech_NOMClipboard 
{ 
	class NOM  
		{ 
		public: 
			NOM (){}
			
			//<summary>
			//Gets the value assigned to the input string. The input string can be a species name/Id, parameter name/Id, compartment name/Id.
			//</summary>
			static double getValue(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					double result;
					oService.getMethod("double getValue(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//The returns 1 if the input string appears in the sbml document otherwise 0. The input string can be a species name/Id, parameter name/Id, compartment name/Id.
			//</summary>
			static bool exists(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					bool result;
					oService.getMethod("boolean exists(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Loads the sbml document. The input string must be a valid sbml document. An exception will be thrown if there are fatal errors in the input string.
			//</summary>
			static void loadSBML(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0.c_str());
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					oService.getMethod("void loadSBML(string)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Validates the input sbml document. The input string must be a valid sbml document. An exception will be thrown if there are fatal errors in the input string.
			//</summary>
			static string validateSBML(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0.c_str());
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string validateSBML(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the currently loaded sbml document
			//</summary>
			static string getSBML()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getSBML()").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Modifies the names of local parameters by adding reaction name at the beginning and promotes them to global.
			//</summary>
			static string getParamPromotedSBML(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0.c_str());
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getParamPromotedSBML(string)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the modelName/Id given in sbml document
			//</summary>
			static string getModelName()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getModelName()").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the modelId/Name given in sbml document
			//</summary>
			static string getModelId()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getModelId()").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number offunction Definitions listed in the sbml document
			//</summary>
			static int getNumFunctionDefinitions()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumFunctionDefinitions()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of compartments listed in the sbml document
			//</summary>
			static int getNumCompartments()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumCompartments()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of reactions listed in the sbml document
			//</summary>
			static int getNumReactions()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumReactions()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of floating species in the sbml document
			//</summary>
			static int getNumFloatingSpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumFloatingSpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of boundary species in the sbml document
			//</summary>
			static int getNumBoundarySpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumBoundarySpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of global parameters in the sbml document
			//</summary>
			static int getNumGlobalParameters()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumGlobalParameters()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//The return type is a list containing {functionId, list of arguments, function body}. The index can vary from 0 to (numOfFunctionDefinitions-1). If the index exceeds the total number of function Definitions then the method throws an exception
			//</summary>
			static DataBlockReader getNthFunctionDefinition(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getNthFunctionDefinition(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//The return type is a list containing {species id's} where the species modify the reaction. The index can vary from 0 to (numReactions-1). If the index exceeds the total number of reactions then the method throws an exception
			//</summary>
			static DataBlockReader getNthListOfModifiers(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getNthListOfModifiers(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of compartment for the input index. The index can vary from 0 to (numOfCompartments-1). If the index exceeds the total number of compartments then the method throws an exception
			//</summary>
			static string getNthCompartmentName(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthCompartmentName(int)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the Id of compartment for the input index. The index can vary from 0 to (numOfCompartments-1). If the index exceeds the total number of compartments then the method throws an exception
			//</summary>
			static string getNthCompartmentId(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthCompartmentId(int)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the outside compartment for the input. The input should be a compartment name for level 1 and compartment id for level 2. Throws an exception if the id or name is not found.
			//</summary>
			static string getOutsideCompartment(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getOutsideCompartment(string)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of all the floating speciesIds.
			//</summary>
			static DataBlockReader getListOfFloatingSpeciesIds()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getListOfFloatingSpeciesIds()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of all the floating species and their values. The return type will be a list of lists ex:- {{\"S1\",1.0},{\"S2\",2.0}}
			//</summary>
			static DataBlockReader getListOfFloatingSpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getListOfFloatingSpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the floatingSpecies for the input index. The index can vary from 0 to (numOfFloatingSpecies-1). If the index exceeds the total number of floatingSpecies then the method throws an exception
			//</summary>
			static string getNthFloatingSpeciesName(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthFloatingSpeciesName(int)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the id of the floatingSpecies for the input index. The index can vary from 0 to (numOfFloatingSpecies-1). If the index exceeds the total number of floatingSpecies then the method throws an exception
			//</summary>
			static string getNthFloatingSpeciesId(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthFloatingSpeciesId(int)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of all the Boundary speciesIds.
			//</summary>
			static DataBlockReader getListOfBoundarySpeciesIds()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getListOfBoundarySpeciesIds()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of all the boundary species and their values. The return type will be a list of lists ex:- {{\"S1\",1.0},{\"S2\",2.0}}
			//</summary>
			static DataBlockReader getListOfBoundarySpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getListOfBoundarySpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the boundarySpecies for the input index. The index can vary from 0 to (numOfBoundarySpecies-1). If the index exceeds the total number of boundarySpecies then the method throws an exception
			//</summary>
			static string getNthBoundarySpeciesName(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthBoundarySpeciesName(int)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the id of the boundarySpecies for the input index. The index can vary from 0 to (numOfBoundarySpecies-1). If the index exceeds the total number of boundarySpecies then the method throws an exception
			//</summary>
			static string getNthBoundarySpeciesId(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthBoundarySpeciesId(int)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name/Id of the compartment where the Species with the given speciesId is located
			//</summary>
			static string getCompartmentIdBySpeciesId(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0.c_str());
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getCompartmentIdBySpeciesId(string)").call(oArguments) >> result;
					return result.c_str();
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the compartment where the floatingSpecies with the given index is located
			//</summary>
			static string getNthFloatingSpeciesCompartmentName(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthFloatingSpeciesCompartmentName(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the compartment where the floatingSpecies with the given index is located
			//</summary>
			static string getNthBoundarySpeciesCompartmentName(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthBoundarySpeciesCompartmentName(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns 1 if the reaction for the input index value is reversible and 0 otherwise. The index can vary from 0 to (numOfReactions-1). If the index exceeds the total number of Reactions then the method throws an exception
			//</summary>
			static bool isReactionReversible(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					bool result;
					oService.getMethod("boolean isReactionReversible(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the reaction for the input index value. The index can vary from 0 to (numOfReactions-1). If the index exceeds the total number of Reactions then the method throws an exception
			//</summary>
			static string getNthReactionName(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthReactionName(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the id of the reaction for the input index value. The index can vary from 0 to (numOfReactions-1). If the index exceeds the total number of Reactions then the method throws an exception
			//</summary>
			static string getNthReactionId(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthReactionId(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of reactants for tbe reaction index. The index can vary from 0 to (numOfReactions-1). If the index exceeds the total number of Reactions then the method throws an exception
			//</summary>
			static int getNumReactants(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumReactants(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of products for tbe reaction index. The index can vary from 0 to (numOfReactions-1). If the index exceeds the total number of Reactions then the method throws an exception
			//</summary>
			static int getNumProducts(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumProducts(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of reactant for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfReactants-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of reactants of the reaction then the method throws an exception
			//</summary>
			static string getNthReactantName(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthReactantName(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of product for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfProducts-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of products of the reaction then the method throws an exception
			//</summary>
			static string getNthProductName(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthProductName(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the Kineticlaw of reaction at the index value provided. The index can vary from 0 to (numOfReactions-1). If the index exceeds the total number of Reactions then the method throws an exception
			//</summary>
			static string getKineticLaw(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getKineticLaw(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of stoichiometry value for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfReactants-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of products of the reaction then the method throws an exception
			//</summary>
			static int getNthReactantStoichiometry(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNthReactantStoichiometry(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of stoichiometry value for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfProducts-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of products of the reaction then the method throws an exception
			//</summary>
			static int getNthProductStoichiometry(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNthProductStoichiometry(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of stoichiometry value for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfReactants-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of products of the reaction then the method throws an exception
			//</summary>
			static double getNthReactantStoichiometryDouble(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					double result;
					oService.getMethod("double getNthReactantStoichiometryDouble(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of stoichiometry value for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfProducts-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of products of the reaction then the method throws an exception
			//</summary>
			static double getNthProductStoichiometryDouble(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					double result;
					oService.getMethod("double getNthProductStoichiometryDouble(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of both the global & local parameters and their values. The return type will be a list of lists ex:- {{\"K1\",1.0},{\"K2\",2.0}}
			//</summary>
			static DataBlockReader getListOfParameters()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getListOfParameters()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the total number of local parameters for the input reaction index.
			//</summary>
			static int getNumParameters(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumParameters(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the parameter for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (localParameters-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of Parameters of the reaction then the method throws an exception
			//</summary>
			static string getNthParameterName(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthParameterName(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the id of the parameter for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (localParameters-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of Parameters of the reaction then the method throws an exception
			//</summary>
			static string getNthParameterId(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthParameterId(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the value of parameter for the indicies values provided. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfParameters-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of Parameters of the reaction then the method throws an exception
			//</summary>
			static double getNthParameterValue(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					double result;
					oService.getMethod("double getNthParameterValue(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns 1 if a value is assigned to the parameter for the indicies values provided and 0 otherwise. The first input is the reaction index and it can vary from 0 to (numOfReactions-1). The second index varies from 0 to (numberOfParameters-1) of the input reaction index. If the first index exceeds the total number of Reactions or the second index exceeds the total number of Parameters of the	reaction then the method throws an exception
			//</summary>
			static bool getNthParameterHasValue(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					bool result;
					oService.getMethod("boolean getNthParameterHasValue(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the global parameter at index values provided. The index can vary from 0 to (numOfGlobalParameters-1). If the index exceeds the total number of Global Parameters then the method throws an exception
			//</summary>
			static string getNthGlobalParameterName(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthGlobalParameterName(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the id of the global parameter at index values provided. The index can vary from 0 to (numOfGlobalParameters-1). If the index exceeds the total number of Global Parameters then the method throws an exception
			//</summary>
			static string getNthGlobalParameterId(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthGlobalParameterId(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the total number of Rules in the sbml.
			//</summary>
			static int getNumRules()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumRules()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the rule at the index value provided. The index can vary from 0 to (numOfRules-1). If the index exceeds the total number of rules then the method throws an exception.
			//</summary>
			static string getNthRule(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthRule(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//The return string indicates the type of rule at the index provided. Eg., 'Assignment_Rule', 'Algebraic_Rule', 'Rate_Rule', 'Parameter_Rule'; 'Species_Concentration_Rule'; 'Compartment_Volume_Rule'. The index can vary from 0 to (numOfRules-1). If the index exceeds the total number of rules then the method throws an exception.
			//</summary>
			static string getNthRuleType(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string getNthRuleType(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the total number of Event in the sbml.
			//</summary>
			static int getNumEvents()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					int result;
					oService.getMethod("int getNumEvents()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the event at the index value provided. The return type is a list containing {trigger, delay, {lValue_eventAssignment1, rValue_eventAssignment1}, {lValue_eventAssignment2, rValue_eventAssignment2}, ...} The index can vary from 0 to (numOfEvents-1). If the index exceeds the total number of events then the method throws an exception.
			//</summary>
			static DataBlockReader getNthEvent(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					DataBlockReader result;
					oService.getMethod("{} getNthEvent(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the 1 if the input string has a value and 0 otherwise. The input string can be a species name/Id, parameter name/Id, compartment name/Id.
			//</summary>
			static bool hasValue(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					bool result;
					oService.getMethod("boolean hasValue(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the description of the builtin funtion for the input string provided.
			//</summary>
			static vector< string > getBuiltinFunctionInfo(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					vector< string > result;
					oService.getMethod("string[] getBuiltinFunctionInfo(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of strings of all the builtin functions.
			//</summary>
			static vector< string > getBuiltinFunctions()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					vector< string > result;
					oService.getMethod("string[] getBuiltinFunctions()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Converts a MathML string to mathematical infix expression.
			//</summary>
			static string convertMathMLToString(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string convertMathMLToString(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Converts a mathematical infix expression to a MathML string.
			//</summary>
			static string convertStringToMathML(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string convertStringToMathML(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Converts a SBML level 1 document to level2 document.
			//</summary>
			static string convertLevel1ToLevel2Impl(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string convertLevel1ToLevel2Impl(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Converts a SBML level 2 document to level1 document.
			//</summary>
			static string convertLevel2ToLevel1Impl(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string convertLevel2ToLevel1Impl(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Converts a power tag to ^. The input is a valid sbml string. The output is also an sbml string with power expressions converted.
			//</summary>
			static string convertPowImpl(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.caltech.NOMClipboard");
					Service oService = oModule.findServiceByName("NOM");
					string result;
					oService.getMethod("string convertPowImpl(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
		};
}
#endif
