
#include <iostream>
#include <set>
#include "symbolTable.hpp"

namespace Bubble
{
	Env::Env()
		: lOffset(-16), pOffset(0) 
	{

	} 
    /*
     * 환경 내에 tok을 복사해 넣는다. 직접적으로 쓸 일이 없다.
     */
    void Env::put(const string& id, const IDToken& tok)
    {
        *items[id] = tok;
		items[id]->setAddr(lOffset);
		lOffset -= items[id]->getSize();
    }

    void Env::put(const string& id, IDToken* tok)
    {
        items[id] = tok;
		items[id]->setAddr(lOffset);
		lOffset -= items[id]->getSize();
    }

    void Env::putParamFirst(const string& id, IDToken* tok)
    {
		items[id] = tok;
		items[id]->setAddr(pOffset);
    }

    void Env::setParamFirst(const string& id)
    {
		items[id]->setAddr(lOffset);
		lOffset -= items[id]->getSize();
    }

    void Env::putParam(const string& id, IDToken* tok)
    {
        items[id] = tok;
		items[id]->setAddr(pOffset);
		pOffset += items[id]->getSize();
    }

    /*
     * 환경 내에 IDToken을 가져와서 tok에 세팅한다. 직접적으로 쓸 일이 없다.
     * 부수효과: tok
     * 성공하면 0, 실패하면 -1을 반환한다.
     */
    int Env::get(const string& id, IDToken& tok) const
    {
        SymbolMap::const_iterator found = items.find(id);
        if (found != items.end()) {
            tok = *(found->second);
            return 0;
        }
        return -1;
    }

    int Env::get(const string& id, IDToken*& tok) const
    {
        SymbolMap::const_iterator found = items.find(id);
        if (found != items.end()) {
            tok = found->second;
            return 0;
        }
        return -1;
    }

    /*
     * 환경 내에 심볼이 있는지 검사한다. 직접적으로 쓸 일이 없다.
     */
    bool Env::exist(const string& id) const
    {
        return items.find(id) != items.end();
    }

    unsigned int
    Env::count() const {
        return items.size();
    }
	

    /*
     * 환경 내에 있는 심볼들을 모두 C 코드의 선언부로 바꾼다.
     */
    std::string Env::ToCCode() const
    {
        std::ostringstream oss;
        for (SymbolMap::const_iterator itr=items.begin(); itr != items.end(); itr++) {
            oss << itr->second->getValueTypeStr() << " " << itr->first << ";" << std::endl;
        }
        return oss.str();
    }

	SymbolTable::SymbolTable() 
			: tmp_count(0) {
		push();
	}

    SymbolTable::~SymbolTable()
    {
        typedef std::set<IDToken*> SSet;
        SSet s;
        //std::cout << "Destroying SymbolTable!\n";
        for (unsigned int i = 0; i < owned.size(); i++) {
            s.insert(owned[i]);
        }
        for (SSet::iterator itr = s.begin(); itr != s.end(); itr++) {
            //std::cout << "Destroying " << (*itr)->toString() << std::endl;
            delete (*itr);
        }
        //std::cout << "Destroying SymbolTable! Finished.\n";
    }
	
    Env&
    SymbolTable::top() {
        return envs.back(); 
    }

    unsigned int
    SymbolTable::count() const {
        return envs.size();
    }
	
    /*
     * 심볼 테이블 내에 특정 심볼이 있는지 검사한다.
     */
    bool SymbolTable::exist(const string& id) const
    {
        for (SymbolTableEntry::const_reverse_iterator itr=envs.rbegin(); itr != envs.rend(); itr++) {
            if (itr->exist(id)) return true;
        }
        return false;
    }

    /*
     * 심볼 테이블에서 특정 심볼을 가져온다.
     * 맨 윗 환경부터 탐색하여 제일 먼저 나온 IDToken을 tok에 세팅한다.
     * 부수효과: tok
     * 성공하면 0, 실패하면 -1을 반환한다.
     */
    int SymbolTable::get(const string& id, IDToken& tok) const
    {
        for (SymbolTableEntry::const_reverse_iterator itr=envs.rbegin(); itr != envs.rend(); itr++) {
            if (itr->exist(id)) {
                itr->get(id, tok);
                //std::cout << "SymbolTable::get(" << tok.getType() << ", " << id << ")" << std::endl;
                return 0;
            }
        }
        return -1;
    }

    int SymbolTable::get(const string& id, IDToken*& tok) const
    {
        for (SymbolTableEntry::const_reverse_iterator itr=envs.rbegin(); itr != envs.rend(); itr++) {
            if (itr->exist(id)) {
                itr->get(id, tok);
                //std::cout << "SymbolTable::get(" << tok->getType() << ", " << id << ")" << std::endl;
                return 0;
            }
        }
        return -1;
    }

    /*
     * 맨 윗 환경에 tok을 복사해 넣는다.
     * 같은 심볼이 이미 있으면 덮어쓴다.
     */
    void SymbolTable::put(const string& id, const IDToken& tok)
    {
		if (exist(id))
			update(id, tok);
		else {
        	IDToken* copied  = new IDToken(tok);
            owned.push_back(copied);
           	envs.back().put(id, copied);
		}

        //std::cout << "SymbolTable::put(" << tok.getType() << ", " << id << ")" << std::endl;
    }
 
    void SymbolTable::putParam(const string& id, const IDToken& tok)
    {
		if (exist(id))
			update(id, tok);
		else {
        	IDToken* copied  = new IDToken(tok);
            owned.push_back(copied);
           	envs.back().putParam(id, copied);
		}

        //std::cout << "SymbolTable::put(" << tok.getType() << ", " << id << ")" << std::endl;
    }

    void SymbolTable::putParamFirst(const string& id, const IDToken& tok)
    {
		if (exist(id))
			update(id, tok);
		else {
        	IDToken* copied  = new IDToken(tok);
            owned.push_back(copied);
           	envs.back().putParamFirst(id, copied);
		}

        //std::cout << "SymbolTable::put(" << tok.getType() << ", " << id << ")" << std::endl;
    }

    void SymbolTable::setParamFirst(const string& id) 
    {
        for (SymbolTableEntry::reverse_iterator itr=envs.rbegin(); itr != envs.rend(); itr++) {
            if (itr->exist(id)) {
				itr->setParamFirst(id);
				break;
            }
        }
    }

    int SymbolTable::update(const string& id, const IDToken& tok) 
    {
        for (SymbolTableEntry::reverse_iterator itr=envs.rbegin(); itr != envs.rend(); itr++) {
            if (itr->exist(id)) {
				IDToken *target;
				itr->get(id, target);
				target->setValueType(tok.getValueType());
				target->setValue(tok.getValue());
				target->setAddr(tok.getAddr());
                return 0;
            }
        }
        return -1;
    }

    /*
     * 새로운 환경 변수를 하나 반환한다.
     * 이름은 _temp_var_n 형식이고 n은 0부터 증가한다.
     */
    std::string SymbolTable::temp()
    {
        std::ostringstream ostrm;
        ostrm << "_temp_var_" << tmp_count++;
        return ostrm.str();
    }

}
