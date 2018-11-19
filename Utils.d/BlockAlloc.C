#include <stdio.h>
#include "../Utils.d/BlockAlloc.h"

void *
BlockAlloc::getMem(size_t nbyte)
{
 // fprintf(stderr,"BLOCK ALLOC GET MEM\n");
  if(nbyte > blLen) return new char[nbyte];
  if(block == 0 || (index+nbyte) > blLen) {
     block = new char[blLen];
     allBlocks[nblock++] = block;
     index = 0;
  }
  if(nbyte & 0x7) {
    nbyte = (nbyte+8)-(nbyte & 0x7);
  }
  void *p = block+index;
  index += nbyte;
  return p;
}

BlockAlloc::~BlockAlloc()
{
 // fprintf(stderr,"BLOCK ALLOC DESTRUCTOR\n");
 int iBlock;
 for(iBlock = 0; iBlock < nblock; ++iBlock)
   delete [] allBlocks[iBlock];
}


void * operator new(size_t nbyte, BlockAlloc &block)
{
 //fprintf(stderr,"BLOCK ALLOC NEW\n");
 return block.getMem(nbyte);
}

