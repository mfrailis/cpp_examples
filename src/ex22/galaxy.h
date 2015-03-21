
#ifndef GUARD_GALAXY_H
#define GUARD_GALAXY_H

struct Point {
  double ra;
  double dec;
};

struct Galaxy {

  // ID of galaxy instance
  unsigned long id;
  // Galaxy coordinates (RA, DEC)
  Point coord;
  // Redshif of Galaxy instance
  double z;
  // Velocity of Galaxy instance
  double v;
};


#endif // end of GUARD_GALAXY_H
