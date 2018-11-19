#include "../Element.d/Element.h"
#include <math.h>

void
calcpresstoforce(CoordSet& cs, double value, int* nl){
    int i,j;
  Node* nd1 = cs[nl[0]];
  Node* nd2 = cs[nl[1]];
  Node* nd3 = cs[nl[2]];
  Node* nd4 = cs[nl[3]];
    double xyz[4][3];

  	xyz[0][0] = nd1->x;xyz[0][1] = nd1->y; xyz[0][2] = nd1->z;
  	xyz[1][0] = nd2->x;xyz[1][1] = nd2->y; xyz[1][2] = nd2->z;
  	xyz[2][0] = nd3->x;xyz[2][1] = nd3->y; xyz[2][2] = nd3->z;
  	xyz[3][0] = nd4->x;xyz[3][1] = nd4->y; xyz[3][2] = nd4->z;

    double E=0, F=0, G=0;
    double rxi[3], reta[3];
    double xi[4] = {-0.25,  0.25, 0.25, -0.25};
    double eta[4]= {-0.25, -0.25, 0.25,  0.25};

    for(i = 0; i < 3; ++i){
        for(j = 0; j < 4; ++j){
            rxi[i] = 0;
            reta[i] = 0;
        }
    }

    for(i = 0; i < 3; ++i){
        for(j = 0; j < 4; ++j){
            rxi[i] += xi[j]*xyz[j][i];
            reta[i] +=eta[j]*xyz[j][i];
        }
    }

    for(i = 0; i < 3; ++i){
        E += rxi[i]*rxi[i];
        G += reta[i]*reta[i];
        F += rxi[i]*reta[i];
    }

    double det;
    det = sqrt(E*G-F*F);

    double n[3];
    crossprod(rxi, reta, n);

    for(i = 0 ; i < 3; ++i){
        n[i] /= det;
    }
    double area = 4.0*det;
    double magnitude = area*value/4.0;

    double exf[3];
    for(i =0; i <3; ++i){
        exf[i] = magnitude * n[i];
    }

    for(i =0; i <3; ++i){
        nd1->extf[i] += exf[i];
        nd2->extf[i] += exf[i];
        nd3->extf[i] += exf[i];
        nd4->extf[i] += exf[i];
    }
}


 void
 BPress::renum(CoordSet& cs){
        int i;
        for(i = 0; i < 4; ++i){
            nodelist[i] = cs.getnindex(nodelist[i]);
        }
    }
