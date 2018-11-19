#ifndef _DOMAIN_H_
#define _DOMAIN_H_

#include <stdio.h>

#include "../Element.d/Element.h"
#include "../Element.d/Part.h"
#include "../Utils.d/resize_array.h"
#include "../Timers.d/MatrixTimers.h"
#include "../Material.d/material.h"
#include "../Utils.d/curve.h"
#include "../Utils.d/Solverinfo.h"
#include "../Solvers.d/Solver.h"
#include "../Solvers.d/Damping.h"
#include "../Utils.d/OutputInfo.h"
#include "../Solvers.d/ConstData.h"

//#include "../Registration.d/getid.h"


//fenqupolie
class FenQu{
public:
	int key[2];
	double ftime[2];
	double oktime[2];
	int step;
	int rstep;
	int rkey[2];
	FenQu(){

	}
};
// Boundary Condition Structure
/*
struct BCond {
int    nnum;   // node number
int    dofnum; // dof number
int    curvenum; //dof curve
double val;    // value of bc
};

struct BCFixed{
int nnum;
int fix[3];
};

struct Bulk_Vis{
int bvflg;
double q1;
double q2;
};
*/
class BCond {
public:
	int    nnum;   // node number
	int    dofnum; // dof number
	int    curvenum; //dof curve
	double val;    // value of bc
};

class BCFixed{
public:
	int nnum;
	int fix[3];
};

class Bulk_Vis{
public:
	int bvflg;
	double q1;
	double q2;
};

class INISTRESS{
public:
	int nele;
	double istress[6];
};

class attribute{
public:
	int elemnum;
	int matnum;
};

class fileinfo{
public:
	char infpath[256];
	char refpath[256];
	char *outputname;
	fileinfo(){outputname = NULL;}
};

class versionctrl{
public:
	char *version;
	char *statversion;
	char *dataversion;
};



class Domain {
protected:

	// The following Domain class data members are needed for all types
	// problems as well as all types of elements.
	FenQu *fq;
	//debug
	int debugflg;
	int restartflg;
	int numnodes;	    // number of nodes
	CoordSet &nodes;    // All the nodes

	int numele;		    // number of elements
	Elemset &eset;      // set of elements

	int exactNumEle;
	Elemset packedEset;	 // set of compressed elements
	int exactNumNode;
	CoordSet packedNodes;

	int nummat;      //number of materials
	Matset &mset;    //set of material

	int numcu;
	Curveset &cset;

	int numpart;
	Partset &pset;


	int numfixed;
	BCFixed* nfixed;

	int numDirichlet;
	BCond* dbc;

	int numNeuman;
	BCond* nbc;

	int numIVel;		 // number of initial velocities
	BCond *iVel;		 // set of those initial velocities

	int numIAcc;
	BCond *iAcc;

	int numist;	            // number of inital stress
	ResizeArray<INISTRESS>  inistr;// set of those properties

	int numpress;
	ResizeArray<BPress> pres;

	DynOps dynops;

	MatrixTimers mm;

	SolverInfo sinfo;
	Solver solv;


	int numatt;
	ResizeArray<attribute> attrib;
	int numpatt;
	ResizeArray<attribute> pattrib;

	damping damp;
	StaticSolver sts;

	int numnout;
	int* nout;

	int numeout;
	int* eout;


	OutPutInterval ointer;
	OutPutInterval hisointer;

	int hisnodenum;
	int* hisnout;

	int hiselemnum;
	int* hiseout;

	OutPutInterval statinter;

	fileinfo finfo;

	versionctrl ver;

	double gravity[3];
	int jaumannflg;
	int hourglassflg;
	double hourglasspara;
	int numhis;

	Bulk_Vis *bv;
	int cleandvaflg;
	int exportflacflg;
	//     double *gravityAcceleration;   // (gx,gy,gz)

	Domain(Domain &, int nele, int *ele, int nnodes, int *nodes);

public:
	Domain();

	// Functions to support the parsing:
	int setdebug(){debugflg = 1;  return debugflg;    }
	int setexportflacflg(){exportflacflg = 1;  return exportflacflg;   }
	int setrestartflg(){restartflg = 1; return restartflg;    }
	int  addNode(int nd, double xyz[3]);
	int  addElem(int en, int type, int nn, int *nodes);
	int  addMat(int n, int mtype, int nprops, double *props);
	int  addPart(int n, int ptype, Part *p);
	int  addPart(int n, int ptype, int num, int *p);
	int  setDirichlet(int,BCond *);
	int  setNeuman(int,BCond *);
	int  setfix(int, BCFixed*);
	int  setIVel(int, BCond *);
	int  setIAcc(int, BCond *);
	int  setinistress(int, double*);
	int  setpress(BPress&);
	void setlarge();
	void setgrav(double, double, double);
	void setatt(int, int);
	void setpatt(int,int);

	int  addCurve(int, int , CurveCoef*);
	int  addCurve(int, int , double*);
	int  SetCurrentTime(double);
	int  setendtime(double endt){ sinfo.tmax = endt;return 0;  }
	int  settimestep(int, double);
	int  settimestep(int);
	int  calctimestep();
	int sethourglass(int hgflg){hourglassflg = hgflg;hourglasspara = 0.0; return 0;}
	int sethourglass(int hgflg, double qhg){
		hourglassflg = hgflg;
		hourglasspara = qhg; return 0;
	}
	MatrixTimers &getTimers()    { return mm; }
	SolverInfo   &solinfo() {return sinfo;     }
	int  probType() { return sinfo.probType; }
	int inisolver(SolverInfo&);

	int setdamping(int, double);

	int staticterm();
	int staticterm(double);

	void setUpData();
	void preProcess();
	void solve();
	void setointer(int _otype,double _tinterval){ointer.outfiletype = _otype;ointer.ninterval = 0; ointer.tinterval = _tinterval;
	ointer.ncount = 0; ointer.tcount = 0.0;}
	void setointer(int _otype,int _ninterval){ointer.outfiletype = _otype;ointer.ninterval = _ninterval; ointer.tinterval = 0.0;
	ointer.ncount = 0; ointer.tcount = 0.0;}
	void sethisointer(double _histinterval){ hisointer.ninterval = 0; hisointer.tinterval = _histinterval;
	hisointer.ncount = 0; hisointer.tcount = 0.0;
	}

	void setsinter(double _tinterval){statinter.ninterval = 0; statinter.tinterval = _tinterval;
	statinter.ncount = 0; statinter.tcount = 0.0;}
	void setsinter(int _ninterval){statinter.ninterval = _ninterval; statinter.tinterval = 0.0;
	statinter.ncount = 0; statinter.tcount = 0.0;}

	void setinfilepath(char*);
	void setrefilepath(char*);

	void addnout(int);
	void addeout(int);
	int TECPLOT_VNN(int&, char*);
	int TECPLOT_VL(int*);

	int setoutfile(char*);
	void addhisnode(int);
	void addhiselem(int);
	void dynaplotoutput(int,double);
	void sethisdata(int his){numhis = his; }
	void dynahisoutput();
	int  dynastatoutput(int, double);
	int  dynatecpoutput(int,double, int*,int*,int*);

	void iniversion(){
		ver.version = "V1.00";
		ver.statversion = "V1.00";
		ver.dataversion = "V1.00";
	}
	//restart set part
	int ResetSolver(int, double*);
	int ReadCDerflg(int*);
	int ResetNData(double*, int*, int);
	int ResetEData(double*, int, int);

	int delelem(int);
	int delpart(int);
	int initmass();
	int userdel();
	int setbulkvisco(double, double);
	int cleardv();
	int exportflac();
	int packelemdelete();
	int packelemall();
	double calcfm();
	int fenqupolie();
	int setfenqu(double,double,double, double);
};

inline int
Domain::addElem(int en, int type, int nn, int *nodes)
{
	eset.elemadd(en, type, nn, nodes);
	return 0;
}

inline int
Domain::addMat(int n, int mtype, int nprops, double *props)
{
	mset.propadd(n, mtype, nprops, props);
	return 0;
}

inline int
Domain::addCurve(int n,int l, CurveCoef *nv)
{
	cset.curveadd(n,l,nv);
	return 0;
}

inline int
Domain::addCurve(int n,int l, double *nv)
{
	cset.curveadd(n,l,nv);
	return 0;
}


inline int
Domain::addPart(int n, int type, Part *p){
	pset.partadd(n, type, p);
	return 0;
}

inline int
Domain::addPart(int n, int ptype, int num, int *p){
	pset.partadd(n,ptype,num,p);
	return 0;
}
#endif
