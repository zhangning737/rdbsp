/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 2 "p.y"

#include <stdio.h>
#include <stdlib.h>
#include "../Parser.d/auxx.h"
 int numColumns = 3;
 double amplitude = 1.0;

extern Domain *domain;
extern int yylex();
extern void yyerror(const char *);


/* Line 371 of yacc.c  */
#line 81 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 16 "p.y"

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



/* Line 387 of yacc.c  */
#line 272 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 300 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  115
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   610

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  389

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    75,    77,    79,
      81,    85,    88,    94,    99,   103,   111,   123,   135,   138,
     142,   145,   150,   154,   159,   161,   164,   169,   181,   193,
     199,   203,   206,   210,   212,   215,   219,   223,   227,   231,
     233,   236,   242,   246,   250,   252,   255,   261,   265,   270,
     274,   276,   279,   288,   292,   294,   297,   305,   308,   313,
     319,   326,   330,   338,   340,   343,   347,   352,   354,   357,
     361,   366,   374,   378,   380,   383,   387,   392,   393,   398,
     407,   416,   425,   430,   440,   450,   459,   464,   470,   476,
     484,   492,   499,   507,   515,   522,   524,   527,   529,   532,
     533,   538,   543,   547,   550,   554,   558,   561,   565,   570,
     575,   579,   587,   590,   594,   597,   601,   607,   610,   613,
     616,   621,   624,   629,   632,   637,   640,   648,   656,   659,
     663,   671,   673,   675
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      66,     0,    -1,    67,    10,    -1,    68,    -1,    67,    68,
      -1,    69,    -1,    71,    -1,    75,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,    87,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,   101,    -1,   104,    -1,    90,
      -1,    84,    -1,   105,    -1,   106,    -1,   107,    -1,   110,
      -1,   111,    -1,   112,    -1,   114,    -1,   116,    -1,   117,
      -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,   124,
      -1,   125,    -1,   126,    -1,   127,    -1,   128,    -1,   130,
      -1,     5,     6,    70,    -1,    69,    70,    -1,   131,   132,
     132,   132,     6,    -1,   131,   132,   132,     6,    -1,   131,
     132,     6,    -1,     7,    58,    49,    61,    63,     6,    73,
      -1,     7,    58,    49,    61,    63,    58,    60,    61,   131,
       6,    73,    -1,     7,    58,    60,    61,   131,    58,    49,
      61,    63,     6,    73,    -1,    71,    62,    -1,     7,     6,
      72,    -1,    71,    72,    -1,   131,   131,    74,     6,    -1,
     131,    74,     6,    -1,    73,   131,    74,     6,    -1,   131,
      -1,    74,   131,    -1,    47,   131,   131,   131,    -1,    11,
      58,    56,    61,   131,    58,    49,    61,    64,     6,    76,
      -1,    11,    58,    49,    61,    64,    58,    56,    61,   131,
       6,    76,    -1,    11,     6,   131,   131,    76,    -1,    11,
       6,    76,    -1,    77,     6,    -1,    76,    77,     6,    -1,
     132,    -1,    77,   132,    -1,    12,     6,    82,    -1,    13,
       6,    82,    -1,    14,     6,    82,    -1,    15,     6,    82,
      -1,    83,    -1,    82,    83,    -1,   131,   131,   131,   132,
       6,    -1,   131,   131,     6,    -1,    23,     6,    85,    -1,
      86,    -1,    85,    86,    -1,   131,   131,   131,   131,     6,
      -1,   131,   131,     6,    -1,   131,   131,   131,     6,    -1,
      16,     6,    88,    -1,    89,    -1,    88,    89,    -1,   131,
     132,   132,   132,   132,   132,   132,     6,    -1,    22,     6,
      91,    -1,    92,    -1,    91,    92,    -1,   131,   132,   131,
     131,   131,   131,     6,    -1,    17,     6,    -1,    32,     6,
     131,     6,    -1,    32,     6,   131,   132,     6,    -1,    18,
       6,   132,   132,   132,     6,    -1,    19,     6,    97,    -1,
      19,    58,    49,    61,    60,     6,    99,    -1,    98,    -1,
      97,    98,    -1,   131,   131,     6,    -1,   131,   131,   131,
       6,    -1,   100,    -1,    99,   100,    -1,   131,   131,     6,
      -1,   131,   131,   131,     6,    -1,    20,    58,    56,    61,
     131,     6,   102,    -1,    20,     6,   102,    -1,   103,    -1,
     102,   103,    -1,   132,   132,     6,    -1,    21,     6,   132,
       6,    -1,    -1,    24,     6,   132,     6,    -1,    24,    58,
      49,    61,    55,     6,   132,     6,    -1,    24,    58,    49,
      61,    53,     6,   132,     6,    -1,    24,    58,    49,    61,
      54,     6,   131,     6,    -1,    26,     6,    25,     6,    -1,
      27,     6,   131,   131,     6,   108,     6,   109,     6,    -1,
      27,     6,   131,   132,     6,   108,     6,   109,     6,    -1,
      27,     6,   132,     6,   108,     6,   109,     6,    -1,    27,
       6,   132,     6,    -1,    27,     6,   131,   131,     6,    -1,
      27,     6,   131,   132,     6,    -1,    27,     6,   131,   131,
       6,   108,     6,    -1,    27,     6,   131,   132,     6,   108,
       6,    -1,    27,     6,   132,     6,   108,     6,    -1,    27,
       6,   131,   131,     6,   109,     6,    -1,    27,     6,   131,
     132,     6,   109,     6,    -1,    27,     6,   132,     6,   109,
       6,    -1,    28,    -1,   108,    28,    -1,    29,    -1,   109,
      29,    -1,    -1,    30,     6,   131,     6,    -1,    31,     6,
     132,     6,    -1,    37,     6,   113,    -1,   131,     6,    -1,
     113,   131,     6,    -1,    38,     6,   115,    -1,   131,     6,
      -1,   115,   131,     6,    -1,    33,     6,   132,     6,    -1,
      33,     6,   131,     6,    -1,    35,     6,   118,    -1,    35,
      58,    49,    61,    60,     6,   119,    -1,   131,     6,    -1,
     118,   131,     6,    -1,   131,     6,    -1,   119,   131,     6,
      -1,    36,     6,   132,   132,     6,    -1,    39,     6,    -1,
      40,     6,    -1,    41,     6,    -1,    41,     6,   132,     6,
      -1,    42,     6,    -1,    42,     6,   132,     6,    -1,    43,
       6,    -1,    43,     6,   132,     6,    -1,    44,     6,    -1,
      45,    58,    56,    61,   131,     6,   129,    -1,    46,    58,
      56,    61,   131,     6,   129,    -1,    74,     6,    -1,   129,
      74,     6,    -1,    48,     6,   132,   132,   132,   132,     6,
      -1,     3,    -1,     3,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    73,    74,    77,    78,    79,    80,    82,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     117,   119,   123,   125,   127,   131,   133,   135,   137,   138,
     139,   142,   147,   149,   154,   156,   158,   164,   166,   168,
     170,   174,   176,   179,   181,   185,   189,   193,   197,   202,
     204,   208,   210,   214,   218,   220,   224,   226,   228,   232,
     235,   237,   241,   246,   249,   251,   255,   260,   264,   266,
     270,   275,   276,   280,   281,   284,   286,   292,   293,   296,
     298,   304,   306,   310,   312,   316,   321,   324,   325,   327,
     329,   331,   335,   339,   341,   343,   345,   347,   349,   351,
     353,   355,   357,   359,   361,   366,   368,   372,   374,   377,
     378,   382,   386,   389,   391,   395,   398,   400,   404,   406,
     410,   411,   414,   416,   420,   422,   427,   431,   435,   439,
     441,   445,   447,   451,   453,   457,   461,   465,   469,   471,
     475,   479,   483,   485
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IntConstant", "DblConstant", "NODE",
  "NewLine", "ELEMENT", "ZERO", "STRNAME", "END", "MATERIAL", "DISP",
  "FORCE", "IVEL", "IACC", "ISTR", "JAUMA", "GRAV", "ATT", "CURVE", "TERM",
  "PRESSURE", "FIXED", "TIMESTEP", "DYNA", "SOLV", "OUTPUT", "NOUTPUTID",
  "EOUTPUTID", "HISTORY", "HISOUTPUT", "HOURGLASS", "STATUSFILE", "TITLE",
  "REMOVE", "BULK_VISCOSITY", "HISNODE", "HISELEM", "DEBUGFLG",
  "CLEARDVFLG", "LOCALDAMP", "COMBINEDDAMP", "STATICTERM", "EXPORTFLAC",
  "NODEPART", "ELEMPART", "GENERATE", "FENQUPL", "TYPE", "ESET", "C3D8R",
  "TIMESTEPID", "TIMESTEP_FIXED", "TIMESTEP_CURVE", "TIMESTEP_AUTO", "ID",
  "IDNO", "COMMA", "ELEMENTTYPE", "EPART", "EQUALSIGN", "Element_Solid",
  "ET_SOLID", "MT_ELASTIC", "$accept", "FinalizedData", "All", "Component",
  "NodeSet", "Node", "ElemSet", "Element", "Element_Solid_List",
  "NodeNums", "MatSet", "PropsList", "Props", "DirichletBC", "NeumanBC",
  "IVel", "IAcc", "BCDataList", "BC_Data", "BoundaryFix", "BCFDataList",
  "BCF_Data", "IStr", "IStressList", "IStressData", "Pressure",
  "PressureList", "PresData", "SetLarge", "HourGlassControl", "SetGravity",
  "SetAttribute", "AttList", "AttData", "PAttList", "PAttData",
  "ReadCurve", "CurveDataList", "CurveData", "SetEndTime", "TimeStep",
  "Solver", "OutInfo", "NOutList", "EOutList", "History", "HisOutput",
  "NodeForHis", "HisNodeList", "ElemForHis", "HisEleList", "WriteStatus",
  "DeleteElement", "DelElList", "DelPList", "Bulk_Visco", "DebugFlg",
  "ClearDV", "LocalDamping", "CombinedDamping", "StaticTerm", "ExportFlac",
  "NodePart", "ElemPart", "PartList", "FenQu", "Integer", "Float", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    79,    80,    81,    82,
      82,    83,    83,    84,    85,    85,    86,    86,    86,    87,
      88,    88,    89,    90,    91,    91,    92,    93,    94,    94,
      95,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   104,   105,   105,   105,
     105,   105,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   112,   113,   113,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   121,   122,   123,
     123,   124,   124,   125,   125,   126,   127,   128,   129,   129,
     130,   131,   132,   132
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     5,     4,     3,     7,    11,    11,     2,     3,
       2,     4,     3,     4,     1,     2,     4,    11,    11,     5,
       3,     2,     3,     1,     2,     3,     3,     3,     3,     1,
       2,     5,     3,     3,     1,     2,     5,     3,     4,     3,
       1,     2,     8,     3,     1,     2,     7,     2,     4,     5,
       6,     3,     7,     1,     2,     3,     4,     1,     2,     3,
       4,     7,     3,     1,     2,     3,     4,     0,     4,     8,
       8,     8,     4,     9,     9,     8,     4,     5,     5,     7,
       7,     6,     7,     7,     6,     1,     2,     1,     2,     0,
       4,     4,     3,     2,     3,     3,     2,     3,     4,     4,
       3,     7,     2,     3,     2,     3,     5,     2,     2,     2,
       4,     2,     4,     2,     4,     2,     7,     7,     2,     3,
       7,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     5,
       6,     7,     8,     9,    10,    11,    20,    12,    19,    13,
      14,    15,    16,    17,    18,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,   151,
     153,   155,     0,     0,     0,     1,     2,     4,   161,    41,
       0,    48,    50,     0,    40,    49,     0,     0,   161,   163,
      60,     0,     0,    63,     0,     0,    65,    69,     0,    66,
      67,    68,    79,    80,     0,   162,     0,    91,    93,     0,
       0,   102,   103,     0,     0,     0,    83,    84,     0,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,   132,     0,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    64,     0,     0,     0,    70,     0,    81,     0,
       0,    94,     0,     0,   104,     0,     0,   106,    85,     0,
      75,     0,   108,     0,   112,     0,     0,   116,   130,   131,
      88,     0,   139,   138,     0,   142,     0,     0,     0,   133,
       0,   136,   150,   152,   154,     0,     0,     0,    44,     0,
       0,     0,    54,     0,     0,    62,    59,     0,     0,    72,
       0,     0,     0,    95,     0,     0,   105,     0,     0,    77,
       0,     0,     0,     0,   117,   118,   125,   127,     0,     0,
      89,   143,     0,   146,   134,   137,     0,     0,     0,    43,
       0,     0,    51,    55,     0,     0,     0,     0,     0,     0,
       0,    90,    96,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   126,   124,   128,     0,
       0,     0,     0,    42,     0,    45,     0,     0,     0,     0,
       0,    71,     0,    92,    97,     0,   101,     0,    76,     0,
       0,     0,   119,   122,   120,   123,     0,   141,     0,     0,
     156,   157,   160,    56,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,   110,   111,   109,     0,     0,   115,
       0,   144,   158,     0,     0,    52,     0,     0,     0,     0,
       0,    99,     0,    86,   113,   114,   145,   159,    53,     0,
       0,     0,     0,    82,   100,    46,    47,    58,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    36,    37,    38,    39,   119,    40,   122,   315,   339,
      41,   130,   131,    42,    43,    44,    45,   136,   137,    46,
     159,   160,    47,   142,   143,    48,   156,   157,    49,    50,
      51,    52,   147,   148,   323,   324,    53,   151,   152,    54,
      55,    56,    57,   268,   269,    58,    59,    60,   176,    61,
     178,    62,    63,   172,   337,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   340,    73,   138,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -257
static const yytype_int16 yypact[] =
{
     450,    35,     6,     9,    49,    73,    75,    77,    84,    86,
      90,    10,    11,    92,    94,    99,    12,   101,   117,   124,
     129,   132,   149,    13,   151,   153,   156,   159,   160,   162,
     163,   165,   167,   -28,   116,   169,   176,   557,  -257,   146,
       1,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,   146,   146,   -36,   115,    24,   146,
     146,   146,   146,   146,  -257,   143,   146,   130,   143,   125,
     143,   146,   146,   143,   131,   152,   115,   146,   143,   146,
     115,   146,   133,   143,   146,   146,  -257,  -257,   143,   143,
     143,  -257,   127,   136,   143,  -257,  -257,  -257,  -257,  -257,
     143,  -257,  -257,   146,  -257,  -257,   123,   134,  -257,  -257,
     143,    36,   146,  -257,   137,   138,   146,  -257,   146,   146,
     146,   146,   146,  -257,   143,  -257,   143,   146,  -257,   146,
     139,   143,  -257,   143,   142,   179,   146,  -257,   143,   146,
    -257,   146,   180,   144,   181,   115,   182,   183,   187,    71,
     188,   198,   146,   200,   147,   143,   146,   201,   146,   203,
     204,   205,   206,   154,   155,   143,    85,     3,   150,   146,
      91,  -257,  -257,   143,   158,   146,  -257,    25,  -257,   143,
     143,  -257,    53,   157,  -257,   208,   146,  -257,  -257,   146,
    -257,   103,  -257,    87,  -257,   212,   214,    -2,  -257,  -257,
    -257,   217,  -257,  -257,   218,  -257,   166,   219,   221,  -257,
     222,  -257,  -257,  -257,  -257,   146,   146,   143,  -257,    98,
     146,   108,  -257,    14,   171,  -257,   143,   172,   173,  -257,
     143,   143,   226,  -257,   227,   228,  -257,   229,   146,  -257,
     109,   230,   231,   232,    -2,    -2,  -257,  -257,    15,     4,
    -257,  -257,   233,  -257,  -257,  -257,   234,   235,   143,  -257,
     237,   146,  -257,  -257,   146,   184,   197,   191,   199,   243,
     143,  -257,  -257,   146,   143,   146,  -257,   244,   143,   146,
     143,    23,     5,    26,     8,   223,  -257,  -257,  -257,   146,
       3,     3,   245,  -257,   146,   146,     3,   192,   194,   196,
     207,  -257,   143,   146,  -257,   146,   143,   146,  -257,   252,
     253,   255,   223,  -257,   223,  -257,    16,   146,   258,   110,
       3,     3,  -257,  -257,     3,   121,   146,   202,   146,   209,
     143,  -257,   122,   261,  -257,  -257,  -257,    17,    19,  -257,
     263,  -257,  -257,   126,   128,  -257,   268,   272,   273,   274,
     275,  -257,   276,  -257,  -257,  -257,  -257,  -257,  -257,   146,
     146,   143,   143,  -257,  -257,   146,   146,   143,   143
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -257,  -257,  -257,   246,  -257,   211,  -257,   215,  -228,  -180,
    -257,  -191,  -125,  -257,  -257,  -257,  -257,    63,   -54,  -257,
    -257,   107,  -257,  -257,   145,  -257,  -257,   135,  -257,  -257,
    -257,  -257,  -257,   148,  -257,   -34,  -257,    -1,  -148,  -257,
    -257,  -257,  -257,  -111,  -256,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,   -19,  -257,   -39,   260
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     120,   123,   246,   204,   118,   190,   118,   241,   302,   304,
     307,   333,    75,   126,   335,    77,    86,    88,    93,   101,
     284,   305,   359,   374,   127,   375,   266,   267,   118,   332,
     112,   249,   334,   308,   308,   120,   123,   308,   132,   145,
     129,    74,   191,   306,   144,   308,   308,   149,   308,   336,
     240,   306,   158,   161,   306,    79,   118,   165,   167,   253,
     169,   170,   173,   121,    76,   177,   179,    78,    87,    89,
      94,   102,   285,   134,   145,   129,   357,   220,   358,    80,
     135,    81,   196,    82,   187,   196,   196,   196,   145,   129,
      83,   238,    84,   193,   145,   129,    85,   245,    90,   197,
      91,   145,   129,   144,   279,    92,   118,    95,   149,   259,
     202,   118,   118,   118,   282,   296,   362,   158,   128,   129,
     161,   190,   211,    96,   118,   118,   215,   365,   371,   118,
      97,   118,   377,   224,   378,    98,   345,   228,    99,   230,
     261,   262,   263,   139,   140,   141,   145,   129,   242,   118,
     244,   385,   386,   301,   303,   100,   248,   103,   250,   104,
     363,   363,   105,   254,   364,   106,   107,   257,   108,   109,
     258,   110,   260,   111,   113,   114,   115,   164,   204,   150,
     163,   154,   174,   183,   188,   207,   212,   214,   217,   218,
     387,   388,   184,   219,   222,   189,   276,   277,   194,   195,
     203,   281,   283,   206,   223,   213,   225,   229,   226,   231,
     232,   233,   234,   243,   256,   235,   236,   255,   264,   295,
     265,   297,   247,   270,   271,   273,   272,   274,   275,   286,
     287,   288,   291,   292,   293,   294,   298,   299,   300,   309,
     310,   311,   314,   313,   317,   316,   318,   319,   320,   321,
     328,   342,   267,   346,   325,   347,   327,   348,   354,   355,
     330,   356,   190,   190,   361,   367,   210,   373,   349,   376,
     338,   242,   242,   369,   379,   343,   344,   242,   380,   381,
     382,   383,   384,   117,   325,   124,   352,   198,   353,   351,
     125,   208,   341,   326,     0,   201,     0,     0,   360,     0,
     283,   242,   242,     0,     0,   242,   283,   366,     0,   368,
       0,     0,     0,   372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   283,   283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,   316,     0,     0,     0,   146,   344,   344,   153,     0,
     155,     0,     0,   162,     0,     0,   166,     0,   168,     0,
     171,     0,     0,   175,     0,     0,     0,     0,   180,   181,
     182,     0,     0,     0,   185,     0,     0,     0,     0,     0,
     186,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,   200,     0,     0,     0,
       0,   153,     0,   205,     0,     0,     0,     0,   209,     0,
       0,     0,     0,     0,     0,   216,     0,     0,     0,   221,
       0,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   239,     0,     0,     0,
     192,     0,     0,     0,     0,     1,     0,     2,     0,   251,
     252,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,    17,    18,     0,     0,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   278,    35,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     289,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,     0,     0,     0,   153,     0,     0,     0,   329,     0,
     331,     0,     1,     0,     2,     0,     0,   116,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   350,    17,    18,     0,   153,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,     0,     0,     0,     0,
     370
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-257)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      39,    40,   193,   151,     3,   130,     3,   187,   264,   265,
       6,     6,     6,    49,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,    60,     6,    28,    29,     3,     6,
      58,     6,     6,    29,    29,    74,    75,    29,    77,     3,
       4,     6,     6,    28,    83,    29,    29,    86,    29,   305,
      47,    28,    91,    92,    28,     6,     3,    96,    97,     6,
      99,   100,   101,    62,    58,   104,   105,    58,    58,    58,
      58,    58,    58,    49,     3,     4,   332,     6,   334,     6,
      56,     6,   136,     6,   123,   139,   140,   141,     3,     4,
       6,     6,     6,   132,     3,     4,     6,     6,     6,   138,
       6,     3,     4,   142,     6,     6,     3,     6,   147,     6,
     149,     3,     3,     3,     6,     6,     6,   156,     3,     4,
     159,   246,   161,     6,     3,     3,   165,     6,     6,     3,
       6,     3,     6,   172,     6,     6,   316,   176,     6,   178,
      53,    54,    55,    80,    81,    82,     3,     4,   187,     3,
     189,   379,   380,   264,   265,     6,   195,     6,   197,     6,
     340,   341,     6,   202,   344,     6,     6,   206,     6,     6,
     209,     6,   211,     6,    58,     6,     0,    25,   326,    49,
      49,    56,    49,    56,    61,     6,     6,     6,     6,     6,
     381,   382,    56,     6,     6,    61,   235,   236,    61,    61,
      61,   240,   241,    61,     6,    61,     6,     6,    61,     6,
       6,     6,     6,    63,     6,    61,    61,    60,     6,   258,
       6,   260,    64,     6,     6,     6,    60,     6,     6,    58,
      58,    58,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,   281,     6,    60,   284,    49,    56,    49,     6,
       6,     6,    29,    61,   293,    61,   295,    61,     6,     6,
     299,     6,   387,   388,     6,    63,   159,     6,    61,     6,
     309,   310,   311,    64,     6,   314,   315,   316,     6,     6,
       6,     6,     6,    37,   323,    74,   325,   142,   327,   323,
      75,   156,   311,   294,    -1,   147,    -1,    -1,   337,    -1,
     339,   340,   341,    -1,    -1,   344,   345,   346,    -1,   348,
      -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,   364,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     379,   380,    -1,    -1,    -1,    85,   385,   386,    88,    -1,
      90,    -1,    -1,    93,    -1,    -1,    96,    -1,    98,    -1,
     100,    -1,    -1,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   186,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,     5,    -1,     7,    -1,   199,
     200,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   237,    48,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     290,    -1,    -1,    -1,   294,    -1,    -1,    -1,   298,    -1,
     300,    -1,     5,    -1,     7,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   322,    26,    27,    -1,   326,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    -1,    -1,    -1,
     350
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    26,    27,    30,
      31,    32,    33,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    48,    66,    67,    68,    69,
      71,    75,    78,    79,    80,    81,    84,    87,    90,    93,
      94,    95,    96,   101,   104,   105,   106,   107,   110,   111,
     112,   114,   116,   117,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   130,     6,     6,    58,     6,    58,     6,
       6,     6,     6,     6,     6,     6,     6,    58,     6,    58,
       6,     6,     6,     6,    58,     6,     6,     6,     6,     6,
       6,     6,    58,     6,     6,     6,     6,     6,     6,     6,
       6,     6,    58,    58,     6,     0,    10,    68,     3,    70,
     131,    62,    72,   131,    70,    72,    49,    60,     3,     4,
      76,    77,   131,   132,    49,    56,    82,    83,   131,    82,
      82,    82,    88,    89,   131,     3,   132,    97,    98,   131,
      49,   102,   103,   132,    56,   132,    91,    92,   131,    85,
      86,   131,   132,    49,    25,   131,   132,   131,   132,   131,
     131,   132,   118,   131,    49,   132,   113,   131,   115,   131,
     132,   132,   132,    56,    56,   132,   132,   131,    61,    61,
      77,     6,   132,   131,    61,    61,    83,   131,    89,   132,
     132,    98,   131,    61,   103,   132,    61,     6,    92,   132,
      86,   131,     6,    61,     6,   131,   132,     6,     6,     6,
       6,   132,     6,     6,   131,     6,    61,   132,   131,     6,
     131,     6,     6,     6,     6,    61,    61,   132,     6,   132,
      47,    74,   131,    63,   131,     6,    76,    64,   131,     6,
     131,   132,   132,     6,   131,    60,     6,   131,   131,     6,
     131,    53,    54,    55,     6,     6,    28,    29,   108,   109,
       6,     6,    60,     6,     6,     6,   131,   131,   132,     6,
     132,   131,     6,   131,     6,    58,    58,    58,    58,   132,
     132,     6,     6,     6,     6,   131,     6,   131,     6,     6,
       6,   108,   109,   108,   109,     6,    28,     6,    29,     6,
       6,     6,   132,     6,   131,    73,   131,    60,    49,    56,
      49,     6,   132,    99,   100,   131,   102,   131,     6,   132,
     131,   132,     6,     6,     6,     6,   109,   119,   131,    74,
     129,   129,     6,   131,   131,    74,    61,    61,    61,    61,
     132,   100,   131,   131,     6,     6,     6,   109,   109,     6,
     131,     6,     6,    74,    74,     6,   131,    63,   131,    64,
     132,     6,   131,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,    73,    73,    76,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 69 "p.y"
    { 
	   return 0; 
         }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 81 "p.y"
    {if(domain->setDirichlet((yyvsp[(1) - (1)].bclist)->n,(yyvsp[(1) - (1)].bclist)->d)<0) { delete (yyvsp[(1) - (1)].bclist); return -1;   }   }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 83 "p.y"
    {if(domain->setNeuman((yyvsp[(1) - (1)].bclist)->n,(yyvsp[(1) - (1)].bclist)->d)<0){  delete (yyvsp[(1) - (1)].bclist); return -1;    } }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 95 "p.y"
    {if(domain->setfix((yyvsp[(1) - (1)].bcflist)->n, (yyvsp[(1) - (1)].bcflist)->d)<0) {   delete (yyvsp[(1) - (1)].bcflist); return -1;}   }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 118 "p.y"
    { domain->addNode((yyvsp[(3) - (3)].nval).num, (yyvsp[(3) - (3)].nval).xyz); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 120 "p.y"
    { domain->addNode((yyvsp[(2) - (2)].nval).num, (yyvsp[(2) - (2)].nval).xyz); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 124 "p.y"
    { (yyval.nval).num = (yyvsp[(1) - (5)].ival); (yyval.nval).xyz[0] = (yyvsp[(2) - (5)].fval); (yyval.nval).xyz[1] = (yyvsp[(3) - (5)].fval);  (yyval.nval).xyz[2] = (yyvsp[(4) - (5)].fval); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 126 "p.y"
    { (yyval.nval).num = (yyvsp[(1) - (4)].ival); (yyval.nval).xyz[0] = (yyvsp[(2) - (4)].fval); (yyval.nval).xyz[1] = (yyvsp[(3) - (4)].fval);  (yyval.nval).xyz[2] = 0.0; }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 128 "p.y"
    { (yyval.nval).num = (yyvsp[(1) - (3)].ival); (yyval.nval).xyz[0] = (yyvsp[(2) - (3)].fval); (yyval.nval).xyz[1] = 0.0; (yyval.nval).xyz[2] = 0.0; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 132 "p.y"
    {delete (yyvsp[(7) - (7)].nlist);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 134 "p.y"
    {domain->addPart((yyvsp[(9) - (11)].ival), 2 , (yyvsp[(11) - (11)].nlist)->n, (yyvsp[(11) - (11)].nlist)->d);  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 136 "p.y"
    {domain->addPart((yyvsp[(5) - (11)].ival), 2 , (yyvsp[(11) - (11)].nlist)->n, (yyvsp[(11) - (11)].nlist)->d); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 143 "p.y"
    { /* Define each Element */
          domain->addElem((yyvsp[(1) - (4)].ival), (yyvsp[(2) - (4)].ival), (yyvsp[(3) - (4)].nlist)->n, (yyvsp[(3) - (4)].nlist)->d); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 148 "p.y"
    {(yyval.nlist) = new NList;(yyval.nlist)->add((yyvsp[(1) - (3)].ival)); domain->addElem((yyvsp[(1) - (3)].ival), TypeInfo::Solid, (yyvsp[(2) - (3)].nlist)->n,(yyvsp[(2) - (3)].nlist)->d );}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 150 "p.y"
    {(yyval.nlist)->add((yyvsp[(2) - (4)].ival)); domain->addElem((yyvsp[(2) - (4)].ival), TypeInfo::Solid, (yyvsp[(3) - (4)].nlist)->n,(yyvsp[(3) - (4)].nlist)->d );}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 155 "p.y"
    { (yyval.nlist) = new NList; (yyval.nlist)->add((yyvsp[(1) - (1)].ival)) ; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 157 "p.y"
    { (yyval.nlist)->add((yyvsp[(2) - (2)].ival)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 159 "p.y"
    {int i;(yyval.nlist) = new NList;
      for(i=(yyvsp[(2) - (4)].ival); i<(yyvsp[(3) - (4)].ival)+(yyvsp[(4) - (4)].ival); i = i+(yyvsp[(4) - (4)].ival))
      {         (yyval.nlist)->add(i);      }  }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 165 "p.y"
    {domain->addMat((yyvsp[(5) - (11)].ival), 1 , (yyvsp[(11) - (11)].pl)->n,  (yyvsp[(11) - (11)].pl)->d) ; delete (yyvsp[(11) - (11)].pl);    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 167 "p.y"
    {domain->addMat((yyvsp[(9) - (11)].ival), 1 , (yyvsp[(11) - (11)].pl)->n,  (yyvsp[(11) - (11)].pl)->d) ; delete (yyvsp[(11) - (11)].pl);    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 169 "p.y"
    {domain->addMat((yyvsp[(3) - (5)].ival), (yyvsp[(4) - (5)].ival) , (yyvsp[(5) - (5)].pl)->n,  (yyvsp[(5) - (5)].pl)->d) ; delete (yyvsp[(5) - (5)].pl);    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 171 "p.y"
    {domain->addMat(0, 1 , (yyvsp[(3) - (3)].pl)->n,  (yyvsp[(3) - (3)].pl)->d) ; delete (yyvsp[(3) - (3)].pl);    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 175 "p.y"
    {(yyval.pl) = new PropList; (yyval.pl)->add((yyvsp[(1) - (2)].pl));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 177 "p.y"
    { (yyval.pl)->add((yyvsp[(2) - (3)].pl));  }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 180 "p.y"
    { (yyval.pl) = new PropList;(yyval.pl)->add((yyvsp[(1) - (1)].fval)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 182 "p.y"
    { (yyval.pl)->add((yyvsp[(2) - (2)].fval));  }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 186 "p.y"
    { (yyval.bclist) = (yyvsp[(3) - (3)].bclist); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 190 "p.y"
    { (yyval.bclist) = (yyvsp[(3) - (3)].bclist); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 194 "p.y"
    { if(domain->setIVel((yyvsp[(3) - (3)].bclist)->n,(yyvsp[(3) - (3)].bclist)->d) < 0) return -1; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 198 "p.y"
    { if(domain->setIAcc((yyvsp[(3) - (3)].bclist)->n,(yyvsp[(3) - (3)].bclist)->d) < 0) return -1; }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 203 "p.y"
    { (yyval.bclist) = new BCList; (yyval.bclist)->add((yyvsp[(1) - (1)].bcval)); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 205 "p.y"
    { (yyval.bclist) = (yyvsp[(1) - (2)].bclist); (yyval.bclist)->add((yyvsp[(2) - (2)].bcval)); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 209 "p.y"
    { (yyval.bcval).nnum = (yyvsp[(1) - (5)].ival); (yyval.bcval).dofnum = (yyvsp[(2) - (5)].ival); (yyval.bcval).curvenum = (yyvsp[(3) - (5)].ival); (yyval.bcval).val = (yyvsp[(4) - (5)].fval); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 211 "p.y"
    { (yyval.bcval).nnum = (yyvsp[(1) - (3)].ival); (yyval.bcval).dofnum = (yyvsp[(2) - (3)].ival); (yyval.bcval).curvenum = 0; (yyval.bcval).val = 0.0; }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 215 "p.y"
    {(yyval.bcflist)  = (yyvsp[(3) - (3)].bcflist);  }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 219 "p.y"
    { (yyval.bcflist) = new BCFList; (yyval.bcflist)->add((yyvsp[(1) - (1)].bcfix)); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 221 "p.y"
    { (yyval.bcflist) = (yyvsp[(1) - (2)].bcflist); (yyval.bcflist)->add((yyvsp[(2) - (2)].bcfix)); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 225 "p.y"
    { (yyval.bcfix).nnum = (yyvsp[(1) - (5)].ival); (yyval.bcfix).fix[0] = (yyvsp[(2) - (5)].ival); (yyval.bcfix).fix[1] = (yyvsp[(3) - (5)].ival); (yyval.bcfix).fix[2] = (yyvsp[(4) - (5)].ival); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 227 "p.y"
    { (yyval.bcfix).nnum = (yyvsp[(1) - (3)].ival); (yyval.bcfix).fix[0] = (yyvsp[(2) - (3)].ival); (yyval.bcfix).fix[1] = 0; (yyval.bcfix).fix[2] = 0; }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 229 "p.y"
    { (yyval.bcfix).nnum = (yyvsp[(1) - (4)].ival); (yyval.bcfix).fix[0] = (yyvsp[(2) - (4)].ival); (yyval.bcfix).fix[1] = (yyvsp[(3) - (4)].ival); (yyval.bcfix).fix[2] = 0;    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 236 "p.y"
    {domain->setinistress((yyvsp[(1) - (1)].istr).nele, (yyvsp[(1) - (1)].istr).istress);     }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 238 "p.y"
    {domain->setinistress((yyvsp[(2) - (2)].istr).nele, (yyvsp[(2) - (2)].istr).istress);    }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 242 "p.y"
    {(yyval.istr).nele=(yyvsp[(1) - (8)].ival); (yyval.istr).istress[0]=(yyvsp[(2) - (8)].fval); (yyval.istr).istress[1] = (yyvsp[(3) - (8)].fval);
         (yyval.istr).istress[2] = (yyvsp[(4) - (8)].fval); (yyval.istr).istress[3] = (yyvsp[(5) - (8)].fval); (yyval.istr).istress[4] = (yyvsp[(6) - (8)].fval); (yyval.istr).istress[5] = (yyvsp[(7) - (8)].fval);}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 250 "p.y"
    { domain->setpress((yyvsp[(1) - (1)].bp));    }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 252 "p.y"
    { domain->setpress((yyvsp[(2) - (2)].bp));     }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 256 "p.y"
    {(yyval.bp).cnum = (yyvsp[(1) - (7)].ival); (yyval.bp).value = (yyvsp[(2) - (7)].fval); (yyval.bp).nodelist[0] = (yyvsp[(3) - (7)].ival); (yyval.bp).nodelist[1] = (yyvsp[(4) - (7)].ival); (yyval.bp).nodelist[2] = (yyvsp[(5) - (7)].ival); (yyval.bp).nodelist[3] = (yyvsp[(6) - (7)].ival);     }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 261 "p.y"
    {domain->setlarge();     }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 265 "p.y"
    {         domain->sethourglass((yyvsp[(3) - (4)].ival));     }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 267 "p.y"
    {domain->sethourglass((yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].fval));}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 271 "p.y"
    {domain->setgrav((yyvsp[(3) - (6)].fval), (yyvsp[(4) - (6)].fval), (yyvsp[(5) - (6)].fval));     }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 285 "p.y"
    {domain->setatt((yyvsp[(1) - (3)].ival), (yyvsp[(2) - (3)].ival));    }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 287 "p.y"
    { int i;
       for(i=(yyvsp[(1) - (4)].ival); i<(yyvsp[(2) - (4)].ival)+1; ++i)    domain->setatt(i, (yyvsp[(3) - (4)].ival));
       }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 297 "p.y"
    {domain->setpatt((yyvsp[(1) - (3)].ival), (yyvsp[(2) - (3)].ival));    }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 299 "p.y"
    { int i;
       for(i=(yyvsp[(1) - (4)].ival); i<(yyvsp[(2) - (4)].ival)+1; ++i)    domain->setpatt(i, (yyvsp[(3) - (4)].ival));
       }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 305 "p.y"
    {domain->addCurve((yyvsp[(5) - (7)].ival),(yyvsp[(7) - (7)].clist)->n,(yyvsp[(7) - (7)].clist)->d); delete (yyvsp[(7) - (7)].clist);  }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 307 "p.y"
    {domain->addCurve(0,(yyvsp[(3) - (3)].clist)->n,(yyvsp[(3) - (3)].clist)->d); delete (yyvsp[(3) - (3)].clist);      }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 311 "p.y"
    {(yyval.clist) = new CurveTable; (yyval.clist)->add((yyvsp[(1) - (1)].ccoef));}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 313 "p.y"
    {(yyval.clist) = (yyvsp[(1) - (2)].clist); (yyval.clist)->add((yyvsp[(2) - (2)].ccoef));}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 317 "p.y"
    {(yyval.ccoef).coef1 = (yyvsp[(1) - (3)].fval); (yyval.ccoef).coef2 = (yyvsp[(2) - (3)].fval);}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 322 "p.y"
    {domain->setendtime((yyvsp[(3) - (4)].fval));     }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 326 "p.y"
    {domain->settimestep(1,(yyvsp[(3) - (4)].fval));     }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 328 "p.y"
    {domain->settimestep(1,(yyvsp[(7) - (8)].fval));}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 330 "p.y"
    {domain->settimestep(2,(yyvsp[(7) - (8)].fval)); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 332 "p.y"
    {domain->settimestep((yyvsp[(7) - (8)].ival));}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 336 "p.y"
    {domain->solinfo().setProbType(1);}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 340 "p.y"
    { domain->setointer((yyvsp[(3) - (9)].ival),(yyvsp[(4) - (9)].ival)); }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 342 "p.y"
    { domain->setointer((yyvsp[(3) - (9)].ival),(yyvsp[(4) - (9)].fval)); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 344 "p.y"
    { domain->setointer(1,(yyvsp[(3) - (8)].fval)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 346 "p.y"
    { domain->setointer(1,(yyvsp[(3) - (4)].fval)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 348 "p.y"
    { domain->setointer((yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].ival)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 350 "p.y"
    { domain->setointer((yyvsp[(3) - (5)].ival),(yyvsp[(4) - (5)].fval)); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 352 "p.y"
    { domain->setointer((yyvsp[(3) - (7)].ival),(yyvsp[(4) - (7)].ival)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 354 "p.y"
    { domain->setointer((yyvsp[(3) - (7)].ival),(yyvsp[(4) - (7)].fval)); }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 356 "p.y"
    { domain->setointer(1,(yyvsp[(3) - (6)].fval)); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 358 "p.y"
    { domain->setointer((yyvsp[(3) - (7)].ival),(yyvsp[(4) - (7)].ival)); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 360 "p.y"
    { domain->setointer((yyvsp[(3) - (7)].ival),(yyvsp[(4) - (7)].fval)); }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 362 "p.y"
    { domain->setointer(1,(yyvsp[(3) - (6)].fval)); }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 367 "p.y"
    {domain->addnout((yyvsp[(1) - (1)].ival)); }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 369 "p.y"
    { domain->addnout((yyvsp[(2) - (2)].ival)); }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 373 "p.y"
    {domain->addeout((yyvsp[(1) - (1)].ival)); }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 375 "p.y"
    { domain->addeout((yyvsp[(2) - (2)].ival)); }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 379 "p.y"
    {domain->sethisdata((yyvsp[(3) - (4)].ival));}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 383 "p.y"
    {domain->sethisointer((yyvsp[(3) - (4)].fval));}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 390 "p.y"
    {domain->addhisnode((yyvsp[(1) - (2)].ival));     }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 392 "p.y"
    {domain->addhisnode((yyvsp[(2) - (3)].ival));     }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 399 "p.y"
    {domain->addhiselem((yyvsp[(1) - (2)].ival)); }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 401 "p.y"
    {domain->addhiselem((yyvsp[(2) - (3)].ival));}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 405 "p.y"
    {domain->setsinter((yyvsp[(3) - (4)].fval));     }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 407 "p.y"
    {domain->setsinter((yyvsp[(3) - (4)].ival));     }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 415 "p.y"
    {domain->delelem((yyvsp[(1) - (2)].ival));      }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 417 "p.y"
    {domain->delelem((yyvsp[(2) - (3)].ival));}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 421 "p.y"
    {domain->delpart((yyvsp[(1) - (2)].ival));      }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 423 "p.y"
    {domain->delpart((yyvsp[(2) - (3)].ival));}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 428 "p.y"
    {domain->setbulkvisco((yyvsp[(3) - (5)].fval),(yyvsp[(4) - (5)].fval));      }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 432 "p.y"
    {domain->setdebug();}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 436 "p.y"
    {domain->cleardv();}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 440 "p.y"
    {domain->setdamping(1,0.8);  }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 442 "p.y"
    {domain->setdamping(1,(yyvsp[(3) - (4)].fval));}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 446 "p.y"
    {domain->setdamping(2,0.8); }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 448 "p.y"
    {domain->setdamping(2,(yyvsp[(3) - (4)].fval)); }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 452 "p.y"
    {domain->staticterm();  }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 454 "p.y"
    {domain->staticterm((yyvsp[(3) - (4)].fval));}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 458 "p.y"
    {domain->setexportflacflg();}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 462 "p.y"
    {domain->addPart((yyvsp[(5) - (7)].ival), 1 , (yyvsp[(7) - (7)].ptemp));    }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 466 "p.y"
    {domain->addPart((yyvsp[(5) - (7)].ival), 2 , (yyvsp[(7) - (7)].ptemp));     }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 470 "p.y"
    {(yyval.ptemp) = new Part;(yyval.ptemp)->addvect((yyvsp[(1) - (2)].nlist)->n,(yyvsp[(1) - (2)].nlist)->d);}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 472 "p.y"
    {(yyval.ptemp)->addvect((yyvsp[(2) - (3)].nlist)->n,(yyvsp[(2) - (3)].nlist)->d);}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 476 "p.y"
    {domain->setfenqu((yyvsp[(3) - (7)].fval),(yyvsp[(4) - (7)].fval),(yyvsp[(5) - (7)].fval),(yyvsp[(6) - (7)].fval));}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 480 "p.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 484 "p.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].ival); }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 486 "p.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].fval); }
    break;


/* Line 1792 of yacc.c  */
#line 2563 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 487 "p.y"

