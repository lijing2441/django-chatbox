#include <algorithm>
#include "CalcGenerators.hpp"
#include "CalcDerivative.h"
namespace Calc
{
  long double derivFun (dataIt xx, dataIt yy)
  {
    return (*(std::next(yy)) - (*yy)) / (*(std::next(xx)) - (*xx));
  }
  const Data derivative(Data&& x, Data&& y)
  {
    Data p(x.size());
    transformPointZip(x.begin(), x.end()-1, y.begin(), p.begin(),
		    derivFun);
    p[p.size()-1] = p[p.size()-2];
    return std::move(p);
  }
  const Data derivative(Data& x, Data& y)
  {
    Data p(x.size());
    transformPointZip(x.begin(), x.end()-1, y.begin(), p.begin(),
		    derivFun);
    p[p.size()-1] = p[p.size()-2];
    return std::move(p);
  }
  const Data derivative(const long double&& xmin, const long double&& xmax, Data&& x)
  {
    Data y(x.size());
    generate(y.begin(), y.end(),
	     x_gen(xmin, xmax, x.size()));
    return derivative(std::move(y), std::move(x));
  }
  const Data derivative(const long double&& xmin, const long double&& xmax, Data& x)
  {
    Data y(x.size());
    generate(y.begin(), y.end(),
	     x_gen(xmin, xmax, x.size()));
    return derivative(std::move(y), std::move(x));
  }
}
