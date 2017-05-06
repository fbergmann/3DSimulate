#ifndef BROKER_BROKER_H
#define BROKER_BROKER_H
#include "SBW/SBW.h"

#include <string>
#include <vector>

using namespace std;
using namespace SystemsBiologyWorkbench;

namespace BROKER1
{ 
	class BROKER  
		{ 
		public: 
			BROKER (){}
			
			//<summary>
			//returns the version of the broker
			//</summary>
			static string getVersion()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
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
			//returns the module identifier of the given name, or starts up a new module
			//</summary>
			static int getModuleInstance(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					int result;
					oService.getMethod("int getModuleInstance(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns an array of module descriptors. The flags are localOnly (search only for local modules) and includeRunning (search also running modules)
			//</summary>
			static vector< DataBlockReader > getModuleDescriptors(bool  var0,bool  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					vector< DataBlockReader > result;
					oService.getMethod("{}[] getModuleDescriptors(boolean, boolean)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns the module descriptor for the module with the given name, if the flag is true running modules will also be included in the search, otherwise only registered modules
			//</summary>
			static DataBlockReader getModuleDescriptor(string  var0,bool  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					DataBlockReader result;
					oService.getMethod("{} getModuleDescriptor(string, boolean)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns the module descriptor for the module with the given id
			//</summary>
			static DataBlockReader getModuleDescriptor2(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					DataBlockReader result;
					oService.getMethod("{} getModuleDescriptor(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns an array of all services registered with a given category, the flag indicates whether services of subcategories should also be returned
			//</summary>
			static vector< DataBlockReader > findServices(string  var0,bool  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					vector< DataBlockReader > result;
					oService.getMethod("{}[] findServices(string, boolean)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns an array of subcategories of the given string. e.g.: '/' represents the root category and returns all subcategories.
			//</summary>
			static vector< string > getServiceCategories(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					vector< string > result;
					oService.getMethod("string[] getServiceCategories(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//links this broker to a remote broker ... the parameter is the hostname or hostaddress of the remote computer. A connection will be made to the same port as the local broker. A different port can be used by using <hostname or ip>/<port>
			//</summary>
			static int linkBroker(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					int result;
					oService.getMethod("int linkBroker(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns an array of currently running module id's
			//</summary>
			static vector< int > getExistingModuleInstanceIds()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					vector< int > result;
					oService.getMethod("int[] getExistingModuleInstanceIds()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns the service descriptor with the given module id and service name
			//</summary>
			static DataBlockReader getServiceDescriptor(int  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					DataBlockReader result;
					oService.getMethod("{} getServiceDescriptor(int, string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns the service descriptor with the given module id and service id
			//</summary>
			static DataBlockReader getServiceDescriptor2(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					DataBlockReader result;
					oService.getMethod("{} getServiceDescriptor(int, int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns the service descriptors of the module with the given name
			//</summary>
			static vector< DataBlockReader > getServiceDescriptors(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					vector< DataBlockReader > result;
					oService.getMethod("{}[] getServiceDescriptors(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns the service descriptors of the module with the given identifier
			//</summary>
			static vector< DataBlockReader > getServiceDescriptors2(int  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					vector< DataBlockReader > result;
					oService.getMethod("{}[] getServiceDescriptors(int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//registers a module with: moduleName, moduleDisplayName, moduleType, commandLine, help
			//</summary>
			static void registerModule(string  var0,string  var1,int  var2,string  var3,string  var4)
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
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					oService.getMethod("void registerModule(string, string, int, string, string)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//changes the module-name of the module with the given id to the new given name
			//</summary>
			static void changeModuleName(int  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					oService.getMethod("void changeModuleName(int, string)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//registers the service with: moduleName, serviceName, serviceDisplayName, category,help
			//</summary>
			static void registerService(string  var0,string  var1,string  var2,string  var3,string  var4)
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
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					oService.getMethod("void registerService(string, string, string, string, string)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//unregisters the module with the given name
			//</summary>
			static void unregisterModule(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					oService.getMethod("void unregisterModule(string)").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//shuts down the broker
			//</summary>
			static void shutdownBroker()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					oService.getMethod("void shutdownBroker()").call(oArguments);
					return;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns the ids and names of all currently running modules
			//</summary>
			static DataBlockReader getListOfModules()
			{
				try
				{
					DataBlockWriter oArguments;
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					DataBlockReader result;
					oService.getMethod("{} getListOfModules()").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns all method id's and names for the given module id and service id
			//</summary>
			static DataBlockReader getMethodIds(int  var0,int  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					DataBlockReader result;
					oService.getMethod("{} getMethodIds(int,int)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns all method id's and names for the given module name and service name
			//</summary>
			static DataBlockReader getMethodIds2(string  var0,string  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					DataBlockReader result;
					oService.getMethod("{} getMethodIds(string,string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//reads a file from the file system and returns a string containing the results. (file must be with absolute path)
			//</summary>
			static string readFromFile(string  var0)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					string result;
					oService.getMethod("string readFromFile(string)").call(oArguments) >> result;
					return result;
				}
				catch(SBWException *e)
				{
					throw e;
				}
				catch(...) {throw "unexpected exception";}
			}
			
			//<summary>
			//returns an array of all local services registered with a given category, the flag indicates whether services of subcategories should also be returned
			//</summary>
			static vector< DataBlockReader > findLocalServices(string  var0,bool  var1)
			{
				try
				{
					DataBlockWriter oArguments;
					oArguments.add(var0);
					oArguments.add(var1);
					
					SBW::connect();
					Module oModule = SBW::getModuleInstance("BROKER");
					Service oService = oModule.findServiceByName("BROKER");
					vector< DataBlockReader > result;
					oService.getMethod("{}[] findLocalServices(string, boolean)").call(oArguments) >> result;
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

