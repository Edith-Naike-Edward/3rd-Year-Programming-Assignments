/* Declarations */

%{
    #include <stdio.h>
    #include <string.h>

    #include "parser.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
alphanum [a-zA-Z0-9]
underscore [_]
digit [0-9]
nonzero [1-9]
zero [0]


/* Rules */
%%

"printf"  {strcpy(yylval.nd_obj.name,(yytext)); return PRINTF;}
"int"     {strcpy(yylval.nd_obj.name,(yytext)); return INT;}
"void"    {strcpy(yylval.nd_obj.name,(yytext)); return VOID;}
"if"      {strcpy(yylval.nd_obj.name,(yytext)); return IF;}
"else"    {strcpy(yylval.nd_obj.name,(yytext)); return ELSE;}
"while"   {strcpy(yylval.nd_obj.name,(yytext)); return WHILE;}
"float"   {strcpy(yylval.nd_obj.name,(yytext)); return FLOAT;}
"return"  {strcpy(yylval.nd_obj.name,(yytext)); return RETURN;}
"main"    {strcpy(yylval.nd_obj.name,(yytext)); return MAIN;}

{zero}|([-]?{nonzero}({digit})*)      {strcpy(yylval.nd_obj.name,(yytext)); return NUMBER;}
[-]?{digit}{digit}*\.{digit}{digit}*  {strcpy(yylval.nd_obj.name,(yytext)); return FLOAT_NUM;}
({alpha}|{underscore})({alpha}|{digit}|{underscore})*   {strcpy(yylval.nd_obj.name,(yytext)); return ID;}
["].*["]  {strcpy(yylval.nd_obj.name,(yytext)); return STRING;}
['].*[']  {strcpy(yylval.nd_obj.name,(yytext)); return STRING;}

"<="     {strcpy(yylval.nd_obj.name,(yytext)); return LE;}
"="      {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN;}
">="     {strcpy(yylval.nd_obj.name,(yytext)); return GE;}
"=="     {strcpy(yylval.nd_obj.name,(yytext)); return EQ;}
"!="     {strcpy(yylval.nd_obj.name,(yytext)); return NE;}
">"	     {strcpy(yylval.nd_obj.name,(yytext)); return GT;}
"<"	     {strcpy(yylval.nd_obj.name,(yytext)); return LT;}
"&&"	 {strcpy(yylval.nd_obj.name,(yytext)); return AND;}
"||"	 {strcpy(yylval.nd_obj.name,(yytext)); return OR;}
"!"      {strcpy(yylval.nd_obj.name,(yytext)); return NOT;}
"+"      {strcpy(yylval.nd_obj.name,(yytext)); return ADD;}
"-"      {strcpy(yylval.nd_obj.name,(yytext)); return SUBTRACT;}
"/"      {strcpy(yylval.nd_obj.name,(yytext)); return DIVIDE;}
"*"      {strcpy(yylval.nd_obj.name,(yytext)); return MULTIPLY;}

"("      {strcpy(yylval.nd_obj.name,(yytext)); return O_BRACK;}
")"      {strcpy(yylval.nd_obj.name,(yytext)); return C_BRACK;}
"{"      {strcpy(yylval.nd_obj.name,(yytext)); return OC_BRACK;}
"}"      {strcpy(yylval.nd_obj.name,(yytext)); return CC_BRACK;}
";"      {strcpy(yylval.nd_obj.name,(yytext)); return S_COLON;}
","      {strcpy(yylval.nd_obj.name,(yytext)); return COMMA;}

[\n]                        { countn++; }



%%

int yywrap() {
    return 1;
}


