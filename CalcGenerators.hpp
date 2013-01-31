#ifndef CALCGEN
#define CALCGEN

namespace Calc {
  struct x_gen
  {
    const long double EPSILON = 0.0001;
    const long double min, max, step;
    long double c ,tmp;
    x_gen(const long double& xmin, const long double& xmax, const int& N) :
      min(xmin), tmp(xmin), c(xmin), max(xmax), step((max - min) / (N-1)) {}
    long double operator()() {
      tmp = c;
      if (c == min) {
	c += step;
      }
      else if ((c - max) < -EPSILON) {
	c += step;
      }
      return tmp;
    }
  };
}
#endif
