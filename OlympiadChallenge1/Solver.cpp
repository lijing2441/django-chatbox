#include <algorithm>
#include "Solver.h"

void Solver::findCode(const DataPacket& dataPacket, PassCode& passCode)
{
  int mins[dataPacket.NUM_STREAMS][4];
  int maxs[dataPacket.NUM_STREAMS][4];

  // For each stream
  for (int i = 0; i < dataPacket.NUM_STREAMS; ++i) {
    // Find the 4 min values in this stream
    std::partial_sort_copy(dataPacket.streams[i],
			   dataPacket.streams[i] + dataPacket.STREAM_SIZE,
			   mins[i], mins[i] + 4);

    // Find the 4 max values in this stream
    // Note: This can be done once for all streams, ie 1 dimensionally,
    // because it doesn't matter if they both come from the same stream.
    // It then becomes unneccessary to sort (or indeed create) the maxs array.
    std::partial_sort_copy(dataPacket.streams[i],
			   dataPacket.streams[i] + dataPacket.STREAM_SIZE,
			   maxs[i], maxs[i] + 4,
			   [](const int a, const int b) { return a > b; });
  }

  // Sort the min 2D array as a 1D array
  std::sort(reinterpret_cast<int*>(&mins),
	    reinterpret_cast<int*>(&mins) + (dataPacket.NUM_STREAMS * 4));

  // Sort the max 2D array as a 1D array (in descending order)
  std::sort(reinterpret_cast<int*>(&maxs),
	    reinterpret_cast<int*>(&maxs) + (dataPacket.NUM_STREAMS * 4),
	    [](const int a, const int b) { return a > b; });

  // Get the 5 min values
  passCode.digits[0] = reinterpret_cast<int*>(&mins)[0];
  passCode.digits[1] = reinterpret_cast<int*>(&mins)[1];
  passCode.digits[2] = reinterpret_cast<int*>(&mins)[2];
  passCode.digits[3] = reinterpret_cast<int*>(&mins)[3];
  passCode.digits[4] = reinterpret_cast<int*>(&mins)[4];

  // Get the 2 max values
  passCode.digits[5] = reinterpret_cast<int*>(&maxs)[1];
  passCode.digits[6] = reinterpret_cast<int*>(&maxs)[0];
}
