
#include "tstats.h"

#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> iv = {1,3,2,8,4,6};
  vector<double> dv = {3.4, 6.5, 2.8, 4.2};

  cout << "Max of iv: " << max(iv) << endl;
  cout << "Max of dv: " << max(dv) << endl;

  return 0;
}
