#ifndef SPLINE_CURVE_H
#define SPLINE_CURVE_H
#include "commons.h"
#include "ndarray.h"

/**
 * @brief SplineCurve
 *
 */
class SplineCurve {
public:
  /**
   * @brief 计算参数t对应的曲线上点
   *
   * @param t
   * @return Point3D
   */
  virtual Point3D D0(double t) const = 0;

  /**
   * @brief 计算参数t对应的曲线的一阶导矢
   *
   * @param t
   * @return Vector3D
   */
  virtual Vector3D D1(double t) const = 0;

  /**
   * @brief 计算参数t对应的曲线的二阶导矢
   *
   * @param t
   * @return Vector3D
   */
  virtual Vector3D D2(double t) const = 0;

public:
  static Point4D DimUp(const Point3D &pt3d, const double &weight);

  static Point3D DimDown(const Point4D &pt4d);
};

#endif