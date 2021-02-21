#include <fstream>
#include <iostream>
#include <vector>

#include "bezier_curve.h"

using std::ofstream;

int main() {
  std::vector<Point3D> poles{{1, 1, 0}, {10, 5, 0}, {20, 1, 0}, {30, 5, 0}};
  std::vector<double> weights{1, 1, 1, 1};
  ofstream fout0("data0.txt");
  ofstream fout1("data1.txt");
  ofstream fout2("data2.txt");
  BezierCurve bezier(poles, weights);
  double t = 0;
  while (t <= 1) {
    Point3D pt3d = bezier.D0(t);
    Vector3D vec3d1 = bezier.D1(t);
    Vector3D vec3d2 = bezier.D2(t);
    fout0 << pt3d << std::endl;
    fout1 << vec3d1 << std::endl;
    fout2 << vec3d2 << std::endl;
    t += 0.02;
  }
  fout0.close();
  fout1.close();
  fout2.close();
  return 0;
}
