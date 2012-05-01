        switch(opr) {
        case NOP:
            ;
            break;
        case ANDOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case OROP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case ADDOP:
            operands[0]->setValueType(operands[1]->getValueType());
            break;
        case SUBOP:
            operands[0]->setValueType(operands[1]->getValueType());
            break;
        case MULOP:
            operands[0]->setValueType(operands[1]->getValueType());
            break;
        case DIVOP:
            operands[0]->setValueType(operands[1]->getValueType());
            break;
        case EQOP:
            operands[0]->setValueType(operands[1]->getValueType());
            break;
        case NEQOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case LESSOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case GREATEROP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case LEQOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case GEQOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case ASSIGNOP:
            operands[0]->setValueType(operands[1]->getValueType());
            break;
        case LARRAYOP:
            operands[0]->setValueType((Token::TYPE)(operands[2]->getValueType() | Token::T_ARRAY));
            break;
        case RARRAYOP:
            operands[0]->setValueType((Token::TYPE)(operands[1]->getValueType() & ~Token::T_ARRAY));
            break;
        case GOTOOP:
            ;
            break;
        case IFOP:
            ;
            break;
        case UNLESSOP:
            ;
            break;
        case IFLESSOP:
            ;
            break;
        case IFGREATEROP:
            ;
            break;
        case IFLEQOP:
            ;
            break;
        case IFGEQOP:
            ;
            break;
        case IFEQOP:
            ;
            break;
        case IFNEQOP:
            ;
            break;
        case PARAMOP:
            ;
            break;
        case PROCEDUREOP:
            ;
            break;
        case FUNCTIONOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case RETURNOP:
            ;
            break;
        case ADDRESSOP:
            ;
            break;
        case STAROP:
            ;
            break;
        case STARASSIGNOP:
            ;
            break;
        case NOTOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case MINUSOP:
            operands[0]->setValueType(Token::T_INT);
            break;
        case PRINTOP:
            ;
            break;
        case LABELOP:
            ;
            break;
        default:
            break;
            // for eliminating warnings
        }
