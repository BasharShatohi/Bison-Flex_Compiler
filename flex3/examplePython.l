%{
#include <stdio.h>
%}

%option noyywrap

/* Define token types as constants */
%{
#define IDENTIFIER 1
#define KEYWORD 2
#define LITERAL 3
#define OPERATOR 4
%}

/* Regular expressions to match tokens */
DIGIT [0-9]
LETTER [_a-zA-Z]
ALPHANUM {LETTER}|{DIGIT}
IDENTIFIER {LETTER}{ALPHANUM}*

LITERALSTRING \"([^\"\\]|\\.)*\"
LITERALCHAR \'([^\']|\\.)\'

KEYWORD if|else|while|for|def|class|as|assert|continue|del|except|import|in|lambda|print|finally|global|not|return|True|with|yield
OPERATORS [+\-*/=(){}\[\]:,;<>!]=?


%%
{OPERATORS}				{printf("OPERATOR: %s\n", yytext);}

{KEYWORD}              		{printf("keyword = %s \n",yytext);}
{DIGIT}+			{printf("Number = %s \n",yytext);}
{IDENTIFIER}           		{printf("IDENTIFIER = %s \n",yytext);}
\"[^\"\\]*\"|\'[^\'\\]*\'		{printf("STRING_LITERAL: %s\n", yytext);}
\"([^\"\\]*(\\\n[^\"\\]*)*)\" 	{printf("BIG_STRING_LITERAL: %s\n", yytext);}
\#.* 					{printf("COMMENTS: %s\n", yytext);}

.|\n 					{/* Ignore everything else. */}




%%

int main(int argc, char **argv) {

  if (argc > 1){
        for(int i=0;i<argc;i++)
            printf("value of argv[%d] = %s\n\n",i,argv[i]);
            yyin=fopen(argv[1],"r");
    }
        
    else
        yyin=stdin;
    yylex();
    return 0;
}
