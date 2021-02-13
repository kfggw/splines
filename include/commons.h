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

#endif