#ifndef EDU_KGI_ROADRUNNER_SIM_H
#define EDU_KGI_ROADRUNNER_SIM_H

#include "SBW/sbw.h"

#include <string>
#include <vector>

using namespace std;
using namespace SystemsBiologyWorkbench;

namespace edu_kgi_roadRunner 
{ 
	class sim  
		{ 
		public: 
			sim (){}
			
			//<summary>
			//Returns the name of module
			//</summary>
			static string getName()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getName()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the version number of the module
			//</summary>
			static string getVersion()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getVersion()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the name of the module author
			//</summary>
			static string getAuthor()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getAuthor()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a description of the module
			//</summary>
			static string getDescription()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getDescription()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the display name of the module
			//</summary>
			static string getDisplayName()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getDisplayName()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the copyright string for the module
			//</summary>
			static string getCopyright()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getCopyright()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the URL string associated with the module (if any)
			//</summary>
			static string getURL()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getURL()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the current generated source code
			//</summary>
			static string getCSharpCode()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getCSharpCode()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Load SBML into simulator
			//</summary>
			static void loadSBML(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
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
			//Returns the currently loaded model as SBML
			//</summary>
			static string getSBML()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getSBML()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the time start for the simulation
			//</summary>
			static void setTimeStart(double  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setTimeStart(double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the time end for the simulation
			//</summary>
			static void setTimeEnd(double  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setTimeEnd(double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the number of points to generate during the simulation
			//</summary>
			static void setNumPoints(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setNumPoints(int)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//reset the simulator back to the initial conditions specified in the SBML model
			//</summary>
			static void reset()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void reset()").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Change the initial conditions to another concentration vector
			//</summary>
			static void changeInitialConditions(vector< double >  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void changeInitialConditions(double[])").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Carry out a time course simulation
			//</summary>
			static DataBlockReader  simulate()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] simulate()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Extension method to simulate (time start, time end, number of points). This routine resets the model to its initial condition before running the simulation (unlike simulate())
			//</summary>
			static DataBlockReader  simulateEx(double  var0,double  var1,int  var2)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					oArguments.add(var2);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] simulateEx(double,double,int)").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the current vector of reactions rates
			//</summary>
			static vector< double > getReactionRates()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getReactionRates()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the current vector of rates of change
			//</summary>
			static vector< double > getRatesOfChange()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getRatesOfChange()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of floating species names: This method is deprecated, please use getFloatingSpeciesNames()
			//</summary>
			static DataBlockReader getSpeciesNames()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getSpeciesNames()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of reaction names
			//</summary>
			static DataBlockReader getReactionNames()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getReactionNames()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get Simulator Capabilities
			//</summary>
			static string getCapabilities()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					string result;
					oService.getMethod("string getCapabilities()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set Simulator Capabilites
			//</summary>
			static void setCapabilities(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setCapabilities(string)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the number of compartments
			//</summary>
			static int getNumberOfCompartments()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfCompartments()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Sets the value of a compartment by its index
			//</summary>
			static void setCompartmentByIndex(int  var0,double  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setCompartmentByIndex(int,double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the value of a compartment by its index
			//</summary>
			static double getCompartmentByIndex(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getCompartmentByIndex(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the value of a compartment by its index
			//</summary>
			static void setCompartmentVolumes(vector< double >  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setCompartmentVolumes(double[])").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Gets the list of compartment names
			//</summary>
			static DataBlockReader getCompartmentNames()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getCompartmentNames()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the number of boundary species
			//</summary>
			static int getNumberOfBoundarySpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfBoundarySpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Sets the value of a boundary species by its index
			//</summary>
			static void setBoundarySpeciesByIndex(int  var0,double  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setBoundarySpeciesByIndex(int,double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the value of a boundary species by its index
			//</summary>
			static double getBoundarySpeciesByIndex(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getBoundarySpeciesByIndex(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns an array of boundary species concentrations
			//</summary>
			static vector< double > getBoundarySpeciesConcentrations()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getBoundarySpeciesConcentrations()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the concentrations for all boundary species in the model
			//</summary>
			static void setBoundarySpeciesConcentrations(vector< double >  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setBoundarySpeciesConcentrations(double[])").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Gets the list of boundary species names
			//</summary>
			static DataBlockReader getBoundarySpeciesNames()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getBoundarySpeciesNames()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the number of floating species
			//</summary>
			static int getNumberOfFloatingSpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfFloatingSpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Sets the value of a floating species by its index
			//</summary>
			static void setFloatingSpeciesByIndex(int  var0,double  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setFloatingSpeciesByIndex(int,double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the value of a floating species by its index
			//</summary>
			static double getFloatingSpeciesByIndex(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getFloatingSpeciesByIndex(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns an array of floating species concentrations
			//</summary>
			static vector< double > getFloatingSpeciesConcentrations()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getFloatingSpeciesConcentrations()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the concentrations for all floating species in the model
			//</summary>
			static void setFloatingSpeciesConcentrations(vector< double >  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setFloatingSpeciesConcentrations(double[])").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of floating species names
			//</summary>
			static DataBlockReader getFloatingSpeciesNames()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getFloatingSpeciesNames()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the number of global parameters
			//</summary>
			static int getNumberOfGlobalParameters()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfGlobalParameters()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Sets the value of a global parameter by its index
			//</summary>
			static void setGlobalParameterByIndex(int  var0,double  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setGlobalParameterByIndex(int,double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the value of a global parameter by its index
			//</summary>
			static double getGlobalParameterByIndex(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getGlobalParameterByIndex(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the values for all global parameters in the model
			//</summary>
			static void setGlobalParameterValues(vector< double >  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setGlobalParameterValues(double[])").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the values for all global parameters in the model
			//</summary>
			static vector< double > getGlobalParameterValues()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getGlobalParameterValues()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Gets the list of parameter names
			//</summary>
			static DataBlockReader getGlobalParameterNames()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getGlobalParameterNames()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Sets the value of the given species or global parameter to the given value (not of local parameters)
			//</summary>
			static void setValue(string  var0,double  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setValue(string,double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Gets the Value of the given species or global parameter (not of local parameters)
			//</summary>
			static double getValue(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
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
			//Returns a list of global parameter tuples: { {parameter Name, value},...
			//</summary>
			static DataBlockReader getAllGlobalParameterTupleList()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getAllGlobalParameterTupleList()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the number of local parameters for a given reaction
			//</summary>
			static int getNumberOfLocalParameters(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfLocalParameters(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Sets the value of a global parameter by its index
			//</summary>
			static void setLocalParameterByIndex(int  var0,int  var1,double  var2)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					oArguments.add(var2);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setLocalParameterByIndex(int,int,double)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the value of a global parameter by its index
			//</summary>
			static double getLocalParameterByIndex(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getLocalParameterByIndex(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the values for all global parameters in the model
			//</summary>
			static void setLocalParameterValues(int  var0,vector< double >  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setLocalParameterValues(int,double[])").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the values for all global parameters in the model
			//</summary>
			static vector< double > getLocalParameterValues(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getLocalParameterValues(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Gets the list of parameter names
			//</summary>
			static DataBlockReader getLocalParameterNames(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getLocalParameterNames(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns a list of global parameter tuples: { {parameter Name, value},...
			//</summary>
			static DataBlockReader getAllLocalParameterTupleList()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getAllLocalParameterTupleList()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get the number of reactions
			//</summary>
			static int getNumberOfReactions()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfReactions()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the rate of a reaction by its index
			//</summary>
			static double getReactionRate(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getReactionRate(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the rate of changes of a species by its index
			//</summary>
			static double getRateOfChange(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getRateOfChange(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the names given to the rate of change of the floating species
			//</summary>
			static DataBlockReader getRateOfChangeNames()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					DataBlockReader result;
					oService.getMethod("{} getRateOfChangeNames()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Set the columns to be returned by simulate() or simulateEx(), valid symbol names include time, species names, , volume, reaction rates and rates of change (speciesName')
			//</summary>
			static void setSelectionList(DataBlockReader  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void setSelectionList({})").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the rates of changes given an array of new floating species concentrations
			//</summary>
			static vector< double > getRatesOfChangeEx(vector< double >  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getRatesOfChangeEx(double[])").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the rates of changes given an array of new floating species concentrations
			//</summary>
			static vector< double > getReactionRatesEx(vector< double >  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					vector< double > result;
					oService.getMethod("double[] getReactionRatesEx(double[])").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Carry out a single integration step using a stepsize as indicated in the method call
			//</summary>
			static double oneStep(double  var0,double  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double oneStep(double,double)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the steady state of the model, returns the sum of squares of the solution
			//</summary>
			static double steadyState()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double steadyState()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the reduced Jacobian at the current operating point
			//</summary>
			static DataBlockReader  getReducedJacobian()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getReducedJacobian()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the full Jacobian at the current operating point
			//</summary>
			static DataBlockReader  getFullJacobian()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getFullJacobian()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the Link Matrix for the currently loaded model
			//</summary>
			static DataBlockReader  getLinkMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getLinkMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the reduced stoichiometry matrix (Nr) for the currently loaded model
			//</summary>
			static DataBlockReader  getNrMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getNrMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the L0 matrix for the currently loaded model
			//</summary>
			static DataBlockReader  getL0Matrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getL0Matrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the stoichiometry matrix for the currently loaded model
			//</summary>
			static DataBlockReader  getStoichiometryMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getStoichiometryMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the conservation matrix (gamma) for the currently loaded model
			//</summary>
			static DataBlockReader  getConservationMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getConservationMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of dependent species in the model
			//</summary>
			static int getNumberOfDependentSpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfDependentSpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the number of independent species in the model
			//</summary>
			static int getNumberOfIndependentSpecies()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					int result;
					oService.getMethod("int getNumberOfIndependentSpecies()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Returns the elasticity of a given reaction to a given parameter. Parameters can be boundary species or global parameters
			//</summary>
			static double getUnScaledElasticity(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getUnScaledElasticity(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the unscaled species elasticity matrix at the current operating point
			//</summary>
			static DataBlockReader  getUnscaledElasticityMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getUnscaledElasticityMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the unscaled elasticity matrix at the current operating point
			//</summary>
			static DataBlockReader  getScaledElasticityMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getScaledElasticityMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the unscaled elasticity for a given reaction and given species
			//</summary>
			static double getUnscaledFloatingSpeciesElasticity(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getUnscaledFloatingSpeciesElasticity(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the scaled elasticity for a given reaction and given species
			//</summary>
			static double getScaledFloatingSpeciesElasticity(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getScaledFloatingSpeciesElasticity(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the matrix of unscaled concentration control coefficients
			//</summary>
			static DataBlockReader  getUnscaledConcentrationControlCoefficientMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getUnscaledConcentrationControlCoefficientMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the matrix of scaled concentration control coefficients
			//</summary>
			static DataBlockReader  getScaledConcentrationControlCoefficientMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getScaledConcentrationControlCoefficientMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the matrix of unscaled flux control coefficients
			//</summary>
			static DataBlockReader  getUnscaledFluxControlCoefficientMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getUnscaledFluxControlCoefficientMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the matrix of scaled flux control coefficients
			//</summary>
			static DataBlockReader  getScaledFluxControlCoefficientMatrix()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getScaledFluxControlCoefficientMatrix()").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular unscaled concentration control coefficients with respect to a local parameter
			//</summary>
			static double getUnscaledConcentrationControlCoefficient(string  var0,string  var1,string  var2)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					oArguments.add(var2);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getUnscaledConcentrationControlCoefficient(string,string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular scaled concentration control coefficients with respect to a local parameter
			//</summary>
			static double getScaledConcentrationControlCoefficient(string  var0,string  var1,string  var2)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					oArguments.add(var2);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getScaledConcentrationControlCoefficient(string,string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular concentration control coefficient, permitted parameters include global parameters, boundary conditions and conservation totals
			//</summary>
			static double getUnscaledConcentrationControlCoefficient2(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getUnscaledConcentrationControlCoefficient(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular scaled concentration control coefficients with respect to a global or boundary species parameter
			//</summary>
			static double getScaledConcentrationControlCoefficient2(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getScaledConcentrationControlCoefficient(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular unscaled flux control coefficients with respect to a local parameter
			//</summary>
			static double getUnscaledFluxControlCoefficient(string  var0,string  var1,string  var2)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					oArguments.add(var2);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getUnscaledFluxControlCoefficient(string,string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular flux control coefficient, permitted parameters include global parameters, boundary conditions and conservation totals
			//</summary>
			static double getUnscaledFluxControlCoefficient2(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getUnscaledFluxControlCoefficient(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular scaled flux control coefficients with respect to a local parameter
			//</summary>
			static double getScaledFluxControlCoefficient(string  var0,string  var1,string  var2)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					oArguments.add(var2);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getScaledFluxControlCoefficient(string,string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the value for a particular scaled flux control coefficients with respect to a global or boundary species parameter
			//</summary>
			static double getScaledFluxControlCoefficient2(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getScaledFluxControlCoefficient(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get unscaled control coefficient with respect to a global parameter
			//</summary>
			static double getuCC(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getuCC(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get scaled control coefficient with respect to a global parameter
			//</summary>
			static double getCC(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getCC(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get unscaled elasticity coefficient with respect to a global parameter or species
			//</summary>
			static double getuEE(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getuEE(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Get scaled elasticity coefficient with respect to a global parameter or species
			//</summary>
			static double getEE(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					double result;
					oService.getMethod("double getEE(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Compute the frequency response, startW, Number Of Decades, Number of Points, parameterName, variableName
			//</summary>
			static DataBlockReader  getFrequencyResponse(double  var0,int  var1,int  var2,string  var3,string  var4,bool  var5,bool  var6)
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
					oArguments.add(var6);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getFrequencyResponse(double,int,int,string,string,boolean,boolean)").call(oArguments);}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//Derpar Continuation, stepSize = stepsize; independentVariable = index to parameter; parameterType = {'globalParameter', 'boundarySpecies'
			//</summary>
			static void computeContinuation(double  var0,int  var1,string  var2)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					oArguments.add(var2);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("edu.kgi.roadRunner");
					Service oService = oModule.findServiceByName("sim");
					oService.getMethod("void computeContinuation(double,int,string)").call(oArguments);
					return;
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
