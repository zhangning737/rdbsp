#include <sys/time.h>
#include "../Timers.d/GetTime.h"

// function to get current time

double getTime() {
 timeval tp;
 struct timezone tz;
 gettimeofday(&tp, &tz);
 return 1000.0*tp.tv_sec + tp.tv_usec/1000.0;
}

