#ifndef _HOWNBROWN_H_
#define _HOWNBROWN_H_
#include "../../Material.d/material.h"


class Material_HKB: public StructProp{
    double cm[14];
      private:
    double dBulk,dShear,dYoung,dPoisson,dSigci,dMb,dS,dA,dS3cv;
    double dDEP;
    int iMTab,iSTab,iATab,iCTab,iMULTab;
	double dE1,dE2,dG2,dF,dIts;
    unsigned uiMTab,uiSTab,uiATab,uiCTab,uiMULTab;
public:
Material_HKB();
Material_HKB(int num,int nprops, double *props);
double* getprops(double * = 0);
 double calcmass(double);
 int calcstress(double*,double*,double*,double,double,int&,int&);
 double getwavespeed();
 double getdensity();
 int gettype(){ return 5; }
 int getnprops(){return 14; }
 int mathb(double* , double* , double* , double* , double , double, int&,int& );
 int init();
};


#endif
