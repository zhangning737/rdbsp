#ifndef _PART_H_
#define _PART_H_
#include "../Utils.d/BlockAlloc.h"

class Part {
 public:
  int partnum;
  int *vect;
  int parttype;
  int length;

 public:
  Part();
  Part(int);
  Part(const Part &);
  ~Part() { delete[] vect; }
  void addvect(int, int *);
};

class Partset {
 protected:
  int pmax;
  Part **parts;
  BlockAlloc ba;

 public:
  Partset(int = 0);
  int size() { return pmax; }
  int last();
  Part *operator[](int i) { return parts[i]; }
  //   void partadd(Part*);
  void partadd(int num, int nn, Part *partn);
  void partadd(int pn, int type, int n, int *el);
  void list();
  Part *getpart(int);
};

#endif
