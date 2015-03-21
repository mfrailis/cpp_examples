
#include "beam.h"

#include <iostream>
using namespace std;

int main()
{
  GaussianBeam beam =  {-0.0678,-0.034,0.0036,0.00446,0.044,0.70};

  double x = -0.070, y =  -0.035;
  double measure = beam(x, y);

  cout << measure << endl;

}
