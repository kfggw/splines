#include "bezier_curve.h"
#include <fstream>
#include <iostream>
#include <vector>

using std::ofstream;

int main() {
  std::vector<Point3D> poles{{1, 1, 0}, {10, 5, 0}, {20, 1, 0}, {30, 5, 0}};
  std::vector<double> weights{1, 2, 10, 1};
  ofstream fout("data.txt");
  BezierCurve bezier(poles, weights);
  double t = 0;
  while (t <= 1) {
    Point3D pt3d = bezier.D0(t);
    fout << pt3d << std::endl;
    t += 0.02;
  }
  fout.close();
  return 0;
}