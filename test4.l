%{
#include <stdio.h>
#include <stdlib.h>
#include "p.tab.h"



int indentation_stack[100];
int stack_index = 0;
int in_string = 0;
int in_comment = 0;
%}

%option noyywrap

%x STR COMMENT MULTILINE_COMMENT INDENTATION

%{
int current_indentation = 0;

void push_indentation(int value) {
    if (stack_index < 100) {
        indentation_stack[stack_index++] = value;
    } else {
        /*fprintf(stderr, "Stack overflow\n");*/
        exit(1);
    }
}

void pop_indentation() {
    if (stack_index > 0) {
        stack_index--;
    } else {
        /*fprintf(stderr, "Stack underflow\n");*/
        exit(1);
    }
}

void handle_indentation(int spaces) {
    while (spaces < indentation_stack[stack_index - 1]) {
       /* printf("DEDENT\n");*/
        pop_indentation();
    }

    if (spaces == indentation_stack[stack_index - 1]) {
        // Same level of indentation, just print SPACE if needed
        if (spaces > 0) {
           /* printf("SPACE\n");*/
        }
    } else if (spaces > indentation_stack[stack_index - 1]) {
        // Increase in indentation level
        push_indentation(spaces);
       /* printf("INDENT\n");*/
    }
}

%}

%%

<INITIAL>[ \t]+ {
    handle_indentation(yyleng);
 }

<INITIAL>\n {
   /* printf("NEWLINE\n");*/
    return NEWLINE;
}

<INITIAL>"\"" {
    if (!in_comment) {
        BEGIN(STR);
        in_string = 1;
       /* printf("STRING_BEGIN\n");*/
    } else {
      /*  printf("UNRECOGNIZED: %s\n", yytext);*/
    }
}


<INITIAL>"#" {
    if (!in_string) {
        BEGIN(COMMENT);
        in_comment = 1;
       /* printf("COMMENT_BEGIN\n");*/
    } else {
      /*  printf("UNRECOGNIZED: %s\n", yytext);*/
    }
}

<INITIAL>[0-9]+(\.[0-9]+)? {
   /* printf("NUMBER: %s\n", yytext);*/
    return NUMBER;
}

<INITIAL>\"([^\\\"]|\\.)*\"  {/* printf("STRING: %s\n", yytext);*/ return STRING; }


<INITIAL>"="          { return ASSIGNMENT; }

<INITIAL>as          { return AS; }
<INITIAL>assert      { return ASSERT; }
<INITIAL>async       { return ASYNC; }
<INITIAL>await       { return AWAIT; }
<INITIAL>break       { return BREAK; }
<INITIAL>class       { return CLASS; }
<INITIAL>continue    { return CONTINUE; }
<INITIAL>def         { return DEF; }
<INITIAL>del         { return DEL; }
<INITIAL>elif        { return ELIF; }
<INITIAL>else        { return ELSE; }
<INITIAL>except      { return EXCEPT; }
<INITIAL>finally     { return FINALLY; }
<INITIAL>for         { return FOR; }
<INITIAL>from        { return FROM; }
<INITIAL>global      { return GLOBAL; }
<INITIAL>if          { return IF; }
<INITIAL>import      { return IMPORT; }
<INITIAL>in          { return IN; }
<INITIAL>is          { return IS; }
<INITIAL>lambda      { return LAMBDA; }
<INITIAL>nonlocal    { return NONLOCAL; }
<INITIAL>not         { return NOT; }
<INITIAL>or          { return OR; }
<INITIAL>pass        { return PASS; }
<INITIAL>print       { return PRINT; }
<INITIAL>raise       { return RAISE; }
<INITIAL>range       { return RANGE; }
<INITIAL>return      { return RETURN; }
<INITIAL>try         { return TRY; }
<INITIAL>while       { return WHILE; }
<INITIAL>with        { return WITH; }
<INITIAL>yield       { return YIELD; }




<INITIAL>"_"         { return UNDERSCORE; }
<INITIAL>","         { return COMMA; }
<INITIAL>"."         { return DOT; }
<INITIAL>";"         { return SEMICOLON; }
<INITIAL>"@"         { return AT; }
<INITIAL>"("         { return LPAREN; }
<INITIAL>")"         {  return RPAREN; }
<INITIAL>"["         { return LBRACKET; }
<INITIAL>"]"         { return RBRACKET; }
<INITIAL>"{"         { return LBRACE; }
<INITIAL>"}"         { return RBRACE; }
<INITIAL>":"         { return COLON; }




<INITIAL>"=="       { return EQ; }
<INITIAL>">="       { return GE; }
<INITIAL>"<="       { return LE; }
<INITIAL>">"        { return GT; }
<INITIAL>"<"        { return LT; }
<INITIAL>"+"        { return ADD; }
<INITIAL>"-"        { return SUB; }
<INITIAL>"\*"       { return MUL; }
<INITIAL>"/"        { return DIV; }
<INITIAL>"\^"       { return POW; }
<INITIAL>"%"        { return MOD; }
<INITIAL>"and"      { return AND; }
<INITIAL>.          { /* Ignore all other characters */ }






<INITIAL>[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFIER; }



<STR>\\n          { /* Handle newline character in strings */ }
<STR>\\[^\n]       { /* Ignore escaped characters in strings */ }
<STR>"\""         { BEGIN(INITIAL); in_string = 0; /*printf("STRING_END\n");*/ }
<STR>[^\n]         {/* printf("STRING_CONTENT: %s\n", yytext); */}
<STR>\n            { /*printf("NEWLINE\n");*/ }

<INITIAL>"/*"    { BEGIN(MULTILINE_COMMENT);          /*printf("MULTILINE_COMMENT_START\n");*/ }
<COMMENT>"#"       { BEGIN(INITIAL); in_comment = 0;        /* printf("COMMENT_END\n");*/ }

<COMMENT>\n        { /* Ignore newline characters in comments */ }

<MULTILINE_COMMENT>\n { /* Ignore newline characters in multiline comments */ }

<COMMENT>.         { /* Ignore comment content */ }





%%
