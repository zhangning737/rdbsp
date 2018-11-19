#include "../Driver.d/Domain.h"
#include "../Element.d/Element.h"
#include "../Solvers.d/ConstData.h"

extern Domain *domain;

class NList{
 public:
    int n;
    int *d;
    NList();
    NList add(int&);
};

class BCList
{
public:
  int n;
  int maxn;
  BCond *d;
  BCList();    //initial a bcond list
  BCList add(BCond&);  //define add a bcond to the list
};

class BCFList
{
public:
  int n;
  BCFixed *d;
  BCFList();
  BCFList add(BCFixed&);
};

class CurveTable
{
 public:
    int n;
    CurveCoef *d;
    CurveTable();
    CurveTable add(CurveCoef&);
};

typedef struct NumedNode
{
  int num;
  double xyz[3];
} NumedNode;


class PropList{
 public:
    int n;
    double *d;
    PropList();
    PropList add(double &);
    PropList add(PropList *p);
};
