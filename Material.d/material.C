#include <stdio.h>

#include "../Material.d/material.h"
#include "../Material.d/matela/elastic.h"
#include "../Material.d/mohr/mohr.h"

void
Matset::propadd(int num, int mtype, int nprops, double *p)
{
   StructProp *property;

   switch(mtype) 
   {
     case 1:
       property = new (ba) Material_Ela(num,nprops, p);
       break;
   case 2:
       property = new (ba) Material_Mohr(num, nprops, p);
       break;
   default:
       break;
   }
 
     propadd(property);
}
