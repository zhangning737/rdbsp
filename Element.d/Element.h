#ifndef	_ELEMENT_H_
#define	_ELEMENT_H_

#include "../Utils.d/BlockAlloc.h"
#include "../Material.d/material.h"
#include "../Utils.d/curve.h"
#include "../Utils.d/Solverinfo.h"
#include "../Solvers.d/Solver.h"
#include "../Solvers.d/Damping.h"
#include "../Utils.d/utilities.h"
#include "../Utils.d/Sign.h"
#include "../Utils.d/resize_array.h"

//****************************************************************
//*
//*     class Node: Keeps the coordinates of a node
//*
//****************************************************************
class DynOps
{
 public:
    double *ijac;
    double *vort;
    double *de;
    double *pkxj;
    double *sig;
    DynOps(){ijac = new double[81]; vort =new double[81]; de = new double[81];  pkxj = new double[81];sig = new double[81]; }
    void    reini(){
        int i;
        for(i = 0; i < 81; ++i){
            ijac[i] = 0.0;
            vort[i] = 0.0;
            de[i]   = 0.0;
            pkxj[i] = 0.0;
            sig[i]  = 0.0;
        }
    }
};
class Node {
  public:
	// Constructors
        Node() {}
        Node(int num,double *xyz) {nodenum = num; x = xyz[0]; y = xyz[1]; z = xyz[2];
            int i;
            for(i=0;i<3;++i){
                disdef[i] =0.0;
                u[i] = 0.0;
                v[i] = 0.0;
                a[i] = 0.0;
                cun[i] = 0;
                cfn[i] = 0;
                defined[i] =0;
                grav[i] = 0.0;
                deltaf[i] = 0.0;
                ubf[i] = 0.0;
            }
            fixed =0; mass = 0.0; EngKinetic = 0.0; ubfr = 0.0;}
        int setfix(int*);
        int setdisp(int, int ,double);
        int setvel(Solver&);
        int setacc(Curveset&);
        void updatea(Curveset&, Solver&, damping&, StaticSolver&);
        void updateu(Solver&);
        void updateE();
        void updateubf();
        void calcBF(double*);
        void updategeo();
        void cleaninterf();
        void cleanextf();
        void cleanEng();
        int cleandv();

	// Coordinates
        int nodenum;
        double 	x;
        double 	y;
        double 	z;
        double disdef[3];
        double  u[3];
        double  v[3];
        double  a[3];
        double  interf[3];
        double  extf[3];
        double deltaf[3];
        double grav[3];
        int fixed;//0 no fixed 1 2 3 three directtion 456 2 direction 7 all fixed
        int defined[3]; // simliar as above
        int cun[3];
        int cfn[3];
        double mass;
        double EngKinetic;
        double ubf[3];
        double ubfr;
};

// ****************************************************************
// *                        WARNING                               *
// *       Nodes in the CoordSet are from 0 and not from 1        *
// *       It is a good idea to subtract 1 from node input        *
// *       from the user at any time a node is read in rather     *
// *       then keeping it from 1 and then subtracting 1 here     *
// *       and there....                                          *
// *       functions for this class are in Element.d/Coordset.C   *
// ****************************************************************

class CoordSet {
        int nmax;
	Node **nodes;
    BlockAlloc ba;
public:
        // Constructors
        CoordSet(int = 0);
        CoordSet(const CoordSet&, int n, int *nd);

        CoordSet * copy();

	// Member functions
        int  size() { return nmax ; }
        void nodeadd(int n, double*xyz);
        void nodeadd(Node*);
	    Node &getNode(int);

        Node *operator[] (int i) { return nodes[i]; }

        int getnindex(int);

        //   Node &operator[] (int i) { return *nodes[i]; }
        

        void deleteNodes() { delete [] nodes; }
};

// ****************************************************************
// * Class Element defines functions for finite elements.         *
// * Each element has a structural property and a pressure        *
// * associated with it. Each element defines it's own dofs, sets *
// * it's own node numbers, calculates stiffness, calculates mass *
// * von mises stress, internal force and displacements. Where    *
// * these functions are written for each type of element and if  *
// * a function is not defined for an element type, it will       *
// * default to the appropriate function in Element.C             *  
// * i.e. an element with a zero mass matrix, will just return a  *
// * matrix of the appropriate size containing zeroes.            *
// ****************************************************************

class Element {
  public:
	int elemnum;
    StructProp *prop;
    int eldel;
    int elfail;
    int plas;
  public:
    Element(){eldel = 0;
        elfail = 0;
        plas = 0;    }
       void setProp(StructProp *p) { prop = p; }
        virtual Element *clone() { return 0; }

        virtual int    GetEleType() = 0;
        virtual int    getDimNumber();
        virtual int    numDofs()=0;

        virtual int    numNodes() = 0;
        virtual int*   nodes(int* = 0) = 0;

        virtual void    renum(CoordSet&) = 0;
        virtual int     rerenum(CoordSet&) = 0 ;
        virtual int     getVol(CoordSet&, DynOps&) =0;
        virtual void    setMass(CoordSet&,double) = 0;
        virtual void    setinistr(double*) = 0;
        virtual void    setvol0() = 0;
        virtual double  getvol0() = 0;
        virtual void    calcde(DynOps&, Solver&, CoordSet&) = 0;
        virtual void    constructMat(DynOps&, Solver&) = 0;
        virtual void    large(DynOps&) = 0;
        virtual void    updatenodalforce(CoordSet&, DynOps&) = 0;
        virtual void    updatea(CoordSet&,Curveset&, Solver&, damping&,StaticSolver&) = 0;
        virtual int     getouttype() = 0;
        virtual double* getoutstress(double*) = 0;
        virtual double* getoutstrain(double*) = 0;
        virtual int     sethistory(int)   = 0;
        virtual double* getouthis(double*) = 0;
        virtual void    hourglassctrl(DynOps&, CoordSet&, int&, double&) = 0;
        virtual double  EleTimeStep(CoordSet&) = 0;
        virtual int     ResetData(double* ,int) = 0;
        virtual double*  getlocal(CoordSet&) =0;
        virtual double  getfm() =0;
        virtual double getmass() = 0;
            
        friend class Domain;
};

//*****************************************************************
//*                        WARNING                                *
//*       The same remark as for node is valid for elements       *
//*       The functions for this class are in Element.d/ElemSet.C *
//*****************************************************************


class Elemset {
  protected:
    Element **elem;
    int emax;
    BlockAlloc ba;
  public:
    Elemset(int = 0);
    int size() { return emax; }
    int last();
    Element *operator[] (int i) { return elem[i]; }
    void elemadd(Element *);
    void elemadd(int num, int type, int nnodes, int *nodes);
    void list();
    Element *getelem(int elnum);
    int clear();
};




class BPress{
 public:
    int cnum;
    double value;
    int nodelist[4];
    
    void renum(CoordSet&);
};

void calcpresstoforce(CoordSet&, double, int*);


#endif
