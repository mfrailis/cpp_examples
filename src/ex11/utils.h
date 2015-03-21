
#ifndef GUARD_UTILS_H
#define GUARD_UTILS_H

#include <vector>
#include <iostream>
#include <string>

// Reads lines from a Comma-separated Value file
std::vector<std::vector<std::string>>
readCSVLines(std::istream&, char fieldSep = ',',
             char lineSep = '\n');

// Inline function
inline void swap(int& v1, int& v2)
{
  int tmp = v1;
  v1 = v2;
  v2 = tmp;
}

#endif // end of GUARD_UTILS_H
