#ifndef _MATRIXTIMERS_H_
#define _MATRIXTIMERS_H_




class MatrixTimers {
 public:
   double readTime;
   double setUpDataTime;
   double solveTime;


   long long memoryParse;
   long long memorySetUp;
   long long memorySolve;

   MatrixTimers() {  readTime = 0.0;  setUpDataTime = 0.0;
                   solveTime = 0.0;
                    memoryParse = 0; memorySetUp = 0;
                    memorySolve = 0; }
};


#endif
