        std::ostringstream oss;
        switch(opr) {
        case NOP_ANY:
            oss << "\tNOP" << std::endl;
            break;
        case ADDOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tadd r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case ADDOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tadd r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case ADDOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tadd r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case ADDOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tadd r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
            break;
        case SUBOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tsub r0, r0, r1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case SUBOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tsub r0, r0, r1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case SUBOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tsub r0, r0, r1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case SUBOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tsub r0, r0, r1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case MULOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tmul r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case MULOP_INT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tmul r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case MULOP_CINT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tmul r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case MULOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tmul r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case DIVOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl __divsi3" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case DIVOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl __divsi3" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case DIVOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl __divsi3" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case DIVOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl __divsi3" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case ANDOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tand r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case ANDOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tand r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case ANDOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tand r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case ANDOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tand r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case OROP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\torr r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case OROP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\torr r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case OROP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\torr r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case OROP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\torr r0, r1, r0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case EQOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #0" << std::endl;
            oss << "\tmoveq r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case EQOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #0" << std::endl;
            oss << "\tmoveq r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case EQOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #0" << std::endl;
            oss << "\tmoveq r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case EQOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #0" << std::endl;
            oss << "\tmoveq r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case EQOP_STR_STR:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl compare_str" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovne r0, #0" << std::endl;
            oss << "\tmoveq r0, #1" << std::endl;
            break;
            break;
            break;
            break;
        case NEQOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #1" << std::endl;
            oss << "\tmoveq r0, #0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case NEQOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #1" << std::endl;
            oss << "\tmoveq r0, #0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case NEQOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #1" << std::endl;
            oss << "\tmoveq r0, #0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case NEQOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovne r0, #1" << std::endl;
            oss << "\tmoveq r0, #0" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case NEQOP_STR_STR:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl compare_str" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovne r0, #1" << std::endl;
            oss << "\tmoveq r0, #0" << std::endl;
            break;
            break;
            break;
            break;
        case LESSOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovge r0, #0" << std::endl;
            oss << "\tmovlt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case LESSOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovge r0, #0" << std::endl;
            oss << "\tmovlt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case LESSOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovge r0, #0" << std::endl;
            oss << "\tmovlt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case LESSOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovge r0, #0" << std::endl;
            oss << "\tmovlt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case LESSOP_STR_STR:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl compare_str" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovlt r0, #1" << std::endl;
            oss << "\tmovge r0, #0" << std::endl;
            break;
            break;
            break;
            break;
        case GREATEROP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovle r0, #0" << std::endl;
            oss << "\tmovgt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case GREATEROP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovle r0, #0" << std::endl;
            oss << "\tmovgt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case GREATEROP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovle r0, #0" << std::endl;
            oss << "\tmovgt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case GREATEROP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovle r0, #0" << std::endl;
            oss << "\tmovgt r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case GREATEROP_STR_STR:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl compare_str" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovgt r0, #1" << std::endl;
            oss << "\tmovle r0, #0" << std::endl;
            break;
            break;
            break;
            break;
        case LEQOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovgt r0, #0" << std::endl;
            oss << "\tmovle r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case LEQOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovgt r0, #0" << std::endl;
            oss << "\tmovle r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case LEQOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovgt r0, #0" << std::endl;
            oss << "\tmovle r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case LEQOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovgt r0, #0" << std::endl;
            oss << "\tmovle r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case LEQOP_STR_STR:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl compare_str" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovle r0, #1" << std::endl;
            oss << "\tmovgt r0, #0" << std::endl;
            break;
            break;
            break;
            break;
        case GEQOP_INT_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovlt r0, #0" << std::endl;
            oss << "\tmovge r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case GEQOP_INT_CINT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovlt r0, #0" << std::endl;
            oss << "\tmovge r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case GEQOP_CINT_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovlt r0, #0" << std::endl;
            oss << "\tmovge r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case GEQOP_CINT_CINT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tcmp r0, r1" << std::endl;
            oss << "\tmovlt r0, #0" << std::endl;
            oss << "\tmovge r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case GEQOP_STR_STR:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r1, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl compare_str" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovge r0, #1" << std::endl;
            oss << "\tmovlt r0, #0" << std::endl;
            break;
            break;
            break;
            break;
        case ASSIGNOP_INT_ANY_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case ASSIGNOP_CINT_ANY_INT:
            oss << "\tmov r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case ASSIGNOP_STR_ANY_STR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tbl assign_str" << std::endl;
            break;
        case ASSIGNOP_CSTR_ANY_STR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, " << operands[1]->toAssemStr() << std::endl;
            oss << "\tbl assign_str_const" << std::endl;
            break;
        case ASSIGNOP_IARR_ANY_IARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tbl assign_int_array" << std::endl;
            break;
            break;
        case ASSIGNOP_SARR_ANY_SARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tbl assign_str_array" << std::endl;
            break;
        case LARRAYOP_INT_INT_IARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r2, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl set_element_int_array" << std::endl;
            break;
        case LARRAYOP_CINT_INT_IARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r2, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl set_element_int_array" << std::endl;
            break;
        case LARRAYOP_INT_CINT_IARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r2, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl set_element_int_array" << std::endl;
            break;
        case LARRAYOP_CINT_CINT_IARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tmov r2, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl set_element_int_array" << std::endl;
            break;
            break;
        case LARRAYOP_INT_STR_SARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r2, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl set_element_str_array" << std::endl;
            break;
        case LARRAYOP_CINT_STR_SARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r2, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl set_element_str_array" << std::endl;
            break;
        case LARRAYOP_INT_CSTR_SARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r2, " << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl set_element_str_array_const" << std::endl;
            break;
        case LARRAYOP_CINT_CSTR_SARR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tmov r1, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tldr r2, " << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl set_element_str_array_const" << std::endl;
            break;
        case RARRAYOP_IARR_INT_INT:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r2, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl get_element_int_array" << std::endl;
            break;
        case RARRAYOP_IARR_CINT_INT:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r2, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl get_element_int_array" << std::endl;
            break;
            break;
        case RARRAYOP_SARR_INT_STR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tldr r2, [fp, #" << operands[2]->toAssemStr() << "]" << std::endl;
            oss << "\tbl get_element_str_array" << std::endl;
            break;
        case RARRAYOP_SARR_CINT_STR:
            oss << "\tadd r0, fp, #" << operands[0]->toAssemStr() << std::endl;
            oss << "\tldr r1, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tmov r2, #" << operands[2]->toAssemStr() << std::endl;
            oss << "\tbl get_element_str_array" << std::endl;
            break;
        case GOTOOP_ANY_ANY_LABEL:
            oss << "\tbeq ." << operands[0]->toAssemStr() << std::endl;
            oss << "\tbne ." << operands[0]->toAssemStr() << std::endl;
            break;
        case IFOP_ANY:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tbne ." << operands[0]->toAssemStr() << std::endl;
            break;
        case UNLESSOP_ANY:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tbeq ." << operands[0]->toAssemStr() << std::endl;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
            break;
        case PARAMOP_ANY:
            oss << "\tparam " << operands[0]->toAssemStr() << std::endl;
            break;
        case PROCEDUREOP_ANY:
            oss << "\tbl " << operands[1]->toAssemStr() << std::endl;
            break;
        case FUNCTIONOP_ANY:
            oss << "\tbl " << operands[1]->toAssemStr() << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case RETURNOP_ANY:
            oss << "\tldr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
            break;
            break;
        case NOTOP_CINT:
            oss << "\tldr r0, #" << operands[1]->toAssemStr() << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovne r0, #0" << std::endl;
            oss << "\tmoveq r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
        case NOTOP_INT:
            oss << "\tldr r0, [fp, #" << operands[1]->toAssemStr() << "]" << std::endl;
            oss << "\tcmp r0, #0" << std::endl;
            oss << "\tmovne r0, #0" << std::endl;
            oss << "\tmoveq r0, #1" << std::endl;
            oss << "\tstr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            break;
            break;
        case PRINTOP_ANY_ANY_INT:
            oss << "\tldr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            oss << "\tbl print_int" << std::endl;
            break;
            break;
        case PRINTOP_ANY_ANY_STR:
            oss << "\tldr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            oss << "\tbl print_str" << std::endl;
            break;
        case PRINTOP_ANY_ANY_IARR:
            oss << "\tldr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            oss << "\tbl print_int_array" << std::endl;
            break;
            break;
        case PRINTOP_ANY_ANY_SARR:
            oss << "\tldr r0, [fp, #" << operands[0]->toAssemStr() << "]" << std::endl;
            oss << "\tbl print_str_array" << std::endl;
            break;
        case LABELOP_ANY_ANY_LABEL:
            oss << "\t\n." << operands[0]->toAssemStr() << ":" << std::endl;
            break;
        default:
            oss << "@ couldn't generate code for this operation!" << std::endl;
            break;
        };
        return oss.str();
