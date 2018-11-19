#include "egen.h"
#include <math.h>
#include <stdio.h>

 int  jaco_(double *sig, double *eval, double *vv)
 {
     /*
      * Solves the eigenvalues and eigenvectors of real
      * symmetric matrix by jacobi method.
      *  Written by bp. Inspired by ED WILSON jaco_ procedure.
      *
      * Parameters (input):
      * nf - number of significant figures
      *
      * Output params:
      * eval - eigen values (not sorted)
      * v    - eigenvectors (stored columvise)
      */
 
 
     /* Local variables */
     
     double A[3][3], v[3][3];
     
     double ssum, aa, co, si, tt, tol, sum, aij, aji;
     int ite, i, j, k, ih;
     int neq = 3;
     int nf = 3;
 
     double c_b2 = .10;
     //double c_b27 = .01;
 
     for ( i = 0; i < neq; i++ ) {
          A[i][i] = sig[i];
     }
     A[0][1] = A[1][0] = sig[3];
     A[1][2] = A[2][1] = sig[4];
     A[0][2] = A[2][0] = sig[5];
     /* Function Body */
 
 
     for ( i = 0; i < neq; i++ ) {
         eval[i] = A[i][i];
     }
 
     tol = pow(c_b2, nf);
     sum = 0.0;
     for ( i = 0; i < neq; ++i ) {
         for ( j = 0; j < neq; ++j ) {
             sum += fabs( A[i][j] );
             v[i][j] = 0.0;
         }
 
         v[i][i] = 1.0;
     }
 
     if ( sum <= 0.0 ) {
         return 0;
     }
 
 
     /* ---- REDUCE MATRIX TO DIAGONAL ---------------- */
     ite = 0;
     do {
         ssum = 0.0;
         for ( j = 1; j < neq; ++j ) {
             ih = j - 1;
             for ( i = 0; i < ih; ++i ) {
                 if ( ( fabs( A[i][j] ) / sum ) > tol ) {
                     ssum += fabs( A[i][j] );
                     /* ---- CALCULATE ROTATION ANGLE ----------------- */
                     aa = atan2( A[i][j] * 2.0, eval[i] - eval[j] ) /  2.0;
                     si = sin(aa);
                     co = cos(aa);
                     /*
                      *   // ---- MODIFY "I" AND "J" COLUMNS OF "A" AND "V"
                      *   for (k = 1; k <= neq; ++k) {
                      *    tt = this->at(k, i);
                      *    this->at(k, i) = co * tt + si * this->at(k, j);
                      *    this->at(k, j) = -si * tt + co * this->at(k, j);
                      *    tt = v[k][i];
                      *    v[k][i] = co * tt + si * v[k][j];
                      *    // L500:
                      *    v[k][j] = -si * tt + co * v[k][j];
                      *   }
                      *   // ---- MODIFY DIAGONAL TERMS --------------------
                      *   this->at(i, i) = co * this->at(i, i) + si * A[j][i];
                      *   this->at(j, j) = -si * A[i][j] + co * this->at(j, j);
                      *   A[i][j] = 0.0;
                      *   // ---- MAKE "A" MATRIX SYMMETRICAL --------------
                      *   for (k = 1; k <= neq; ++k) {
                      *    A[i][k] = this->at(k, i);
                      *    A[j][k] = this->at(k, j);
                      *    // L600:
                      *   }
                      */
                     // ---- MODIFY "I" AND "J" COLUMNS OF "A" AND "V"
                     for ( k = 0; k < i; ++k ) {
                         tt = A[k][i];
                         A[k][i] = co * tt + si *A[k][j];
                         A[k][j] = -si * tt + co *A[k][j];
                         tt = v[k][i];
                         v[k][i]= co * tt + si *v[k][j];
                         v[k][j] = -si * tt + co *v[k][j];
                     }
 
                     // diagonal term (i,i)
                     tt = eval[i];
                     eval[i] = co * tt + si *A[i][j];
                     aij = -si * tt + co *A[i][j];
                     tt = v[i][i];
                     v[i][i] = co * tt + si *v[i][j];
                     v[i][j] = -si * tt + co *v[i][j];
 
                     for ( k = i + 1; k < j; ++k ) {
                         tt = A[i][k];
                         A[i][k] = co * tt + si *A[k][j];
                         A[k][j] = -si * tt + co *A[k][j];
                         tt = v[k][i];
                         v[k][i] = co * tt + si *v[k][j];
                         v[k][j] = -si * tt + co *v[k][j];
                     }
 
                     // diagonal term (j,j)
                     tt = A[i][j];
                     aji = co * tt + si *eval[j];
                     eval[j] = -si * tt + co *eval[j];
 
                     tt = v[j][i];
                     v[j][i] = co * tt + si *v[j][j];
                     v[j][j] = -si * tt + co *v[j][j];
                     //
                     for ( k = j + 1; k < neq; ++k ) {
                         tt = A[i][k];
                         A[i][k] = co * tt + si *A[j][k];
                         A[j][k] = -si * tt + co *A[j][k];
                         tt = v[k][i];
                         v[k][i] = co * tt + si *v[k][j];
                         v[k][j] = -si * tt + co *v[k][j];
                     }
 
                     // ---- MODIFY DIAGONAL TERMS --------------------
                     eval[i] = co * eval[i] + si * aji;
                     eval[j] = -si * aij + co *eval[j];
                     A[i][j] = 0.0;
                 } else {
                     /* ---- A(I,J) MADE ZERO BY ROTATION ------------- */
                     ;
                 }
             }
         }
 
         /* ---- CHECK FOR CONVERGENCE -------------------- */
         if ( ++ite > 50 ) {
             fprintf(stderr,"FloatMatrix::jaco_: too many iterations");
         }
     } while ( fabs(ssum) / sum > tol );
 
     // restore original matrix
     for ( i = 0; i < neq; i++ ) {
         for ( j = i; j < neq; j++ ) {
             A[i][j] = A[j][i];
         }
     }

     double swap;
     for ( i = 0; i < 2; i++ ) {
         for ( j = 0; j < 2; j++ ) {
             if ( eval[j+1] < eval[j] ) {
                 // swap eigen values and eigen vectors
                 swap = eval[j+1];
                 eval[j+1] = eval[j];
                 eval[j] = swap;
      
                 for ( k = 0; k < neq; k++ ) {
                     swap = v[k][j+1];
                     v[k][j+1] = v[k][j];
                     v[k][j] = swap;
                 }
             }
         }
     }

     for(i = 0; i < 3; ++i){
         for(j = 0; j <3 ;++j){
             vv[i*3+j] = v[i][j];
         }
     }
 
     return 0;
 } /* jaco_ */
