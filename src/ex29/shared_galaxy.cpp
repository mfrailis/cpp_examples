
#include "ex22/galaxy.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

int main()
{
  // filling a vector of galaxy pointers with dynamically allocated instances
  vector<shared_ptr<Galaxy>> vg;
  vg.push_back(shared_ptr<Galaxy>(new Galaxy{1, {349.18372, -0.070794291}, 0.527313}));
  vg.push_back(shared_ptr<Galaxy>(new Galaxy{2, {348.3452, 0.0653423}, 0.5135289}));
  vg.push_back(shared_ptr<Galaxy>(new Galaxy{3, {346.29340, 0.034823}, 0.5126848}));

  // lambda expression to sort galaxy pointers by RA
  auto sort_by_ra = [] (shared_ptr<const Galaxy> x, shared_ptr<const Galaxy> y)
                       {return x->coord.ra < y->coord.ra;};

  sort(vg.begin(), vg.end(), sort_by_ra);

  cout << "galaxies ordering by RA: ";
  for (const auto x : vg)
    cout << x->id << " ";
  cout << endl;


//  // deleting all the dynamically allocated galaxies within the vector
//  for (auto x : vg) {
//    delete x;
//    x = nullptr;
//  }

  return 0;
}
