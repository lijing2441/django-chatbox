#include <vector>

namespace Calc {
  template < class InputIterator, class OutputIterator, class BinaryOperator >
    OutputIterator transformPointZip ( InputIterator first1, InputIterator last1,
				       InputIterator first2, OutputIterator result,
				       BinaryOperator op )
  {
    while (first1 != last1) {
      *result++ = op(first1++, first2++);
    }
    return result;
  }
  typedef std::vector<long double> Data;
  typedef Data::iterator dataIt;
  const Data derivative(Data&& x, Data&& y);
  const Data derivative(Data& x, Data& y);
  const Data derivative(const long double&& xmin, const long double&& xmax, Data&& x);
  const Data derivative(const long double&& xmin, const long double&& xmax, Data& x);
}
