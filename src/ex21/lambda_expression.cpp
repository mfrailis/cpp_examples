
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  vector<int> v = {0,1,7,5,6,3,5,2,3,4};

  int val = 5;

  // lambda expressions can be stored in variables
  auto lambda  = [val] (int x) -> bool { return x == val;};

  // count how many elements are equal to val
  int found = count_if(v.begin(),v.end(),lambda);

  cout << "found " << found << " elements equal to " << val << endl;

  // print the elements using a lambda expression
  for_each(v.begin(),v.end(),[](int x){cout << x << " ";});

  cout << endl;
  return 0;
}
