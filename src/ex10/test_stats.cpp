
#include "stats.h"
#include <iostream>

using namespace std;

int main()
{
  vector<double> v{1,2,3,4,5,6,7,8,9,10};

  cout << "v median: " << median(v) << endl;

  cout << "v mean: " << mean(v) << endl;

  return 0;
}
