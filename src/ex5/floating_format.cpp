
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  const double PI = 3.1415926535897931;

  cout << PI << endl;
  cout << setprecision(15) << PI << endl;
  cout << scientific << PI << endl;
  cout << fixed << setw(20) << PI << endl;     // setw sets the field width
  cout << resetiosflags(ostream::floatfield);  // revert to default notation
  cout << PI << endl;

  return 0;
}
