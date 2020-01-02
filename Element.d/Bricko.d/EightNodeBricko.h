#ifndef _EIGHTNODEBRICKO_H_
#define _EIGHTNODEBRICKO_H_

#include "../../Element.d/Element.h"
#include "../../Element.d/elstatus.h"

class EightNodeBricko : public Element {
 public:
  int nn[8];
  elstatus* elsta;
  double* hisv;

 public:
  EightNodeBricko(int, int*);

  Element* clone();

  int* nodes(int* p);

  int GetEleType() { return 1; }

  int numDofs();

  int numNodes();
  int getDimNumber();
  void renum(CoordSet&);
  int rerenum(CoordSet&);
  void setMass(CoordSet&, double);
  int getVol(CoordSet&, DynOps&);
  void setinistr(double*);
  void setvol0();
  double getvol0();
  double getmass();
  void calcde(DynOps&, Solver&, CoordSet&);
  void constructMat(DynOps&, Solver&);
  void large(DynOps&);
  void updatenodalforce(CoordSet&, DynOps&);
  void updatea(CoordSet&, Curveset&, Solver&, damping&, StaticSolver&);
  int getouttype();
  double* getoutstress(double* p);
  double* getoutstrain(double*);
  int sethistory(int);
  double* getouthis(double*);
  void hourglassctrl(DynOps&, CoordSet&, int&, double&);
  double EleTimeStep(CoordSet&);
  double* getlocal(CoordSet&);
  double getfm();

  // reset
  int ResetData(double*, int);
};
#endif
