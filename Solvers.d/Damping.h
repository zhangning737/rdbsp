#ifndef _DAMPING_H_
#define _DAMPING_H_

class damping{
 public:
    int dampingtype;
    double local;
    double combined;
    double rayleigh;
    damping(){
        dampingtype =0;
        local = 0.8;
        combined = 0.2;
        rayleigh = 0.0;
    }
};

#endif
