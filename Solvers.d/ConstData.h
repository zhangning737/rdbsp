#ifndef _CONSTDATA_H_
#define _CONSTDATA_H_
struct TypeInfo{
    
enum NOUTPUTT{displacement=1,
              interforce,
              velocity,
              accelerate,
              exterforce
} ;

enum EOUTPUTT{
    Stress=1,Strain,History,PrinStress, PrinMises,Center
};

 enum ELEMT{Solid =1, Truss};

    enum TIMESTEPT{ATUO = 1, Fixed, Curve};
    
    NOUTPUTT NOutputT;
    EOUTPUTT EOutputT;
    ELEMT ElemT;
    TIMESTEPT TimestepT;
    TypeInfo(){ }
};


#endif
