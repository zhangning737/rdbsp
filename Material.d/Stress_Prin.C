#include <mkl_lapacke.h>
#include <stdio.h>
#include <stdlib.h>

void
princ_stress( double* sig, double *dir , double *ps ){
    double temp_stress[3][3], eps, swap, WORK(1000);
    double pss[3],W[3];

    int i,j,L,k;
    #define N 3
    #define LDA N
	MKL_INT n = N, lda = LDA, info;
	double w[N];


    eps = 0.0001;
    info = 0;
    dir[0] = sig[0];
    dir[4] = sig[1];
    dir[8] = sig[2];
          
    dir[1] = sig[3];
    dir[3] = dir[1];
    dir[5] = sig[4];
    dir[7] = dir[5];
    dir[2] = sig[5];
    dir[6] = dir[2];

	info = LAPACKE_dsyev( LAPACK_ROW_MAJOR, 'V', 'U', n, dir, lda, w );
	if( info > 0 ) {
		fprintf(stderr, "The algorithm failed to compute eigenvalues.\n" );
		exit( 1 );
        }

    for(i =0; i<3; ++i){
        ps[i] = w[i];
    }
    /*       
    for(i =0; i < 2; ++i){
        for(j =0; j< 2; ++j){
            if(ps[j+1] < ps[j]){
                swap =ps[j+1];
                ps[j+1] = ps[j];
                ps[j] = swap;
                for(k = 0; k < 3; ++k){
                    swap = dir[k+(j+1)*3];
                    dir[k+(j+1)*3]=dir[k+j*3];
                    dir[k+j*3] =swap;
                }
            }
        }
    }
    */

    swap = dir[1];
    dir[1] = dir[3];
    dir[3] = swap;

    swap = dir[2];
    dir[2] = dir[6];
    dir[6] = swap;

    swap = dir[5];
    dir[5] = dir[7];
    dir[7] = swap;
 
             

}
