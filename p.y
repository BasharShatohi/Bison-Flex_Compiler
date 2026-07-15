
%code requires {
      #include "classes.hpp"
      #include <iostream>
      #include <string>
}

%union{
	AstNode* astNode;
    
	int d;
}


%{
#include <stdio.h>
#include <string.h>
#include "classes.hpp"
#include <iostream>
extern FILE* yyin;
extern FILE* yyout;
int yydebug = 1;
extern int yylex();
extern int yyparse();
void yyerror(const char *);
AstNode* root = NULL;
int n_nodes = 0;

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


%type  <astNode> file statements statement stats except_stat except_expression except_stat_list
%type <astNode> try complex_with_as_stat with class block assert for while else if function_call
%type <astNode> yield nonlocal global continue break return expression expression_stat print
%type <astNode> compound_stat simple_stat stat finally_stat args_identifiers args_generator with_as generator class_args
%type <astNode> elif args args_expressions function_def match IdentifierNode




%%
program: stats{root = $1; YYACCEPT;};

stats: stat {$$ = new statements("statements"); $$->add($1);}
          | stat NEWLINE stats {  $$ = $3; $3->add($1); }
          | INDENT stats DEDENT { $$ = $2;}
          ;

stat: simple_stat{
                $$=new statement("statement");
                $$->add($1);
                }
            | compound_stat{
                    $$=new statement("statement");
                    $$->add($1);
        }
    ;

simple_stat:{ $$=nullptr; }
                 | print  {
                    $$=new simple_stat("simple_stat");
                    $$->add($1);
                 }
                 | expression_stat  {
                  $$=new simple_stat("simple_stat");
                  $$->add($1);

                  }
                 | return  {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);

                  }
                 | break  {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);

                  }
                 | continue  {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);

                 }
                 | global  {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);

                 }
                 | nonlocal  {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);

                 }
                 | yield  {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);

                  }
                 | function_call  {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);

                  }
                 | COMMENT_STRING  {
                 $$=new simple_stat("simple_stat");
                  $$->add($1);

                }
                 | assert {
                    $$=new simple_stat("simple_stat");
                  $$->add($1);
                };


compound_stat: if {
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                   }
                   | class  {
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                   }
                   | while {
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                    }
                   | for {
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                    }
                   | with{
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                   }
                   | try {
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                   }
                   | match {
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                   }
                   | function_def {
                    $$=new compound_stat("compound_stat");
                    $$->add($1);
                    }
                   | elif {
                     $$=new compound_stat("compound_stat");
                    $$->add($1);
                     }
                   | else {
                   $$=new compound_stat("compound_stat");
                    $$->add($1);
                    };

print: PRINT LPAREN expression RPAREN  {
                  $$=new print_node("print");
                  $$->add($3);

                 };

expression_stat: expression  {
                   $$=new expression_stat("expression_stat");
                    $$->add($1);

                       };

expression: expression ADD expression {
                      $$=new add_Node();
                      $$->add($1);
                       $$->add($3);
                   }
          | expression SUB expression { 
                      $$=new sub_Node();
                      $$->add($1);
                       $$->add($3);
        }
          | expression MUL expression { 
                      $$=new mul_Node();
                      $$->add($1);
                       $$->add($3);
           }
          | expression DIV expression {
                      $$=new div_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression EQ expression {
                      $$=new equal_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression GE expression {
                      $$=new greaterorequal_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression LE expression {
                      $$=new lessorequal_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression GT expression {
                      $$=new greaterthan_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression LT expression {
                      $$=new lessthan_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression POW expression {
                      $$=new pow_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression MOD expression {
                      $$=new mod_Node();
                      $$->add($1);
                       $$->add($3);
          }
          | expression AND expression {
                       $$=new and_Node();
                       $$->add($1);
                        $$->add($3);
          }
          | expression AT expression {
                       $$=new at_Node("AT");
                       $$->add($1);
                        $$->add($3);
          }
          | expression LOGICALOR expression {
                      $$=new logicalor("logicalor");
                      $$->add($1);
                       $$->add($3);
          }
          | expression LOGICALAND expression {
                    $$=new logicaland("logicaland");
                      $$->add($1);
                       $$->add($3);
           }
          | LOGICALNOT expression {
                    $$=new logicalnot("logicalnot");
                      $$->add($1);
                       $$->add($2);
          }
          | expression IDENTITY expression {
                    $$=new identity("identity");
                            $$->add($1);
                            $$->add($3);
          }
          | expression MEMBERSHIP expression {
                    $$=new membership("membership");
                            $$->add($1);
                            $$->add($3);
           }
          | expression EQUALITY expression {
                    $$=new equality("equality");
                      $$->add($1);
                       $$->add($3);
          }
          | expression RELATIONAL expression {
                    $$=new relational("relational");
                      $$->add($1);
                       $$->add($3);
          }
          | expression '|' expression { /*fprintf(yyout, "Bitwise OR\n");*/ }
          | expression '^' expression { /*fprintf(yyout, "Bitwise XOR\n");*/ }
          | expression '&' expression {/* fprintf(yyout, "Bitwise AND\n");*/ }
          | expression BITWISESHIFT expression { /*fprintf(yyout, "Bitwise Shift\n");*/ }
          | expression '+' expression { /*fprintf(yyout, "Addition\n");*/ }
          | expression '-' expression { /*fprintf(yyout, "Subtraction\n");*/ }
          | expression '*' expression { /*fprintf(yyout, "Multiplication\n");*/ }
          | expression '%' expression { /*fprintf(yyout, "Modulus\n"); */}
          | expression '/' expression { /*fprintf(yyout, "Division\n");*/ }
          | expression DIVFLOOR expression { /*fprintf(yyout, "Division Floor\n");*/ }
          | '-' expression %prec UNARY { /*fprintf(yyout, "Unary Minus\n"); */}
          | '+' expression %prec UNARY { /*fprintf(yyout, "Unary Plus\n");*/ }
          | '~' expression %prec UNARY { /*fprintf(yyout, "Bitwise Not\n");*/ }
          | expression EXPONENTIATION expression { /*fprintf(yyout, "Exponentiation\n"); */}
          | NUMBER
          | NUMBER COMMA NUMBER { /*fprintf(yyout, "Comparison\n");*/ }
          | STRING
          | STRING COMMA expression
          | expression COMMA expression
          | LPAREN expression RPAREN { /*printf("Processed expression within parentheses\n"); */}
          | IDENTIFIER ASSIGNMENT expression {/* fprintf(yyout, "Assignment\n");*/ }
          | IDENTIFIER { /*fprintf(yyout, "Identifier\n");*/ }
          | IDENTIFIER ASSIGNMENT LBRACKET expression RBRACKET {/* fprintf(yyout, "Array Access\n"); */}
          | IDENTIFIER AS IDENTIFIER ASSIGNMENT expression { /*fprintf(yyout, "Type Alias\n"); */}
          ;

return: RETURN args_expressions SEMICOLON{
                $$=new return_statement("return_statement");
                    $$->add($1);
                    $$->add($2);
                }
                | RETURN SEMICOLON{
                    $$=new return_statement("return_statement");
                    $$->add($1);
                };

break: BREAK SEMICOLON {
                    $$=new break_statement("break_statement");
                    $$->add($1);
                };

continue: CONTINUE SEMICOLON {
                    $$=new continue_statement("continue_statement");
                    $$->add($1);
                };

global: GLOBAL args_identifiers SEMICOLON{
    $$=new global_statement("global_statement");
                    $$->add($1);
                    $$->add($2);
};

nonlocal: NONLOCAL args_identifiers SEMICOLON
        {
            $$=new nonlocal_statement("nonlocal_statement");
                    $$->add($1);
                    $$->add($2);
        };

yield: YIELD args_expressions SEMICOLON{
                    $$=new yield_statement("yield_statement");
                    $$->add($1);
                    $$->add($2);
        };

function_call: IDENTIFIER LPAREN args RPAREN COMMA{
                $$=new function_call("function_call");
                    $$->add($1);
                    $$->add($3);
        }
                |IDENTIFIER LPAREN args RPAREN ASSIGNMENT{
                    $$=new function_call("function_call");
                    $$->add($1);
                    $$->add($3);
                    $$->add($5);
                };


if: IF expression COLON stats elif{
        $$=new if_statement("if_statement",$2);
                    $$->add($4);
                    $$->add($5);
    } ;

elif: ELIF expression COLON stats elif
              | else;

else: ELSE COLON stats
        {
            $$=new else_statement("else_statement");
                    $$->add($1);
                    $$->add($3);
        } ;




while: WHILE expression COLON stats{
                $$=new while_statement("while_statement",$2);
                    $$->add($4);
            }
                |WHILE expression COLON stats else{
                    $$=new while_statement("while_statement",$2);
                    $$->add($2);
                    $$->add($4);
                    $$->add($5);
                };

for: FOR IDENTIFIER IN RANGE expression COLON stats  {
                $$=new for_statement("for_statement");
                    $$->add($1);
                     $$->add($2);
                     $$->add($3);
                      $$->add($4);
                    $$->add($5);
                    $$->add($7);
            }
            | FOR IDENTIFIER IN expression COLON stats {
                $$=new for_statement("for_statement");
                    $$->add($1);
                     $$->add($2);
                     $$->add($3);
                     $$->add($4);
                    $$->add($6);
            }
            ;


assert: ASSERT expression SEMICOLON {
                 $$=new assert_statement("assert_statement");
                    $$->add($1);
                     $$->add($2);
            }
               ;




block: LBRACE stats RBRACE {
                    $$=new block("block");
                    $$->add($2);
            }
        ;

class: CLASS IDENTIFIER COLON stats{
                    $$=new class_statement("class_statement");
                    $$->add($1);
                    $$->add($2);
                    $$->add($4);
                }
                | CLASS IDENTIFIER LPAREN class_args RPAREN COLON stats SEMICOLON{
                    $$=new class_statement("class_statement");
                    $$->add($2);
                    $$->add($4);
                    $$->add($7);
                }
                ;


with: WITH with COLON stats else SEMICOLON{
                $$=new with_statement("with_statement");
                    $$->add($1);
                    $$->add($2);
                    $$->add($4);
                    $$->add($5);
            };
with: generator{
            $$=new with("with");
                    $$->add($1);
        }
    | with_as{
        $$=new with("with");
                    $$->add($1);
    }
    | complex_with_as_stat{
        $$=new with("with");
                    $$->add($1);
    }
    ;
complex_with_as_stat: LPAREN args_generator RPAREN AS LPAREN args_identifiers RPAREN{
    $$=new complex_with_as_statement("complex_with_as_statement");
                    $$->add($2);
                     $$->add($4);
                      $$->add($6);
}


args_generator: generator
    | generator COMMA args_generator
    ;



with_as: generator AS IDENTIFIER
    | generator AS IDENTIFIER COMMA with_as
    ;





try: TRY COLON stats except_stat_list else finally_stat{
                    $$=new try_statement("try_statement");
                     $$->add($3);
                      $$->add($4);
                      $$->add($5);
                      $$->add($6);
                      };

except_stat_list:  except_stat {
    $$=new except_statement_list("except_statement_list");
                    $$->add($1);
 }
    | except_stat except_stat_list {
        $$=new except_statement_list("except_statement_list");
                    $$->add($1);
    }
    ;
except_stat: EXCEPT except_expression COLON stats{
    $$=new except_statement("except_statement");
                    $$->add($2);
                    $$->add($4);
};
except_expression:
    | generator
    | LPAREN args_generator RPAREN
    | exception_as
    ;
exception_as: IDENTIFIER AS generator;

function_identifier_parameter: IDENTIFIER
                                | UNDERSCORE { /*fprintf(yyout, "Underscore Identifier\n"); */}
                                | IDENTIFIER ':' IDENTIFIER
                                ;


args_expressions: expression COMMA args_expressions  {/* fprintf(yyout, "args_expressions\n"); */}
                | expression;

args_identifiers: IDENTIFIER COMMA args_identifiers
                | IDENTIFIER;


args: expression COMMA args
    | expression
    | EXPONENTIATION IDENTIFIER
    | '*' IDENTIFIER COMMA args
    | IDENTIFIER ASSIGNMENT expression COMMA args;


range_expression: LPAREN NUMBER COMMA NUMBER RPAREN {/*
    printf("Range expression: (%s, %s)\n", $2, $4);*/
}

generator: IDENTIFIER
         | function_call;

class_args: IDENTIFIER
    | IDENTIFIER COMMA class_args
    | IDENTIFIER LBRACKET args_identifiers RBRACKET
    | IDENTIFIER LBRACKET args_identifiers RBRACKET COMMA class_args
    ;

finally_stat:
    | FINALLY COLON block { /*fprintf(yyout, "Finally stat\n");*/ }
    ;
match: MATCH expression_stat COLON INDENT pattern_list DEDENT SEMICOLON;
pattern_list: pattern else SEMICOLON {/* fprintf(yyout, "Case stat\n");*/ }
    | pattern pattern_list SEMICOLON {/* fprintf(yyout, "Case stat\n"); */}
    ;
pattern: CASE expression_stat COLON block SEMICOLON
    | CASE IDENTIFIER AS IDENTIFIER COLON block SEMICOLON
    | CASE expression_stat IF args_expressions COLON block SEMICOLON
    ;

function_def: DEF IDENTIFIER expression COLON stats {/* fprintf(yyout, "Function Declaration\n"); */}
                            | DEF IDENTIFIER LPAREN function_declaratin_args RPAREN ARROW IDENTIFIER COLON stats SEMICOLON;


function_declaratin_args:
    | function_identifier_parameter COMMA
    | function_identifier_parameter COMMA function_declaratin_args
    | keyword_args
    ;
function_identifier_parameter: IDENTIFIER
    | IDENTIFIER COLON IDENTIFIER
    ;
keyword_args: IDENTIFIER ASSIGNMENT expression_stat
    | IDENTIFIER ASSIGNMENT expression_stat COMMA keyword_args
    ;



/*
varibale_arg: | '*' IDENTIFIER | '*' IDENTIFIER COMMA;
keyword_args:
    | IDENTIFIER ASSIGNMENT expression_stat COMMA
    | keyword_arg_list
    ;
keyword_arg_list: IDENTIFIER ASSIGNMENT expression_stat
    | IDENTIFIER ASSIGNMENT expression_stat COMMA keyword_arg_list
    ;
*/
%%



int main(int argc, char **argv)
{

     if (argc > 1){
        for(int i=0;i<argc;i++)
            yyin=fopen(argv[1],"r");
      }
      else
        yyin=stdin;

      yyparse();

      // AST is constructed, you can print it now
      if (root != NULL) {
            AST ast(root);
            ast.Print();
      }
      return 0;
}


void yyerror(const char* s) {
    std::cerr << "Parser error: " << s << std::endl;
}
