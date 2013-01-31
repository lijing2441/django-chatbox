#include <iostream>
#include "prettyprint.hpp"
#include "CalcDerivative.h"
using namespace std;
using namespace Calc;

int main(int argc, char *argv[]) {
  cout << derivative({0, 2, 3, 4, 5, 6, 7},
		     {-1.0, -.5, 0, .5, 1.0, 1.5, 2.0}) << endl
       << derivative(-1, 1, {-1.0, -.5, 0, .5, 1.0})    << endl
       << derivative(-10, 10, {-1.0, -.5, 0, .5, 1.0})  << endl;
  return 0;
}
