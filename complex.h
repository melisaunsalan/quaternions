#ifndef QUATERNION_COMPLEX_H
#define QUATERNION_COMPLEX_H

#include <iostream>
#include <cmath>
using namespace std;

class Complex {
 private:
  double r,i;
 public:
  friend ostream& operator<<(ostream&, Complex);
  friend istream& operator>>(istream&, Complex&);
  void print();
  double norm();
  Complex();
  Complex(double r);
  Complex(double r, double i);
  Complex operator=(Complex z);
  Complex operator!();
  Complex operator-();
  Complex operator+(Complex z);
  Complex operator*(Complex z);
  Complex operator*(double a);
  Complex operator/(double a);
  Complex inverse();
  Complex unit();
  Complex _2D_Rotation(double angle);
};

Complex :: Complex() {
  r=i=0;
}

Complex :: Complex(double r) {
  this->r=r;
  this->i=0;
}

Complex :: Complex(double r, double i) {
  this->r=r;
  this->i=i;
}

void Complex :: print() {
  cout<<r<<" + "<<i<<"i"<<endl;
}

double Complex :: norm() {
  return sqrt(r*r+i*i);
}

Complex Complex :: operator=(Complex z) {
  this->r=z.r;
  this->i=z.i;
  return *this;
}

Complex Complex :: operator!() {
  return Complex(this->r,-this->i);
}

Complex Complex :: operator-() {
  return Complex(-this->r,-this->i);
}

Complex Complex :: operator+(Complex z) {
  Complex tmp;
  tmp.r=this->r+z.r;
  tmp.i=this->i+z.i;
  return tmp;
}

Complex Complex :: operator*(Complex z) {
  Complex tmp;
  tmp.r=this->r*z.r-this->i*z.i;
  tmp.i=this->r*z.i+this->i*z.r;
  return tmp;
}

Complex Complex :: operator*(double a) {
  return Complex(this->r*a,this->i*a);
}

Complex Complex :: operator/(double a) {
  return Complex(this->r/a,this->i/a);
}

Complex Complex :: inverse() {
  Complex tmp=*this;
  return !tmp/(tmp.norm()*tmp.norm());
}

Complex Complex :: unit() {
  if(!this->norm())
    exit(1);
  else
    return *this/this->norm();
}

ostream& operator<<(ostream& os, Complex z) {
  os<<z.r<<" + "<<z.i<<"i"<<endl;
  return os;
}

istream& operator>>(istream& is, Complex& z) {
  is>>z.r;
  is>>z.i;
  return is;
}


#endif //QUATERNION_COMPLEX_H
