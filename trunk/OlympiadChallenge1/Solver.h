#pragma once

///////////////////////////////////////////////////////////////////////////////
// Data Packet Passcode Solver 											     //
///////////////////////////////////////////////////////////////////////////////

#include "DataPacket.h"
#include "PassCode.h"

class Solver
{
public:
	/**
	 * Populate the specified pass code using the specified data packet.
	 *
	 * The pass code is determined as follows:
	 *	For each stream of data in the data packet 
	 *		Extract and accumulate the 4 smallest and 4 largest values
	 *  Populate the pass code using the 5 smallest and 2 largest accumulated values
	 */
	void findCode(const DataPacket& dataPacket, PassCode& passCode);
};
