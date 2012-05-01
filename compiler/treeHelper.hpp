#ifndef _TREE_HELPER_HPP_
#define _TREE_HELPER_HPP_

#include <list>
#include "quadruple.hpp"
#include "parseTree.hpp"
#include "token.hpp"
#include "symbolTable.hpp"
#include "function_table.hpp"

namespace Bubble {
	class TypeChecker{
	public:
		static int matchType(const Token::TYPE typeA, const Token::TYPE typeB, const int& type);
		static int matchType(const Token::TYPE typeA, const int& type);
        static int matchType(const ParseTreeNode<Token>* nodeA, const ParseTreeNode<Token>* nodeB, const int& type);
        static int matchType(const ParseTreeNode<Token>* nodeA, const int& type);
		static int matchArrayType(const Token::TYPE typeA, const Token::TYPE typeB, const int& type);
		static int matchArrayType(const Token::TYPE typeA, const int& type);
        static int matchArrayType(const ParseTreeNode<Token>* nodeA, const ParseTreeNode<Token>* nodeB, const int& type);
        static int matchArrayType(const ParseTreeNode<Token>* nodeA, const int& type);
	};
	
    class TreeHelper {
    public:
		static int IFstep1(
				const ParseTreeNode<Token>* node,
				const std::string& labelA, const std::string& labelB,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static int IFstep2(
				const std::string& labelB, const std::string& labelC,
				QuadrupleVector* quad_vector
		);

		static int IFstep3(
				const std::string& labelC,
				QuadrupleVector* quad_vector
		);

		static int WhileStep1(
				const std::string& labelA,
				QuadrupleVector* quad_vector
		);
		
		static int WhileStep2(
				const ParseTreeNode<Token>* node,
				const std::string& labelB, const std::string& labelC,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static int WhileStep3(
				const std::string& labelA,
				const std::string& labelC,
				QuadrupleVector* quad_vector
		);

		static ParseTreeNode<Token>* PrintStmt(
				const ParseTreeNode<Token>* id,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static ParseTreeNode<Token>* PrintArrayStmt(
				const ParseTreeNode<Token>* id, int cnt,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static ParseTreeNode<Token>* FuncCall(
				const ParseTreeNode<Token>* id,
				FunctionTable& function_tbl, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);
				
		static ParseTreeNode<Token>* FuncCall(
				const ParseTreeNode<Token>* id,
				const ParseTreeNode<Token>* arg,
				FunctionTable& function_tbl, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static ParseTreeNode<Token>* Expr(
				const ParseTreeNode<Token>* nodeA, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);
		
        static ParseTreeNode<Token>* UnaryExpr(
				const ParseTreeNode<Token>* nodeA, 
				const Operator& op, const int& iType, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

        static ParseTreeNode<Token>* BinaryExpr(
				const ParseTreeNode<Token>* nodeA, const ParseTreeNode<Token>* nodeB, 
				const Operator& op, const int& iType, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static std::list<const ParseTreeNode<Token>*> RetrieveList(
				const ParseTreeNode<Token>* nodeA,
				const std::string& delim
		);

		static int VarAssign(
				const ParseTreeNode<Token>* var, const ParseTreeNode<Token>* value,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static int LArrayAssign(
				const ParseTreeNode<Token>* array, const ParseTreeNode<Token>* value,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static ParseTreeNode<Token>* ArrayRef(
				const ParseTreeNode<Token>* node, const int& type, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static ParseTreeNode<Token>* ArrayDef(
				const ParseTreeNode<Token>* node, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

	protected:
		static Token* GetToken(const ParseTreeNode<Token>* node, const SymbolTable& symbol_tbl);
		static const ParseTreeNode<Token>* ProcessNode(
				const ParseTreeNode<Token>* node, const int& type, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

		static const ParseTreeNode<Token>* ProcessNode2(
				const ParseTreeNode<Token>* node, const int& type, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector
		);

        static ParseTreeNode<Token>* TmpVar(SymbolTable& symbol_tbl);

		static void retrieve_list_rec(
				const ParseTreeNode<Token>* nodeA, 
				const std::string& delim, std::list<const ParseTreeNode<Token>*>& lst
		);
    };
}
#endif
