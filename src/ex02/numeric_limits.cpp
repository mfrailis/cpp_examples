
#include <iostream>
#include <limits>
using namespace std;


/*
This program prints main properties of each C++ numeric type using the
numeric_limits class provided by the <limits> standard header
*/

int main()
{
  cout << "bool type:\n\t size(bytes)=" << sizeof(bool) << endl;

  // A satic cast of char min and max values is necessary to print them as
  // integer values and not as characters
  cout << "char type:\n\t min=" <<  static_cast<int>(numeric_limits<char>::min())
       << " max=" << static_cast<int>(numeric_limits<char>::max())
       << " size(bytes)=" << sizeof(char) << endl;

  cout << "int type:\n\t min=" <<  numeric_limits<int>::min()
       << " max=" << numeric_limits<int>::max()
       << " size(bytes)=" << sizeof(int) << endl;

  cout << "long type:\n\t min=" <<  numeric_limits<long>::min()
       << " max=" << numeric_limits<long>::max()
       << " size(bytes)=" << sizeof(long) << endl;

  cout << "long long type:\n\t min=" <<  numeric_limits<long long>::min()
       << " max=" << numeric_limits<long long>::max()
       << " size(bytes)=" << sizeof(long long) << endl;

  cout << "float type:\n\t min=" <<  numeric_limits<float>::min()
       << " max=" << numeric_limits<float>::max()
       << " size (bytes)=" << sizeof(float) << endl
       << "\t decimal digits=" << numeric_limits<float>::max_digits10
       << " mantissa(bits)=" << numeric_limits<float>::digits
       << endl;

  cout << "double type:\n\t min=" <<  numeric_limits<double>::min()
       << " max=" << numeric_limits<double>::max()
       << " size(bytes)=" << sizeof(double) << endl
       << "\t decimal digits=" << numeric_limits<double>::max_digits10
       << " mantissa(bits)=" << numeric_limits<double>::digits
       << endl;

  // Even if the size of long double is reported to be 128 bits, only 80 bits
  // are really used
  cout << "long double type:\n\t min = " <<  numeric_limits<long double>::min()
       << " max = " << numeric_limits<long double>::max()
       << " size(bytes)=" << sizeof(long double) << endl
       << "\t decimal digits=" << numeric_limits<long double>::max_digits10
       << " mantissa(bits)=" << numeric_limits<long double>::digits
       << endl;

  return 0;
}
