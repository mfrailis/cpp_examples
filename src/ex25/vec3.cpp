
#include "vec3.h"

namespace dimg {

  Vec3::Vec3()
  {
    elems[0] = elems[1] = elems[2] = 0;
  }

  Vec3::Vec3(double x, double y, double z)
  {
    elems[0] = x; elems[1] = y; elems[2] = z;
  }

  Vec3& Vec3::operator+=(const Vec3& s) {
    elems[0] += s.elems[0];
    elems[1] += s.elems[1];
    elems[2] += s.elems[2];
    return *this;
  }

  Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {
    Vec3 r = lhs;   // implicit copy constructor used
    r += rhs;
    return r;
  }


}
