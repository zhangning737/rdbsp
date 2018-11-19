#include "../Element.d/Part.h"
#include <string.h>

Part::Part(){
    
    length = 0;
    partnum =0;
    vect = new int;
    parttype = 0;

}

Part::Part(int n){
    
    length = 0;
    partnum =n;
    vect = new int;
    parttype = 0;

}

Part::Part(const Part& pr){
    length = pr.length;
    partnum = pr.partnum;
    parttype = pr.parttype;
    vect = new int[length];
    memcpy(vect,pr.vect,length*sizeof(int));
}


void
Part::addvect(int num, int* nnn){
    if(vect) {
    // Allocate memory for correct number of dbc
        int *nd = new int[length+num];

   // copy old dbc
   int i;
   for(i=0; i < length; ++i)
      nd[i] = vect[i];

   // copy new dbc 
   for(i=0; i< num; ++i)
   nd[i+length] = nnn[i];

   // set correct number of dbc
   length += num; 

   // delete old array of dbc 
   delete []vect;
   
   // set new pointer to correct number of dbc 
   vect = nd;

 } else {
 length = num;
 vect= nnn;
        }
}



int Partset::last()
{
 int last = size();
 while(--last >= 0)
    if(parts[last] != 0) break;

 return last+1;
}

void Partset::list()
{
}

typedef Part *parP;

Partset::Partset(int initsize)
{
  parts = new parP[initsize];
  pmax = initsize;
  int i;
  for(i = 0; i < pmax; ++i)
    parts[i] = 0;
}

void
Partset::partadd(int pn, int type,Part *el)
{

    el->partnum = pn;
    el->parttype = type;
    
    int newsize = pmax+1;
    parP *np = new parP[newsize];
    int i;
    for(i= 0; i < pmax; ++i)
     np[i] = parts[i];

     pmax = newsize;
     np[pmax-1] = 0;
    delete[] parts;
    parts = np;

  parts[pmax-1] = el;
}

Part*
Partset::getpart(int elnum)
{
    int i;
    for(i=0;i<pmax;++i)
    {
        if(parts[i]->partnum == elnum)
            return parts[i];
      
    }
    return parts[elnum];
}

void
Partset::partadd(int pn, int type,int n, int *el)
{
    Part *p = new Part();
    p->addvect(n, el);
    partadd( pn,  type,p);
 
}
