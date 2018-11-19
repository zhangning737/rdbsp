#ifndef _DP_H_
#define _DP_H_
#include "../../Material.d/material.h"


class Material_DP: public StructProp{
    double cm[7];
      private:
    double dBulk,dShear,dYoung,dPoisson,dQPhi,dKPhi,dQPsi,dTension;
    double dE1,dE2,dG2,dGKQ,dKQ,dTAnd,dFACG;
	double dShearNew;

public:
Material_DP();
Material_DP(int num,int nprops, double *props);
double* getprops(double * = 0);
 double calcmass(double);
 int calcstress(double*,double*,double*,double,double,int&,int&);
 double getwavespeed();
 double getdensity();
 int gettype(){ return 3; }
 int getnprops(){return 7; }
 int matdp(double* , double* , double* , double* , double , double, int&,int& );
 int init();
};


#endif
