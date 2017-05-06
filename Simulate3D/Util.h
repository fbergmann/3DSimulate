#ifndef SIMULATE3D_UTIL_H
#define SIMULATE3D_UTIL_H

#include <string>

namespace simulate
{
	class Util
	{
	public:

		static std::string upperCase(std::string s);
		static std::string lowerCase(std::string s);
		static std::string getFullName(std::string sFile, std::string sBasePath);
		static std::string getPath(std::string sFile);
		static std::string getName(std::string sFile);
		static bool fileExists(const char* sFile);
		static double sign(double dValue);
		static double abs(double dValue);

		inline static std::string trim(const std::string& s) {
			if(s.length() == 0)
				return s;
			int b = s.find_first_not_of(" \t");
			int e = s.find_last_not_of(" \t");
			if(b == -1) // No non-spaces
				return "";
			return std::string(s, b, e - b + 1);
		}

	};
}



#endif
