#include <time.h>
#include "../Timers.d/GetTime.h"

// function to get current time

double getTime() {
 time_t tp;
 struct tm tz;
 time(&tp);
 return tp;
}

