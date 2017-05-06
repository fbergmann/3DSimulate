#ifndef SIMULATION_THREAD_H
#define SIMULATION_THREAD_H

#include <SBW/portableOS.h>

namespace simulate
{
	class SimulationThread : public SystemsBiologyWorkbench::SBWThread
	{
	private:
		bool operational;
		static double _dTimeStart;
	public:
		SimulationThread() : SystemsBiologyWorkbench::SBWThread("")
		{
			
		}
		void setOperational(bool bIsOperational);

		void startThread(double dTimeStart);
		void continueThread();

		static void setTimeStart(double dStartTime);
		static double getTimeStart() { return _dTimeStart; };

		void stop();

		virtual void run();
		static bool _bUpdateSpecies;

	};
}

#endif
