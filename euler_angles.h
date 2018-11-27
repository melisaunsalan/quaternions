#ifndef QUATERNION_EULER_ANGLES_H
#define QUATERNION_EULER_ANGLES_H

#include <iostream>
#include <cmath>
using namespace std;

class Quaternion;

class Euler_Angles {
  double yaw;     // giratie   // heading z
  double pitch;   // tangaj    // pitch   y
  double roll;    // ruliu     // bank    x
 public:
  friend class Quaternion;
  friend ostream& operator<<(ostream&, Euler_Angles);
  friend istream& operator>>(istream&, Euler_Angles&);
  Euler_Angles();
  Euler_Angles(double yaw, double pitch, double roll);
  Euler_Angles rad();
  Euler_Angles deg();
  friend Euler_Angles Quaternion_to_Euler_Angles(Quaternion q);
  friend Quaternion Euler_Angles_to_Quaternion(Euler_Angles ea);
};

Euler_Angles :: Euler_Angles() {
  yaw=pitch=roll=0;
}

Euler_Angles :: Euler_Angles(double yaw, double pitch, double roll) {
  this->yaw=yaw;
  this->pitch=pitch;
  this->roll=roll;
}

Euler_Angles Euler_Angles :: rad() {
  this->pitch=this->pitch*2*3.1415/360;
  this->yaw=this->yaw*2*3.1415/360;
  this->roll=this->roll*2*3.1415/360;
  return *this;
}

Euler_Angles Euler_Angles :: deg() {
  this->pitch=this->pitch*360/(2*3.1415);
  this->yaw=this->yaw*360/(2*3.1415);
  this->roll=this->roll*360/(2*3.1415);
  return *this;
}


ostream& operator<<(ostream& os, Euler_Angles ea) {
  os<<"Roll= "<<ea.roll<<endl;
  os<<"Pitch= "<<ea.pitch<<endl;
  os<<"Yaw= "<<ea.yaw<<endl;

  cout<<endl;
}

istream& operator>>(istream& is, Euler_Angles& ea) {
  is>>ea.roll;
  is>>ea.pitch;
  is>>ea.yaw;
  return is;
}




#endif //QUATERNION_EULER_ANGLES_H
