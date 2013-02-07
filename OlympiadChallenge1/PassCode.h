#pragma once

///////////////////////////////////////////////////////////////////////////////
// Pass Code Definition													     //
///////////////////////////////////////////////////////////////////////////////

/**
 * Pass code format - a sequence of ints defining a passcode. 
 *
 * Usage assumptions: The passcode will be ordered by value from smallest 
 * to largest, e.g. 1 2 6 12 42 655 902. 
 */
struct PassCode
{
	static const int NUM_DIGITS = 7;

	int digits[NUM_DIGITS];
};