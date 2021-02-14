#ifndef BEZIER_CURVE_H
#define BEZIER_CURVE_H

#include "commons.h"
#include "spline_curve.h"
#include <vector>

// BezierCurve, 控制顶点, 有理, 权重

/**
 * @brief BezierCurve
 *
 */
class BezierCurve : public SplineCurve {
public:
  BezierCurve(bool is_rational = false);

  BezierCurve(std::vector<Point3D> poles);

  BezierCurve(std::vector<Point3D> poles, std::vector<double> weights);

  void SetPoles(std::vector<Point3D> poles);

  void SetWeights(std::vector<double> weights);

public:
  Point3D D0(double t) const override;

  Vector3D D1(double t) const override;

  Vector3D D2(double t) const override;

private:
  Point3D D0OfRational(double t) const;
  Point3D D0OfNonRational(double t) const;

  Vector3D D1OfRational(double t) const;
  Vector3D D1OfNonRational(double t) const;

private:
  bool is_rational_;
  std::vector<Point3D> poles_;
  std::vector<double> weights_;
};

#endif