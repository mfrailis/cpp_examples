
#include "utils.h"
#include <fstream>

using namespace std;

int main()
{
  ifstream infile("../src/ex11/data.csv");
  auto lines = readCSVLines(infile); // default field and line separator
  infile.clear();                    // clear fail and eof bits
  infile.seekg(0, ios::beg);         // back to the start!
  lines = readCSVLines(infile, ' '); // use space as field sep

  for (const auto& line : lines)
  {
    for (const auto& field : line)
      cout << field << " ";
    cout << endl;
  }
}
