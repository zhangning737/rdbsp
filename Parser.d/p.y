%error-verbose
%{
#include <stdio.h>
#include <stdlib.h>
#include "../Parser.d/auxx.h"
 int numColumns = 3;
 double amplitude = 1.0;

extern Domain *domain;
extern int yylex();
extern void yyerror(const char *);

%}

%union
{
 int ival;
 double fval;
 char * strval;
 NumedNode nval;  //aux struct
 PropList *pl;     //strure prop
 BCond bcval;
 BCList *bclist;  //BC list
 INISTRESS istr;
BPress bp;
 BCFixed bcfix;
 Part *ptemp;
 BCFList *bcflist;
CurveCoef  ccoef;
CurveTable *clist;
NList *nlist;

}

%token IntConstant DblConstant NODE NewLine  ELEMENT  ZERO
%token STRNAME END MATERIAL DISP FORCE IVEL IACC ISTR JAUMA
%token GRAV ATT CURVE TERM PRESSURE FIXED TIMESTEP DYNA
%token SOLV OUTPUT NOUTPUTID EOUTPUTID HISTORY HISOUTPUT
%token HOURGLASS STATUSFILE TITLE REMOVE BULK_VISCOSITY
%token HISNODE HISELEM DEBUGFLG CLEARDVFLG LOCALDAMP
%token COMBINEDDAMP STATICTERM EXPORTFLAC NODEPART ELEMPART
%token GENERATE  FENQUPL TYPE ESET C3D8R TIMESTEPID
%token TIMESTEP_FIXED TIMESTEP_CURVE TIMESTEP_AUTO
%token ID IDNO  COMMA ELEMENTTYPE EPART EQUALSIGN Element_Solid
%token ET_SOLID MT_ELASTIC

%type <nval> Node

%type <strval> STRNAME 
%type <ival> Integer IntConstant
%type <fval> Float DblConstant
%type <pl> Props PropsList
%type <bcval> BC_Data
%type <bclist> DirichletBC NeumanBC BCDataList
%type <istr> IStressData
%type <bp> PresData
%type <bcfix> BCF_Data
%type <bcflist> BCFDataList BoundaryFix
%type <ival> NOUTPUTID EOUTPUTID ELEMENTTYPE TIMESTEPID
%type <ptemp>  PartList
%type <ival> IDNO
%type <clist> CurveDataList 
%type <ccoef> CurveData
%type <nlist> Element_Solid_List NodeNums

%%
FinalizedData:
	All END
	 { 
	   return 0; 
         }
All:
	Component
	| All Component

Component:
	NodeSet 
	| ElemSet
    | MatSet
    | DirichletBC
    {if(domain->setDirichlet($1->n,$1->d)<0) { delete $1; return -1;   }   }
    | NeumanBC
    {if(domain->setNeuman($1->n,$1->d)<0){  delete $1; return -1;    } }
    | IVel
    | IAcc
    | IStr
    | SetLarge
    | HourGlassControl
    | SetGravity
    | SetAttribute
    | ReadCurve
    | SetEndTime
    | Pressure
    | BoundaryFix
    {if(domain->setfix($1->n, $1->d)<0) {   delete $1; return -1;}   }
    | TimeStep
    | Solver
    | OutInfo
    | History
    | HisOutput
    | NodeForHis
    | ElemForHis
    | WriteStatus
    | DeleteElement
    | Bulk_Visco
    | DebugFlg
    | ClearDV
    | LocalDamping
    | CombinedDamping
    | StaticTerm
    | ExportFlac
    | NodePart
    | ElemPart
    | FenQu

NodeSet:
	NODE NewLine Node
	{ domain->addNode($3.num, $3.xyz); }
	| NodeSet Node
	{ domain->addNode($2.num, $2.xyz); }    
	
Node:
	Integer Float Float Float NewLine
	{ $$.num = $1; $$.xyz[0] = $2; $$.xyz[1] = $3;  $$.xyz[2] = $4; }
	| Integer Float Float NewLine
	{ $$.num = $1; $$.xyz[0] = $2; $$.xyz[1] = $3;  $$.xyz[2] = 0.0; }
	| Integer Float NewLine
	{ $$.num = $1; $$.xyz[0] = $2; $$.xyz[1] = 0.0; $$.xyz[2] = 0.0; }
	
ElemSet:
      ELEMENT COMMA TYPE EQUALSIGN ET_SOLID NewLine Element_Solid_List
      {delete $7;}
    | ELEMENT COMMA TYPE EQUALSIGN ET_SOLID COMMA  EPART EQUALSIGN Integer NewLine Element_Solid_List
    {domain->addPart($9, 2 , $11->n, $11->d);  }
    | ELEMENT COMMA  EPART EQUALSIGN Integer COMMA TYPE EQUALSIGN ET_SOLID  NewLine Element_Solid_List
    {domain->addPart($5, 2 , $11->n, $11->d); }
    | ElemSet Element_Solid
    | ELEMENT NewLine Element
	| ElemSet Element

Element:
	Integer Integer NodeNums NewLine
	{ /* Define each Element */
          domain->addElem($1, $2, $3->n, $3->d); }

 Element_Solid_List:
         Integer NodeNums NewLine
       {$$ = new NList;$$->add($1); domain->addElem($1, TypeInfo::Solid, $2->n,$2->d );}
       |Element_Solid_List Integer NodeNums NewLine
       {$$->add($2); domain->addElem($2, TypeInfo::Solid, $3->n,$3->d );}


NodeNums:
	Integer
	{ $$ = new NList; $$->add($1) ; }
	| NodeNums Integer
	{ $$->add($2); }
    | GENERATE Integer Integer Integer 
    {int i;$$ = new NList;
      for(i=$2; i<$3+$4; i = i+$4)
      {         $$->add(i);      }  }

MatSet:
     MATERIAL COMMA ID EQUALSIGN Integer COMMA TYPE EQUALSIGN MT_ELASTIC NewLine PropsList 
     {domain->addMat($5, 1 , $11->n,  $11->d) ; delete $11;    }
    |MATERIAL COMMA TYPE EQUALSIGN MT_ELASTIC COMMA ID EQUALSIGN Integer  NewLine PropsList 
     {domain->addMat($9, 1 , $11->n,  $11->d) ; delete $11;    }
    |MATERIAL NewLine Integer Integer PropsList
     {domain->addMat($3, $4 , $5->n,  $5->d) ; delete $5;    }
    |MATERIAL NewLine PropsList
     {domain->addMat(0, 1 , $3->n,  $3->d) ; delete $3;    }

PropsList:
    Props NewLine
    {$$ = new PropList; $$->add($1);}
   | PropsList Props NewLine
    { $$->add($2);  }  
Props:
     Float
	{ $$ = new PropList;$$->add($1); }
	| Props Float
	{ $$->add($2);  }  
     
DirichletBC:
        DISP NewLine BCDataList
        { $$ = $3; }

NeumanBC:
	FORCE NewLine BCDataList
	{ $$ = $3; }

IVel:
        IVEL NewLine BCDataList
        { if(domain->setIVel($3->n,$3->d) < 0) return -1; }

IAcc:
        IACC NewLine BCDataList
        { if(domain->setIAcc($3->n,$3->d) < 0) return -1; }


BCDataList:
	BC_Data
	{ $$ = new BCList; $$->add($1); }
	| BCDataList BC_Data
	{ $$ = $1; $$->add($2); }

BC_Data:
	Integer Integer Integer Float NewLine
	{ $$.nnum = $1; $$.dofnum = $2; $$.curvenum = $3; $$.val = $4; }
	| Integer Integer NewLine
	{ $$.nnum = $1; $$.dofnum = $2; $$.curvenum = 0; $$.val = 0.0; }

BoundaryFix:
     FIXED NewLine BCFDataList
     {$$  = $3;  }

BCFDataList:
     BCF_Data
	{ $$ = new BCFList; $$->add($1); }
	| BCFDataList BCF_Data
	{ $$ = $1; $$->add($2); }

BCF_Data:
	Integer Integer Integer Integer NewLine
	{ $$.nnum = $1; $$.fix[0] = $2; $$.fix[1] = $3; $$.fix[2] = $4; }
	| Integer Integer NewLine
	{ $$.nnum = $1; $$.fix[0] = $2; $$.fix[1] = 0; $$.fix[2] = 0; }
    | Integer Integer Integer NewLine
    { $$.nnum = $1; $$.fix[0] = $2; $$.fix[1] = $3; $$.fix[2] = 0;    }

IStr:
     ISTR NewLine IStressList
     
IStressList:
     IStressData
     {domain->setinistress($1.nele, $1.istress);     }
     |IStressList IStressData
     {domain->setinistress($2.nele, $2.istress);    }

IStressData:
     Integer  Float  Float Float  Float Float Float NewLine
     {$$.nele=$1; $$.istress[0]=$2; $$.istress[1] = $3;
         $$.istress[2] = $4; $$.istress[3] = $5; $$.istress[4] = $6; $$.istress[5] = $7;}

Pressure:
     PRESSURE NewLine PressureList
     
PressureList:
     PresData
     { domain->setpress($1);    }
     |PressureList PresData
     { domain->setpress($2);     }

PresData:
     Integer Float Integer Integer Integer Integer NewLine
     {$$.cnum = $1; $$.value = $2; $$.nodelist[0] = $3; $$.nodelist[1] = $4; $$.nodelist[2] = $5; $$.nodelist[3] = $6;     }


SetLarge:
     JAUMA NewLine
     {domain->setlarge();     }

HourGlassControl:
     HOURGLASS NewLine Integer NewLine
     {         domain->sethourglass($3);     }
     |HOURGLASS NewLine Integer Float NewLine
     {domain->sethourglass($3,$4);}

SetGravity:
     GRAV NewLine Float Float Float NewLine
     {domain->setgrav($3, $4, $5);     }


SetAttribute:
     ATT NewLine AttList
     |ATT COMMA TYPE EQUALSIGN EPART NewLine PAttList
     

AttList:
    AttData
    |AttList AttData

AttData:
    Integer Integer NewLine
    {domain->setatt($1, $2);    }
   |Integer Integer Integer NewLine
   { int i;
       for(i=$1; i<$2+1; ++i)    domain->setatt(i, $3);
       }

PAttList:
    PAttData
    |PAttList PAttData

PAttData:
    Integer Integer NewLine
    {domain->setpatt($1, $2);    }
   |Integer Integer Integer NewLine
   { int i;
       for(i=$1; i<$2+1; ++i)    domain->setpatt(i, $3);
       }

ReadCurve:
     CURVE COMMA ID EQUALSIGN Integer NewLine CurveDataList
     {domain->addCurve($5,$7->n,$7->d); delete $7;  }
     | CURVE NewLine CurveDataList
     {domain->addCurve(0,$3->n,$3->d); delete $3;      }

CurveDataList:
      CurveData
     {$$ = new CurveTable; $$->add($1);}
     | CurveDataList CurveData
     {$$ = $1; $$->add($2);}

CurveData:
     Float Float NewLine
     {$$.coef1 = $1; $$.coef2 = $2;}
     

SetEndTime:
     TERM NewLine Float NewLine
     {domain->setendtime($3);     }

TimeStep:
     | TIMESTEP NewLine Float NewLine
     {domain->settimestep(1,$3);     }
     | TIMESTEP COMMA TYPE EQUALSIGN TIMESTEP_AUTO NewLine Float NewLine
     {domain->settimestep(1,$7);}
     | TIMESTEP COMMA TYPE EQUALSIGN TIMESTEP_FIXED NewLine Float NewLine
     {domain->settimestep(2,$7); }
     | TIMESTEP COMMA TYPE EQUALSIGN TIMESTEP_CURVE NewLine Integer NewLine
     {domain->settimestep($7);}

Solver:
     SOLV NewLine DYNA NewLine
     {domain->solinfo().setProbType(1);}

OutInfo:
     OUTPUT NewLine Integer Integer NewLine NOutList NewLine EOutList NewLine
     { domain->setointer($3,$4); }
     |OUTPUT NewLine Integer Float NewLine NOutList NewLine EOutList NewLine
     { domain->setointer($3,$4); }
     |OUTPUT NewLine Float NewLine NOutList NewLine EOutList NewLine
     { domain->setointer(1,$3); }
     |OUTPUT NewLine Float NewLine 
     { domain->setointer(1,$3); }
     | OUTPUT NewLine Integer Integer NewLine 
     { domain->setointer($3,$4); }
     |OUTPUT NewLine Integer Float NewLine
     { domain->setointer($3,$4); }
     | OUTPUT NewLine Integer Integer NewLine NOutList NewLine
     { domain->setointer($3,$4); }
     |OUTPUT NewLine Integer Float NewLine NOutList NewLine
     { domain->setointer($3,$4); }
     |OUTPUT NewLine Float NewLine NOutList NewLine
     { domain->setointer(1,$3); }
     | OUTPUT NewLine Integer Integer NewLine EOutList NewLine
     { domain->setointer($3,$4); }
     |OUTPUT NewLine Integer Float NewLine EOutList NewLine
     { domain->setointer($3,$4); }
     |OUTPUT NewLine Float NewLine EOutList NewLine
     { domain->setointer(1,$3); }


NOutList:
     NOUTPUTID
     {domain->addnout($1); }
     | NOutList NOUTPUTID
     { domain->addnout($2); }

EOutList:
     EOUTPUTID
     {domain->addeout($1); }
     | EOutList EOUTPUTID
     { domain->addeout($2); }

History:
     | HISTORY NewLine Integer NewLine
     {domain->sethisdata($3);}

HisOutput:
     HISOUTPUT NewLine Float NewLine
     {domain->sethisointer($3);}

NodeForHis:
     HISNODE NewLine HisNodeList

HisNodeList:
     Integer NewLine
     {domain->addhisnode($1);     }
     | HisNodeList Integer NewLine
     {domain->addhisnode($2);     }

ElemForHis:
     HISELEM NewLine HisEleList

HisEleList:
     Integer NewLine
     {domain->addhiselem($1); }
     | HisEleList Integer NewLine
     {domain->addhiselem($2);}

WriteStatus:
     STATUSFILE NewLine Float NewLine
     {domain->setsinter($3);     }
     | STATUSFILE NewLine Integer NewLine
     {domain->setsinter($3);     }
     
DeleteElement:
      REMOVE NewLine DelElList
      | REMOVE COMMA TYPE EQUALSIGN EPART NewLine DelPList

DelElList:
      Integer NewLine
      {domain->delelem($1);      }
      | DelElList Integer NewLine
      {domain->delelem($2);}

DelPList:
      Integer NewLine
      {domain->delpart($1);      }
      | DelPList Integer NewLine
      {domain->delpart($2);}


Bulk_Visco:
      BULK_VISCOSITY NewLine Float Float NewLine
      {domain->setbulkvisco($3,$4);      }

DebugFlg:
      DEBUGFLG NewLine
      {domain->setdebug();}

ClearDV:
      CLEARDVFLG NewLine
      {domain->cleardv();}

LocalDamping:
      LOCALDAMP NewLine
      {domain->setdamping(1,0.8);  }
      | LOCALDAMP NewLine Float NewLine
      {domain->setdamping(1,$3);}

CombinedDamping:
      COMBINEDDAMP NewLine
      {domain->setdamping(2,0.8); }
      | COMBINEDDAMP NewLine Float NewLine
      {domain->setdamping(2,$3); }

StaticTerm:
      STATICTERM NewLine
      {domain->staticterm();  }
      | STATICTERM NewLine Float NewLine
      {domain->staticterm($3);}

ExportFlac:
      EXPORTFLAC NewLine
      {domain->setexportflacflg();}

NodePart:
      NODEPART COMMA ID EQUALSIGN Integer NewLine PartList
      {domain->addPart($5, 1 , $7);    }

ElemPart:
      ELEMPART COMMA ID  EQUALSIGN Integer NewLine PartList
      {domain->addPart($5, 2 , $7);     }

PartList:
       NodeNums NewLine
      {$$ = new Part;$$->addvect($1->n,$1->d);}
      | PartList NodeNums NewLine
      {$$->addvect($2->n,$2->d);}

FenQu:
      FENQUPL NewLine Float Float Float Float NewLine
      {domain->setfenqu($3,$4,$5,$6);}

Integer:
	IntConstant
	{ $$ = $1; }

Float:
	IntConstant
	{ $$ = $1; }
	| DblConstant
	{ $$ = $1; }
%%
