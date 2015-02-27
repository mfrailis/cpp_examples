

#include <cmath>
#include <iostream>
#include <complex>

using namespace std;

const double PI = 3.1415926535897931;

const double RAD2DEG = 180.0/PI;

// Convert Cartesian coordinates to spherical coordinates
int main()
{
  // Coordinates to be converted
  double x = 10.3, y=-5.2, z=36;

  // Norm
  double r = sqrt(x*x + y*y + z*z);

  // Longitude
  double phi = atan2(y, x);
  phi = phi < 0 ? phi + 2*PI : phi;

  // Colatitude
  double theta = acos(z/r);

  cout << "Longitude = " << phi*RAD2DEG << " deg, Colatitude = "
       << theta*RAD2DEG << " deg, Radius = " << r << endl;

  return 0;
}
