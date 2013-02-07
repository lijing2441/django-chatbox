#include <iostream>
#include <iterator>
#include <array>
#include <algorithm>
#include "TestHelpers.h"
#include "TestData.h"
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

  int result[SIZE];

  transform(c_matrix_A, c_matrix_A + SIZE, c_matrix_B,
	    result, MatrixMult {});

  move(result, result + SIZE,
       ostream_iterator<int>{cout,", "});

  TIMER_END
  return 0;
}
