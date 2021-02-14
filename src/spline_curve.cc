#include "spline_curve.h"

Point4D SplineCurve::DimUp(const Point3D &pt3d, const double &weight) {
  // TODO: 检查weight
  return Point4D(pt3d.X() * weight, pt3d.Y() * weight, pt3d.Z() * weight,
                 weight);
}

Point3D SplineCurve::DimDown(const Point4D &pt4d) {
  // TODO: 检查weight
  double weight = pt4d.W();
  return Point3D(pt4d.X() / weight, pt4d.Y() / weight, pt4d.Z() / weight);
}