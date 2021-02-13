#ifndef BEZIER_CURVE_H
#define BEZIER_CURVE_H

#include "spline_curve.h"

// BezierCurve, 控制顶点, 有理, 权重

/**
 * @brief BezierCurve
 *
 */
class BezierCurve : public SplineCurve {
public:
  BezierCurve();

public:
  Point3D D0(double t) const override;

  Vector3D D1(double t) const override;

  Vector3D D2(double t) const override;
};

#endif