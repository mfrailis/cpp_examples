
#include <iostream>
#include <algorithm>    // std::lower_bound
#include <list>

using namespace std;

inline bool is_even(int i)
{
  return !(i%2);
}


int main()
{
  list<int> l1{1,2,3,4,5,14,15};
  list<int> l2{10,12,13};

  // find the first element in l1 which is not less than 10
  auto low = lower_bound(l1.begin(),l1.end(),10);

  // insert the list l2 in l1 starting from low index
  l1.splice(low,l2);

 // remove even elements using the function previously defined
  l1.remove_if(is_even);

  for(const auto& e : l1)
    cout << e << " ";
  cout << endl;

  return 0;
}
