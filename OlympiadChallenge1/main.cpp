
///////////////////////////////////////////////////////////////////////////////
// Olympiad Challenge One : Code Breaker								     //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Timer.h"
#include "DataPacket.h"
#include "PassCode.h"
#include "Setup.h"
#include "Solver.h"

/**
 * Setup the packet using either random data or pre-generated data
 */
void doSetup(DataPacket &dataPacket, bool preGenerated)
{
	preGenerated ?
		Setup::applyPreGeneratedSetup(dataPacket) :
		Setup::applyRandomSetup(dataPacket);
}

/**
 * Extract the code from the data packet and return the ellapsed time
 */
double doWork(DataPacket &dataPacket)
{
	Solver solver;
	PassCode passCode;

	// Find the code and record the ellapsed time
	Timer timer = Timer();
	timer.Start();
	solver.findCode(dataPacket, passCode);
	timer.Stop();

	// Display the passcode on the console
	std::cout << "Code:";
	for(int idx = 0; idx < PassCode::NUM_DIGITS; idx++)
		std::cout << " " << passCode.digits[idx];
	std::cout << std::endl;

	return timer.Duration();
}

/**
 * Setup data packet and time the decode duration
 */
int main()
{
	DataPacket dataPacket;

	// Setup the data arrays with the necessary data
	doSetup(dataPacket, true);

	// Sort and arrays and determine smallest values
	double duration = doWork(dataPacket);

	// Display total execution time
	std::cout << "Duration = " << duration << "ms" << std::endl;

	// Pause before exiting
	system("pause");

	return 0;
}