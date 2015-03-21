
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

int main()
{
  int a[] =       {11, 45, 6, 7, 8, 10, 9, 2};
  vector<int> v = {11, 45, 6, 7, 8, 10, 9, 2};

  // sort the elements of v
  sort(v.begin(),v.end());

  // set the 4th element in the position as array a was sorted
  nth_element(a,a+3,a+8);
  /*
    v == 2 6 7 8  9 10 11 45
    a == 6 2 7 8 11 10  9 45
   */
  cout << "v == "; pretty_print(cout, v);
  cout << "a == "; pretty_print(cout, a);


}
