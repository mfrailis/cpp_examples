
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


// This example shows some cases of function overloading. Here we overload
// a pretty_print function, defined in order to automatically print
// vectors of various element types

void pretty_print(ostream& os, const vector<double>& v)
{
  os << "[ ";
  for (decltype(v.size()) i = 0; i < v.size(); ++i) {
    if (i != 0)
      os << ", ";
    os << v[i];
  }
  os << " ]" << endl;
}

void pretty_print(ostream& os, const vector<double>& v, int precision)
{
  int prev_precision = os.precision();
  os.precision(precision);
  pretty_print(os, v);
  os.precision(prev_precision);
}

// The compiler distinguishes between const and non-const parameters
// however this function definition is redundant with respect to the
// first one
void pretty_print(ostream& os, vector<double>& v)
{
  os << "[ ";
  for (decltype(v.size()) i = 0; i < v.size(); ++i) {
    if (i != 0)
      os << ", ";
    os << v[i];
  }
  os << " ]" << endl;
}

void pretty_print(ostream& os, vector<int>& v)
{
  os << "[ ";
  for (decltype(v.size()) i = 0; i < v.size(); ++i) {
    if (i != 0)
      os << ", ";
    os << v[i];
  }
  os << " ]" << endl;
}

int main()
{
  const vector<double> a{4.5, 7.7};
  vector<double> b{5.6, 7.6, 1.23};

  vector<int> c{1,2,3,4,5};

  pretty_print(cout, a);
  pretty_print(cout, a, 10);
  pretty_print(cout, b);
  pretty_print(cout, c);

  return 0;
}
