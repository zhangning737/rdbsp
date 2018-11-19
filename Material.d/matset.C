#include "../Material.d/material.h"

// Last returns the true last defined element
typedef StructProp *proP;

Matset::Matset(int initsize)
{
  props = new proP[initsize];
  pmax = initsize;
  int i;
  for(i = 0; i < pmax; ++i)
    props[i] = 0;
}

int Matset::last()
{
 int last = size();
 while(--last >= 0)
    if(props[last] != 0) break;

 return last+1;
}

void Matset::list()
{
}


void
Matset::propadd(StructProp *p)
{
    int newsize = pmax+1;
    proP *pr = new proP[newsize];
    int i;
    for(i= 0; i < pmax; ++i)
     pr[i] = props[i];
     pmax = newsize;
     pr[pmax-1] = 0;
    delete[] props;
    props = pr;

  props[pmax-1] = p;
}

StructProp*
Matset::getmat(int mnum)
{
    int i;
    for(i=0;i < pmax ; ++i)
    {
        if(props[i]->matnum == mnum)
            return props[i];

    }
}
