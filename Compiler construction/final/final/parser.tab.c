
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();

    void add(char c, char *str);
    void printTree(struct node*, int depth, int branch[]);
    void printBranches(int branch[], int depth);
    
    struct node* mknode(struct node *one, struct node *two, struct node *three, struct node *four, struct node *five, char *token);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[200];

    int count=0;
    int q;
    char type[10];
    extern int countn;

    struct node *head;
    struct node {
        struct node *one;
        struct node *two;
        struct node *three;
        struct node *four;
        struct node *five;
        char *token;
    };


/* Line 189 of yacc.c  */
#line 114 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINTF = 258,
     VOID = 259,
     IF = 260,
     ELSE = 261,
     INT = 262,
     WHILE = 263,
     FLOAT = 264,
     RETURN = 265,
     NUMBER = 266,
     MAIN = 267,
     FLOAT_NUM = 268,
     ID = 269,
     STRING = 270,
     LE = 271,
     ASSIGN = 272,
     GE = 273,
     EQ = 274,
     NE = 275,
     GT = 276,
     LT = 277,
     AND = 278,
     OR = 279,
     NOT = 280,
     ADD = 281,
     SUBTRACT = 282,
     DIVIDE = 283,
     MULTIPLY = 284,
     O_BRACK = 285,
     C_BRACK = 286,
     OC_BRACK = 287,
     CC_BRACK = 288,
     S_COLON = 289,
     COMMA = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 41 "parser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 



/* Line 214 of yacc.c  */
#line 194 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "parser.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    11,    17,    18,    19,
      25,    26,    31,    33,    34,    38,    39,    40,    41,    42,
      43,    53,    54,    57,    58,    61,    62,    65,    66,    67,
      74,    75,    80,    81,    86,    87,    91,    92,    93,    94,
     101,   104,   106,   108,   110,   113,   117,   118,   123,   124,
     125,   131,   132,   133,   134,   135,   136,   137,   151,   152,
     153,   154,   155,   156,   167,   168,   173,   174,   178,   179,
     180,   187,   188,   189,   195,   199,   201,   205,   207,   208,
     211,   212,   215,   216,   219,   220,   223,   224,   227,   228,
     231,   232,   235,   236,   239,   240,   243,   247,   249,   250,
     253,   254,   257,   258,   261,   262,   265,   266,   267,   273,
     274,   275,   276,   284,   285,   288,   289,   292,   293,   296,
     297,   302,   304,   305,   308,   309,   312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    47,    -1,    38,    39,    -1,    -1,
      -1,    52,    14,    40,    41,    56,    -1,    -1,    -1,    30,
      42,    44,    31,    43,    -1,    -1,    44,    35,    45,    44,
      -1,    44,    -1,    -1,    52,    14,    46,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    48,    12,    49,    30,    50,    31,
      51,    56,    -1,    -1,     7,    53,    -1,    -1,     9,    54,
      -1,    -1,     4,    55,    -1,    -1,    -1,    32,    57,    59,
      66,    33,    58,    -1,    -1,    63,    35,    60,    59,    -1,
      -1,    63,    34,    61,    59,    -1,    -1,    63,    34,    62,
      -1,    -1,    -1,    -1,    52,    14,    64,    17,    65,    92,
      -1,    67,    66,    -1,    67,    -1,    92,    -1,    82,    -1,
      82,    84,    -1,    82,    86,    84,    -1,    -1,     8,    68,
      89,    56,    -1,    -1,    -1,    10,    69,    92,    34,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    71,    30,
      72,    15,    73,    35,    74,    92,    31,    75,    34,    76,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    77,    30,    78,
      15,    79,    31,    80,    34,    81,    -1,    -1,     5,    83,
      89,    56,    -1,    -1,     6,    85,    56,    -1,    -1,    -1,
       6,    87,     5,    88,    89,    56,    -1,    -1,    -1,    30,
      90,    92,    31,    91,    -1,    93,    94,    92,    -1,    93,
      -1,    93,   105,   104,    -1,   104,    -1,    -1,    16,    95,
      -1,    -1,    18,    96,    -1,    -1,    19,    97,    -1,    -1,
      20,    98,    -1,    -1,    21,    99,    -1,    -1,    22,   100,
      -1,    -1,    23,   101,    -1,    -1,    24,   102,    -1,    -1,
      25,   103,    -1,   104,   108,   111,    -1,   111,    -1,    -1,
      26,   106,    -1,    -1,    27,   107,    -1,    -1,    29,   109,
      -1,    -1,    28,   110,    -1,    -1,    -1,    30,   112,    92,
      31,   113,    -1,    -1,    -1,    -1,    14,   114,    30,   115,
     120,    31,   116,    -1,    -1,    14,   117,    -1,    -1,    11,
     118,    -1,    -1,    13,   119,    -1,    -1,   120,    35,   121,
     120,    -1,   120,    -1,    -1,    14,   122,    -1,    -1,    11,
     123,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    60,    61,    64,    64,    67,    67,    67,
      70,    70,    71,    72,    72,    73,    76,    76,    76,    76,
      76,    80,    80,    81,    81,    82,    82,    85,    85,    85,
      88,    88,    89,    89,    90,    90,    91,    94,    94,    94,
      97,    98,   101,   102,   103,   104,   105,   105,   106,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     108,   108,   108,   108,   111,   111,   114,   114,   117,   117,
     117,   120,   120,   120,   123,   124,   128,   129,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   143,   144,   147,   147,
     148,   148,   151,   151,   152,   152,   155,   155,   155,   156,
     156,   156,   156,   157,   157,   158,   158,   159,   159,   162,
     162,   163,   164,   164,   165,   165,   166
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINTF", "VOID", "IF", "ELSE", "INT",
  "WHILE", "FLOAT", "RETURN", "NUMBER", "MAIN", "FLOAT_NUM", "ID",
  "STRING", "LE", "ASSIGN", "GE", "EQ", "NE", "GT", "LT", "AND", "OR",
  "NOT", "ADD", "SUBTRACT", "DIVIDE", "MULTIPLY", "O_BRACK", "C_BRACK",
  "OC_BRACK", "CC_BRACK", "S_COLON", "COMMA", "$accept", "program",
  "functionList", "function", "$@1", "paramList", "$@2", "$@3", "param",
  "$@4", "$@5", "mainFunction", "$@6", "$@7", "$@8", "$@9", "type", "$@10",
  "$@11", "$@12", "compoundStmt", "$@13", "$@14", "localDeclaration",
  "$@15", "$@16", "$@17", "varDeclaration", "$@18", "$@19",
  "statementList", "statement", "$@20", "$@21", "$@22", "$@23", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33",
  "if_stmt", "$@34", "if_else", "$@35", "else_if", "$@36", "$@37",
  "condition", "$@38", "$@39", "expression", "additiveExpression", "relop",
  "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "$@46", "$@47", "$@48",
  "term", "addop", "$@49", "$@50", "mulop", "$@51", "$@52", "factor",
  "$@53", "$@54", "$@55", "$@56", "$@57", "$@58", "$@59", "$@60", "args",
  "$@61", "$@62", "$@63", 0
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
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    40,    39,    42,    43,    41,
      45,    44,    44,    46,    44,    44,    48,    49,    50,    51,
      47,    53,    52,    54,    52,    55,    52,    57,    58,    56,
      60,    59,    61,    59,    62,    59,    59,    64,    65,    63,
      66,    66,    67,    67,    67,    67,    68,    67,    69,    70,
      67,    71,    72,    73,    74,    75,    76,    67,    77,    78,
      79,    80,    81,    67,    83,    82,    85,    84,    87,    88,
      86,    90,    91,    89,    92,    92,    93,    93,    95,    94,
      96,    94,    97,    94,    98,    94,    99,    94,   100,    94,
     101,    94,   102,    94,   103,    94,   104,   104,   106,   105,
     107,   105,   109,   108,   110,   108,   112,   113,   111,   114,
     115,   116,   111,   117,   111,   118,   111,   119,   111,   121,
     120,   120,   122,   120,   123,   120,   120
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     0,     5,     0,     0,     5,
       0,     4,     1,     0,     3,     0,     0,     0,     0,     0,
       9,     0,     2,     0,     2,     0,     2,     0,     0,     6,
       0,     4,     0,     4,     0,     3,     0,     0,     0,     6,
       2,     1,     1,     1,     2,     3,     0,     4,     0,     0,
       5,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,    10,     0,     4,     0,     3,     0,     0,
       6,     0,     0,     5,     3,     1,     3,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     3,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     0,     5,     0,
       0,     0,     7,     0,     2,     0,     2,     0,     2,     0,
       4,     1,     0,     2,     0,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    25,    16,    23,     3,     2,     0,
      26,     0,    22,    24,     5,    17,     0,     0,     7,     0,
      18,    15,    27,     6,     0,    21,     0,     0,    36,    19,
       8,    10,    13,     0,     0,     0,     0,     9,    15,    14,
      37,    51,    64,    46,    48,   115,   117,   113,   106,     0,
      41,    43,    42,    75,    77,    97,    32,    30,    20,    11,
       0,     0,     0,     0,     0,     0,   116,   118,     0,   114,
       0,    28,    40,    66,    44,     0,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    98,   100,     0,     0,   104,
     102,     0,    36,    35,    36,    38,    52,    59,    71,     0,
       0,     0,   110,     0,    29,     0,     0,    66,    45,    79,
      81,    83,    85,    87,    89,    91,    93,    95,    99,   101,
      74,    76,   105,   103,    96,    33,    31,     0,     0,     0,
       0,    65,    47,    49,   126,   107,    67,    69,    39,    53,
      60,     0,    50,   124,   122,     0,   108,     0,     0,     0,
      72,   125,   123,   111,   119,     0,    54,    61,    73,   112,
     126,    70,     0,     0,   120,     0,    62,    55,    63,     0,
      56,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    16,    19,    21,    37,    26,    38,
      39,     8,    11,    17,    24,    36,    33,    12,    13,    10,
      23,    28,   104,    34,    94,    92,    93,    35,    60,   127,
      49,    50,    64,    65,   142,    61,   128,   148,   162,   169,
     171,    62,   129,   149,   163,   168,    51,    63,    74,   105,
      75,   106,   147,    99,   130,   158,    52,    53,    87,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    54,    88,
     118,   119,    91,   123,   122,    55,    70,   146,    68,   134,
     159,    69,    66,    67,   145,   160,   152,   151
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -69
static const yytype_int8 yypact[] =
{
     -69,    24,    13,   -69,   -69,    -9,   -69,   -69,   -69,    22,
     -69,    15,   -69,   -69,   -69,   -69,   -17,     2,   -69,    25,
     -69,    19,   -69,   -69,    27,   -69,    -2,    36,    19,   -69,
     -69,   -69,   -69,    42,     1,    18,    25,   -69,    19,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,    29,   -69,    28,
       1,    54,   -69,    21,    26,   -69,   -69,   -69,   -69,    31,
      45,    37,    40,    41,    41,     5,   -69,   -69,    43,   -69,
       5,   -69,   -69,    67,   -69,    68,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     5,     5,   -69,
     -69,     5,    19,   -69,    19,   -69,   -69,   -69,   -69,    25,
      25,    44,   -69,    46,   -69,    25,    70,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,    26,   -69,   -69,   -69,   -69,   -69,     5,    61,    64,
       5,   -69,   -69,   -69,    -4,   -69,   -69,   -69,   -69,   -69,
     -69,    49,   -69,   -69,   -69,    -1,   -69,    41,    47,    50,
     -69,   -69,   -69,   -69,   -69,    25,   -69,   -69,   -69,   -69,
      -4,   -69,     5,    51,    48,    55,   -69,   -69,   -69,    53,
     -69,   -69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    52,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,     0,   -69,   -69,   -69,
     -36,   -69,   -69,   -43,   -69,   -69,   -69,   -69,   -69,   -69,
      38,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    14,   -69,
     -69,   -69,   -69,   -63,   -69,   -69,   -62,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     3,   -69,
     -69,   -69,   -69,   -69,   -69,     4,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -68,   -69,   -69,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -110
static const yytype_int16 yytable[] =
{
      58,   100,     9,   101,    41,   -21,    42,   143,   103,    43,
     144,    44,    45,    18,    46,    47,    45,     4,    46,    47,
       5,    27,     6,     4,     3,   120,    25,    15,     6,    30,
     153,    48,    20,    31,   154,    48,    14,    76,    27,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   125,
      32,   126,    56,    57,    89,    90,    40,    22,    29,  -109,
      73,    71,    95,   131,   132,   138,    31,    96,   141,   136,
      97,    98,   -68,   102,   107,   137,   139,   135,   133,   140,
     150,   157,   156,   154,   155,   166,   167,   170,    72,   108,
      59,   121,   164,     0,     0,   124,     0,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161
};

static const yytype_int16 yycheck[] =
{
      36,    64,     2,    65,     3,    14,     5,    11,    70,     8,
      14,    10,    11,    30,    13,    14,    11,     4,    13,    14,
       7,    21,     9,     4,     0,    87,     7,    12,     9,    31,
      31,    30,    30,    35,    35,    30,    14,    16,    38,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    92,
      14,    94,    34,    35,    28,    29,    14,    32,    31,    30,
       6,    33,    17,    99,   100,   127,    35,    30,   130,   105,
      30,    30,     5,    30,     6,     5,    15,    31,    34,    15,
      31,    31,    35,    35,   147,    34,    31,    34,    50,    75,
      38,    88,   160,    -1,    -1,    91,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,     0,     4,     7,     9,    39,    47,    52,
      55,    48,    53,    54,    14,    12,    40,    49,    30,    41,
      30,    42,    32,    56,    50,     7,    44,    52,    57,    31,
      31,    35,    14,    52,    59,    63,    51,    43,    45,    46,
      14,     3,     5,     8,    10,    11,    13,    14,    30,    66,
      67,    82,    92,    93,   104,   111,    34,    35,    56,    44,
      64,    71,    77,    83,    68,    69,   118,   119,   114,   117,
     112,    33,    66,     6,    84,    86,    16,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    94,   105,    28,
      29,   108,    61,    62,    60,    17,    30,    30,    30,    89,
      89,    92,    30,    92,    58,    85,    87,     6,    84,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   106,   107,
      92,   104,   110,   109,   111,    59,    59,    65,    72,    78,
      90,    56,    56,    34,   115,    31,    56,     5,    92,    15,
      15,    92,    70,    11,    14,   120,   113,    88,    73,    79,
      31,   123,   122,    31,    35,    89,    35,    31,    91,   116,
     121,    56,    74,    80,   120,    92,    34,    31,    81,    75,
      34,    76
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, NULL, NULL, NULL, "program"); head = (yyval.nd_obj).nd;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 60 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, NULL, NULL, NULL, "functionList");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    { add('V', "ID"); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {(yyvsp[(2) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (5)].nd_obj).nd, (yyvsp[(2) - (5)].nd_obj).nd, (yyvsp[(4) - (5)].nd_obj).nd, (yyvsp[(5) - (5)].nd_obj).nd, NULL, "function");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    { add('S', "O_BRACK"); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    { add('S', "C_BRACK"); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    {(yyvsp[(1) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); (yyvsp[(4) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (5)].nd_obj).nd, (yyvsp[(3) - (5)].nd_obj).nd, (yyvsp[(4) - (5)].nd_obj).nd, NULL, NULL, "paramList");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    { add('S', "COMMA"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    {(yyvsp[(2) - (4)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "COMMA"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(2) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, NULL, NULL, "param");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "param");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { add('V', "ID"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    {(yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, NULL, NULL, NULL, "param");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { add('K', "INT"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { add('K', "MAIN"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { add('S', "O_BRACK"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { add('S', "C_BRACK"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {(yyvsp[(1) - (9)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "INT"); (yyvsp[(3) - (9)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "MAIN"); (yyvsp[(5) - (9)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); (yyvsp[(7) - (9)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (9)].nd_obj).nd, (yyvsp[(3) - (9)].nd_obj).nd, (yyvsp[(5) - (9)].nd_obj).nd, (yyvsp[(7) - (9)].nd_obj).nd, (yyvsp[(9) - (9)].nd_obj).nd, "main");;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    { add('K', "INT"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "INT"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "type");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    { add('K', "FLOAT"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "FLOAT"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "type");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    { add('K', "VOID"); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "VOID"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "type");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { add('S', "OC_BRACK"); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { add('S', "CC_BRACK"); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    {(yyvsp[(1) - (6)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "OC_BRACK"); (yyvsp[(5) - (6)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "CC_BRACK"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (6)].nd_obj).nd, (yyvsp[(3) - (6)].nd_obj).nd, (yyvsp[(4) - (6)].nd_obj).nd, (yyvsp[(5) - (6)].nd_obj).nd, NULL, "compStmt");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    { add('S', "COMMA"); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {(yyvsp[(2) - (4)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "COMMA"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(2) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, NULL, NULL, "Declarations");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { add('S', "S_COLON"); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {(yyvsp[(2) - (4)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(2) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, NULL, NULL, "Declarations");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    { add('S', "S_COLON"); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {(yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, NULL, NULL, NULL, "Declarations");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { add('V', "ID"); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { add('O', "ASSIGN"); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {(yyvsp[(2) - (6)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); (yyvsp[(4) - (6)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ASSIGN"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (6)].nd_obj).nd, (yyvsp[(2) - (6)].nd_obj).nd, (yyvsp[(4) - (6)].nd_obj).nd, (yyvsp[(6) - (6)].nd_obj).nd, NULL, "var");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, NULL, NULL, NULL, "stmtList");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "stmtList");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "stmt");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "stmt");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, NULL, NULL, NULL, "stmt");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, NULL, NULL, "stmt");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    { add('K', "WHILE"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, NULL, NULL, NULL, "while_stmt");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    { add('K', "RETURN"); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    { add('S', "S_COLON"); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {(yyvsp[(1) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "RETURN"); (yyvsp[(4) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (5)].nd_obj).nd, (yyvsp[(3) - (5)].nd_obj).nd, (yyvsp[(4) - (5)].nd_obj).nd, NULL, NULL, "stmt");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { add('K', "PRINTF"); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { add('S', "O_BRACK"); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { add('C', "STRING"); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { add('S', "COMMA"); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { add('S', "C_BRACK"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { add('S', "S_COLON"); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {(yyvsp[(1) - (13)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "PRINTF"); (yyvsp[(3) - (13)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); (yyvsp[(5) - (13)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "STRING"); (yyvsp[(10) - (13)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); (yyvsp[(12) - (13)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); (yyvsp[(7) - (13)].nd_obj).nd = mknode((yyvsp[(9) - (13)].nd_obj).nd, (yyvsp[(10) - (13)].nd_obj).nd, (yyvsp[(12) - (13)].nd_obj).nd, NULL, NULL, "COMMA"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (13)].nd_obj).nd, (yyvsp[(3) - (13)].nd_obj).nd, (yyvsp[(5) - (13)].nd_obj).nd, (yyvsp[(7) - (13)].nd_obj).nd, NULL, "stmt");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { add('K', "PRINTF"); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { add('S', "O_BRACK"); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { add('C', "STRING"); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { add('S', "C_BRACK"); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { add('S', "S_COLON"); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {(yyvsp[(1) - (10)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "PRINTF"); (yyvsp[(3) - (10)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); (yyvsp[(5) - (10)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "STRING"); (yyvsp[(7) - (10)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); (yyvsp[(9) - (10)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "S_COLON"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (10)].nd_obj).nd, (yyvsp[(3) - (10)].nd_obj).nd, (yyvsp[(5) - (10)].nd_obj).nd, (yyvsp[(7) - (10)].nd_obj).nd, (yyvsp[(9) - (10)].nd_obj).nd, "stmt");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { add('K', "IF"); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {(yyvsp[(1) - (4)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "IF"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(3) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, NULL, NULL, "if_stmt");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    { add('K', "ELSE"); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {(yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ELSE"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, NULL, NULL, NULL, "if_stmt");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { add('K', "ELSE"); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { add('K', "IF"); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {(yyvsp[(1) - (6)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ELSE"); (yyvsp[(3) - (6)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "IF"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (6)].nd_obj).nd, (yyvsp[(3) - (6)].nd_obj).nd, (yyvsp[(5) - (6)].nd_obj).nd, (yyvsp[(6) - (6)].nd_obj).nd, NULL, "if_stmt");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { add('S', "O_BRACK"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { add('S', "C_BRACK"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {(yyvsp[(1) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); (yyvsp[(4) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (5)].nd_obj).nd, (yyvsp[(3) - (5)].nd_obj).nd, (yyvsp[(4) - (5)].nd_obj).nd, NULL, NULL, "condition");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, NULL, NULL, "expr");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "expr");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, NULL, NULL, "addExp");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "addExp");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { add('O', "LE"); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "LE"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    { add('O', "GE"); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "GE"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    { add('O', "EQ"); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "EQ"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { add('O', "NE"); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "NE"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    { add('O', "GT"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "GT"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { add('O', "LT"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "LT"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { add('O', "AND"); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "AND"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { add('O', "OR"); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "OR"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { add('O', "NOT"); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "NOT"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "relop");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, NULL, NULL, "term");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "term");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { add('O', "ADD"); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ADD"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "addop");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    { add('O', "SUBTRACT"); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "SUBTRACT"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "addop");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { add('O', "MULTIPLY"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "MULTIPLY"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "mulop");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { add('O', "DIVIDE"); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "DIVIDE"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "mulop");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { add('S', "O_BRACK"); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { add('S', "C_BRACK"); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyvsp[(1) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); (yyvsp[(4) - (5)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (5)].nd_obj).nd, (yyvsp[(3) - (5)].nd_obj).nd, (yyvsp[(4) - (5)].nd_obj).nd, NULL, NULL, "factor");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { add('V', "ID"); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { add('S', "O_BRACK"); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { add('S', "C_BRACK"); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyvsp[(1) - (7)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); (yyvsp[(3) - (7)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "O_BRACK"); (yyvsp[(6) - (7)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "C_BRACK"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (7)].nd_obj).nd, (yyvsp[(3) - (7)].nd_obj).nd, (yyvsp[(5) - (7)].nd_obj).nd, (yyvsp[(6) - (7)].nd_obj).nd, NULL, "funCall");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { add('V', "ID"); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "factor");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { add('C', "NUMBER"); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "NUMBER"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "factor");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { add('C', "FLOAT_NUM"); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "FLOAT_NUM"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "factor");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    { add('S', "COMMA"); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {(yyvsp[(2) - (4)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "COMMA"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(2) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, NULL, NULL, "args");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, NULL, NULL, NULL, "args");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { add('V', "ID"); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "ID"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "args");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { add('C', "NUMBER"); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {(yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, NULL, NULL, NULL, "NUMBER"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, NULL, NULL, NULL, "args");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2448 "parser.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 170 "parser.y"


int main() {
    yyparse();
    printf("\n\n");
    printf("\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    printf("\nSYMBOL\t\tTYPE\t\tTOKEN\t\tLINE NUMBER \n");
    printf("_______________________________________________________\n\n");
    int i=0;
    for(i=0; i<count; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t\n", symbol_table[i].id_name, symbol_table[i].type, symbol_table[i].data_type, symbol_table[i].line_no);
    }
    for(i=0;i<count;i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }

    printf("\n\n");
    printf("\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    int branch[100] = {0};

    printTree(head, 0, branch); 
    printf("\n\n");
}

void add(char c, char *str) {
    if(c == 'S') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Symbol");
            count++;
        }
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Keyword\t");
            count++;
        }
        else if(c == 'V') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Variable");
            count++;
        }
        else if(c == 'C') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Value");
            count++;
        }
        else if(c == 'O') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(str);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Operator");
            count++;
        }
	
}

struct node* mknode(struct node *one, struct node *two, struct node *three, struct node *four, struct node *five, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->one = one;
	newnode->two = two;
    newnode->three = three;
	newnode->four = four;
    newnode->five = five;
	newnode->token = newstr;
	return(newnode);
}


void printBranches(int branch[], int depth) {
    for (int i = 0; i < depth; ++i) {
        if (i == depth - 1) {
            printf("|-- ");
        } else {
            printf(branch[i] ? "|   " : "    ");
        }
    }
}

void printTree(struct node *root, int depth, int branch[]) {
    if (root == NULL) {
        return;
    }

    printBranches(branch, depth);
    printf("%s\n", root->token);

    // Update the branch array: 1 if sibling nodes exist, 0 otherwise
    branch[depth] = (root->two != NULL || root->three != NULL || root->four != NULL || root->five != NULL);

    printTree(root->one, depth + 1, branch);
    printTree(root->two, depth + 1, branch);
    printTree(root->three, depth + 1, branch);
    printTree(root->four, depth + 1, branch);

    // For the last node, change the branch symbol
    if (root->five != NULL) {
        branch[depth] = 0; // No more siblings
        printBranches(branch, depth);
        printf("| ");
        printTree(root->five, depth + 1, branch);
    }
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}


