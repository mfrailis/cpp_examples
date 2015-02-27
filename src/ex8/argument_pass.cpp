
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


// Compute the samples mean value
// (passing argumens by const reference)
double mean(const vector<double>& samples)
{
  auto size = samples.size();

  if (size == 0)
    throw domain_error("mean of an empty vector");

  double sum = 0;
  for (const auto& x : samples)
    sum += x;
  return sum/size;
}

// Return the greatest common divisor
// (passing arguments by value)
int gcd(int v1, int v2)
{
  while (v2)
  {
    int temp = v2;
    v2 = v1 % v2;
    v1 = temp;
  }
  return v1;
}


// swap v2 and v2 values - just an example, since it is already provided by the std library
// (passing arguments by reference)
void swap(int& v1, int&v2)
{
  int tmp = v2;
  v2 = v1;
  v1 = tmp;
}


int main()
{

  int x = 132, y = 36;

  cout << "Greatest common divisor of " << x << " and " << y << ": " << gcd(x,y) << endl;

  vector<double> v = {1.1, 2.5, 3.2, 1,5};
  cout << "v mean value: " << mean(v) << endl;

  cout << "Swapping x and y: ";
  swap(x,y);
  cout << x << " " << y << endl;

  return 0;
}
