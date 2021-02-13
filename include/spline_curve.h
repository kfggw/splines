#ifndef SPLINE_CURVE_H
#define SPLINE_CURVE_H
#include "ndarray.h"

using Point3D = Array3D;
using Point4D = Array4D;

using Vector3D = Array3D;
using vector4D = Array4D;

/**
 * @brief SplineCurve
 *
 */
class SplineCurve {
public:
  virtual Point3D D0(double t) const = 0;

  virtual Vector3D D1(double t) const = 0;

  virtual Vector3D D2(double t) const = 0;
};

#endif