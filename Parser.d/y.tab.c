/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "p.y" /* yacc.c:337  */

#include <stdio.h>
#include <stdlib.h>
#include "../Parser.d/auxx.h"
 int numColumns = 3;
 double amplitude = 1.0;

extern Domain *domain;
extern int yylex();
extern void yyerror(const char *);


#line 83 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
#line 16 "p.y" /* yacc.c:352  */

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


#line 273 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  389

#define YYUNDEFTOK  2
#define YYMAXUTOK   319

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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
  "NodePart", "ElemPart", "PartList", "FenQu", "Integer", "Float", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -257

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-257)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 69 "p.y" /* yacc.c:1652  */
    { 
	   return 0; 
         }
#line 1684 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 81 "p.y" /* yacc.c:1652  */
    {if(domain->setDirichlet((yyvsp[0].bclist)->n,(yyvsp[0].bclist)->d)<0) { delete (yyvsp[0].bclist); return -1;   }   }
#line 1690 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 83 "p.y" /* yacc.c:1652  */
    {if(domain->setNeuman((yyvsp[0].bclist)->n,(yyvsp[0].bclist)->d)<0){  delete (yyvsp[0].bclist); return -1;    } }
#line 1696 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 95 "p.y" /* yacc.c:1652  */
    {if(domain->setfix((yyvsp[0].bcflist)->n, (yyvsp[0].bcflist)->d)<0) {   delete (yyvsp[0].bcflist); return -1;}   }
#line 1702 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 118 "p.y" /* yacc.c:1652  */
    { domain->addNode((yyvsp[0].nval).num, (yyvsp[0].nval).xyz); }
#line 1708 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 120 "p.y" /* yacc.c:1652  */
    { domain->addNode((yyvsp[0].nval).num, (yyvsp[0].nval).xyz); }
#line 1714 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 124 "p.y" /* yacc.c:1652  */
    { (yyval.nval).num = (yyvsp[-4].ival); (yyval.nval).xyz[0] = (yyvsp[-3].fval); (yyval.nval).xyz[1] = (yyvsp[-2].fval);  (yyval.nval).xyz[2] = (yyvsp[-1].fval); }
#line 1720 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 126 "p.y" /* yacc.c:1652  */
    { (yyval.nval).num = (yyvsp[-3].ival); (yyval.nval).xyz[0] = (yyvsp[-2].fval); (yyval.nval).xyz[1] = (yyvsp[-1].fval);  (yyval.nval).xyz[2] = 0.0; }
#line 1726 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 128 "p.y" /* yacc.c:1652  */
    { (yyval.nval).num = (yyvsp[-2].ival); (yyval.nval).xyz[0] = (yyvsp[-1].fval); (yyval.nval).xyz[1] = 0.0; (yyval.nval).xyz[2] = 0.0; }
#line 1732 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 132 "p.y" /* yacc.c:1652  */
    {delete (yyvsp[0].nlist);}
#line 1738 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 134 "p.y" /* yacc.c:1652  */
    {domain->addPart((yyvsp[-2].ival), 2 , (yyvsp[0].nlist)->n, (yyvsp[0].nlist)->d);  }
#line 1744 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 136 "p.y" /* yacc.c:1652  */
    {domain->addPart((yyvsp[-6].ival), 2 , (yyvsp[0].nlist)->n, (yyvsp[0].nlist)->d); }
#line 1750 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 143 "p.y" /* yacc.c:1652  */
    { /* Define each Element */
          domain->addElem((yyvsp[-3].ival), (yyvsp[-2].ival), (yyvsp[-1].nlist)->n, (yyvsp[-1].nlist)->d); }
#line 1757 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 148 "p.y" /* yacc.c:1652  */
    {(yyval.nlist) = new NList;(yyval.nlist)->add((yyvsp[-2].ival)); domain->addElem((yyvsp[-2].ival), TypeInfo::Solid, (yyvsp[-1].nlist)->n,(yyvsp[-1].nlist)->d );}
#line 1763 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 150 "p.y" /* yacc.c:1652  */
    {(yyval.nlist)->add((yyvsp[-2].ival)); domain->addElem((yyvsp[-2].ival), TypeInfo::Solid, (yyvsp[-1].nlist)->n,(yyvsp[-1].nlist)->d );}
#line 1769 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 155 "p.y" /* yacc.c:1652  */
    { (yyval.nlist) = new NList; (yyval.nlist)->add((yyvsp[0].ival)) ; }
#line 1775 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 157 "p.y" /* yacc.c:1652  */
    { (yyval.nlist)->add((yyvsp[0].ival)); }
#line 1781 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 159 "p.y" /* yacc.c:1652  */
    {int i;(yyval.nlist) = new NList;
      for(i=(yyvsp[-2].ival); i<(yyvsp[-1].ival)+(yyvsp[0].ival); i = i+(yyvsp[0].ival))
      {         (yyval.nlist)->add(i);      }  }
#line 1789 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 165 "p.y" /* yacc.c:1652  */
    {domain->addMat((yyvsp[-6].ival), 1 , (yyvsp[0].pl)->n,  (yyvsp[0].pl)->d) ; delete (yyvsp[0].pl);    }
#line 1795 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 167 "p.y" /* yacc.c:1652  */
    {domain->addMat((yyvsp[-2].ival), 1 , (yyvsp[0].pl)->n,  (yyvsp[0].pl)->d) ; delete (yyvsp[0].pl);    }
#line 1801 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 169 "p.y" /* yacc.c:1652  */
    {domain->addMat((yyvsp[-2].ival), (yyvsp[-1].ival) , (yyvsp[0].pl)->n,  (yyvsp[0].pl)->d) ; delete (yyvsp[0].pl);    }
#line 1807 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 171 "p.y" /* yacc.c:1652  */
    {domain->addMat(0, 1 , (yyvsp[0].pl)->n,  (yyvsp[0].pl)->d) ; delete (yyvsp[0].pl);    }
#line 1813 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 175 "p.y" /* yacc.c:1652  */
    {(yyval.pl) = new PropList; (yyval.pl)->add((yyvsp[-1].pl));}
#line 1819 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 177 "p.y" /* yacc.c:1652  */
    { (yyval.pl)->add((yyvsp[-1].pl));  }
#line 1825 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 180 "p.y" /* yacc.c:1652  */
    { (yyval.pl) = new PropList;(yyval.pl)->add((yyvsp[0].fval)); }
#line 1831 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 182 "p.y" /* yacc.c:1652  */
    { (yyval.pl)->add((yyvsp[0].fval));  }
#line 1837 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 186 "p.y" /* yacc.c:1652  */
    { (yyval.bclist) = (yyvsp[0].bclist); }
#line 1843 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 190 "p.y" /* yacc.c:1652  */
    { (yyval.bclist) = (yyvsp[0].bclist); }
#line 1849 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 194 "p.y" /* yacc.c:1652  */
    { if(domain->setIVel((yyvsp[0].bclist)->n,(yyvsp[0].bclist)->d) < 0) return -1; }
#line 1855 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 198 "p.y" /* yacc.c:1652  */
    { if(domain->setIAcc((yyvsp[0].bclist)->n,(yyvsp[0].bclist)->d) < 0) return -1; }
#line 1861 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 203 "p.y" /* yacc.c:1652  */
    { (yyval.bclist) = new BCList; (yyval.bclist)->add((yyvsp[0].bcval)); }
#line 1867 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 205 "p.y" /* yacc.c:1652  */
    { (yyval.bclist) = (yyvsp[-1].bclist); (yyval.bclist)->add((yyvsp[0].bcval)); }
#line 1873 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 209 "p.y" /* yacc.c:1652  */
    { (yyval.bcval).nnum = (yyvsp[-4].ival); (yyval.bcval).dofnum = (yyvsp[-3].ival); (yyval.bcval).curvenum = (yyvsp[-2].ival); (yyval.bcval).val = (yyvsp[-1].fval); }
#line 1879 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 211 "p.y" /* yacc.c:1652  */
    { (yyval.bcval).nnum = (yyvsp[-2].ival); (yyval.bcval).dofnum = (yyvsp[-1].ival); (yyval.bcval).curvenum = 0; (yyval.bcval).val = 0.0; }
#line 1885 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 215 "p.y" /* yacc.c:1652  */
    {(yyval.bcflist)  = (yyvsp[0].bcflist);  }
#line 1891 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 219 "p.y" /* yacc.c:1652  */
    { (yyval.bcflist) = new BCFList; (yyval.bcflist)->add((yyvsp[0].bcfix)); }
#line 1897 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 221 "p.y" /* yacc.c:1652  */
    { (yyval.bcflist) = (yyvsp[-1].bcflist); (yyval.bcflist)->add((yyvsp[0].bcfix)); }
#line 1903 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 225 "p.y" /* yacc.c:1652  */
    { (yyval.bcfix).nnum = (yyvsp[-4].ival); (yyval.bcfix).fix[0] = (yyvsp[-3].ival); (yyval.bcfix).fix[1] = (yyvsp[-2].ival); (yyval.bcfix).fix[2] = (yyvsp[-1].ival); }
#line 1909 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 227 "p.y" /* yacc.c:1652  */
    { (yyval.bcfix).nnum = (yyvsp[-2].ival); (yyval.bcfix).fix[0] = (yyvsp[-1].ival); (yyval.bcfix).fix[1] = 0; (yyval.bcfix).fix[2] = 0; }
#line 1915 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 229 "p.y" /* yacc.c:1652  */
    { (yyval.bcfix).nnum = (yyvsp[-3].ival); (yyval.bcfix).fix[0] = (yyvsp[-2].ival); (yyval.bcfix).fix[1] = (yyvsp[-1].ival); (yyval.bcfix).fix[2] = 0;    }
#line 1921 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 236 "p.y" /* yacc.c:1652  */
    {domain->setinistress((yyvsp[0].istr).nele, (yyvsp[0].istr).istress);     }
#line 1927 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 238 "p.y" /* yacc.c:1652  */
    {domain->setinistress((yyvsp[0].istr).nele, (yyvsp[0].istr).istress);    }
#line 1933 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 242 "p.y" /* yacc.c:1652  */
    {(yyval.istr).nele=(yyvsp[-7].ival); (yyval.istr).istress[0]=(yyvsp[-6].fval); (yyval.istr).istress[1] = (yyvsp[-5].fval);
         (yyval.istr).istress[2] = (yyvsp[-4].fval); (yyval.istr).istress[3] = (yyvsp[-3].fval); (yyval.istr).istress[4] = (yyvsp[-2].fval); (yyval.istr).istress[5] = (yyvsp[-1].fval);}
#line 1940 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 250 "p.y" /* yacc.c:1652  */
    { domain->setpress((yyvsp[0].bp));    }
#line 1946 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 252 "p.y" /* yacc.c:1652  */
    { domain->setpress((yyvsp[0].bp));     }
#line 1952 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 256 "p.y" /* yacc.c:1652  */
    {(yyval.bp).cnum = (yyvsp[-6].ival); (yyval.bp).value = (yyvsp[-5].fval); (yyval.bp).nodelist[0] = (yyvsp[-4].ival); (yyval.bp).nodelist[1] = (yyvsp[-3].ival); (yyval.bp).nodelist[2] = (yyvsp[-2].ival); (yyval.bp).nodelist[3] = (yyvsp[-1].ival);     }
#line 1958 "y.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 261 "p.y" /* yacc.c:1652  */
    {domain->setlarge();     }
#line 1964 "y.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 265 "p.y" /* yacc.c:1652  */
    {         domain->sethourglass((yyvsp[-1].ival));     }
#line 1970 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 267 "p.y" /* yacc.c:1652  */
    {domain->sethourglass((yyvsp[-2].ival),(yyvsp[-1].fval));}
#line 1976 "y.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 271 "p.y" /* yacc.c:1652  */
    {domain->setgrav((yyvsp[-3].fval), (yyvsp[-2].fval), (yyvsp[-1].fval));     }
#line 1982 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 285 "p.y" /* yacc.c:1652  */
    {domain->setatt((yyvsp[-2].ival), (yyvsp[-1].ival));    }
#line 1988 "y.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 287 "p.y" /* yacc.c:1652  */
    { int i;
       for(i=(yyvsp[-3].ival); i<(yyvsp[-2].ival)+1; ++i)    domain->setatt(i, (yyvsp[-1].ival));
       }
#line 1996 "y.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 297 "p.y" /* yacc.c:1652  */
    {domain->setpatt((yyvsp[-2].ival), (yyvsp[-1].ival));    }
#line 2002 "y.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 299 "p.y" /* yacc.c:1652  */
    { int i;
       for(i=(yyvsp[-3].ival); i<(yyvsp[-2].ival)+1; ++i)    domain->setpatt(i, (yyvsp[-1].ival));
       }
#line 2010 "y.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 305 "p.y" /* yacc.c:1652  */
    {domain->addCurve((yyvsp[-2].ival),(yyvsp[0].clist)->n,(yyvsp[0].clist)->d); delete (yyvsp[0].clist);  }
#line 2016 "y.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 307 "p.y" /* yacc.c:1652  */
    {domain->addCurve(0,(yyvsp[0].clist)->n,(yyvsp[0].clist)->d); delete (yyvsp[0].clist);      }
#line 2022 "y.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 311 "p.y" /* yacc.c:1652  */
    {(yyval.clist) = new CurveTable; (yyval.clist)->add((yyvsp[0].ccoef));}
#line 2028 "y.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 313 "p.y" /* yacc.c:1652  */
    {(yyval.clist) = (yyvsp[-1].clist); (yyval.clist)->add((yyvsp[0].ccoef));}
#line 2034 "y.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 317 "p.y" /* yacc.c:1652  */
    {(yyval.ccoef).coef1 = (yyvsp[-2].fval); (yyval.ccoef).coef2 = (yyvsp[-1].fval);}
#line 2040 "y.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 322 "p.y" /* yacc.c:1652  */
    {domain->setendtime((yyvsp[-1].fval));     }
#line 2046 "y.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 326 "p.y" /* yacc.c:1652  */
    {domain->settimestep(1,(yyvsp[-1].fval));     }
#line 2052 "y.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 328 "p.y" /* yacc.c:1652  */
    {domain->settimestep(1,(yyvsp[-1].fval));}
#line 2058 "y.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 330 "p.y" /* yacc.c:1652  */
    {domain->settimestep(2,(yyvsp[-1].fval)); }
#line 2064 "y.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 332 "p.y" /* yacc.c:1652  */
    {domain->settimestep((yyvsp[-1].ival));}
#line 2070 "y.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 336 "p.y" /* yacc.c:1652  */
    {domain->solinfo().setProbType(1);}
#line 2076 "y.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 340 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-6].ival),(yyvsp[-5].ival)); }
#line 2082 "y.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 342 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-6].ival),(yyvsp[-5].fval)); }
#line 2088 "y.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 344 "p.y" /* yacc.c:1652  */
    { domain->setointer(1,(yyvsp[-5].fval)); }
#line 2094 "y.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 346 "p.y" /* yacc.c:1652  */
    { domain->setointer(1,(yyvsp[-1].fval)); }
#line 2100 "y.tab.c" /* yacc.c:1652  */
    break;

  case 117:
#line 348 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-2].ival),(yyvsp[-1].ival)); }
#line 2106 "y.tab.c" /* yacc.c:1652  */
    break;

  case 118:
#line 350 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-2].ival),(yyvsp[-1].fval)); }
#line 2112 "y.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 352 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-4].ival),(yyvsp[-3].ival)); }
#line 2118 "y.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 354 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-4].ival),(yyvsp[-3].fval)); }
#line 2124 "y.tab.c" /* yacc.c:1652  */
    break;

  case 121:
#line 356 "p.y" /* yacc.c:1652  */
    { domain->setointer(1,(yyvsp[-3].fval)); }
#line 2130 "y.tab.c" /* yacc.c:1652  */
    break;

  case 122:
#line 358 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-4].ival),(yyvsp[-3].ival)); }
#line 2136 "y.tab.c" /* yacc.c:1652  */
    break;

  case 123:
#line 360 "p.y" /* yacc.c:1652  */
    { domain->setointer((yyvsp[-4].ival),(yyvsp[-3].fval)); }
#line 2142 "y.tab.c" /* yacc.c:1652  */
    break;

  case 124:
#line 362 "p.y" /* yacc.c:1652  */
    { domain->setointer(1,(yyvsp[-3].fval)); }
#line 2148 "y.tab.c" /* yacc.c:1652  */
    break;

  case 125:
#line 367 "p.y" /* yacc.c:1652  */
    {domain->addnout((yyvsp[0].ival)); }
#line 2154 "y.tab.c" /* yacc.c:1652  */
    break;

  case 126:
#line 369 "p.y" /* yacc.c:1652  */
    { domain->addnout((yyvsp[0].ival)); }
#line 2160 "y.tab.c" /* yacc.c:1652  */
    break;

  case 127:
#line 373 "p.y" /* yacc.c:1652  */
    {domain->addeout((yyvsp[0].ival)); }
#line 2166 "y.tab.c" /* yacc.c:1652  */
    break;

  case 128:
#line 375 "p.y" /* yacc.c:1652  */
    { domain->addeout((yyvsp[0].ival)); }
#line 2172 "y.tab.c" /* yacc.c:1652  */
    break;

  case 130:
#line 379 "p.y" /* yacc.c:1652  */
    {domain->sethisdata((yyvsp[-1].ival));}
#line 2178 "y.tab.c" /* yacc.c:1652  */
    break;

  case 131:
#line 383 "p.y" /* yacc.c:1652  */
    {domain->sethisointer((yyvsp[-1].fval));}
#line 2184 "y.tab.c" /* yacc.c:1652  */
    break;

  case 133:
#line 390 "p.y" /* yacc.c:1652  */
    {domain->addhisnode((yyvsp[-1].ival));     }
#line 2190 "y.tab.c" /* yacc.c:1652  */
    break;

  case 134:
#line 392 "p.y" /* yacc.c:1652  */
    {domain->addhisnode((yyvsp[-1].ival));     }
#line 2196 "y.tab.c" /* yacc.c:1652  */
    break;

  case 136:
#line 399 "p.y" /* yacc.c:1652  */
    {domain->addhiselem((yyvsp[-1].ival)); }
#line 2202 "y.tab.c" /* yacc.c:1652  */
    break;

  case 137:
#line 401 "p.y" /* yacc.c:1652  */
    {domain->addhiselem((yyvsp[-1].ival));}
#line 2208 "y.tab.c" /* yacc.c:1652  */
    break;

  case 138:
#line 405 "p.y" /* yacc.c:1652  */
    {domain->setsinter((yyvsp[-1].fval));     }
#line 2214 "y.tab.c" /* yacc.c:1652  */
    break;

  case 139:
#line 407 "p.y" /* yacc.c:1652  */
    {domain->setsinter((yyvsp[-1].ival));     }
#line 2220 "y.tab.c" /* yacc.c:1652  */
    break;

  case 142:
#line 415 "p.y" /* yacc.c:1652  */
    {domain->delelem((yyvsp[-1].ival));      }
#line 2226 "y.tab.c" /* yacc.c:1652  */
    break;

  case 143:
#line 417 "p.y" /* yacc.c:1652  */
    {domain->delelem((yyvsp[-1].ival));}
#line 2232 "y.tab.c" /* yacc.c:1652  */
    break;

  case 144:
#line 421 "p.y" /* yacc.c:1652  */
    {domain->delpart((yyvsp[-1].ival));      }
#line 2238 "y.tab.c" /* yacc.c:1652  */
    break;

  case 145:
#line 423 "p.y" /* yacc.c:1652  */
    {domain->delpart((yyvsp[-1].ival));}
#line 2244 "y.tab.c" /* yacc.c:1652  */
    break;

  case 146:
#line 428 "p.y" /* yacc.c:1652  */
    {domain->setbulkvisco((yyvsp[-2].fval),(yyvsp[-1].fval));      }
#line 2250 "y.tab.c" /* yacc.c:1652  */
    break;

  case 147:
#line 432 "p.y" /* yacc.c:1652  */
    {domain->setdebug();}
#line 2256 "y.tab.c" /* yacc.c:1652  */
    break;

  case 148:
#line 436 "p.y" /* yacc.c:1652  */
    {domain->cleardv();}
#line 2262 "y.tab.c" /* yacc.c:1652  */
    break;

  case 149:
#line 440 "p.y" /* yacc.c:1652  */
    {domain->setdamping(1,0.8);  }
#line 2268 "y.tab.c" /* yacc.c:1652  */
    break;

  case 150:
#line 442 "p.y" /* yacc.c:1652  */
    {domain->setdamping(1,(yyvsp[-1].fval));}
#line 2274 "y.tab.c" /* yacc.c:1652  */
    break;

  case 151:
#line 446 "p.y" /* yacc.c:1652  */
    {domain->setdamping(2,0.8); }
#line 2280 "y.tab.c" /* yacc.c:1652  */
    break;

  case 152:
#line 448 "p.y" /* yacc.c:1652  */
    {domain->setdamping(2,(yyvsp[-1].fval)); }
#line 2286 "y.tab.c" /* yacc.c:1652  */
    break;

  case 153:
#line 452 "p.y" /* yacc.c:1652  */
    {domain->staticterm();  }
#line 2292 "y.tab.c" /* yacc.c:1652  */
    break;

  case 154:
#line 454 "p.y" /* yacc.c:1652  */
    {domain->staticterm((yyvsp[-1].fval));}
#line 2298 "y.tab.c" /* yacc.c:1652  */
    break;

  case 155:
#line 458 "p.y" /* yacc.c:1652  */
    {domain->setexportflacflg();}
#line 2304 "y.tab.c" /* yacc.c:1652  */
    break;

  case 156:
#line 462 "p.y" /* yacc.c:1652  */
    {domain->addPart((yyvsp[-2].ival), 1 , (yyvsp[0].ptemp));    }
#line 2310 "y.tab.c" /* yacc.c:1652  */
    break;

  case 157:
#line 466 "p.y" /* yacc.c:1652  */
    {domain->addPart((yyvsp[-2].ival), 2 , (yyvsp[0].ptemp));     }
#line 2316 "y.tab.c" /* yacc.c:1652  */
    break;

  case 158:
#line 470 "p.y" /* yacc.c:1652  */
    {(yyval.ptemp) = new Part;(yyval.ptemp)->addvect((yyvsp[-1].nlist)->n,(yyvsp[-1].nlist)->d);}
#line 2322 "y.tab.c" /* yacc.c:1652  */
    break;

  case 159:
#line 472 "p.y" /* yacc.c:1652  */
    {(yyval.ptemp)->addvect((yyvsp[-1].nlist)->n,(yyvsp[-1].nlist)->d);}
#line 2328 "y.tab.c" /* yacc.c:1652  */
    break;

  case 160:
#line 476 "p.y" /* yacc.c:1652  */
    {domain->setfenqu((yyvsp[-4].fval),(yyvsp[-3].fval),(yyvsp[-2].fval),(yyvsp[-1].fval));}
#line 2334 "y.tab.c" /* yacc.c:1652  */
    break;

  case 161:
#line 480 "p.y" /* yacc.c:1652  */
    { (yyval.ival) = (yyvsp[0].ival); }
#line 2340 "y.tab.c" /* yacc.c:1652  */
    break;

  case 162:
#line 484 "p.y" /* yacc.c:1652  */
    { (yyval.fval) = (yyvsp[0].ival); }
#line 2346 "y.tab.c" /* yacc.c:1652  */
    break;

  case 163:
#line 486 "p.y" /* yacc.c:1652  */
    { (yyval.fval) = (yyvsp[0].fval); }
#line 2352 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2356 "y.tab.c" /* yacc.c:1652  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 487 "p.y" /* yacc.c:1918  */

