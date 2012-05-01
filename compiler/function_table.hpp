
#ifndef _FUNCTION_TABLE_HPP_
#define _FUNCTION_TABLE_HPP_

#include <string>
#include <map>
#include <vector>
#include "token.hpp"
#include "quadruple.hpp"

namespace Bubble
{
    struct FunctionEntry
    {
        std::string name;
        std::string return_type;
        std::vector<IDToken*> param_list;
        std::vector<IDToken*> var_list;
        std::map<std::string, String*> c_str_list;

		std::string c_str_section;

		int sp_size;
        QuadrupleVector body;
        bool type_checked;
		
        FunctionEntry(): name(""), return_type("__int_t"), c_str_section(label()), type_checked(false){}
        ~FunctionEntry() { std::cerr << "Destroying function entry of " << name << "!\n"; }
        FunctionEntry(const std::string& str): name(str), return_type("__int_t"), c_str_section(label()) {}
        FunctionEntry(const std::string& str, const std::string& rt): name(str), return_type(rt), c_str_section(label()) {}
        FunctionEntry(const std::string& str, const FunctionEntry& other);
        FunctionEntry(const FunctionEntry& other);
        void AddParameter(IDToken* tok);
        int SetParamType(const unsigned int& index, const Token::TYPE& type);
        QuadrupleVector* getBody() { return &body; }
        std::string ToCCode() const;
        std::string ToCCodeAll() const;
		std::string C_StrSection() const;
		std::string C_StrDataSection() const;
        std::string ToASMCodeAll() const;

        void construct_list();
    };

	std::vector<IDToken*> VarVectorClone(const std::vector<IDToken*>& other);
	std::map<std::string, String*> StrMapClone(const std::map<std::string, String*>& other);

    typedef std::map<std::string, FunctionEntry> FunctionMap;
    struct FunctionTable
    {
        FunctionMap items;
        ~FunctionTable() { std::cerr << "Destroying FunctionTable!\n"; }
        void Put(const std::string& s, const FunctionEntry& e);
        int Get(const std::string& s, FunctionEntry& e) const;
		
        int GenType();
        int GenReturn();
        int GenList();
		
        std::string ToCCode() const;
        std::string ToCCodeAll() const;
        std::string ToASMCodeAll() const;
    };
}

#endif
