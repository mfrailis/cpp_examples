
#include <CCfits/CCfits>
#include <iostream>
#include <valarray>
#define EIGEN_DEFAULT_TO_ROW_MAJOR
#include <eigen3/Eigen/Dense>

using namespace CCfits;
using namespace std;

int main()
{

  bool readAllInMemory = true; //read data at Fits object construction
  unique_ptr<FITS> pInFile(new FITS("../src/ex31/sample.fits", Read, readAllInMemory));

  PHDU& image = pInFile->pHDU();

  valarray<double> v;

  // copy the image in the container
  image.read(v);

  // create an Eigen array of doubles
  Eigen::ArrayXXd m(image.axis(0), image.axis(1));

  //copy the elements in the array
  size_t i = 0;
  for(auto x : v)
    m(i++) = x;

  cout << m << endl;
}
