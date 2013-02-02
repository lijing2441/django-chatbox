#include <chrono>
#include <iostream>
#include <iterator>
#include <array>
#include <algorithm>
#include "TestHelpers.h"
#include "TestData.h"
#include "prettyprint.hpp"
using namespace std;

// I make this function object because you can't make a
// lambda constexpr.
struct MatrixMult {
public:
  constexpr MatrixMult() {}
  constexpr int operator() (const int& m, const int& n) {
    return m * n;
  }
};

int main(int argc, char *argv[])
{
  TIMER_START

  array<int, 1000> result;

  transform(matrix_A.begin(), matrix_A.end(), matrix_B.begin(),
	    result.begin(), MatrixMult {});

  cout << result << endl;
  // move(result.begin(), result.end(),
  //      ostream_iterator<int>{cout,", "});

  TIMER_END
  return 0;
}
