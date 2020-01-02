#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <alloca.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "../Driver.d/Domain.h"
#include "../Material.d/Stress_Prin.h"
#include "../Material.d/material.h"
#include "../Math.d/egen.h"
#include "../Math.d/mathfem.h"
#include "../TecplotIO.d/TECIO.h"
#include "../Utils.d/Sign.h"
#include "../Utils.d/linkfc.h"

INISTRESS emptyst;
attribute emptyat;
BPress emptypr;

Domain::Domain()
    : eset(*(new Elemset)),
      nodes(*(new CoordSet)),
      pset(*(new Partset)),
      mset(*(new Matset)),
      inistr(emptyst),
      pres(emptypr),
      attrib(emptyat),
      pattrib(emptyat),
      cset(*(new Curveset))

{
  debugflg = 0;
  restartflg = 0;
  numnodes = 0;
  numele = 0;
  numpart = 0;
  exactNumNode = 0;
  exactNumEle = 0;
  jaumannflg = 0;
  dbc = new BCond;
  nfixed = new BCFixed;
  nummat = 0;
  numfixed = 0;
  numDirichlet = 0;
  numNeuman = 0;
  numIVel = 0;  // number of initial velocities
  numIAcc = 0;
  numist = 0;  // number of inital stress
  numpress = 0;
  gravity[0] = 0.0;
  gravity[1] = 0.0;
  gravity[2] = 0.0;
  numatt = 0;
  numpatt = 0;
  numcu = 0;
  numnout = 0;
  numeout = 0;
  hisnodenum = 0;
  hiselemnum = 0;
  fq = new FenQu;
  nout = new int;
  eout = new int;
  hisnout = new int;
  hiseout = new int;
  jaumannflg = 0;
  hourglassflg = 0;
  numhis = 0;
}

int Domain::addNode(int n, double *d) {
  nodes.nodeadd(n, d);
  return 0;
}

// set dirichlet boundary conditions
int Domain::setDirichlet(int _numDirichlet, BCond *_dbc) {
  // dbc = dirichlet boundary conditions
  if (dbc) {
    // Allocate memory for correct number of dbc
    BCond *nd = new BCond[numDirichlet + _numDirichlet];

    // copy old dbc
    int i;
    for (i = 0; i < numDirichlet; ++i) nd[i] = dbc[i];

    // copy new dbc
    for (i = 0; i < _numDirichlet; ++i) nd[i + numDirichlet] = _dbc[i];

    // set correct number of dbc
    numDirichlet += _numDirichlet;

    // delete old array of dbc
    delete[] dbc;

    // set new pointer to correct number of dbc
    dbc = nd;

  } else {
    numDirichlet = _numDirichlet;
    dbc = _dbc;
  }
  return 0;
}

int Domain::setNeuman(int _numNeuman, BCond *_nbc) {
  if (nbc) {
    // Allocate memory for correct number of dbc
    BCond *nd = new BCond[numNeuman + _numNeuman];

    // copy old dbc
    int i;
    for (i = 0; i < numNeuman; ++i) nd[i] = nbc[i];

    // copy new dbc
    for (i = 0; i < _numNeuman; ++i) nd[i + numNeuman] = _nbc[i];

    // set correct number of dbc
    numNeuman += _numNeuman;

    // delete old array of dbc
    delete[] nbc;

    // set new pointer to correct number of dbc
    nbc = nd;

  } else {
    numNeuman = _numNeuman;
    nbc = _nbc;
  }
  return 0;
}

int Domain::setfix(int _numfixed, BCFixed *_nfixed) {
  if (nfixed) {
    // Allocate memory for correct number of dbc
    BCFixed *nd = new BCFixed[numfixed + _numfixed];

    // copy old dbc
    int i;
    for (i = 0; i < numfixed; ++i) nd[i] = nfixed[i];

    // copy new dbc
    for (i = 0; i < _numfixed; ++i) nd[i + numfixed] = _nfixed[i];

    // set correct number of dbc
    numfixed += _numfixed;

    // delete old array of dbc
    delete[] nfixed;

    // set new pointer to correct number of dbc
    nfixed = nd;

  } else {
    numfixed = _numfixed;
    nfixed = _nfixed;
  }
  return 0;
}

int Domain::setIVel(int _numIVel, BCond *_iVel) {
  if (iVel) {
    // Allocate memory for correct number of dbc
    BCond *nd = new BCond[numIVel + _numIVel];

    // copy old dbc
    int i;
    for (i = 0; i < numIVel; ++i) nd[i] = iVel[i];

    // copy new dbc
    for (i = 0; i < _numIVel; ++i) nd[i + numIVel] = _iVel[i];

    // set correct number of dbc
    numIVel += _numIVel;

    // delete old array of dbc
    delete[] iVel;

    // set new pointer to correct number of dbc
    iVel = nd;

  } else {
    numIVel = _numIVel;
    iVel = _iVel;
  }
  return 0;
}

int Domain::setoutfile(char *of) { finfo.outputname = of; }

int Domain::setIAcc(int _numIAcc, BCond *_iAcc) {
  if (iAcc) {
    // Allocate memory for correct number of dbc
    BCond *nd = new BCond[numIAcc + _numIAcc];

    // copy old dbc
    int i;
    for (i = 0; i < numIAcc; ++i) nd[i] = iAcc[i];

    // copy new dbc
    for (i = 0; i < _numIAcc; ++i) nd[i + numIAcc] = _iAcc[i];

    // set correct number of dbc
    numIAcc += _numIAcc;

    // delete old array of dbc
    delete[] iAcc;

    // set new pointer to correct number of dbc
    iAcc = nd;

  } else {
    numIAcc = _numIAcc;
    iAcc = _iAcc;
  }
  return 0;
}

int Domain::setinistress(int num, double *stress) {
  inistr[numist].nele = num;
  inistr[numist].istress[0] = stress[0];
  inistr[numist].istress[1] = stress[1];
  inistr[numist].istress[2] = stress[2];
  inistr[numist].istress[3] = stress[3];
  inistr[numist].istress[4] = stress[4];
  inistr[numist].istress[5] = stress[5];
  numist++;
  return 0;
}

int Domain::setpress(BPress &bpr) {
  int i;
  pres[numpress].cnum = bpr.cnum;
  pres[numpress].value = bpr.value;
  for (i = 0; i < 4; ++i) {
    pres[numpress].nodelist[i] = bpr.nodelist[i];
  }
  numpress++;
  return 0;
}

void Domain::setinfilepath(char *inp) { strcpy(finfo.infpath, inp); }

void Domain::setrefilepath(char *rep) { strcpy(finfo.refpath, rep); }

void Domain::addnout(int noutnum) {
  if (nout) {
    // Allocate memory for correct number of dbc
    int *nd = new int[numnout + 1];

    // copy old dbc
    int i;
    for (i = 0; i < numnout; ++i) nd[i] = nout[i];

    // copy new dbc
    for (i = 0; i < 1; ++i) nd[i + numnout] = noutnum;

    // set correct number of dbc
    numnout += 1;

    // delete old array of dbc
    delete[] nout;

    // set new pointer to correct number of dbc
    nout = nd;

  } else {
    numnout = 1;
    nout[0] = noutnum;
  }
}

void Domain::addeout(int eoutnum) {
  if (eout) {
    // Allocate memory for correct number of dbc
    int *nd = new int[numeout + 1];

    // copy old dbc
    int i;
    for (i = 0; i < numeout; ++i) nd[i] = eout[i];

    // copy new dbc
    for (i = 0; i < 1; ++i) nd[i + numeout] = eoutnum;

    // set correct number of dbc
    numeout += 1;

    // delete old array of dbc
    delete[] eout;

    // set new pointer to correct number of dbc
    eout = nd;

  } else {
    numeout = 1;
    eout[0] = eoutnum;
  }
}

void Domain::addhisnode(int hisnode) {
  if (hisnout) {
    // Allocate memory for correct number of dbc
    int *nd = new int[hisnodenum + 1];

    // copy old dbc
    int i;
    for (i = 0; i < hisnodenum; ++i) nd[i] = hisnout[i];

    // copy new dbc
    for (i = 0; i < 1; ++i) nd[i + hisnodenum] = hisnode;

    // set correct number of dbc
    hisnodenum += 1;

    // delete old array of dbc
    delete[] hisnout;

    // set new pointer to correct number of dbc
    hisnout = nd;

  } else {
    numeout = 1;
    hisnout[0] = hisnode;
  }
}

void Domain::addhiselem(int hiselem) {
  if (hiseout) {
    // Allocate memory for correct number of dbc
    int *nd = new int[hiselemnum + 1];

    // copy old dbc
    int i;
    for (i = 0; i < hiselemnum; ++i) nd[i] = hiseout[i];

    // copy new dbc
    for (i = 0; i < 1; ++i) nd[i + hiselemnum] = hiselem;

    // set correct number of dbc
    hiselemnum += 1;

    // delete old array of dbc
    delete[] hiseout;

    // set new pointer to correct number of dbc
    hiseout = nd;

  } else {
    numeout = 1;
    hiseout[0] = hiselem;
  }
}

void Domain::setlarge() { jaumannflg = 1; }

void Domain::setgrav(double x, double y, double z) {
  //    gravity = new double[3];
  gravity[0] = x;
  gravity[1] = y;
  gravity[2] = z;
}

void Domain::setatt(int elnum, int mnum) {
  attrib[numatt].elemnum = elnum;
  attrib[numatt].matnum = mnum;

  numatt++;
}

void Domain::setpatt(int pnum, int mnum) {
  pattrib[numpatt].elemnum = pnum;
  pattrib[numpatt].matnum = mnum;

  numpatt++;
}

int Domain::inisolver(SolverInfo &sinfo) {
  solv.inidt = sinfo.inidt;
  solv.tmax = sinfo.tmax;
  solv.factor = sinfo.tfactor;
  solv.dt = sinfo.dt;
  solv.timestepflg = sinfo.timestepflg;
  return 0;
}

int Domain::SetCurrentTime(double t) {
  solv.currentTime = t;
  return 0;
}

int Domain::ResetSolver(int flg, double *st) {
  solv.timestepflg = flg;
  solv.inidt = st[0];
  solv.dt = st[1];
  solv.tmax = st[2];
  solv.factor = st[3];
  return 0;
}

int Domain::ReadCDerflg(int *flg) {
  int i;
  for (i = 0; i < numcu; ++i) {
    cset[i]->derflg = flg[i];
  }
  return 0;
}

int Domain::cleardv() { cleandvaflg = 1; }

void Domain::setUpData() {
  fprintf(stderr, "Start Setup Data\n");
  int i, j, iEle;

  numele = eset.last();     // number of elements
  numnodes = nodes.size();  // number of nodes
  nummat = mset.last();
  numcu = cset.last();
  numpart = pset.last();
  if (exportflacflg == 1) exportflac();
  // Reset Node Link Number
  fprintf(stderr, "Reset node index\n");
  for (i = 0; i < numele; ++i) {
    Element *el = eset[i];
    if (el == 0) {
      fprintf(stderr, "\n *** WARNING: Element was not existent element %d\n",
              i);
      continue;
    }
    el->renum(nodes);
  }

  for (i = 0; i < nummat; ++i) {
    mset[i]->init();
  }
  // Set up element attributes
  for (i = 0; i < numatt; ++i) {
    Element *ele = eset.getelem(attrib[i].elemnum);

    // Check if element exists
    if (ele == 0) {
      fprintf(stderr,
              "\n *** WARNING: Attribute was found for"
              " non existent element %d\n",
              attrib[i].elemnum);
      continue;
    }
    //  Check for Virtual elements
    if (attrib[i].matnum < 0)
      ele->setProp(NULL);
    else
      ele->setProp(mset.getmat(attrib[i].matnum));
  }

  for (i = 0; i < numpatt; ++i) {
    Element *ele;
    Part *pt = pset.getpart(pattrib[i].elemnum);
    for (j = 0; j < pt->length; ++j) {
      ele = eset.getelem(pt->vect[j]);

      // Check if element exists
      if (ele == 0) {
        fprintf(stderr,
                "\n *** WARNING: Attribute was found for"
                " non existent element %d\n",
                attrib[i].elemnum);
        continue;
      }
      //  Check for Virtual elements
      if (pattrib[i].matnum < 0)
        ele->setProp(NULL);
      else
        ele->setProp(mset.getmat(pattrib[i].matnum));
    }
  }

  /*
// int exactNumEle = 0;
  for(iEle = 0; iEle < numele; ++iEle) {
    Element *ele = eset[iEle];
    if(ele != NULL  && ele->prop != NULL && ele->eldel != 0 && ele->elfail !=0)
{ packedEset.elemadd(ele); exactNumEle += 1;
    }
}
  */
  packelemall();
  int errorel = numele - exactNumEle;
  if (errorel != 0)
    fprintf(stderr, "WARNING: %d element miss property \n", errorel);

  inisolver(sinfo);

  fprintf(stderr, "End Setup Data\n");
}

void Domain::preProcess() {
  int i, j;
  // inital the constraint boundary conditions
  for (i = 0; i < numfixed; ++i) {
    int *m = nfixed[i].fix;
    nodes.getNode(nfixed[i].nnum).setfix(m);
  }

  // initial the displacement boundary
  //          for(i = 0; i< numcu; ++i){
  //        cset[i]->dervalue();
  //    }

  for (i = 0; i < numDirichlet; ++i) {
    int cnum = dbc[i].curvenum;
    int dir = dbc[i].dofnum;
    double value = dbc[i].val;  // displacement value
    nodes.getNode(dbc[i].nnum)
        .setdisp(dir, cnum, value);  // set disp and defined
    if (cset.getCurve(cnum).derflg == 0) cset.getCurve(cnum).dervalue_a();
    nodes.getNode(dbc[i].nnum).setacc(cset);  // set velocity and defined
  }
  // initial the pressure
  // set up extern force
  int cnum;
  double value;
  int nodelist[4];
  if (restartflg != 1) {
    for (i = 0; i < numpress; ++i) {
      pres[i].renum(nodes);
    }
  }

  for (i = 0; i < numpress; ++i) {
    cnum = pres[i].cnum;
    if (cnum == 0) {
      value = pres[i].value;
    } else {
      value = pres[i].value * cset.getCurve(cnum).getvalue(0.0);
      //        fprintf(stderr,"the pressure change code has not writen yet");
      // return;
    }
    for (j = 0; j < 4; ++j) {
      nodelist[j] = pres[i].nodelist[j];
    }
    calcpresstoforce(nodes, value, nodelist);
  }
  // initial the element stress

  for (i = 0; i < numist; ++i) {
    eset.getelem(inistr[i].nele)->setinistr(inistr[i].istress);
  }
  // calcutate the
  initmass();

  double evol;
  double c[3][3];
  for (i = 0; i < exactNumEle; ++i) {
    Element *el = packedEset[i];
    if (el == 0) {
      fprintf(stderr, "\n *** WARNING: Element was not existent element %d\n",
              i);
      continue;
    }
    el->getVol(nodes, dynops);
    el->setvol0();
    evol = el->getvol0();
    el->setMass(nodes, evol);
    el->sethistory(numhis);
  }

  Node *nd;
  int iNod;
  // int exactNumEle = 0;
  for (iNod = 0; iNod < numnodes; ++iNod) {
    nd = nodes[iNod];
    if (nd != NULL && nd->mass != 0) {
      packedNodes.nodeadd(nd);
      exactNumNode += 1;
    }
  }
}

void Domain::solve() {
  fprintf(stderr, "Start Solve\n");

  int i, j, volerr;
  double dtk = 0.0;
  int outfilenum = 0;
  int statfilenum = 0;
  double Fm = 0.0;
  // clear data
  if (cleandvaflg != 0) {
    for (i = 0; i < numnodes; ++i) {
      Node *nd = nodes[i];
      nd->cleandv();
    }
  }

  // output initial state
  // creat tecplot file

  INTEGER4 *varlocation;
  INTEGER4 *varpositive;
  INTEGER4 *varshare;
  if (ointer.outfiletype == 2) {
    int tecvarnum;
    char *tecvarname = 0;
    tecvarname = new char[2048];
    TECPLOT_VNN(tecvarnum, tecvarname);

    varlocation = new INTEGER4[tecvarnum];
    varpositive = new INTEGER4[tecvarnum];
    varshare = new INTEGER4[tecvarnum];
    for (i = 0; i < tecvarnum; ++i) {
      varshare[i] = 0;
      varpositive[i] = 0;
    }

    TECPLOT_VL(varlocation);
    char *tecoutname = new char[256];
    if (finfo.outputname != NULL) {
      // tecoutname = finfo.outputname;
      sprintf(tecoutname, "%s.plt", finfo.outputname);

    } else {
      sprintf(tecoutname, "tecplot.plt");
    }

    INTEGER4 Debug, I, DIsDouble, VIsDouble, FileType;

    Debug = debugflg;
    VIsDouble = 1;
    DIsDouble = 1;
    FileType = 0;

    I = TECINI112((char *)"DATABASE OF DCP", (char *)tecvarname,
                  (char *)tecoutname, (char *)".", &FileType, &Debug,
                  &VIsDouble);

    // delete []tecoutname;
    // delete []tecvarname;
  }

  // creat file

  FILE *hout;
  char *rofnamehead = "hisoutput";
  char *rofnamenum = new char[7];
  char *rofnametail = ".his";
  char *rofname = new char[128];
  sprintf(rofname, "%s%s", rofnamehead, rofnametail);

  hout = fopen(rofname, "w");

  fclose(hout);

  FILE *hisout;
  char *rof = "hisv27.csv";
  hisout = fopen(rof, "w");
  fclose(hisout);

  // ==============================================

  //       if(ointer.outfiletype == 2)      TECEND112();
  if (ointer.outfiletype == 2) {
    dynatecpoutput(outfilenum, solv.currentTime, varlocation, varpositive,
                   varshare);
    fprintf(stderr, "time = %f  step = %d  ", solv.currentTime, solv.istep);
    fprintf(stderr, "EngKinetic = %6.3e  Writing Tecplot\n", sts.maxE);
  } else {
    dynaplotoutput(outfilenum, solv.currentTime);
    fprintf(stderr, "time = %f  step = %d  ", solv.currentTime, solv.istep);
    fprintf(stderr, "EngKinetic = %6.3e  Writing Paraview\n", sts.maxE);
  }

  ++outfilenum;
  dynahisoutput();
  sts.Fm = calcfm();

  // calc strain stress inter force
  while ((solv.tmax > 0.0) ? (solv.currentTime <= solv.tmax)
                           : (sts.termsign == 0)) {
    // fenqupolie();
    // in order to increase the effi comment packelement
    // packelemall();
    // clear the interforce to
    // calc timestep
    calctimestep();

    if (solv.dt < 1.0e-9) {
      fprintf(stderr, "timestep is too small\n");
      exit(-1);
    }

    //================recalc the mass =========

    initmass();

    for (i = 0; i < exactNumEle; ++i) {
      Element *el = packedEset[i];
      el->setMass(nodes, el->getvol0());  // calc mass for delete element
    }
    for (i = 0; i < numnodes; ++i) {
      Node *nd = nodes[i];
      nd->cleaninterf();
      nd->cleanextf();
      if (nd->mass != 0.0) {
        nd->setvel(solv);
        nd->updateu(solv);
      }
    }
    // ==================yinggai shiduile
    // set up extern force
    int cnum;
    double value;
    int nodelist[4];

    for (i = 0; i < numpress; ++i) {
      cnum = pres[i].cnum;
      if (cnum == 0) {
        value = pres[i].value;
      } else {
        value = pres[i].value * cset.getCurve(cnum).getvalue(solv.currentTime);
        //        fprintf(stderr,"the pressure change code has not writen yet");
        //      return;
      }
      for (j = 0; j < 4; ++j) {
        nodelist[j] = pres[i].nodelist[j];
      }
      calcpresstoforce(nodes, value, nodelist);
    }

    // calc strain and stress and force
    for (i = 0; i < exactNumEle; ++i) {
      Element *el = packedEset[i];
      if (el == 0) {
        fprintf(stderr, "\n *** WARNING: Element was not existent element %d\n",
                i);
        continue;
      }
      volerr = el->getVol(nodes, dynops);
      if (volerr != 0) {
        fprintf(stderr, "%d volume nagetative\n", el->elemnum);
        return;
      }

      el->calcde(dynops, solv, nodes);
      if (jaumannflg == 1) {
        el->large(dynops);
      }
      el->constructMat(dynops, solv);

      el->updatenodalforce(nodes, dynops);
      if (hourglassflg != 0) {
        el->hourglassctrl(dynops, nodes, hourglassflg, hourglasspara);
      }
    }

    for (i = 0; i < numnodes; ++i) {
      Node *nd = nodes[i];

      nd->calcBF(gravity);
    }
    // update the volcity and acclarate
    /*
   for(i = 0; i < exactNumEle; ++i)
   {
       Element *el = packedEset[i];
       el->updatea(nodes, cset, solv, damp);
   }
    */
    sts.Fm = calcfm();
    for (i = 0; i < numnodes; ++i) {
      Node *nd = nodes[i];
      if (nd->mass != 0.) {
        nd->updatea(cset, solv, damp, sts);
      }
    }

    for (i = 0; i < numnodes; ++i) {
      Node *nd = nodes[i];
      nd->updateE();
      nd->updateubf();
    }

    // set delete element a = 0?? no the boundary not 0;
    // ruguo bu canyu jieusna  buyaongshezhi
    // out put contral
    solv.currentTime += solv.dt;
    ++solv.istep;
    ointer.tcount += solv.dt;
    ++ointer.ncount;
    if (ointer.ninterval == 0) {
      if (ointer.tcount >= ointer.tinterval) {
        if (ointer.outfiletype == 1) {
          dynaplotoutput(outfilenum, solv.currentTime);
          fprintf(stderr, "time = %f  step = %d  ", solv.currentTime,
                  solv.istep);
          fprintf(stderr, "EngKinetic = %6.3e  Writing Paraview\n", sts.maxE);
          ++outfilenum;
          ointer.tcount = 0.0;
        } else if (ointer.outfiletype == 2) {
          dynatecpoutput(outfilenum, solv.currentTime, varlocation, varpositive,
                         varshare);
          fprintf(stderr, "time = %f  step = %d  ", solv.currentTime,
                  solv.istep);
          fprintf(stderr, "EngKinetic = %6.3e  Writing Tecplot \n", sts.maxE);
          ++outfilenum;
          ointer.tcount = 0.0;
        }
      }
    }

    statinter.tcount += solv.dt;
    ++statinter.ncount;
    if (statinter.ninterval == 0) {
      if (statinter.tinterval != 0.0) {
        if (statinter.tcount >= statinter.tinterval) {
          dynastatoutput(statfilenum, solv.currentTime);
          fprintf(stderr, "time = %f  step = %d  ", solv.currentTime,
                  solv.istep);
          fprintf(stderr, "EngKinetic = %6.3e  Writing Status\n", sts.maxE);
          ++statfilenum;
          statinter.tcount = 0.0;
        }
      }
    }

    hisointer.tcount += solv.dt;
    ++hisointer.ncount;
    if (hisointer.ninterval == 0) {
      if (hisointer.tcount >= hisointer.tinterval) {
        dynahisoutput();
        hisointer.tcount = 0.0;
      }
    }
    if (debugflg == 1) {
      if (solv.istep >= 1 && solv.istep <= 500) {
        dynaplotoutput(outfilenum, solv.currentTime);
        ++outfilenum;
      }
    }

    sts.maxE = 0.0;
    double totalinf, averageinf;
    totalinf = 0.;
    averageinf = 0.0;
    /*
    for(i = 0; i < numnodes; ++i)
    {
    Node *nd = nodes[i];
    //sts.maxE = dmax(sts.maxE ,nd->EngKinetic);
    sts.maxE = dmax(sts.maxE ,nd->ubfr);
    }*/

    for (i = 0; i < numnodes; ++i) {
      Node *nd = nodes[i];
      sts.maxE = dmax(sts.maxE, nd->ubfr);
    }

    sts.maxE = sts.maxE / sts.Fm;

    if (solv.istep >= 1000) {
      if (sts.staticflg == 1) {
        if (sts.maxE < sts.miniE) {
          sts.termsign = 1;
          dynastatoutput(statfilenum, solv.currentTime);
          fprintf(stderr, "time = %f  step = %d  ", solv.currentTime,
                  solv.istep);
          fprintf(stderr, "EngKinetic = %6.3e  Writing Status\n", sts.maxE);
          ++statfilenum;
          statinter.tcount = 0.0;
        }
      }
    }
    if (debugflg == 1) {
      fprintf(stderr, "time = %f  step = %d  ", solv.currentTime, solv.istep);
      fprintf(stderr, "EngKinetic = %6.3e \n", sts.maxE);
    }
    /*
for(i = 0; i <exactNumEle;++i)
  {
      deltattemp = deltat;
      Element *el = packedEset[i];
      el->EleTimeStep(nodes, deltat,solv.factor);
      deltat = dcp::min(deltattemp, deltat);
  }
  if(solv.dt == 0.){
      solv.dt = solv.factor*deltat;
  }else{
      solv.dt = dcp::max(solv.dt, solv.factor*deltat);
  }
    */
    //       fprintf(stderr,"step  = %d , time = %7.4e \n ", solv.istep,
    //       solv.currentTime);
  }
  // last step output
  if (ointer.outfiletype == 1) {
    dynaplotoutput(outfilenum, solv.currentTime);
    fprintf(stderr, "time = %f  step = %d  ", solv.currentTime, solv.istep);
    fprintf(stderr, "EngKinetic = %6.3e  Writing Paraview\n", sts.maxE);
  }
  ++outfilenum;
  dynahisoutput();
  if (ointer.outfiletype == 2) {
    dynatecpoutput(outfilenum, solv.currentTime, varlocation, varpositive,
                   varshare);
    fprintf(stderr, "time = %f  step = %d  ", solv.currentTime, solv.istep);
    fprintf(stderr, "EngKinetic = %6.3e  Writing Tecplot\n", sts.maxE);
    ++outfilenum;
    TECEND112();
  }
  fprintf(stderr, "End Solve\n");
}

void Domain::dynaplotoutput(int outfilenum, double ct) {
  FILE *rout;
  char *rofnamehead = "resplot";
  char *rofnamenum = new char[7];
  char *rofnametail = ".vtk";
  char *rofname = new char[128];
  sprintf(rofname, "%s%d%s", rofnamehead, outfilenum, rofnametail);
  rout = fopen(rofname, "w+");

  int i, j, k;
  // packelemdelete();
  // file head
  fprintf(rout, "# vtk DataFile Version 3.0\n");
  fprintf(rout, "t = %f\n", ct);
  fprintf(rout, "ASCII\n\n");

  fprintf(rout, "DATASET UNSTRUCTURED_GRID\n");
  fprintf(rout, "POINTS %d double\n", numnodes);
  for (i = 0; i < numnodes; ++i) {
    fprintf(rout, "%f\t%f\t%f\n", nodes[i]->x, nodes[i]->y, nodes[i]->z);
  }
  fprintf(rout, "\n");

  long datasize = 0;
  for (i = 0; i < exactNumEle; ++i) {
    datasize += packedEset[i]->numNodes();
    ++datasize;
  }
  fprintf(rout, "CELLS %d %d\n", exactNumEle, datasize);

  int nnodes;
  int *nnn = new int[32];
  for (i = 0; i < exactNumEle; ++i) {
    nnodes = packedEset[i]->numNodes();
    nnn = packedEset[i]->nodes(nnn);
    fprintf(rout, "%d\t", nnodes);
    for (j = 0; j < (nnodes - 1); ++j) {
      fprintf(rout, "%d\t", nnn[j]);
    }
    fprintf(rout, "%d\n", nnn[nnodes - 1]);
  }
  delete[] nnn;
  fprintf(rout, "\n");

  int outtype;
  fprintf(rout, "CELL_TYPES %d\n", exactNumEle);
  for (i = 0; i < exactNumEle; ++i) {
    outtype = packedEset[i]->getouttype();
    fprintf(rout, "%d\n", 12);
  }

  fprintf(rout, "\n");

  if (numnout != 0) {
    if (numnout != 0) fprintf(rout, "POINT_DATA %d\n", numnodes);
    fprintf(rout, "FIELD FieldData %d\n", numnout);
    for (i = 0; i < numnout; ++i) {
      if (nout[i] == 1) {
        fprintf(rout, "displacement 3 %d float\n", numnodes);
        for (j = 0; j < numnodes; ++j) {
          fprintf(rout, "%7.3e\t%7.3e\t%7.3e\n", nodes[j]->u[0], nodes[j]->u[1],
                  nodes[j]->u[2]);
        }
        fprintf(rout, "\n");
      }

      if (nout[i] == 2) {
        fprintf(rout, "interforce 3 %d float\n", numnodes);
        for (j = 0; j < numnodes; ++j) {
          fprintf(rout, "%7.3e\t%7.3e\t%7.3e\n", nodes[j]->interf[0],
                  nodes[j]->interf[1], nodes[j]->interf[2]);
        }
        fprintf(rout, "\n");
      }
      if (nout[i] == 3) {
        fprintf(rout, "volicity 3 %d float\n", numnodes);
        for (j = 0; j < numnodes; ++j) {
          fprintf(rout, "%7.3e\t%7.3e\t%7.3e\n", nodes[j]->v[0], nodes[j]->v[1],
                  nodes[j]->v[2]);
        }
        fprintf(rout, "\n");
      }
      if (nout[i] == 4) {
        fprintf(rout, "accerlater 3 %d float\n", numnodes);
        for (j = 0; j < numnodes; ++j) {
          fprintf(rout, "%7.3e\t%7.3e\t%7.3e\n", nodes[j]->a[0], nodes[j]->a[1],
                  nodes[j]->a[2]);
        }
        fprintf(rout, "\n");
      }
      if (nout[i] == 5) {
        fprintf(rout, "extf 3 %d float\n", numnodes);
        for (j = 0; j < numnodes; ++j) {
          fprintf(rout, "%7.3e\t%7.3e\t%7.3e\n", nodes[j]->extf[0],
                  nodes[j]->extf[1], nodes[j]->extf[2]);
        }
        fprintf(rout, "\n");
      }
    }
  }
  if (numeout != 0) {
    fprintf(rout, "CELL_DATA %d\n", exactNumEle);
    fprintf(rout, "FIELD FieldData %d\n", numeout + 2);

    double *stress = new double[6];
    double *strain = new double[6];
    double *prinstre = new double[9];
    double *stredir = new double[9];
    double *hisv = new double[27];
    double plas;
    double mises, dpval;

    fprintf(rout, "Plas 1 %d float\n", exactNumEle);
    for (j = 0; j < exactNumEle; ++j) {
      plas = packedEset[j]->plas;
      //      plas = packedEset[j]->elfail;
      fprintf(rout, "%7.3e\n", plas);
    }

    fprintf(rout, "\n");

    fprintf(rout, "ID 1 %d float\n", exactNumEle);
    for (j = 0; j < exactNumEle; ++j) {
      plas = packedEset[j]->elemnum;
      fprintf(rout, "%7.3e\n", plas);
    }

    fprintf(rout, "\n");
    for (i = 0; i < numeout; ++i) {
      if (eout[i] == 1) {
        fprintf(rout, "stress 6 %d float\n", exactNumEle);
        for (j = 0; j < exactNumEle; ++j) {
          stress = packedEset[j]->getoutstress(stress);
          for (k = 0; k < 5; ++k) {
            fprintf(rout, "%7.3e\t", stress[k]);
          }
          fprintf(rout, "%7.3e\n", stress[5]);
        }
        fprintf(rout, "\n");
      }
      if (eout[i] == 2) {
        fprintf(rout, "strain 6 %d float\n", exactNumEle);
        for (j = 0; j < exactNumEle; ++j) {
          strain = packedEset[j]->getoutstrain(strain);
          for (k = 0; k < 5; ++k) {
            fprintf(rout, "%7.3e\t", strain[k]);
          }
          fprintf(rout, "%7.3e\n", strain[5]);
        }
        fprintf(rout, "\n");
      }
      if (eout[i] == 3) {
        fprintf(rout, "history 16 %d float\n", exactNumEle);
        for (j = 0; j < exactNumEle; ++j) {
          hisv = packedEset[j]->getouthis(hisv);
          for (k = 0; k < 15; ++k) {
            fprintf(rout, "%7.3e\t", hisv[k]);
          }
          fprintf(rout, "%7.3e\n", hisv[5]);
        }
        fprintf(rout, "\n");
      }
      if (eout[i] == 4) {
        fprintf(rout, "prinstress 3 %d float\n", exactNumEle);
        for (j = 0; j < exactNumEle; ++j) {
          stress = packedEset[j]->getoutstress(stress);
          princ_stress(stress, stredir, prinstre);
          // jaco_(stress,prinstre,stredir);
          for (k = 0; k < 2; ++k) {
            fprintf(rout, "%7.3e\t", prinstre[k]);
          }
          fprintf(rout, "%7.3e\n", prinstre[2]);
        }
        fprintf(rout, "\n");
      }
      if (eout[i] == 5) {
        fprintf(rout, "mises 1 %d float\n", exactNumEle);
        for (j = 0; j < exactNumEle; ++j) {
          stress = packedEset[j]->getoutstress(stress);
          dpval = (stress[0] + stress[1] + stress[2]) / 3.;
          stress[0] = stress[0] - dpval;
          stress[1] = stress[1] - dpval;
          stress[2] = stress[2] - dpval;
          mises =
              sqrt(1. / 2. *
                   (stress[0] * stress[0] + stress[1] * stress[1] +
                    stress[2] * stress[2] + 2. * stress[3] * stress[3] +
                    2. * stress[4] * stress[4] + 2. * stress[5] * stress[5]));
          // jaco_(stress,prinstre,stredir);

          fprintf(rout, "%7.3e\n", mises);
        }
        fprintf(rout, "\n");
      }
      double *dcenter = new double[3];
      if (eout[i] == 6) {
        fprintf(rout, "center 3 %d float\n", exactNumEle);
        for (j = 0; j < exactNumEle; ++j) {
          dcenter = packedEset[j]->getlocal(nodes);
          for (k = 0; k < 2; ++k) {
            fprintf(rout, "%7.3e\t", dcenter[k]);
          }
          fprintf(rout, "%7.3e\n", dcenter[2]);
        }

        fprintf(rout, "\n");
      }
    }
  }

  fclose(rout);
  ++outfilenum;
}

void Domain::dynahisoutput() {
  FILE *heout;
  FILE *hnout;
  char *rofnamehead = "ehisoutput";
  char *rofnamenum = new char[7];
  char *rofnametail = ".csv";
  char *rofname = new char[128];
  char *rofname1 = new char[128];
  sprintf(rofname, "%s%s", rofnamehead, rofnametail);

  char *rofnamehead1 = "nhisoutput";
  sprintf(rofname1, "%s%s", rofnamehead1, rofnametail);

  hnout = fopen(rofname1, "a+");

  heout = fopen(rofname, "a+");

  int i, j, k;

  double *stress = new double[6];
  double *strain = new double[6];
  double *prinstre = new double[9];
  double *stredir = new double[9];
  double *ccenter = new double[3];
  double *history = new double[27];
  Element *el;
  int ne;
  int plas;
  if (hiselemnum == 0) {
    stress = eset[0]->getoutstress(stress);
    strain = eset[0]->getoutstrain(strain);
    fprintf(heout, "%e,", solv.currentTime);
    for (i = 0; i < 3; ++i) {
      fprintf(heout, "%e,", stress[i]);
    }
    for (i = 0; i < 3; ++i) {
      fprintf(heout, "%e,", strain[i]);
    }
    plas = eset[0]->plas;
    fprintf(heout, "%x \n", plas);

  } else {
    /*
    fprintf(heout,"-------------------%f-----------------\n",solv.currentTime);
    for(i =0 ;i <hiselemnum; ++i){
        //el = eset.getelem(hiseout[i]);
        el = packedEset[hiseout[i]-1];
        ccenter = el->getlocal(nodes);
            stress = el->getoutstress(stress);
            // strain = el->getoutstrain(strain);
            fprintf(heout,"%d,",el->elemnum);
            for(j=0;j < 3; ++j){
                fprintf(heout,"%e,",ccenter[j]);
            }
            for(j = 0; j< 6;++j){
                fprintf(heout,"%e,",stress[j]);}
            //          for(i = 0; i< 6;++i){
            //    fprintf(heout,"%e,",strain[i]);
            //}
fprintf(heout,"\n");
            // jaco_(stress,prinstre,stredir);
//        princ_stress(stress, prinstre,   stredir );
//             for(k = 0; k < 3; ++k){
//                fprintf(heout,"%7.3e\t", prinstre[k]);
//            }

    }     */
    // fprintf(heout,"-------------------%f-----------------\n",solv.currentTime);
    for (i = 0; i < 1; ++i) {
      // el = eset.getelem(hiseout[i]);
      double pval, mises;
      el = packedEset.getelem(hiseout[i]);  //[hiseout[i]-1];
      ccenter = el->getlocal(nodes);
      stress = el->getoutstress(stress);
      // strain = el->getoutstrain(strain);
      fprintf(heout, "%e,%d,", solv.currentTime, el->elemnum);
      for (j = 0; j < 3; ++j) {
        fprintf(heout, "%e,", ccenter[j]);
      }
      for (j = 0; j < 6; ++j) {
        fprintf(heout, "%e,", stress[j]);
      }
      pval = (stress[0] + stress[1] + stress[2]) / 3.;
      stress[0] = stress[0] - pval;
      stress[1] = stress[1] - pval;
      stress[2] = stress[2] - pval;

      fprintf(heout, "%e,", pval);

      fprintf(heout, "%e,",
              sqrt(1. / 2. *
                   (stress[0] * stress[0] + stress[1] * stress[1] +
                    stress[2] * stress[2] + 2. * stress[3] * stress[3] +
                    2. * stress[4] * stress[4] + 2. * stress[5] * stress[5])));
      fprintf(heout, "%d,", el->plas);
      history = el->getouthis(history);
      fprintf(heout, "%e,", history[6]);
      fprintf(heout, "%e,", history[7]);
      fprintf(heout, "%e,", history[8]);
      fprintf(heout, "%e,", history[9]);
      //          for(i = 0; i< 6;++i){
      //    fprintf(heout,"%e,",strain[i]);
      //}
      fprintf(heout, "\n");
      // jaco_(stress,prinstre,stredir);
      //        princ_stress(stress, prinstre,   stredir );
      //             for(k = 0; k < 3; ++k){
      //                fprintf(heout,"%7.3e\t", prinstre[k]);
      //            }
    }
  }
  Node nd;
  int nn;
  if (hisnodenum == 0) {
    nd = nodes.getNode(1);
    fprintf(hnout, "%e,", solv.currentTime);
    fprintf(hnout, "1   ,");
    for (i = 0; i < 3; ++i) {
      fprintf(hnout, "%e,", nd.u[i]);
    }
    fprintf(hnout, "\n");
  } else {
    for (i = 0; i < hisnodenum; ++i) {
      nn = hisnout[i];
      nd = nodes.getNode(nn);
      fprintf(hnout, "%e,", solv.currentTime);
      fprintf(hnout, "%d ,", nn);
      for (j = 0; j < 3; ++j) {
        fprintf(hnout, "%e,", nd.u[j]);
      }
      for (j = 0; j < 3; ++j) {
        fprintf(hnout, "%e,", nd.v[j]);
      }
      for (j = 0; j < 3; ++j) {
        fprintf(hnout, "%e,", nd.a[j]);
      }
      fprintf(hnout, "%e\n", nd.x - nd.u[0]);
    }
  }

  fclose(heout);
  fclose(hnout);

  FILE *hisout;
  char *rof = "hisv27.csv";
  hisout = fopen(rof, "a+");

  double *hisv = new double[21];
  hisv = eset[0]->getouthis(hisv);
  fprintf(hisout, "%e,", solv.currentTime);
  for (i = 0; i < 20; ++i) {
    fprintf(hisout, "%e,", hisv[i]);
  }
  fprintf(hisout, "%e\n", hisv[19]);

  fclose(hisout);
}

int Domain::dynastatoutput(int outfilenum, double ct) {
  FILE *sout;
  char *sfnamehead = "statfile";
  char *sfnamenum = new char[7];
  char *sfnametail = ".sta";
  char *sfname = new char[128];
  sprintf(sfname, "%s%d%s", sfnamehead, outfilenum, sfnametail);
  sout = fopen(sfname, "wb+");

  int i, j, k;
  // output input file path
  fwrite(finfo.infpath, sizeof(char), sizeof(finfo.infpath), sout);
  // output time and data

  time_t timep;
  //    char *td;
  time(&timep);
  //    td = asctime(gmtime(&timep));
  time_t *tp;
  tp = &timep;
  fwrite(tp, sizeof(time_t), 1, sout);

  // output stat file version
  fwrite(ver.statversion, sizeof(char), 5, sout);
  // output computation time
  double *comput = &ct;
  fwrite(comput, sizeof(double), 1, sout);

  // output nodal number

  int *ntemp = new int[49];
  double *dtemp = new double[49];

  ntemp[0] = restartflg;
  fwrite(ntemp, sizeof(int), 1, sout);
  ntemp[0] = numnodes;
  fwrite(ntemp, sizeof(int), 1, sout);
  ntemp[0] = numele;
  fwrite(ntemp, sizeof(int), 1, sout);

  ntemp[0] = sinfo.probType;
  // fprintf(stderr, "type = %d \n ", ntemp[0]);
  fwrite(ntemp, sizeof(int), 1, sout);

  ntemp[0] = sinfo.timestepflg;
  fwrite(ntemp, sizeof(int), 1, sout);

  dtemp[0] = solv.inidt;
  fwrite(dtemp, sizeof(double), 1, sout);

  dtemp[0] = solv.dt;
  fwrite(dtemp, sizeof(double), 1, sout);

  dtemp[0] = solv.tmax;
  fwrite(dtemp, sizeof(double), 1, sout);

  dtemp[0] = solv.factor;
  fwrite(dtemp, sizeof(double), 1, sout);

  ntemp[0] = numhis;
  fwrite(ntemp, sizeof(int), 1, sout);

  ntemp[0] = jaumannflg;
  fwrite(ntemp, sizeof(int), 1, sout);

  ntemp[0] = hourglassflg;
  fwrite(ntemp, sizeof(int), 1, sout);

  dtemp[0] = hourglasspara;
  fwrite(dtemp, sizeof(double), 1, sout);

  for (i = 0; i < 3; ++i) {
    dtemp[i] = gravity[i];
  }
  fwrite(dtemp, sizeof(double), 3, sout);

  ntemp[0] = ointer.outfiletype;
  ntemp[1] = ointer.ninterval;
  fwrite(ntemp, sizeof(int), 2, sout);

  dtemp[0] = ointer.tinterval;
  fwrite(dtemp, sizeof(double), 1, sout);

  // out put output type
  ntemp[0] = numnout;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < numnout; ++i) {
    ntemp[i] = nout[i];
  }
  fwrite(ntemp, sizeof(int), numnout, sout);

  ntemp[0] = numeout;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < numeout; ++i) {
    ntemp[i] = eout[i];
  }
  fwrite(ntemp, sizeof(int), numeout, sout);

  dtemp[0] = hisointer.tinterval;
  fwrite(dtemp, sizeof(double), 1, sout);

  ntemp[0] = hisointer.ninterval;
  fwrite(ntemp, sizeof(int), 1, sout);

  ntemp[0] = hisnodenum;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < hisnodenum; ++i) {
    ntemp[i] = hisnout[i];
  }
  fwrite(ntemp, sizeof(int), hisnodenum, sout);

  ntemp[0] = hiselemnum;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < hiselemnum; ++i) {
    ntemp[i] = hiseout[i];
  }
  fwrite(ntemp, sizeof(int), hiselemnum, sout);

  // out put material
  ntemp[0] = nummat;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < nummat; ++i) {
    StructProp *pr;
    pr = mset[i];
    ntemp[0] = pr->matnum;
    ntemp[1] = pr->gettype();
    ntemp[2] = pr->getnprops();
    fwrite(ntemp, sizeof(int), 3, sout);
    dtemp = pr->getprops(dtemp);
    fwrite(dtemp, sizeof(double), ntemp[2], sout);
  }

  // out put Cset
  ntemp[0] = numcu;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < numcu; ++i) {
    CurveList *cp;
    cp = cset[i];
    ntemp[0] = cp->curvenum;
    ntemp[1] = cp->curvelength;
    //        ntemp[2] = cp->derflg;
    fwrite(ntemp, sizeof(int), 2, sout);
    for (j = 0; j < ntemp[1]; ++j) {
      dtemp[0] = cp->curvevalue[j].coef1;
      dtemp[1] = cp->curvevalue[j].coef2;
      fwrite(dtemp, sizeof(double), 2, sout);
    }
  }

  for (i = 0; i < numcu; ++i) {
    CurveList *cp;
    cp = cset[i];
    ntemp[0] = cp->derflg;
    fwrite(ntemp, sizeof(int), 1, sout);
  }

  // out put pressure
  ntemp[0] = numpress;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < numpress; ++i) {
    ntemp[0] = pres[i].cnum;

    fwrite(ntemp, sizeof(int), 1, sout);

    dtemp[0] = pres[i].value;
    fwrite(dtemp, sizeof(double), 1, sout);
    ntemp[0] = pres[i].nodelist[0];
    ntemp[1] = pres[i].nodelist[1];
    ntemp[2] = pres[i].nodelist[2];
    ntemp[3] = pres[i].nodelist[3];
    fwrite(ntemp, sizeof(int), 4, sout);
  }
  // out put data block

  // output node date

  for (i = 0; i < numnodes; ++i) {
    Node *nd;
    nd = nodes[i];
    // node coor
    ntemp[0] = nd->nodenum;
    dtemp[0] = nd->x;
    dtemp[1] = nd->y;
    dtemp[2] = nd->z;
    fwrite(ntemp, sizeof(int), 1, sout);
    fwrite(dtemp, sizeof(double), 3, sout);
  }
  for (i = 0; i < numnodes; ++i) {
    Node *nd;
    nd = nodes[i];
    // node coor
    for (j = 0; j < 3; ++j) {
      dtemp[j] = nd->disdef[j];
    }
    fwrite(dtemp, sizeof(double), 3, sout);

    for (j = 0; j < 3; ++j) {
      dtemp[j] = nd->u[j];
    }
    fwrite(dtemp, sizeof(double), 3, sout);

    for (j = 0; j < 3; ++j) {
      dtemp[j] = nd->v[j];
    }
    fwrite(dtemp, sizeof(double), 3, sout);

    for (j = 0; j < 3; ++j) {
      dtemp[j] = nd->a[j];
    }
    fwrite(dtemp, sizeof(double), 3, sout);

    for (j = 0; j < 3; ++j) {
      dtemp[j] = nd->interf[j];
    }
    fwrite(dtemp, sizeof(double), 3, sout);

    for (j = 0; j < 3; ++j) {
      dtemp[j] = nd->extf[j];
    }
    fwrite(dtemp, sizeof(double), 3, sout);

    dtemp[0] = nd->mass;
    fwrite(dtemp, sizeof(double), 1, sout);

    ntemp[0] = nd->fixed;
    fwrite(ntemp, sizeof(int), 1, sout);

    for (j = 0; j < 3; ++j) {
      ntemp[j] = nd->defined[j];
    }
    fwrite(ntemp, sizeof(int), 3, sout);

    for (j = 0; j < 3; ++j) {
      ntemp[j] = nd->cun[j];
    }
    fwrite(ntemp, sizeof(int), 3, sout);

    for (j = 0; j < 3; ++j) {
      ntemp[j] = nd->cfn[j];
    }
    fwrite(ntemp, sizeof(int), 3, sout);
  }

  // output elemenet data

  for (i = 0; i < numele; ++i) {
    Element *el = eset[i];
    if (el == 0) {
      fprintf(stderr, "\n *** WARNING: Element was not existent element %d\n",
              i);
      continue;
    }
    el->rerenum(nodes);
  }

  for (i = 0; i < numele; ++i) {
    Element *el;
    el = eset[i];
    ntemp[0] = el->elemnum;
    ntemp[1] = el->GetEleType();
    fwrite(ntemp, sizeof(int), 2, sout);

    int en;
    en = el->numNodes();
    for (j = 0; j < en; ++j) {
      ntemp = el->nodes(ntemp);
    }
    fwrite(ntemp, sizeof(int), en, sout);
  }
  for (i = 0; i < numele; ++i) {
    Element *el = eset[i];
    if (el == 0) {
      fprintf(stderr, "\n *** WARNING: Element was not existent element %d\n",
              i);
      continue;
    }
    el->renum(nodes);
  }

  for (i = 0; i < numele; ++i) {
    Element *el;
    el = eset[i];
    int ndim = el->getDimNumber();

    dtemp = el->getoutstrain(dtemp);

    if (ndim == 3) {
      fwrite(dtemp, sizeof(double), 6, sout);
    } else {
      fwrite(dtemp, sizeof(double), 4, sout);
    }

    dtemp = el->getoutstress(dtemp);

    if (ndim == 3) {
      fwrite(dtemp, sizeof(double), 6, sout);
    } else {
      fwrite(dtemp, sizeof(double), 4, sout);
    }

    dtemp = el->getouthis(dtemp);
    fwrite(dtemp, sizeof(double), numhis, sout);
  }
  ntemp[0] = numatt;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < numatt; ++i) {
    ntemp[0] = attrib[i].elemnum;
    ntemp[1] = attrib[i].matnum;
    fwrite(ntemp, sizeof(int), 2, sout);
  }

  ntemp[0] = numpatt;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < numpatt; ++i) {
    ntemp[0] = pattrib[i].elemnum;
    ntemp[1] = pattrib[i].matnum;
    fwrite(ntemp, sizeof(int), 2, sout);
  }

  // write part
  ntemp[0] = numpart;
  fwrite(ntemp, sizeof(int), 1, sout);

  for (i = 0; i < numpart; ++i) {
    Part *pt = pset[i];
    ntemp[0] = pt->length;
    ntemp[1] = pt->partnum;
    ntemp[2] = pt->parttype;
    fwrite(ntemp, sizeof(int), 3, sout);
    for (j = 0; j < pt->length; ++j) {
      ntemp[0] = pt->vect[j];
      fwrite(ntemp, sizeof(int), 1, sout);
    }
  }

  // output
  fclose(sout);

  return 0;
}

int Domain::ResetNData(double *dt, int *nt, int n) {
  int i, j;
  Node *nd = nodes[n];

  for (j = 0; j < 3; ++j) {
    nd->disdef[j] = dt[j];
    nd->u[j] = dt[j + 3];
    nd->v[j] = dt[j + 6];
    nd->a[j] = dt[j + 9];
    nd->interf[j] = dt[j + 12];
    nd->extf[j] = dt[j + 15];
  }
  nd->mass = dt[18];
  nd->fixed = nt[0];
  for (j = 0; j < 3; ++j) {
    nd->defined[j] = nt[j + 1];
    nd->cun[j] = nt[j + 4];
    nd->cfn[j] = nt[j + 7];
  }
  return 0;
}

int Domain::ResetEData(double *dt, int hn, int en) {
  int i, j;
  Element *el = eset[en];
  if (el == 0) {
    fprintf(stderr, "\n *** WARNING: Element was not existent element %d\n", i);
  }
  el->ResetData(dt, hn);
  return 0;
}

int Domain::delelem(int en) {
  Element *el;
  el = eset.getelem(en);

  el->eldel = 0;
  return 0;
}

int Domain::delpart(int pn) {
  int i;
  Element *el;
  Part *pt;
  pt = pset.getpart(pn);
  for (i = 0; i < pt->length; ++i) {
    el = eset.getelem(pt->vect[i]);
    el->eldel = 0;
  }

  return 0;
}

int Domain::initmass() {
  int i, j;
  for (i = 0; i < numnodes; ++i) {
    nodes[i]->mass = 0;
    /*
    for(j = 0; j < 3; ++j){
        nodes[i]->interf[j] =0;
        }*/
  }
  return 0;
}

int Domain::userdel() {
  int i;
  for (i = 0; i < numele; ++i) {
    Element *el = eset[i];
  }
  return 0;
}

int Domain::setbulkvisco(double q1, double q2) {
  bv->bvflg = 1;
  bv->q1 = q1;
  bv->q2 = q2;
  return 0;
}

int Domain::setdamping(int type, double para) {
  if (type == 1) {
    damp.dampingtype = type;
    damp.local = para;
  }

  if (type == 2) {
    damp.dampingtype = type;
    damp.combined = para;
  }
  return 0;
}

int Domain::staticterm() { sts.staticflg = 1; }

int Domain::staticterm(double flg) {
  sts.staticflg = 1;
  sts.miniE = flg;
}

int Domain::TECPLOT_VNN(int &num, char *name) {
  int i, j;
  num = 3;
  sprintf(name, "X Y Z");
  num += 1;
  sprintf(name, "%s PLAS", name);
  for (i = 0; i < numnout; ++i) {
    switch (nout[i]) {
      case 1:
        num += 4;
        sprintf(name, "%s DISP XDISP YDISP ZDISP", name);

        break;
      case 2:
        num += 3;
        sprintf(name, "%s XINTF YINTF ZINTF", name);
        break;
      case 3:
        num += 3;
        sprintf(name, "%s XVol YVol ZVol", name);
        break;
      case 4:
        num += 3;
        sprintf(name, "%s XAcc YAcc ZAcc", name);
        break;
      case 5:
        num += 3;
        sprintf(name, "%s XEXTF YEXTF ZEXTF", name);
    }
  }

  for (i = 0; i < numeout; ++i) {
    switch (eout[i]) {
      case 1:
        num += 6;
        sprintf(name, "%s XSTRESS YSTRESS ZSTRESS XYSTRESS YZSTRESS XZSTRESS",
                name);
        break;
      case 2:
        num += 6;
        sprintf(name, "%s XSTRAIN YSTRAIN ZSTRAIN XYSTRAIN YZSTRAIN XZSTRAIN",
                name);
        break;
      case 3:
        num += 16;
        sprintf(name,
                "%s HISTORY1 HISTORY2 HISTORY3 HISTORY4 HISTORY5 HISTORY6 "
                "HISTORY7 HISTORY8 HISTORY9 HISTORY10 HISTORY11 HISTORY12 "
                "HISTORY13 HISTORY14 HISTORY15 HISTORY16",
                name);
        break;
      case 4:
        num += 3;
        sprintf(name, "%s MAXPSTRE MIDPSTRE MINPSTRE", name);
        break;
      case 5:
        num += 1;
        sprintf(name, "%s MISES", name);
        break;
      case 6:
        num += 3;
        sprintf(name, "%s Xcenter Ycenter Zcenter", name);
        break;
    }
  }
}

int Domain::TECPLOT_VL(int *varl) {
  int i, j, k;
  j = 0;
  for (i = 0; i < 3; ++i) {
    varl[i] = 1;
  }
  j = j + 3;
  varl[j] = 0;
  j = j + 1;
  for (i = 0; i < numnout; ++i) {
    if (nout[i] == 1) {
      for (k = 0; k < 4; ++k) {
        varl[j + k] = 1;
      }
      j += 4;
    }
    if (nout[i] == 2) {
      for (k = 0; k < 3; ++k) {
        varl[j + k] = 1;
      }
      j += 3;
    }
    if (nout[i] == 3) {
      for (k = 0; k < 3; ++k) {
        varl[j + k] = 1;
      }
      j += 3;
    }
    if (nout[i] == 4) {
      for (k = 0; k < 3; ++k) {
        varl[j + k] = 1;
      }
      j += 3;
    }
    if (nout[i] == 5) {
      for (k = 0; k < 3; ++k) {
        varl[j + k] = 1;
      }
      j += 3;
    }
  }

  for (i = 0; i < numeout; ++i) {
    if (eout[i] == 1) {
      for (k = 0; k < 6; ++k) {
        varl[j + k] = 0;
      }
      j += 6;
    }
    if (eout[i] == 2) {
      for (k = 0; k < 6; ++k) {
        varl[j + k] = 0;
      }
      j += 6;
    }
    if (eout[i] == 3) {
      for (k = 0; k < 16; ++k) {
        varl[j + k] = 0;
      }
      j += 16;
    }
    if (eout[i] == 4) {
      for (k = 0; k < 3; ++k) {
        varl[j + k] = 0;
      }
      j += 3;
    }
    if (eout[i] == 5) {
      for (k = 0; k < 1; ++k) {
        varl[j + k] = 0;
      }
      j += 1;
    }
    if (eout[i] == 6) {
      for (k = 0; k < 3; ++k) {
        varl[j + k] = 0;
      }
      j += 3;
    }
  }
}

int Domain::dynatecpoutput(int onum, double ct, int *vl, int *pf, int *shv) {
  INTEGER4 Debug, I, J, K, L, II, III, NPts, NElm, DIsDouble, VIsDouble, IMax,
      JMax, KMax;
  INTEGER4 ICellMax, JCellMax, KCellMax, ZoneType, Clipping;
  INTEGER4 IsBlock, NumFaceConnections, FaceNeighborMode,
      ShareConnectivityFromZone;
  INTEGER4 NM[12][4];
  double XP, YP, ZP, FH, LineSpacing, PatternLength;
  double SolutionTime;
  double BoxMargin, BoxLineThickness, TextAngle;
  INTEGER4 AttachToZone, Zone, Scope, PositionCoordSys, FontType, HeightUnits;
  INTEGER4 IsFilled, GeomType, LinePattern, NumEllipsePts;
  INTEGER4 Anchor, BoxType, BoxColor, BoxFillColor, TextColor, Color, FillColor;
  INTEGER4 ArrowheadStyle, ArrowheadAttachment, NumSegments, NumSegPts[1];
  double LineThickness, ArrowheadSize, ArrowheadAngle;
  float XGeomData[1], YGeomData[1], ZGeomData[1];
  INTEGER4 StrandID, ParentZone, TotalNumFaceNodes, NumConnectedBoundaryFaces,
      TotalNumBoundaryConnections;
  // packelemdelete();
  ZoneType = 5;
  IMax = numnodes;
  JMax = exactNumEle;
  KMax = 0;
  ICellMax = 0;
  JCellMax = 0;
  KCellMax = 0;
  SolutionTime = ct;
  StrandID = 1;
  ParentZone = 0;
  IsBlock = 1;
  NumFaceConnections = 0;
  FaceNeighborMode = 0;
  TotalNumFaceNodes = 0;
  NumConnectedBoundaryFaces = 0;
  TotalNumBoundaryConnections = 0;
  INTEGER4 PassiveVarList = 0;
  //  ValueLocation = 0;
  INTEGER4 ShareVarFromZone = 0;
  ShareConnectivityFromZone = 0;
  DIsDouble = 1;
  VIsDouble = 1;

  I = TECZNE112((char *)"DCP Zone", &ZoneType, &IMax, &JMax, &KMax, &ICellMax,
                &JCellMax, &KCellMax, &SolutionTime, &StrandID, &ParentZone,
                &IsBlock, &NumFaceConnections, &FaceNeighborMode,
                &TotalNumFaceNodes, &NumConnectedBoundaryFaces,
                &TotalNumBoundaryConnections, (INTEGER4 *)pf, (INTEGER4 *)vl,
                (INTEGER4 *)shv, &ShareConnectivityFromZone);
  int i, j, k;
  double x, y, z;
  II = numnodes * 3;
  III = numele;
  double *nodtemp;
  double *eletemp;
  int *eleitemp;

  nodtemp = new double[3 * numnodes];
  eletemp = new double[6 * numele];
  //  eleitemp = new int[numele];

  for (j = 0; j < numnodes; ++j) {
    nodtemp[j] = nodes[j]->x;
    nodtemp[j + numnodes] = nodes[j]->y;
    nodtemp[j + 2 * numnodes] = nodes[j]->z;
  }

  I = TECDAT112(&II, &nodtemp[0], &DIsDouble);

  //            int iplas;
  delete eletemp;
  eletemp = new double[exactNumEle];
  for (k = 0; k < exactNumEle; ++k) {
    //                iplas = packedEset[k]->plas;
    eletemp[k] = packedEset[k]->plas;
    // eletemp[k] = packedEset[k]->elfail;
  }
  II = exactNumEle;
  I = TECDAT112(&II, &eletemp[0], &DIsDouble);

  for (i = 0; i < numnout; ++i) {
    switch (nout[i]) {
      case 1:
        delete[] nodtemp;
        nodtemp = new double[4 * numnodes];
        for (k = 0; k < numnodes; ++k) {
          x = nodes[k]->u[0];
          y = nodes[k]->u[1];
          z = nodes[k]->u[2];
          nodtemp[k] = sqrt(x * x + y * y + z * z);
          nodtemp[numnodes + k] = x;
          nodtemp[2 * numnodes + k] = y;
          nodtemp[3 * numnodes + k] = z;
        }
        II = numnodes * 4;
        I = TECDAT112(&II, &nodtemp[0], &DIsDouble);
        break;
      case 2:
        delete[] nodtemp;
        nodtemp = new double[3 * numnodes];
        for (k = 0; k < numnodes; ++k) {
          nodtemp[k] = nodes[k]->interf[0];
          nodtemp[1 * numnodes + k] = nodes[k]->interf[1];
          nodtemp[2 * numnodes + k] = nodes[k]->interf[2];
        }
        II = numnodes * 3;
        I = TECDAT112(&II, &nodtemp[0], &DIsDouble);
        break;
      case 3:
        delete[] nodtemp;
        nodtemp = new double[3 * numnodes];
        for (k = 0; k < numnodes; ++k) {
          nodtemp[k] = nodes[k]->v[0];
          nodtemp[1 * numnodes + k] = nodes[k]->v[1];
          nodtemp[2 * numnodes + k] = nodes[k]->v[2];
        }
        II = numnodes * 3;
        I = TECDAT112(&II, &nodtemp[0], &DIsDouble);
        break;
      case 4:
        delete[] nodtemp;
        nodtemp = new double[3 * numnodes];
        for (k = 0; k < numnodes; ++k) {
          nodtemp[k] = nodes[k]->a[0];
          nodtemp[1 * numnodes + k] = nodes[k]->a[1];
          nodtemp[2 * numnodes + k] = nodes[k]->a[2];
        }
        II = numnodes * 3;
        I = TECDAT112(&II, &nodtemp[0], &DIsDouble);
        break;
      case 5:
        delete[] nodtemp;
        nodtemp = new double[3 * numnodes];
        for (k = 0; k < numnodes; ++k) {
          nodtemp[k] = nodes[k]->extf[0];
          nodtemp[1 * numnodes + k] = nodes[k]->extf[1];
          nodtemp[2 * numnodes + k] = nodes[k]->extf[2];
        }
        II = numnodes * 3;
        I = TECDAT112(&II, &nodtemp[0], &DIsDouble);
        break;
    }
  }
  double *stress = new double[6];
  double *strain = new double[6];
  double *hisv = new double[27];
  double *prinstre = new double[3];
  double *stredir = new double[9];
  double *ccenter = new double[3];
  double dpval;
  for (i = 0; i < numeout; ++i) {
    switch (eout[i]) {
      case 1:
        delete[] eletemp;
        eletemp = new double[6 * exactNumEle];
        for (k = 0; k < exactNumEle; ++k) {
          stress = packedEset[k]->getoutstress(stress);
          for (j = 0; j < 6; ++j) eletemp[j * exactNumEle + k] = stress[j];
        }
        II = exactNumEle * 6;
        I = TECDAT112(&II, &eletemp[0], &DIsDouble);
        break;
      case 2:
        delete[] eletemp;
        eletemp = new double[6 * exactNumEle];
        for (k = 0; k < exactNumEle; ++k) {
          stress = packedEset[k]->getoutstrain(strain);
          for (j = 0; j < 6; ++j) eletemp[j * exactNumEle + k] = strain[j];
        }
        II = exactNumEle * 6;
        I = TECDAT112(&II, &eletemp[0], &DIsDouble);
        break;
      case 3:
        delete[] eletemp;
        eletemp = new double[16 * exactNumEle];
        for (k = 0; k < exactNumEle; ++k) {
          hisv = packedEset[k]->getouthis(hisv);
          for (j = 0; j < 16; ++j) eletemp[j * exactNumEle + k] = hisv[j];
        }
        II = exactNumEle * 16;
        I = TECDAT112(&II, &eletemp[0], &DIsDouble);
        break;
      case 4:
        delete[] eletemp;
        eletemp = new double[3 * exactNumEle];
        for (k = 0; k < exactNumEle; ++k) {
          stress = packedEset[k]->getoutstress(stress);
          princ_stress(stress, stredir, prinstre);
          for (j = 0; j < 3; ++j) eletemp[j * exactNumEle + k] = prinstre[j];
        }
        II = exactNumEle * 3;
        I = TECDAT112(&II, &eletemp[0], &DIsDouble);
        break;
      case 5:
        delete[] eletemp;
        eletemp = new double[3 * exactNumEle];
        for (k = 0; k < exactNumEle; ++k) {
          stress = packedEset[k]->getoutstress(stress);
          dpval = (stress[0] + stress[1] + stress[2]) / 3.;
          stress[0] = stress[0] - dpval;
          stress[1] = stress[1] - dpval;
          stress[2] = stress[2] - dpval;
          eletemp[k] =
              sqrt(1. / 2. *
                   (stress[0] * stress[0] + stress[1] * stress[1] +
                    stress[2] * stress[2] + 2. * stress[3] * stress[3] +
                    2. * stress[4] * stress[4] + 2. * stress[5] * stress[5]));
        }
        II = exactNumEle;
        I = TECDAT112(&II, &eletemp[0], &DIsDouble);
        break;
      case 6:
        delete[] eletemp;
        eletemp = new double[3 * exactNumEle];
        for (k = 0; k < exactNumEle; ++k) {
          ccenter = packedEset[k]->getlocal(nodes);
          for (j = 0; j < 3; ++j) eletemp[j * exactNumEle + k] = ccenter[j];
        }
        II = exactNumEle * 3;
        I = TECDAT112(&II, &eletemp[0], &DIsDouble);
        break;
    }
  }

  int *connectlist;
  int *nnn = new int[32];
  II = 8 * exactNumEle;
  connectlist = new int[II];
  for (i = 0; i < exactNumEle; ++i) {
    nnn = packedEset[i]->nodes(nnn);

    for (j = 0; j < 8; ++j) {
      connectlist[j + i * 8] = nnn[j] + 1;
    }
  }
  I = TECNOD112(connectlist);

  return 0;
}

int Domain::exportflac() {
  FILE *flacout;
  char *rofnamehead = "MODEL";
  char *rofnamenum = new char[7];
  char *rofnametail = ".Flac3D";
  char *rofname = new char[128];
  sprintf(rofname, "%s%s", rofnamehead, rofnametail);
  flacout = fopen(rofname, "w+");

  int i, j, k;
  // file head
  fprintf(flacout, "* FLAC3D grid produced by FLAC3D\n");
  fprintf(flacout, "* GRIDPOINTS\n");

  for (i = 0; i < numnodes; ++i) {
    fprintf(flacout, "G %d  %f  %f  %f\n", nodes[i]->nodenum, nodes[i]->x,
            nodes[i]->y, nodes[i]->z);
  }
  fprintf(flacout, "* ZONES\n");

  int nnodes;
  int *nnn = new int[32];
  for (i = 0; i < numele; ++i) {
    Element *ele = eset[i];
    nnodes = ele->numNodes();
    nnn = ele->nodes(nnn);
    fprintf(flacout, "Z B8 %d   ", ele->elemnum);

    for (j = 0; j < 2; ++j) {
      fprintf(flacout, "%d ", nnn[j]);
    }
    fprintf(flacout, "%d %d %d %d %d %d\n", nnn[3], nnn[4], nnn[2], nnn[7],
            nnn[5], nnn[6]);
  }
  delete[] nnn;
  int count = 0;
  int l;
  j = 0;
  for (i = 0; i < numpart; ++i) {
    j = 0;
    Part *pt = pset[i];
    nnn = pt->vect;
    l = pt->length;
    fprintf(flacout, "ZGROUP PART%d \n", pt->partnum);

    while (j < l) {
      fprintf(flacout, "%d ", nnn[j]);
      ++count;
      /*
      if(count == 15) {
       fprintf(flacout,"\n");
       count = 0;
       }*/
      ++j;
    }
    fprintf(flacout, "\n ");
  }

  fclose(flacout);
}

int Domain::packelemdelete() {
  int iEle;
  packedEset.clear();
  exactNumEle = 0;
  for (iEle = 0; iEle < numele; ++iEle) {
    Element *ele = eset[iEle];
    if (ele != NULL && ele->prop != NULL && ele->eldel != 0) {
      packedEset.elemadd(ele);
      exactNumEle += 1;
    }
  }
  return 0;
}

int Domain::packelemall() {
  int iEle;
  packedEset.clear();
  exactNumEle = 0;
  for (iEle = 0; iEle < numele; ++iEle) {
    Element *ele = eset[iEle];
    if (ele != NULL && ele->prop != NULL && ele->eldel != 0 &&
        ele->elfail != 0) {
      packedEset.elemadd(ele);
      exactNumEle += 1;
      if (ele->prop == NULL) {
        fprintf(stderr, "%d element miss property\n", ele->elemnum);
      }
    }
  }
  return 0;
}

int Domain::fenqupolie() {
  int i, j, k;
  if (fq->step == 0) {
    if (solv.currentTime >= fq->ftime[0]) {
      for (i = 0; i < numele; ++i) {
        Element *el = eset[i];
        if (el->plas > 0) {
          el->elfail = 0;
        }
      }
      fq->step += 1;
    }
  } else if (fq->step == 1) {
    if ((fq->rkey[0] == 0) &&
        (solv.currentTime >= (fq->ftime[0] + fq->oktime[0]))) {
      for (i = 0; i < numele; ++i) {
        Element *el = eset[i];
        el->elfail = 1;
      }
      fq->rkey[0] = 1;
    }
    if (solv.currentTime >= fq->ftime[1]) {
      for (i = 0; i < numele; ++i) {
        Element *el = eset[i];
        if (el->plas > 0) {
          el->elfail = 0;
        }
      }
      fq->step += 1;
    }
  } else if (fq->step == 2) {
    if ((fq->rkey[1] == 0) &&
        (solv.currentTime >= (fq->ftime[1] + fq->oktime[1]))) {
      for (i = 0; i < numele; ++i) {
        Element *el = eset[i];
        el->elfail = 1;
      }
      fq->rkey[1] = 1;
    }
  }
  return 0;
}

int Domain::setfenqu(double d1, double d2, double d3, double d4) {
  int i;
  fq->step = 0;
  fq->rstep = 0;
  for (i = 0; i < 2; ++i) {
    fq->key[i] = 0;
  }
  fq->ftime[0] = d1;
  fq->ftime[1] = d2;
  fq->oktime[0] = d3;
  fq->oktime[1] = d4;
}

int Domain::settimestep(int timesteptype, double val) {
  sinfo.timestepflg = timesteptype;

  switch (timesteptype) {
    case 2:
      sinfo.dt = val;
      break;
    case 1:
      sinfo.tfactor = val;
    default:
      break;
  }
  return 0;
}

int Domain::settimestep(int val) {
  sinfo.timestepflg = 3;
  sinfo.CurveID = val;
}

int Domain::calctimestep() {
  int i;
  switch (solv.timestepflg) {
    case 1:
      double deltat, deltattemp;
      deltat = 1.e30;

      for (i = 0; i < exactNumEle; ++i) {
        deltattemp = deltat;
        Element *el = packedEset[i];
        deltattemp = deltat;
        deltat = el->EleTimeStep(nodes);
        deltat = dcp::max(dcp::min(deltattemp, deltat), 0.0);
      }
      if (solv.factor != 0.0) {
        solv.dt = deltat * solv.factor;
      } else {
        solv.dt = deltat;
      }

      break;
    case 2:
      break;
    case 3:
      solv.dt = cset.getCurve(sinfo.CurveID).getvalue(solv.currentTime);
      if (solv.dt == 0.0) {
        exit(-1);
      }
      break;
    default:
      break;
  }
}

double Domain::calcfm() {
  int i, j;
  double fm;
  fm = 0.0;
  Element *el;
  int numnfn = 0;
  Node *nd;
  for (i = 0; i < exactNumEle; ++i) {
    el = packedEset[i];
    fm += el->getfm();
    if (gravity[0] || gravity[1] || gravity[2]) {
      fm += el->getmass() *
            (fabs(gravity[0] + fabs(gravity[1]) + fabs(gravity[2])));
    }
  }

  for (i; i < numnodes; ++i) {
    nd = nodes[i];
    if (nd->fixed != 7) {
      numnfn += 1;
    }
  }

  fm = fm / numnfn;
  return fm;
}
