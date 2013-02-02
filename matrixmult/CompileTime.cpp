#include <chrono>
#include <iostream>
#include "TestHelpers.h"
#include "TestData.h"
#include "prettyprint.hpp"
using namespace std;

constexpr int mMult(const int m, const int n) {
  return m * n;
}

int main(int argc, char *argv[])
{
  TIMER_START

  int result[SIZE];

  for (int i = 0; i < SIZE; ++i)
    result[i] = mMult(c_matrix_A[i], c_matrix_B[i]);

cout << result << endl;

  TIMER_END
  return 0;
}
