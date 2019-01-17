/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

        #define YYSTYPE std::string
        #include <algorithm>
        #include <cstdio>
        #include <stdio.h>
        #include <iostream>
        #include <fstream>
        #include <string>
        #include <deque>
        #include <stack>
        #include <vector>
        #include "functions.h"

        int yylex();
        extern int yylineno;
        void yyerror(char const *s);
        vector<string> output;
        vector<variable> variables;
        vector<variable> forIterators;
        vector<long long int> whilejumps;
        vector<long long int> ifjumps;
        vector<long long int> forjumps;
        bool assign=true;
        long long int currentIndex=0;
        long long int k=0;
        bool write=false;
        bool table=false;

        void loadToRegister(string s, string place,string tableIndex);
        void addToOutPut(string s);
        void storeInMemoryFromRegister(string s, string place, string tableIndex);

        void storeInMemoryIterator(string s,string place);
        void loadLastIterator();
        void storeInMemoryIterator2(string s,string place);
        void loadLastIterator2();

        string decToBin(long long int n);
        void addToRegisterValue(long long int n,string place);

        string ideName[2] = {"-1", "-1"};
        string ideIndex[2] = {"-1", "-1"};

        string tableAssignIndex = "-1";
        string assignIDE="";
   

#line 114 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    NUM = 258,
    IDE = 259,
    DECLARE = 260,
    IN = 261,
    END = 262,
    IF = 263,
    THEN = 264,
    ELSE = 265,
    ENDIF = 266,
    WHILE = 267,
    DO = 268,
    ENDWHILE = 269,
    ENDDO = 270,
    FOR = 271,
    FROM = 272,
    ENDFOR = 273,
    WRITE = 274,
    READ = 275,
    SEM = 276,
    TO = 277,
    DOWNTO = 278,
    LB = 279,
    RB = 280,
    ASSIGN = 281,
    EQ = 282,
    LT = 283,
    GT = 284,
    LE = 285,
    GE = 286,
    NE = 287,
    ADD = 288,
    SUB = 289,
    MUL = 290,
    DIV = 291,
    MOD = 292,
    COLON = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "parser.tab.c" /* yacc.c:358  */

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
# elif ! defined YYSIZE_T
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    69,    69,    86,   111,   115,   116,   119,
     119,   128,   128,   128,   132,   132,   141,   141,   141,   148,
     148,   173,   173,   183,   183,   198,   198,   219,   219,   242,
     242,   250,   250,   260,   266,   271,   280,   289,   307,   328,
     350,   368,   381,   391,   400,   411,   423,   431,   434,   459,
     498
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "IDE", "DECLARE", "IN", "END",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "ENDDO", "FOR",
  "FROM", "ENDFOR", "WRITE", "READ", "SEM", "TO", "DOWNTO", "LB", "RB",
  "ASSIGN", "EQ", "LT", "GT", "LE", "GE", "NE", "ADD", "SUB", "MUL", "DIV",
  "MOD", "COLON", "$accept", "program", "declarations", "$@1", "commands",
  "command", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "forend", "$@11", "$@12", "whilecond", "$@13", "ifend", "$@14",
  "expression", "condition", "value", "identifier", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -23

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-23)))

#define YYTABLE_NINF -18

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -23,    24,    -2,   -23,   -16,   106,    29,     6,    14,
     -23,   -23,   -23,    32,   -23,   -23,    21,   -23,   -23,    16,
       7,   -23,     3,    12,    12,   106,   -23,    12,    40,   -23,
     -23,    34,   -23,    46,    25,    26,   -23,   -23,    41,   -23,
     -23,   106,    36,    33,    45,   106,    12,    37,   -23,   -23,
      52,    12,    12,    12,    12,    12,    12,    50,    12,   -23,
     -23,    44,    53,   130,    56,   106,   -23,   -23,   -23,   -23,
     -23,   -23,    66,     8,   -23,   -23,    12,    12,    12,    12,
      12,   -23,     1,   -23,    12,    12,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,    69,    70,   106,   -23,   -23,
     104,   106,   106,   -23,   129,   142,   -23,   -23
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     0,     0,     1,     3,     0,     0,     0,    48,
      11,    29,    16,     0,    23,    21,     0,     8,    14,     0,
       0,     4,     0,     0,     0,     0,    19,     0,     0,     2,
       7,     0,     9,     0,     0,     0,    46,    12,     0,    47,
      30,     0,     0,     0,     0,     0,     0,     0,    50,    49,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    24,
      22,     0,     0,    34,     0,     0,    40,    42,    43,    44,
      45,    41,     0,     0,    15,    10,     0,     0,     0,     0,
       0,     5,     0,    18,     0,     0,    20,    35,    36,    37,
      38,    39,    31,    33,    13,     0,     0,     0,    25,    27,
       0,     0,     0,    32,     0,     0,    26,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,   -23,   -23,   -22,   -15,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,    43,   -23,
     -23,   -23,   -23,    62,    51,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     8,    16,    17,    46,    23,    50,    31,
      25,    72,    42,    28,    27,    86,   101,   102,    18,    24,
      94,    97,    62,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    30,     5,    41,     6,     9,    34,    35,     7,    10,
      19,    92,    93,    11,    12,    36,     9,    13,     1,    19,
      14,    15,    44,    61,     4,     9,    30,    21,    29,    10,
      84,    85,    20,    11,    12,    19,    26,    13,    22,    19,
      14,    15,    32,    82,     9,    33,    30,    45,     9,    47,
      48,    49,    10,    58,    59,    19,    11,    12,    74,    19,
      13,    65,    64,    14,    15,   -17,    60,    30,    51,    52,
      53,    54,    55,    56,    75,   100,    19,    81,    43,   104,
     105,    83,    98,    99,    57,    30,    40,     0,     0,    30,
      30,    19,     0,     0,    19,    19,    19,    63,    19,    19,
       0,     0,    66,    67,    68,    69,    70,    71,     9,    73,
       9,     0,    10,     0,    10,   103,    11,    12,    11,    12,
      13,     0,    13,    14,    15,    14,    15,    87,    88,    89,
      90,    91,     0,     9,     0,    95,    96,    10,     0,     0,
       0,    11,    12,     0,     0,    13,     9,   106,    14,    15,
      10,     0,     0,     0,    11,    12,     0,     0,    13,     0,
     107,    14,    15,    76,    77,    78,    79,    80
};

static const yytype_int8 yycheck[] =
{
       6,    16,     4,    25,     6,     4,     3,     4,    24,     8,
      16,    10,    11,    12,    13,     3,     4,    16,     5,    25,
      19,    20,    28,    45,     0,     4,    41,    21,     7,     8,
      22,    23,     3,    12,    13,    41,     4,    16,    24,    45,
      19,    20,    26,    65,     4,    38,    61,    13,     4,     3,
      25,    25,     8,    17,    21,    61,    12,    13,    14,    65,
      16,     9,    25,    19,    20,    15,    21,    82,    27,    28,
      29,    30,    31,    32,    21,    97,    82,    21,    27,   101,
     102,    15,    13,    13,    41,   100,    24,    -1,    -1,   104,
     105,    97,    -1,    -1,   100,   101,   102,    46,   104,   105,
      -1,    -1,    51,    52,    53,    54,    55,    56,     4,    58,
       4,    -1,     8,    -1,     8,    11,    12,    13,    12,    13,
      16,    -1,    16,    19,    20,    19,    20,    76,    77,    78,
      79,    80,    -1,     4,    -1,    84,    85,     8,    -1,    -1,
      -1,    12,    13,    -1,    -1,    16,     4,    18,    19,    20,
       8,    -1,    -1,    -1,    12,    13,    -1,    -1,    16,    -1,
      18,    19,    20,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    40,    41,     0,     4,     6,    24,    42,     4,
       8,    12,    13,    16,    19,    20,    43,    44,    57,    64,
       3,    21,    24,    46,    58,    49,     4,    53,    52,     7,
      44,    48,    26,    38,     3,     4,     3,    62,    63,    64,
      62,    43,    51,    63,    64,    13,    45,     3,    25,    25,
      47,    27,    28,    29,    30,    31,    32,    57,    17,    21,
      21,    43,    61,    63,    25,     9,    63,    63,    63,    63,
      63,    63,    50,    63,    14,    21,    33,    34,    35,    36,
      37,    21,    43,    15,    22,    23,    54,    63,    63,    63,
      63,    63,    10,    11,    59,    63,    63,    60,    13,    13,
      43,    55,    56,    11,    43,    43,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    42,    41,    41,    41,    43,    43,    45,
      44,    46,    47,    44,    48,    44,    49,    50,    44,    51,
      44,    52,    44,    53,    44,    55,    54,    56,    54,    58,
      57,    60,    59,    59,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     4,     8,     0,     2,     1,     0,
       5,     0,     0,     7,     0,     5,     0,     0,     6,     0,
       6,     0,     4,     0,     4,     0,     6,     0,     6,     0,
       3,     0,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     4,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
| yyreduce -- Do a reduction.  |
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
#line 64 "parser.y" /* yacc.c:1646  */
    {
                                    addToOutPut("HALT");}
#line 1364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 69 "parser.y" /* yacc.c:1646  */
    {      
                                if(myfind(variables, (yyvsp[0])) == -1){
                                        variable var; 
                                        var.name = (yyvsp[0]);
                                        var.initialized=false; 
                                        var.beginIndex= -1;
                                        var.endIndex= -1;
                                        var.table=false;
                                        var.memBeginIndex=currentIndex;
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        variables.push_back(var);
                                } else {
                                        cout << "Błąd, użyto już" << (yyvsp[0]) << "do deklaracji."<<endl;
                                        exit(1);
                                }
                        }
#line 1386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "parser.y" /* yacc.c:1646  */
    {
                                long long int begin=atoll((yyvsp[-4]).c_str());
                                long long int end=atoll((yyvsp[-2]).c_str());
                                if(begin>end){
                                cout << "Błąd, niewłaściwy zakres tablicy " << (yyvsp[-6]) << endl;
                                    exit(1);
                                }
                                if(myfind(variables, (yyvsp[-6])) == -1){
                                        variable var; 
                                        var.name = (yyvsp[-6]);
                                        var.initialized=false;
                                        var.table=true;
                                        var.beginIndex=begin;
                                        var.endIndex=end;
                                        var.memBeginIndex=currentIndex;
                                        currentIndex=currentIndex+(end-begin);
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        variables.push_back(var);

                                } else {
                                        cout << "Błąd, użyto już" << (yyvsp[-6]) << "do deklaracji."<<endl;
                                        exit(1);
                                }
      }
#line 1416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "parser.y" /* yacc.c:1646  */
    {assign=false;}
#line 1422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "parser.y" /* yacc.c:1646  */
    {   
                                                        long long int index=myfind(variables, (yyvsp[-4]));
                                                        if(variables[index].table==false){
                                                        variables[index].initialized=true;
                                                        } 
                                                        storeInMemoryFromRegister((yyvsp[-4]),"D",tableAssignIndex);
                                                       // tableAssignIndex="-1";     
                                                        assign=true;
                                                }
#line 1436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "parser.y" /* yacc.c:1646  */
    {assign=false;}
#line 1442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "parser.y" /* yacc.c:1646  */
    {assign=true;
                                        ifjumps.push_back(k);
                                        addToOutPut("JZERO D ");
                                        }
#line 1451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "parser.y" /* yacc.c:1646  */
    {
                                                whilejumps.push_back(k);
                                                addToOutPut("JZERO D ");
                                                }
#line 1460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 135 "parser.y" /* yacc.c:1646  */
    {
                                                output[whilejumps.back()]=output[whilejumps.back()]+toString(k+1);
                                                whilejumps.pop_back();
                                                addToOutPut("JUMP "+toString(whilejumps.back()));
                                                whilejumps.pop_back();
                                                }
#line 1471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 141 "parser.y" /* yacc.c:1646  */
    {whilejumps.push_back(k);}
#line 1477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "parser.y" /* yacc.c:1646  */
    {
                                                        whilejumps.pop_back();
                                                        addToOutPut("JZERO D "+toString(k+2));
                                                        addToOutPut("JUMP "+toString(whilejumps.back()));
                                                        }
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 145 "parser.y" /* yacc.c:1646  */
    {
                                                        whilejumps.pop_back();
                                                        }
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 148 "parser.y" /* yacc.c:1646  */
    {
                                long long int x=myfind(variables,(yyvsp[0]));
                                //long long int y=myfind(forIterators,$2);
                                if(x==-1){
                                        variable var; 
                                        var.name = (yyvsp[0]);
                                        var.initialized=true; 
                                        var.beginIndex= -1;
                                        var.endIndex= -1;
                                        var.table=false;
                                        var.memBeginIndex=currentIndex;
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        variables.push_back(var);
                                        var.memBeginIndex=currentIndex;
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        forIterators.push_back(var);
                                }else {
                                        cout << "Błąd, użyto już" << (yyvsp[0]) << "do deklaracji."<<endl;
                                        exit(1);
                                }
                                assign=false;
                                assignIDE=(yyvsp[0]);
                }
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 173 "parser.y" /* yacc.c:1646  */
    {assign=true;}
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 173 "parser.y" /* yacc.c:1646  */
    { 
                                        long long int index=myfind(variables, assignIDE);
                                        if(variables[index].table==false){
                                        variables[index].initialized=true;
                                        } 
                                        addToOutPut("SUB D D");
                                        addToOutPut("GET D");
                                        storeInMemoryFromRegister(assignIDE,"D",tableAssignIndex);
                                        assign=true;
                                        }
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "parser.y" /* yacc.c:1646  */
    {
                        assign=false;
                        write=true;
                        }
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 186 "parser.y" /* yacc.c:1646  */
    {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        addToOutPut("PUT D");
                                        assign=false;
                                        write=false;
                                        ideName[0] = "-1";
                                        ideIndex[0] = "-1";
                                        assign=true;
                                        write=false;
                                        }
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 198 "parser.y" /* yacc.c:1646  */
    {    loadToRegister(ideName[0],"D",ideIndex[0]);
                                loadToRegister(ideName[1],"E",ideIndex[1]);
                                storeInMemoryIterator(assignIDE,"D");
                                forjumps.push_back(k);
                                addToOutPut("JZERO D ");
                                ideName[0]="-1";
                                ideIndex[0]="-1";
                                ideName[1]="-1";
                                ideIndex[1]="-1";
                                assign = true;
         }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 208 "parser.y" /* yacc.c:1646  */
    {
                                loadLastIterator();
                                addToOutPut("DEC D");
                                addToOutPut("STORE D");
                                addToOutPut("JUMP "+toString(forjumps.back()));
                                output[forjumps.back()]=output[forjumps.back()]+toString(k);
                                forjumps.pop_back();
                                variables.pop_back();
                                forIterators.pop_back();
                                assign=true;
                         }
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 219 "parser.y" /* yacc.c:1646  */
    {
                                loadToRegister(ideName[0],"D",ideIndex[0]);
                                loadToRegister(ideName[1],"E",ideIndex[1]);
                                storeInMemoryIterator2(assignIDE,"D");
                                forjumps.push_back(k);
                                addToOutPut("JZERO D ");
                                ideName[0]="-1";
                                ideIndex[0]="-1";
                                ideName[1]="-1";
                                ideIndex[1]="-1";
                                assign = true; }
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 229 "parser.y" /* yacc.c:1646  */
    {
                                                loadLastIterator2();
                                                addToOutPut("DEC D");
                                                addToOutPut("STORE D");
                                                addToOutPut("JUMP "+toString(forjumps.back()));
                                                output[forjumps.back()]=output[forjumps.back()]+toString(k);
                                                forjumps.pop_back();
                                                variables.pop_back();
                                                forIterators.pop_back();
                                                assign=true;
                         }
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 242 "parser.y" /* yacc.c:1646  */
    {       
                                        assign=false;
                                        whilejumps.push_back(k);
                                        }
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 245 "parser.y" /* yacc.c:1646  */
    {   
                                                assign=true;
                                        }
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 250 "parser.y" /* yacc.c:1646  */
    {                  
                                        long long int elsejump=k;
                                        addToOutPut("JUMP ");
                                        output[ifjumps.back()]=output[ifjumps.back()]+toString(k);
                                        ifjumps.pop_back();
                                        ifjumps.push_back(elsejump);
                        }
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 256 "parser.y" /* yacc.c:1646  */
    {
                                        output[ifjumps.back()]=output[ifjumps.back()]+toString(k);
                                        ifjumps.pop_back();
                        }
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 260 "parser.y" /* yacc.c:1646  */
    {                  
                                        output[ifjumps.back()]=output[ifjumps.back()]+toString(k);
                                        ifjumps.pop_back();
                        }
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 266 "parser.y" /* yacc.c:1646  */
    {                
                                loadToRegister(ideName[0],"D",ideIndex[0]);
                                ideName[0]="-1";
                                ideIndex[0]="-1";
                                }
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 271 "parser.y" /* yacc.c:1646  */
    {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("ADD D E");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                                }
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 280 "parser.y" /* yacc.c:1646  */
    {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("SUB D E");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                                }
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 289 "parser.y" /* yacc.c:1646  */
    {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("SUB F F");
                                        long long start=k;
                                        addToOutPut("JZERO E "+toString(start+7));
                                        addToOutPut("JODD E "+toString(start+5));
                                        addToOutPut("ADD D D");
                                        addToOutPut("HALF E");
                                        addToOutPut("JUMP "+toString(start));
                                        addToOutPut("ADD F D");
                                        addToOutPut("JUMP "+toString(start+2));
                                        addToOutPut("COPY D F");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 307 "parser.y" /* yacc.c:1646  */
    {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("JZERO E "+toString(k+10));
                                        addToOutPut("SUB F F");
                                        addToOutPut("COPY G D");
                                        addToOutPut("COPY H G");
                                        addToOutPut("INC H");
                                        addToOutPut("SUB H E");
                                        long long start=k;
                                        addToOutPut("JZERO H "+toString(start+5));
                                        addToOutPut("SUB G E");
                                        addToOutPut("INC F");
                                        addToOutPut("JUMP "+toString(start-1));
                                        addToOutPut("SUB F F");
                                        addToOutPut("COPY D F");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                }
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 328 "parser.y" /* yacc.c:1646  */
    {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("JZERO E "+toString(k+8));
                                        addToOutPut("COPY G D");
                                        addToOutPut("COPY H G");
                                        addToOutPut("INC H");
                                        addToOutPut("SUB H E");
                                        long long start=k;
                                        addToOutPut("JZERO H "+toString(start+4));
                                        addToOutPut("SUB G E");
                                        addToOutPut("JUMP "+toString(start-1));
                                        addToOutPut("SUB G G");
                                        addToOutPut("COPY D G");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                }
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 350 "parser.y" /* yacc.c:1646  */
    {
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("COPY F D");
                        addToOutPut("COPY H E");
                        addToOutPut("SUB D H");
                        addToOutPut("SUB E F");
                        addToOutPut("ADD D E");
                        addToOutPut("JZERO D "+toString(k+3));
                        addToOutPut("SUB D D");
                        addToOutPut("JUMP "+toString(k+2));
                        addToOutPut("INC D");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                        assign=true;
}
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 368 "parser.y" /* yacc.c:1646  */
    {
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("COPY F D");
                        addToOutPut("COPY H E");
                        addToOutPut("SUB D H");
                        addToOutPut("SUB E F");
                        addToOutPut("ADD D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 381 "parser.y" /* yacc.c:1646  */
    {
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("SUB E D");
                        addToOutPut("COPY D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 391 "parser.y" /* yacc.c:1646  */
    {
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("SUB D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 400 "parser.y" /* yacc.c:1646  */
    {
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("INC E");
                        addToOutPut("SUB E D");
                        addToOutPut("COPY D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 411 "parser.y" /* yacc.c:1646  */
    {
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("INC D");
                        addToOutPut("SUB D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 423 "parser.y" /* yacc.c:1646  */
    {
                                if (ideName[0] == "-1"){
                                        ideName[0] = (yyvsp[0]);
                                }
                                else{
                                        ideName[1] = (yyvsp[0]);
                                }
               }
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 434 "parser.y" /* yacc.c:1646  */
    { 
                                long long int x = myfind(variables, (yyvsp[0]));
                                if(x == -1){
                                        cout << "Błąd! Niezadeklarowana zmienna " << (yyvsp[0]) << endl;
                                        exit(1);
                                }else if(variables[x].table==true){
                                        cout << "Błąd! Zmienna" << (yyvsp[0]) << "jest tablicą."<<endl;
                                        exit(1);
                                }else if(!assign){
                                        if(variables[x].initialized == false){                                                            
                                        cout << "Błąd! Użycie niezainicjowanej zmiennej " << (yyvsp[0]) << endl;
                                        exit(1);
                                        }
                                }
                                if(!assign){
                                        if (ideName[0] == "-1"){
                                                ideName[0] = (yyvsp[0]);
                                        }
                                        else{
                                                ideName[1] = (yyvsp[0]);
                                        }       
                                }else{
                                assignIDE=(yyvsp[0]);
                                }
                        }
#line 1936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 459 "parser.y" /* yacc.c:1646  */
    { 
                                long long int x = myfind(variables, (yyvsp[-1]));
                               
                                if(x == -1){
                                        cout << "Błąd! Niezadeklarowana zmienna" << (yyvsp[-1]) << endl;
                                        exit(1);
                                } else if(variables[x].table==true){
                                        cout << "Błąd! Zmienna" << (yyvsp[-1]) << "jest tablicą."<<endl;
                                        exit(1);
                                }else {
                                        if(variables[x].initialized == false){                                                            
                                                cout << "Błąd! Użycie niezainicjowanej zmiennej " << (yyvsp[-1]) << endl;
                                                exit(1);
                                        }
                                }
                                long long int y = myfind(variables, (yyvsp[-3]));
                                if(y == -1){
                                        cout << "Błąd! Niezadeklarowana tablica" << (yyvsp[-3]) << endl;
                                        exit(1);
                                }  else if(variables[y].table==false){
                                        cout << "Błąd! Zmienna" << (yyvsp[-3]) << "nie jest tablicą."<<endl;
                                        exit(1);
                                }

                                if(!assign){
                                        if (ideName[0] == "-1"){
                                                ideName[0] = (yyvsp[-3]);
                                                ideIndex[0] = (yyvsp[-1]);
                                        }
                                        else{
                                                ideName[1] = (yyvsp[-3]);
                                                ideIndex[1] = (yyvsp[-1]);
                                        }
                                }else{
                                        assignIDE=(yyvsp[-3]);
                                        tableAssignIndex=(yyvsp[-1]);
                                }

                        }
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 498 "parser.y" /* yacc.c:1646  */
    { 
                                long long int  x = myfind(variables, (yyvsp[-3]));
                                long long int number= atoll((yyvsp[-1]).c_str());
                                if(x == -1){
                                        cout << "Błąd! Niezadeklarowana tablica " << (yyvsp[-3]) << endl;
                                        exit(1);
                                } else if(variables[x].table==false){
                                        cout << "Błąd! Zmienna" << (yyvsp[-3]) << "nie jest tablicą."<<endl;
                                        exit(1);
                                }
                                else if(number < variables[x].beginIndex || number > variables[x].endIndex){                                                          
                                        cout << "Błąd! Odwołanie się do niestniejącego elementu tablicy" << (yyvsp[-3]) << "("<<(yyvsp[-1])<<")"<<endl;
                                        exit(1);
                                }
                                if(!assign){
                                        if (ideName[0] == "-1"){
                                                ideName[0] = (yyvsp[-3]);
                                                ideIndex[0] = (yyvsp[-1]);
                                        }
                                        else{
                                                ideName[1] = (yyvsp[-3]);
                                                ideIndex[1] = (yyvsp[-1]);
                                        }
                                }else{
                                        assignIDE=(yyvsp[-3]);
                                      tableAssignIndex=(yyvsp[-1]);          
                                }
                        }
#line 2013 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2017 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 527 "parser.y" /* yacc.c:1906  */


void wypisz(){
        for (long long int  i = 0; i < output.size(); i++){
                cout << output[i] << endl;
        }

}


void loadToRegister(string s, string place, string tableIndex){ 
                                if(isNumber(s)){ 
                                        long long int n = stoll(s);
                                        /*string bin = decToBin(n);
                                        long long int limit = bin.size();
                                        addToOutPut("SUB "+place+" "+place);
                                        for(long long int i = 0; i < limit; ++i){
                                                if(bin[i] == '1'){
                                                        addToOutPut("INC "+place);
                                                }
                                                if(i < (limit - 1)){
                                                        addToOutPut("ADD "+place+" "+place);
                                                }
                                        }*/
                                        addToRegisterValue(n,place);
                                        
                                }else {      
                                        long long int x=myfind(variables,s);
                                        if(variables[x].table==true){
                                                if(!isNumber(tableIndex)){
                                                        long long int y=myfind(variables,tableIndex);
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[y].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[y].memBeginIndex,"A");
                                                        addToOutPut("LOAD B");
                                                        /*addToOutPut("SUB C C");
                                                        for(long long int i=0;i<variables[x].beginIndex;i++){
                                                                addToOutPut("INC C");
                                                        }*/
                                                        addToRegisterValue(variables[x].beginIndex,"C");
                                                        addToOutPut("SUB B C");
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToOutPut("ADD A B");
                                                        addToOutPut("LOAD "+place);
                                                }else{
                                                        long long targetTableIndex=atoll(tableIndex.c_str());
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToRegisterValue(targetTableIndex-variables[x].beginIndex,"B");
                                                        addToOutPut("ADD A B");
                                                        /*for(long long int i=0;i<targetTableIndex-variables[x].beginIndex;i++){
                                                                addToOutPut("INC A");  
                                                        }*/
                                                        addToOutPut("LOAD "+place);
                                                }
                                        }else{
                                                /*addToOutPut("SUB A A");
                                                for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                addToOutPut("INC A");
                                                }*/
                                                addToRegisterValue(variables[x].memBeginIndex,"A");
                                                addToOutPut("LOAD "+place);
                                        }
                                }
                              
}
void storeInMemoryIterator(string s,string place){
                long long int x=myfind(variables,s);
                addToRegisterValue(variables[x].memBeginIndex,"A");
                addToOutPut("STORE D");
                addToOutPut("SUB E D");
                addToOutPut("COPY D E");
                addToOutPut("INC D");
                long long int y=myfind(forIterators,s);
                addToRegisterValue(forIterators[y].memBeginIndex,"A");
                addToOutPut("STORE D");
}
void storeInMemoryIterator2(string s,string place){
                long long int x=myfind(variables,s);
                addToRegisterValue(variables[x].memBeginIndex,"A");
                addToOutPut("STORE D");
                addToOutPut("SUB D E");
                addToOutPut("INC D");
                long long int y=myfind(forIterators,s);
                addToRegisterValue(forIterators[y].memBeginIndex,"A");
                addToOutPut("STORE D");
}
void loadLastIterator(){
        long long int x=myfind(variables,variables.back().name);
        addToRegisterValue(variables[x].memBeginIndex,"A");
        addToOutPut("LOAD D");
        addToOutPut("INC D");
        addToOutPut("STORE D");
        addToOutPut("INC A");
        addToOutPut("LOAD D");
                                
}

void loadLastIterator2(){
        long long int x=myfind(variables,variables.back().name);
        addToRegisterValue(variables[x].memBeginIndex,"A");
        addToOutPut("LOAD D");
        addToOutPut("DEC D");
        addToOutPut("STORE D");
        addToOutPut("INC A");
        addToOutPut("LOAD D");
                                
}

void storeInMemoryFromRegister(string s, string place, string tableIndex){
                                        long long int x=myfind(variables,s);
                                        if(variables[x].table==true){
                                                if(!isNumber(tableIndex)){
                                                        long long int y=myfind(variables,tableIndex);
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[y].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[y].memBeginIndex,"A");
                                                        addToOutPut("LOAD B"); //  uzyskanie wartości a, w B wartość a
                                                        /*addToOutPut("SUB C C");
                                                        for(long long int i=0;i<variables[x].beginIndex;i++){
                                                                addToOutPut("INC C"); // wpisanie początku tablicy
                                                        }*/
                                                        addToRegisterValue(variables[x].beginIndex,"C");
                                                        addToOutPut("SUB B C"); // wartość a - początek tablicy, ile mamy skoczyć
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToOutPut("ADD A B"); // dodanie do A 
                                                        addToOutPut("STORE "+place);
                                                }else{
                                                        long long targetTableIndex=atoll(tableIndex.c_str());
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }
                                                        for(long long int i=0;i<targetTableIndex-variables[x].beginIndex;i++){
                                                                addToOutPut("INC A");  
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToRegisterValue(targetTableIndex-variables[x].beginIndex,"B");
                                                        addToOutPut("ADD A B");
                                                        addToOutPut("STORE "+place);
                                                }
                                        }else{
                                                /*addToOutPut("SUB A A");
                                                for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                addToOutPut("INC A");
                                                }*/
                                                addToRegisterValue(variables[x].memBeginIndex,"A");
                                                addToOutPut("STORE "+place);
                                        }
}

void addToRegisterValue(long long int n,string place){
                                        string bin = decToBin(n);
                                        long long int limit = bin.size();
                                        addToOutPut("SUB "+place+" "+place);
                                        for(long long int i = 0; i < limit; ++i){
                                                if(bin[i] == '1'){
                                                        addToOutPut("INC "+place);
                                                }
                                                if(i < (limit - 1)){
                                                        addToOutPut("ADD "+place+" "+place);
                                                }
                                        }

}
void addToOutPut(string s){
      output.push_back(s);
    //cout << s << endl;
      k++;                   
}


string decToBin(long long int n) {
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}



void yyerror (char const *s){
        cout << "Błąd składni w pobliżu linii " << yylineno << ": " << s << endl;
        exit(1);
}
int main(void) {
        yyparse();
        wypisz();
        return 0;
}
