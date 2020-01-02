#include <math.h>

#include "../Element.d/Element.h"
#include "../Utils.d/Sign.h"

int Node::setfix(int *m) {
  if (fixed == 0) {
    if (m[0] == 0 && m[1] == 0 && m[2] == 0)
      fixed = 0;
    else if (m[0] == 1 && m[1] == 0 && m[2] == 0)
      fixed = 1;
    else if (m[0] == 0 && m[1] == 1 && m[2] == 0)
      fixed = 2;
    else if (m[0] == 0 && m[1] == 0 && m[2] == 1)
      fixed = 3;
    else if (m[0] == 1 && m[1] == 1 && m[2] == 0)
      fixed = 4;
    else if (m[0] == 0 && m[1] == 1 && m[2] == 1)
      fixed = 5;
    else if (m[0] == 1 && m[1] == 0 && m[2] == 1)
      fixed = 6;
    else if (m[0] == 1 && m[1] == 1 && m[2] == 1)
      fixed = 7;
    else
      fprintf(stderr, "ERROR: Boundary condition format error\n");
  } else if (fixed == 1) {
    if (m[0] == 0 && m[1] == 1 && m[2] == 0)
      fixed = 4;
    else if (m[0] == 0 && m[1] == 0 && m[2] == 1)
      fixed = 6;
  } else if (fixed == 2) {
    if (m[0] == 1 && m[1] == 0 && m[2] == 0)
      fixed = 4;
    else if (m[0] == 0 && m[1] == 0 && m[2] == 1)
      fixed = 5;

  } else if (fixed == 3) {
    if (m[0] == 1 && m[1] == 0 && m[2] == 0)
      fixed = 6;
    else if (m[0] == 0 && m[1] == 1 && m[2] == 0)
      fixed = 5;
  } else if (fixed == 4) {
    if (m[0] == 0 && m[1] == 0 && m[2] == 1) fixed = 7;
  } else if (fixed == 5) {
    if (m[0] == 1 && m[1] == 0 && m[2] == 0) fixed = 7;
  } else if (fixed == 6) {
    if (m[0] == 0 && m[1] == 1 && m[2] == 0) fixed = 7;
  } else {
    fprintf(stderr, "ERROR: Boundary condition format error\n");
  }
  return 0;
}

int Node::setdisp(int dir, int cnum, double disp) {
  if (dir == 1) {
    cun[0] = cnum;
    disdef[0] = disp;
    defined[0] = 1;
  } else if (dir == 2) {
    cun[1] = cnum;
    disdef[1] = disp;
    defined[1] = 1;
  } else if (dir == 3) {
    cun[2] = cnum;
    disdef[2] = disp;
    defined[2] = 1;
  }

  return 0;
}

int Node::setvel(Solver &sol) {
  int i;
  for (i = 0; i < 3; ++i) {
    if (defined[i] != 0 && a[i] == 0.0) {
      v[i] = 0.0;
    } else {
      v[i] += a[i] * sol.dt;
    }
  }
}

int Node::setacc(Curveset &mm) {
  int i;
  for (i = 0; i < 3; ++i) {
    if (defined[i] != 0) {
      a[i] = mm.getCurve(cun[i]).getdervalue_a(0.0) * disdef[i];
    }
  }

  return 0;
}

void Node::updatea(Curveset &mm, Solver &sol, damping &dp, StaticSolver &sts) {
  int i;
  int deb;
  double t[3];
  if (dp.dampingtype == 0) {
    if (fixed == 0) {
      a[0] = (extf[0] + grav[0] - interf[0]) / mass;
      a[1] = (extf[1] + grav[1] - interf[1]) / mass;
      a[2] = (extf[2] + grav[2] - interf[2]) / mass;
    } else if (fixed == 1) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      a[1] = (extf[1] + grav[1] - interf[1]) / mass;
      a[2] = (extf[2] + grav[2] - interf[2]) / mass;
    } else if (fixed == 2) {
      a[0] = (extf[0] + grav[0] - interf[0]) / mass;
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      a[2] = (extf[2] + grav[2] - interf[2]) / mass;
    } else if (fixed == 3) {
      a[0] = (extf[0] + grav[0] - interf[0]) / mass;
      a[1] = (extf[1] + grav[1] - interf[1]) / mass;
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 4) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      a[2] = (extf[2] + grav[2] - interf[2]) / mass;
    } else if (fixed == 5) {
      a[0] = (extf[0] + grav[0] - interf[0]) / mass;
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 6) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      a[1] = (extf[1] + grav[1] - interf[1]) / mass;
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 7) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      extf[1] = interf[1] - grav[1];
      extf[2] = interf[2] - grav[2];
      a[1] = 0.0;
      a[2] = 0.0;
    }
  }
  if (dp.dampingtype == 1) {
    double alpha = dp.local;
    int signv[3];
    for (i = 0; i < 3; ++i) {
      signv[i] = sign(v[i]);
    }
    if (fixed == 0) {
      for (i = 0; i < 3; ++i) {
        t[i] = extf[i] + grav[i] - interf[i];
        if (sol.istep == 0) {
          signv[i] = sign(t[i]);
        } else {
          if (fabs(t[i] / sts.Fm) < 0.00001) signv[i] = 0.0;
        }
        a[i] = (t[i] + signv[i] * alpha * fabs(t[i])) / mass;
      }
    } else if (fixed == 1) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      t[1] = extf[1] + grav[1] - interf[1];
      t[2] = extf[2] + grav[2] - interf[2];
      if (sol.istep == 0) {
        signv[1] = sign(t[1]);
        signv[2] = sign(t[2]);
      } else {
        if (fabs(t[1] / sts.Fm) < 0.00001) signv[1] = 0.0;
        if (fabs(t[2] / sts.Fm) < 0.00001) signv[2] = 0.0;
      }

      a[1] = (t[1] + signv[1] * alpha * fabs(t[1])) / mass;
      a[2] = (t[2] + signv[2] * alpha * fabs(t[2])) / mass;
    } else if (fixed == 2) {
      t[0] = extf[0] + grav[0] - interf[0];
      t[2] = extf[2] + grav[2] - interf[2];
      if (sol.istep == 0) {
        signv[0] = sign(t[0]);
        signv[2] = sign(t[2]);
      } else {
        if (fabs(t[0] / sts.Fm) < 0.00001) signv[0] = 0.0;
        if (fabs(t[2] / sts.Fm) < 0.00001) signv[2] = 0.0;
      }
      a[0] = (t[0] + signv[0] * alpha * fabs(t[0])) / mass;
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];

      a[2] = (t[2] + signv[2] * alpha * fabs(t[2])) / mass;
    } else if (fixed == 3) {
      t[0] = extf[0] + grav[0] - interf[0];
      t[1] = extf[1] + grav[1] - interf[1];
      if (sol.istep == 0) {
        signv[0] = sign(t[0]);
        signv[1] = sign(t[1]);
      } else {
        if (fabs(t[0] / sts.Fm) < 0.00001) signv[0] = 0.0;
        if (fabs(t[1] / sts.Fm) < 0.00001) signv[1] = 0.0;
      }
      a[0] = (t[0] + signv[0] * alpha * fabs(t[0])) / mass;
      a[1] = (t[1] + signv[1] * alpha * fabs(t[1])) / mass;
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 4) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      t[2] = extf[2] + grav[2] - interf[2];
      if (sol.istep == 0) {
        signv[2] = sign(t[2]);
      } else {
        if (fabs(t[2] / sts.Fm) < 0.00001) signv[2] = 0.0;
      }
      a[2] = (t[2] + signv[2] * alpha * fabs(t[2])) / mass;
    } else if (fixed == 5) {
      t[0] = extf[0] + grav[0] - interf[0];

      if (sol.istep == 0) {
        signv[0] = sign(t[0]);
      } else {
        if (fabs(t[0] / sts.Fm) < 0.00001) signv[0] = 0.0;
      }
      a[0] = (t[0] + signv[0] * alpha * fabs(t[0])) / mass;
      a[1] = 0.0;
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 6) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      t[1] = extf[1] + grav[1] - interf[1];
      if (sol.istep == 0) {
        signv[1] = sign(t[1]);
      } else {
        if (fabs(t[1] / sts.Fm) < 0.00001) signv[1] = 0.0;
      }
      a[1] = (t[1] + signv[1] * alpha * fabs(t[1])) / mass;
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 7) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      extf[1] = interf[1] - grav[1];
      extf[2] = interf[2] - grav[2];
      a[1] = 0.0;
      a[2] = 0.0;
    }
  }

  if (dp.dampingtype == 2) {
    double alpha = dp.combined;
    int signv[3];
    for (i = 0; i < 3; ++i) {
      signv[i] = sign(extf[i]) - sign(v[i]);
    }
    if (fixed == 0) {
      for (i = 0; i < 3; ++i) {
        a[i] = (extf[i] + grav[i] - interf[i]) * (1 + signv[i] * alpha) / mass;
      }
    } else if (fixed == 1) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      a[1] = (extf[1] + grav[1] - interf[1]) * (1 + signv[1] * alpha) / mass;
      a[2] = (extf[2] + grav[2] - interf[2]) * (1 + signv[2] * alpha) / mass;
    } else if (fixed == 2) {
      a[0] = (extf[0] + grav[0] - interf[0]) * (1 + signv[0] * alpha) / mass;
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      a[2] = (extf[2] + grav[2] - interf[2]) * (1 + signv[2] * alpha) / mass;
    } else if (fixed == 3) {
      a[0] = (extf[0] + grav[0] - interf[0]) * (1 + signv[0] * alpha) / mass;
      a[1] = (extf[1] + grav[1] - interf[1]) * (1 + signv[1] * alpha) / mass;
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 4) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      a[2] = (extf[2] + grav[2] - interf[2]) * (1 + signv[2] * alpha) / mass;
    } else if (fixed == 5) {
      a[0] = (extf[0] + grav[0] - interf[0]) * (1 + signv[0] * alpha) / mass;
      a[1] = 0.0;
      a[1] = 0.0;
      extf[1] = interf[1] - grav[1];
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 6) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      a[1] = (extf[1] + grav[1] - interf[1]) * (1 + signv[1] * alpha) / mass;
      a[2] = 0.0;
      extf[2] = interf[2] - grav[2];
    } else if (fixed == 7) {
      a[0] = 0.0;
      extf[0] = interf[0] - grav[0];
      extf[1] = interf[1] - grav[1];
      extf[2] = interf[2] - grav[2];
      a[1] = 0.0;
      a[2] = 0.0;
    }
  }
  for (i = 0; i < 3; ++i) {
    if (defined[i] != 0) {
      /*
      if(sol.currentTime > 1.0)
         {
             deb = 1.0;
          }
*/
      a[i] = mm.getCurve(cun[i]).getdervalue_a(sol.currentTime) * disdef[i];
    }
  }
  for (i = 0; i < 3; ++i) {
    if (fabs(a[i]) > 1.e10) {
      fprintf(stderr, "direct = %d, a= %e,interf = %e, extf = %e\n", i, a[i],
              interf[i], extf[i]);
    }
  }
}

void Node::updateu(Solver &sol) {
  double du[3];
  int i;
  for (i = 0; i < 3; ++i) {
    du[i] = v[i] * sol.dt;
    u[i] += du[i];
    if (fabs(du[i]) > 1.0) {
      fprintf(
          stderr,
          "WARNING, %d displacement to large!direction = %d,v = %e, a = %e\n",
          nodenum, i, v[i], a[i]);
    }
  }
  x += du[0];
  y += du[1];
  z += du[2];
}

void Node::updategeo() {}

void Node::cleaninterf() {
  int i;
  for (i = 0; i < 3; ++i) {
    interf[i] = 0.0;
  }
}

void Node::cleanextf() {
  int i;
  for (i = 0; i < 3; ++i) {
    extf[i] = 0.0;
  }
}

void Node::cleanEng() { EngKinetic = 0.0; }

int Node::cleandv() {
  int i;
  for (i = 0; i < 3; ++i) {
    u[i] = 0.0;
    v[i] = 0.0;
    a[i] = 0.0;
  }
}
void Node::updateE() {
  EngKinetic = 0.0;
  int i;
  for (i = 0; i < 3; ++i) {
    EngKinetic += 0.5 * mass * v[i] * v[i];
  }
}

void Node::updateubf() {
  int i;
  if (mass != 0.0) {
    double temp[3], u[3];

    for (i = 0; i < 3; ++i) {
      temp[i] = ubf[i];
    }
    for (i = 0; i < 3; ++i) {
      ubf[i] = extf[i] + grav[i] - interf[i];
    }
    ubfr =
        fabs(sqrt(ubf[0] * ubf[0] + ubf[1] * ubf[1] + ubf[2] * ubf[2]) -
             sqrt(temp[0] * temp[0] + temp[1] * temp[1] + temp[2] * temp[2]));
  }

  else {
    for (i = 0; i < 3; ++i) {
      ubf[i] = 0.0;
    }
  }
}

void Node::calcBF(double *gr) {
  int i;
  for (i = 0; i < 3; ++i) {
    grav[i] = gr[i] * mass;
  }
}
