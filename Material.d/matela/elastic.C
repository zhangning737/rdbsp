
#include <math.h>

#include "../../Material.d/matela/elastic.h"
#include "../../Utils.d/linkfc.h"

const double d4d3 = 4.0 / 3.;
const double d2d3 = 2.0 / 3.;

extern "C" {
void _FORTRAN(mat1)(double*, double*, double*, double*, double&, double&, int&);
}

Material_Ela::Material_Ela(int num, int nprops, double* props) {
  if (nprops != 3)
    fprintf(stderr, "Warning: The number of elastic material is correct\n");
  matnum = num;
  cm[0] = props[0];
  cm[1] = props[1];
  cm[2] = props[2];
}

double* Material_Ela::getprops(double* p) {
  if (p == 0) p = new double[3];
  p[0] = cm[0];
  p[1] = cm[1];
  p[2] = cm[2];

  return p;
}

double Material_Ela::calcmass(double evol) {
  double density = cm[0];
  double mass = evol * density;
  return mass;
}

double Material_Ela::getdensity() {
  double density = cm[0];
  return density;
}

int Material_Ela::init() {
  dBulk = cm[1] / 3 / (1 - 2.0 * cm[2]);
  dShear = cm[1] / 2 / (1 + cm[2]);

  dE1 = dBulk + d4d3 * dShear;
  dE2 = dBulk - d2d3 * dShear;
  dG2 = 2.0 * dShear;
  return (0);
}

int Material_Ela::calcstress(double* sig, double* eps, double* his, double dt,
                             double tt, int& ps, int& fail) {
  // double mm[2];
  // mm[0]= cm[1];
  // mm[1] =cm[2];
  //_FORTRAN(mat1)((double*)mm,(double*)eps,(double*)sig,(double*)his, dt,tt,
  //ps);

  double dE11 = eps[0];
  double dE22 = eps[1];
  double dE33 = eps[2];
  sig[0] += (dE22 + dE33) * dE2 + dE11 * dE1;
  sig[1] += (dE11 + dE33) * dE2 + dE22 * dE1;
  sig[2] += (dE11 + dE22) * dE2 + dE33 * dE1;
  sig[3] += eps[3] * dG2;
  sig[4] += eps[4] * dG2;
  sig[5] += eps[5] * dG2;

  return 0;
}

double Material_Ela::getwavespeed() {
  double rho = cm[0];
  double E = cm[1];
  double mu = cm[2];
  double wavespeed = sqrt(E * (1 - mu) / ((1 + mu) * (1 - 2 * mu) * rho));
  return wavespeed;
}
