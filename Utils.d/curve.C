#include "../Utils.d/curve.h"

CurveList:: CurveList(int num, int ncoef, CurveCoef* coef)
{
    curvenum = num;
	curvelength = ncoef;
    curvevalue = new CurveCoef[curvelength];
     int i;
     for(i=0; i< curvelength; ++i){
         curvevalue[i].coef1 = coef[i].coef1;
         curvevalue[i].coef2 = coef[i].coef2;
     }
     derflg = 0;
}

CurveList:: CurveList(int num, int ncoef, double* coef)
{
    curvenum = num;
	curvelength = ncoef/2;
     curvevalue = new CurveCoef[curvelength];
     int i;
     for(i=0; i< curvelength; ++i){
         curvevalue[i].coef1 = coef[2*i];
         curvevalue[i].coef2 = coef[2*i+1];
     }
     derflg = 0;
}

double
CurveList::getvalue(double t)
{
    int i;
    double f1, f2, t1, t2;
    if(t>0.5){
        int j = 1;
    }
    for(i = 0 ; i< curvelength ; ++i)
    {
        t1 = curvevalue[i].coef1;
        if(t == t1) return curvevalue[i].coef2;
        else if(t > t1) {
            if(i == curvelength){
                fprintf(stderr, "Current time is out curve! time = %f", t);
            return 0.0;
            }
            t2 = curvevalue[i+1].coef1;
            if(t < t2)
            {
                f1 = curvevalue[i].coef2;
                f2 = curvevalue[i+1].coef2;
                double cv = f1 + (f2 -f1)*(t-t1)/(t2-t1);
                return cv;
            }
        }
                    
    }
}

int
CurveList::dervalue_a()
{
    derflg = 1;
    int i;
    double tempv, tempa;
    double f1, f2, t1 , t2;
    for(i = 0; i< curvelength-1; ++i)
    {
        t1 = curvevalue[i].coef1;
        t2 = curvevalue[i+1].coef1;
        f1 = curvevalue[i].coef2;
        f2 = curvevalue[i+1].coef2;
        tempv = (f2 - f1)/(t2 - t1);
        tempa = tempv*1.0/(t2 - t1);
        curvevalue[i].coef2 = tempa;
    }
    return 0;
}

double
CurveList::getdervalue_a(double t)
{
       int i;
    double f1, f2, t1, t2;
    double temp;
    for(i = 0 ; i< curvelength ; ++i)
    {
        t1 = curvevalue[i].coef1;
        if(t == t1) return curvevalue[i].coef2;
        else if(t > t1) {
            if(i == curvelength){
                fprintf(stderr, "Current time is out curve! time = %f", t);
            return;
            }
            t2 = curvevalue[i+1].coef1;
            if(t < t2)
            {
                temp = curvevalue[i].coef2;
                    return temp;
             }
 }
    }
}
CurveList&
Curveset::getCurve(int i)
{
    int n;
    for(n=0;n<cmax; ++n)
    {
         if(curves[n]){
            if(curves[n]->curvenum == i){
                return *curves[n];
            }
        }
    }
    return *curves[i];
}


void
Curveset::curveadd(int num, int length, CurveCoef *n)
{
   CurveList *cl;

   cl = new (ba) CurveList(num,length, n);
    
 curveadd(cl);
}

void
Curveset::curveadd(int num, int length, double *n)
{
   CurveList *cl;

   cl = new (ba) CurveList(num,length, n);
    
 curveadd(cl);
}


// Last returns the true last defined element
int Curveset::last()
{
 int last = size();
 while(--last >= 0)
     if(curves[last] != 0) break;

 return last+1;
}

void Curveset::list()
{
}

typedef CurveList *curP;

Curveset::Curveset(int initsize)
{
  curves = new curP[initsize];
  cmax = initsize;
  int i;
  for(i = 0; i < cmax; ++i)
    curves[i] = 0;
}

void
Curveset::curveadd(CurveList *l)
{

    int newsize = cmax+1;
    curP *np = new curP[newsize];
    int i;
    for(i= 0; i < cmax; ++i)
     np[i] = curves[i];

     cmax = newsize;
     np[cmax-1] = 0;
    delete[] curves;
    curves = np;

  curves[cmax-1] = l;
}


