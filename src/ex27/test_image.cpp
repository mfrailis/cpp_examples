
#include "image.h"
#include <iostream>

using namespace std;
using namespace dimg;

int main(int argc, char* argv[])
{
  // Creates an image of double values
  // with 15 rows and 10 columns
  Image<double> a(15, 10);
  // All pixels are set to 5.0
  a = 5;
  // Setting pixel (4,5) to 10
  a(4, 5) = 10;
  // b is a copy of a
  Image<double> b(a);
  // Retrieving image dimensions and size
  auto size = b.size();
  auto width = b.width();
  auto height = b.height();
  // Resetting all pixels in a range-for loop
  for (auto& x : a)
    x = 0;

  cout << "a width: " << width << " height: " << height << " size: " << size << endl;
  cout << a << endl;
  Mask<unsigned short> c(a.width(), a.height());
  c = 0x1;
  Mask<unsigned short> d(c);
  d = 0x2;
  c |= d;

  cout << "c:" << endl;
  cout << c << endl;

}
