#include "../Utils.d/Sign.h"

int sign(double x){
    /*
    if(x > 0)  return -1;
    if(x < 0 ) return  1;
    if(x ==0)  return  0;*/
    return ( x > 0. ? -1 : 1 );
    /*
    if(x > -1.e-20 && x < 1.e-20){
        return 0  ;
    }
    else if(x > 1.0e-20){
        return -1;
    }
    else if(x < -1.e-20){
        return 1;
    }
    */
}

double dmax(double a, double b){
    if(a > b)  return a;
    if(b > a)  return b;
    if(a == b) return a;
}
