
#ifndef GUARD_BEAM_H
#define GUARD_BEAM_H

class GaussianBeam
{
 public:
  // Constructor
  GaussianBeam(double center_x, double center_y, double sigma_x, double sigma_y,
               double amplitude, double orientation):
      x0(center_x), y0(center_y), sigmax(sigma_x),
      sigmay(sigma_y),amp(amplitude),alpha(orientation) {}

  // Call operator
  double operator() (double xpos, double ypos);

 private:
  GaussianBeam(); // prevent use of default constructor

  // Beam center
  double x0, y0;
  // Beam dispersions
  double sigmax, sigmay;
  // Beam amplitude (kelvin)
  double amp;
  // Beam orientation (radians)
  double alpha;
};

#endif // end of GUARD_BEAM_H
