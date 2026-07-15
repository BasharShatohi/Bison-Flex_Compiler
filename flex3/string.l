%option noyywrap
%x STRING
%{
char* string_literal_value = NULL;
#define STRING_LITERAL 265
%}


%{
    #include<stdio.h>
    #include<ctype.h>
    #include <string.h>
%}


%%

\" 			{
    				BEGIN(STRING);  // Transition to the STRING start condition when a double quote is encountered
    				string_literal_value = strdup("");  // Initialize the string literal value
			}
			
			
<STRING>[^\"\n\\]+ 	{
    				string_literal_value = realloc(string_literal_value, strlen(string_literal_value) + yyleng + 1);
    				strcat(string_literal_value, yytext);
			}
			
			
<STRING>\\\n 		{	//string_literal_value = realloc(string_literal_value, strlen(string_literal_value) + 1);strcat(string_literal_value, "\n");  
			}


<STRING>\\\" 		{
    				string_literal_value = realloc(string_literal_value, strlen(string_literal_value) + 1);
    				strcat(string_literal_value, "\"");  // Handle escaped double quote
			}


<STRING>\" 		{
    				BEGIN(INITIAL);  // Return to the initial start condition when a closing double quote is encountered
    				printf("the end of STate: %s\n", string_literal_value);
    				return STRING_LITERAL;  // Return the STRING_LITERAL token
			}


			
. 			{
    				/* Ignore everything else in the STRING start condition */
			}



%%

void main(int argc, char **argv)
{
    if (argc > 1){
        for(int i=0;i<argc;i++)
            printf("value of argv[%d] = %s\n\n",i,argv[i]);
            yyin=fopen(argv[1],"r");
    }
    
    else
        yyin=stdin;
    yylex();    
}
