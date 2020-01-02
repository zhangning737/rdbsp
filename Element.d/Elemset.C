#include "../Element.d/Element.h"

// Last returns the true last defined element
int Elemset::clear() {
  int i;
  for (i = 0; i < emax; ++i) {
    elem[i] = NULL;
  }
  emax = 0;
  return 1;
}

int Elemset::last() {
  int last = size();
  while (--last >= 0)
    if (elem[last] != 0) break;

  return last + 1;
}

void Elemset::list() {}

typedef Element *ElemP;

Elemset::Elemset(int initsize) {
  elem = new ElemP[initsize];
  emax = initsize;
  int i;
  for (i = 0; i < emax; ++i) elem[i] = 0;
}

void Elemset::elemadd(Element *el) {
  int newsize = emax + 1;
  ElemP *np = new ElemP[newsize];
  int i;
  for (i = 0; i < emax; ++i) np[i] = elem[i];

  emax = newsize;
  np[emax - 1] = 0;
  delete[] elem;
  elem = np;

  elem[emax - 1] = el;
}

Element *Elemset::getelem(int elnum) {
  int i;
  for (i = 0; i < emax; ++i) {
    if (elem[i]->elemnum == elnum) return elem[i];
  }
  return elem[elnum];
}
