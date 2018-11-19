#ifndef _STATICTIMER_H_
#define _STATICTIMER_H_

#include <stdio.h>

class Timings;
class Domain;

class StaticTimers {
public:
  double solve, preProcess;

  long long memoryPreProcess;
  long long memorySolve;

  FILE *f;

  StaticTimers() {
                    solve    = 0.0;
                    preProcess = 0.0;
                   f = NULL;
                   memoryPreProcess = 0;
                   memorySolve = 0;
	         }

};

#endif
