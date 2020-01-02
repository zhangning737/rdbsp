#include "../Element.d/Bricko.d/inverse.h"
void princ2stress(double* sig, double* dir, double* ps) {
  double det;
  double pss[3][3], dirt[3][3], idir[3][3], temp_stress[3][3], *idirr,
      dirr[3][3];
  idirr = new double[9];

  int i, j, k;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      dirr[i][j] = dir[i * 3 + j];
      dirt[i][j] = 0.0;
      temp_stress[i][j] = 0.0;
    }
  }

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      pss[i][j] = 0.0;
    }
    pss[i][i] = ps[i];
  }

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      for (k = 0; k < 3; ++k) {
        dirt[i][j] = dirt[i][j] + pss[i][k] * dirr[k][j];
      }
    }
  }

  Inverse3(dir, idirr, det);

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      idir[i][j] = idirr[i * 3 + j];
    }
  }

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      for (k = 0; k < 3; ++k) {
        temp_stress[i][j] = temp_stress[i][j] + idir[i][k] * dirt[k][j];
      }
    }
  }

  for (i = 0; i < 3; ++i) {
    sig[i] = temp_stress[i][i];
  }
  sig[3] = temp_stress[0][1];
  sig[4] = temp_stress[1][2];
  sig[5] = temp_stress[0][2];
}
