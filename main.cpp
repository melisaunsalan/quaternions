#include <iostream>
#include "quaternion.h"
#include "complex.h"
#include <cmath>
#include "euler_angles.h"

#define PI 3.1415

using namespace std;

double deg2rad(double d) {
  return d*2*PI/360;
}

double rad2deg(double r) {
  return r*360/(2*PI);
}

Quaternion Quaternion :: _3D_Rotation(Quaternion dir, double angle) {
  dir=dir.unit();
  Quaternion q(cos(angle/2),sin(angle/2)*dir.i, sin(angle/2)*dir.j, sin(angle/2)*dir.k);
  Quaternion tmp=q*(*this)*q.inverse();
  if(tmp.u<1e-10)
    tmp.u=0;
  return tmp;
}

Complex Complex ::_2D_Rotation(double angle) {
  return Complex(cos(angle),sin(angle))*(*this);
}

Euler_Angles Quaternion_to_Euler_Angles (Quaternion q) {
  Euler_Angles tmp;
  tmp.roll=atan(2*(q.u*q.i+q.j*q.k)/(1-2*(q.i*q.i+q.j*q.j)));
  tmp.pitch=asin(2*(q.u*q.j-q.k*q.i));
  tmp.yaw=atan(2*(q.u*q.k+q.i*q.j)/(1-2*(q.j*q.j+q.k*q.k)));
  return tmp;
}

Quaternion Euler_Angles_to_Quaternion(Euler_Angles ea) {
  double cy = cos(ea.yaw/2);
  double sy = sin(ea.yaw/2);
  double cr = cos(ea.roll/2);
  double sr = sin(ea.roll/2);
  double cp = cos(ea.pitch/2);
  double sp = sin(ea.pitch/2);
  Quaternion tmp;
  tmp.u=cy * cr * cp + sy * sr * sp;
  tmp.i=cy * sr * cp - sy * cr * sp;
  tmp.j=cy * cr * sp + sy * sr * cp;
  tmp.k=sy * cr * cp - cy * sr * sp;
  return tmp;
}

int main() {
  Quaternion Point(0,3,4,5);
  Quaternion dir(0,2,4,1);
  double theta=60;
  theta=deg2rad(theta);
  Quaternion Rotated_Point=Point._3D_Rotation(dir,theta);
  print_coord(Rotated_Point);
  cout<<"ijk= "<<ijk();
  

  return 0;
}