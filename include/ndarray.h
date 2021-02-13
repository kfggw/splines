#ifndef NDARRAY_H
#define NDARRAY_H

#include "commons.h"

/**
 * @brief Array3D
 *
 */
class Array3D {
public:
  Array3D();
  Array3D(double x, double y, double z);

  Array3D(const Array3D &other);

  // operators overload
  Array3D operator+(const Array3D &other) const;
  Array3D &operator+=(const Array3D &other);

  Array3D operator-(const Array3D &other) const;
  Array3D &operator-=(const Array3D &other);

  // Getters and Setters
  double X() const;
  double Y() const;
  double Z() const;

  Array3D &X(double x);
  Array3D &Y(double y);
  Array3D &Z(double z);

private:
  double x_, y_, z_;
};

// Array3D * factor
Array3D operator*(const Array3D &array, const double &factor);
Array3D operator*(const double &factor, const Array3D &array);

StdOut &operator<<(StdOut &os, const Array3D &array);

/**
 * @brief Array4D
 *
 */
class Array4D : public Array3D {
public:
  Array4D();
  Array4D(double x, double y, double z, double w);
  Array4D(const Array4D &other);

  // operators overload
  Array4D operator+(const Array4D &other) const;
  Array4D &operator+=(const Array4D &other);

  Array4D operator-(const Array4D &other) const;
  Array4D &operator-=(const Array4D &other);

  double W() const;
  Array4D &W(double w);

private:
  double w_;
};

// Array4D * factor
Array4D operator*(const Array4D &array, const double &factor);
Array4D operator*(const double &factor, const Array4D &array);

StdOut &operator<<(StdOut &os, const Array4D &array);

#endif