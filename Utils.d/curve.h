#ifndef _CURVE_H_
#define _CURVE_H_

#include "../Utils.d/resize_array.h"
#include "../Utils.d/BlockAlloc.h"

typedef struct CurveCoef{
	double coef1;
	double coef2;
} CurveCoef;


class CurveList{
public:
    int curvenum;
	int curvelength;
    int derflg;
	CurveCoef *curvevalue;
	CurveList(int ,int, CurveCoef*);
    CurveList(int ,int, double*);
    double getvalue(double);
    int    dervalue_a();
    double getdervalue_a(double);
};


    class Curveset{
    protected:
        int cmax;
        CurveList **curves;
        BlockAlloc ba;
  public:
    Curveset(int = 0);
    int size() { return cmax; }
    int last();
    CurveList *operator[] (int i) { return curves[i]; }
    void curveadd(CurveList*);
    void curveadd(int num,  int ncoef, CurveCoef *coef);
    void curveadd(int num,  int ncoef, double *coef);
    void list();
    CurveList& getCurve(int);
    };
#endif
