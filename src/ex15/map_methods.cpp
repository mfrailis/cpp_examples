
#include <map>
#include <iostream>

using namespace std;

int main()
{
  // Constructing a map from an initializer list
  map<string, string> m1 = {{"TELESCOP", "PLANCK"},
                            {"INSTRUME", "LFI"},
                            {"APID", "1538"}};

  m1["TYPE"] = "3";   // adding a new key-value pair {"TYPE","3}

  // A pair is the really the type of each element in the map
  pair<string,string> p{"SUBTYPE","25"};
  // Attributes of a pair type
  cout << "pair elements: " << p.first << " " << p.second << endl;

  // Alternative isertion methods
  m1.insert(p);
  m1.insert({"PI1_VAL","102"});
  m1.emplace("PI2_VAL", "0");

  cout << "m1 elements: [ ";
  for (const auto& x : m1)
    cout << "(" << x.first << "," << x.second << ") ";
  cout << " ]" << endl;

  // Searching a key within the map m1
  auto it = m1.find("APID");
  if (it != m1.end())
    cout << "key \"APID\" found: "
         << "(" << (*it).first << "," << (*it).second << ")"
         << endl;
}
