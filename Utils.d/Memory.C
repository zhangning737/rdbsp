#include <malloc.h>
#include <stdio.h>
#include <sys/types.h>
#include "../Utils.d/Memory.h"

long long currentSize = 0;
long long deletedSize = 0;

void * operator new( size_t size )
{
  void *ptr = malloc( size );

  //  size_t allocatedMemory = mallocblksize(ptr);
    size_t allocatedMemory = sizeof(ptr);
  currentSize += allocatedMemory;

  //fprintf(stderr,"Allocate    %14d bytes %14d bytes\n",
  //        allocatedMemory,currentSize);

  return ptr;
}

void operator delete(void *p)
{
    // size_t deletedMemory =  mallocblksize(p);
     size_t deletedMemory =  sizeof(p);
 deletedSize += deletedMemory;
 currentSize -= deletedMemory;
 //fprintf(stderr,"De-allocate %14d bytes %14d bytes\n",
 //        deletedMemory,currentSize);
 free(p);
}

long long
memoryUsed()
{
 return currentSize;
}

long long
memoryDeleted()
{
 return deletedSize;
}

