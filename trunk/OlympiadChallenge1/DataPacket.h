#pragma once

///////////////////////////////////////////////////////////////////////////////
// Data Packet Definition													 //
///////////////////////////////////////////////////////////////////////////////

/**
 * Data packet - structure and size of a received packet of data
 *
 * Usage assumptions: A packet will comprise a number of streams of integer 
 * data arranged in order of stream.
 */
struct DataPacket
{
	static const int NUM_STREAMS = 5;
	static const int STREAM_SIZE =  100;

	int streams[NUM_STREAMS][STREAM_SIZE];
};