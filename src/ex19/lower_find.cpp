

#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  vector<int> v = {1,5,6,8,11,20};
  vector<int>::iterator lb, fi;

  // find the first element equal to or grater then 7
  lb = lower_bound(v.begin(),v.end(),7);

  // find the first element equal to 7
  fi = find(v.begin(),v.end(),7);

  /*
   *lb == 8
   fi == v.end()
   */
}
