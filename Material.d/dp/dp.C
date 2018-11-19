
#include "../../Material.d/dp/dp.h"
#include "../../Utils.d/linkfc.h"
#include "../../Math.d/egen.h"
#include "../Prin2Stress.h"
#include "../Stress_Prin.h"

#include <math.h>

static const double d2d3 = 2.0 / 3.0;
 static const double d4d3 = 4.0 / 3.0;
static const double dPi  = 3.141592653589793238462643383279502884197169399;
static const double dDegRad = dPi / 180.0;

// Plasticity Indicators
static const int mShearNow    = 0x01;  /* state logic */
static const int mTensionNow  = 0x02;
static const int mShearPast   = 0x04;
static const int mTensionPast = 0x08;

Material_DP::Material_DP(int num, int nprops,double *props)
{
if(nprops!= 6)
fprintf(stderr,"Warning: The number of druck-prager material is correct\n");
    matnum = num;
    cm[0] = props[0];
    cm[1] = props[1];
    cm[2] = props[2];
    cm[3] = props[3];
    cm[4] = props[4];
    cm[5] = props[5];
    cm[6] = props[6];
}


double*
Material_DP::getprops(double *p ){
    if(p == 0) p = new double[3];
    p[0] = cm[0];
    p[1] = cm[1];
    p[2] = cm[2];
    p[3] = cm[3];
    p[4] = cm[4];
    p[5] = cm[5];
    p[6] = cm[6];
    return p;
}

double
Material_DP::calcmass(double evol)
{
    double density = cm[0];
    double mass = evol * density;
    return mass;
}

double
Material_DP::getdensity()
{
    double density = cm[0];
    return density;
}

int
Material_DP::calcstress(double *sig, double *eps, double *his, double dt, double tt, int& ps,int& fail)
{
    double mm[6];
    mm[0]= cm[1];
    mm[1] =cm[2];
    mm[2]= cm[3];
    mm[3] =cm[4];
    mm[4] =cm[5];
    mm[5] =cm[6];

    matdp((double*)mm ,(double*)eps,(double*)sig,(double*)his, dt, tt, ps, fail);

    return 0;
}

double
Material_DP::getwavespeed()
{
    double rho = cm[0];
    double E = cm[1];
    double mu = cm[2];
    double wavespeed = sqrt(E*(1-mu)/((1+mu)*(1-2*mu)*rho));
    return wavespeed;
    
}

int
Material_DP::init()
{
  dYoung    = cm[1];
  dPoisson  = cm[2];
  dQPhi = cm[3];
  dKPhi = cm[4];
  dQPsi = cm[5];
  dTension  = cm[6];

  dBulk = dYoung/ (1.0 -2.0* dPoisson)/3.0 ;
  dShear = dYoung/(1.0+ dPoisson)/2.0 ;
  dShearNew = dShear;


  dE1 = dBulk + d4d3 * dShear;
  dE2 = dBulk - d2d3 * dShear;
  dG2 = 2.0 * dShear;
    dKQ = dBulk * dQPsi;
  dGKQ = dShear + dKQ * dQPhi;
  dTAnd = sqrt(dQPhi * dQPhi + 1.) - dQPhi;
  dFACG = dKPhi - (dQPhi + dTAnd) * dTension;
  /* --- set fTension to cone apex if larger than apex --- */
  double dApex = dTension;
  if (dQPhi) dApex = dKPhi/dQPhi;
  dTension = dApex < dTension ? dApex : dTension;

  return(0);

}

int
Material_DP::matdp(double* mm, double* eps, double* sig, double* his, double dt, double tt, int& iPlas,int& fail) {

    int plas, i ,j ,k;
  plas = 0;
    if (iPlas & mShearNow)
      iPlas = (iPlas | mShearPast);
      iPlas = (iPlas & ~mShearNow);
  if (iPlas & mTensionNow)
      iPlas = (iPlas | mTensionPast);
      iPlas = (iPlas & ~mTensionNow);
      double dE11 = eps[0];
  double dE22 = eps[1];
  double dE33 = eps[2];
  double dE12 = eps[3];
  double dE23 = eps[4];
  double dE13 = eps[5];
  /* --- trial elastic stresses --- */
  sig[0] += dE11 * dE1 + (dE22 + dE33) * dE2;
  sig[1] += (dE11 + dE33) * dE2 + dE22 * dE1;
  sig[2] += (dE11 + dE22) * dE2 + dE33 * dE1;
  sig[3] += dE12 * dG2;
  sig[4] += dE23 * dG2;
  sig[5] += dE13 * dG2;
  /* --- mean stress --- */
  double dSigi = (sig[0] + sig[1] + sig[2]) / 3.0;
  /* --- deviatoric stresses --- */
  double tsig[6];
  tsig[0] = sig[0] - dSigi;
  tsig[1] = sig[1] - dSigi;
  tsig[2] = sig[2] - dSigi;
  tsig[3] = sig[3];
  tsig[4] = sig[4];
  tsig[5] = sig[5];
  /* --- second deviatoric stress invariant --- */
  double dTaui = sqrt(0.5 * (tsig[0] * tsig[0] +
                             tsig[1] * tsig[1] +
                             tsig[2] * tsig[2])
                      + tsig[3] * tsig[3]
                      + tsig[4] * tsig[4]
                      + tsig[5] * tsig[5]);
  /* --- Drucker-Prager yield criterion --- */
  double dFi = dTaui + dQPhi * dSigi - dKPhi;
  /* --- mean stress smaller than tensile strength --- */
  double dDsig = dSigi - dTension;
  if (dDsig < 0.0) {
    if (dFi > 0.) {
      /* --- shear failure --- */
      double dLam = dFi / dGKQ;
      plas = 1;
      iPlas = iPlas | mShearNow;
      /* --- correct second deviatoric stress invariant --- */
      double dTaun = dTaui - dLam * dShearNew;
      /* --- correct volumetric stress --- */
      double dSign = dSigi - dLam * dKQ;
      /* --- correct deviatoric stresses --- */
      double dRat = dTaun / dTaui;
      tsig[0] = tsig[0] * dRat;
      tsig[1] = tsig[1] * dRat;
      tsig[2] = tsig[2] * dRat;
      tsig[3] = tsig[3] * dRat;
      tsig[4] = tsig[4] * dRat;
      tsig[5] = tsig[5] * dRat;
      /* --- new stresses --- */
      sig[0] = tsig[0] + dSign;
      sig[1] = tsig[1] + dSign;
      sig[2] = tsig[2] + dSign;
      sig[3] = tsig[3];
      sig[4] = tsig[4];
      sig[5] = tsig[5];
    }
  } else {
    /* --- mean stress larger than tensile strength --- */
    if (dTaui - dTAnd * dSigi - dFACG > 0.0) {
      /* --- shear failure --- */
      plas = 1;
      iPlas = iPlas | mShearNow;
      double dLam = dFi / dGKQ;
      /* --- correct second deviatoric stress invariant --- */
      double dTaun = dTaui - dLam * dShearNew;
      /* --- correct volumetric stress --- */
      double dSign = dSigi - dLam * dKQ;
      /* --- correct deviatoric stresses --- */
      double dRat = dTaun / dTaui;
      tsig[0] = tsig[0] * dRat;
      tsig[1] = tsig[1] * dRat;
      tsig[2] = tsig[2] * dRat;
      tsig[3] = tsig[3] * dRat;
      tsig[4] = tsig[4] * dRat;
      tsig[5] = tsig[5] * dRat;
      /* --- new stresses --- */
      
      sig[0] = tsig[0] + dSign;
      sig[1] = tsig[1] + dSign;
      sig[2] = tsig[2] + dSign;
      sig[3] = tsig[3];
      sig[4] = tsig[4];
      sig[5] = tsig[5];
    } else {
      /* --- tensile failure --- */
      plas = 2;
      iPlas = iPlas | mTensionNow;
      sig[0] -= dDsig;
      sig[1] -= dDsig;
      sig[2] -= dDsig;
    }
  }

  return(0);

}


