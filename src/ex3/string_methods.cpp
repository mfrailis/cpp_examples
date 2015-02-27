
#include <string>

using namespace std;

int main()
{
  string s1;
  string s2 = "Hell0";
  string s3 = s2 + " World";          // string + literal concatenation

  bool isEmpty = s1.empty();          // check if s1 is an empty string
  char first = s3[0];                 // get the first character
  s3[4] = 'o';                        // modify the 5th character in s3
  bool isLess = s2 < s1;              // comparison operator between strings
                                      // (lexicographic order)
  s1 = s2;                            // copy s2 in s1, replacing s1 characters
  string s4 = s3.substr(6, 5);        // get the substring starting at index 6
                                      // and taking 5 chars (s4 = "World")
  string::size_type size = s4.size(); // get string size in bytes

  return 0;
}
