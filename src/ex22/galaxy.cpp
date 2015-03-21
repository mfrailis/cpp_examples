
#include "galaxy.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  Galaxy g1{1, {349.18372, -0.070794291}, 0.527313,
            1/(1 + 0.527313)};

  Galaxy g2; // default initialized galaxy instance
             // in this case all elements initialized to zero

  cout << "Size of galaxy" << sizeof(g1) << endl;

  g2.id = 2;
  g2.coord.ra = 348.3452;
  g2.coord.dec = 0.0653423;
  g2.z = 0.5135289;
  g2.v = 1/(1+g2.z);

  double ra = g1.coord.ra;
  double dec = g1.coord.dec;

  cout << "galaxy g1 RA-DEC: (" << ra << ", " << dec << ")" << endl;

  std::vector<Galaxy> galaxy_cluster;
  galaxy_cluster.push_back(g1);
  galaxy_cluster.push_back(g2);
  return 0;
}
