
#include "beam.h"

#include <cmath>

double GaussianBeam::operator() (double xpos, double ypos)
{
  double sinalpha = sin(alpha);
  double cosalpha = cos(alpha);
  double dx = xpos - x0;
  double dy = ypos - y0;
  double partx = (dx*cosalpha + dy*sinalpha)/sigmax;
  double party = (-dx*sinalpha + dy*cosalpha)/sigmay;

  return amp*exp(-0.5*(partx*partx + party*party));
}
