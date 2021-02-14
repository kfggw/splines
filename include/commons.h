#ifndef COMMONS_H
#define COMMONS_H
#include <iostream>
#include <istream>
#include <ostream>

using StdIn = std::istream;
using StdOut = std::ostream;

/**
 * @brief CurveConfig
 *
 */
struct CurveConfig {
  static const int kBezierMaxDegree;
  static const int kBSplineMaxDegree;
};

class Array3D;
class Array4D;

using Point3D = Array3D;
using Point4D = Array4D;

using Vector3D = Array3D;
using vector4D = Array4D;

#endif