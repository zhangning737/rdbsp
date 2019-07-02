/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IntConstant = 258,
    DblConstant = 259,
    NODE = 260,
    NewLine = 261,
    ELEMENT = 262,
    ZERO = 263,
    STRNAME = 264,
    END = 265,
    MATERIAL = 266,
    DISP = 267,
    FORCE = 268,
    IVEL = 269,
    IACC = 270,
    ISTR = 271,
    JAUMA = 272,
    GRAV = 273,
    ATT = 274,
    CURVE = 275,
    TERM = 276,
    PRESSURE = 277,
    FIXED = 278,
    TIMESTEP = 279,
    DYNA = 280,
    SOLV = 281,
    OUTPUT = 282,
    NOUTPUTID = 283,
    EOUTPUTID = 284,
    HISTORY = 285,
    HISOUTPUT = 286,
    HOURGLASS = 287,
    STATUSFILE = 288,
    TITLE = 289,
    REMOVE = 290,
    BULK_VISCOSITY = 291,
    HISNODE = 292,
    HISELEM = 293,
    DEBUGFLG = 294,
    CLEARDVFLG = 295,
    LOCALDAMP = 296,
    COMBINEDDAMP = 297,
    STATICTERM = 298,
    EXPORTFLAC = 299,
    NODEPART = 300,
    ELEMPART = 301,
    GENERATE = 302,
    FENQUPL = 303,
    TYPE = 304,
    ESET = 305,
    C3D8R = 306,
    TIMESTEPID = 307,
    TIMESTEP_FIXED = 308,
    TIMESTEP_CURVE = 309,
    TIMESTEP_AUTO = 310,
    ID = 311,
    IDNO = 312,
    COMMA = 313,
    ELEMENTTYPE = 314,
    EPART = 315,
    EQUALSIGN = 316,
    Element_Solid = 317,
    ET_SOLID = 318,
    MT_ELASTIC = 319
  };
#endif
/* Tokens.  */
#define IntConstant 258
#define DblConstant 259
#define NODE 260
#define NewLine 261
#define ELEMENT 262
#define ZERO 263
#define STRNAME 264
#define END 265
#define MATERIAL 266
#define DISP 267
#define FORCE 268
#define IVEL 269
#define IACC 270
#define ISTR 271
#define JAUMA 272
#define GRAV 273
#define ATT 274
#define CURVE 275
#define TERM 276
#define PRESSURE 277
#define FIXED 278
#define TIMESTEP 279
#define DYNA 280
#define SOLV 281
#define OUTPUT 282
#define NOUTPUTID 283
#define EOUTPUTID 284
#define HISTORY 285
#define HISOUTPUT 286
#define HOURGLASS 287
#define STATUSFILE 288
#define TITLE 289
#define REMOVE 290
#define BULK_VISCOSITY 291
#define HISNODE 292
#define HISELEM 293
#define DEBUGFLG 294
#define CLEARDVFLG 295
#define LOCALDAMP 296
#define COMBINEDDAMP 297
#define STATICTERM 298
#define EXPORTFLAC 299
#define NODEPART 300
#define ELEMPART 301
#define GENERATE 302
#define FENQUPL 303
#define TYPE 304
#define ESET 305
#define C3D8R 306
#define TIMESTEPID 307
#define TIMESTEP_FIXED 308
#define TIMESTEP_CURVE 309
#define TIMESTEP_AUTO 310
#define ID 311
#define IDNO 312
#define COMMA 313
#define ELEMENTTYPE 314
#define EPART 315
#define EQUALSIGN 316
#define Element_Solid 317
#define ET_SOLID 318
#define MT_ELASTIC 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "p.y" /* yacc.c:1921  */

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


#line 205 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
