
/**
 * 토큰 클래스 구현 부분
 */
#include <string>
#include <sstream>
#include <iostream>
#include "token.hpp"
#include "quadruple.hpp"

using std::string;
using std::ostringstream;
using std::cout;

namespace Bubble {
	Token::Token(const Token& other) 
		: type(other.type) 
		, valueType(other.valueType)
		, offset(other.offset)
		, cLabel(other.cLabel) {
		
	}
	
    Token::Token(const string& type)
        : type(type)
        , valueType(T_UNKNOWN) {
    }

    Token::Token(const string& type, TYPE valueType)
        : type(type) 
        , valueType(valueType){
    }
	
    Token::~Token() {

    }

    void
    Token::setValueType(TYPE type) {
        valueType = type;
    }

    Token::TYPE
    Token::getValueType() const {
        return valueType;
    }

    string
    Token::getValueTypeStr() const {
        switch (getValueType()) {
        case T_INT:
            return "__int_t";
        case T_DOUBLE:
            return "__double_t";
        case T_STR:
            return "__str_t";
        case T_INT_ARRAY:
            return "__int_array_t";
        case T_DOUBLE_ARRAY:
            return "__double_array_t";
        case T_STR_ARRAY:
            return "__str_array_t";
        default:
            break;
            // for eliminating warnings.
        }
        return "";
    }

    string
    Token::getType() const {
        return type;
    }
	
    void
    Token::setAddr(const int _offset) {
        offset = _offset;
    }

    int
    Token::getAddr() const {
        return offset;
    }

	int
	Token::getSize() const {
		return 0;
	}

	string 
	Token::toAssemStr() const {
		return "THIS IS NOT SUPPOSE TO BE CALLED";
	}

	bool
	Token::isVar() const {
		return false;
	}

    string 
    Token::toString() const {
        return type;
    }

    Token*
    Token::clone() {
        Token* token = new Token(*this);
        return token;
    }

	IDToken::IDToken(const IDToken& other) 
		: Token(other)
		, name(other.name) {
	
	}
	
    IDToken::IDToken(const string& name) 
        : Token("ID")
        , name(name) {

    }

    IDToken::IDToken(const string& name, TYPE type) 
        : Token("ID", type)
        , name(name) {

    }
	
	void
	IDToken::set(const IDToken& other) {
		type = other.type;
		valueType = other.valueType;	
		name = other.name;
		offset = other.offset;
	}

    string
    IDToken::getValue() const {
        return name;
    }

	void
	IDToken::setValue(const string& val) {
		name = val;
	}

	string 
	IDToken::toAssemStr() const {
		ostringstream oss;
		switch (getValueType()) {
		case T_FUNC:
			oss << name;
			break;
		default:
			oss << getAddr();
		}

		return oss.str();
	}

	int
	IDToken::getSize() const {
        return 4;
	}

    string
    IDToken::toString() const {
        return name;
    }

    Token*
    IDToken::clone() {
        IDToken* token = new IDToken(*this);

        return token;
    }

	Int::Int(const Int& other) 
		: Token(other)
		, value(other.value) {

	}
	
    Int::Int(const int& val)
        : Token("INT_VAL", T_INT)
        , value(val) {

		cLabel = label();
    }

    int
    Int::getValue() const {
        return value;
    }

	int
	Int::getSize() const {
        return 4;
	}

	string 
	Int::toAssemStr() const {
		ostringstream oss;
		oss << getValue();

		return oss.str();
	}

    string
    Int::toString() const {
        ostringstream oss;
        oss << value;

        return oss.str();
    }

    Token*
    Int::clone() {
        Token* token = new Int(*this);
        return token;
    }
	
	Double::Double(const Double& other) 
		: Token(other)
		, value(other.value) {

	}
	
    Double::Double(const double& val)
        : Token("DOUBLE_VAL", T_DOUBLE)
        , value(val) {

		cLabel = label();
    }

    double
    Double::getValue() const {
        return value;
    }

	int
	Double::getSize() const {
        return 8;
	}

	string 
	Double::toAssemStr() const {
		ostringstream oss;
		oss << getValue();

		return oss.str();
	}

    string
    Double::toString() const {
        ostringstream oss;
        oss << value;

        return oss.str();
    }
	
    Token*
    Double::clone() {
        Token* token = new Double(*this);
        return token;
    }

	String::String(const String& other) 
		: Token(other)
		, value(other.value) 
		, global_section(other.global_section)  {

	}
	
    String::String(const string& val)
        : Token("STRING_VAL", T_STR)
        , value(val) {

		cLabel = label();
    }

    string
    String::getValue() const {
        return "\"" + value + "\"";
    }

	int
	String::getSize() const {
        return value.length() + 1;
	}

	string
	String::getOrigValue() const {
		return value;
	}

	string 
	String::toAssemStr() const {
		ostringstream oss;
		oss << "." << global_section;
		if (offset != 0)
			oss << "+" << offset;

		return oss.str();
	}

    string
    String::toString() const {
        return "\"" + value + "\"";
    }

    Token*
    String::clone() {
        Token* token = new String(*this);
        return token;
    }

	Label::Label(const Label& other) 
		: Token(other)
		, value(other.value) {

	}
	
    Label::Label(const string& val)
        : Token("LABEL", T_LABEL)
        , value(val) {

    }

    string
    Label::getValue() const {
        return value;
    }

	int
	Label::getSize() const {
        return value.length() + 1;
	}

	string 
	Label::toAssemStr() const {
		ostringstream oss;
		oss << getValue();

		return oss.str();
	}

    string
    Label::toString() const {
        return value;
    }

    Token*
    Label::clone() {
        Token* token = new Label(*this);
        return token;
    }

    void
    print_token(const Token& tok) {
        cout << tok.toString();
    }

}
