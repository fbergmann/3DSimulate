#ifndef JARNAC_SIM_H
#define JARNAC_SIM_H

#include "SBW/sbw.h"

#include <string>
#include <vector>

using namespace std;
using namespace SystemsBiologyWorkbench;

namespace Jarnac
{
	class sim
	{
	public:
		sim (){}

		//<summary>
		//Returns the name of the module
		//</summary>
		static string getName()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getName()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the version number for this module
		//</summary>
		static string getVersion()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
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
		//Returns the name of the author who wrote the module
		//</summary>
		static string getAuthor()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getAuthor()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns a brief description of the module
		//</summary>
		static string getDescription()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getDescription()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns a string suitable for display to a user
		//</summary>
		static string getDisplayName()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getDisplayName()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the copyright notice, if any
		//</summary>
		static string getCopyright()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getCopyright()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the URL for the module (if any)
		//</summary>
		static string getURL()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getURL()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Load the sbml model contained in the string argument
		//</summary>
		static void loadSBML(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
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
		//Returns the current model as SBML, int arg is the level, 1 or 2
		//</summary>
		static string getSBML(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getSBML(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Load the Jarnac script model contained in the string argument
		//</summary>
		static void loadJarnac(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void loadJarnac(string)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Load the initial conditions vector with a new vector
		//</summary>
		static void changeInitialConditions (vector< double >  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void changeInitialConditions (double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Set the time start for the simulation
		//</summary>
		static void setTimeStart (double  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setTimeStart (double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Set the time end for the simulation
		//</summary>
		static void setTimeEnd (double  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setTimeEnd (double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Set the number of output data points
		//</summary>
		static void setNumPoints (int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setNumPoints (int)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the list of variables to return when calling simulate(), eg setSelectionList(handle, {'Time', 'S1', 'J0'
		//</summary>
		static void setSelectionList (DataBlockReader  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setSelectionList ({})").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Reset the model to it's initial conditions
		//</summary>
		static void reset ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void reset ()").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Carry out one step in the simulation. The method takes two arguments, the current time and the step size to use in the next integration step. The method returns the time at the new point. Usage: t = oneStep (t, 0.1)
		//</summary>
		static double oneStep (double  var0,double  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double oneStep (double, double)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Carry out a simulation using a stiff ODE itegrator
		//</summary>
		static DataBlockReader  simulate()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] simulate()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//simulate (timeStart, timeEnd, numPoints)
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
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] simulateEx(double, double, int)").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets all the floating species concentrations
		//</summary>
		static void setFloatingSpeciesConcentrations(vector< double >  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setFloatingSpeciesConcentrations(double[])").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the value of a floating species by it index value in the species array
		//</summary>
		static void setFloatingSpeciesByIndex(int  var0,double  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setFloatingSpeciesByIndex(int, double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the value of a floating species by it index value in the species array
		//</summary>
		static void setBoundarySpeciesByIndex(int  var0,double  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setBoundarySpeciesByIndex(int, double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the concentration of floating species i
		//</summary>
		static double getFloatingSpeciesByIndex(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getFloatingSpeciesByIndex(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the concentration of boundary species i
		//</summary>
		static double getBoundarySpeciesByIndex(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getBoundarySpeciesByIndex(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the value of a parameter by it index value in the parameter array
		//</summary>
		static void setParameterByIndex(int  var0,double  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setParameterByIndex(int, double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the reaction rates as a vector
		//</summary>
		static vector< double > getReactionRates()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getReactionRates()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get a particular reaction rate (ithReaction)
		//</summary>
		static double getReactionRate(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getReactionRate(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the rates of change as a vector
		//</summary>
		static vector< double > getRatesOfChange()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getRatesOfChange()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get rates of change given the floating species vector
		//</summary>
		static vector< double > getRatesOfChangeEx (vector< double >  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getRatesOfChangeEx (double[])").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of floating species names
		//</summary>
		static DataBlockReader getFloatingSpeciesNames()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getFloatingSpeciesNames()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of floating species names
		//</summary>
		static DataBlockReader getSpeciesNames()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getSpeciesNames()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get an array of floating species values
		//</summary>
		static vector< double > getFloatingSpeciesConcentrations()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getFloatingSpeciesConcentrations()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get an array of floating species values
		//</summary>
		static vector< double > getSpeciesValues()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getSpeciesValues()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of reaction names
		//</summary>
		static DataBlockReader getReactionNames()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getReactionNames()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of boundary species values
		//</summary>
		static vector< double > getBoundarySpeciesConcentrations()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getBoundarySpeciesConcentrations()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of boundary species names
		//</summary>
		static DataBlockReader getBoundarySpeciesNames()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getBoundarySpeciesNames()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of parameters in the model
		//</summary>
		static DataBlockReader getAllLocalParameterNames()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getAllLocalParameterNames()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of local parameter values in the model
		//</summary>
		static vector< double > getAllLocalParameterValues()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getAllLocalParameterValues()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of parameter names for reaction Id
		//</summary>
		static DataBlockReader getLocalParameterNames(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getLocalParameterNames(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of local parameter values in the model for reaction Id
		//</summary>
		static vector< double > getLocalParameterValues(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getLocalParameterValues(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Set a local parameter of reaction Id and parameter Id
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
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setLocalParameterByIndex(int, int, double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get value of local parameter of reaction Id and parameter Id
		//</summary>
		static double getLocalParameterByIndex(int  var0,int  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getLocalParameterByIndex(int, int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the list of global parameter
		//</summary>
		static DataBlockReader getGlobalParameterNames()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getGlobalParameterNames()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the array of global parameters, returns zero in Jarnac
		//</summary>
		static vector< double > getGlobalParameterValues()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				vector< double > result;
				oService.getMethod("double[] getGlobalParameterValues()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Non-functional method, not applicable to Jarnac's internal model
		//</summary>
		static void setGlobalParameterByIndex (int  var0,double  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setGlobalParameterByIndex (int, double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Non-functional method, not applicable to Jarnac's internal model
		//</summary>
		static double getGlobalParameterByIndex (int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getGlobalParameterByIndex (int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the ith floating species name
		//</summary>
		static string getFloatingSpeciesName(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getFloatingSpeciesName(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the ith boundary species name
		//</summary>
		static string getBoundarySpeciesName(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getBoundarySpeciesName(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of reaction in the current model
		//</summary>
		static int getNumReactions()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumReactions()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of reaction in the current model
		//</summary>
		static int getNumberOfReactions()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumberOfReactions()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the number of compartments in the current model
		//</summary>
		static int getNumberOfCompartments()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumberOfCompartments()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Compute the steady state, returns the sum fo squares indicating the quality of the solution
		//</summary>
		static double steadyState()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double steadyState()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the current reduced jacobian matrix. This call will return the reduced matrix, that is dependent species have been removed
		//</summary>
		static DataBlockReader  getReducedJacobian()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getReducedJacobian()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the current reduced jacobian matrix. This call will return the reduced matrix, that is dependent species have been removed
		//</summary>
		static DataBlockReader  getJacobian()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getJacobian()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the current full jacobian matrix.
		//</summary>
		static DataBlockReader  getFullJacobian()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getFullJacobian()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the model as a list of ODE equation strings
		//</summary>
		static DataBlockReader getODEList ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getODEList ()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the models' list of rate laws
		//</summary>
		static DataBlockReader getRateLawList ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getRateLawList ()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the conservation law array
		//</summary>
		static DataBlockReader  getConservationLawArray ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getConservationLawArray ()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Updates the dependent species in the model
		//</summary>
		static void updateDependentSpecies ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void updateDependentSpecies ()").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the stoichiometry matrix
		//</summary>
		static DataBlockReader  getStoichiometryMatrix ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getStoichiometryMatrix ()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the reduced stoichiometry matrix
		//</summary>
		static DataBlockReader  getNrMatrix ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getNrMatrix ()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the link matrix
		//</summary>
		static DataBlockReader  getLinkMatrix ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getLinkMatrix ()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the matrix of unscaled elasticities
		//</summary>
		static DataBlockReader  getUnScaledElasticityMatrix ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] getUnScaledElasticityMatrix ()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the simulators' capabilities
		//</summary>
		static string getCapabilities ()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string getCapabilities ()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the number of local parameters in the model
		//</summary>
		static int getNumLocalParameters()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumLocalParameters()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the number of local parameters in a particular reaction
		//</summary>
		static int getNumberOfLocalParameters(int  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumberOfLocalParameters(int)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Will always return zero in Jarnac
		//</summary>
		static int getNumberofGlobalParameters()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumberofGlobalParameters()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the number of floating species
		//</summary>
		static int getNumFloatingSpecies()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumFloatingSpecies()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
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
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumberOfFloatingSpecies()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the number of boundary species
		//</summary>
		static int getNumBoundarySpecies()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumBoundarySpecies()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
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
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumberOfBoundarySpecies()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Return the number of independent species
		//</summary>
		static int getNumIndependentSpecies()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumIndependentSpecies()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Return the number of dependent species
		//</summary>
		static int getNumDependentSpecies()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				int result;
				oService.getMethod("int getNumDependentSpecies()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the current state of the model, arg1 = time, arg2 = variable array, arg3 = parameter array
		//</summary>
		static DataBlockReader  evalModel(double  var0,vector< double >  var1,vector< double >  var2)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);
				oArguments.add(var2);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] evalModel(double, double[], double[])").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the scaled control coefficient
		//</summary>
		static double getCC (string  var0,string  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getCC (string, string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the unscaled control coefficient
		//</summary>
		static double getuCC (string  var0,string  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getuCC (string, string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the scaled elasticity coefficient
		//</summary>
		static double getEE (string  var0,string  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getEE (string, string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the unscaled elasticity coefficient
		//</summary>
		static double getuEE (string  var0,string  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getuEE (string, string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Carry out a simulation using the Gillespie method
		//</summary>
		static DataBlockReader  gillespie()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				return oService.getMethod("double[][] gillespie()").call(oArguments);}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Set the value of the named symbol, eg setValue (\"ATP\", 1.2\")
		//</summary>
		static void setValue(string  var0,double  var1)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);
				oArguments.add(var1);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setValue(string, double)").call(oArguments);
				return;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Get the value of the named symbol, eg x = getValue (\"ATP\")
		//</summary>
		static double getValue(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				double result;
				oService.getMethod("double getValue(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//evaluate a Jarnac script, eg eval (\"print sin (30)\")
		//</summary>
		static string eval(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				string result;
				oService.getMethod("string eval(string)").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Returns the list simulator names
		//</summary>
		static DataBlockReader getIntegrationMethodList()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				DataBlockReader result;
				oService.getMethod("{} getIntegrationMethodList()").call(oArguments) >> result;
				return result;
			}
			catch(SBWException *e)
			{
				throw e;
			}
			catch(...) {}
		}

		//<summary>
		//Sets the integration method
		//</summary>
		static void setIntegrationMethod(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("Jarnac");
				Service oService = oModule.findServiceByName("sim");
				oService.getMethod("void setIntegrationMethod(string)").call(oArguments);
				return;
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
