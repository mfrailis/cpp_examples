
#include "ex10/stats.h"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

// This example will generate an exception
int main()
{

  vector<double> samples = {1,2,3,4,5,6,7,8,9,10};
  vector<double> elements;

  try {
    double mean_value = mean(samples);
    double median_value = median(elements);

    cout << "sample statistics: mean=" << mean_value
         << " median=" << median_value << endl;
  } catch (domain_error& e) {
    cerr << e.what() << endl;
  }

}
