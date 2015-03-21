
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  double x = 0.5;
  // dp points to x
  double* dp = &x ;
  cout << "x = " << x << endl ;
  // change the value of x through dp
  *dp += 0.5;
  cout << "x = " << x << endl ;
  // xref is a reference to x
  double& xref = *dp;
  xref += 0.5;
  cout << "x = " << x << endl;

  // c array of floats
  float y[] = {1,2,3,4,5};
  // print first and last element of y
  cout << "y[0] = " << *y << ", y[4] = " << *(y+4) << endl;

}
