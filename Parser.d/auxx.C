#include "../Parser.d/auxx.h"

NList:: NList()
{
    n = 0;

    d = new int;
}

NList
NList:: add(int &m)
{
    int i;
    n = n+1;
    int maxn = n+10;
    int *newd = new int[maxn];
    int bbb=sizeof(*newd);
    for(i=0; i<(n-1); ++i)
        newd[i] = d[i];
    newd[n-1] =m;
    delete [] d;
    d =newd;
    
    return *this;
}

BCList:: BCList()
{
    n = 0;

    d = new BCond;
}

BCList
BCList:: add(BCond &m)
{
    int i;
    n = n+1;
    int maxn = n+10;
    BCond *newd = new BCond[maxn];
    int bbb=sizeof(*newd);
    for(i=0; i<(n-1); ++i)
        newd[i] = d[i];
    newd[n-1] =m;
    delete [] d;
    d =newd;
    
    return *this;
}


BCFList:: BCFList()
{
    n = 0;

    d = new BCFixed;
}

BCFList
BCFList:: add(BCFixed &m)
{
    int i;
    n = n+1;
    int maxn = n+10;
    BCFixed *newd = new BCFixed[maxn];
    int bbb=sizeof(*newd);
    for(i=0; i<(n-1); ++i)
        newd[i] = d[i];
    newd[n-1] =m;
    delete [] d;
    d =newd;
    
    return *this;
}

CurveTable:: CurveTable()
{
    n = 0;

    d = new CurveCoef;
}

CurveTable
CurveTable:: add(CurveCoef &m)
{
    int i;
    n = n+1;
    int maxn = n+10;
    CurveCoef *newd = new CurveCoef[maxn];
    int bbb=sizeof(*newd);
    for(i=0; i<(n-1); ++i)
        newd[i] = d[i];
    newd[n-1] =m;
    delete [] d;
    d =newd;
    
    return *this;
}

PropList:: PropList()
{
    n = 0;

    d = new double;
}

PropList
PropList:: add(double &m)
{
    int i;
    n = n+1;
    int maxn = n+10;
    double *newd = new double[maxn];
    int bbb=sizeof(*newd);
    for(i=0; i<(n-1); ++i)
        newd[i] = d[i];
    newd[n-1] =m;
    delete [] d;
    d =newd;
    
    return *this;
}

PropList
PropList:: add(PropList *p)
{
    int i;
    n = n+p->n;
    int maxn = n+10;
    double *newd = new double[maxn];
    int bbb=sizeof(*newd);
    for(i=0; i<(n-p->n); ++i)
        newd[i] = d[i];
    for(i =n-p->n; i < n; ++i )
    newd[i] =p->d[i-n +p->n];
    delete [] d;
    d =newd;
    
    return *this;
}
