
#include "quadruple.hpp"
#include "symbolTable.hpp"
extern Bubble::SymbolTable symbol_tbl;

namespace Bubble {
    Quadruple::Quadruple()
        : opr(NOP)
    {
        operands[0] = 0;
        operands[1] = 0;
        operands[2] = 0;
    }

    Quadruple::Quadruple(Operator o, pToken o1, pToken o2, pToken o3)
        : opr(o)
    {
        operands[0] = o1;
        operands[1] = o2;
        operands[2] = o3;
    }

    Quadruple Quadruple::Clone() const
    {
        Quadruple q(*this);
        for (int i = 0; i < 3; i++) {
            IDToken* pid_tok = dynamic_cast<IDToken*>(operands[i]);
            if (pid_tok != 0) {
                q.operands[i] = new IDToken(*pid_tok);
                symbol_tbl.owned.push_back(static_cast<IDToken*>(q.operands[i]));
            }
        }
        return q;
    }

    std::string Quadruple::OperatorToStr() const
    {
#include "operator_to_str.inc"
    }

    void Quadruple::InferenceType()
    {
#include "inference_type.inc"
    }

    // 타입 정보가 들어간 연산자로 바꾼다.
    void Quadruple::GuessType()
    {
#include "guess_type.inc"
    }

    std::string Quadruple::ToCCode() const
    {
#include "to_c_code.inc"
    }

    std::string Quadruple::ToASMCode() const
    {
#include "to_asm_code.inc"
    }

    std::string 
    Quadruple::toString() const {
        std::ostringstream oss;
        oss << OperatorToStr() << ": ";
        oss << operands[0]->toString();
        if (operands[1] != NULL)
            oss << ", " << operands[1]->toString();
        if (operands[2] != NULL)
            oss << ", " << operands[2]->toString();

        return oss.str();
    }
	
    QuadrupleVector QuadrupleVectorClone(const QuadrupleVector& q)
    {
        QuadrupleVector ret;
        for (unsigned int i = 0; i < q.size(); i++)
            ret.push_back(q[i].Clone());
        return ret;
    }

    void QuadrupleVectorInferenceType(QuadrupleVector& q)
    {
        for (unsigned int i=0; i<q.size(); i++)
            q[i].InferenceType();
    }

    void QuadrupleVectorGuessType(QuadrupleVector& q)
    {
        for (QuadrupleVector::iterator itr = q.begin(); itr != q.end(); itr++) {
            itr->GuessType();
        }
    }

    std::string QuadrupleVectorToCCode(const QuadrupleVector& q)
    {
        std::ostringstream oss;
        std::vector<std::string> param_stack;
        unsigned int tmp;
        for (QuadrupleVector::const_iterator itr = q.begin(); itr != q.end(); itr++) {
            std::istringstream iss(itr->ToCCode());
            std::string tok;
            iss >> tok;
            if (tok == "param") {
                iss >> tok;
                param_stack.push_back(tok);
            } else if (tok == "call") {
                std::string ret;
                iss >> ret >> tok >> tmp;
                if (ret != "0") oss << ret << " = ";
                oss << tok << "(";
                if (tmp > 0) {
                    std::string param_list;
                    for (unsigned int i = 0; i < tmp; i++) {
                        param_list = param_stack.back() + ", " + param_list;
                        param_stack.pop_back();
                    }
                    param_list = param_list.substr(0, param_list.length()-2);
                    oss << param_list;
                }
                oss << ");" << std::endl;
            } else {
                oss << itr->ToCCode() << std::endl;
            }
        }
        return oss.str();
    }

    std::string QuadrupleVectorToASMCode(const QuadrupleVector& q)
    {
        std::ostringstream oss;
        int count = 0;
        for (QuadrupleVector::const_iterator itr = q.begin(); itr != q.end(); itr++) {
            oss << "\t@ " << itr->toString() << std::endl;
            oss << "\t@ " << itr->ToCCode() << std::endl;
            std::istringstream iss(itr->ToASMCode());
            std::string tok;
            iss >> tok;
            if (tok == "bl") count = 0;
            if (tok == "param") {
                iss >> tok;
                oss << "\tldr r" << count++ << ", [fp, #" << tok << "]\n" << std::endl;
            } else {
                oss << itr->ToASMCode() << std::endl;
            }
        }
        return oss.str();
    }

    std::string label() {
    	static unsigned int label_postfix = 0;

        std::ostringstream oss;
        oss << "L" << label_postfix;
        label_postfix++;
        
        return oss.str();
    }

    IDTokenSet QuadrupleVectorToIDTokenSet(const QuadrupleVector& q)
    {
        IDTokenSet ret;
        for (unsigned int i=0; i<q.size(); i++) {
            for (unsigned int j=0; j<3; j++) {
                IDToken* pt = dynamic_cast<IDToken*>(q[i].operands[j]);
                if (pt != 0) {
                    IDTokenSet::const_iterator s_itr = ret.begin();
                    for (; s_itr != ret.end(); s_itr++) {
                        if (**s_itr == *pt)
                            break;
                    }
                    if (s_itr == ret.end())
                        ret.insert(pt);
                }
            }
        }
        return ret;
    }

    std::string QuadrupleVectorToCDeclaration(const QuadrupleVector &q, const std::vector<IDToken*>& p)
    {
        std::ostringstream oss;
        IDTokenSet s(QuadrupleVectorToIDTokenSet(q));
        for (IDTokenSet::const_iterator itr = s.begin(); itr != s.end(); itr++) {
            std::vector<IDToken*>::const_iterator c_iter = p.begin();
            for (; c_iter != p.end(); c_iter++)
                if ((*c_iter)->toString() == (*itr)->toString())
                    break;
            if (c_iter == p.end())
                if ((*itr)->getValueTypeStr() != "") {
                    if ((*itr)->getValueTypeStr() == "__int_array_t" || (*itr)->getValueTypeStr() == "__double_array_t" || (*itr)->getValueTypeStr() == "__str_array_t")
                        oss << (*itr)->getValueTypeStr() << "t "  << (*itr)->toString() << "___t;" << std::endl;
                    oss << (*itr)->getValueTypeStr() << " "  << (*itr)->toString() << ";" << std::endl;
                    
                    if ((*itr)->getValueTypeStr() == "__int_array_t" || (*itr)->getValueTypeStr() == "__double_array_t" || (*itr)->getValueTypeStr() == "__str_array_t") {
                        oss << (*itr)->toString() << " = &" << (*itr)->toString() << "___t;" << std::endl;
                        oss << (*itr)->toString() << "->size = 0;" << std::endl;
                    }
                }
        }
        return oss.str();
    }

    std::string QuadrupleVectorToString(const QuadrupleVector& q) {
        std::ostringstream oss;
        QuadrupleVector::const_iterator c_iter = q.begin();
        for (; c_iter != q.end(); c_iter++)
            oss << c_iter->toString() << std::endl;

        return oss.str();
    }

    int lastAssignIndex(const QuadrupleVector & q) {
        int index = -1;

        QuadrupleVector::const_reverse_iterator r_iter = q.rbegin();
        for (int i = q.size() - 1; r_iter != q.rend(); r_iter++, i--) {
            if (r_iter->opr == ASSIGNOP || r_iter->opr == ASSIGNOP_INT_ANY_INT || r_iter->opr == ASSIGNOP_STR_ANY_STR) {
                index = i;
                break;
            }
        }

        return index;
    }
	
}
