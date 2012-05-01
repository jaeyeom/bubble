%{

#include <stdio.h>
#include <iostream>
#include <string>
#include "parseTree.hpp"	
#include "function_table.hpp"	
#include "bubbleLexer.hpp"
#include "bubbleParser.hpp"

using Bubble::Token;
using Bubble::print_token;

extern "C" int yywrap(void)
{
    return 1;
}

int lineno = 1;

void yyerror(const std::string& msg) {
    std::cerr << lineno << ": " << msg << std::endl;
}

void yyerror(char* msg)
{
    std::cerr << lineno << ": " << msg << std::endl;
}

%}

DIGIT	[0-9]
LETTER	[a-zA-Z_]

%%

print						{ return PRINT;		}
if							{ return IF;		}
else						{ return ELSE;		}
while						{ return WHILE;		}
begin						{ return BEG;		}
end							{ return END;		}

,							{ return COMMA;		}
\(							{ return LPAREN;	}
\)							{ return RPAREN;	}
\[							{ return LBRACKET;	}
\]							{ return RBRACKET;	}
:=							{ return ASSIGN;	}
\> 							{ return GTH; 		}
\<							{ return LTH;		}
==							{ return EQ;		}
\>=							{ return GEQ;		}
\<=							{ return LEQ;		}
!=							{ return NEQ;		}

\*							{ return STAR;		}
\/							{ return DIV;		}
\+							{ return PLUS;		}
-							{ return MINUS;		}

&&							{ return AND;		}
\|\|						{ return OR;		}
!							{ return NOT;		}

{DIGIT}+					{ 
								yylval.ival = atoi( yytext );	
								return INT_VAL;		
							}
{DIGIT}+"."{DIGIT}+			{ 
								yylval.fval = atof( yytext );
								return DOUBLE_VAL;	
							}
\"[^\"]*\"					{
								yylval.sval = new std::string(yytext + 1, strlen(yytext + 1) - 1);
								return STRING_VAL;
							}
{LETTER}({LETTER}|{DIGIT})*	{ 
								yylval.id = new std::string(yytext);	
								return ID;
							}

\n							{ 
								++lineno; 
								return NL;
							}
[ \t]+						{ }			
.							{ return ERROR_TOKEN; 	}

%%


