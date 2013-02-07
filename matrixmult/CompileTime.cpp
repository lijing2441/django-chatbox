#include <stdio.h>
#include "TestHelpers.h"
#include "TestData.h"
using namespace std;

// http://stackoverflow.com/questions/12108390/c11-compile-time-calculation-of-array

typedef array<int, SIZE> matrix;

constexpr int f(const int a) { return matrix_A[a] * matrix_B[a]; }

template<int... i>
constexpr matrix fs() {
  return matrix{{ f(i)... }};
}

template<int... i> struct S;

template<int... i> struct S<0, i...> {
  static constexpr matrix gs() {
    return fs<0, i...>();
  }
};
template<int i, int... j> struct S<i, j...> {
  static constexpr matrix gs() {
    return S<i-1, i, j...>::gs();
  }
};

constexpr auto result = S<SIZE-1>::gs();


int main(int argc, char *argv[])
{
  TIMER_START

  // TODO: Create string at compile time.

  for (int i = 0; i < SIZE ; ++i) {
    printf("%d",result[i]);
  }
  puts("\n");

  TIMER_END
  return 0;
}
