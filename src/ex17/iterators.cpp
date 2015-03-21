
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<int> v(8); // v is initialized with 8 zeroes
  int a[] = {2,5,7,1,0,45,30,3};

  /* copies first 4 elements from a to v and returns
   * the iterator to the next element in v
   */
  vector<int>::iterator it = copy(a, a+4, v.begin());

  /* fills with -5 starting from it until the last
   * element of v
   */
  fill(it, v.end(),-5);

  for(const auto& x : v)
    cout << x << " ";
  cout << endl;

  return 0;
}
