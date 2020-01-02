
#include <math.h>

#include "../../Element.d/Bricko.d/EightNodeBricko.h"
#include "../../Math.d/mathfem.h"
#include "../../Utils.d/linkfc.h"
#include "jacob.h"

EightNodeBricko::EightNodeBricko(int n, int* nodenums) {
  elemnum = n;
  nn[0] = nodenums[0];
  nn[1] = nodenums[1];
  nn[2] = nodenums[2];
  nn[3] = nodenums[3];
  nn[4] = nodenums[4];
  nn[5] = nodenums[5];
  nn[6] = nodenums[6];
  nn[7] = nodenums[7];
  elsta = new elstatus;
  hisv = new double;
  eldel = 1;
  elfail = 1;
}

Element* EightNodeBricko::clone() { return new EightNodeBricko(*this); }

int EightNodeBricko::numNodes() { return 8; }

int* EightNodeBricko::nodes(int* p) {
  if (p == 0) p = new int[8];
  p[0] = nn[0];
  p[1] = nn[1];
  p[2] = nn[2];
  p[3] = nn[3];
  p[4] = nn[4];
  p[5] = nn[5];
  p[6] = nn[6];
  p[7] = nn[7];
  return p;
}

double EightNodeBricko::getfm() { return elsta->fm; }

double EightNodeBricko::getmass() { return elsta->mass; }

int EightNodeBricko::numDofs() { return 24; }

int EightNodeBricko::getDimNumber() { return 3; }

void EightNodeBricko::renum(CoordSet& cs) {
  nn[0] = cs.getnindex(nn[0]);
  nn[1] = cs.getnindex(nn[1]);
  nn[2] = cs.getnindex(nn[2]);
  nn[3] = cs.getnindex(nn[3]);
  nn[4] = cs.getnindex(nn[4]);
  nn[5] = cs.getnindex(nn[5]);
  nn[6] = cs.getnindex(nn[6]);
  nn[7] = cs.getnindex(nn[7]);
}

int EightNodeBricko::rerenum(CoordSet& cs) {
  int i;
  for (i = 0; i < 8; ++i) {
    nn[i] = cs[nn[i]]->nodenum;
  }
  return 0;
}

int EightNodeBricko::getVol(CoordSet& cs, DynOps& ops) {
  int i, j;
  Node* nd;
  double xyz[8][3], evol;

  for (j = 0; j < 8; ++j) {
    nd = cs[nn[j]];
    xyz[j][0] = nd->x;
    xyz[j][1] = nd->y;
    xyz[j][2] = nd->z;
  }

  jacob((double*)xyz, evol, ops.ijac);

  elsta->vol = evol;

  if (evol <= 0.0) {
    return 1;
  } else {
    return 0;
  }
}

void EightNodeBricko::setvol0() { elsta->vol0 = elsta->vol; }

double EightNodeBricko::getvol0() { return elsta->vol0; }

void EightNodeBricko::setMass(CoordSet& cs, double evol) {
  int i;
  elsta->mass = prop->calcmass(evol);
  // initial the mass
  /*
  for(i = 0; i < 8; ++i)
  {
      cs[nn[i]].mass = 0.0;
  }
  */
  for (i = 0; i < 8; ++i) {
    cs[nn[i]]->mass += elsta->mass / 8.0;
  }
}

void EightNodeBricko::setinistr(double* istress) {
  int i;
  for (i = 0; i < 6; ++i) {
    elsta->stress[i] = istress[i];
  }
}
void EightNodeBricko::calcde(DynOps& ops, Solver& sol, CoordSet& cs) {
  int i, j;
  double v[8][3];
  Node* nd;

  for (i = 0; i < 8; ++i) {
    nd = cs[nn[i]];
    for (j = 0; j < 3; ++j) {
      v[i][j] = nd->v[j];
    }
  }

  double v17[3], v28[3], v35[3], v46[3];
  double pkxj[4][3];
  double ijac[3][3], dij[3][3];
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      ijac[i][j] = ops.ijac[i * 3 + j];
    }
  }

  for (i = 0; i < 3; ++i) {
    pkxj[0][i] = (-ijac[i][0] - ijac[i][1] - ijac[i][2]) / 8.0;
    pkxj[1][i] = (ijac[i][0] - ijac[i][1] - ijac[i][2]) / 8.0;
    pkxj[2][i] = (ijac[i][0] + ijac[i][1] - ijac[i][2]) / 8.0;
    pkxj[3][i] = (-ijac[i][0] + ijac[i][1] - ijac[i][2]) / 8.0;
  }
  for (i = 0; i < 4; ++i) {
    for (j = 0; j < 3; ++j) {
      ops.pkxj[i * 3 + j] = pkxj[i][j];
    }
  }

  for (i = 0; i < 3; ++i) {
    v17[i] = v[0][i] - v[6][i];
    v28[i] = v[1][i] - v[7][i];
    v35[i] = v[2][i] - v[4][i];
    v46[i] = v[3][i] - v[5][i];
  }

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      dij[i][j] = v17[i] * pkxj[0][j] + v28[i] * pkxj[1][j] +
                  v35[i] * pkxj[2][j] + v46[i] * pkxj[3][j];
    }
    ops.de[i] = dij[i][i];
  }
  ops.de[4] = (dij[1][2] + dij[2][1]) / 2.;
  ops.de[5] = (dij[0][2] + dij[2][0]) / 2.;
  ops.de[3] = (dij[0][1] + dij[1][0]) / 2.;

  ops.vort[1] = (dij[1][2] - dij[2][1]) / 2.;
  ops.vort[2] = (dij[0][2] - dij[2][0]) / 2.;
  ops.vort[0] = (dij[0][1] - dij[1][0]) / 2.;

  for (i = 0; i < 3; ++i) {
    ops.de[i] = sol.dt * ops.de[i];
    ops.vort[i] = sol.dt * ops.vort[i];
  }
  for (i = 3; i < 6; ++i) {
    ops.de[i] = sol.dt * ops.de[i];
  }

  for (i = 0; i < 6; ++i) {
    elsta->strain[i] += ops.de[i];
  }
}

void EightNodeBricko::constructMat(DynOps& ops, Solver& sol) {
  int i;
  prop->calcstress((double*)elsta->stress, (double*)ops.de, (double*)hisv,
                   sol.dt, sol.currentTime, plas, elfail);
}

void EightNodeBricko::large(DynOps& ops) {
  double q[3], rot[6];
  int i;
  q[0] = 2.0 * elsta->stress[5] * ops.vort[2];
  q[1] = 2.0 * elsta->stress[4] * ops.vort[1];
  q[2] = 2.0 * elsta->stress[3] * ops.vort[0];

  rot[0] = q[2] + q[0];
  rot[1] = -q[2] + q[1];
  rot[2] = -q[1] - q[2];
  rot[4] = ops.vort[1] * (elsta->stress[2] - elsta->stress[1]) -
           ops.vort[2] * elsta->stress[3] - ops.vort[0] * elsta->stress[5];
  rot[5] = ops.vort[2] * (elsta->stress[2] - elsta->stress[0]) -
           ops.vort[1] * elsta->stress[3] + ops.vort[0] * elsta->stress[4];
  rot[3] = ops.vort[0] * (elsta->stress[1] - elsta->stress[0]) +
           ops.vort[1] * elsta->stress[4] + ops.vort[2] * elsta->stress[5];

  for (i = 0; i < 6; ++i) {
    elsta->stress[i] = elsta->stress[i] + rot[i];
  }
}

void EightNodeBricko::updatenodalforce(CoordSet& cs, DynOps& ops) {
  int i, j, k;
  double pkxj[4][3], pkxjv[4][3];
  /*
  double nf[8][3];
  _FORTRAN(nodalforce)((double*)nf, (double*) ops.pkxj,(double*) elsta->stress,
  elsta->vol);*/
  double nf[3][8];

  for (i = 0; i < 4; ++i) {
    for (j = 0; j < 3; ++j) {
      pkxj[i][j] = ops.pkxj[j + i * 3];
    }
  }
  for (i = 0; i < 4; ++i) {
    for (k = 0; k < 3; ++k) {
      pkxjv[i][k] = elsta->vol * pkxj[i][k];
    }
  }

  for (i = 0; i < 4; ++i) {
    nf[0][i] =
        (elsta->stress[0] * pkxjv[i][0] + elsta->stress[3] * pkxjv[i][1] +
         elsta->stress[5] * pkxjv[i][2]);
    nf[1][i] =
        (elsta->stress[1] * pkxjv[i][1] + elsta->stress[3] * pkxjv[i][0] +
         elsta->stress[4] * pkxjv[i][2]);
    nf[2][i] =
        (elsta->stress[2] * pkxjv[i][2] + elsta->stress[4] * pkxjv[i][1] +
         elsta->stress[5] * pkxjv[i][0]);
  }

  for (i = 0; i < 3; ++i) {
    nf[i][4] = -nf[i][2];
    nf[i][5] = -nf[i][3];
    nf[i][6] = -nf[i][0];
    nf[i][7] = -nf[i][1];
  }

  elsta->fm = 0.0;

  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 8; ++j) elsta->fm += fabs(nf[i][j]);
  }

  for (i = 0; i < 8; ++i) {
    for (j = 0; j < 3; ++j) {
      // Node *nd= cs[nn[i]];
      cs[nn[i]]->interf[j] += nf[j][i];
      if (fabs(cs[nn[i]]->interf[j]) > 1.0e20) {
        fprintf(stderr, "InterStress ERROR\n");
      }
    }
  }
}

void EightNodeBricko::updatea(CoordSet& cs, Curveset& mm, Solver& sol,
                              damping& dp, StaticSolver& sts) {
  int i;
  for (i = 0; i < 8; ++i) {
    cs[nn[i]]->updatea(mm, sol, dp, sts);
  }
}

int EightNodeBricko::getouttype() { return 12; }

double* EightNodeBricko::getoutstress(double* p) {
  if (p == 0) p = new double[6];
  p[0] = elsta->stress[0];
  p[1] = elsta->stress[1];
  p[2] = elsta->stress[2];
  p[3] = elsta->stress[3];
  p[4] = elsta->stress[4];
  p[5] = elsta->stress[5];
  return p;
}

double* EightNodeBricko::getoutstrain(double* p) {
  if (p == 0) p = new double[6];
  p[0] = elsta->strain[0];
  p[1] = elsta->strain[1];
  p[2] = elsta->strain[2];
  p[3] = elsta->strain[3];
  p[4] = elsta->strain[4];
  p[5] = elsta->strain[5];
  return p;
}

int EightNodeBricko::sethistory(int n) {
  int i;
  delete[] hisv;
  hisv = new double[n];
  for (i = 0; i < n; ++i) {
    hisv[i] = 0.0;
  }
}

double* EightNodeBricko::getouthis(double* p) {
  int i;
  if (p == 0) p = new double[21];

  for (i = 0; i < 21; ++i) {
    p[i] = hisv[i];
  }
  return p;
}

void EightNodeBricko::hourglassctrl(DynOps& ops, CoordSet& cs, int& flg,
                                    double& para) {
  int i, j, k;

  double v[8][3];
  Node* nd;

  double xyz[8][3], force[8][3], evol;
  double density, ws;
  for (i = 0; i < 8; ++i) {
    nd = cs[nn[i]];
    xyz[i][0] = nd->x;
    xyz[i][1] = nd->y;
    xyz[i][2] = nd->z;
    for (j = 0; j < 3; ++j) {
      v[i][j] = nd->v[j];
      force[i][j] = nd->interf[j];
    }
  }

  evol = elsta->vol;
  density = prop->getdensity();
  ws = prop->getwavespeed();

  //    _FORTRAN(hourglassforce)((double*) v, (double *) xyz, ops.pkxj, evol,
  //    density, ws,flg, para, (double*) force);
  switch (flg) {
    case 0:
      break;
    case 1:
      if (para < 1.0e-6) {
        break;
      } else {
        double v3478[3], v2358[3], v1467[3], v1256[3], hgr[3][4], fh[8][3];
        double hap[3], ham[3], hbp[3], hbm[3];
        double a = para * density / 4.0;
        double v32 = pow(evol, (2. / 3.));
        double ah = a * v32 * ws;
        double al = a * v32 * (100. * para);
        for (i = 0; i < 3; ++i) {
          v3478[i] = v[2][i] - v[3][i] - v[6][i] + v[7][i];
          v2358[i] = v[1][i] - v[2][i] - v[4][i] + v[7][i];
          v1467[i] = v[0][i] - v[3][i] - v[5][i] + v[6][i];
          v1256[i] = v[0][i] - v[1][i] - v[4][i] + v[5][i];
        }
        for (i = 0; i < 3; ++i) {
          hgr[i][0] = v1467[i] - v2358[i];
          hgr[i][1] = v1467[i] + v2358[i];
          hgr[i][2] = v1256[i] - v3478[i];
          hgr[i][3] = v1256[i] + v3478[i];
        }

        for (i = 0; i < 3; ++i) {
          for (k = 0; k < 4; ++k) {
            hgr[i][k] = hgr[i][k] * (ah + fabs(al * hgr[i][k]));
          }
        }

        for (i = 0; i < 3; ++i) {
          hap[i] = hgr[i][0] + hgr[i][3];
          ham[i] = hgr[i][0] - hgr[i][3];
          hbp[i] = hgr[i][1] + hgr[i][2];
          hbm[i] = hgr[i][1] - hgr[i][2];
        }

        for (i = 0; i < 3; ++i) {
          fh[0][i] = -hap[i] - hbp[i];
          fh[1][i] = hap[i] - hbm[i];
          fh[2][i] = -hap[i] + hbp[i];
          fh[3][i] = hap[i] + hbm[i];
          fh[4][i] = -ham[i] + hbp[i];
          fh[5][i] = ham[i] + hbm[i];
          fh[6][i] = -ham[i] - hbp[i];
          fh[7][i] = ham[i] - hbm[i];
        }
        for (i = 0; i < 8; ++i) {
          for (j = 0; j < 3; ++j) {
            force[i][j] = force[i][j] - fh[i][j];
          }
        }
      }
      break;
    case 2:
      if (para < 1.0e-6) {
        break;
      } else {
        double h[4][4] = {
            {1, 1, 1, 1}, {-1, 1, -1, -1}, {1, -1, -1, 1}, {-1, -1, 1, -1}};
        double ss[4][4] = {{2., -2., -2., 0.},
                           {-2., -2., 2., 0.},
                           {2., 2., 2., 0.},
                           {-2., 2., -2., 0.0}};
        double x3478[3], x2358[3], x1467[3], x1256[3];
        double hgr[3][4], beta[3][4], gama[4][8], g[3][4], pkxj[4][3];
        double ah, qh, fh[8][3], fhx[3][8];
        int p;
        ah = -para * ws * density * pow(evol, (2. / 3.)) / 4.;
        for (i = 0; i < 3; ++i) {
          x3478[i] = xyz[2][i] - xyz[3][i] - xyz[6][i] + xyz[7][i];
          x2358[i] = xyz[1][i] - xyz[2][i] - xyz[4][i] + xyz[7][i];
          x1467[i] = xyz[0][i] - xyz[3][i] - xyz[5][i] + xyz[6][i];
          x1256[i] = xyz[0][i] - xyz[1][i] - xyz[4][i] + xyz[5][i];
        }

        for (i = 0; i < 3; ++i) {
          beta[i][0] = x1467[i] - x2358[i];
          beta[i][1] = x1467[i] + x2358[i];
          beta[i][2] = x1256[i] - x3478[i];
          beta[i][3] = x1256[i] + x3478[i];
        }
        for (i = 0; i < 4; ++i) {
          for (j = 0; j < 3; ++j) {
            pkxj[i][j] = ops.pkxj[j + i * 3];
          }
        }
        for (j = 0; j < 4; ++j) {
          for (k = 0; k < 4; ++k) {
            gama[j][k] = h[k][j];
            for (i = 0; i < 3; ++i) {
              gama[j][k] = gama[j][k] - beta[i][j] * pkxj[k][i];
            }
          }
        }
        for (j = 0; j < 4; ++j) {
          gama[j][4] = ss[0][j] - gama[j][2];
          gama[j][5] = ss[1][j] - gama[j][3];
          gama[j][6] = ss[2][j] - gama[j][0];
          gama[j][7] = ss[3][j] - gama[j][1];
        }
        for (i = 0; i < 3; ++i) {
          for (j = 0; j < 4; ++j) {
            g[i][j] = 0.0;
            for (k = 0; k < 8; ++k) {
              g[i][j] = g[i][j] + v[k][i] * gama[j][k];
            }
          }
        }
        for (i = 0; i < 3; ++i) {
          for (k = 0; k < 8; ++k) {
            fhx[i][k] = 0.0;
            for (j = 0; j < 4; ++j) {
              fhx[i][k] = fhx[i][k] + g[i][j] * gama[j][k];
            }
            fhx[i][k] = ah * fhx[i][k];
          }
        }
        for (i = 0; i < 3; ++i) {
          for (j = 0; j < 8; ++j) {
            fh[j][i] = fhx[i][j];
          }
        }
        for (i = 0; i < 8; ++i) {
          for (j = 0; j < 3; ++j) {
            force[i][j] = force[i][j] - fh[i][j];
          }
        }
      }
      break;
  }

  for (i = 0; i < 8; ++i) {
    nd = cs[nn[i]];
    for (j = 0; j < 3; ++j) {
      nd->interf[j] = force[i][j];
    }
  }
}

double EightNodeBricko::EleTimeStep(CoordSet& cs) {
  int i, j;
  Node* nd;
  double xyz[8][3], evol;
  double density, ws;
  for (i = 0; i < 8; ++i) {
    nd = cs[nn[i]];
    xyz[i][0] = nd->x;
    xyz[i][1] = nd->y;
    xyz[i][2] = nd->z;
  }

  evol = elsta->vol;
  ws = prop->getwavespeed();
  double times, eld;
  int k1, k2, k3, k4;
  double x13[3], x24[3], fs[3], ft[4];
  double e, f, g, atest, at, dt;
  //    _FORTRAN(elementtimestep)((double*)xyz, evol,ws, dtk, eld, factor);
  int fac[6][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 6, 5},
                   {2, 3, 7, 6}, {3, 4, 8, 7}, {4, 1, 5, 8}};
  double areal = 1.e20;
  double aream = 0.0;

  for (j = 0; j < 6; ++j) {
    for (i = 0; i < 3; ++i) {
      k1 = fac[j][0] - 1;
      k2 = fac[j][1] - 1;
      k3 = fac[j][2] - 1;
      k4 = fac[j][3] - 1;

      x13[i] = xyz[k3][i] - xyz[k1][i];
      x24[i] = xyz[k4][i] - xyz[k2][i];

      fs[i] = x13[i] - x24[i];
      ft[i] = x13[i] + x24[i];
    }

    e = fs[0] * fs[0] + fs[1] * fs[1] + fs[2] * fs[2];
    f = fs[0] * ft[0] + fs[1] * ft[1] + fs[2] * ft[2];
    g = ft[0] * ft[0] + ft[1] * ft[1] + ft[2] * ft[2];

    atest = e * g - f * f;

    aream = dcp::max(atest, aream);
    areal = dcp::min(atest, areal);
  }

  at = areal / aream;
  dt = 4. * evol / sqrt(aream);
  dt = dt / ws;

  eld = at;
  return dt;
}

int EightNodeBricko::ResetData(double* d, int nhis) {
  int i;
  sethistory(nhis);
  for (i = 0; i < 6; ++i) {
    elsta->strain[i] = d[i];
    elsta->stress[i] = d[i + 6];
  }
  for (i = 0; i < nhis; ++i) {
    hisv[i] = d[i + 12];
  }
}

double* EightNodeBricko::getlocal(CoordSet& cs) {
  Node* nd1 = cs[nn[0]];
  Node* nd2 = cs[nn[1]];
  Node* nd3 = cs[nn[2]];
  Node* nd4 = cs[nn[3]];
  Node* nd5 = cs[nn[4]];
  Node* nd6 = cs[nn[5]];
  Node* nd7 = cs[nn[6]];
  Node* nd8 = cs[nn[7]];
  double xyz[8][3];

  xyz[0][0] = nd1->x;
  xyz[0][1] = nd1->y;
  xyz[0][2] = nd1->z;
  xyz[1][0] = nd2->x;
  xyz[1][1] = nd2->y;
  xyz[1][2] = nd2->z;
  xyz[2][0] = nd3->x;
  xyz[2][1] = nd3->y;
  xyz[2][2] = nd3->z;
  xyz[3][0] = nd4->x;
  xyz[3][1] = nd4->y;
  xyz[3][2] = nd4->z;
  xyz[4][0] = nd5->x;
  xyz[4][1] = nd5->y;
  xyz[4][2] = nd5->z;
  xyz[5][0] = nd6->x;
  xyz[5][1] = nd6->y;
  xyz[5][2] = nd6->z;
  xyz[6][0] = nd7->x;
  xyz[6][1] = nd7->y;
  xyz[6][2] = nd7->z;
  xyz[7][0] = nd8->x;
  xyz[7][1] = nd8->y;
  xyz[7][2] = nd8->z;
  int i, j;

  double* c = new double[3];
  for (i = 0; i < 3; ++i) {
    c[i] = 0;
  }

  for (i = 0; i < 2; ++i) {
    for (j = 0; j < 8; ++j) {
      c[i] += xyz[j][i];
    }
  }
  for (i = 0; i < 3; ++i) {
    c[i] = c[i] / 8.;
  }
  return c;
}
