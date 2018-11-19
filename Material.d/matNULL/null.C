
#include "../../Material.d/matNULL/null.h"
#include "../../Utils.d/linkfc.h"
#include <math.h>


Material_NULL::Material_NULL(int num, int nprops,double *props)
{
    
}


double*
Material_NULL::getprops(double *p ){
    
}

double
Material_NULL::calcmass(double evol)
{
        return 0.0;
}

double
Material_NULL::getdensity()
{
    
    return 0.0;
}

int
Material_NULL::init(){
  return(0);

}

int
Material_NULL::calcstress(double *sig, double *eps, double *his, double dt, double tt,int& ps,int& fail)
{
    //double mm[2];
    // mm[0]= cm[1];
    //mm[1] =cm[2];
    //_FORTRAN(mat1)((double*)mm,(double*)eps,(double*)sig,(double*)his, dt,tt, ps);

    
    
    return 0;
}

double
Material_NULL::getwavespeed()
{
    return 0.0;
    
}
