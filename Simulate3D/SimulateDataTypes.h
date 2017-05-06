#ifndef SIMULATE_DATA_TYPES
#define SIMULATE_DATA_TYPES

#include <vector>
#include <string>


namespace simulate
{
	struct SpeciesCoordinates
	{
		std::string			SpeciesName;
		std::vector<double>	Position;
		std::vector<double>	Dimension;
		std::vector<double>	Color;
		bool			IsBoundary;
		double			Concentration;
		double			BaseConcentration; // used for modifying the Concentration
		int				Index;
		float			z;
		bool			Dirty;
	};

	struct ReactionInfo
	{
		std::string		ID;
		double			RateOfChange;		
		double			Rate;
		double			LineWidth;
		std::vector<double>	Color;
		int				Index;
		bool			Dirty;
	};

	struct ParameterInfo
	{
		std::string     ID;
		double			Value;
	};

}

#endif
