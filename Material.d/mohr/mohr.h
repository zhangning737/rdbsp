#ifndef _MOHR_H_
#define _MOHR_H_
#include "../../Material.d/material.h"


class Material_Mohr: public StructProp{
    double cm[7];
      private:
    double dBulk,dShear,dCohesion,dFriction,dDilation,dTension,dYoung,dPoisson;
    double dE1,dE2,dG2,dNPH,dCSN,dSC1,dSC2,dSC3,dBISC,dE21;
	double dRnps;

public:
Material_Mohr();
Material_Mohr(int num,int nprops, double *props);
double* getprops(double * = 0);
 double calcmass(double);
 int calcstress(double*,double*,double*,double,double,int&,int&);
 double getwavespeed();
 double getdensity();
 int gettype(){ return 2; }
 int getnprops(){return 7; }
 int matmohr(double* , double* , double* , double* , double , double, int&,int& );
 int init();
};


#endif
