#include <type_traits>
#include <iterator>
#include <stdio.h>
#include "TestHelpers.h"
#include "TestData.h"
using namespace std;

int main(int argc, char *argv[])
{
  TIMER_START

  for (int i = 0; i < SIZE ; ++i) {
    printf("%d", c_matrix_A[i] * c_matrix_B[i]);
  }
  puts("\n");

  TIMER_END
  return 0;
}
