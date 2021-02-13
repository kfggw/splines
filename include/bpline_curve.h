#ifndef BSPLINE_CURVE_H
#define BSPLINE_CURVE_H

#include "spline_curve.h"

/**
 * @brief BSplineCurve
 *
 */
class BSplineCurve : public SplineCurve {
public:
  Point3D D0(double t) const override;

  Vector3D D1(double t) const override;

  Vector3D D2(double t) const override;
};

#endif