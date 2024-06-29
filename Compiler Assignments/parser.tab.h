
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 48 "parser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 

    struct var_name3 {
        char name[100];
        struct node* nd;
        char if_body[5];
        char else_body[5];  
    } nd_obj3;



/* Line 1676 of yacc.c  */
#line 103 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


