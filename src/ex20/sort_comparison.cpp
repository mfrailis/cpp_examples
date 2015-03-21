
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <class ContainerT>
void pretty_print(ostream& os, const ContainerT& range)
{
  for (const auto& x : range)
    os << x << " ";
  os << endl;
}

// Function to sort elements in descending order
bool gt (int x, int y) { return x > y;}

int main()
{
  vector<int> v = {11, 45, 6, 7, 8, 12, 9, 2};
  int a[] =       {11, 45, 6, 7, 8, 12, 9, 2};

  sort(v.begin(),v.end(),gt);

  auto it = lower_bound(v.begin(),v.end(),10,gt);

  nth_element(a,a+3,a+8,gt);

  /*
   v == 45 12 11 9 8 7 6 2
   a == 11 45 12 9 8 7 6 2
   *it == 9
  */

  cout << "v == "; pretty_print(cout, v);
  cout << "a == "; pretty_print(cout, a);
  cout << "*it == " << *it << endl;
}
