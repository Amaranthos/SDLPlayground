#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

namespace Game {
	class Timer {
	public:
		Timer();
		
		void Start();
		void Stop();
		void Pause();
		void Unpause();

		Uint32 GetTicks();

		bool IsStarted() { return isStarted; }
		bool IsPaused() { return isStarted && isPaused; }

	private:
		Uint32 startTicks;
		Uint32 pausedTicks;

		bool isStarted;
		bool isPaused;
	};
	//wdith
}
#endif //TIMER_H
