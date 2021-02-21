#include "ndarray.h"

Array3D::Array3D() : x_(0), y_(0), z_(0) {}

Array3D::Array3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

Array3D::Array3D(const Array3D &other)
    : x_(other.X()), y_(other.Y()), z_(other.Z()) {}

Array3D Array3D::operator+(const Array3D &other) const {
  double x = x_ + other.X();
  double y = y_ + other.Y();
  double z = z_ + other.Z();

  return Array3D(x, y, z);
}

Array3D &Array3D::operator+=(const Array3D &other) {
  x_ += other.X();
  y_ += other.Y();
  z_ += other.Z();
  return *this;
}

Array3D Array3D::operator-(const Array3D &other) const {
  double x = x_ - other.X();
  double y = y_ - other.Y();
  double z = z_ - other.Z();

  return Array3D(x, y, z);
}

Array3D &Array3D::operator-=(const Array3D &other) {
  x_ -= other.X();
  y_ -= other.Y();
  z_ -= other.Z();
  return *this;
}

Array3D &Array3D::operator=(const Array3D &other) {
  x_ = other.X();
  y_ = other.Y();
  z_ = other.Z();
  return *this;
}

inline double Array3D::X() const { return x_; }
inline double Array3D::Y() const { return y_; }
inline double Array3D::Z() const { return z_; }

inline Array3D &Array3D::X(double x) {
  x_ = x;
  return *this;
}

inline Array3D &Array3D::Y(double y) {
  y_ = y;
  return *this;
}

inline Array3D &Array3D::Z(double z) {
  z_ = z;
  return *this;
}

Array3D operator*(const Array3D &array, const double &factor) {
  return Array3D(array.X() * factor, array.Y() * factor, array.Z() * factor);
}

Array3D operator*(const double &factor, const Array3D &array) {
  return array * factor;
}

StdOut &operator<<(StdOut &os, const Array3D &array) {
  os << array.X() << ", " << array.Y() << ", " << array.Z();
  return os;
}

Array4D::Array4D() : Array3D(), w_(1) {}

Array4D::Array4D(double x, double y, double z, double w)
    : Array3D(x, y, z), w_(w) {}

Array4D::Array4D(const Array4D &other) : Array3D(other), w_(other.W()) {}

Array4D Array4D::operator+(const Array4D &other) const {
  return Array4D(X() + other.X(), Y() + other.Y(), Z() + other.Z(),
                 W() + other.W());
}

Array4D &Array4D::operator+=(const Array4D &other) {
  double x = X();
  double y = Y();
  double z = Z();
  double w = W();
  X(x + other.X()).Y(y + other.Y()).Z(z + other.Z());
  W(w + other.W());
  return *this;
}

Array4D Array4D::operator-(const Array4D &other) const {
  return Array4D(X() - other.X(), Y() - other.Y(), Z() - other.Z(),
                 W() - other.W());
}

Array4D &Array4D::operator-=(const Array4D &other) {
  double x = X();
  double y = Y();
  double z = Z();
  double w = W();
  X(x - other.X()).Y(y - other.Y()).Z(z - other.Z());
  W(w - other.W());
  return *this;
}

Array4D &Array4D::operator=(const Array4D &other) {
  X(other.X()).Y(other.Y()).Z(other.Z());
  w_ = other.W();
  return *this;
}

inline double Array4D::W() const { return w_; }

inline Array4D &Array4D::W(double w) {
  w_ = w;
  return *this;
}

Array4D operator*(const Array4D &array, const double &factor) {
  return Array4D(array.X() * factor, array.Y() * factor, array.Z() * factor,
                 array.W() * factor);
}

Array4D operator*(const double &factor, const Array4D &array) {
  return array * factor;
}

StdOut &operator<<(StdOut &os, const Array4D &array) {
  os << array.X() << ", " << array.Y() << ", " << array.Z() << ", "
     << array.W();
  return os;
}
