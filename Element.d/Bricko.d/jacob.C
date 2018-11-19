#include"inverse.h"
#include "stdio.h"

void
jacob(double* xyzo, double& vol, double* ijac){
    int i,j;
    double det_;
    double jac[3][3];
    double xyz[3][8];

    double x17[3], x28[3], x35[3], x46[3];

    double b[3], x[3],dett[2];

    for(j = 0 ; j < 8 ; ++j){
        for(i = 0;i<3;++i){
            xyz[i][j] = xyzo[i+j*3];
        }
    }

    for(i = 0; i < 3; ++i){
        x17[i] = xyz[i][6] - xyz[i][0];
		x28[i] = xyz[i][7] - xyz[i][1];
		x35[i] = xyz[i][4] - xyz[i][2];
		x46[i] = xyz[i][5] - xyz[i][3];
    }

    for(i = 0; i < 3; ++i){
        jac[0][i] = (x17[i] - x28[i] - x35[i] + x46[i])/8.0;
		jac[1][i] = (x17[i] + x28[i] - x35[i] - x46[i])/8.0;
		jac[2][i] = (x17[i] + x28[i] + x35[i] + x46[i])/8.0;
    }

    Inverse3((double*)jac,ijac, det_);

    vol = 8.0*det_;
    if (vol <=0.0){
        fprintf(stderr,"Volume \< 0\n");
    }
    return;
    
    
}
