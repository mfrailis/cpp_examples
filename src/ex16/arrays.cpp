
#include <iostream>
#include <array>
using namespace std;

int main()
{

  // Built-in array examples

  // Defining an array of doubles: 1024 elements
  double buffer[1024];

  // the size of the array can be specified using const variables
  const auto BSIZE = 1024;
  double buffer2[BSIZE];

  // size deduced from the initialization list length
  double filter[] = {0.020, 0.230, 0.498, 0.230, 0.020};

  // set all elements to 0.0
  for(auto i=0; i<BSIZE; i++)
    buffer2[i] = 0;

  cout << "Printing first values of buffer, buffer2 and filter:" << endl;
  cout << buffer[0] << " " << buffer2[0] << " " << filter[0] << endl;

  // std::array example

  array<int, 5> a = {0,5,2,6,9};

  // key is a value to search in the unsorted a
  int key = 6;
  bool found = false;

  size_t i = 0;
  while (i < a.size() and !found) {
    if (a[i] == key)
      found = true;
    ++i;
  }

  if (found)
    cout << "Value 6 found in a at index " << i << endl;

}
