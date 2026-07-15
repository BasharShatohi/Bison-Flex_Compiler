/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NEWLINE = 258,
     IDENTIFIER = 259,
     STRING = 260,
     LPAREN = 261,
     RPAREN = 262,
     SEMICOLON = 263,
     PRINT = 264,
     ERROR = 265,
     RANGE = 266,
     ASSERT = 267,
     ASYNC = 268,
     EOL = 269,
     AWAIT = 270,
     DEL = 271,
     FROM = 272,
     IMPORT = 273,
     IN = 274,
     IS = 275,
     LAMBDA = 276,
     PASS = 277,
     RAISE = 278,
     COMMA = 279,
     AND = 280,
     COLON = 281,
     LBRACE = 282,
     RBRACE = 283,
     ADD = 284,
     SUB = 285,
     MUL = 286,
     DIV = 287,
     POW = 288,
     COMMENT_STRING = 289,
     NUMBER = 290,
     UNDERSCORE = 291,
     DOT = 292,
     AT = 293,
     LBRACKET = 294,
     RBRACKET = 295,
     EQ = 296,
     GE = 297,
     LE = 298,
     GT = 299,
     LT = 300,
     MOD = 301,
     OR = 302,
     NOT = 303,
     ASSIGNMENT = 304,
     EQUALITY = 305,
     RELATIONAL = 306,
     IDENTITY = 307,
     MEMBERSHIP = 308,
     DEDENT = 309,
     INDENT = 310,
     LOGICALAND = 311,
     LOGICALOR = 312,
     LOGICALNOT = 313,
     BITWISESHIFT = 314,
     ARROW = 315,
     RETURN = 316,
     BREAK = 317,
     CONTINUE = 318,
     GLOBAL = 319,
     NONLOCAL = 320,
     YIELD = 321,
     IF = 322,
     CLASS = 323,
     ELIF = 324,
     ELSE = 325,
     WHILE = 326,
     FOR = 327,
     WITH = 328,
     AS = 329,
     TRY = 330,
     EXCEPT = 331,
     FINALLY = 332,
     MATCH = 333,
     CASE = 334,
     DEF = 335,
     DIVFLOOR = 336,
     EXPONENTIATION = 337,
     UNARY = 338
   };
#endif
/* Tokens.  */
#define NEWLINE 258
#define IDENTIFIER 259
#define STRING 260
#define LPAREN 261
#define RPAREN 262
#define SEMICOLON 263
#define PRINT 264
#define ERROR 265
#define RANGE 266
#define ASSERT 267
#define ASYNC 268
#define EOL 269
#define AWAIT 270
#define DEL 271
#define FROM 272
#define IMPORT 273
#define IN 274
#define IS 275
#define LAMBDA 276
#define PASS 277
#define RAISE 278
#define COMMA 279
#define AND 280
#define COLON 281
#define LBRACE 282
#define RBRACE 283
#define ADD 284
#define SUB 285
#define MUL 286
#define DIV 287
#define POW 288
#define COMMENT_STRING 289
#define NUMBER 290
#define UNDERSCORE 291
#define DOT 292
#define AT 293
#define LBRACKET 294
#define RBRACKET 295
#define EQ 296
#define GE 297
#define LE 298
#define GT 299
#define LT 300
#define MOD 301
#define OR 302
#define NOT 303
#define ASSIGNMENT 304
#define EQUALITY 305
#define RELATIONAL 306
#define IDENTITY 307
#define MEMBERSHIP 308
#define DEDENT 309
#define INDENT 310
#define LOGICALAND 311
#define LOGICALOR 312
#define LOGICALNOT 313
#define BITWISESHIFT 314
#define ARROW 315
#define RETURN 316
#define BREAK 317
#define CONTINUE 318
#define GLOBAL 319
#define NONLOCAL 320
#define YIELD 321
#define IF 322
#define CLASS 323
#define ELIF 324
#define ELSE 325
#define WHILE 326
#define FOR 327
#define WITH 328
#define AS 329
#define TRY 330
#define EXCEPT 331
#define FINALLY 332
#define MATCH 333
#define CASE 334
#define DEF 335
#define DIVFLOOR 336
#define EXPONENTIATION 337
#define UNARY 338




/* Copy the first part of user declarations.  */
#line 1 "p.y"

#include <stdio.h>
#include <string.h>
#include "classes.hpp"
#include <iostream>

%union{
	AstNode* astNode;
        IdentifierNode* idNode;
	int d;
}

extern FILE* yyin;
extern FILE* yyout;
int yydebug = 1;
extern int yylex();
void yyerror(const char* s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 281 "p.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1790

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  46
/* YYNRULES -- Number of rules. */
#define YYNRULES  150
/* YYNRULES -- Number of states. */
#define YYNSTATES  334

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    88,    83,     2,
       2,     2,    86,    84,     2,    85,     2,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    81,     2,    92,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    89,    90,    91
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    15,    17,    19,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    38,    40,
      42,    44,    46,    48,    50,    52,    54,    56,    58,    60,
      62,    67,    69,    73,    77,    81,    85,    89,    93,    97,
     101,   105,   109,   113,   117,   121,   125,   129,   132,   136,
     140,   144,   148,   152,   156,   160,   164,   168,   172,   176,
     180,   184,   188,   191,   194,   197,   201,   203,   207,   209,
     213,   217,   221,   225,   227,   233,   239,   243,   246,   249,
     252,   256,   260,   264,   270,   276,   282,   288,   290,   294,
     299,   305,   313,   320,   324,   328,   333,   342,   349,   351,
     353,   355,   363,   365,   369,   373,   379,   386,   388,   391,
     396,   397,   399,   403,   405,   409,   411,   413,   417,   421,
     423,   427,   429,   433,   435,   438,   443,   449,   451,   453,
     455,   459,   464,   471,   472,   476,   484,   488,   492,   498,
     506,   514,   520,   531,   532,   535,   539,   541,   543,   547,
     551
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
      95,     0,    -1,    96,    -1,    97,    -1,    97,     3,    96,
      -1,    55,    96,    54,    -1,    98,    -1,    99,    -1,    -1,
     100,    -1,   101,    -1,   103,    -1,   104,    -1,   105,    -1,
     106,    -1,   107,    -1,   108,    -1,   109,    -1,    34,    -1,
     115,    -1,   110,    -1,   117,    -1,   113,    -1,   114,    -1,
     118,    -1,   122,    -1,   134,    -1,   137,    -1,   111,    -1,
     112,    -1,     9,     6,   102,     7,    -1,   102,    -1,   102,
      29,   102,    -1,   102,    30,   102,    -1,   102,    31,   102,
      -1,   102,    32,   102,    -1,   102,    41,   102,    -1,   102,
      42,   102,    -1,   102,    43,   102,    -1,   102,    44,   102,
      -1,   102,    45,   102,    -1,   102,    33,   102,    -1,   102,
      46,   102,    -1,   102,    25,   102,    -1,   102,    38,   102,
      -1,   102,    57,   102,    -1,   102,    56,   102,    -1,    58,
     102,    -1,   102,    52,   102,    -1,   102,    53,   102,    -1,
     102,    50,   102,    -1,   102,    51,   102,    -1,   102,    81,
     102,    -1,   102,    82,   102,    -1,   102,    83,   102,    -1,
     102,    59,   102,    -1,   102,    84,   102,    -1,   102,    85,
     102,    -1,   102,    86,   102,    -1,   102,    88,   102,    -1,
     102,    87,   102,    -1,   102,    89,   102,    -1,    85,   102,
      -1,    84,   102,    -1,    92,   102,    -1,   102,    90,   102,
      -1,    35,    -1,    35,    24,    35,    -1,     5,    -1,     5,
      24,   102,    -1,   102,    24,   102,    -1,     6,   102,     7,
      -1,     4,    49,   102,    -1,     4,    -1,     4,    49,    39,
     102,    40,    -1,     4,    74,     4,    49,   102,    -1,    61,
     128,     8,    -1,    61,     8,    -1,    62,     8,    -1,    63,
       8,    -1,    64,   129,     8,    -1,    65,   129,     8,    -1,
      66,   128,     8,    -1,     4,     6,   130,     7,    24,    -1,
       4,     6,   130,     7,    49,    -1,    67,   102,    26,    96,
     111,    -1,    69,   102,    26,    96,   111,    -1,   112,    -1,
      70,    26,    96,    -1,    71,   102,    26,    96,    -1,    71,
     102,    26,    96,   112,    -1,    72,     4,    19,    11,   102,
      26,    96,    -1,    72,     4,    19,   102,    26,    96,    -1,
      12,   102,     8,    -1,    27,    96,    28,    -1,    68,     4,
      26,    96,    -1,    68,     4,     6,   132,     7,    26,    96,
       8,    -1,    73,   118,    26,    96,   112,     8,    -1,   131,
      -1,   121,    -1,   119,    -1,     6,   120,     7,    74,     6,
     129,     7,    -1,   131,    -1,   131,    24,   120,    -1,   131,
      74,     4,    -1,   131,    74,     4,    24,   121,    -1,    75,
      26,    96,   123,   112,   133,    -1,   124,    -1,   124,   123,
      -1,    76,   125,    26,    96,    -1,    -1,   131,    -1,     6,
     120,     7,    -1,   126,    -1,     4,    74,   131,    -1,     4,
      -1,    36,    -1,     4,    93,     4,    -1,   102,    24,   128,
      -1,   102,    -1,     4,    24,   129,    -1,     4,    -1,   102,
      24,   130,    -1,   102,    -1,    90,     4,    -1,    86,     4,
      24,   130,    -1,     4,    49,   102,    24,   130,    -1,     4,
      -1,   109,    -1,     4,    -1,     4,    24,   132,    -1,     4,
      39,   129,    40,    -1,     4,    39,   129,    40,    24,   132,
      -1,    -1,    77,    26,   116,    -1,    78,   101,    26,    55,
     135,    54,     8,    -1,   136,   112,     8,    -1,   136,   135,
       8,    -1,    79,   101,    26,   116,     8,    -1,    79,     4,
      74,     4,    26,   116,     8,    -1,    79,   101,    67,   128,
      26,   116,     8,    -1,    80,     4,   102,    26,    96,    -1,
      80,     4,     6,   138,     7,    60,     4,    26,    96,     8,
      -1,    -1,   127,    24,    -1,   127,    24,   138,    -1,   139,
      -1,     4,    -1,     4,    26,     4,    -1,     4,    49,   101,
      -1,     4,    49,   101,    24,   139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    47,    47,    49,    50,    51,    54,    58,    64,    65,
      69,    74,    79,    84,    89,    94,    99,   104,   109,   114,
     120,   124,   128,   132,   136,   140,   144,   148,   152,   156,
     161,   168,   174,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   224,   225,   227,   229,
     231,   233,   235,   237,   238,   241,   243,   244,   246,   251,
     252,   254,   255,   259,   265,   268,   269,   273,   274,   275,
     276,   278,   280,   281,   284,   285,   288,   290,   291,   293,
     294,   295,   296,   297,   299,   301,   302,   303,   307,   308,
     310,   311,   314,   315,   316,   317,   318,   325,   326,   328,
     329,   330,   331,   334,   335,   337,   338,   339,   341,   342,
     343,   346,   347,   350,   351,   352,   353,   355,   356,   358,
     359
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEWLINE", "IDENTIFIER", "STRING",
  "LPAREN", "RPAREN", "SEMICOLON", "PRINT", "ERROR", "RANGE", "ASSERT",
  "ASYNC", "EOL", "AWAIT", "DEL", "FROM", "IMPORT", "IN", "IS", "LAMBDA",
  "PASS", "RAISE", "COMMA", "AND", "COLON", "LBRACE", "RBRACE", "ADD",
  "SUB", "MUL", "DIV", "POW", "COMMENT_STRING", "NUMBER", "UNDERSCORE",
  "DOT", "AT", "LBRACKET", "RBRACKET", "EQ", "GE", "LE", "GT", "LT", "MOD",
  "OR", "NOT", "ASSIGNMENT", "EQUALITY", "RELATIONAL", "IDENTITY",
  "MEMBERSHIP", "DEDENT", "INDENT", "LOGICALAND", "LOGICALOR",
  "LOGICALNOT", "BITWISESHIFT", "ARROW", "RETURN", "BREAK", "CONTINUE",
  "GLOBAL", "NONLOCAL", "YIELD", "IF", "CLASS", "ELIF", "ELSE", "WHILE",
  "FOR", "WITH", "AS", "TRY", "EXCEPT", "FINALLY", "MATCH", "CASE", "DEF",
  "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "DIVFLOOR",
  "EXPONENTIATION", "UNARY", "'~'", "':'", "$accept", "program", "stats",
  "stat", "simple_stat", "compound_stat", "print", "expression_stat",
  "expression", "return", "break", "continue", "global", "nonlocal",
  "yield", "function_call", "if", "elif", "else", "while", "for", "assert",
  "block", "class", "with", "complex_with_as_stat", "args_generator",
  "with_as", "try", "except_stat_list", "except_stat", "except_expression",
  "exception_as", "function_identifier_parameter", "args_expressions",
  "args_identifiers", "args", "generator", "class_args", "finally_stat",
  "match", "pattern_list", "pattern", "function_def",
  "function_declaratin_args", "keyword_args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   124,    94,    38,    43,    45,    42,    47,    37,   336,
     337,   338,   126,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    94,    95,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   104,   105,
     106,   107,   108,   109,   109,   110,   111,   111,   112,   113,
     113,   114,   114,   115,   116,   117,   117,   118,   118,   118,
     118,   119,   120,   120,   121,   121,   122,   123,   123,   124,
     125,   125,   125,   125,   126,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   132,   132,   133,   133,   134,   135,   135,   136,   136,
     136,   137,   137,   138,   138,   138,   138,   127,   127,   139,
     139
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     3,     3,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     1,     3,     1,     3,
       3,     3,     3,     1,     5,     5,     3,     2,     2,     2,
       3,     3,     3,     5,     5,     5,     5,     1,     3,     4,
       5,     7,     6,     3,     3,     4,     8,     6,     1,     1,
       1,     7,     1,     3,     3,     5,     6,     1,     2,     4,
       0,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       3,     1,     3,     1,     2,     4,     5,     1,     1,     1,
       3,     4,     6,     0,     3,     7,     3,     3,     5,     7,
       7,     5,    10,     0,     2,     3,     1,     1,     3,     3,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       8,    73,    68,     0,     0,     0,    18,    66,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     6,     7,     9,    10,    31,    11,    12,    13,
      14,    15,    16,    17,    20,    28,    29,    22,    23,    19,
      21,    24,   100,    99,    25,    98,    26,    27,     0,     0,
       0,     0,     0,     0,   128,     0,   102,     0,    73,     0,
       0,     0,    47,    77,   119,     0,    78,    79,   121,     0,
       0,     0,     0,     0,     0,     8,     0,     0,   127,     0,
       0,     8,     0,     0,    63,    62,    64,     1,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,   123,     0,     0,    72,     0,    69,
      71,     0,     0,     0,    93,    67,     5,     0,    76,     0,
      80,    81,    82,     8,     0,     8,     8,    88,     8,     0,
       8,     0,     0,   143,     0,     4,    70,    43,    32,    33,
      34,    35,    41,    44,    36,    37,    38,    39,    40,    42,
      50,    51,    48,    49,    46,    45,    55,    52,    53,    54,
      56,    57,    58,    60,    59,    61,    65,   104,     0,     0,
     124,     0,     0,     0,     0,     0,   103,    30,    70,   118,
     120,     0,   129,     0,    95,     0,    89,     0,     0,     0,
     110,     0,   107,     0,    73,   116,     0,     0,   146,     8,
       0,    72,     0,    70,   122,    83,    84,    74,    75,     0,
      85,    87,     0,     0,     0,    86,    90,     0,     8,     0,
     127,     0,     0,   113,   111,   133,   108,     0,     0,     0,
       0,     0,     0,   143,     0,   141,   105,     0,     0,   125,
       0,   130,     0,     8,     8,    92,    97,     0,     0,     8,
       0,   106,    73,     0,     0,     0,     0,   148,   149,    31,
     117,   115,   145,     0,   126,   101,   131,     0,    91,   114,
     112,   109,     0,     0,     0,     0,   135,   136,   137,     0,
       0,     0,     0,    96,     8,   134,     0,     0,     0,     0,
     150,     8,   132,     0,     0,   138,     0,     0,    94,     0,
       0,   142,   139,   140
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   315,    50,    51,    52,    65,    53,    54,   221,
     222,   252,   253,   226,    75,    79,   135,    55,   213,   281,
      56,   258,   259,    57,   227,   228
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -260
static const short int yypact[] =
{
     264,     1,    10,   306,    40,   346,  -260,    45,   264,   346,
     170,    63,    65,    68,    68,   346,   346,    70,   346,    50,
     346,    78,    12,    58,   346,    84,   346,   346,   346,    93,
    -260,    91,  -260,  -260,  -260,  -260,  1100,  -260,  -260,  -260,
    -260,  -260,  -260,    55,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,    57,  -260,  -260,   133,   203,
     128,   346,   346,   430,  -260,   127,   112,   346,   -26,   564,
     105,    87,  1435,  -260,  1167,   135,  -260,  -260,   125,   143,
     145,   146,   631,    29,   698,   264,   765,   137,   151,   155,
     134,   264,   138,   361,  1401,  1401,  1401,  -260,   264,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     157,   -25,   159,   161,  1234,   160,   346,  1100,   117,  1100,
    -260,    95,   155,   497,  -260,  -260,  -260,   346,  -260,    68,
    -260,  -260,  -260,   264,   166,   264,   264,  -260,   264,   303,
     264,    96,   116,   341,   832,  -260,  1100,  1100,  1100,  1100,
    1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,  1100,
    1467,  1467,  1467,  1467,  1435,  1368,  1633,  1534,  1566,  1602,
    1669,  1669,  1700,  1700,  1700,  1700,  1401,   149,   203,   153,
    -260,   133,     7,   899,   346,   173,  -260,  -260,  1167,  -260,
    -260,    17,    23,   174,  -260,    17,   110,   346,   966,   110,
      64,   110,    96,   103,     4,  -260,   162,   176,  -260,   264,
     155,  1301,   133,  1234,  -260,  -260,  -260,  -260,  1100,    68,
    -260,  -260,   166,    68,   158,  -260,  -260,  1033,   264,   177,
       5,   155,   163,  -260,  -260,   111,  -260,   365,   136,   -28,
     183,   203,   188,     8,   139,  -260,  -260,    57,   133,  -260,
     186,  -260,   154,   264,   264,  -260,  -260,   155,   189,   264,
     169,  -260,   -10,   -13,   190,   193,   194,  -260,   180,  1100,
    -260,     3,  -260,   202,  -260,  -260,   187,   204,  -260,  -260,
    -260,  -260,   197,   206,   197,   346,  -260,  -260,  -260,   209,
     346,   200,   166,  -260,   264,  -260,    14,   207,   201,   165,
    -260,   264,  -260,   205,   197,  -260,   197,   221,  -260,   226,
     227,  -260,  -260,  -260
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -260,  -260,    -8,  -260,  -260,  -260,  -260,   -18,    -1,  -260,
    -260,  -260,  -260,  -260,  -260,     0,  -260,  -179,  -178,  -260,
    -260,  -260,  -259,  -260,   214,  -260,  -121,    11,  -260,    15,
    -260,  -260,  -260,  -260,   -14,     6,  -173,     2,  -232,  -260,
    -260,   -15,  -260,  -260,   -17,   -62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -129
static const short int yytable[] =
{
      71,    81,    63,    64,    69,    66,    92,    58,    72,    74,
     271,    58,   291,   304,    74,    82,    88,    84,    89,    86,
      80,   206,    64,    59,   198,    94,    95,    96,   234,   260,
     260,   235,   240,   241,    61,   154,   245,   241,   246,    59,
     324,   249,    19,   255,   225,   317,    67,   242,    60,    60,
      59,   257,   310,   261,   305,   155,   236,   134,   137,   269,
     139,    63,   243,   204,   303,   329,   143,   330,   250,    70,
     251,    76,    78,    77,    83,    60,    85,   157,    60,   277,
     322,   285,    87,   161,    91,    22,    18,    19,    93,    64,
     165,    66,   164,    97,    98,   294,   262,   262,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,  -128,
     278,   130,   138,   209,   141,   203,   142,   131,     2,    62,
     145,   146,    64,   148,    66,   211,   208,   214,   215,   149,
     216,   150,   219,   151,   152,   210,   159,    58,   218,    88,
     160,   197,    63,   199,   162,   200,   204,   202,     7,   205,
     212,   223,   220,   230,    68,     2,    62,   232,    73,   239,
      19,   244,   257,   264,   273,   276,   263,   287,   280,   279,
     284,     9,   290,   295,   296,   302,   300,   231,   306,   293,
     233,   307,   308,   238,   309,     7,   311,    68,     2,    62,
     316,   312,   313,   319,   310,   325,   247,    26,    27,   132,
      64,   265,   254,   133,   314,    28,   321,   326,     9,   331,
      64,   134,   267,   328,   332,   333,    90,   256,     7,   283,
     275,   266,   136,   288,   286,   270,   292,   320,     0,   272,
       0,    64,     0,    66,    26,    27,     0,     0,     0,     0,
     289,     9,    28,     0,     0,   297,   298,   233,     1,     2,
       3,   301,     0,     4,     0,     0,     5,    64,     0,   299,
       0,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,   318,   288,     0,     0,    28,     0,     0,     6,     7,
       0,     0,     0,     0,    74,     0,   323,    68,     2,    62,
       1,     2,    62,   327,   217,     0,     0,     0,     0,     8,
       0,     0,     9,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     7,    23,
       0,     7,    24,     0,    25,   224,     2,    62,    26,    27,
      68,     2,    62,     0,     0,     0,    28,     0,     0,     0,
       0,     9,     0,     0,     9,    68,     2,   163,     0,   282,
       2,    62,     0,     0,     0,     0,     7,   225,     0,     0,
       0,     7,     0,     0,     0,     0,     0,    26,    27,     0,
      26,    27,     0,     0,     0,    28,     7,     0,    28,     9,
       7,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,     0,     0,     9,     0,    26,    27,     0,     0,     0,
      26,    27,     0,    28,     0,     0,     0,   140,    28,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,    26,
      27,     0,     0,    28,    99,   100,     0,    28,     0,   101,
     102,   103,   104,   105,     0,     0,     0,     0,   106,     0,
       0,   107,   108,   109,   110,   111,   112,     0,     0,     0,
     113,   114,   115,   116,     0,     0,   117,   118,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    99,   100,     0,     0,     0,   101,   102,   103,   104,
     105,     0,     0,     0,     0,   106,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,   113,   114,   115,
     116,     0,     0,   117,   118,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    99,   100,
       0,     0,     0,   101,   102,   103,   104,   105,     0,     0,
       0,     0,   106,     0,     0,   107,   108,   109,   110,   111,
     112,     0,     0,     0,   113,   114,   115,   116,     0,     0,
     117,   118,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    99,   100,   153,     0,     0,
     101,   102,   103,   104,   105,     0,     0,     0,     0,   106,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     0,
       0,   113,   114,   115,   116,     0,     0,   117,   118,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    99,   100,   156,     0,     0,   101,   102,   103,
     104,   105,     0,     0,     0,     0,   106,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     0,     0,   113,   114,
     115,   116,     0,     0,   117,   118,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    99,
     100,   158,     0,     0,   101,   102,   103,   104,   105,     0,
       0,     0,     0,   106,     0,     0,   107,   108,   109,   110,
     111,   112,     0,     0,     0,   113,   114,   115,   116,     0,
       0,   117,   118,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    99,   100,   229,     0,
       0,   101,   102,   103,   104,   105,     0,     0,     0,     0,
     106,     0,     0,   107,   108,   109,   110,   111,   112,     0,
       0,     0,   113,   114,   115,   116,     0,     0,   117,   118,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    99,   100,     0,     0,     0,   101,   102,
     103,   104,   105,     0,     0,     0,     0,   106,     0,   237,
     107,   108,   109,   110,   111,   112,     0,     0,     0,   113,
     114,   115,   116,     0,     0,   117,   118,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      99,   100,   248,     0,     0,   101,   102,   103,   104,   105,
       0,     0,     0,     0,   106,     0,     0,   107,   108,   109,
     110,   111,   112,     0,     0,     0,   113,   114,   115,   116,
       0,     0,   117,   118,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    99,   100,   274,
       0,     0,   101,   102,   103,   104,   105,     0,     0,     0,
       0,   106,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,   113,   114,   115,   116,     0,     0,   117,
     118,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    99,   100,     0,     0,     0,   101,
     102,   103,   104,   105,     0,     0,     0,     0,   106,     0,
       0,   107,   108,   109,   110,   111,   112,     0,     0,     0,
     113,   114,   115,   116,     0,     0,   117,   118,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   147,   100,     0,     0,     0,   101,   102,   103,   104,
     105,     0,     0,     0,     0,   106,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,   113,   114,   115,
     116,     0,     0,   117,   118,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   201,   100,
       0,     0,     0,   101,   102,   103,   104,   105,     0,     0,
       0,     0,   106,     0,     0,   107,   108,   109,   110,   111,
     112,     0,     0,     0,   113,   114,   115,   116,     0,     0,
     117,   118,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   268,   100,     0,     0,     0,
     101,   102,   103,   104,   105,     0,     0,     0,     0,   106,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     0,
       0,   113,   114,   115,   116,     0,     0,   117,   118,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    99,   100,     0,     0,     0,   101,   102,   103,
     104,   105,     0,     0,     0,     0,   106,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     0,     0,   113,   114,
     115,   116,     0,     0,   117,    99,   100,   119,     0,     0,
     101,   102,   103,   104,   105,     0,     0,     0,     0,   106,
       0,     0,   107,   108,   109,   110,   111,   112,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    99,
     100,     0,     0,     0,   101,   102,   103,   104,   105,     0,
       0,     0,     0,   106,     0,     0,   107,   108,   109,   110,
     111,   112,     0,     0,     0,   113,   114,   115,   116,     0,
       0,    99,   100,     0,   119,     0,   101,   102,   103,   104,
     105,     0,     0,     0,     0,   106,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    99,   100,
       0,     0,     0,   101,   102,   103,   104,   105,     0,     0,
       0,     0,   106,     0,     0,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,     0,   119,     0,   101,   102,   103,   104,   105,
       0,     0,     0,     0,   106,     0,     0,   107,   108,   109,
     110,   111,   112,     0,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   119,    99,   100,     0,     0,
       0,   101,   102,   103,   104,   105,     0,     0,     0,     0,
     106,     0,     0,   107,   108,   109,   110,   111,   112,   122,
     123,   124,   125,   126,   127,   128,   129,    99,   100,     0,
       0,   119,   101,   102,   103,   104,   105,     0,     0,     0,
       0,   106,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,   123,   124,   125,   126,
     127,   128,   129,    99,   100,     0,     0,     0,   101,   102,
     103,   104,   105,     0,     0,     0,     0,   106,     0,     0,
     107,   108,   109,   110,   111,   112,     0,   123,   124,   125,
     126,   127,   128,   129,    99,   100,     0,     0,     0,   101,
     102,   103,   104,   105,     0,     0,     0,     0,   106,     0,
       0,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129
};

static const short int yycheck[] =
{
       8,    15,     3,     3,     5,     3,    24,     6,     9,    10,
     242,     6,     4,    26,    15,    16,     4,    18,     6,    20,
      14,   142,    22,    49,    49,    26,    27,    28,   201,    26,
      26,    24,   211,   211,    24,     6,   215,   215,   216,    49,
      26,   219,    70,   221,    36,   304,     6,    24,    74,    74,
      49,    79,    49,    49,    67,    26,    49,    58,    59,   232,
      61,    62,    39,    49,    74,   324,    67,   326,     4,    24,
       6,     8,     4,     8,     4,    74,    26,    85,    74,    74,
     312,   259,     4,    91,    26,    73,    69,    70,     4,    89,
      98,    89,    93,     0,     3,   268,    93,    93,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    74,
     251,    74,     4,   147,     7,   136,    24,     4,     5,     6,
      35,    54,   142,     8,   142,   153,   147,   155,   156,    24,
     158,     8,   160,     8,     8,   149,    19,     6,   159,     4,
      26,     4,   163,     4,    26,     4,    49,     7,    35,    74,
       4,    55,    76,    24,     4,     5,     6,    24,     8,     6,
      70,     7,    79,     7,    26,     8,    24,     4,    77,    26,
      54,    58,     4,     7,    40,    26,     7,   198,     8,    60,
     201,     8,     8,   204,    24,    35,     4,     4,     5,     6,
       4,    24,     8,     4,    49,     8,   217,    84,    85,    86,
     220,   229,   220,    90,    27,    92,    26,    26,    58,     8,
     230,   232,   230,    28,     8,     8,    22,   222,    35,   257,
     248,   230,    39,   261,   259,   239,   263,   309,    -1,   243,
      -1,   251,    -1,   251,    84,    85,    -1,    -1,    -1,    -1,
     261,    58,    92,    -1,    -1,   273,   274,   268,     4,     5,
       6,   279,    -1,     9,    -1,    -1,    12,   277,    -1,   277,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,
      -1,   305,   310,    -1,    -1,    92,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,   305,    -1,   314,     4,     5,     6,
       4,     5,     6,   321,    11,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    35,    75,
      -1,    35,    78,    -1,    80,     4,     5,     6,    84,    85,
       4,     5,     6,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    58,     4,     5,     6,    -1,     4,
       5,     6,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,
      84,    85,    -1,    -1,    -1,    92,    35,    -1,    92,    58,
      35,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    58,    -1,    84,    85,    -1,    -1,    -1,
      84,    85,    -1,    92,    -1,    -1,    -1,     7,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    84,
      85,    -1,    -1,    92,    24,    25,    -1,    92,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    52,    53,    -1,    -1,    56,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    51,    52,
      53,    -1,    -1,    56,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    51,    52,    53,    -1,    -1,
      56,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    -1,    -1,    56,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    -1,    -1,    56,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    50,    51,    52,    53,    -1,
      -1,    56,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    50,    51,    52,    53,    -1,    -1,    56,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      51,    52,    53,    -1,    -1,    56,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      -1,    -1,    56,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    24,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    51,    52,    53,    -1,    -1,    56,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    52,    53,    -1,    -1,    56,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    51,    52,
      53,    -1,    -1,    56,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    51,    52,    53,    -1,    -1,
      56,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    -1,    -1,    56,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    24,    25,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    -1,    -1,    56,    24,    25,    59,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    50,    51,    52,    53,    -1,
      -1,    24,    25,    -1,    59,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    59,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    59,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    43,    44,    45,    46,    83,
      84,    85,    86,    87,    88,    89,    90,    24,    25,    -1,
      -1,    59,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      41,    42,    43,    44,    45,    46,    -1,    84,    85,    86,
      87,    88,    89,    90,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     4,     5,     6,     9,    12,    34,    35,    55,    58,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    75,    78,    80,    84,    85,    92,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     117,   118,   119,   121,   122,   131,   134,   137,     6,    49,
      74,    24,     6,   102,   109,   120,   131,     6,     4,   102,
      24,    96,   102,     8,   102,   128,     8,     8,     4,   129,
     129,   128,   102,     4,   102,    26,   102,     4,     4,     6,
     118,    26,   101,     4,   102,   102,   102,     0,     3,    24,
      25,    29,    30,    31,    32,    33,    38,    41,    42,    43,
      44,    45,    46,    50,    51,    52,    53,    56,    57,    59,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      74,     4,    86,    90,   102,   130,    39,   102,     4,   102,
       7,     7,    24,   102,     8,    35,    54,    24,     8,    24,
       8,     8,     8,    26,     6,    26,    26,    96,    26,    19,
      26,    96,    26,     6,   102,    96,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,     4,    49,     4,
       4,    24,     7,   102,    49,    74,   120,     7,   102,   128,
     129,    96,     4,   132,    96,    96,    96,    11,   102,    96,
      76,   123,   124,    55,     4,    36,   127,   138,   139,    26,
      24,   102,    24,   102,   130,    24,    49,    40,   102,     6,
     111,   112,    24,    39,     7,   111,   112,   102,    26,   112,
       4,     6,   125,   126,   131,   112,   123,    79,   135,   136,
      26,    49,    93,    24,     7,    96,   121,   131,    24,   130,
     129,   132,   129,    26,    26,    96,     8,    74,   120,    26,
      77,   133,     4,   101,    54,   112,   135,     4,   101,   102,
       4,     4,   138,    60,   130,     7,    40,    96,    96,   131,
       7,    96,    26,    74,    26,    67,     8,     8,     8,    24,
      49,     4,    24,     8,    27,   116,     4,   116,   128,     4,
     139,    26,   132,    96,    26,     8,    26,    96,    28,   116,
     116,     8,     8,     8
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 3:
#line 49 "p.y"
    {;}
    break;

  case 4:
#line 50 "p.y"
    { YYACCEPT; ;}
    break;

  case 5:
#line 51 "p.y"
    { YYACCEPT; ;}
    break;

  case 6:
#line 54 "p.y"
    {
                    (yyval)=new stat("stat");
                    (yyval)->add((yyvsp[0]));
                       ;}
    break;

  case 7:
#line 58 "p.y"
    {
            (yyval)=new stat("stat");
                    (yyval)->add((yyvsp[0]));
         ;}
    break;

  case 8:
#line 64 "p.y"
    { (yyval)=nullptr ;}
    break;

  case 9:
#line 65 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                    (yyval)->add((yyvsp[0]));
                 ;}
    break;

  case 10:
#line 69 "p.y"
    {
                  (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                  ;}
    break;

  case 11:
#line 74 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                  ;}
    break;

  case 12:
#line 79 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                  ;}
    break;

  case 13:
#line 84 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                 ;}
    break;

  case 14:
#line 89 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                 ;}
    break;

  case 15:
#line 94 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                 ;}
    break;

  case 16:
#line 99 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                  ;}
    break;

  case 17:
#line 104 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));

                  ;}
    break;

  case 18:
#line 109 "p.y"
    {
                 (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0].astNode));

                ;}
    break;

  case 19:
#line 114 "p.y"
    {
                    (yyval)=new simple_stat("simple_stat");
                  (yyval)->add((yyvsp[0]));
                ;}
    break;

  case 20:
#line 120 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                   ;}
    break;

  case 21:
#line 124 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                   ;}
    break;

  case 22:
#line 128 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                    ;}
    break;

  case 23:
#line 132 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                    ;}
    break;

  case 24:
#line 136 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                   ;}
    break;

  case 25:
#line 140 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                   ;}
    break;

  case 26:
#line 144 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                   ;}
    break;

  case 27:
#line 148 "p.y"
    {
                    (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                    ;}
    break;

  case 28:
#line 152 "p.y"
    {
                     (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                     ;}
    break;

  case 29:
#line 156 "p.y"
    {
                   (yyval)=new compound_stat("compound_stat");
                    (yyval)->add((yyvsp[0]));
                    ;}
    break;

  case 30:
#line 161 "p.y"
    {
                  (yyval)=new print("print");
                  (yyval)->add((yyvsp[-3].astNode));
                  (yyval)->add((yyvsp[-1]));

                 ;}
    break;

  case 31:
#line 168 "p.y"
    {
                   (yyval)=new expression_stat("expression_stat");
                    (yyval)->add((yyvsp[0]));

                       ;}
    break;

  case 32:
#line 174 "p.y"
    {
                      (yyval)=new add_Node("add");
                      (yyval)->add((yyvsp[-2]));
                       (yyval)->add((yyvsp[0]));
                   ;}
    break;

  case 33:
#line 179 "p.y"
    { fprintf(yyout, "Subtraction\n"); ;}
    break;

  case 34:
#line 180 "p.y"
    { fprintf(yyout, "Multiply\n"); ;}
    break;

  case 35:
#line 181 "p.y"
    { fprintf(yyout, "Division\n"); ;}
    break;

  case 36:
#line 182 "p.y"
    { fprintf(yyout, "Equal\n"); ;}
    break;

  case 37:
#line 183 "p.y"
    { fprintf(yyout, "Greater Or Equal\n"); ;}
    break;

  case 38:
#line 184 "p.y"
    { fprintf(yyout, "Less Or Equal\n"); ;}
    break;

  case 39:
#line 185 "p.y"
    { fprintf(yyout, "Greater Than\n"); ;}
    break;

  case 40:
#line 186 "p.y"
    { fprintf(yyout, "Less Than\n"); ;}
    break;

  case 41:
#line 187 "p.y"
    { fprintf(yyout, "Power \n"); ;}
    break;

  case 42:
#line 188 "p.y"
    { fprintf(yyout, "Modulus \n"); ;}
    break;

  case 43:
#line 189 "p.y"
    { fprintf(yyout, "And \n"); ;}
    break;

  case 44:
#line 190 "p.y"
    { fprintf(yyout, "At Expression\n"); ;}
    break;

  case 45:
#line 191 "p.y"
    { fprintf(yyout, "Logical OR\n"); ;}
    break;

  case 46:
#line 192 "p.y"
    { fprintf(yyout, "Logical AND\n"); ;}
    break;

  case 47:
#line 193 "p.y"
    { fprintf(yyout, "Logical NOT\n"); ;}
    break;

  case 48:
#line 194 "p.y"
    { fprintf(yyout, "Identity\n"); ;}
    break;

  case 49:
#line 195 "p.y"
    { fprintf(yyout, "Membership\n"); ;}
    break;

  case 50:
#line 196 "p.y"
    { fprintf(yyout, "Equality\n"); ;}
    break;

  case 51:
#line 197 "p.y"
    { fprintf(yyout, "Relational\n"); ;}
    break;

  case 52:
#line 198 "p.y"
    { fprintf(yyout, "Bitwise OR\n"); ;}
    break;

  case 53:
#line 199 "p.y"
    { fprintf(yyout, "Bitwise XOR\n"); ;}
    break;

  case 54:
#line 200 "p.y"
    { fprintf(yyout, "Bitwise AND\n"); ;}
    break;

  case 55:
#line 201 "p.y"
    { fprintf(yyout, "Bitwise Shift\n"); ;}
    break;

  case 56:
#line 202 "p.y"
    { fprintf(yyout, "Addition\n"); ;}
    break;

  case 57:
#line 203 "p.y"
    { fprintf(yyout, "Subtraction\n"); ;}
    break;

  case 58:
#line 204 "p.y"
    { fprintf(yyout, "Multiplication\n"); ;}
    break;

  case 59:
#line 205 "p.y"
    { fprintf(yyout, "Modulus\n"); ;}
    break;

  case 60:
#line 206 "p.y"
    { fprintf(yyout, "Division\n"); ;}
    break;

  case 61:
#line 207 "p.y"
    { fprintf(yyout, "Division Floor\n"); ;}
    break;

  case 62:
#line 208 "p.y"
    { fprintf(yyout, "Unary Minus\n"); ;}
    break;

  case 63:
#line 209 "p.y"
    { fprintf(yyout, "Unary Plus\n"); ;}
    break;

  case 64:
#line 210 "p.y"
    { fprintf(yyout, "Bitwise Not\n"); ;}
    break;

  case 65:
#line 211 "p.y"
    { fprintf(yyout, "Exponentiation\n"); ;}
    break;

  case 67:
#line 213 "p.y"
    { fprintf(yyout, "Comparison\n"); ;}
    break;

  case 71:
#line 217 "p.y"
    { printf("Processed expression within parentheses\n"); ;}
    break;

  case 72:
#line 218 "p.y"
    { fprintf(yyout, "Assignment\n"); ;}
    break;

  case 73:
#line 219 "p.y"
    { fprintf(yyout, "Identifier\n"); ;}
    break;

  case 74:
#line 220 "p.y"
    { fprintf(yyout, "Array Access\n"); ;}
    break;

  case 75:
#line 221 "p.y"
    { fprintf(yyout, "Type Alias\n"); ;}
    break;

  case 78:
#line 227 "p.y"
    { fprintf(yyout, "Break stat\n"); ;}
    break;

  case 79:
#line 229 "p.y"
    { fprintf(yyout, "Continue stat\n"); ;}
    break;

  case 91:
#line 254 "p.y"
    { fprintf(yyout, "For stat\n"); ;}
    break;

  case 92:
#line 255 "p.y"
    { fprintf(yyout, "For stat\n"); ;}
    break;

  case 93:
#line 259 "p.y"
    { fprintf(yyout, "Assertion stat\n"); ;}
    break;

  case 94:
#line 265 "p.y"
    { fprintf(yyout, "Block\n"); ;}
    break;

  case 107:
#line 290 "p.y"
    { fprintf(yyout, "Except stat\n"); ;}
    break;

  case 108:
#line 291 "p.y"
    { fprintf(yyout, "Except stat\n"); ;}
    break;

  case 116:
#line 302 "p.y"
    { fprintf(yyout, "Underscore Identifier\n"); ;}
    break;

  case 118:
#line 307 "p.y"
    { fprintf(yyout, "args_expressions\n"); ;}
    break;

  case 134:
#line 335 "p.y"
    { fprintf(yyout, "Finally stat\n"); ;}
    break;

  case 136:
#line 338 "p.y"
    { fprintf(yyout, "Case stat\n"); ;}
    break;

  case 137:
#line 339 "p.y"
    { fprintf(yyout, "Case stat\n"); ;}
    break;

  case 141:
#line 346 "p.y"
    { fprintf(yyout, "Function Declaration\n"); ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2377 "p.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 374 "p.y"




void main(int argc, char **argv)
{
 /*success("This is a valid python expression");*/
     if (argc > 1){
        for(int i=0;i<argc;i++)
            printf("value of argv[%d] = %s\n\n",i,argv[i]);
            yyin=fopen(argv[1],"r");
    }
        else
        yyin=stdin;
     yyparse();
}

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
