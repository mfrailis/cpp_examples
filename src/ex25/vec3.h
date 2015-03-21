
#ifndef GUARD_VEC3_H
#define GUARD_VEC3_H

#include <cstddef>
#include <cmath>

// namespace definition
namespace dimg {

  class Vec3 {
  public:
    Vec3();
    Vec3(double x, double y, double z);

    double& at(std::size_t i) { return elems[i];}
    const double& at(std::size_t i) const { return elems[i];}

    double norm() const;

    Vec3& operator+=(const Vec3& s);

  private:
    double elems[3];
  };

  Vec3 operator+(const Vec3& lhs, const Vec3& rhs);

  inline double Vec3::norm() const
  {
    return sqrt( elems[0]*elems[0] + elems[1]*elems[1] +
                 elems[2]*elems[2]);
  }

}


#endif  // end of GUARD_VEC3_H

