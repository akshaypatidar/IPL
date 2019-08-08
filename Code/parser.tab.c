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

#include <stdio.h>
extern "C" void yyerror(char *s);
extern int yylex(void);
extern int yylineno;
Symbol_Table * global_symbol_table = new Symbol_Table(), *local_symbol_table = new Symbol_Table();
std::string * curr_procedure; 

#line 75 "parser.tab.c" /* yacc.c:339  */

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
    INTEGER_NUMBER = 258,
    ASSIGN = 259,
    INTEGER = 260,
    NAME = 261,
    VOID = 262,
    DOUBLE_NUMBER = 263,
    RETURN = 264,
    FLOAT = 265,
    LESS_THAN = 266,
    LESS_THAN_EQUAL = 267,
    GREATER_THAN = 268,
    GREATER_THAN_EQUAL = 269,
    EQUAL = 270,
    NOT_EQUAL = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    WHILE = 275,
    DO = 276,
    IF = 277,
    ELSE = 278,
    PRINT = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "parser.y" /* yacc.c:355  */

	int integer_value;
	double double_value;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;
	list<Procedure*>* procedure_list;
	list<Symbol_Table_Entry *>* symbol_entry_list;
	Data_Type type;

#line 155 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 172 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

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
      32,    33,    29,    27,    34,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,    31,
       2,     2,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    85,    86,    89,    90,    93,   121,   136,
     149,   172,   197,   200,   207,   213,   221,   224,   243,   250,
     258,   258,   302,   302,   348,   351,   356,   359,   365,   389,
     396,   405,   408,   415,   416,   419,   423,   429,   446,   453,
     462,   469,   479,   482,   487,   490,   493,   496,   499,   512,
     516,   519,   524,   527,   530,   533,   538,   548,   558,   568,
     578,   588,   600,   610,   620,   630,   633,   638,   648,   660,
     669,   680,   683,   687,   690,   693,   706,   732,   735,   740,
     743
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_NUMBER", "ASSIGN", "INTEGER",
  "NAME", "VOID", "DOUBLE_NUMBER", "RETURN", "FLOAT", "LESS_THAN",
  "LESS_THAN_EQUAL", "GREATER_THAN", "GREATER_THAN_EQUAL", "EQUAL",
  "NOT_EQUAL", "AND", "OR", "NOT", "WHILE", "DO", "IF", "ELSE", "PRINT",
  "'?'", "':'", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "','",
  "'{'", "'}'", "$accept", "program", "global_declaration_list",
  "global_declaration", "global_variable_declaration",
  "global_procedure_declaration", "procedure_definition_list",
  "param_list_decl", "optional_param_list", "param_list",
  "procedure_definition", "@1", "@2",
  "local_optional_variable_declaration_list",
  "local_variable_declaration_list", "local_variable_declaration",
  "variable_list", "statement_list", "optional_arg_list", "arg_list",
  "procedure_call", "return_statement", "assignment_statement",
  "statement", "matched_stmt", "unmatched_stmt", "boolean_expression",
  "logical_expression", "E", "variable", "constant", "data_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    63,    58,    43,    45,    42,
      47,    59,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -80,    19,    60,   -80,   -80,     6,   -80,   -80,   -80,   -80,
     142,   -80,    17,    10,    32,   -80,    40,    34,    -6,     8,
      45,    54,     8,   -80,    85,    -2,    61,    16,    98,     8,
       8,    64,    79,   -80,    83,     8,    96,     8,   -80,    88,
      98,   101,   105,   111,   -80,   -80,   -80,   110,   140,   -80,
     -80,   -80,   -80,   118,     8,   -80,     8,   -80,     8,   -80,
     149,   -80,    81,   -80,   -80,    44,    87,   124,   129,   127,
     109,   128,   156,   -80,   -80,   134,   143,   -80,   -80,   -80,
     -80,   160,   -80,   -80,   129,   -80,   -80,   -80,   129,   129,
     129,   -80,    63,   191,   -80,   -80,   129,   161,   162,   129,
     152,   104,   -80,   -80,   135,   155,   174,   191,   -80,   191,
     -80,   -11,   157,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,    12,   177,   178,    46,
     -80,   -80,   158,   164,   -80,   129,   -80,   -80,   -80,   199,
     185,   191,   191,   191,   191,   191,   191,    90,    90,   -80,
     -80,   109,   129,   129,   109,   -80,   -80,   191,   129,   -80,
     -80,    51,   133,   -80,   194,   191,   192,   193,   109,   -80,
     -80,   -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    79,     0,    80,     4,     5,     6,
       2,    12,     0,     0,     0,    13,     0,    29,     0,    16,
       0,     0,    16,     7,     0,     0,     0,    17,    14,    16,
      16,     0,     0,    30,     0,     0,    22,     0,    18,     0,
       0,     0,     0,    20,    11,    15,     9,     0,     0,    22,
      20,    10,     8,     0,    24,    19,    24,    31,    25,    26,
       0,    31,     0,    27,    29,     0,     0,    76,    38,     0,
       0,     0,     0,    31,    23,     0,     0,    45,    32,    42,
      43,     0,    28,    21,    33,    77,    76,    78,     0,     0,
       0,    65,     0,    39,    71,    72,     0,     0,     0,     0,
       0,     0,    50,    51,     0,     0,    34,    35,    64,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,    48,     0,     0,    37,     0,    66,    73,    62,    63,
       0,    56,    58,    57,    59,    60,    61,    67,    68,    69,
      70,     0,     0,     0,     0,    41,    40,    36,     0,    46,
      54,     0,     0,    52,    42,    75,     0,     0,     0,    47,
      55,    44,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   200,    18,   -80,
     215,   -80,   -80,   170,   -80,   169,   168,   -58,   -80,   -80,
     125,   -80,   -80,    76,   -69,   -68,   -80,   -79,   -63,   -62,
     -80,    14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    10,    25,    26,    27,
      11,    53,    47,    57,    58,    59,    18,    62,   105,   106,
      75,    76,    77,    78,    79,    80,    91,    92,   109,    94,
      95,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      81,    97,    98,    66,    81,    93,   113,   114,    81,   108,
     100,   111,    13,     4,   115,   101,    12,   126,     6,     3,
     129,   107,   136,    17,    16,    23,   110,   112,    24,   113,
     114,    34,    35,    28,   138,   139,    28,   115,    20,    81,
      32,   133,    19,    40,    40,   151,    21,    39,    41,    45,
      37,    48,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   113,   114,     4,    22,     5,   113,   114,
       6,   115,   157,   161,   162,    82,   115,    29,    24,   154,
     113,   114,   159,   160,   166,   164,    30,    67,   115,    81,
      68,    33,    81,    67,    36,   165,    68,    42,    35,   171,
     172,    69,    70,    71,    38,    72,    81,    69,    70,    71,
      67,    72,    43,    68,    44,    67,    73,    74,    68,   124,
     125,    49,    73,    83,    69,    70,    71,    46,    72,    69,
      70,    71,    85,    72,    50,    86,    51,    87,    85,    73,
     131,    67,    52,    87,    73,    54,    55,     4,    88,    14,
     113,   114,     6,    56,    88,    64,    84,    89,   115,    96,
      99,    90,    86,    89,   104,   102,   167,    90,   116,   117,
     118,   119,   120,   121,   103,   116,   117,   118,   119,   120,
     121,   127,   128,   130,   122,   123,   124,   125,   134,   155,
     137,   122,   123,   124,   125,   156,   116,   117,   118,   119,
     120,   121,   116,   117,   118,   119,   120,   121,   135,   152,
     153,   158,   122,   123,   124,   125,   113,   168,   122,   123,
     124,   125,    31,   169,   170,    15,    61,    63,    65,   132,
     163
};

static const yytype_uint8 yycheck[] =
{
      62,    70,    70,    61,    66,    68,    17,    18,    70,    88,
      72,    90,     6,     5,    25,    73,     2,    96,    10,     0,
      99,    84,    33,     6,    10,    31,    89,    90,    34,    17,
      18,    33,    34,    19,   113,   114,    22,    25,     6,   101,
      22,   104,    32,    29,    30,    33,     6,    29,    30,    35,
      34,    37,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    17,    18,     5,    32,     7,    17,    18,
      10,    25,   135,   152,   153,    31,    25,    32,    34,    33,
      17,    18,   151,   151,    33,   154,    32,     6,    25,   151,
       9,     6,   154,     6,    33,   158,     9,    33,    34,   168,
     168,    20,    21,    22,     6,    24,   168,    20,    21,    22,
       6,    24,    33,     9,    31,     6,    35,    36,     9,    29,
      30,    33,    35,    36,    20,    21,    22,    31,    24,    20,
      21,    22,     3,    24,    33,     6,    31,     8,     3,    35,
      36,     6,    31,     8,    35,    35,     6,     5,    19,     7,
      17,    18,    10,    35,    19,     6,    32,    28,    25,    32,
      32,    32,     6,    28,     4,    31,    33,    32,    11,    12,
      13,    14,    15,    16,    31,    11,    12,    13,    14,    15,
      16,    20,    20,    31,    27,    28,    29,    30,    33,    31,
      33,    27,    28,    29,    30,    31,    11,    12,    13,    14,
      15,    16,    11,    12,    13,    14,    15,    16,    34,    32,
      32,    26,    27,    28,    29,    30,    17,    23,    27,    28,
      29,    30,    22,    31,    31,    10,    56,    58,    60,   104,
     154
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,     5,     7,    10,    40,    41,    42,
      43,    47,    68,     6,     7,    47,    68,     6,    53,    32,
       6,     6,    32,    31,    34,    44,    45,    46,    68,    32,
      32,    44,    45,     6,    33,    34,    33,    34,     6,    45,
      68,    45,    33,    33,    31,    68,    31,    49,    68,    33,
      33,    31,    31,    48,    35,     6,    35,    50,    51,    52,
      68,    50,    54,    52,     6,    53,    54,     6,     9,    20,
      21,    22,    24,    35,    36,    57,    58,    59,    60,    61,
      62,    66,    31,    36,    32,     3,     6,     8,    19,    28,
      32,    63,    64,    65,    66,    67,    32,    61,    62,    32,
      66,    54,    31,    31,     4,    55,    56,    65,    64,    65,
      65,    64,    65,    17,    18,    25,    11,    12,    13,    14,
      15,    16,    27,    28,    29,    30,    64,    20,    20,    64,
      31,    36,    57,    65,    33,    34,    33,    33,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    33,    32,    32,    33,    31,    31,    65,    26,    61,
      62,    64,    64,    60,    61,    65,    33,    33,    23,    31,
      31,    61,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    42,    42,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      48,    47,    49,    47,    50,    50,    51,    51,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    67,    68,
      68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     3,     6,     6,
       6,     6,     1,     2,     1,     3,     0,     1,     2,     4,
       0,    10,     0,    10,     0,     1,     1,     2,     3,     1,
       3,     0,     2,     0,     1,     1,     3,     4,     1,     2,
       4,     4,     1,     1,     7,     1,     5,     7,     3,     3,
       2,     2,     5,     7,     5,     7,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     1,     1,     3,     2,     5,     1,     1,     1,     1,
       1
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
#line 73 "parser.y" /* yacc.c:1646  */
    {
					global_symbol_table->set_table_scope(global);
					program_object.set_global_table(*global_symbol_table);
					program_object.called_proc_are_defined_check();
					if(!program_object.variable_in_proc_map_check("main") || program_object.get_procedure_prototype("main")->get_return_type() != void_data_type){
						printf("cs316: Error : Line no. : %d Main should be defined and it's type should be void\n",yylineno);
						exit(0);
					}
				}
#line 1391 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "parser.y" /* yacc.c:1646  */
    {	
															(yyval.symbol_table) = new Symbol_Table();
															for (list<Symbol_Table_Entry*>::iterator it=(yyvsp[-1].symbol_entry_list)->begin(); it != (yyvsp[-1].symbol_entry_list)->end(); ++it){
																if(program_object.variable_in_proc_map_check((*it)->get_variable_name())){
																	printf("cs316: Error : Line No. %d Global variable name cannot be same as procedure name\n",yylineno);
																	exit(0);
																}
																if(global_symbol_table->is_empty()){
																	(*it)->set_data_type((yyvsp[-2].type));
																	(yyval.symbol_table)->push_symbol(*it);
																	global_symbol_table->push_symbol(*it);	
																}
																else{
																	if(global_symbol_table->variable_in_symbol_list_check((*it)->get_variable_name())){
																		printf("cs316: Error : Variable declared twice. Line no. : %d\n",yylineno);
																		exit(0);
																	}
																	else{
																		(*it)->set_data_type((yyvsp[-2].type));
																		(yyval.symbol_table)->push_symbol(*it);
																		global_symbol_table->push_symbol(*it);		
																	}
																}
															}
														}
#line 1421 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "parser.y" /* yacc.c:1646  */
    {
											if(global_symbol_table->variable_in_symbol_list_check(*(yyvsp[-4].string_value))){
												printf("cs316: Error : Line No. %d Procedure Name cannot be same as global variable\n",yylineno);
												exit(0);
											}
											string s = *(yyvsp[-4].string_value);
											//s = s + "_";
											(yyval.procedure) = new Procedure((yyvsp[-5].type),s,yylineno);
											(yyvsp[-2].symbol_table)->set_table_scope(formal);
											(yyval.procedure)->set_formal_param_list(*(yyvsp[-2].symbol_table));	 
											program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
				
											

										}
#line 1441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "parser.y" /* yacc.c:1646  */
    {
											if(global_symbol_table->variable_in_symbol_list_check(*(yyvsp[-4].string_value))){
												printf("cs316: Error : Line No. %d Procedure Name cannot be same as global variable\n",yylineno);
												exit(0);
											}
											string s = *(yyvsp[-4].string_value);
											//s = s + "_";
											(yyval.procedure) = new Procedure(void_data_type,s,yylineno);
											(yyvsp[-2].symbol_table)->set_table_scope(formal);
											(yyval.procedure)->set_formal_param_list(*(yyvsp[-2].symbol_table));	 
											program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
											
										}
#line 1459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "parser.y" /* yacc.c:1646  */
    {
											string s = *(yyvsp[-4].string_value);
											if(global_symbol_table->variable_in_symbol_list_check(*(yyvsp[-4].string_value))){
												printf("cs316: Error : Line No. %d Procedure Name cannot be same as global variable\n",yylineno);
												exit(0);
											}
											//s = s + "_";
											(yyval.procedure) = new Procedure((yyvsp[-5].type),s,yylineno);
											
											Symbol_Table * temp = new Symbol_Table();
											int i = 1;
											for (list<Symbol_Table_Entry*>::iterator it=(yyvsp[-2].symbol_entry_list)->begin(); it != (yyvsp[-2].symbol_entry_list)->end(); ++it){
												string s = (*it)->get_variable_name();
												s = s + std::to_string(i);
												temp->push_symbol(new Symbol_Table_Entry(s,(*it)->get_data_type(),yylineno));
												i++;
											}	
											temp->set_table_scope(formal);
											(yyval.procedure)->set_formal_param_list(*temp);	 
											program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
											
											
										}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 172 "parser.y" /* yacc.c:1646  */
    {
											string s = *(yyvsp[-4].string_value);
											if(global_symbol_table->variable_in_symbol_list_check(*(yyvsp[-4].string_value))){
												printf("cs316: Error : Line No. %d Procedure Name cannot be same as global variable\n",yylineno);
												exit(0);
											}
											//s = s + "_";
											(yyval.procedure) = new Procedure(void_data_type,s,yylineno);
											Symbol_Table * temp = new Symbol_Table();
											int i = 1;
											for (list<Symbol_Table_Entry*>::iterator it=(yyvsp[-2].symbol_entry_list)->begin(); it != (yyvsp[-2].symbol_entry_list)->end(); ++it){
												string s = (*it)->get_variable_name();
												s = s + std::to_string(i);
												temp->push_symbol(new Symbol_Table_Entry(s,(*it)->get_data_type(),yylineno));
												i++;
											}	
											temp->set_table_scope(formal);
											(yyval.procedure)->set_formal_param_list(*temp);	 
											program_object.set_proc_to_map(*(yyvsp[-4].string_value), (yyval.procedure));
											
											
										}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval.procedure_list) = new list<Procedure*>();
													  (yyval.procedure_list)->push_back((yyvsp[0].procedure));
													 }
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 200 "parser.y" /* yacc.c:1646  */
    {
																					(yyvsp[-1].procedure_list)->push_back((yyvsp[0].procedure));
																					(yyval.procedure_list) = (yyvsp[-1].procedure_list);
																				}
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 207 "parser.y" /* yacc.c:1646  */
    {
							(yyval.symbol_entry_list) = new list<Symbol_Table_Entry*>();
							string s = "dummy";
							// s = s + ;
							(yyval.symbol_entry_list)->push_back(new Symbol_Table_Entry(s,(yyvsp[0].type),yylineno));
						}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "parser.y" /* yacc.c:1646  */
    {
							string s = "dummy";
		  					// s = s + "_";
							(yyvsp[-2].symbol_entry_list)->push_back(new Symbol_Table_Entry(s,(yyvsp[0].type),yylineno));
							(yyval.symbol_entry_list)=(yyvsp[-2].symbol_entry_list);
						}
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 221 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_table) = new Symbol_Table();
										}
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 224 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_table) = new Symbol_Table();
											for (list<Symbol_Table_Entry*>::iterator it=(yyvsp[0].symbol_entry_list)->begin(); it != (yyvsp[0].symbol_entry_list)->end(); ++it){
												if((yyval.symbol_table)->is_empty()){
													(yyval.symbol_table)->push_symbol(*it);
												}
												else{
													if((yyval.symbol_table)->variable_in_symbol_list_check((*it)->get_variable_name())){
														printf("cs316: Error : Same Parameter declared twice. Line no. : %d\n",yylineno);
														exit(0);
													}
													else{
														(yyval.symbol_table)->push_symbol(*it);
													}
												}
											}	
										}
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 243 "parser.y" /* yacc.c:1646  */
    {
											(yyval.symbol_entry_list) = new list<Symbol_Table_Entry*>();
											string s = *(yyvsp[0].string_value);
											// s = s + "_";
											(yyval.symbol_entry_list)->push_back(new Symbol_Table_Entry(s,(yyvsp[-1].type),yylineno));
										}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 250 "parser.y" /* yacc.c:1646  */
    {
															string s = *(yyvsp[0].string_value);
										  					// s = s + "_";
					            							(yyvsp[-3].symbol_entry_list)->push_back(new Symbol_Table_Entry(s,(yyvsp[-1].type),yylineno));
					            							(yyval.symbol_entry_list)=(yyvsp[-3].symbol_entry_list);
														}
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 258 "parser.y" /* yacc.c:1646  */
    {
								if(global_symbol_table->variable_in_symbol_list_check(*(yyvsp[-3].string_value))){
									printf("cs316: Error : Line No. %d Procedure Name cannot be same as global variable\n",yylineno);
									exit(0);
								}
								string s = *(yyvsp[-3].string_value);
								//s = s + "_";
								(yyval.procedure) = new Procedure((yyvsp[-4].type), s, yylineno);
								(yyvsp[-1].symbol_table)->set_table_scope(formal);
								(yyval.procedure)->set_formal_param_list(*(yyvsp[-1].symbol_table));	 
								(yyval.procedure)->set_proc_is_defined();
								curr_procedure = (yyvsp[-3].string_value);

								
								if(program_object.variable_in_proc_map_check(*(yyvsp[-3].string_value))){
									if(program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->is_proc_defined()){
										printf("cs316: Error : Line No. %d Procedure Already Defined\n",yylineno);
										exit(0);
									}
									else if(program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->get_return_type() != (yyvsp[-4].type)){
										printf("cs316: Error : Line No. %d Return Type do not match\n",yylineno);
										exit(0);
									}
									else{
										program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->set_formal_param_list(*(yyvsp[-1].symbol_table));
										program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->set_proc_is_defined();
									}
								}
								else{
									program_object.set_proc_to_map(*(yyvsp[-3].string_value), (yyval.procedure));
								}
							}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 293 "parser.y" /* yacc.c:1646  */
    {
									Procedure* p = program_object.get_procedure_prototype((yyvsp[-4].procedure)->get_proc_name());

									p->set_ast_list(*(yyvsp[-1].ast_list));
									(yyvsp[-2].symbol_table)->set_table_scope(local);
									p->set_local_list(*(yyvsp[-2].symbol_table));
									(yyval.procedure) = p;
									local_symbol_table = new Symbol_Table();
							}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 302 "parser.y" /* yacc.c:1646  */
    {
								if(global_symbol_table->variable_in_symbol_list_check(*(yyvsp[-3].string_value))){
									printf("cs316: Error : Line No. %d Procedure Name cannot be same as global variable\n",yylineno);
									exit(0);
								}
								string s = *(yyvsp[-3].string_value);
								//s = s + "_";
								(yyval.procedure) = new Procedure(void_data_type,s, yylineno);
								(yyvsp[-1].symbol_table)->set_table_scope(formal);
								(yyval.procedure)->set_formal_param_list(*(yyvsp[-1].symbol_table));	 
								(yyval.procedure)->set_proc_is_defined();
								curr_procedure = (yyvsp[-3].string_value);
								
								if(program_object.variable_in_proc_map_check(*(yyvsp[-3].string_value))){
									if(program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->is_proc_defined()){
										printf("cs316: Error : Line No. %d Procedure Already Defined\n",yylineno);
										exit(0);
									}
									else if(program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->get_return_type() != void_data_type){
										printf("cs316: Error : Line No. %d Return Type do not match\n",yylineno);
										exit(0);
									}
									else{
										program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->set_formal_param_list(*(yyvsp[-1].symbol_table));
										program_object.get_procedure_prototype(*(yyvsp[-3].string_value))->set_proc_is_defined();
									}
								}
								else{
									program_object.set_proc_to_map(*(yyvsp[-3].string_value), (yyval.procedure));
								}
							}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 336 "parser.y" /* yacc.c:1646  */
    {
									Procedure* p = program_object.get_procedure_prototype((yyvsp[-4].procedure)->get_proc_name());
									p->set_ast_list(*(yyvsp[-1].ast_list));
									(yyvsp[-2].symbol_table)->set_table_scope(local);
									p->set_local_list(*(yyvsp[-2].symbol_table));
									(yyval.procedure) = p;
									local_symbol_table = new Symbol_Table();
							}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 348 "parser.y" /* yacc.c:1646  */
    {
                        										(yyval.symbol_table) = new Symbol_Table();
                        									}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 351 "parser.y" /* yacc.c:1646  */
    {	
																			(yyval.symbol_table) = (yyvsp[0].symbol_table);
																		}
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 356 "parser.y" /* yacc.c:1646  */
    {
																	(yyval.symbol_table) = (yyvsp[0].symbol_table);
																}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 360 "parser.y" /* yacc.c:1646  */
    {
																(yyvsp[-1].symbol_table)->append_list(*(yyvsp[0].symbol_table),yylineno);(yyval.symbol_table) = (yyvsp[-1].symbol_table);
															}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 365 "parser.y" /* yacc.c:1646  */
    {	
															(yyval.symbol_table) = new Symbol_Table();
															for (list<Symbol_Table_Entry*>::iterator it=(yyvsp[-1].symbol_entry_list)->begin(); it != (yyvsp[-1].symbol_entry_list)->end(); ++it){
																if(local_symbol_table->is_empty()){
																	(*it)->set_data_type((yyvsp[-2].type));
																	(yyval.symbol_table)->push_symbol(*it);
																	local_symbol_table->push_symbol(*it);	
																}
																else{
																	if(local_symbol_table->variable_in_symbol_list_check((*it)->get_variable_name())){
																		printf("cs316: Error : Variable declared twice. Line no. : %d\n",yylineno);
																		exit(0);
																	}
																	else{
																		(*it)->set_data_type((yyvsp[-2].type));
																		(yyval.symbol_table)->push_symbol(*it);
																		local_symbol_table->push_symbol(*it);		
																	}
																}
															}
														}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 389 "parser.y" /* yacc.c:1646  */
    {
							(yyval.symbol_entry_list) = new list<Symbol_Table_Entry*>();
						  //printf("Variable = %s\n",*$1);
						  string s = *(yyvsp[0].string_value);
						  // s = s + "_";
						  (yyval.symbol_entry_list)->push_back(new Symbol_Table_Entry(s,void_data_type,yylineno));	
						 }
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 396 "parser.y" /* yacc.c:1646  */
    {
                							string s = *(yyvsp[0].string_value);
						  					// s = s + "_";
                							(yyvsp[-2].symbol_entry_list)->push_back(new Symbol_Table_Entry(s,void_data_type,yylineno));
                							(yyval.symbol_entry_list)=(yyvsp[-2].symbol_entry_list);
                						}
#line 1786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 405 "parser.y" /* yacc.c:1646  */
    {
									(yyval.ast_list) = new list<Ast *>();
								}
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 409 "parser.y" /* yacc.c:1646  */
    {
									(yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list)=(yyvsp[-1].ast_list);
								}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 415 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_list) = new list<Ast *>();}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 416 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_list) = (yyvsp[0].ast_list);}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "parser.y" /* yacc.c:1646  */
    {
							(yyval.ast_list) = new list<Ast*>();
							(yyval.ast_list)->push_back((yyvsp[0].ast));	
						}
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 423 "parser.y" /* yacc.c:1646  */
    {
							(yyvsp[-2].ast_list)->push_back((yyvsp[0].ast));
							(yyval.ast_list) = (yyvsp[-2].ast_list);
						}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 429 "parser.y" /* yacc.c:1646  */
    {
						
						// if(p == NULL || !p->is_proc_defined()){
						if(!program_object.variable_in_proc_map_check(*(yyvsp[-3].string_value))){
							printf("cs316: Error : Line No. %d Procedure not defined\n",yylineno);
							exit(0);
						}
						Procedure* p = program_object.get_procedure_prototype(*(yyvsp[-3].string_value));
						p->set_proc_is_called();
						Call_Ast* call_ast = new Call_Ast(*(yyvsp[-3].string_value), yylineno);
						call_ast->set_data_type(p->get_return_type());
						call_ast->set_actual_param_list(*(yyvsp[-1].ast_list));
						call_ast->check_actual_formal_param(p->get_formal_param_list());
						(yyval.ast) = call_ast;
					}
#line 1852 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 446 "parser.y" /* yacc.c:1646  */
    { 	
									if(program_object.get_procedure_prototype(*curr_procedure)->get_return_type() != void_data_type){
										printf("cs316: Error : Line No. %d Return Type not compatible\n",yylineno);
										exit(0);
									}
									(yyval.ast) = new Return_Ast(NULL, *curr_procedure, yylineno);
								}
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 453 "parser.y" /* yacc.c:1646  */
    { 
									if(program_object.get_procedure_prototype(*curr_procedure)->get_return_type() != (yyvsp[0].ast)->get_data_type()){
										printf("cs316: Error : Line No. %d Return Type not compatible\n",yylineno);
										exit(0);
									}
									(yyval.ast) = new Return_Ast((yyvsp[0].ast), *curr_procedure, yylineno);
									}
#line 1876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 462 "parser.y" /* yacc.c:1646  */
    {
													(yyval.ast) = new Assignment_Ast((yyvsp[-3].ast),(yyvsp[-1].ast),yylineno);
													if ((yyvsp[-3].ast)->get_data_type() != (yyvsp[-1].ast)->get_data_type()){
														printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
														exit(0);
													}	
												  }
#line 1888 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 469 "parser.y" /* yacc.c:1646  */
    {
																	(yyval.ast) = new Assignment_Ast((yyvsp[-3].ast), (yyvsp[-1].ast), yylineno);
																	if ((yyvsp[-3].ast)->get_data_type() != (yyvsp[-1].ast)->get_data_type()){
																		printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
																		exit(0);
																	}
																}
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 479 "parser.y" /* yacc.c:1646  */
    {
									(yyval.ast) = (yyvsp[0].ast);
								}
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 482 "parser.y" /* yacc.c:1646  */
    {
									(yyval.ast) = (yyvsp[0].ast);
								}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 487 "parser.y" /* yacc.c:1646  */
    {
																					(yyval.ast) = new Selection_Statement_Ast((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
																					}
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 490 "parser.y" /* yacc.c:1646  */
    {
											(yyval.ast) = (yyvsp[0].ast);(yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
										}
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 493 "parser.y" /* yacc.c:1646  */
    {
																		(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno,false);
																	}
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 496 "parser.y" /* yacc.c:1646  */
    {
																				(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast),(yyvsp[-5].ast),yylineno,true);
																			}
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 499 "parser.y" /* yacc.c:1646  */
    {
														Sequence_Ast* temp = new Sequence_Ast(yylineno);
														if((yyvsp[-1].ast_list) == NULL || (yyvsp[-1].ast_list)->size() == 0){
																printf("cs316: Error : Line No. %d Block of statements cannot be empty\n",yylineno);
																exit(0);	
														}
														else{
															for(list<Ast*>::iterator it=(yyvsp[-1].ast_list)->begin(); it != (yyvsp[-1].ast_list)->end(); ++it){
																temp->ast_push_back(*it);
															}
															(yyval.ast) = temp;
														}
													}
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 512 "parser.y" /* yacc.c:1646  */
    {
											(yyval.ast) = new Print_Ast((yyvsp[-1].ast),yylineno);
									   }
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 516 "parser.y" /* yacc.c:1646  */
    {
											(yyval.ast) = (yyvsp[-1].ast);
										}
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 519 "parser.y" /* yacc.c:1646  */
    {
												(yyval.ast) = (yyvsp[-1].ast);
											}
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 524 "parser.y" /* yacc.c:1646  */
    {
																(yyval.ast) = new Selection_Statement_Ast((yyvsp[-2].ast),(yyvsp[0].ast),NULL,yylineno);
															}
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 527 "parser.y" /* yacc.c:1646  */
    {
																						(yyval.ast) = new Selection_Statement_Ast((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
																					}
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 530 "parser.y" /* yacc.c:1646  */
    {
																		(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno,false);
																	}
#line 2014 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 533 "parser.y" /* yacc.c:1646  */
    {
																				(yyval.ast) = new Iteration_Statement_Ast((yyvsp[-2].ast),(yyvsp[-5].ast),yylineno,true);
																			}
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 538 "parser.y" /* yacc.c:1646  */
    {
											Ast *temp = new Relational_Expr_Ast((yyvsp[-2].ast),less_than,(yyvsp[0].ast),yylineno);
											if(temp->check_ast()){
												(yyval.ast) = temp;
											}
											else{
												printf("cs316: Error : Line No. %d Expressions not compatible for LESS_THAN\n",yylineno);
												exit(0);
											}
										}
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 548 "parser.y" /* yacc.c:1646  */
    {
												Ast *temp = new Relational_Expr_Ast((yyvsp[-2].ast),greater_than,(yyvsp[0].ast),yylineno);
												if(temp->check_ast()){
													(yyval.ast) = temp;
												}
												else{
													printf("cs316: Error : Line No. %d Expressions not compatible for GREATER_THAN\n",yylineno);
													exit(0);
												}
											}
#line 2052 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 558 "parser.y" /* yacc.c:1646  */
    {
													Ast *temp = new Relational_Expr_Ast((yyvsp[-2].ast),less_equalto,(yyvsp[0].ast),yylineno);
													if(temp->check_ast()){
														(yyval.ast) = temp;
													}
													else{
														printf("cs316: Error : Line No. %d Expressions not compatible for LESS_THAN_EQUAL\n",yylineno);
														exit(0);
													}
												}
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 568 "parser.y" /* yacc.c:1646  */
    {
													Ast *temp = new Relational_Expr_Ast((yyvsp[-2].ast),greater_equalto,(yyvsp[0].ast),yylineno);
													if(temp->check_ast()){
														(yyval.ast) = temp;
													}
													else{
														printf("cs316: Error : Line No. %d Expressions not compatible for GREATER_THAN_EQUAL\n",yylineno);
														exit(0);
													}
												}
#line 2082 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 578 "parser.y" /* yacc.c:1646  */
    {
										Ast *temp = new Relational_Expr_Ast((yyvsp[-2].ast),equalto,(yyvsp[0].ast),yylineno);
										if(temp->check_ast()){
											(yyval.ast) = temp;
										}
										else{
											printf("cs316: Error : Line No. %d Expressions not compatible for EQUAL\n",yylineno);
											exit(0);
										}
									}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 588 "parser.y" /* yacc.c:1646  */
    {
											Ast *temp = new Relational_Expr_Ast((yyvsp[-2].ast),not_equalto,(yyvsp[0].ast),yylineno);
											if(temp->check_ast()){
												(yyval.ast) = temp;
											}
											else{
												printf("cs316: Error : Line No. %d Expressions not compatible for NOT_EQUAL\n",yylineno);
												exit(0);
											}
										}
#line 2112 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 600 "parser.y" /* yacc.c:1646  */
    {
																		Ast* temp = new Logical_Expr_Ast((yyvsp[-2].ast),_logical_and,(yyvsp[0].ast),yylineno);
																		if(temp->check_ast()){
																			(yyval.ast) = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for AND\n",yylineno);
																			exit(0);
																		}
																	}
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 610 "parser.y" /* yacc.c:1646  */
    {
																		Ast* temp = new Logical_Expr_Ast((yyvsp[-2].ast),_logical_or,(yyvsp[0].ast),yylineno);
																		if(temp->check_ast()){
																			(yyval.ast) = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for OR\n",yylineno);
																			exit(0);
																		}
																	}
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 620 "parser.y" /* yacc.c:1646  */
    {
													Ast *temp = new Logical_Expr_Ast(NULL,_logical_not,(yyvsp[0].ast),yylineno);
													if(temp->check_ast()){
														(yyval.ast) = temp;
													}
													else{
														printf("cs316: Error : Line No. %d Expressions not compatible for NOT\n",yylineno);
														exit(0);
													}
												}
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 630 "parser.y" /* yacc.c:1646  */
    {
												(yyval.ast) = (yyvsp[0].ast);(yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
											}
#line 2165 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 633 "parser.y" /* yacc.c:1646  */
    {
													(yyval.ast) = (yyvsp[-1].ast);(yyval.ast)->set_data_type((yyvsp[-1].ast)->get_data_type());
												}
#line 2173 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 638 "parser.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-2].ast)->get_data_type() == (yyvsp[0].ast)->get_data_type()){
					 (yyval.ast) = new Plus_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					 (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
					}
				else {
					printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
					exit(0);
					}
				}
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 648 "parser.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-2].ast)->get_data_type() == (yyvsp[0].ast)->get_data_type()){
					 (yyval.ast) = new Minus_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					 (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
					}
				else{
					printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
					exit(0);	
					}
				}
#line 2203 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 660 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].ast)->get_data_type() == (yyvsp[0].ast)->get_data_type()){
					(yyval.ast) = new Mult_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
				 	(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
				 }
				 else{
				 	printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
				 	}
				}
#line 2217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 669 "parser.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-2].ast)->get_data_type() == (yyvsp[0].ast)->get_data_type()){
					(yyval.ast) = new Divide_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
				}
				else{
					printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
					exit(0);	
					}
				}
#line 2232 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 680 "parser.y" /* yacc.c:1646  */
    {
 					(yyval.ast) = (yyvsp[0].ast);(yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
 				}
#line 2240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 683 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);(yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
				}
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 687 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[-1].ast); (yyval.ast)->set_data_type((yyvsp[-1].ast)->get_data_type());
				}
#line 2256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 690 "parser.y" /* yacc.c:1646  */
    {
								(yyval.ast) = new UMinus_Ast((yyvsp[0].ast),NULL,yylineno);(yyval.ast)->set_data_type((yyvsp[0].ast)->get_data_type());
							}
#line 2264 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 693 "parser.y" /* yacc.c:1646  */
    {
										if ((yyvsp[-2].ast)->get_data_type() == (yyvsp[0].ast)->get_data_type()){
											 (yyval.ast) = new Conditional_Expression_Ast((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
											 (yyval.ast)->set_data_type((yyvsp[-2].ast)->get_data_type());
											}
										else{
											printf("cs316: Error : Line No. %d Arithmetic statement data type not compatible\n",yylineno);
											exit(0);	
											}
										}
#line 2279 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 706 "parser.y" /* yacc.c:1646  */
    {	
						string s = *(yyvsp[0].string_value);
						// s = s+"_";
						bool present_local = local_symbol_table->variable_in_symbol_list_check(s);
						bool present_global = global_symbol_table->variable_in_symbol_list_check(s);
						bool present_argument = program_object.get_procedure_prototype(*curr_procedure)->get_formal_param_list().variable_in_symbol_list_check(s);
						if(present_local){
							(yyval.ast) = new Name_Ast(s,local_symbol_table->get_symbol_table_entry(s),yylineno);
							(yyval.ast)->set_data_type(local_symbol_table->get_symbol_table_entry(s).get_data_type());
						}
						else if(present_argument){
							(yyval.ast) = new Name_Ast(s,program_object.get_procedure_prototype(*curr_procedure)->get_formal_param_list().get_symbol_table_entry(s),yylineno);
							(yyval.ast)->set_data_type(program_object.get_procedure_prototype(*curr_procedure)->get_formal_param_list().get_symbol_table_entry(s).get_data_type());
						}
						else if(present_global){
							(yyval.ast) = new Name_Ast(s,global_symbol_table->get_symbol_table_entry(s),yylineno);
							(yyval.ast)->set_data_type(global_symbol_table->get_symbol_table_entry(s).get_data_type());
						}
						else{
							printf("cs316: Error : Line no : %d Variable not declared\n", yylineno);
							exit(0);
						}
						
					 }
#line 2308 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 732 "parser.y" /* yacc.c:1646  */
    {
									(yyval.ast) = new Number_Ast<int>((yyvsp[0].integer_value),int_data_type,yylineno);
								}
#line 2316 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 735 "parser.y" /* yacc.c:1646  */
    {
									(yyval.ast) = new Number_Ast<double>((yyvsp[0].double_value),double_data_type,yylineno);
								}
#line 2324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 740 "parser.y" /* yacc.c:1646  */
    {
							(yyval.type) = int_data_type;
						}
#line 2332 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 743 "parser.y" /* yacc.c:1646  */
    {
							(yyval.type) = double_data_type;
						}
#line 2340 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2344 "parser.tab.c" /* yacc.c:1646  */
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
