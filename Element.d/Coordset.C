#include "../Element.d/Element.h"

typedef Node *NodeP;

CoordSet::CoordSet(int initialSize) {
  nodes = new NodeP[initialSize];
  nmax = initialSize;

  int i;
  for (i = 0; i < nmax; ++i) nodes[i] = 0;
}

CoordSet::CoordSet(const CoordSet &cs, int n, int *ndn) {
  nmax = n;
  nodes = new NodeP[nmax];
  int i;
  for (i = 0; i < nmax; ++i) nodes[i] = cs.nodes[ndn[i]];
}

void CoordSet::nodeadd(int n, double *xyz) {
  int newsize = nmax + 1;
  NodeP *np = new NodeP[newsize];
  int i;
  for (i = 0; i < nmax; ++i) np[i] = nodes[i];
  nmax = newsize;
  np[nmax - 1] = 0;
  delete[] nodes;
  nodes = np;

  nodes[nmax - 1] = new (ba) Node(n, xyz);
}

void CoordSet::nodeadd(Node *nd) {
  int newsize = nmax + 1;
  NodeP *np = new NodeP[newsize];
  int i;
  for (i = 0; i < nmax; ++i) np[i] = nodes[i];
  nmax = newsize;
  np[nmax - 1] = 0;
  delete[] nodes;
  nodes = np;

  nodes[nmax - 1] = nd;
}

Node &CoordSet::getNode(int i) {
  int n;
  for (n = 0; n < nmax; ++n) {
    if (nodes[n]) {
      if (nodes[n]->nodenum == i) {
        return *nodes[n];
      }
    }
  }
  return *nodes[i];
}

int CoordSet::getnindex(int i) {
  int n;
  /*
  if(nodes[i-1]){
      if(nodes[i-1]->nodenum == i){
          return i-1;
      }
  }
  */
  for (n = 0; n < nmax; ++n) {
    if (nodes[n]) {
      if (nodes[n]->nodenum == i) {
        return n;
      }
    } else {
      fprintf(stderr, "NODES Not Exsit!!!");
      return -1;
    }
  }

  return -1;
}

CoordSet *CoordSet::copy() {
  CoordSet *newset = new CoordSet;

  double *xyz = new double[3];
  int nodeno;

  int i;
  for (i = 0; i < nmax; ++i) {
    if (nodes[i]) {
      nodeno = nodes[i]->nodenum;
      xyz[0] = nodes[i]->x;
      xyz[1] = nodes[i]->y;
      xyz[2] = nodes[i]->z;
      newset->nodeadd(nodeno, xyz);
    }
  }

  return newset;
}
