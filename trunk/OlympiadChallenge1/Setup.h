#pragma once

///////////////////////////////////////////////////////////////////////////////
// Packet Setup Utilities 												     //
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <time.h>

#include "DataPacket.h"

/**
 * Collection of static utilities that provide randomised or predetermine 
 * data packet population.
 */
class Setup
{
public:

	/**
     * Populate all streams within the packet with random integer data
	 * bounded in the range 1 to 100.
	 */
	static void applyRandomSetup(DataPacket& dataPacket)
	{
		// Ensure a randomised sequence
		srand ( time(NULL) ); 
		
		// Populate each stream
		for(int streamIdx = 0; streamIdx < dataPacket.NUM_STREAMS; streamIdx ++)
			populateArrayWithRandomInts(
				dataPacket.streams[streamIdx], dataPacket.STREAM_SIZE);
	}

	/**
	 * Populate data streams with a predetermined collection of data to 
	 * permit algorithm reliability testing. Different setups can be selected
	 * through the version parameter.
	 *
	 * Usage assumptions: The data packet will comprise 5 streams of size 100 	 
	 *
	 * Current supported pregenerated sequence passcodes are:
	 * version = 1 : Pass code = 1 2 3 5 6 197 210
	 *
	 */
	static void applyPreGeneratedSetup(DataPacket &dataPacket, int version = 1)
	{
		static_assert(DataPacket::NUM_STREAMS == 5, "Unsupported number of streams");
		static_assert(DataPacket::STREAM_SIZE == 100, "Unsupported stream size");

		switch( version)
		{
		case 1:
		default:
			populateArrayWithPreGeneratedData1(dataPacket);
			break;
		}
	}

private:
	static void populateArrayWithRandomInts(int* ptrArray, const int arraySize)
	{
		int count = 0;
		while( count++ < arraySize )
			*ptrArray++ = rand() % 100 + 1;
	}

	static void populateArrayWithPreGeneratedData1(DataPacket& dataPacket)
	{
		// This sequence has a pass code of 1 2 3 5 6 197 210

		// Stream 0 data
		dataPacket.streams[0][0]  = 42;
		dataPacket.streams[0][1]  = 39;
		dataPacket.streams[0][2]  = 28;
		dataPacket.streams[0][3]  = 44;
		dataPacket.streams[0][4]  = 29;
		dataPacket.streams[0][5]  = 80;
		dataPacket.streams[0][6]  = 87;
		dataPacket.streams[0][7]  = 71;
		dataPacket.streams[0][8]  = 59;
		dataPacket.streams[0][9]  = 35;
		dataPacket.streams[0][10] = 47;
		dataPacket.streams[0][11] = 53;
		dataPacket.streams[0][12] = 46;
		dataPacket.streams[0][13] = 68;
		dataPacket.streams[0][14] = 70;
		dataPacket.streams[0][15] = 94;
		dataPacket.streams[0][16] = 68;
		dataPacket.streams[0][17] = 42;
		dataPacket.streams[0][18] = 56;
		dataPacket.streams[0][19] = 52;
		dataPacket.streams[0][20] = 5;
		dataPacket.streams[0][21] = 78;
		dataPacket.streams[0][22] = 49;
		dataPacket.streams[0][23] = 18;
		dataPacket.streams[0][24] = 45;
		dataPacket.streams[0][25] = 58;
		dataPacket.streams[0][26] = 99;
		dataPacket.streams[0][27] = 29;
		dataPacket.streams[0][28] = 36;
		dataPacket.streams[0][29] = 70;
		dataPacket.streams[0][30] = 94;
		dataPacket.streams[0][31] = 66;
		dataPacket.streams[0][32] = 87;
		dataPacket.streams[0][33] = 72;
		dataPacket.streams[0][34] = 140;
		dataPacket.streams[0][35] = 58;
		dataPacket.streams[0][36] = 22;
		dataPacket.streams[0][37] = 31;
		dataPacket.streams[0][38] = 93;
		dataPacket.streams[0][39] = 30;
		dataPacket.streams[0][40] = 109;
		dataPacket.streams[0][41] = 74;
		dataPacket.streams[0][42] = 22;
		dataPacket.streams[0][43] = 61;
		dataPacket.streams[0][44] = 60;
		dataPacket.streams[0][45] = 23;
		dataPacket.streams[0][46] = 41;
		dataPacket.streams[0][47] = 50;
		dataPacket.streams[0][48] = 35;
		dataPacket.streams[0][49] = 75;
		dataPacket.streams[0][50] = 24;
		dataPacket.streams[0][51] = 50;
		dataPacket.streams[0][52] = 78;
		dataPacket.streams[0][53] = 55;
		dataPacket.streams[0][54] = 85;
		dataPacket.streams[0][55] = 35;
		dataPacket.streams[0][56] = 41;
		dataPacket.streams[0][57] = 33;
		dataPacket.streams[0][58] = 17;
		dataPacket.streams[0][59] = 66;
		dataPacket.streams[0][60] = 52;
		dataPacket.streams[0][61] = 88;
		dataPacket.streams[0][62] = 40;
		dataPacket.streams[0][63] = 90;
		dataPacket.streams[0][64] = 91;
		dataPacket.streams[0][65] = 15;
		dataPacket.streams[0][66] = 54;
		dataPacket.streams[0][67] = 65;
		dataPacket.streams[0][68] = 84;
		dataPacket.streams[0][69] = 40;
		dataPacket.streams[0][70] = 25;
		dataPacket.streams[0][71] = 67;
		dataPacket.streams[0][72] = 33;
		dataPacket.streams[0][73] = 54;
		dataPacket.streams[0][74] = 48;
		dataPacket.streams[0][75] = 32;
		dataPacket.streams[0][76] = 35;
		dataPacket.streams[0][77] = 78;
		dataPacket.streams[0][78] = 48;
		dataPacket.streams[0][79] = 87;
		dataPacket.streams[0][80] = 87;
		dataPacket.streams[0][81] = 85;
		dataPacket.streams[0][82] = 20;
		dataPacket.streams[0][83] = 55;
		dataPacket.streams[0][84] = 60;
		dataPacket.streams[0][85] = 73;
		dataPacket.streams[0][86] = 75;
		dataPacket.streams[0][87] = 74;
		dataPacket.streams[0][88] = 69;
		dataPacket.streams[0][89] = 74;
		dataPacket.streams[0][90] = 7;
		dataPacket.streams[0][91] = 34;
		dataPacket.streams[0][92] = 41;
		dataPacket.streams[0][93] = 65;
		dataPacket.streams[0][94] = 49;
		dataPacket.streams[0][95] = 78;
		dataPacket.streams[0][96] = 76;
		dataPacket.streams[0][97] = 18;
		dataPacket.streams[0][98] = 17;
		dataPacket.streams[0][99] = 42;

		// Stream 1 data
		dataPacket.streams[1][0]  = 36;
		dataPacket.streams[1][1]  = 71;
		dataPacket.streams[1][2]  = 55;
		dataPacket.streams[1][3]  = 98;
		dataPacket.streams[1][4]  = 96;
		dataPacket.streams[1][5]  = 88;
		dataPacket.streams[1][6]  = 83;
		dataPacket.streams[1][7]  = 83;
		dataPacket.streams[1][8]  = 2;
		dataPacket.streams[1][9]  = 36;
		dataPacket.streams[1][10] = 70;
		dataPacket.streams[1][11] = 57;
		dataPacket.streams[1][12] = 93;
		dataPacket.streams[1][13] = 72;
		dataPacket.streams[1][14] = 38;
		dataPacket.streams[1][15] = 41;
		dataPacket.streams[1][16] = 45;
		dataPacket.streams[1][17] = 38;
		dataPacket.streams[1][18] = 34;
		dataPacket.streams[1][19] = 20;
		dataPacket.streams[1][20] = 26;
		dataPacket.streams[1][21] = 85;
		dataPacket.streams[1][22] = 19;
		dataPacket.streams[1][23] = 34;
		dataPacket.streams[1][24] = 3;
		dataPacket.streams[1][25] = 63;
		dataPacket.streams[1][26] = 27;
		dataPacket.streams[1][27] = 39;
		dataPacket.streams[1][28] = 80;
		dataPacket.streams[1][29] = 67;
		dataPacket.streams[1][30] = 78;
		dataPacket.streams[1][31] = 60;
		dataPacket.streams[1][32] = 60;
		dataPacket.streams[1][33] = 36;
		dataPacket.streams[1][34] = 70;
		dataPacket.streams[1][35] = 45;
		dataPacket.streams[1][36] = 88;
		dataPacket.streams[1][37] = 89;
		dataPacket.streams[1][38] = 23;
		dataPacket.streams[1][39] = 83;
		dataPacket.streams[1][40] = 210;
		dataPacket.streams[1][41] = 19;
		dataPacket.streams[1][42] = 86;
		dataPacket.streams[1][43] = 55;
		dataPacket.streams[1][44] = 93;
		dataPacket.streams[1][45] = 72;
		dataPacket.streams[1][46] = 32;
		dataPacket.streams[1][47] = 75;
		dataPacket.streams[1][48] = 14;
		dataPacket.streams[1][49] = 175;
		dataPacket.streams[1][50] = 96;
		dataPacket.streams[1][51] = 13;
		dataPacket.streams[1][52] = 55;
		dataPacket.streams[1][53] = 47;
		dataPacket.streams[1][54] = 13;
		dataPacket.streams[1][55] = 58;
		dataPacket.streams[1][56] = 15;
		dataPacket.streams[1][57] = 25;
		dataPacket.streams[1][58] = 32;
		dataPacket.streams[1][59] = 53;
		dataPacket.streams[1][60] = 51;
		dataPacket.streams[1][61] = 77;
		dataPacket.streams[1][62] = 16;
		dataPacket.streams[1][63] = 80;
		dataPacket.streams[1][64] = 99;
		dataPacket.streams[1][65] = 27;
		dataPacket.streams[1][66] = 15;
		dataPacket.streams[1][67] = 11;
		dataPacket.streams[1][68] = 44;
		dataPacket.streams[1][69] = 27;
		dataPacket.streams[1][70] = 85;
		dataPacket.streams[1][71] = 45;
		dataPacket.streams[1][72] = 65;
		dataPacket.streams[1][73] = 94;
		dataPacket.streams[1][74] = 28;
		dataPacket.streams[1][75] = 82;
		dataPacket.streams[1][76] = 75;
		dataPacket.streams[1][77] = 81;
		dataPacket.streams[1][78] = 67;
		dataPacket.streams[1][79] = 79;
		dataPacket.streams[1][80] = 37;
		dataPacket.streams[1][81] = 67;
		dataPacket.streams[1][82] = 11;
		dataPacket.streams[1][83] = 80;
		dataPacket.streams[1][84] = 88;
		dataPacket.streams[1][85] = 39;
		dataPacket.streams[1][86] = 77;
		dataPacket.streams[1][87] = 21;
		dataPacket.streams[1][88] = 60;
		dataPacket.streams[1][89] = 11;
		dataPacket.streams[1][90] = 76;
		dataPacket.streams[1][91] = 70;
		dataPacket.streams[1][92] = 11;
		dataPacket.streams[1][93] = 63;
		dataPacket.streams[1][94] = 74;
		dataPacket.streams[1][95] = 85;
		dataPacket.streams[1][96] = 94;
		dataPacket.streams[1][97] = 20;
		dataPacket.streams[1][98] = 54;
		dataPacket.streams[1][99] = 73;

		// Stream 2 data
		dataPacket.streams[2][0]  = 80;
		dataPacket.streams[2][1]  = 69;
		dataPacket.streams[2][2]  = 86;
		dataPacket.streams[2][3]  = 71;
		dataPacket.streams[2][4]  = 65;
		dataPacket.streams[2][5]  = 13;
		dataPacket.streams[2][6]  = 92;
		dataPacket.streams[2][7]  = 49;
		dataPacket.streams[2][8]  = 68;
		dataPacket.streams[2][9]  = 32;
		dataPacket.streams[2][10] = 39;
		dataPacket.streams[2][11] = 48;
		dataPacket.streams[2][12] = 53;
		dataPacket.streams[2][13] = 82;
		dataPacket.streams[2][14] = 20;
		dataPacket.streams[2][15] = 97;
		dataPacket.streams[2][16] = 38;
		dataPacket.streams[2][17] = 35;
		dataPacket.streams[2][18] = 93;
		dataPacket.streams[2][19] = 64;
		dataPacket.streams[2][20] = 30;
		dataPacket.streams[2][21] = 97;
		dataPacket.streams[2][22] = 93;
		dataPacket.streams[2][23] = 33;
		dataPacket.streams[2][24] = 26;
		dataPacket.streams[2][25] = 71;
		dataPacket.streams[2][26] = 37;
		dataPacket.streams[2][27] = 52;
		dataPacket.streams[2][28] = 75;
		dataPacket.streams[2][29] = 44;
		dataPacket.streams[2][30] = 35;
		dataPacket.streams[2][31] = 35;
		dataPacket.streams[2][32] = 93;
		dataPacket.streams[2][33] = 35;
		dataPacket.streams[2][34] = 58;
		dataPacket.streams[2][35] = 65;
		dataPacket.streams[2][36] = 75;
		dataPacket.streams[2][37] = 87;
		dataPacket.streams[2][38] = 17;
		dataPacket.streams[2][39] = 37;
		dataPacket.streams[2][40] = 51;
		dataPacket.streams[2][41] = 87;
		dataPacket.streams[2][42] = 51;
		dataPacket.streams[2][43] = 70;
		dataPacket.streams[2][44] = 59;
		dataPacket.streams[2][45] = 83;
		dataPacket.streams[2][46] = 82;
		dataPacket.streams[2][47] = 23;
		dataPacket.streams[2][48] = 24;
		dataPacket.streams[2][49] = 50;
		dataPacket.streams[2][50] = 71;
		dataPacket.streams[2][51] = 82;
		dataPacket.streams[2][52] = 25;
		dataPacket.streams[2][53] = 75;
		dataPacket.streams[2][54] = 34;
		dataPacket.streams[2][55] = 32;
		dataPacket.streams[2][56] = 35;
		dataPacket.streams[2][57] = 16;
		dataPacket.streams[2][58] = 93;
		dataPacket.streams[2][59] = 44;
		dataPacket.streams[2][60] = 72;
		dataPacket.streams[2][61] = 69;
		dataPacket.streams[2][62] = 94;
		dataPacket.streams[2][63] = 39;
		dataPacket.streams[2][64] = 18;
		dataPacket.streams[2][65] = 40;
		dataPacket.streams[2][66] = 64;
		dataPacket.streams[2][67] = 50;
		dataPacket.streams[2][68] = 74;
		dataPacket.streams[2][69] = 95;
		dataPacket.streams[2][70] = 75;
		dataPacket.streams[2][71] = 37;
		dataPacket.streams[2][72] = 44;
		dataPacket.streams[2][73] = 75;
		dataPacket.streams[2][74] = 98;
		dataPacket.streams[2][75] = 91;
		dataPacket.streams[2][76] = 13;
		dataPacket.streams[2][77] = 82;
		dataPacket.streams[2][78] = 79;
		dataPacket.streams[2][79] = 80;
		dataPacket.streams[2][80] = 38;
		dataPacket.streams[2][81] = 52;
		dataPacket.streams[2][82] = 32;
		dataPacket.streams[2][83] = 32;
		dataPacket.streams[2][84] = 42;
		dataPacket.streams[2][85] = 49;
		dataPacket.streams[2][86] = 25;
		dataPacket.streams[2][87] = 84;
		dataPacket.streams[2][88] = 39;
		dataPacket.streams[2][89] = 74;
		dataPacket.streams[2][90] = 30;
		dataPacket.streams[2][91] = 86;
		dataPacket.streams[2][92] = 41;
		dataPacket.streams[2][93] = 20;
		dataPacket.streams[2][94] = 86;
		dataPacket.streams[2][95] = 42;
		dataPacket.streams[2][96] = 76;
		dataPacket.streams[2][97] = 61;
		dataPacket.streams[2][98] = 10;
		dataPacket.streams[2][99] = 10;

		// Stream 3 data
		dataPacket.streams[3][0]  = 72;
		dataPacket.streams[3][1]  = 74;
		dataPacket.streams[3][2]  = 12;
		dataPacket.streams[3][3]  = 46;
		dataPacket.streams[3][4]  = 12;
		dataPacket.streams[3][5]  = 93;
		dataPacket.streams[3][6]  = 1;
		dataPacket.streams[3][7]  = 77;
		dataPacket.streams[3][8]  = 25;
		dataPacket.streams[3][9]  = 80;
		dataPacket.streams[3][10] = 56;
		dataPacket.streams[3][11] = 62;
		dataPacket.streams[3][12] = 88;
		dataPacket.streams[3][13] = 85;
		dataPacket.streams[3][14] = 31;
		dataPacket.streams[3][15] = 58;
		dataPacket.streams[3][16] = 68;
		dataPacket.streams[3][17] = 11;
		dataPacket.streams[3][18] = 90;
		dataPacket.streams[3][19] = 72;
		dataPacket.streams[3][20] = 85;
		dataPacket.streams[3][21] = 25;
		dataPacket.streams[3][22] = 85;
		dataPacket.streams[3][23] = 90;
		dataPacket.streams[3][24] = 65;
		dataPacket.streams[3][25] = 70;
		dataPacket.streams[3][26] = 21;
		dataPacket.streams[3][27] = 80;
		dataPacket.streams[3][28] = 25;
		dataPacket.streams[3][29] = 100;
		dataPacket.streams[3][30] = 66;
		dataPacket.streams[3][31] = 87;
		dataPacket.streams[3][32] = 76;
		dataPacket.streams[3][33] = 21;
		dataPacket.streams[3][34] = 97;
		dataPacket.streams[3][35] = 42;
		dataPacket.streams[3][36] = 66;
		dataPacket.streams[3][37] = 31;
		dataPacket.streams[3][38] = 90;
		dataPacket.streams[3][39] = 20;
		dataPacket.streams[3][40] = 42;
		dataPacket.streams[3][41] = 55;
		dataPacket.streams[3][42] = 82;
		dataPacket.streams[3][43] = 82;
		dataPacket.streams[3][44] = 23;
		dataPacket.streams[3][45] = 53;
		dataPacket.streams[3][46] = 74;
		dataPacket.streams[3][47] = 63;
		dataPacket.streams[3][48] = 24;
		dataPacket.streams[3][49] = 197;
		dataPacket.streams[3][50] = 74;
		dataPacket.streams[3][51] = 21;
		dataPacket.streams[3][52] = 89;
		dataPacket.streams[3][53] = 77;
		dataPacket.streams[3][54] = 22;
		dataPacket.streams[3][55] = 95;
		dataPacket.streams[3][56] = 92;
		dataPacket.streams[3][57] = 8;
		dataPacket.streams[3][58] = 93;
		dataPacket.streams[3][59] = 88;
		dataPacket.streams[3][60] = 39;
		dataPacket.streams[3][61] = 67;
		dataPacket.streams[3][62] = 96;
		dataPacket.streams[3][63] = 10;
		dataPacket.streams[3][64] = 47;
		dataPacket.streams[3][65] = 36;
		dataPacket.streams[3][66] = 34;
		dataPacket.streams[3][67] = 22;
		dataPacket.streams[3][68] = 62;
		dataPacket.streams[3][69] = 51;
		dataPacket.streams[3][70] = 65;
		dataPacket.streams[3][71] = 37;
		dataPacket.streams[3][72] = 42;
		dataPacket.streams[3][73] = 69;
		dataPacket.streams[3][74] = 80;
		dataPacket.streams[3][75] = 84;
		dataPacket.streams[3][76] = 74;
		dataPacket.streams[3][77] = 28;
		dataPacket.streams[3][78] = 39;
		dataPacket.streams[3][79] = 71;
		dataPacket.streams[3][80] = 121;
		dataPacket.streams[3][81] = 96;
		dataPacket.streams[3][82] = 54;
		dataPacket.streams[3][83] = 30;
		dataPacket.streams[3][84] = 43;
		dataPacket.streams[3][85] = 65;
		dataPacket.streams[3][86] = 61;
		dataPacket.streams[3][87] = 30;
		dataPacket.streams[3][88] = 26;
		dataPacket.streams[3][89] = 95;
		dataPacket.streams[3][90] = 51;
		dataPacket.streams[3][91] = 15;
		dataPacket.streams[3][92] = 67;
		dataPacket.streams[3][93] = 28;
		dataPacket.streams[3][94] = 18;
		dataPacket.streams[3][95] = 70;
		dataPacket.streams[3][96] = 48;
		dataPacket.streams[3][97] = 96;
		dataPacket.streams[3][98] = 46;
		dataPacket.streams[3][99] = 84;

		// Stream 4 data
		dataPacket.streams[4][0]  = 65;
		dataPacket.streams[4][1]  = 43;
		dataPacket.streams[4][2]  = 50;
		dataPacket.streams[4][3]  = 35;
		dataPacket.streams[4][4]  = 41;
		dataPacket.streams[4][5]  = 100;
		dataPacket.streams[4][6]  = 91;
		dataPacket.streams[4][7]  = 85;
		dataPacket.streams[4][8]  = 14;
		dataPacket.streams[4][9]  = 14;
		dataPacket.streams[4][10] = 74;
		dataPacket.streams[4][11] = 35;
		dataPacket.streams[4][12] = 6;
		dataPacket.streams[4][13] = 74;
		dataPacket.streams[4][14] = 13;
		dataPacket.streams[4][15] = 40;
		dataPacket.streams[4][16] = 24;
		dataPacket.streams[4][17] = 52;
		dataPacket.streams[4][18] = 94;
		dataPacket.streams[4][19] = 10;
		dataPacket.streams[4][20] = 39;
		dataPacket.streams[4][21] = 26;
		dataPacket.streams[4][22] = 62;
		dataPacket.streams[4][23] = 80;
		dataPacket.streams[4][24] = 84;
		dataPacket.streams[4][25] = 25;
		dataPacket.streams[4][26] = 75;
		dataPacket.streams[4][27] = 77;
		dataPacket.streams[4][28] = 98;
		dataPacket.streams[4][29] = 159;
		dataPacket.streams[4][30] = 79;
		dataPacket.streams[4][31] = 87;
		dataPacket.streams[4][32] = 54;
		dataPacket.streams[4][33] = 65;
		dataPacket.streams[4][34] = 76;
		dataPacket.streams[4][35] = 79;
		dataPacket.streams[4][36] = 37;
		dataPacket.streams[4][37] = 42;
		dataPacket.streams[4][38] = 93;
		dataPacket.streams[4][39] = 93;
		dataPacket.streams[4][40] = 62;
		dataPacket.streams[4][41] = 47;
		dataPacket.streams[4][42] = 94;
		dataPacket.streams[4][43] = 95;
		dataPacket.streams[4][44] = 94;
		dataPacket.streams[4][45] = 84;
		dataPacket.streams[4][46] = 20;
		dataPacket.streams[4][47] = 10;
		dataPacket.streams[4][48] = 47;
		dataPacket.streams[4][49] = 23;
		dataPacket.streams[4][50] = 90;
		dataPacket.streams[4][51] = 48;
		dataPacket.streams[4][52] = 60;
		dataPacket.streams[4][53] = 100;
		dataPacket.streams[4][54] = 48;
		dataPacket.streams[4][55] = 80;
		dataPacket.streams[4][56] = 51;
		dataPacket.streams[4][57] = 89;
		dataPacket.streams[4][58] = 66;
		dataPacket.streams[4][59] = 99;
		dataPacket.streams[4][60] = 49;
		dataPacket.streams[4][61] = 70;
		dataPacket.streams[4][62] = 27;
		dataPacket.streams[4][63] = 63;
		dataPacket.streams[4][64] = 85;
		dataPacket.streams[4][65] = 72;
		dataPacket.streams[4][66] = 62;
		dataPacket.streams[4][67] = 89;
		dataPacket.streams[4][68] = 57;
		dataPacket.streams[4][69] = 37;
		dataPacket.streams[4][70] = 84;
		dataPacket.streams[4][71] = 55;
		dataPacket.streams[4][72] = 46;
		dataPacket.streams[4][73] = 95;
		dataPacket.streams[4][74] = 20;
		dataPacket.streams[4][75] = 82;
		dataPacket.streams[4][76] = 71;
		dataPacket.streams[4][77] = 63;
		dataPacket.streams[4][78] = 100;
		dataPacket.streams[4][79] = 22;
		dataPacket.streams[4][80] = 73;
		dataPacket.streams[4][81] = 91;
		dataPacket.streams[4][82] = 72;
		dataPacket.streams[4][83] = 44;
		dataPacket.streams[4][84] = 13;
		dataPacket.streams[4][85] = 100;
		dataPacket.streams[4][86] = 51;
		dataPacket.streams[4][87] = 50;
		dataPacket.streams[4][88] = 90;
		dataPacket.streams[4][89] = 56;
		dataPacket.streams[4][90] = 44;
		dataPacket.streams[4][91] = 133;
		dataPacket.streams[4][92] = 96;
		dataPacket.streams[4][93] = 86;
		dataPacket.streams[4][94] = 43;
		dataPacket.streams[4][95] = 87;
		dataPacket.streams[4][96] = 27;
		dataPacket.streams[4][97] = 19;
		dataPacket.streams[4][98] = 69;
		dataPacket.streams[4][99] = 76;
	}
};