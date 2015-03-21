
#include "property.h"

#include <map>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  std::map<string, Property*> pmap;

  pmap["APID"] = createProperty("APID", 1536);
  pmap["TELESCOP"] = createProperty("TELESCOP", "PLANCK");
  pmap["MEAN_VAL"] = createProperty("MEAN_VAL", 4.434234);

  for (const auto& x : pmap){
    cout << x.first << ": " << x.second->getValueAsString() << endl;
  }
}
