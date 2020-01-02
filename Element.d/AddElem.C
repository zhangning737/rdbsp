#include <stdio.h>

#include "../Element.d/Bricko.d/EightNodeBricko.h"
#include "../Element.d/Element.h"
void Elemset::elemadd(int num, int etype, int nnodes, int *n) {
  Element *ele;

  switch (etype) {
    case 1:
      ele = new (ba) EightNodeBricko(num, n);
      break;
    default:
      return;
  }

  elemadd(ele);
}
