
#include "vec3.h"

using namespace dimg;


int main(int argc, char* argv[])
{

  Vec3 p;  // default-constructor is called
  Vec3 q{0, 1.5, -2.4};  // the second constructor is called
  Vec3 r(q); // implicit copy-constructor used

  p = q + r;

  return 0;
}
