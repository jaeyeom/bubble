
#ifndef _BUBBLE_HPP_
#define _BUBBLE_HPP_

#include <stdio.h>

int yyparse();
int yylex();
void yyerror(char *msg);
void yyerror(const std::string& msg);

extern FILE* yyin;

#include "token.hpp"

#endif
