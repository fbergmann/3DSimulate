#ifndef SIMULATE3D_ARGUMENTS_H
#define SIMULATE3D_ARGUMENTS_H

#include <string>

namespace simulate
{
	class Simulate3DArgumentParser
		{
		public:
			Simulate3DArgumentParser(int argc, char* argv[]);
			Simulate3DArgumentParser () : _bUseWhite(false), _bRenderReactions(false), 
			_sModelFile(""), _sTextureFile(""), _sDataFile(""), _sConfigFile("") {}
			
			
			inline bool			hasModelFile()						{ return _sModelFile != ""; }
			inline std::string	getModelFile()						{ return _sModelFile; }
			inline void			setModelFile(std::string sFile)		{ _sModelFile = sFile; }
			
			inline bool			hasTextureFile()					{ return _sTextureFile != ""; }
			inline std::string	getTextureFile()					{ return _sTextureFile; }
			inline void			setTextureFile(std::string sFile)	{ _sTextureFile = sFile; }
			
			inline bool			hasDataFile()						{ return _sDataFile != ""; }
			inline std::string	getDataFile()						{ return _sDataFile; }
			inline void			setDataFile(std::string sFile)		{ _sDataFile = sFile; }
			
			inline bool			hasConfigFile()						{ return _sConfigFile != ""; }
			inline std::string	getConfigFile()						{ return _sConfigFile; }
			inline void			setConfigFile(std::string sFile)	{ _sConfigFile = sFile; }
			
			inline bool			useWhite()							{ return _bUseWhite; }
			inline void			setUseWhite(bool bValue)			{ _bUseWhite = bValue; }
			
			inline bool			renderReactions()					{ return _bRenderReactions; };
			inline void			setRenderReactions(bool bValue)		{ _bRenderReactions = bValue; };
			
			static std::string getUsage(const char* argv0);
			
			static Simulate3DArgumentParser getDefaultArgsModel(std::string sFileName)
			{
				Simulate3DArgumentParser oResult;
				oResult.setModelFile(sFileName);
				oResult.setRenderReactions(true);
				return oResult;
			}
			
			static Simulate3DArgumentParser getDefaultArgsConfig(std::string sFileName)
			{
				Simulate3DArgumentParser oResult;
				oResult.setConfigFile(sFileName);
				oResult.setRenderReactions(false);
				return oResult;
			}
			
			
		private:
			
			bool _bUseWhite;
			bool _bRenderReactions;
			
			std::string _sModelFile;
			std::string _sTextureFile;
			std::string _sDataFile;
			std::string _sConfigFile;
		};
}


#endif
