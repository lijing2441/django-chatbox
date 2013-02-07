#pragma once

///////////////////////////////////////////////////////////////////////////////
// Millisecond Accurate Timer 											     //
///////////////////////////////////////////////////////////////////////////////

#include <Windows.h>

/**
 * Timer with ms accuracy. 
 */
class Timer
{
public:
	Timer() {};

	/**
	 * Start the timer
	 */
	inline void Start() {
		QueryPerformanceCounter(&startCycle);
	}

	/**
	 * Stop the timer
	 */
	inline void Stop() {
		QueryPerformanceCounter(&endCycle);
	}

	/**
	 * Return the number of ellapsed ms
	 */
	inline double Duration() {
		QueryPerformanceFrequency(&frequency);
		double cyclesPerMs = 1000.0 /  frequency.QuadPart;
		return (endCycle.QuadPart - startCycle.QuadPart) * cyclesPerMs;
	}

private:
	// Numeric values for the start and end cycle counts, alongside CPU frequency count
	LARGE_INTEGER startCycle;
	LARGE_INTEGER endCycle;

	// Numeric value for the CPU frequency count
	LARGE_INTEGER frequency;
};
