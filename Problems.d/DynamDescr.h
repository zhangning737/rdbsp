#ifndef _DYNAM_DESCR_H_
#define _DYNAM_DESCR_H_

#include "../Driver.d/DynamProbType.h"

class Domain;
class DynamMat;
class StaticTimers;

// Single Domain Dynamic Post Processor Class


// Single Domain Dynamic Problem Description

class SingleDomainDynamic {
    Domain *domain;
    StaticTimers *times;
    Solver *solver;

 public:
    SingleDomainDynamic(Domain *d) { domain = d; }
    void getTimes(double &dt, double &t);
    void preProcess();
    Solver *getSolver();
    void printTimers();

// Central Difference only related subroutines
    void computeStabilityTimeStep(double& dt, DynamMat& dMat);

};


#endif
