
/**
 * 토큰 클래스 선언 부분
 */
#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_
#include <string>
namespace Bubble {

    using std::string;

    /**
     * 토큰을 담아두는 클래스
     */
    class Token {
    public:
        enum TYPE {
            T_ARRAY           = 1,
            T_UNKNOWN         = 2,
            T_UNKNOWN_ARRAY   = 3,
            T_LABEL           = 4,
            T_DOUBLE          = 8,
            T_DOUBLE_ARRAY    = 9,
            T_INT             = 16,
            T_INT_ARRAY       = 17,
            T_STR             = 64,
            T_STR_ARRAY       = 65,
            T_FUNC            = 256
        };

        Token() {}
        Token(const Token& other);
        Token(const string& type);
        Token(const string& type, TYPE valueType);
        virtual ~Token();

        void setValueType(TYPE type);
        TYPE getValueType() const;
        string getValueTypeStr() const;

        string getType() const;

        void setAddr(const int offset);
        int getAddr() const;
		void setLabel(const string& label) { cLabel = label; }
		string getLabel() const { return cLabel; }
		
		virtual string toAssemStr() const;
		virtual bool isVar() const;
		virtual int getSize() const;
        virtual string toString() const;
        virtual Token* clone();
	
    protected:
        string type;
        TYPE valueType;
        int offset;
		string cLabel;
    };

    class IDToken : public Token {
    public:
        IDToken() {}
        IDToken(const IDToken& other);
        IDToken(const string& name);
        IDToken(const string& name, TYPE valueType);

		void set(const IDToken& other);
        string getValue() const;
        void setValue(const string& val);

		virtual string toAssemStr() const;
		virtual bool isVar() const { return true; }
		virtual int getSize() const;
        virtual string toString() const;
        virtual Token* clone();

        bool operator==(const IDToken& tok) const { return name == tok.toString(); }

    protected:
        string name;
    };

    class Int : public Token {
    public:
        Int() {}
        Int(const Int& other);
        Int(const int& val);

        int getValue() const;

		virtual string toAssemStr() const;
		virtual bool isVar() const { return false; }
		virtual int getSize() const;
        virtual string toString() const;
        virtual Token* clone();
	
    protected:
        int value;
    };

    class Double : public Token {
    public:
        Double() {}
        Double(const Double& other);
        Double(const double& val);

        double getValue() const;

		virtual string toAssemStr() const;
		virtual bool isVar() const { return false; }
		virtual int getSize() const;
        virtual string toString() const;
        virtual Token* clone();

    protected:
        double value;
    };
    
    class String : public Token {
    public:
        String() {}
        String(const String& other);
        String(const string& val);

        string getValue() const;
        string getOrigValue() const;
		void setGlobalSection(const string& gs) { global_section = gs; }

		virtual string toAssemStr() const;
		virtual bool isVar() const { return false; }
		virtual int getSize() const;
        virtual string toString() const;
        virtual Token* clone();

    protected:
        string value;
		string global_section;
    };

    class Label : public Token {
    public:
        Label() {}
        Label(const Label& other);
        Label(const string& val);

        string getValue() const;

		virtual string toAssemStr() const;
		virtual bool isVar() const { return true; }
		virtual int getSize() const;
        virtual string toString() const;
        virtual Token* clone();

    protected:
        string value;
    };

    void print_token(const Token& tok);
}
#endif

