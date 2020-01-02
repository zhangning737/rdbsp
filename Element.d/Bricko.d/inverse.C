void Inverse3(double* jaco, double* ijac, double& det_) {
  double idet;
  double jac[3][3];
  double ipiv[3], work[3];
  int inf, i, j;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      jac[i][j] = jaco[i * 3 + j];
    }
  }
  det_ =
      jac[0][0] * jac[1][1] * jac[2][2] + jac[1][0] * jac[2][1] * jac[0][2] +
      jac[2][0] * jac[0][1] * jac[1][2] -
      (jac[2][0] * jac[1][1] * jac[0][2] + jac[1][0] * jac[0][1] * jac[2][2] +
       jac[0][0] * jac[2][1] * jac[1][2]);

  ijac[0] = jac[1][1] * jac[2][2] - jac[1][2] * jac[2][1];
  ijac[3] = jac[1][2] * jac[2][0] - jac[1][0] * jac[2][2];
  ijac[6] = jac[1][0] * jac[2][1] - jac[2][0] * jac[1][1];

  ijac[1] = jac[0][2] * jac[2][1] - jac[0][1] * jac[2][2];
  ijac[4] = jac[0][0] * jac[2][2] - jac[0][2] * jac[2][0];
  ijac[7] = jac[0][1] * jac[2][0] - jac[0][0] * jac[2][1];

  ijac[2] = jac[0][1] * jac[1][2] - jac[1][1] * jac[0][2];
  ijac[5] = jac[0][2] * jac[1][0] - jac[0][0] * jac[1][2];
  ijac[8] = jac[0][0] * jac[1][1] - jac[0][1] * jac[1][0];

  idet = 1.0 / det_;

  for (i = 0; i < 9; ++i) {
    ijac[i] = ijac[i] * idet;
  }

  return;
}
