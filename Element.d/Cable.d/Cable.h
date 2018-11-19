#ifndef _CABLE_H_
#define _CABLE_H_

#include "../../Element.d/Element.h"
#include "../../Element.d/elstatus.h"



class Cable: public Element {
 public:
	int nn[2];
    double *hisv;

public:
	Cable(int, int*);

    Element *clone();

    int *nodes(int *p) ;

    int GetEleType(){return 11;}

    int numDofs();

    int numNodes();
	int getDimNumber();
    
    void renum(CoordSet&);
    
    int rerenum(CoordSet&);
    void setMass(CoordSet&,double);
    int getVol(CoordSet&, DynOps&);
    void setinistr(double*);
    void setvol0();
    double getvol0();
    void calcde(DynOps&, Solver&, CoordSet&);
    void constructMat(DynOps&, Solver&);
    void large(DynOps&);
    void updatenodalforce(CoordSet&, DynOps&);
    void updatea(CoordSet&, Curveset&, Solver&,damping&);
    int getouttype();
    double* getoutstress(double* p);
    double* getoutstrain(double*);
    int sethistory(int );
    double* getouthis(double*);
    void hourglassctrl(DynOps&, CoordSet&,int&,double&);
    double EleTimeStep(CoordSet&,double&,double&);
    double* getlocal(CoordSet&);

    //reset
    int ResetData(double* , int );
};
#endif
