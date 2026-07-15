%{
    #include<stdio.h>
    #include<ctype.h>
    int lno=1;
%}

letter      [a-zA-Z]

digit       [0-9]

id          {letter}({letter}|{digit})*

num         {digit}+

keywd       "main"|"while"|"float"|"int"|"if"|"printf"|"else"

arry        ({id}"["({num}|{id})"]")

ws          [ \t]

commt       ("/*"({id}|"\n"|{num}|{ws})*"*/")

sp          [;,.]

literal     (\"([^\"\\]|\\.)*\")
%%


[\n]                    {lno++;}

{ws}                    {}

{sp}                    {printf("special symbols = %s in line = %d\n",yytext,lno);}

">"|"<"|"<="|">="       {printf("relation operator = %s in line = %d\n",yytext,lno);}

{literal}               {printf("string literal  = %s in line = %d\n",yytext,lno);}

{commt}                 {printf("comment = %s in line = %d\n",yytext,lno);}

"="                     {printf("assignment oper = %s in line = %d\n",yytext,lno);}

"+"|"-"|"*"|"/"         {printf("arithmetic oper= %s in line = %d\n",yytext,lno);}

"["|"]"|"{"|"}"|"("|")" {printf("parenthesis = %s in line = %d\n",yytext,lno);}

{keywd}                 {printf("keyword = %s in line = %d\n",yytext,lno);}

{arry}                  {printf("array = %s in line = %d\n",yytext,lno);}

{id}                    {printf("identifier = %s in line = %d\n",yytext,lno);}

{num}                   {printf("number constant= %s in line = %d\n",yytext,lno);}

.                       {printf("error in %d is %s",lno,yytext);}
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
/*yywrap is called whenever lex reaches an end-of-file we must define this function because yylex() need it*/
int yywrap(){
    exit(0);
}