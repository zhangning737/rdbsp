#ifndef _BLOCK_ALLOC_H_
#define _BLOCK_ALLOC_H_

#include <sys/types.h>
#include <stdio.h>
#include "../Utils.d/resize_array.h"

class BlockAlloc {
    char *block;
    int index;
    int blLen;
    ResizeArray<char *> allBlocks;
    int nblock;
  public:
    BlockAlloc(int l = 4096) :
        allBlocks(0) { blLen = l; block = (char *)NULL; nblock = 0;}
    ~BlockAlloc();
    void *getMem(size_t nb);
};

void * operator new(size_t nbyte, BlockAlloc &block);

#endif
