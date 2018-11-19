/*
 * material.h
 *
 *  Created on: 2013-6-9
 *      Author: zn
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../Utils.d/BlockAlloc.h"

// ****************************************************************
// * Class StructProp contains the defined structural properties  *
// ****************************************************************

// contains material and geometrical properties of elements

class StructProp {
  public:
    int matnum;     //number of material
    //	double	*mp;      // material propertys
 public:
    virtual StructProp *clone() { return 0; }
    virtual double*   getprops(double * = 0) = 0;
    virtual double calcmass(double ) = 0;
    virtual int calcstress(double*,double*,double*,double,double,int&,int&) = 0;
    virtual double getwavespeed()= 0;
    virtual double getdensity() = 0;
    virtual int getnprops() = 0;
    virtual int gettype() = 0;
    virtual int init() = 0;

//    friend class Domain;
};

class Matset {
  protected:
    StructProp **props;
    int pmax;
    BlockAlloc ba;
  public:
    Matset(int = 0);
    int size() { return pmax; }
    int last();
    StructProp *operator[] (int i) { return props[i]; }
    void propadd(StructProp*);
    void propadd(int num, int type, int nprops, double *props);
    void list();
    StructProp *getmat(int);
};


#endif /* MATERIAL_H_ */
