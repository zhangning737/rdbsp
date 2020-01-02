#ifndef _ELASTIC_H_
#define _ELASTIC_H_
#include "../../Material.d/material.h"

class Material_Ela : public StructProp {
  double cm[3];

 public:
  Material_Ela();
  Material_Ela(int num, int nprops, double* props);
  double* getprops(double* = 0);
  double calcmass(double);
  int calcstress(double*, double*, double*, double, double, int&, int&);
  double getwavespeed();
  double getdensity();
  int gettype() { return 1; }
  int getnprops() { return 3; }
  int init();

 private:
  double dBulk, dShear, dYoung, dPoisson;
  double dE1, dE2, dG2;
};

#endif
