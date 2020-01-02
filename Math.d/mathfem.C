

#include "mathfem.h"

namespace dcp {
// measure dependent constant
#define CUBIC_ZERO 1.0e-100

void cubic(double a, double b, double c, double d, double *r1, double *r2,
           double *r3, int *num)
//
//   solves cubic equation for real roots
//
//   input:
//     a,b,c,d - coefficients of equation in form:
//     ax^3 + bx^2 + cx + d = 0
//
//   output:
//     r1,r2,r3 - roots (only first num roots is valid)
//     num      - number of roots resolved
//
{
  double aa, p, q, D, u, v, phi;
  double help;

  double norm = 1e-6 * (fabs(a) + fabs(b) + fabs(c)) + CUBIC_ZERO;

  if (fabs(a) <= norm) {
    if (fabs(b) <= norm) {
      if (fabs(c) <= norm) {
        if (fabs(d) <= norm) {
          *r1 = 0.0;
          *num = 1;
          return;
        } else {
          *num = 0;
          return;
        }
      } else {
        *r1 = -d / c;
        *num = 1;
        return;
      }
    } else {
      if ((D = c * c - 4.0 * b * d) < 0.0) {
        *num = 0;
        return;
      } else {
        //*r1 = (-c + sqrt(D)) / 2.0 / b;
        //*r2 = (-c - sqrt(D)) / 2.0 / b;
        if (fabs(c) < norm) {
          help = -d / b;
          if (help > 0.) {
            *r1 = sqrt(help);
            *r2 = -sqrt(help);
            *num = 2;
            return;
          } else {
            *num = 0;
            return;
          }
        } else {
          help = -(c + sgn(c) * sqrt(D)) / 2.0;
          *r1 = help / b;
          *r2 = d / help;
          *num = 2;
        }
      }
    }
  } else {
    aa = a;
    a = b / (aa * 3.0);
    b = c / aa;
    c = d / aa;
    p = b - a * a * 3.0;
    q = 2.0 * a * a * a - a * b + c;
    D = q * q / 4.0 + p * p * p / 27.0;
    if (fabs(D) < CUBIC_ZERO) {
      if (fabs(p * q) < CUBIC_ZERO) {
        *r1 = 0.0 - a;
        *r2 = *r1;
        *r3 = *r1;
        *num = 3;
      } else {
        *r2 = cbrt(q / 2.0) - a;
        *r1 = -2.0 * *r2 - a;
        *num = 2;
      }
    } else {
      if (D > 0.0) {
        u = -q / 2.0 + sqrt(D);
        v = -q - u;

        *r1 = u + v - a;
        *r1 = cbrt(u) + cbrt(v) - a;
        *num = 1;
      } else {
        p = sqrt(fabs(p) / 3.0);
        help = (-q / (2.0 * p * p * p));
        if (fabs(help) > 1.0) {
          help = sgn(help);  // prevent rounding errors
        }

        phi = acos(help) / 3.0;
        double cp = cos(phi);
        double sp = sqrt(3.0) * sin(phi);
        *r1 = 2 * p * cp - a;
        *r2 = -p * (cp + sp) - a;
        *r3 = -p * (cp - sp) - a;

        // I'm getting some pretty bad accuracy, a single iteration like this
        // would help alot
        //* r1 -= (d + c*(*r1) + b*(*r1)*(*r1) + a*(*r1)*(*r1)*(*r1))/(c +
        //2*b*(*r1) + 3*a*(*r1)*(*r1));
        //* r2 -= (d + c*(*r2) + b*(*r2)*(*r2) + a*(*r2)*(*r2)*(*r2))/(c +
        //2*b*(*r2) + 3*a*(*r2)*(*r2));
        //* r3 -= (d + c*(*r3) + b*(*r3)*(*r3) + a*(*r3)*(*r3)*(*r3))/(c +
        //2*b*(*r3) + 3*a*(*r3)*(*r3));
        *num = 3;
      }
    }
  }
}

void cubic3r(double a, double b, double c, double d, double *r1, double *r2,
             double *r3, int *num)
//
//   solves cubic equation for real roots
//
//   input:
//     a,b,c,d - coefficients of equation in form:
//     ax^3 + bx^2 + cx + d = 0
//
//   output:
//     r1,r2,r3 - roots (only first num roots is valid)
//     num      - number of roots resolved
//
{
  double aa, r, q, p, D, phi;
  double help;

  if (fabs(a) < CUBIC_ZERO) {
    if (fabs(b) < CUBIC_ZERO) {
      if (fabs(c) < CUBIC_ZERO) {
        *num = 0;
        return;
      } else {
        *r1 = -d / c;
        *num = 1;
        return;
      }
    } else {  // fabs(b) < CUBIC_ZERO
      if ((D = c * c - 4.0 * b * d) < 0.0) {
        *num = 0;
        return;
      } else {
        //*r1 = (-c + sqrt(D)) / 2.0 / b;
        //*r2 = (-c - sqrt(D)) / 2.0 / b;
        if (fabs(c) < CUBIC_ZERO) {
          help = -d / b;
          if (help >= 0.) {
            *r1 = sqrt(help);
            *r2 = -sqrt(help);
            *num = 2;
            return;
          } else {
            *num = 0;
            return;
          }
        } else {
          help = -(c + sgn(c) * sqrt(D)) / 2.0;
          *r1 = help / b;
          *r2 = d / help;
          *num = 2;
          return;
        }
      }
    }
  } else {
    aa = a;
    a = b / aa;
    b = c / aa;
    c = d / aa;

    q = (a * a - 3.0 * b) / 9.0;
    r = (2.0 * a * a * a - 9.0 * a * b + 27.0 * c) / 54.0;

    D = q * q * q - r * r;
    //  if (D > 0.) {
    // three real roots
    help = r / sqrt(q * q * q);
    if (fabs(help) > 1.0) {
      help = sgn(help);  // prevent rounding errors
    }

    phi = acos(help);
    p = sqrt(q);

    *r1 = -2.0 * p * cos(phi / 3.0) - a / 3.0;
    *r2 = -2.0 * p * cos((phi + 2.0 * M_PI) / 3.0) - a / 3.0;
    *r3 = -2.0 * p * cos((phi - 2.0 * M_PI) / 3.0) - a / 3.0;
    *num = 3;
    /*  } else {
     *
     * help = fabs(r) + sqrt(-D);
     * A = -sgn(r)*pow(D, 1./3.);
     * if (fabs(A) > CUBIC_ZERO)
     * B = q/A;
     * else
     * B = 0.0;
     *
     **r1 = (A+B) - a/3.0;
     **num = 1;
     * }
     */
    return;
  }
}

int iperm(int val, int rank)
//
// returns iperm of val, in specific rank
//
// rank 3 : val is valid from 1,2,3 and returns for val 1,2,3 2,3,1
// rank 2 : -||-
{
  return (val + 1 > rank ? 1 : val + 1);
}

}  // namespace dcp
