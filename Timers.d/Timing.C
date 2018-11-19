#include <stdio.h>
#include <time.h>

#include "../Timers.d/Timing.h"
#include "../Timers.d/GetTime.h"
#include "../Utils.d/Memory.h"

void
startTimerMemory(double &time, long long &mem)
{
  time -= getTime();
  mem  -= memoryUsed();
}

void
stopTimerMemory(double &time, long long &mem)
{
 time += getTime();
 mem  += memoryUsed();
}



