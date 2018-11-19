%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "../Solvers.d/ConstData.h"
#include "../Parser.d/auxx.h"
#include "../Parser.d/y.tab.h"
int line_num = 1;
%}

DIGIT [0-9]
HEXDIGIT [0-9A-Fa-f]
SPACES [ \t]+
NAME [a-zA-Z_][a-zA-Z_0-9]*
TRAIL [a-zA-Z]*
%%
^"*TITLE"[a-zA-Z]* {return TITLE;    }

^"*NODE" { fprintf(stderr,"Reading Nodes\n"); return NODE;    }

"TYPE"   {return TYPE;}

"EPART"   {return EPART;}

"="      {return EQUALSIGN;}

","      {return COMMA;}

"C3D8R"  {return ET_SOLID;}

^"*ELEMENT" { fprintf(stderr,"Reading Elements\n"); return ELEMENT; }

^"*MATERIAL" { fprintf(stderr,"Reading Materials\n"); return MATERIAL;    }

^"*DISPLACEMENT" { fprintf(stderr,"Reading Disp BC\n"); return DISP; }

^"*FORCE" { fprintf(stderr,"Reading Force BC\n");return FORCE; }

"IVEL"[a-zA-Z]* { fprintf(stderr,"Reading Initial Velocity\n");return IVEL; }

"IACC"[a-zA-Z]* { fprintf(stderr,"Reading Initial Accelerate\n");return IACC; }

^"*INISTRESS" { fprintf(stderr,"Reading Initial Stress\n");return ISTR; }

^"*JAUMA"[a-zA-Z]* { fprintf(stderr,"Set Large \n");return JAUMA; }

^"*HOURGLASS" { fprintf(stderr,"Set Large \n");return HOURGLASS; }

^"*GRAVITY" { fprintf(stderr,"Set Gravity \n");return GRAV; }

^"*ATTRIBUTE" { fprintf(stderr,"Reading Attribute \n");return ATT; }

^"*CURVE" { fprintf(stderr,"Reading Curve \n");return CURVE; }

"ID" { return ID; }

^"*SOLVER" { fprintf(stderr,"Set Solver Type \n");return SOLV; }

"DYNAMIC" { return DYNA; }

^"*TERMINATION" { fprintf(stderr,"Set computate time \n");return TERM; }

^"*STATIC" { fprintf(stderr,"Set computate time \n");return STATICTERM; }

^"*TIMESTEP" { fprintf(stderr,"Set timestep \n");return TIMESTEP; }

"Fixed"      {  return TIMESTEP_FIXED;}

"Curve"      {  return TIMESTEP_CURVE;}

"AUTO"      {   return TIMESTEP_AUTO;}

"ELASTIC"   {   return MT_ELASTIC;}

^"*PRESSURE" { fprintf(stderr,"Reading Pressure \n");return PRESSURE; }

^"*FIXNODE" { fprintf(stderr,"Reading Boundary Condition \n");return FIXED; }

^"*OUTPUT" { fprintf(stderr,"Set Output info \n");return OUTPUT; }

^"*HISOUTPUT" { fprintf(stderr,"Set Output info \n");return HISOUTPUT;}

^"*HISNODE" { fprintf(stderr,"Set Output info \n");return HISNODE;}

^"*HISELEM" { fprintf(stderr,"Set Element Historty Output info \n");return HISELEM;}

^"*HISTORY" { fprintf(stderr,"Set Output info \n");return HISTORY; }

^"*STATUSFILE" { fprintf(stderr,"Set Status info \n");return STATUSFILE; }

^"*REMOVE" { fprintf(stderr,"Set Output info \n");return REMOVE;}

^"*NODPART" { fprintf(stderr,"Set NODE Part \n");return NODEPART;}

^"*ELEMPART" { fprintf(stderr,"Set ELEMENT Part \n");return ELEMPART;}

"GENERATE" { fprintf(stderr,"GENERATE \n");return GENERATE;}

^"*BULK_VISCO"[a-zA-Z]* { fprintf(stderr,"Set Output info \n");return BULK_VISCOSITY;}

^"*DEBUG" { fprintf(stderr,"Set Output info \n");return DEBUGFLG;}

^"*CLEARDVA" { fprintf(stderr,"Clear The Displacement and vilocity \n");return CLEARDVFLG;}

^"*EXPORTFLAC" { fprintf(stderr,"Export to Flac3D\n");return EXPORTFLAC;}

^"*FENQU" { fprintf(stderr,"set FENQQ\n");return FENQUPL;}

"eout_stre"[a-zA-Z]* {yylval.ival = TypeInfo::Stress;     return EOUTPUTID; }
"eout_stra"[a-zA-Z]* {yylval.ival= TypeInfo::Strain;     return EOUTPUTID; }
"eout_his"[a-zA-Z]* {yylval.ival= TypeInfo::History;     return EOUTPUTID; }
"eout_prinstress"[a-zA-Z]* {yylval.ival=TypeInfo::PrinStress;     return EOUTPUTID; }
"eout_mises" {yylval.ival=TypeInfo::PrinMises; return EOUTPUTID;}
"eout_center" {yylval.ival=TypeInfo::Center; return EOUTPUTID;}

"nout_disp"[a-zA-Z]* {yylval.ival=TypeInfo::displacement;    return NOUTPUTID; }
"nout_inf"[a-zA-Z]* {yylval.ival = TypeInfo::interforce ;    return NOUTPUTID; }
"nout_v"[a-zA-Z]* {yylval.ival = TypeInfo::velocity ;    return NOUTPUTID; }
"nout_a"[a-zA-Z]* {yylval.ival = TypeInfo::accelerate;    return NOUTPUTID; }
"nout_extf"[a-zA-Z]* {yylval.ival = TypeInfo::exterforce;    return NOUTPUTID; }

^"*LOCALDAMPING" {  return LOCALDAMP; }

^"*COMBINEDDAMPING" {  return LOCALDAMP; }

"ZERO"[a-zA-Z]* { return ZERO;    }

^"*END"  { fprintf(stderr,"End Reading Input File\n"); return END;  }

[A-Za-z][A-Za-z0-9_.]*  { yylval.strval = strdup(yytext); return STRNAME; }

"\""[[A-Za-z0-9_./]*"\"" { yytext[yyleng-1] = 0; yylval.strval = strdup(yytext+1);
                           return STRNAME; }

"\n" { line_num++; /* Count line numbers */ return NewLine; }

{SPACES} /* Just discard spaces */

[+-]?{DIGIT}+ {yylval.ival = atoi(yytext) ; return IntConstant ; }

[+-]?{DIGIT}+"."{DIGIT}* |
[+-]?"."{DIGIT}+ |
[+-]?{DIGIT}+"."{DIGIT}*[eE][+-]?{DIGIT}+ |
[+-]?{DIGIT}+[eE][+-]?{DIGIT}+ |
[+-]?"."{DIGIT}+[eE][+-]?{DIGIT}+ {
       yylval.fval = atof(yytext) ; return DblConstant ; }

[+-]?{DIGIT}+"."{DIGIT}*[dD][+-]?{DIGIT}+ |
[+-]?{DIGIT}+[dD][+-]?{DIGIT}+ |
[+-]?"."{DIGIT}+[dD][+-]?{DIGIT}+ {
       int il;
       for(il = 0; yytext[il] != 'd' && yytext[il] != 'D';) ++il;
       yytext[il] = 'e'; yylval.fval = atof(yytext) ; return DblConstant ; }

"%" { while(yyinput() != '\n') ; line_num++; }

%%
void
yyerror(const char  *s)
{
 fprintf(stderr,"%s\n",s);
 fprintf(stderr,"Syntax Error near line %d : %s\n", line_num,yytext);
}

int yywrap()
{
 return 0;
}
