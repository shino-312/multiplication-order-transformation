/**
 * @brief  Test program of multiplication order of transformation matrix
 * @date   Apr. 19, 2020
 */
#include <iostream>
#include <iomanip>
#include <eigen3/Eigen/Dense>

#define _USE_MATH_DEFINES
#include <cmath>

int main(void) {
  using namespace Eigen;

  // Create transformation matrix
  // T_1 represents 90 deg rotation on x-axis
  // T_2 represents 180 deg rotation on z-axis
  Translation3f trans(0., 0., 0.);
  AngleAxisf rot1(M_PI_2, Vector3f::UnitX());
  AngleAxisf rot2(M_PI, Vector3f::UnitZ());

  Affine3f T1(trans * rot1);
  Affine3f T2(trans * rot2);

  Vector3f P(0., 0., 1.);

  // Extrinsic transformation
  Vector3f Pe = (T2 * T1) * P;

  // Intrinsic transformation
  Vector3f Pi = (T1 * T2) * P;

  // Show result
  std::cout << std::fixed;
  std::cout
    << "Extrinsic transformation: " << std::endl
    << Pe
    << std::endl
    << "Intrinsic transformation: " << std::endl
    << Pi
    << std::endl;

  return 0;
}
