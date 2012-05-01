#include <vector>
#include "treeHelper.hpp"

namespace Bubble {
	
	int 
	TypeChecker::matchType(const Token::TYPE typeA, const Token::TYPE typeB, const int& type) {
		if (typeA & Token::T_UNKNOWN == 0 && typeB & Token::T_UNKNOWN == 0) {
			if (typeA != typeB || typeA & type == 0 || typeB & type == 0) {
				return -1;
			}
			
		} else if (typeA & Token::T_UNKNOWN == 0) {
			if (typeA & type == 0 || (typeB & Token::T_ARRAY != 0 && type & Token::T_ARRAY == 0)) {
				return -1;
			}
		
		} else if (typeB != Token::T_UNKNOWN) {
			if (typeB & type == 0 || (typeA & Token::T_ARRAY != 0 && type & Token::T_ARRAY == 0)) {
				return -1;
			}
			
		} else {
			if ((typeA & Token::T_ARRAY != 0 || typeB & Token::T_ARRAY != 0) && type & Token::T_ARRAY == 0) {
				return -1;
			}
		}

		return 0;
	}
	
	int 
	TypeChecker::matchType(const Token::TYPE typeA, const int& type){
		if (typeA & Token::T_UNKNOWN == 0) {
			if (typeA & type == 0)
				return -1;
			
		} else {
			if (typeA & Token::T_ARRAY != 0 && type & Token::T_ARRAY == 0)
				return -1;
		}

		return 0;
	}

	int 
	TypeChecker::matchType(const ParseTreeNode<Token>* nodeA, const ParseTreeNode<Token>* nodeB, const int& type) {
		Token::TYPE typeA = nodeA->Item()->getValueType();
		Token::TYPE typeB = nodeB->Item()->getValueType();

		return matchType(typeA, typeB, type);
	}
	
	int 
	TypeChecker::matchType(const ParseTreeNode<Token>* nodeA, const int& type) {
		Token::TYPE typeA = nodeA->Item()->getValueType();

		return matchType(typeA, type);
	}

	int 
	TypeChecker::matchArrayType(const Token::TYPE typeA, const Token::TYPE typeB, const int& type) {
		if (typeA & Token::T_UNKNOWN == 0 && typeB & Token::T_UNKNOWN == 0) {
			if (typeA != typeB || typeA & type == 0 || typeB & type == 0 || typeA & Token::T_ARRAY == 0 || typeB & Token::T_ARRAY == 0)
				return -1;
			
		} else if (typeA & Token::T_UNKNOWN == 0) {
			if (typeA & type == 0 || typeA & Token::T_ARRAY == 0)
				return -1;
		
		} else if (typeB != Token::T_UNKNOWN) {
			if (typeB & type == 0 || typeA & Token::T_ARRAY == 0)
				return -1;
		}

		return 0;
	}

	int 
	TypeChecker::matchArrayType(const Token::TYPE typeA, const int& type){
		if (typeA & Token::T_UNKNOWN != 0) {
			if (typeA & type == 0 || typeA & Token::T_ARRAY == 0)
				return -1;
		}

		return 0;
	}
	
	int 
	TypeChecker::matchArrayType(const ParseTreeNode<Token>* nodeA, const ParseTreeNode<Token>* nodeB, const int& type) {
		Token::TYPE typeA = nodeA->Item()->getValueType();
		Token::TYPE typeB = nodeB->Item()->getValueType();

		return matchArrayType(typeA, typeB, type);
	}
	
	int
	TypeChecker::matchArrayType(const ParseTreeNode<Token>* nodeA, const int& type) {
		Token::TYPE typeA = nodeA->Item()->getValueType();

		return matchArrayType(typeA, type);
	}
	
	int
	TreeHelper::IFstep1(
				const ParseTreeNode<Token>* node, 
				const std::string& labelA, const std::string& labelB,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		const ParseTreeNode<Token>* proc_node = ProcessNode(node, Token::T_INT, symbol_tbl, quad_vector);
		if (proc_node == NULL)
			return -1;

		Token* b = GetToken(proc_node, symbol_tbl);
		Token* l1 = new Label(labelA);
		Token* l2 = new Label(labelB);

		Quadruple quad1(IFOP, l1, b, NULL);
		Quadruple quad2(GOTOOP, l2, NULL, NULL);
		Quadruple quad3(LABELOP, l1, NULL, NULL);

		quad_vector->push_back(quad1);
		quad_vector->push_back(quad2);
		quad_vector->push_back(quad3);

		return 0;
	}
	
	int
	TreeHelper::IFstep2(const std::string& labelB, const std::string& labelC, QuadrupleVector* quad_vector) {
		Token* l3 = new Label(labelC);
		Token* l2 = new Label(labelB);
		Quadruple quad1(GOTOOP, l3, NULL, NULL);
		Quadruple quad2(LABELOP, l2, NULL, NULL);

		quad_vector->push_back(quad1);
		quad_vector->push_back(quad2);

		return 0;
	}
	
	int
	TreeHelper::IFstep3(const std::string& labelC, QuadrupleVector* quad_vector) {
		Token* l3 = new Label(labelC);
		Quadruple quad(LABELOP, l3, NULL, NULL);

		quad_vector->push_back(quad);

		return 0;
	}

	int
	TreeHelper::WhileStep1(const std::string& labelA, QuadrupleVector* quad_vector) {
		Token* l1 = new Label(labelA);
		Quadruple quad(LABELOP, l1, NULL, NULL);

		quad_vector->push_back(quad);

		return 0;
	}

	int
	TreeHelper::WhileStep2(
				const ParseTreeNode<Token>* node, 
				const std::string& labelB, const std::string& labelC,
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		const ParseTreeNode<Token>* proc_node = ProcessNode(node, Token::T_INT, symbol_tbl, quad_vector);
		if (proc_node == NULL)
			return -1;

		Token* b = GetToken(proc_node, symbol_tbl);
		Token* l2 = new Label(labelB);
		Token* l3 = new Label(labelC);

		Quadruple quad1(IFOP, l2, b, NULL);
		Quadruple quad2(GOTOOP, l3, NULL, NULL);
		Quadruple quad3(LABELOP, l2, NULL, NULL);

		quad_vector->push_back(quad1);
		quad_vector->push_back(quad2);
		quad_vector->push_back(quad3);

		return 0;
	}
	
	int
	TreeHelper::WhileStep3(const std::string& labelA, const std::string& labelC, QuadrupleVector* quad_vector) {
		Token* l1 = new Label(labelA);
		Token* l3 = new Label(labelC);
		Quadruple quad1(GOTOOP, l1, NULL, NULL);
		Quadruple quad2(LABELOP, l3, NULL, NULL);

		quad_vector->push_back(quad1);
		quad_vector->push_back(quad2);

		return 0;
	}

	ParseTreeNode<Token>* 
	TreeHelper::PrintStmt(
			const ParseTreeNode<Token>* nodeA,
			SymbolTable& symbol_tbl, QuadrupleVector* quad_vector) 
	{
		const ParseTreeNode<Token>* value = ProcessNode(nodeA, Token::T_INT | Token::T_STR | Token::T_ARRAY, symbol_tbl, quad_vector);

		Token* a = GetToken(value, symbol_tbl);
		if (a == NULL)
			return NULL;

		Quadruple quad(PRINTOP, a, NULL, NULL);
		quad_vector->push_back(quad);

		return (ParseTreeNode<Token>*)value;
	}

	ParseTreeNode<Token>* 
	TreeHelper::PrintArrayStmt(
			const ParseTreeNode<Token>* nodeA, int cnt,
			SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		const ParseTreeNode<Token>* id = ProcessNode(nodeA, Token::T_INT | Token::T_STR | Token::T_ARRAY, symbol_tbl, quad_vector);

		for (int i = 0; i < cnt; i++) {
			ParseTreeNode<Token>* tmp = TreeHelper::TmpVar(symbol_tbl);

			Token* a = GetToken(tmp, symbol_tbl);
			Token* b = GetToken(id, symbol_tbl);
			Token* c = new Int(i);

			Quadruple quad1(RARRAYOP, a, b, c);
			Quadruple quad2(PRINTOP, a, NULL, NULL);
			quad_vector->push_back(quad1);
			quad_vector->push_back(quad2);
		}

		return (ParseTreeNode<Token>*)id;
	}

	ParseTreeNode<Token>*
	TreeHelper::FuncCall(
			const ParseTreeNode<Token>* id,
			FunctionTable& function_tbl, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		return FuncCall(id, NULL, function_tbl, symbol_tbl, quad_vector);
	}
		
	ParseTreeNode<Token>*
	TreeHelper::FuncCall(
				const ParseTreeNode<Token>* id,
				const ParseTreeNode<Token>* arg,
				FunctionTable& function_tbl, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		std::vector<Quadruple> qBuffer;

		const ParseTreeNode<Token>* func = ProcessNode(id, Token::T_FUNC, symbol_tbl, quad_vector);
		if (func == NULL)
			return NULL;

		int arg_cnt = 0;
		if (arg != NULL) {
			std::list<const ParseTreeNode<Token>*> arg_lst = RetrieveList(arg, "COMMA");
			arg_cnt = arg_lst.size();
			std::list<const ParseTreeNode<Token>*>::const_iterator c_iter = arg_lst.begin();
			for (; c_iter != arg_lst.end(); c_iter++) {
				const ParseTreeNode<Token>* value = ProcessNode2(*c_iter, Token::T_INT | Token::T_STR | Token::T_ARRAY, symbol_tbl, quad_vector);
				if (value == NULL)
					return NULL;
			
				Token* p = GetToken(value, symbol_tbl);
				if (p == NULL)
					return NULL;
		
				Quadruple quad(PARAMOP, p, 0, 0);
				qBuffer.push_back(quad);
			}
			std::vector<Quadruple>::const_iterator c_itr = qBuffer.begin();
			for (; c_itr != qBuffer.end(); c_itr++)
				quad_vector->push_back(*c_itr);
		}

		ParseTreeNode<Token>* node = TreeHelper::TmpVar(symbol_tbl);
		node->AppendChild(func);

		Token* a = GetToken(node, symbol_tbl);
		Token* b = GetToken(func, symbol_tbl)->clone();
		Token* c = new Int(arg_cnt);
		if (a == NULL || b == NULL || c == NULL)
			return NULL;

		Quadruple quad(FUNCTIONOP, a, b, c);
		quad_vector->push_back(quad);

		return node;
	}

	ParseTreeNode<Token>* 
	TreeHelper::Expr(
				const ParseTreeNode<Token>* nodeA, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector) 
	{
		ParseTreeNode<Token>* tmp = TreeHelper::TmpVar(symbol_tbl);
		tmp->AppendChild(nodeA);

		const ParseTreeNode<Token>* value 
				= ProcessNode(nodeA, Token::T_INT | Token::T_STR | Token::T_FUNC | Token::T_ARRAY, symbol_tbl, quad_vector);

		Token* a = GetToken(tmp, symbol_tbl);
		Token* b = GetToken(value, symbol_tbl);
		if (a == NULL || b == NULL)
			return NULL;

		Quadruple quad(ASSIGNOP, a, b, NULL);
		quad_vector->push_back(quad);

		return tmp;
	}

	ParseTreeNode<Token>*
	TreeHelper::UnaryExpr(
				const ParseTreeNode<Token>* nodeA, 
				const Operator& op, const int& iType, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		const ParseTreeNode<Token>* childA = ProcessNode(nodeA, iType, symbol_tbl, quad_vector);
		if (childA == NULL)
			return NULL;

		if (TypeChecker::matchType(childA, iType) < 0)
			return NULL;

		ParseTreeNode<Token>* node = TreeHelper::TmpVar(symbol_tbl);
		node->AppendChild(childA);

		Token* a = GetToken(node, symbol_tbl);
		Token* b = GetToken(childA, symbol_tbl);
		if (a == NULL || b == NULL)
			return NULL;

		Quadruple quad(op, a, b, NULL);
		quad_vector->push_back(quad);

		return node;
	}
	
	ParseTreeNode<Token>* 
	TreeHelper::BinaryExpr(
				const ParseTreeNode<Token>* nodeA, const ParseTreeNode<Token>* nodeB, 
				const Operator& op, const int& iType, 
				SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		const ParseTreeNode<Token>* childA = ProcessNode(nodeA, iType, symbol_tbl, quad_vector);
		const ParseTreeNode<Token>* childB = ProcessNode(nodeB, iType, symbol_tbl, quad_vector);
		if (childA == NULL || childB == NULL)
			return NULL;

		if (TypeChecker::matchType(childA, childB, iType) < 0)
			return NULL;

		ParseTreeNode<Token>* node = TreeHelper::TmpVar(symbol_tbl);
		node->AppendChild(childA);
		node->AppendChild(childB);

		Token* a = GetToken(node, symbol_tbl);
		Token* b = GetToken(childA, symbol_tbl);
		Token* c = GetToken(childB, symbol_tbl);
		if (a == NULL || b == NULL || c == NULL)
			return NULL;

		Quadruple quad(op, a, b, c);
		quad_vector->push_back(quad);

		return node;
	}

	std::list<const ParseTreeNode<Token>*>
	TreeHelper::RetrieveList(
			const ParseTreeNode<Token>* nodeA,
			const std::string& delim)
	{
		std::list<const ParseTreeNode<Token>*> lst;
		retrieve_list_rec(nodeA, delim, lst);

		return lst;
	}

	void
	TreeHelper::retrieve_list_rec(
			const ParseTreeNode<Token>* nodeA,
			const std::string& delim,
			std::list<const ParseTreeNode<Token>*>& lst)
	{
		if (nodeA->Item()->getType() == delim) {
			std::vector<const ParseTreeNode<Token>*> children = nodeA->Children();
			retrieve_list_rec(children[0], delim, lst);
			retrieve_list_rec(children[1], delim, lst);
			
		} else {
			lst.push_back(nodeA);
		}
	}

	Token*
	TreeHelper::GetToken(const ParseTreeNode<Token>* node, const SymbolTable& symbol_tbl) {
		if (node->Item()->getType() == "ID") {
			IDToken* idtok = NULL;

			IDToken* skey = (IDToken*)(node->Item());
			if (symbol_tbl.get(skey->getValue(), idtok) < 0)
				return NULL;
			return idtok;

		} else {
			return node->Item();
		}
	}
	
	const ParseTreeNode<Token>* 
	TreeHelper::ProcessNode(const ParseTreeNode<Token>* node, const int& type, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector) {
		if (node->Item()->getType() == "ID") {
			IDToken* idtok = NULL;
			
			IDToken* skey = static_cast<IDToken*>(node->Item());
			if (symbol_tbl.get(skey->getValue(), idtok) < 0)
				return NULL;

			skey->set(*idtok);
			if (TypeChecker::matchType(node, type) < 0)
				return NULL;

			return node;

		} else if (node->Item()->getType() == "ARRAY_REF") {
			return ArrayRef(node, type, symbol_tbl, quad_vector);
			
		} else {

			return node;
		}
	}

	const ParseTreeNode<Token>* 
	TreeHelper::ProcessNode2(const ParseTreeNode<Token>* node, const int& type, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector) {
		if (node->Item()->getType() == "ID"
				|| node->Item()->getType() == "ARRAY_REF") {

			return ProcessNode(node, type, symbol_tbl, quad_vector);
			
		} else {
			ParseTreeNode<Token>* n = TmpVar(symbol_tbl);
			n->AppendChild(node);

			Token* a = GetToken(n, symbol_tbl);
			Token* b = GetToken(node, symbol_tbl);
			if (a == NULL || b == NULL)
				return NULL;

			Quadruple quad(ASSIGNOP, a, b, NULL);
			quad_vector->push_back(quad);

			return n;
		}
	}

	ParseTreeNode<Token>* 
	TreeHelper::ArrayRef(const ParseTreeNode<Token>* node, const int& type, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector) {
		if (node->Item()->getType() == "ARRAY_REF") {
			ParseTreeNode<Token>* n = TmpVar(symbol_tbl);
			n->AppendChild(node);

			if (TypeChecker::matchType(node->Child(0), type | Token::T_ARRAY) < 0)
				return NULL;

			const ParseTreeNode<Token>* index = ProcessNode(node->Child(1), type, symbol_tbl, quad_vector);

			Token* a = GetToken(n, symbol_tbl);
			Token* b = GetToken(node->Child(0), symbol_tbl);
			Token* c = GetToken(index, symbol_tbl);
			if (a == NULL || b == NULL || c == NULL)
				return NULL;

			Quadruple quad(RARRAYOP, a, b, c);
			quad_vector->push_back(quad);

			return n;
			
		} else {
			return (ParseTreeNode<Token>*)node;
		}
	}
	
	ParseTreeNode<Token>* 
	TreeHelper::ArrayDef(const ParseTreeNode<Token>* node, SymbolTable& symbol_tbl, QuadrupleVector* quad_vector) {
		std::list<const ParseTreeNode<Token>*> lst = RetrieveList(node, "COMMA");
		ParseTreeNode<Token>* tmp = TreeHelper::TmpVar(symbol_tbl);
		tmp->AppendChild(node);

		std::list<const ParseTreeNode<Token>*>::const_iterator c_iter = lst.begin();
		for (int i = 0; c_iter != lst.end(); c_iter++, i++) {
			const ParseTreeNode<Token>* value = ProcessNode(*c_iter, Token::T_INT | Token::T_STR, symbol_tbl, quad_vector);
			if (value == NULL)
				return NULL;

			Token* a = GetToken(tmp, symbol_tbl);
			Token* b = new Int(i);
			Token* c = GetToken(value, symbol_tbl);
			if (a == NULL || b == NULL || c == NULL)
				return NULL;
		
			Quadruple quad(LARRAYOP, a, b, c);
			quad_vector->push_back(quad);
		}

		return tmp;
	}

	ParseTreeNode<Token>* 
	TreeHelper::TmpVar(SymbolTable& symbol_tbl) {
		string id = symbol_tbl.temp();
		Token* tmp = new IDToken(id);
		symbol_tbl.put(id, *((IDToken*)tmp));

		ParseTreeNode<Token>* node = new ParseTreeNode<Token>(tmp);

		return node;
	}

	// a = b
	int 
	TreeHelper::VarAssign(
			const ParseTreeNode<Token>* var, const ParseTreeNode<Token>* value,
			SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		const ParseTreeNode<Token>* proc_value = ProcessNode(value, Token::T_INT | Token::T_STR | Token::T_ARRAY, symbol_tbl, quad_vector);
		if (proc_value == NULL)
			return -1;

		Token::TYPE valueType = proc_value->Item()->getValueType();
		IDToken* idtok = NULL;
		if (symbol_tbl.get(((IDToken*)(var->Item()))->getValue(), idtok) >= 0) {
			Token::TYPE type = idtok->getValueType();
			if (TypeChecker::matchType(type, valueType, Token::T_INT | Token::T_STR | Token::T_ARRAY) < 0)
				return -1;

		} else {
			symbol_tbl.put(((IDToken*)(var->Item()))->getValue(), *((IDToken*)(var->Item())));
			symbol_tbl.get(((IDToken*)(var->Item()))->getValue(), idtok);
		}

		Token* a = idtok;
		Token* b = GetToken(proc_value, symbol_tbl);
		if (a == NULL || b == NULL)
			return -1;
		
		Quadruple quad(ASSIGNOP, a, b, NULL);
		quad_vector->push_back(quad);

		return 0;
	}

	// a[b] = c
	int
	TreeHelper::LArrayAssign(
			const ParseTreeNode<Token>* array, const ParseTreeNode<Token>* value,
			SymbolTable& symbol_tbl, QuadrupleVector* quad_vector)
	{
		const ParseTreeNode<Token>* proc_value = ProcessNode(value, Token::T_INT | Token::T_STR | Token::T_ARRAY, symbol_tbl, quad_vector);
		if (proc_value == NULL)
			return -1;

		Token::TYPE valueType = proc_value->Item()->getValueType();
		if (valueType & Token::T_ARRAY != 0)
			return -1;

		IDToken* idtok = NULL;
		if (symbol_tbl.get(((IDToken*)(array->Child(0)->Item()))->getValue(), idtok) >= 0) {
			Token::TYPE type = idtok->getValueType();
			if (TypeChecker::matchType(type, valueType, Token::T_INT | Token::T_STR | Token::T_ARRAY) < 0)
				return -1;

		} else {
			symbol_tbl.put(((IDToken*)(array->Child(0)->Item()))->getValue(), *((IDToken*)(array->Child(0)->Item())));
			symbol_tbl.get(((IDToken*)(array->Child(0)->Item()))->getValue(), idtok);
		}

		const ParseTreeNode<Token>* index = ProcessNode(array->Child(1), Token::T_INT, symbol_tbl, quad_vector);
		if (index == NULL)
			return -1;
			
		Token* a = idtok;
		Token* b = GetToken(index, symbol_tbl);
		Token* c = GetToken(proc_value, symbol_tbl);
		if (a == NULL || b == NULL || c == NULL)
			return -1;
		
		Quadruple quad(LARRAYOP, a, b, c);
		quad_vector->push_back(quad);

		return 0;
	}
}
