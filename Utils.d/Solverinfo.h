#ifndef _SOLVER_INFO_
#define _SOLVER_INFO_

struct SolverInfo {
    char** title;

   // Problem type parameters
   int probType;
    enum { Dynamic= 1, Static };

   // Dynamic problem parameters
    int timestepflg;
   double tmax;         // total time of simulation
   double inidt;           // time step size
    double dt;
    double tfactor;
    double totalt;
   double alphaDamp;    // mass matrix damping coefficient
   double  betaDamp;    // stiffness matrix damping coefficient
   double newmarkBeta;  // Newmark algorithm parameter (beta)
   double newmarkGamma; // Newmark algorithm parameter (alpha)
    long long istep;
    int CurveID;


   SolverInfo() { probType  = 1;
                timestepflg = 1;
                CurveID  = 0;
                  tmax = 0.0;
                  inidt = 0.0;
                  alphaDamp = 0.0;    // default no damping
                  betaDamp  = 0.0;    // default no damping
                  newmarkBeta = 0.0;
                  newmarkGamma = 0.0;
                  totalt     = 0.0;
                  tfactor    = 0.6;
                  istep = 0;
                  title = 0;
                   }

   // ---- SolverInfo inline functions ----

   // Note: the last double would be the thermal time step value
    void setTimes(double _tmax, double _inidt ,double _totalt)
    { tmax = _tmax; inidt = _inidt;totalt = _totalt; dt = inidt;}

   // Set Rayleigh damping stiffness coefficient alpha
   // and Rayleigh damping mass coefficient beta
   void setDamping(double beta, double alpha)
    { alphaDamp = alpha; betaDamp = beta; }


   void setProbType(int pbt)
    { probType = pbt;  }

};

#endif
