#include <type_traits>
#include <iterator>
#include <string>
#include <stdio.h>
#include "TestHelpers.h"
#include "TestData.h"
using namespace std;

int main(int argc, char *argv[])
{
  TIMER_START

  string s;

  for (int i = 0; i < SIZE ; ++i) {
    s += to_string(c_matrix_A[i] * c_matrix_B[i]);
  }
  s += "\n";
  cout << s;

  TIMER_END
  return 0;
}
