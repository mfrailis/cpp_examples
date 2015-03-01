
#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main()
{

  int n = 10;
  vector<float> a(n, 5.0);       // a has n elements that are copies of 5.0
  vector<int> b = {3,2,7,11,23}; // b contains the elements provided in the list

  cout << "First and last elements of b: "
       << b[0] << " " << b[b.size()-1] << endl;

  // vector from a list of numbers gathered from the standard input
  double value;
  vector<double> c;
  cout << "Please insert some values (use Ctrl-D to end): " << endl;

  // The user ends inputting numbers with the EOF character
  while (cin >> value)
    c.push_back(value);  // appends a new element at the end of vector c

  // Print vector elements
  cout << "c elements: ";
  for (double x : c)
    cout << x << " ";
  cout << endl;

  vector<double> d(c);   // defines d as a copy of c

  // e holds a copy of the first half of d
  vector<double> e(d.begin(), d.begin() + d.size()/2);

  c.clear();  // removes all elements in c; c.size() == 0

  // erase elements of first half of d
  d.erase(d.begin(), d.begin() + d.size()/2);

  c = e;  // c is now a copy of e

  // prepend elements of a in e
  e.insert(e.begin(), a.begin(), a.end());

  vector<complex<double>> f;
  f.push_back({1, -1});       // analogous to push_back(complex<double>(1,-1)), but shorter
                              // thanks to initializer list
  f.emplace_back(1, -1);      // emplace_back is analogous to push_back but it just needs the
                              // arguments to construct the value, which is created in-place


  // Testing vector capacity behaviour
  vector<int> g;
  cout << "g initial capacity: " << g.capacity() << endl;
  for (int i = 0; i < 33; ++i)
    g.push_back(i);
  cout << "g capacity with 33 elements: " << g.capacity() << endl;

  // Testing vector::reserve method behaviour
  vector<int> h;
  h.reserve(33);
  h.insert(h.end(),g.begin(), g.end());
  cout << "h capacity with 33 elements: " << h.capacity() << endl;

  // Adding one last element to h, to check how capacity changes
  h.push_back(h[h.size()-1]+1);
  cout << "h capacity with 34 elements: " << h.capacity() << endl;

  return 0;
}
