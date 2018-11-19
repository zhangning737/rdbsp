#ifndef _SOLVER_H_
#define _SOLVER_H_

class Solver {
    public:
    double currentTime;// to store solution time
    double dt;
    double tmax;
    double inidt;
    double factor;
    long long istep;
    int timestepflg;
    

    
    // function to return solution time
    double getcurrentTime() {return currentTime;}
    double getdt(){return dt;    }
    Solver(){
        currentTime = 0.0;
        dt = 0.0;
        tmax = 0.0;
        inidt = 0.0;
        factor = 0.0;
        istep = 0;
        timestepflg = 0;
        }
};

class StaticSolver{
    public:
        int staticflg;
        double miniE;
        double maxE;
        double Fm;
        int termsign;
        StaticSolver(){
            staticflg = 0;
            miniE = 1.0e-5;
            maxE = 0.0;
            termsign = 0;
            Fm = 0.0;
        }
};
#endif
