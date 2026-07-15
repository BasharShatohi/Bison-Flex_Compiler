
%{
#include <stdio.h>
#include <string.h>
extern FILE* yyin;
extern FILE* yyout;
int yydebug = 1;
int yylex();
void yyerror(const char *s);
%}

%token EOL
%token COMMENT
%token NUMBER STRING
%token IDENTIFIER
%token ASSIGNMENT
%token EQUALITY RELATIONAL IDENTITY MEMBERSHIP 
%token DEDENT INDENT
%token LOGICALAND LOGICALOR LOGICALNOT
%token BITWISESHIFT
%token ARROW
%token RETURN BREAK CONTINUE GLOBAL NONLOCAL YIELD IF CLASS ELIF ELSE WHILE FOR WITH AS TRY EXCEPT FINALLY MATCH CASE DEF
%token ERROR

%left ASSIGNMENT '='
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
%left '(' ')'
%nonassoc UNARY
%verbose

%%
program: statements;
statements: simple_statement
    | simple_statement EOL statements
    | compound_statement statements 
    | ERROR { yyerror("syntax error"); }
    ;

simple_statement: { fprintf(yyout, "Empty Statement\n"); }
    | expression_statement { fprintf(yyout, "Expression statement\n"); } 
    | assignment_statement { fprintf(yyout, "Assignment statement\n"); } 
    | return_statement { fprintf(yyout, "Return Statement\n"); }
    | break_statement { fprintf(yyout, "Break Statement\n"); }
    | continue_statement { fprintf(yyout, "Continue Statement\n"); }
    | global_statement { fprintf(yyout, "Global Statement\n"); }
    | nonlocal_statement { fprintf(yyout, "Nonlocal Statement\n"); }
    | yield_statement { fprintf(yyout, "Yield statement\n"); }
    | function_call { fprintf(yyout, "Function Call Statement\n"); }
    | COMMENT { fprintf(yyout, "Comment Statement\n"); }
    ;
assignment_statement: IDENTIFIER ASSIGNMENT  expression_statement 
    | IDENTIFIER ASSIGNMENT assignment_statement 
    | IDENTIFIER '='  expression_statement 
    | IDENTIFIER '=' assignment_statement
    ;
expression_statement: expression;
expression: expression LOGICALOR expression { fprintf(yyout, "Logical OR\n"); }
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
    | '(' expression ')' { fprintf(yyout, "Parentheses\n"); }
    | NUMBER                      
    | STRING 
    | IDENTIFIER
    ;
return_statement: RETURN args_expressions 
    | RETURN
    ;
break_statement: BREAK;
continue_statement: CONTINUE;
global_statement: GLOBAL args_identifiers;
nonlocal_statement: NONLOCAL args_identifiers;
yield_statement: YIELD args_expressions;
args_expressions: expression ',' args_expressions 
    | expression
    ;
args_identifiers: IDENTIFIER ',' args_identifiers 
    | IDENTIFIER
    ;
function_call: IDENTIFIER '(' args ')';
args: 
    | expression ',' args 
    | expression 
    | EXPONENTIATION IDENTIFIER 
    | '*' IDENTIFIER ',' args
    | IDENTIFIER '=' expression ',' args
    ;
compound_statement: if_statement { fprintf(yyout, "If Statement\n"); } 
    | class_statement { fprintf(yyout, "Class Statement\n"); }
    | while_statement { fprintf(yyout, "While Statement\n"); }
    | for_statement { fprintf(yyout, "For Statement\n"); }
    | with_statement { fprintf(yyout, "With Statement\n"); }
    | try_statement { fprintf(yyout, "Try Statement\n"); }
    | match_statement { fprintf(yyout, "Match Statement\n"); }
    | function_declaration_statement { fprintf(yyout, "Function Declaration Statement\n"); }
    ;
block: INDENT statements DEDENT;
if_statement: IF args_expressions ':' block elif_statement;
elif_statement: ELIF expression_statement ':' block elif_statement { fprintf(yyout, "Elif Statement\n"); } 
    | else_statement
    ;
else_statement: 
    | ELSE ':' block { fprintf(yyout, "Else Statement\n"); }
    ;
while_statement: WHILE expression_statement ':' block else_statement;
for_statement: FOR args_identifiers MEMBERSHIP generator ':' block else_statement;
generator: IDENTIFIER 
    | function_call
    ;
class_statement: CLASS IDENTIFIER ':' block 
    | CLASS IDENTIFIER '(' class_args ')' ':' block
    ;
class_args: IDENTIFIER 
    | IDENTIFIER ',' class_args 
    | IDENTIFIER '[' args_identifiers ']' 
    | IDENTIFIER '[' args_identifiers ']' ',' class_args 
    ;
with_statement: WITH with ':' block else_statement;
with: generator 
    | with_as 
    | complex_with_as_statement
    ;
complex_with_as_statement: '(' args_generator ')' AS '(' args_identifiers ')';
args_generator: generator 
    | generator ',' args_generator
    ;
with_as: generator AS IDENTIFIER 
    | generator AS IDENTIFIER ',' with_as
    ;
try_statement: TRY ':' block except_statement_list else_statement finally_statement;
except_statement_list:  except_statement { fprintf(yyout, "Except Statement\n"); }
    | except_statement except_statement_list { fprintf(yyout, "Except Statement\n"); }
    ;
except_statement: EXCEPT except_expression ':' block;
except_expression: 
    | generator 
    | '(' args_generator ')' 
    | exception_as
    ;
exception_as: IDENTIFIER AS generator;
finally_statement: 
    | FINALLY ':' block { fprintf(yyout, "Finally Statement\n"); }
    ;
match_statement: MATCH expression_statement ':' INDENT pattern_list DEDENT;
pattern_list: pattern else_statement { fprintf(yyout, "Case Statement\n"); }
    | pattern pattern_list { fprintf(yyout, "Case Statement\n"); }
    ;
pattern: CASE expression_statement ':' block
    | CASE IDENTIFIER AS IDENTIFIER ':' block
    | CASE expression_statement IF args_expressions ':' block
    ;
function_declaration_statement: DEF IDENTIFIER '(' function_declaratin_args ')' ':' block
    | DEF IDENTIFIER '(' function_declaratin_args ')' ARROW IDENTIFIER ':' block;
function_declaratin_args: 
    | function_identifier_parameter
    | function_identifier_parameter ',' function_declaratin_args 
    | keyword_args
    ;
function_identifier_parameter: IDENTIFIER 
    | IDENTIFIER ':' IDENTIFIER
    ;
keyword_args: IDENTIFIER '=' expression_statement 
    | IDENTIFIER '=' expression_statement ',' keyword_args
    ;
/*
varibale_arg: | '*' IDENTIFIER | '*' IDENTIFIER ',';
keyword_args: 
    | IDENTIFIER '=' expression_statement ','
    | keyword_arg_list
    ;
keyword_arg_list: IDENTIFIER '=' expression_statement
    | IDENTIFIER '=' expression_statement ',' keyword_arg_list
    ; 
*/
%%

extern int yyparse();
extern FILE* yyin;
extern FILE* yyout;

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");
    yyin = input_file;
    yyout = output_file;
    yyparse();
    fclose(input_file);
    fclose(output_file);
    return 0;
}

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
