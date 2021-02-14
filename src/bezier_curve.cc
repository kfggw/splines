#include "bezier_curve.h"
#include "commons.h"
#include <cassert>
#include <iostream>
#include <vector>

BezierCurve::BezierCurve(bool is_rational) : is_rational_(is_rational) {}

BezierCurve::BezierCurve(std::vector<Point3D> poles)
    : is_rational_(false), poles_(poles) {}

BezierCurve::BezierCurve(std::vector<Point3D> poles,
                         std::vector<double> weights)
    : is_rational_(true), poles_(poles), weights_(weights) {
  // TODO: 检查控制顶点和权重是否满足条件
}

/**
 * @brief 设置Bezier曲线的控制顶点
 *
 * @param poles
 */
void BezierCurve::SetPoles(std::vector<Point3D> poles) {
  poles_.assign(poles.begin(), poles.end());
}

/**
 * @brief 设置Bezier曲线控制顶点的权重, 只在有理Bezier条件下有效
 *
 * @param weights
 */
void BezierCurve::SetWeights(std::vector<double> weights) {
  if (is_rational_)
    weights_.assign(weights.begin(), weights.end());
}

Point3D BezierCurve::D0(double t) const {
  if (is_rational_)
    return D0OfRational(t);
  else
    return D0OfNonRational(t);
}

Vector3D BezierCurve::D1(double t) const { return Vector3D(); }

Vector3D BezierCurve::D2(double t) const { return Vector3D(); }

Point3D BezierCurve::D0OfRational(double t) const {
  assert(t >= 0 && t <= 1);
  int size = poles_.size();
  assert(size == weights_.size());

  std::vector<Point4D> buf(size);
  for (int i = 0; i < size; ++i) {
    buf[i] = DimUp(poles_[i], weights_[i]);
  }

  int n = size - 1;
  // 递推n次
  for (int L = 1; L <= n; ++L) {
    for (int i = 0; i <= n - L; ++i) {
      buf[i] = (1 - t) * buf[i] + t * buf[i + 1];
    }
  }

  return DimDown(buf[0]);
}

Point3D BezierCurve::D0OfNonRational(double t) const {
  assert(t >= 0 && t <= 1);

  int n = poles_.size() - 1;
  std::vector<Point3D> buf(poles_.begin(), poles_.end());

  // 递推n次
  for (int L = 1; L <= n; ++L) {
    for (int i = 0; i <= n - L; ++i) {
      buf[i] = (1 - t) * buf[i] + t * buf[i + 1];
    }
  }

  return buf[0];
}

Vector3D BezierCurve::D1OfRational(double t) const {
  assert(t >= 0 && t <= 1);
  int size = poles_.size();
  assert(size == weights_.size());

  int n = size - 1;
  // 升到4D
  std::vector<Point4D> buf1(n + 1);
  std::vector<Point4D> buf2(n + 1);
  for (int i = 0; i < n + 1; ++i) {
    buf1[i] = DimUp(poles_[i], weights_[i]);
    buf2[i] = buf1[i];
  }

  // 递推1次得到n个控制顶点
  for (int i = 0; i < n; ++i) {
    buf1[i] = n * (buf1[i + 1] - buf1[i]);
  }

  // 递推n-1次, 得到4D空间内的1阶导矢
  for (int L = 1; L <= n - 1; ++L) {
    for (int i = 0; i < n - L; ++i) {
      buf1[i] = (1 - t) * buf1[i] + t * buf1[i + 1];
    }
  }

  // 递推n次, 得到4D空间内的曲线上的点
  for (int L = 1; L <= n; ++L) {
    for (int i = 0; i <= n - L; ++i) {
      buf2[i] = (1 - t) * buf2[i] + t * buf2[i + 1];
    }
  }

  Point4D pt4d1 = buf2[0];
  Point4D pt4d2 = pt4d1 + buf1[0];

  return DimDown(pt4d2) - DimDown(pt4d1);
}

Vector3D BezierCurve::D1OfNonRational(double t) const {
  assert(t >= 0 && t <= 1);
  int n = poles_.size() - 1;
  // 递推1次, 得到新的控制顶点
  std::vector<Point3D> buf{poles_};
  for (int i = 0; i <= n - 1; ++i) {
    buf[i] = (1 - t) * buf[i] + t * buf[i + 1];
  }

  // 递推n-1次, 得到1阶导矢
  for (int L = 1; L <= n - 1; ++L) {
    for (int i = 0; i < n - L; ++i) {
      buf[i] = (1 - t) * buf[i] + t * buf[i + 1];
    }
  }

  return buf[0];
}