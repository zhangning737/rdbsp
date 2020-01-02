
#include <math.h>

#include "../../Material.d/mohr/mohr.h"
#include "../../Math.d/egen.h"
#include "../../Utils.d/linkfc.h"
#include "../Prin2Stress.h"
#include "../Stress_Prin.h"

static const double d2d3 = 2.0 / 3.0;
static const double d4d3 = 4.0 / 3.0;
static const double dPi = 3.141592653589793238462643383279502884197169399;
static const double dDegRad = dPi / 180.0;

// Plasticity Indicators
static const int mShearNow = 0x01; /* state logic */
static const int mTensionNow = 0x02;
static const int mShearPast = 0x04;
static const int mTensionPast = 0x08;

Material_Mohr::Material_Mohr(int num, int nprops, double* props) {
  if (nprops != 6)
    fprintf(stderr, "Warning: The number of elastic material is correct\n");
  matnum = num;
  cm[0] = props[0];
  cm[1] = props[1];
  cm[2] = props[2];
  cm[3] = props[3];
  cm[4] = props[4];
  cm[5] = props[5];
  cm[6] = props[6];
}

double* Material_Mohr::getprops(double* p) {
  if (p == 0) p = new double[3];
  p[0] = cm[0];
  p[1] = cm[1];
  p[2] = cm[2];
  p[3] = cm[3];
  p[4] = cm[4];
  p[5] = cm[5];
  p[6] = cm[6];
  return p;
}

double Material_Mohr::calcmass(double evol) {
  double density = cm[0];
  double mass = evol * density;
  return mass;
}

double Material_Mohr::getdensity() {
  double density = cm[0];
  return density;
}

int Material_Mohr::calcstress(double* sig, double* eps, double* his, double dt,
                              double tt, int& ps, int& fail) {
  double mm[6];
  mm[0] = cm[1];
  mm[1] = cm[2];
  mm[2] = cm[3];
  mm[3] = cm[4];
  mm[4] = cm[5];
  mm[5] = cm[6];

  matmohr((double*)mm, (double*)eps, (double*)sig, (double*)his, dt, tt, ps,
          fail);

  return 0;
}

double Material_Mohr::getwavespeed() {
  double rho = cm[0];
  double E = cm[1];
  double mu = cm[2];
  double wavespeed = sqrt(E * (1 - mu) / ((1 + mu) * (1 - 2 * mu) * rho));
  return wavespeed;
}

int Material_Mohr::init() {
  dYoung = cm[1];
  dPoisson = cm[2];
  dCohesion = cm[3];
  dFriction = cm[4];
  dDilation = cm[5];
  dTension = cm[6];

  dBulk = dYoung / (1.0 - 2.0 * dPoisson) / 3.0;
  dShear = dYoung / (1.0 + dPoisson) / 2.0;

  dE1 = dBulk + d4d3 * dShear;
  dE2 = dBulk - d2d3 * dShear;
  dG2 = 2.0 * dShear;
  double dRsin = sin(dFriction * dDegRad);
  dNPH = (1.0 + dRsin) / (1.0 - dRsin);
  dCSN = 2.0 * dCohesion * sqrt(dNPH);
  if (dFriction) {
    double dApex = dCohesion * cos(dFriction * dDegRad) / dRsin;
    dTension = dTension < dApex ? dTension : dApex;
  }
  dRsin = sin(dDilation * dDegRad);
  dRnps = (1.0 + dRsin) / (1.0 - dRsin);
  double dRa = dE1 - dRnps * dE2;
  double dRb = dE2 - dRnps * dE1;
  double dRd = dRa - dRb * dNPH;
  dSC1 = dRa / dRd;
  dSC3 = dRb / dRd;
  dSC2 = dE2 * (1.0 - dRnps) / dRd;
  dBISC = sqrt(1.0 + dNPH * dNPH) + dNPH;
  dE21 = dE2 / dE1;
  return 0;
}

int Material_Mohr::matmohr(double* mm, double* eps, double* sig, double* his,
                           double dt, double tt, int& iPlas, int& fail) {
  int plas, i, j, k;

  // double dYoung, dPoisson, dCohesion, dFriction, dDilation, dTension;
  // double dBulk, dShear;

  // double dE1, dE2, dG2;
  // double dNPH, dCSN, dRnps;
  // double dSC1, dSC2, dSC3, dBISC, dE21;
  plas = 0;

  if (iPlas & mShearNow) iPlas = (iPlas | mShearPast);
  iPlas = (iPlas & ~mShearNow);
  if (iPlas & mTensionNow) iPlas = (iPlas | mTensionPast);
  iPlas = (iPlas & ~mTensionNow);

  /* --- plasticity indicator:                                  */
  /*     store 'now' info. as 'past' and turn 'now' info off ---*/
  double dTeTens = dTension;
  /*
  double trace;
  trace = eps[0]+eps[1] +eps[2];
  sig[0] += dG2*(eps[0]-trace/3.) + dBulk* trace;
  sig[1] += dG2*(eps[1]-trace/3.) + dBulk* trace;
  sig[2] += dG2*(eps[2]-trace/3.) + dBulk* trace;
  sig[3] += eps[3] * dG2;
  sig[4] += eps[4] * dG2;
  sig[5] += eps[5] * dG2;
  */
  /* --- trial elastic stresses --- */

  double dE11 = eps[0];
  double dE22 = eps[1];
  double dE33 = eps[2];
  double dE12 = eps[3];
  double dE23 = eps[4];
  double dE13 = eps[5];

  sig[0] += dE11 * dE1 + (dE22 + dE33) * dE2;
  sig[1] += (dE11 + dE33) * dE2 + dE22 * dE1;
  sig[2] += (dE11 + dE22) * dE2 + dE33 * dE1;
  sig[3] += dE12 * dG2;
  sig[4] += dE23 * dG2;
  sig[5] += dE13 * dG2;

  /* --- calculate and sort ps->incips->l stresses and ps->incips->l directions
   * --- */
  double ps[3], dir[9];
  double dPrinMin, dPrinMid, dPrinMax;

  princ_stress(sig, dir, ps);

  //  jaco_(sig, ps, dir);

  dPrinMin = ps[0];
  dPrinMid = ps[1];
  dPrinMax = ps[2];

  double dPrinMinCopy = dPrinMin;
  double dPrinMidCopy = dPrinMid;
  double dPrinMaxCopy = dPrinMax;
  /* --- Mohr-Coulomb failure criterion --- */
  double dFsurf = dPrinMin - dNPH * dPrinMax + dCSN;
  /* --- Tensile failure criteria --- */
  double dTsurf = dTension - dPrinMax;
  double dPdiv = -dTsurf + (dPrinMin - dNPH * dTension + dCSN) * dBISC;
  /* --- tests for failure */
  if (dFsurf < 0.0 && dPdiv < 0.0) {
    iPlas = (iPlas | 0x01);
    plas = 1;
    //     jaco_(sig, ps,  dir);
    /* --- shear failure: correction to ps->incips->l stresses ---*/
    dPrinMin -= dFsurf * dSC1;
    dPrinMid -= dFsurf * dSC2;
    dPrinMax -= dFsurf * dSC3;
  } else if (dTsurf < 0.0 && dPdiv > 0.0) {
    iPlas = (iPlas | 0x02);

    /* --- tension failure: correction to ps->incips->l stresses ---*/
    double dTco = dE21 * dTsurf;
    plas = 2;

    dPrinMin += dTco;
    dPrinMid += dTco;
    dPrinMax = dTension;
  }
  if (plas) {
    ps[0] = dPrinMin;
    ps[1] = dPrinMid;
    ps[2] = dPrinMax;
    princ2stress(sig, dir, ps);

    //    ps->stnS.Resoltoglob(dPrinMin,dPrinMid, dPrinMax, aDir,
    //    dPrinMinCopy,dPrinMidCopy,dPrinMaxCopy, uDim, icase, sdif,  psdif,
    //    bFast);
  }
  return (0);
}
