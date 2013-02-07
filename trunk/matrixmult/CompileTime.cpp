#include <stdio.h>
#include "TestHelpers.h"
#include "TestData.h"
using namespace std;

// http://stackoverflow.com/questions/12108390/c11-compile-time-calculation-of-array

typedef array<int, SIZE> matrix;

constexpr int f(const int a) { return matrix_A[a] * matrix_B[a]; }

template<int... Is>
constexpr matrix fs() {
  return matrix{{ f(Is)... }};
}

template<int... Is> struct S;

template<int... Is> struct S<0, Is...> {
  static constexpr matrix gs() {
    return fs<0, Is...>();
  }
};
template<int I, int... Js> struct S<I, Js...> {
  static constexpr matrix gs() {
    return S<I-1, I, Js...>::gs();
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
