%option noyywrap
%x S1
%x S2
%x S3
%{
#include <stdio.h>
#include <math.h>
%}
%%
"/"	  		{ BEGIN(S1); }
<S1>"*"                 { BEGIN(S2); }
<S2>[^*]         	;/* stay in S2 */
<S2>"*"          	BEGIN(S3);
<S3>"*"          	;/* stay in S3 */
<S3>[^*/]        	BEGIN(S2);
<S3>"/"           	BEGIN(INITIAL);
.		         {printf("%s",yytext);} 			           		
%%
void main(int argc, char **argv)
{
	yyin=fopen(argv[1],"r");
	while(yylex() != 0);
}
/*yywrap is called whenever lex reaches an end-of-file we must define this function because yylex() need it*/
/*int yywrap(){
    return 0;
}*/