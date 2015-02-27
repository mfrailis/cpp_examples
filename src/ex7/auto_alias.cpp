
#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main()
{
  // alias definition
  using vec_compd = vector<complex<double>>;

  vec_compd v = {{1,0}, {1,-1}, {0,1}, {0,-1}};

  // Just to show how auto works
  auto size = v.size();

  // use of auto within a range-for loop. Each element of v is copied in x
  cout << "v has " << size << " elements: [";
  for (auto x : v)
    cout << " " << x ;
  cout << " ]" << endl;

  return 0;

}
