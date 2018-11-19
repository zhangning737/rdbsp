#ifndef _MATNULL_H_
#define _MATNULL_H_
#include "../../Material.d/material.h"
class Material_NULL: public StructProp{
public:
Material_NULL();
Material_NULL(int num,int nprops, double *props);
double* getprops(double * = 0);
 double calcmass(double);
 int calcstress(double*,double*,double*,double,double,int&,int&);
 double getwavespeed();
 double getdensity();
 int gettype(){ return 0; }
 int getnprops(){return 0; }
 int init();

};


#endif
