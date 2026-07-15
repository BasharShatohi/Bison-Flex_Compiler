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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



