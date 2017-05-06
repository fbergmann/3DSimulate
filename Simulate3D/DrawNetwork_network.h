#ifndef DRAWNETWORK_NETWORK_H
#define DRAWNETWORK_NETWORK_H

#include "SBW/SBW.h"

#include <string>
#include <vector>

using namespace std;
using namespace SystemsBiologyWorkbench;

namespace DrawNetwork 
{ 
	class network  
	{ 
	public: 
		network (){}

		//<summary>
		//none provided
		//</summary>
		static string getSBML()
		{
			try
			{
				DataBlockWriter oArguments;

				SBW::connect();
				Module oModule = SBW::getModuleInstance("DrawNetwork");
				Service oService = oModule.findServiceByName("network");
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
		//Loads an SBML file (level 1 or level 2) in order to generate a layout
		//</summary>
		static void doAnalysis(string  var0)
		{
			try
			{
				DataBlockWriter oArguments;
				oArguments.add(var0);

				SBW::connect();
				Module oModule = SBW::getModuleInstance("DrawNetwork");
				Service oService = oModule.findServiceByName("network");
				oService.getMethod("void doAnalysis(string)").call(oArguments);
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
