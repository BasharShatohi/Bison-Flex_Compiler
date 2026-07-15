/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_P_HPP_INCLUDED
# define YY_YY_P_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "p.y" /* yacc.c:1909  */

      #include "classes.hpp"
      #include <iostream>
      #include <string>

#line 50 "p.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 8 "p.y" /* yacc.c:1909  */

	AstNode* astNode;
    
	int d;

#line 152 "p.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P_HPP_INCLUDED  */
