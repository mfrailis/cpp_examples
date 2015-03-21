
#include "utils.h"
#include <sstream>

using std::vector;
using std::string;
using std::istream;
using std::istringstream;

std::vector<std::vector<string>>
readCSVLines(istream& is, char fieldSep,
             char lineSep)
{
   string line;
   vector<vector<string>> csvFields;
   while (getline(is, line, lineSep))
   {
     istringstream fields(line);
     string singleField;
     vector<string> lineFields;

     while(getline(fields, singleField, fieldSep))
        lineFields.push_back(singleField);

     csvFields.push_back(lineFields);
   }
   return csvFields;
}
