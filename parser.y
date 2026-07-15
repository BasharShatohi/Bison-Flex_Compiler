%{
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
%}

%token <astNode> NEWLINE IDENTIFIER STRING LPAREN RPAREN SEMICOLON PRINT ERROR RANGE
%token <astNode> ASSERT ASYNC EOL AWAIT DEL FROM IMPORT IN IS LAMBDA PASS RAISE
%token <astNode> COMMA AND COLON LBRACE RBRACE ADD SUB MUL DIV POW COMMENT_STRING 
%token <astNode> NUMBER UNDERSCORE DOT AT LBRACKET RBRACKET EQ GE LE GT LT MOD
%token <astNode> OR NOT ASSIGNMENT EQUALITY RELATIONAL IDENTITY MEMBERSHIP
%token <astNode> DEDENT INDENT LOGICALAND LOGICALOR LOGICALNOT BITWISESHIFT ARROW
%token <astNode> RETURN BREAK CONTINUE GLOBAL NONLOCAL YIELD IF CLASS ELIF ELSE
%token <astNode> WHILE FOR WITH AS TRY EXCEPT FINALLY MATCH CASE DEF



%left LOGICALOR
%left LOGICALAND
%left LOGICALNOT
%left RELATIONAL EQUALITY IDENTITY MEMBERSHIP
%left '|'
%left '^'
%left '&'
%left BITWISESHIFT
%left '+' '-'
%left '*' '/' '%' DIVFLOOR
%left EXPONENTIATION
%nonassoc UNARY
%verbose


%%
program: statements;

statements: statement 
          | statement NEWLINE statements { YYACCEPT; }
          | INDENT statements DEDENT { YYACCEPT; }
          ;

statement: simple_statement
         | compound_statement
         ;

simple_statement:{ fprintf(yyout, "Empty Statement\n"); }
                 | print_statement  { fprintf(yyout, "print statement\n"); }
                 | expression_statement  { fprintf(yyout, "Expression statement\n"); } 
                 | return_statement  { fprintf(yyout, "Return Statement\n"); }
                 | break_statement  { fprintf(yyout, "Break Statement\n"); }
                 | continue_statement  { fprintf(yyout, "Continue Statement\n"); }
                 | global_statement  { fprintf(yyout, "Global Statement\n"); }
                 | nonlocal_statement  { fprintf(yyout, "Nonlocal Statement\n"); }
                 | yield_statement  { fprintf(yyout, "Yield statement\n"); }
                 | function_call  { fprintf(yyout, "Function Call Statement\n"); }
                 | COMMENT_STRING  { fprintf(yyout, "Comment Statement\n"); }
                 | assert_statement { fprintf(yyout, "Assert Statement\n"); }
                 ;


compound_statement: if_statement { fprintf(yyout, "IF statement\n"); }
                   | class_statement  
                   | while_statement { fprintf(yyout, "WHILE statement\n"); }
                   | for_statement { fprintf(yyout, "FOR statement\n"); }
                   | with_statement 
                   | try_statement 
                   | match_statement 
                   | function_declaration_statement { fprintf(yyout, "Function Declaration Statement \n"); };
                   | elif_statement { fprintf(yyout, "ELIF statement\n"); }
                   | else_statement { fprintf(yyout, "ELSE statement\n"); }

print_statement: PRINT LPAREN expression RPAREN  { printf("Print statement\n"); }
               ;

expression_statement: expression  { fprintf(yyout, "Expression statement\n"); };

expression: expression ADD expression { fprintf(yyout, "Addition\n"); }
          | expression SUB expression { fprintf(yyout, "Subtraction\n"); }
          | expression MUL expression { fprintf(yyout, "Multiply\n"); }
          | expression DIV expression { fprintf(yyout, "Division\n"); }
          | expression EQ expression { fprintf(yyout, "Equal\n"); }
          | expression GE expression { fprintf(yyout, "Greater Or Equal\n"); }
          | expression LE expression { fprintf(yyout, "Less Or Equal\n"); }
          | expression GT expression { fprintf(yyout, "Greater Than\n"); }
          | expression LT expression { fprintf(yyout, "Less Than\n"); }
          | expression POW expression { fprintf(yyout, "Power \n"); }
          | expression MOD expression { fprintf(yyout, "Modulus \n"); }
          | expression AND expression { fprintf(yyout, "And \n"); }
          | expression AT expression { fprintf(yyout, "At Expression\n"); }
          | expression LOGICALOR expression { fprintf(yyout, "Logical OR\n"); }
          | expression LOGICALAND expression { fprintf(yyout, "Logical AND\n"); }
          | LOGICALNOT expression { fprintf(yyout, "Logical NOT\n"); }
          | expression IDENTITY expression { fprintf(yyout, "Identity\n"); } 
          | expression MEMBERSHIP expression { fprintf(yyout, "Membership\n"); }
          | expression EQUALITY expression { fprintf(yyout, "Equality\n"); }
          | expression RELATIONAL expression { fprintf(yyout, "Relational\n"); }
          | expression '|' expression { fprintf(yyout, "Bitwise OR\n"); }
          | expression '^' expression { fprintf(yyout, "Bitwise XOR\n"); }
          | expression '&' expression { fprintf(yyout, "Bitwise AND\n"); }
          | expression BITWISESHIFT expression { fprintf(yyout, "Bitwise Shift\n"); }
          | expression '+' expression { fprintf(yyout, "Addition\n"); }
          | expression '-' expression { fprintf(yyout, "Subtraction\n"); }     
          | expression '*' expression { fprintf(yyout, "Multiplication\n"); }     
          | expression '%' expression { fprintf(yyout, "Modulus\n"); }     
          | expression '/' expression { fprintf(yyout, "Division\n"); }     
          | expression DIVFLOOR expression { fprintf(yyout, "Division Floor\n"); }     
          | '-' expression %prec UNARY { fprintf(yyout, "Unary Minus\n"); }          
          | '+' expression %prec UNARY { fprintf(yyout, "Unary Plus\n"); }          
          | '~' expression %prec UNARY { fprintf(yyout, "Bitwise Not\n"); }          
          | expression EXPONENTIATION expression { fprintf(yyout, "Exponentiation\n"); }
          | NUMBER 
          | NUMBER COMMA NUMBER { fprintf(yyout, "Comparison\n"); }
          | STRING 
          | STRING COMMA expression
          | expression COMMA expression
          | LPAREN expression RPAREN { printf("Processed expression within parentheses\n"); }
          | IDENTIFIER ASSIGNMENT expression { fprintf(yyout, "Assignment\n"); }
          | IDENTIFIER { fprintf(yyout, "Identifier\n"); }
          | IDENTIFIER ASSIGNMENT LBRACKET expression RBRACKET { fprintf(yyout, "Array Access\n"); }
          | IDENTIFIER AS IDENTIFIER ASSIGNMENT expression { fprintf(yyout, "Type Alias\n"); }
          ;

return_statement: RETURN args_expressions SEMICOLON
                | RETURN SEMICOLON;

break_statement: BREAK SEMICOLON { fprintf(yyout, "Break Statement\n"); };

continue_statement: CONTINUE SEMICOLON { fprintf(yyout, "Continue Statement\n"); };

global_statement: GLOBAL args_identifiers SEMICOLON;

nonlocal_statement: NONLOCAL args_identifiers SEMICOLON;

yield_statement: YIELD args_expressions SEMICOLON;

function_call: IDENTIFIER LPAREN args RPAREN COMMA
                |IDENTIFIER LPAREN args RPAREN ASSIGNMENT;


if_statement: IF expression COLON statements elif_statement ;

elif_statement: ELIF expression COLON statements elif_statement 
              | else_statement;

else_statement: ELSE COLON statements ;




while_statement: WHILE expression COLON statements 
                |WHILE expression COLON statements else_statement;

for_statement: FOR IDENTIFIER IN RANGE expression COLON statements  { fprintf(yyout, "For statement\n"); }
            | FOR IDENTIFIER IN expression COLON statements { fprintf(yyout, "For statement\n"); }
            ;


assert_statement: ASSERT expression SEMICOLON { fprintf(yyout, "Assertion Statement\n"); }
               ;




block: LBRACE statements RBRACE { fprintf(yyout, "Block\n"); }
        ;

class_statement: CLASS IDENTIFIER COLON statements 
                | CLASS IDENTIFIER LPAREN class_args RPAREN COLON statements SEMICOLON
                ;


with_statement: WITH with COLON statements else_statement SEMICOLON;
with: generator 
    | with_as 
    | complex_with_as_statement
    ;
complex_with_as_statement: LPAREN args_generator RPAREN AS LPAREN args_identifiers RPAREN

args_generator: generator 
    | generator COMMA args_generator
    ;

with_as: generator AS IDENTIFIER 
    | generator AS IDENTIFIER COMMA with_as
    ;

try_statement: TRY COLON statements except_statement_list else_statement finally_statement ;

except_statement_list:  except_statement { fprintf(yyout, "Except Statement\n"); }
    | except_statement except_statement_list { fprintf(yyout, "Except Statement\n"); }
    ;
except_statement: EXCEPT except_expression COLON statements;
except_expression: 
    | generator 
    | LPAREN args_generator RPAREN 
    | exception_as
    ;
exception_as: IDENTIFIER AS generator;

   
function_identifier_parameter: IDENTIFIER 
                                | UNDERSCORE { fprintf(yyout, "Underscore Identifier\n"); }
                                | IDENTIFIER ':' IDENTIFIER
                                ;


args_expressions: expression COMMA args_expressions  { fprintf(yyout, "args_expressions\n"); }
                | expression;

args_identifiers: IDENTIFIER COMMA args_identifiers 
                | IDENTIFIER;


args: expression COMMA args 
    | expression 
    | EXPONENTIATION IDENTIFIER 
    | '*' IDENTIFIER COMMA args
    | IDENTIFIER ASSIGNMENT expression COMMA args;


range_expression: LPAREN NUMBER COMMA NUMBER RPAREN {
    printf("Range expression: (%s, %s)\n", $2, $4);
}

generator: IDENTIFIER 
         | function_call;

class_args: IDENTIFIER 
    | IDENTIFIER COMMA class_args 
    | IDENTIFIER LBRACKET args_identifiers RBRACKET 
    | IDENTIFIER LBRACKET args_identifiers RBRACKET COMMA class_args 
    ;

finally_statement: 
    | FINALLY COLON block { fprintf(yyout, "Finally Statement\n"); }
    ;
match_statement: MATCH expression_statement COLON INDENT pattern_list DEDENT SEMICOLON;
pattern_list: pattern else_statement SEMICOLON { fprintf(yyout, "Case Statement\n"); }
    | pattern pattern_list SEMICOLON { fprintf(yyout, "Case Statement\n"); }
    ;
pattern: CASE expression_statement COLON block SEMICOLON
    | CASE IDENTIFIER AS IDENTIFIER COLON block SEMICOLON
    | CASE expression_statement IF args_expressions COLON block SEMICOLON
    ;

function_declaration_statement: DEF IDENTIFIER expression COLON statements { fprintf(yyout, "Function Declaration\n"); }
                            | DEF IDENTIFIER LPAREN function_declaratin_args RPAREN ARROW IDENTIFIER COLON statements SEMICOLON;


    
function_declaratin_args: 
    | function_identifier_parameter COMMA
    | function_identifier_parameter COMMA function_declaratin_args 
    | keyword_args
    ;
function_identifier_parameter: IDENTIFIER 
    | IDENTIFIER COLON IDENTIFIER
    ;
keyword_args: IDENTIFIER ASSIGNMENT expression_statement 
    | IDENTIFIER ASSIGNMENT expression_statement COMMA keyword_args
    ;



/*
varibale_arg: | '*' IDENTIFIER | '*' IDENTIFIER COMMA;
keyword_args: 
    | IDENTIFIER ASSIGNMENT expression_statement COMMA
    | keyword_arg_list
    ;
keyword_arg_list: IDENTIFIER ASSIGNMENT expression_statement
    | IDENTIFIER ASSIGNMENT expression_statement COMMA keyword_arg_list
    ; 
*/
%%



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