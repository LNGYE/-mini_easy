%{
#include <stdlib.h>
#include "tac.h"
#include "y.tab.h"
%}

%option yylineno

%%

"int"  {  return INT;  }

"char"  {  return CHAR;  }

"print"  {  return PRINT;  }

"return"  {  return RETURN;  }

"continue"  {  return CONTINUE;  }

"if"  {  return IF;  }

"then"  {  return THEN;  }

"else"  {  return ELSE;  }

"fi"  {  return FI;  }

"while"  {  return WHILE;  }

"for"  { return FOR; }

"do"  {  return DO;  }

"done"  {  return DONE;  }

[A-Za-z]([A-Za-z]|[0-9])*  {  
	yylval.string = strdup(yytext); 
	return IDENTIFIER;
}


[0-9]*	{
	yylval.string = strdup(yytext); 
	return INTEGER;
}

\"[^\"]*\"  {
	yylval.string = strdup(yytext); 
	return TEXT;
}

\'[^\']*\'  {
	yylval.string = strdup(yytext); 
	return CHARTEXT;
}

"=="  {  return EQ;  }

"!="  {  return NE;  }

"<="  {  return LE;  }

"<"  {  return LT;  }

">="  {  return GE;  }

">"  {  return GT;  }

"||"  { return OR; }

"&&"  {  return AND; }

"!"   {  return NOT; }

[ \t\r\n]|#.*

. 	{	return *yytext; }

%%

int yywrap()
{
	return 1;
}

