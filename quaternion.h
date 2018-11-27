#ifndef QUATERNION_QUATERNION_H
#define QUATERNION_QUATERNION_H

#include <iostream>
#include <cmath>
#include "complex.h"
using namespace std;

class Euler_Angles;

class Quaternion {
 private:
  double u;
 protected:
  double i,j,k;
 public:
  friend class Euler_Angles;
  friend istream& operator>>(istream&, Quaternion&);
  friend ostream& operator<<(ostream&, Quaternion);
  friend void print_coord(Quaternion q);
  void print();
  Quaternion();
  Quaternion(double u);
  Quaternion(double u,double i);
  Quaternion(double u,double i,double j,double k);
  double norm();
  double norm1(); //The norm calculated using qxq*
  Quaternion operator=(Quaternion Q);
  Quaternion operator!(); // The NOT operator is used as a conjugate here
  Quaternion operator-();
  Quaternion operator+(Quaternion A);
  Quaternion operator*(double a);
  Quaternion operator/(double a);
  Quaternion operator*(Quaternion A);
  Quaternion inverse();
  Quaternion unit();
  Quaternion _3D_Rotation(Quaternion dir, double angle);
  friend Quaternion ijk();
  friend Euler_Angles Quaternion_to_Euler_Angles(Quaternion q);
  friend Quaternion Euler_Angles_to_Quaternion(Euler_Angles ea);
};

void Quaternion ::print() {
  cout<<this->u<<" + "<<this->i<<"i + "<<this->j<<"j+ "<<this->k<<"k "<<endl;
}

Quaternion :: Quaternion() {
  u=i=j=k=0;
}

Quaternion :: Quaternion(double u) {
  this->u=u;
  i=j=k=0;
}

Quaternion :: Quaternion(double u, double i) {
  this->u=u;
  this->i=i;
  j=k=0;
}

Quaternion :: Quaternion(double u, double i, double j, double k) {
  this->u=u;
  this->i=i;
  this->j=j;
  this->k=k;
}

double Quaternion :: norm() {
  return sqrt(u*u+i*i+j*j+k*k);
}

Quaternion Quaternion :: operator=(Quaternion Q) {
  this->u=Q.u;
  this->i=Q.i;
  this->j=Q.j;
  this->k=Q.k;
  return *this;
}

Quaternion Quaternion :: operator-(){
  Quaternion tmp;
  tmp.u=-this->u;
  tmp.i=-this->i;
  tmp.j=-this->j;
  tmp.k=-this->k;
  return tmp;
}

Quaternion Quaternion :: operator+(Quaternion A) {
  Quaternion tmp;
  tmp.u=this->u+A.u;
  tmp.i=this->i+A.i;
  tmp.j=this->j+A.j;
  tmp.k=this->k+A.k;
  return tmp;
}

Quaternion Quaternion :: operator!() {
  Quaternion q(this->u,-this->i,-this->j,-this->k);
  return q;
}

Quaternion Quaternion :: operator*(double a) {
  Quaternion q;
  q.u=this->u*a;
  q.i=this->i*a;
  q.j=this->j*a;
  q.k=this->k*a;
  return q;
}

Quaternion Quaternion :: operator/(double a) {
  Quaternion q;
  q.u=this->u/a;
  q.i=this->i/a;
  q.j=this->j/a;
  q.k=this->k/a;
  return q;
}

Quaternion Quaternion :: operator*(Quaternion A) {
  Quaternion q;
  q.u=this->u*A.u-this->i*A.i-this->j*A.j-this->k*A.k;
  q.i=this->u*A.i+this->i*A.u+this->j*A.k-this->k*A.j;
  q.j=this->u*A.j+this->j*A.u-this->i*A.k+this->k*A.i;
  q.k=this->u*A.k+this->k*A.u+this->i*A.j-this->j*A.i;
  return q;
}

Quaternion Quaternion :: inverse() {
  Quaternion q=*this;
  return !q/(q.norm()*q.norm());
}

double Quaternion :: norm1() {
  Quaternion q=*this;
  return (q*(!q)).u;
}

Quaternion Quaternion :: unit() {
  if(!this->norm())
    exit(1);
  else
    return *this/this->norm();
}

Quaternion ijk() {
  Quaternion i(0,1,0,0);
  Quaternion j(0,0,1,0);
  Quaternion k(0,0,0,1);
  return i*j*k;
}

ostream& operator<<(ostream& os, Quaternion q) {
  os<<q.u<<" + "<<q.i<<"i + "<<q.j<<"j+ "<<q.k<<"k "<<endl;
  return os;
}

istream& operator>>(istream& is, Quaternion& q) {
  is>>q.u;
  is>>q.i;
  is>>q.j;
  is>>q.k;
  return is;
}

void print_coord(Quaternion q) {
  cout<<"The coordinated of the point are:  ("<<q.i<<", "<<q.j<<", "<<q.k<<")"<<endl;
}


class Pure_Quaternion : public Quaternion {
  double u;
 public:
  Pure_Quaternion (double i, double j, double k) : Quaternion(0) {
    this->i=i;
    this->j=j;
    this->k=k;
  }
};


#endif //QUATERNION_QUATERNION_H
