
#include <sstream>
#include <iostream>
#include <stack>
#include <algorithm>
#include "function_table.hpp"
#include "symbolTable.hpp"
#include "quadruple.hpp"
extern Bubble::SymbolTable symbol_tbl;

namespace Bubble
{
	FunctionEntry::FunctionEntry(const std::string& str, const FunctionEntry& other)
			: name(str)
			, return_type(other.return_type)
			, c_str_section(label()) 
			, type_checked(other.type_checked) {

		param_list = VarVectorClone(other.param_list);
		c_str_list = StrMapClone(other.c_str_list);
		var_list = VarVectorClone(other.var_list);
		body = QuadrupleVectorClone(other.body);
	}
	
	FunctionEntry::FunctionEntry(const FunctionEntry& other)
			: name(other.name)
			, return_type(other.return_type)
			, c_str_section(label())
			, type_checked(other.type_checked) {

		param_list = VarVectorClone(other.param_list);
		c_str_list = StrMapClone(other.c_str_list);
		var_list = VarVectorClone(other.var_list);
		body = QuadrupleVectorClone(other.body);
	}

	void
	FunctionEntry::AddParameter(IDToken* tok) {
		param_list.push_back(tok); 
	}

	int	
	FunctionEntry::SetParamType(const unsigned int& index, const Token::TYPE& type) {
		if (index >= param_list.size())
			return -1;

		param_list[index]->setValueType(type);
		return 0;
	}
	
	void
	FunctionEntry::construct_list() {
		QuadrupleVector::const_iterator q_itr = body.begin();
		for (; q_itr != body.end(); q_itr++) {
			for (int i = 0; i < 3; i++) {
				if (q_itr->operands[i] == NULL)
					continue;

				IDToken* idtok = dynamic_cast<IDToken*>(q_itr->operands[i]);
				if (idtok != NULL) {
					if (idtok->getValueType() == Token::T_FUNC)
						continue;

					std::vector<IDToken*>::const_iterator v_itr = var_list.begin();
					bool isFound = false;
					for (; v_itr != var_list.end(); v_itr++) {
						if ((*v_itr)->getValue() == idtok->getValue()) {
							isFound = true;
							break;
						}
					}

					if (isFound == true)
						continue;

					std::vector<IDToken*>::const_iterator p_itr = param_list.begin();
					bool isParam = false;
					for (; p_itr != param_list.end(); p_itr++) {
						if ((*p_itr)->getValue() == idtok->getValue()) {
							isParam = true;
							break;
						}
					}

					if (isParam == false) {
						var_list.push_back(idtok);
					}
				}

				String* strtok = dynamic_cast<String*>(q_itr->operands[i]);
				if (strtok != NULL) {
					strtok->setAddr(4 * c_str_list.size());
					strtok->setGlobalSection(c_str_section);
					c_str_list[strtok->getLabel()] = strtok;
				}
			}
		}
	}

    // 함수의 C 언어 프로토타입을 출력한다.
    // 마지막에 세미콜론은 붙어 있지 않다.
    std::string FunctionEntry::ToCCode() const
    {
        std::ostringstream oss;
        oss << return_type << " " << name << "(";
        if (param_list.size() > 0) {
            oss << param_list[0]->getValueTypeStr() << " " << param_list[0]->toString();
            for (unsigned int i = 1; i < param_list.size(); i++) {
                oss << ", " << param_list[i]->getValueTypeStr() << " " << param_list[i]->toString();
            }
        }
        oss << ")";
        return oss.str();
    }

    std::string FunctionEntry::ToCCodeAll() const
    {
        std::ostringstream oss;
        oss << ToCCode() << std::endl;
        oss << "{" << std::endl;
        oss << QuadrupleVectorToCDeclaration(body, param_list) << std::endl;
        oss << QuadrupleVectorToCCode(body);
        oss << "}" << std::endl;
        return oss.str();
    }

	std::string 
	FunctionEntry::C_StrDataSection() const {
		if (c_str_list.size() == 0)
			return "";

		std::ostringstream oss;
		oss << "\t.section\t\t.rodata\n";

		std::map<std::string, String*>::const_iterator s_itr = c_str_list.begin();
		for (; s_itr != c_str_list.end(); s_itr++) {
			oss << "\t.align\t2\n";
			oss << "." << s_itr->second->getLabel() << ":\n";
			oss << "\t.ascii\t\"" << s_itr->second->getOrigValue() << "\\000\"\n";
		}

		return oss.str();
	}

	std::string 
	FunctionEntry::C_StrSection() const {
		if (c_str_list.size() == 0)
			return "";

		std::ostringstream oss;
		oss << "." << c_str_section << ":\n";
		
		std::map<std::string, String*>::const_iterator s_itr = c_str_list.begin();
		for (; s_itr != c_str_list.end(); s_itr++) {
			oss << "\t.word\t." << s_itr->second->getLabel() << "\n";
		}

		return oss.str();
	}

    std::string FunctionEntry::ToASMCodeAll() const
    {
        std::ostringstream oss;
		oss << C_StrDataSection();
        oss << "\t.text\n\t.align\t2\n\t.global\t" << name << "\n\t.type\t" << name << ", %function\n" << name << ":\n";
        // TODO: oss에 arg나 프레임 크기 등의 정보를 주석처리하여 쓰면 좋을 듯
        oss << "\tmov\tip, sp\n\tstmfd\tsp!, {fp, ip, lr, pc}\n\tsub\tfp, ip, #4\n\tsub\tsp, sp, #" << sp_size << "\n";
        oss << "\t@ SETTING ARGUMENTS\n";
        for (size_t i = 0; i < std::min(param_list.size(), static_cast<size_t>(4)); i++) {
            oss << "\tstr\tr" << i << ", [fp, #" << param_list[i]->toAssemStr() << "]\n";
        }
        oss << "\t@ START BODY\n\n";
        oss << QuadrupleVectorToASMCode(body);
        oss << "\t@ END BODY\n";
        oss << "\tsub sp, fp, #12\n";
        oss << "\tldmfd sp, {fp, sp, pc}\n";
        oss << C_StrSection();
        oss << "\t.size\t" << name << ", .-" << name << "\n";
        return oss.str();
    }

    std::vector<IDToken*> VarVectorClone(const std::vector<IDToken*>& p) {
        std::vector<IDToken*> param;
        std::vector<IDToken*>::const_iterator c_iter = p.begin();
        for (; c_iter != p.end(); c_iter++) {
            IDToken* copy = new IDToken(**c_iter);
            param.push_back(copy);
            symbol_tbl.owned.push_back(*c_iter);
        }

        return param;
    }

    std::map<std::string, String*> StrMapClone(const std::map<std::string, String*>& p) {
        std::map<std::string, String*> param;
        std::map<std::string, String*>::const_iterator c_iter = p.begin();
        for (; c_iter != p.end(); c_iter++) {
            String* copy = new String(*c_iter->second);
            param[c_iter->first] = copy;
        }

        return param;
    }

	void FunctionTable::Put(const std::string& s, const FunctionEntry& e) {
		items[s] = e;
	}

    int FunctionTable::Get(const std::string& s, FunctionEntry& e) const
    {
        FunctionMap::const_iterator found = items.find(s);
        if (found != items.end()) {
            e = found->second;
            return 0;
        }
        return -1;
    }
    
	int
	FunctionTable::GenReturn() {
            FunctionMap::iterator f_iter = items.begin();
            for (; f_iter != items.end(); f_iter++) {
                QuadrupleVector* body = &(f_iter->second.body);
                int assign_index = lastAssignIndex(*body);
                Quadruple quad(RETURNOP, (*body)[assign_index].operands[0], NULL, NULL);
                body->push_back(quad);
            }

            return 0;
	}
	
	int
	FunctionTable::GenType() {
		std::stack<std::string> callstack;

		FunctionMap::const_iterator f_iter = items.find("main");
		if (f_iter == items.end())
			return -1;

		QuadrupleVector* main = items["main"].getBody();
		QuadrupleVectorInferenceType(*main);
		QuadrupleVectorGuessType(*main);
		items["main"].type_checked = true;

		callstack.push("main");

		while (callstack.size() > 0) {
			std::string f_id = callstack.top();
			callstack.pop();

			QuadrupleVector* body = items[f_id].getBody();

			QuadrupleVector::const_iterator q_iter = body->begin();
			for (; q_iter != body->end(); q_iter++) {
				if (q_iter->opr == FUNCTIONOP_ANY) {
					IDToken* func_id_tok = (IDToken*)(q_iter->operands[1]);
					std::string func_id = func_id_tok->getValue();
					FunctionEntry* func = &items[func_id];
					int arg_cnt = ((Int*)(q_iter->operands[2]))->getValue();
					std::string func_name = func->name;

					for (int i = 0; i < arg_cnt; i++) {
						Quadruple param = *(q_iter - (arg_cnt - i));
						Token::TYPE type = param.operands[0]->getValueType();
						func->SetParamType(i, type);
						func_name += param.operands[0]->getValueTypeStr();
					}

					if (items.find(func_name) == items.end()) {
						QuadrupleVector *f_body = func->getBody();
						QuadrupleVectorInferenceType(*f_body);
						QuadrupleVectorGuessType(*f_body);

						FunctionEntry fent(func_name, *func);
						items[func_name] = fent;
						items[func_name].type_checked = true;
						callstack.push(func_name);
						IDToken func_tok(func_name, Token::T_FUNC);
						symbol_tbl.put(func_name, func_tok);
					}

					func_id_tok->setValue(func_name);
				}
			}

			std::cerr << std::endl << f_id << std::endl;
			std::cerr << QuadrupleVectorToString(*body) << std::endl;
		}

		return 0;
	}

	int 
	FunctionTable::GenList() {
		FunctionMap::iterator itr = items.begin();
		for (; itr != items.end(); itr++) {
			itr->second.construct_list();
			itr->second.sp_size = itr->second.var_list.size() * 4;
			int arg_size = 4;
			if (itr->second.param_list.size() < 4)
				arg_size = itr->second.param_list.size();

			itr->second.sp_size += 4 * arg_size;
		}

		return 0;
	}
	
    // forward declaration을 위한 테이블 내의 모든 함수 프로토타입을
    // 출력하는 함수다. 마지막에 각각 세미콜론이 불게 된다.
    std::string FunctionTable::ToCCode() const
    {
        std::ostringstream oss;
        for (FunctionMap::const_iterator itr = items.begin(); itr != items.end(); itr++) {
            if (itr->second.type_checked && itr->second.name != "main")
                oss << itr->second.ToCCode() << ";" << std::endl;
        }
        return oss.str();
    }

    std::string FunctionTable::ToCCodeAll() const
    {
        std::ostringstream oss;
        for (FunctionMap::const_iterator itr = items.begin(); itr != items.end(); itr++) {
            if (itr->second.type_checked)
            	oss << itr->second.ToCCodeAll() << std::endl;
        }
        return oss.str();
    }

    std::string FunctionTable::ToASMCodeAll() const
    {
        std::ostringstream oss;
        for (FunctionMap::const_iterator itr = items.begin(); itr != items.end(); itr++) {
            if (itr->second.type_checked)
            	oss << itr->second.ToASMCodeAll() << std::endl;
        }
        return oss.str();
    }

}
