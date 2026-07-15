%{
#include <stdio.h>
#include <math.h>
%}
%%
"/*"(.|\n)*"*/"  { printf( "comment is: %s\n", yytext);}
.		         {} 			           		
%%

void main(int argc, char **argv)
{
	yyin=fopen(argv[1],"r");
	while(yylex() != 0);
}
/*yywrap is called whenever lex reaches an end-of-file we must define this function because yylex() need it*/
int yywrap(){
    return 0;
}