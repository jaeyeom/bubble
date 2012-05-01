%{
	
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include "bubbleLexer.hpp"
#include "token.hpp"
#include "parseTree.hpp"
#include "treeHelper.hpp"
#include "quadruple.hpp"
#include "symbolTable.hpp"
#include "function_table.hpp"

#define YYDEBUG 	1

extern int lineno;
extern Bubble::ParseTreeNode<Bubble::Token>* root_node;
extern Bubble::SymbolTable symbol_tbl;
extern Bubble::FunctionTable function_tbl;
Bubble::QuadrupleVector* quad_vector = NULL;
Bubble::FunctionEntry* func_entry = NULL;

void dummy() {
	return ;
}
	
%}

%union
{
	int ival;
	float fval;
	std::string *sval;
	std::string *id;
	std::string *id_lst;
	Bubble::ParseTreeNode<Bubble::Token>* token;
}

%token PRINT
%token ERROR_TOKEN
%token IF ELSE
%token WHILE
%token BEG END

%token COMMA COLON LPAREN RPAREN LBRACKET RBRACKET NL
%token PLUS MINUS STAR DIV AND OR NOT
%token ASSIGN GTH GEQ LTH LEQ EQ NEQ

%token <ival> INT_VAL
%token <fval> DOUBLE_VAL
%token <sval> STRING_VAL
%token <id> ID

%type <token> bubble declare_stmt function_definition block_stmt stmts
%type <token> stmt expr_stmt while_stmt if_stmt if_block else_block 
%type <token> expr assign_expr rhs_expr array_expr or_expr and_expr equality_expr cmp_expr
%type <token> add_expr mul_expr unary_expr postfix_expr function_call rhs_expr_list primary_expr id_list
%%
bubble
	: declare_stmt
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			$$ = node;
			root_node = node
		}
	| bubble declare_stmt
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			node->AppendChild($2);
			$$ = node;
			root_node = node
		}
	;

declare_stmt
	: NL 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			$$ = node;
		}
	| function_definition 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			$$ = node;
		}
	;

function_definition
	: ID LPAREN id_list RPAREN NL 
		{
			Bubble::IDToken* id = new Bubble::IDToken(*$1, Bubble::Token::T_FUNC);
			symbol_tbl.put(*$1, *id);
			delete id;

			symbol_tbl.push();

			std::string* arg_first = new std::string[4];
			Bubble::FunctionEntry* func = new Bubble::FunctionEntry(*$1);
			std::list<const Bubble::ParseTreeNode<Bubble::Token>*> lst = Bubble::TreeHelper::RetrieveList($3, "COMMA");
			std::list<const Bubble::ParseTreeNode<Bubble::Token>*>::const_iterator c_iter = lst.begin();
			for (int i = 0; c_iter != lst.end(); c_iter++, i++) {
				Bubble::IDToken* id = ((Bubble::IDToken*)((*c_iter)->Item()));
				if (i < 4) {
					symbol_tbl.putParamFirst(id->getValue(), *id);
					arg_first[i] = id->getValue();

				} else
					symbol_tbl.putParam(id->getValue(), *id);

				Bubble::IDToken* id2;
				symbol_tbl.get(id->getValue(), id2);
				func->AddParameter(id2);
			}
			
			$<id_lst>$ = arg_first;
			quad_vector = func->getBody();
			func_entry = func;

		}
	block_stmt
		{
			std::string* arg_first = $<id_lst>6;
			int cnt = 4;
			if (func_entry->param_list.size() < 4)
				cnt = func_entry->param_list.size();

			for (int i = 0; i < cnt; i++) {
				symbol_tbl.setParamFirst(arg_first[i]);
			}

			function_tbl.Put(func_entry->name, *func_entry);
			symbol_tbl.pop();

			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			{
				Bubble::Token* item = new Bubble::IDToken(*($1));
				node->AppendChild(new Bubble::ParseTreeNode<Bubble::Token>(item));
			}
			node->AppendChild($3);
			node->AppendChild($7);
			$$ = node;
		}
	| ID LPAREN RPAREN NL 
		{
			Bubble::IDToken* id = new Bubble::IDToken(*$1, Bubble::Token::T_FUNC);
			symbol_tbl.put(*$1, *id);
			delete id;

			symbol_tbl.push();

			Bubble::FunctionEntry* func = new Bubble::FunctionEntry(*$1);

			std::cerr << "Func: " << *$1 << "()" << std::endl;

			quad_vector = func->getBody();
			func_entry = func;
		}
	block_stmt
		{
			function_tbl.Put(func_entry->name, *func_entry);
			symbol_tbl.pop();

			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			{
				Bubble::Token* item = new Bubble::IDToken(*($1));
				node->AppendChild(new Bubble::ParseTreeNode<Bubble::Token>(item));
			}
			node->AppendChild($6);
			$$ = node;
		}
	;

block_stmt
	: BEG NL 
		{
		}
	stmts END NL
		{
			Bubble::Token* item = new Bubble::Token("BLOCK");
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);
			node->AppendChild($4);
			$$ = node;
		}
	;

stmts
	: stmt 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			$$ = node;
		}
	| stmts stmt 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			node->AppendChild($2);
			$$ = node;
		}
	;

stmt
	: expr_stmt NL
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			{
				Bubble::Token* item = new Bubble::Token("NL");
				node->AppendChild(new Bubble::ParseTreeNode<Bubble::Token>(item));
			}
			$$ = node;
		}
	| while_stmt 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			$$ = node;
		}
	| if_stmt 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			$$ = node;
		}
	| block_stmt 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			$$ = node;
		}
	;

expr_stmt
	: 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			$$ = node;
		}
	| expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			$$ = node;
		}
	| PRINT expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = Bubble::TreeHelper::PrintStmt($2, symbol_tbl, quad_vector);
			if (node == NULL)
				yyerror("Compile Error: print_expr");
			$$ = $2;
		}
	| PRINT expr INT_VAL
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = Bubble::TreeHelper::PrintArrayStmt($2, $3, symbol_tbl, quad_vector);
			if (node == NULL)
				yyerror("Compile Error: print_array_expr");
			$$ = $2;
		}
	;
	
while_stmt 
	: WHILE 
		{
			dummy();
			std::string* labelA = new std::string(Bubble::label());
			$<sval>$ = labelA;
			Bubble::TreeHelper::WhileStep1(*labelA, quad_vector);
		}
	expr NL 
		{
			dummy();
			std::string labelB = Bubble::label();
			std::string* labelC = new std::string(Bubble::label());
			$<sval>$ = labelC;
			if (Bubble::TreeHelper::WhileStep2($3, labelB, *labelC, symbol_tbl, quad_vector) < 0) {
				yyerror("Compile Error: while_stmt");
			}
		}
	block_stmt
		{
			dummy();
			if (Bubble::TreeHelper::WhileStep3(*$<sval>2, *$<sval>5, quad_vector) < 0) {
				yyerror("Compile Error: while_stmt");
			}

			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($3);
			node->AppendChild($6);
			$$ = node;
		}
	;

if_stmt
	: if_block else_block
		{
			dummy();
			std::string labelC = ((Bubble::Label*)($1->Child(2)->Item()))->getValue();
			if (Bubble::TreeHelper::IFstep3(labelC, quad_vector) < 0) {
				yyerror("Compile Error: if_stmt");
			}

			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			node->AppendChild($1);
			node->AppendChild($2);
			$$ = node;
		}
	;

if_block
	: IF expr NL 
		{
			std::string labelA = Bubble::label();
			std::string labelB = Bubble::label();
			$<sval>$ = &labelB;
			if (Bubble::TreeHelper::IFstep1($2, labelA, labelB, symbol_tbl, quad_vector) < 0) {
				yyerror("Compile Error: if_stmt");
			}
		}
	block_stmt 
		{
			std::string labelC = Bubble::label();
			if (Bubble::TreeHelper::IFstep2(*($<sval>4), labelC, quad_vector) < 0) {
				yyerror("Compile Error: if_stmt");
			}

			dummy();
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>();
			Bubble::ParseTreeNode<Bubble::Token>* lab = new Bubble::ParseTreeNode<Bubble::Token>(new Bubble::Label(labelC));
			node->AppendChild($2);
			node->AppendChild($5);
			node->AppendChild(lab);
			$$ = node;
		}
	;

else_block
	:
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(new Bubble::Token("DUMMY"));
			$$ = node;
		}
	| ELSE NL block_stmt
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(new Bubble::Token("ELSE"));
			node->AppendChild($3);
			$$ = node;
		}
	;

expr
	: assign_expr
		{
			$$ = $1;
		}
	;

assign_expr
	: rhs_expr 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = Bubble::TreeHelper::Expr($1, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: assign_expr");
				exit(-1);
			}

			$$ = node;
		}
	| postfix_expr ASSIGN rhs_expr
		{
			Bubble::Token* item = NULL;
			if ($1->Item()->getType() == "ID") {
				if (Bubble::TreeHelper::VarAssign($1, $3, symbol_tbl, quad_vector) < 0) {
					yyerror("Compile Error: assign_expr1");
					exit(-1);
				}

				item = $3->Item()->clone();

			} else if ($1->Item()->getType() == "ARRAY_REF") {
				if (Bubble::TreeHelper::LArrayAssign($1, $3, symbol_tbl, quad_vector) < 0) {
					yyerror("Compile Error: assign_expr2");
					exit(-1);
				}

				item = $3->Item()->clone();

			} else {
				yyerror("Compile Error: assign_expr(" + $1->Item()->getType() + ", " + $3->Item()->getType() + ")");
				exit(-1);
			}

			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);
			node->AppendChild($1);
			node->AppendChild($3);
			$$ = node;
		}
	;

rhs_expr
	: or_expr
		{
			$$ = $1;
		}
	| array_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node = Bubble::TreeHelper::ArrayDef($1, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: rhs_expr");
				exit(-1);
			}
			$$ = node;
		}
	;

array_expr
	: LBRACKET rhs_expr_list RBRACKET
		{
			$$ = $2;
		}
	;

or_expr
	: and_expr
		{
			$$ = $1;
		}
	| or_expr OR and_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::OROP, Bubble::Token::T_INT, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: or_expr");
				exit(-1);
			}

			$$ = node;
		}
	;

and_expr
	: equality_expr
		{
			$$ = $1;
		}
	| and_expr AND equality_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::ANDOP, Bubble::Token::T_INT, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: and_expr");
				exit(-1);
			}

			$$ = node;
		}
	;

equality_expr
	: cmp_expr
		{
			$$ = $1;
		}
	| equality_expr EQ cmp_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::EQOP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: equality_expr");
				exit(-1);
			}

			$$ = node;
		}
	| equality_expr NEQ cmp_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::NEQOP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: equality_expr");
				exit(-1);
			}

			$$ = node;
		}
	;

cmp_expr
	: add_expr
		{
			$$ = $1;
		}
	| cmp_expr LEQ add_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::LEQOP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: cmp_expr");
				exit(-1);
			}

			$$ = node;
		}
	| cmp_expr LTH add_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::LESSOP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: cmp_expr");
				exit(-1);
			}

			$$ = node;
		}
	| cmp_expr GEQ add_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::GEQOP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: cmp_expr");
				exit(-1);
			}

			$$ = node;
		}
	| cmp_expr GTH add_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::GREATEROP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: cmp_expr");
				exit(-1);
			}

			$$ = node;
		}
	;

add_expr
	: mul_expr
		{
			$$ = $1;
		}
	| add_expr PLUS mul_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::ADDOP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: add_expr");
				exit(-1);
			}

			$$ = node;
		}
	| add_expr MINUS mul_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::SUBOP, Bubble::Token::T_INT | Bubble::Token::T_STR, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: add_expr");
				exit(-1);
			}

			$$ = node;
		}
	;

mul_expr
	: unary_expr
		{
			$$ = $1;
		}
	| mul_expr STAR unary_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::MULOP, Bubble::Token::T_INT, symbol_tbl, quad_vector);
			if (node == NULL) {
				yyerror("Compile Error: mul_expr");
				exit(-1);
			}

			$$ = node;
		}
	| mul_expr DIV unary_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::BinaryExpr($1, $3, Bubble::DIVOP, Bubble::Token::T_INT, symbol_tbl, quad_vector);
			
			if (node == NULL) {
				yyerror("Compile Error: mul_expr");
				exit(-1);
			}

			$$ = node;
		}
	;

unary_expr
	: postfix_expr
		{
			$$ = $1;
		}
	| MINUS postfix_expr 
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::UnaryExpr($2, Bubble::MINUSOP, Bubble::Token::T_INT, symbol_tbl, quad_vector);
			
			if (node == NULL) {
				yyerror("Compile Error: unary_expr");
				exit(-1);
			}

			$$ = node;
		}
	| NOT postfix_expr
		{
			Bubble::ParseTreeNode<Bubble::Token>* node 
				= Bubble::TreeHelper::UnaryExpr($2, Bubble::NOTOP, Bubble::Token::T_INT, symbol_tbl, quad_vector);
			
			if (node == NULL) {
				yyerror("Compile Error: unary_expr");
				exit(-1);
			}

			$$ = node;
		}
	;

postfix_expr
	: primary_expr
		{
			$$ = $1;
		}
	| primary_expr LBRACKET expr RBRACKET
		{
			if ($1->Item()->getType() != "ID") {
				yyerror("Compile Error: postfix_expr: " + $1->Item()->getType() + " should be ID");
				exit(-1);
			}

			if (Bubble::TypeChecker::matchType($1, Bubble::Token::T_INT_ARRAY | Bubble::Token::T_STR_ARRAY) < 0) {
				yyerror("Compile Error: postfix_expr");
				exit(-1);
			}

			if (Bubble::TypeChecker::matchType($3, Bubble::Token::T_INT) < 0) {
				yyerror("Compile Error: postfix_expr");
				exit(-1);
			}

			Bubble::Token* item = new Bubble::Token("ARRAY_REF");
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);
			node->AppendChild($1);
			node->AppendChild($3);
			$$ = node;
		}
	| function_call
		{
			$$ = $1;
		}
	;

function_call
	: ID LPAREN RPAREN
		{
			Bubble::Token* item = new Bubble::IDToken(*($1));
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);

			Bubble::ParseTreeNode<Bubble::Token>* ret = Bubble::TreeHelper::FuncCall(node, function_tbl, symbol_tbl, quad_vector);
			if (ret == NULL) {
				yyerror("Compile Error: function_call");
			}

			$$ = ret;

		}
	| ID LPAREN rhs_expr_list RPAREN
		{
			Bubble::Token* item = new Bubble::IDToken(*($1));
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);

			Bubble::ParseTreeNode<Bubble::Token>* ret = Bubble::TreeHelper::FuncCall(node, $3, function_tbl, symbol_tbl, quad_vector);
			if (ret == NULL) {
				yyerror("Compile Error: function_call");
			}

			$$ = ret;
		}
	;

rhs_expr_list
	: rhs_expr
		{
			$$ = $1;
		}
	| rhs_expr_list COMMA rhs_expr
		{
			Bubble::Token* item = new Bubble::Token("COMMA");
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);
			node->AppendChild($1);
			node->AppendChild($3);
			$$ = node;
		}
	;
	
primary_expr
	: ID
		{
			Bubble::Token* item = new Bubble::IDToken(*($1));
			$$ = new Bubble::ParseTreeNode<Bubble::Token>(item);
		}
	| INT_VAL
		{
			Bubble::Token* item = new Bubble::Int($1);
			
			$$ = new Bubble::ParseTreeNode<Bubble::Token>(item);
		}
	| DOUBLE_VAL
		{
			Bubble::Token* item = new Bubble::Double($1);
			$$ = new Bubble::ParseTreeNode<Bubble::Token>(item);
		}
	| STRING_VAL
		{
			Bubble::Token* item = new Bubble::String(*($1));
			$$ = new Bubble::ParseTreeNode<Bubble::Token>(item);
		}
	;

id_list
	: ID
		{
			Bubble::Token* item = new Bubble::IDToken(*($1));
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);
			$$ = node;
		}
	| id_list COMMA ID
		{
			Bubble::Token* item = new Bubble::Token("COMMA");
			Bubble::ParseTreeNode<Bubble::Token>* node = new Bubble::ParseTreeNode<Bubble::Token>(item);
			node->AppendChild($1);
			{
				Bubble::Token* item = new Bubble::IDToken(*($3));
				node->AppendChild(new Bubble::ParseTreeNode<Bubble::Token>(item));
			}
			$$ = node;
		}
	;

%%

