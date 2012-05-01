
#ifndef _SYMBOL_TABLE_HPP_
#define _SYMBOL_TABLE_HPP_
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include "token.hpp"

namespace Bubble
{
    /*
     * 각각의 환경 클래스
     */
    class Env {
    public:
        typedef std::map<std::string, IDToken*> SymbolMap;

		Env();
        void put(const string& id, const IDToken& tok);
        void put(const string& id, IDToken* tok);
        void putParam(const string& id, IDToken* tok);
        void putParamFirst(const string& id, IDToken* tok);
        void setParamFirst(const string& id);

        int get(const string& id, IDToken& tok) const;
        int get(const string& id, IDToken*& tok) const;
        bool exist(const string& id) const;
        unsigned int count() const;
        std::string ToCCode() const;

    protected:
        SymbolMap items;
		int lOffset;
		int pOffset;
    };

    /*
     * 환경들이 집합해 있는 심볼 테이블
     * 환경들의 스택과 같다.
     */
    struct SymbolTable {
        typedef std::vector<Env> SymbolTableEntry;
        typedef std::vector<IDToken*> Owned;
        SymbolTableEntry envs;
        Owned owned;
        int tmp_count;

    public:
        SymbolTable();
        ~SymbolTable();
        // 새로운 환경 얹기
        void push() { envs.push_back(Env()); }
        // 특정 환경 얹기
        void push(Env& e) { envs.push_back(e); }
        // 환경 제거
        void pop() { envs.pop_back(); }
        // 맨 윗 환경 반환
        Env& top();
        // 환경 개수 반환
        unsigned int count() const;

        // 환경 존재 여부
        bool exist(const string& id) const;
        // 위쪽부터 찾아서 얻기
        int get(const string& id, IDToken& tok) const;
        int get(const string& id, IDToken*& tok) const;
        // 맨 위 쪽에 새로 만들어 넣기(맨 위에 이미 있으면 그것을 업데이트)
        void put(const string& id, const IDToken& tok);
        void putParam(const string& id, const IDToken& tok);
        void putParamFirst(const string& id, const IDToken& tok);
        void setParamFirst(const string& id);

        int update(const string& id, const IDToken& tok);
        // 새로운 임시 변수 이름을 반환.
        std::string temp();

        // 맨 윗 환경의 선언부를 C 코드로 리턴한다.
        std::string ToCCodeOfTop() { return top().ToCCode(); }
    };

}
#endif
