        switch(opr) {
        case NOP:
            return "NOP";
        case ANDOP:
            return "ANDOP";
        case OROP:
            return "OROP";
        case ADDOP:
            return "ADDOP";
        case SUBOP:
            return "SUBOP";
        case MULOP:
            return "MULOP";
        case DIVOP:
            return "DIVOP";
        case EQOP:
            return "EQOP";
        case NEQOP:
            return "NEQOP";
        case LESSOP:
            return "LESSOP";
        case GREATEROP:
            return "GREATEROP";
        case LEQOP:
            return "LEQOP";
        case GEQOP:
            return "GEQOP";
        case ASSIGNOP:
            return "ASSIGNOP";
        case LARRAYOP:
            return "LARRAYOP";
        case RARRAYOP:
            return "RARRAYOP";
        case GOTOOP:
            return "GOTOOP";
        case IFOP:
            return "IFOP";
        case UNLESSOP:
            return "UNLESSOP";
        case IFLESSOP:
            return "IFLESSOP";
        case IFGREATEROP:
            return "IFGREATEROP";
        case IFLEQOP:
            return "IFLEQOP";
        case IFGEQOP:
            return "IFGEQOP";
        case IFEQOP:
            return "IFEQOP";
        case IFNEQOP:
            return "IFNEQOP";
        case PARAMOP:
            return "PARAMOP";
        case PROCEDUREOP:
            return "PROCEDUREOP";
        case FUNCTIONOP:
            return "FUNCTIONOP";
        case RETURNOP:
            return "RETURNOP";
        case ADDRESSOP:
            return "ADDRESSOP";
        case STAROP:
            return "STAROP";
        case STARASSIGNOP:
            return "STARASSIGNOP";
        case NOTOP:
            return "NOTOP";
        case MINUSOP:
            return "MINUSOP";
        case PRINTOP:
            return "PRINTOP";
        case LABELOP:
            return "LABELOP";
        case NOP_ANY:
            return "NOP_ANY";
        case ADDOP_INT_INT:
            return "ADDOP_INT_INT";
        case ADDOP_CINT_INT:
            return "ADDOP_CINT_INT";
        case ADDOP_INT_CINT:
            return "ADDOP_INT_CINT";
        case ADDOP_CINT_CINT:
            return "ADDOP_CINT_CINT";
        case ADDOP_DOUBLE_DOUBLE:
            return "ADDOP_DOUBLE_DOUBLE";
        case ADDOP_STR_STR:
            return "ADDOP_STR_STR";
        case SUBOP_INT_INT:
            return "SUBOP_INT_INT";
        case SUBOP_CINT_INT:
            return "SUBOP_CINT_INT";
        case SUBOP_INT_CINT:
            return "SUBOP_INT_CINT";
        case SUBOP_CINT_CINT:
            return "SUBOP_CINT_CINT";
        case SUBOP_DOUBLE_DOUBLE:
            return "SUBOP_DOUBLE_DOUBLE";
        case MULOP_INT_INT:
            return "MULOP_INT_INT";
        case MULOP_INT_CINT:
            return "MULOP_INT_CINT";
        case MULOP_CINT_INT:
            return "MULOP_CINT_INT";
        case MULOP_CINT_CINT:
            return "MULOP_CINT_CINT";
        case MULOP_DOUBLE_DOUBLE:
            return "MULOP_DOUBLE_DOUBLE";
        case DIVOP_INT_INT:
            return "DIVOP_INT_INT";
        case DIVOP_INT_CINT:
            return "DIVOP_INT_CINT";
        case DIVOP_CINT_INT:
            return "DIVOP_CINT_INT";
        case DIVOP_CINT_CINT:
            return "DIVOP_CINT_CINT";
        case DIVOP_DOUBLE_DOUBLE:
            return "DIVOP_DOUBLE_DOUBLE";
        case ANDOP_INT_INT:
            return "ANDOP_INT_INT";
        case ANDOP_INT_CINT:
            return "ANDOP_INT_CINT";
        case ANDOP_CINT_INT:
            return "ANDOP_CINT_INT";
        case ANDOP_CINT_CINT:
            return "ANDOP_CINT_CINT";
        case OROP_INT_INT:
            return "OROP_INT_INT";
        case OROP_INT_CINT:
            return "OROP_INT_CINT";
        case OROP_CINT_INT:
            return "OROP_CINT_INT";
        case OROP_CINT_CINT:
            return "OROP_CINT_CINT";
        case EQOP_INT_INT:
            return "EQOP_INT_INT";
        case EQOP_INT_CINT:
            return "EQOP_INT_CINT";
        case EQOP_CINT_INT:
            return "EQOP_CINT_INT";
        case EQOP_CINT_CINT:
            return "EQOP_CINT_CINT";
        case EQOP_DOUBLE_DOUBLE:
            return "EQOP_DOUBLE_DOUBLE";
        case EQOP_STR_STR:
            return "EQOP_STR_STR";
        case EQOP_STR_CSTR:
            return "EQOP_STR_CSTR";
        case EQOP_CSTR_STR:
            return "EQOP_CSTR_STR";
        case EQOP_CSTR_CSTR:
            return "EQOP_CSTR_CSTR";
        case NEQOP_INT_INT:
            return "NEQOP_INT_INT";
        case NEQOP_INT_CINT:
            return "NEQOP_INT_CINT";
        case NEQOP_CINT_INT:
            return "NEQOP_CINT_INT";
        case NEQOP_CINT_CINT:
            return "NEQOP_CINT_CINT";
        case NEQOP_DOUBLE_DOUBLE:
            return "NEQOP_DOUBLE_DOUBLE";
        case NEQOP_STR_STR:
            return "NEQOP_STR_STR";
        case NEQOP_STR_CSTR:
            return "NEQOP_STR_CSTR";
        case NEQOP_CSTR_STR:
            return "NEQOP_CSTR_STR";
        case NEQOP_CSTR_CSTR:
            return "NEQOP_CSTR_CSTR";
        case LESSOP_INT_INT:
            return "LESSOP_INT_INT";
        case LESSOP_INT_CINT:
            return "LESSOP_INT_CINT";
        case LESSOP_CINT_INT:
            return "LESSOP_CINT_INT";
        case LESSOP_CINT_CINT:
            return "LESSOP_CINT_CINT";
        case LESSOP_DOUBLE_DOUBLE:
            return "LESSOP_DOUBLE_DOUBLE";
        case LESSOP_STR_STR:
            return "LESSOP_STR_STR";
        case LESSOP_STR_CSTR:
            return "LESSOP_STR_CSTR";
        case LESSOP_CSTR_STR:
            return "LESSOP_CSTR_STR";
        case LESSOP_CSTR_CSTR:
            return "LESSOP_CSTR_CSTR";
        case GREATEROP_INT_INT:
            return "GREATEROP_INT_INT";
        case GREATEROP_INT_CINT:
            return "GREATEROP_INT_CINT";
        case GREATEROP_CINT_INT:
            return "GREATEROP_CINT_INT";
        case GREATEROP_CINT_CINT:
            return "GREATEROP_CINT_CINT";
        case GREATEROP_DOUBLE_DOUBLE:
            return "GREATEROP_DOUBLE_DOUBLE";
        case GREATEROP_STR_STR:
            return "GREATEROP_STR_STR";
        case GREATEROP_STR_CSTR:
            return "GREATEROP_STR_CSTR";
        case GREATEROP_CSTR_STR:
            return "GREATEROP_CSTR_STR";
        case GREATEROP_CSTR_CSTR:
            return "GREATEROP_CSTR_CSTR";
        case LEQOP_INT_INT:
            return "LEQOP_INT_INT";
        case LEQOP_INT_CINT:
            return "LEQOP_INT_CINT";
        case LEQOP_CINT_INT:
            return "LEQOP_CINT_INT";
        case LEQOP_CINT_CINT:
            return "LEQOP_CINT_CINT";
        case LEQOP_DOUBLE_DOUBLE:
            return "LEQOP_DOUBLE_DOUBLE";
        case LEQOP_STR_STR:
            return "LEQOP_STR_STR";
        case LEQOP_STR_CSTR:
            return "LEQOP_STR_CSTR";
        case LEQOP_CSTR_STR:
            return "LEQOP_CSTR_STR";
        case LEQOP_CSTR_CSTR:
            return "LEQOP_CSTR_CSTR";
        case GEQOP_INT_INT:
            return "GEQOP_INT_INT";
        case GEQOP_INT_CINT:
            return "GEQOP_INT_CINT";
        case GEQOP_CINT_INT:
            return "GEQOP_CINT_INT";
        case GEQOP_CINT_CINT:
            return "GEQOP_CINT_CINT";
        case GEQOP_DOUBLE_DOUBLE:
            return "GEQOP_DOUBLE_DOUBLE";
        case GEQOP_STR_STR:
            return "GEQOP_STR_STR";
        case GEQOP_STR_CSTR:
            return "GEQOP_STR_CSTR";
        case GEQOP_CSTR_STR:
            return "GEQOP_CSTR_STR";
        case GEQOP_CSTR_CSTR:
            return "GEQOP_CSTR_CSTR";
        case ASSIGNOP_INT_ANY_INT:
            return "ASSIGNOP_INT_ANY_INT";
        case ASSIGNOP_CINT_ANY_INT:
            return "ASSIGNOP_CINT_ANY_INT";
        case ASSIGNOP_DOUBLE_DOUBLE:
            return "ASSIGNOP_DOUBLE_DOUBLE";
        case ASSIGNOP_STR_ANY_STR:
            return "ASSIGNOP_STR_ANY_STR";
        case ASSIGNOP_CSTR_ANY_STR:
            return "ASSIGNOP_CSTR_ANY_STR";
        case ASSIGNOP_IARR_ANY_IARR:
            return "ASSIGNOP_IARR_ANY_IARR";
        case ASSIGNOP_DARR_ANY_DARR:
            return "ASSIGNOP_DARR_ANY_DARR";
        case ASSIGNOP_SARR_ANY_SARR:
            return "ASSIGNOP_SARR_ANY_SARR";
        case LARRAYOP_INT_INT_IARR:
            return "LARRAYOP_INT_INT_IARR";
        case LARRAYOP_CINT_INT_IARR:
            return "LARRAYOP_CINT_INT_IARR";
        case LARRAYOP_INT_CINT_IARR:
            return "LARRAYOP_INT_CINT_IARR";
        case LARRAYOP_CINT_CINT_IARR:
            return "LARRAYOP_CINT_CINT_IARR";
        case LARRAYOP_INT_DOUBLE_DARR:
            return "LARRAYOP_INT_DOUBLE_DARR";
        case LARRAYOP_INT_STR_SARR:
            return "LARRAYOP_INT_STR_SARR";
        case LARRAYOP_CINT_STR_SARR:
            return "LARRAYOP_CINT_STR_SARR";
        case LARRAYOP_INT_CSTR_SARR:
            return "LARRAYOP_INT_CSTR_SARR";
        case LARRAYOP_CINT_CSTR_SARR:
            return "LARRAYOP_CINT_CSTR_SARR";
        case RARRAYOP_IARR_INT_INT:
            return "RARRAYOP_IARR_INT_INT";
        case RARRAYOP_IARR_CINT_INT:
            return "RARRAYOP_IARR_CINT_INT";
        case RARRAYOP_DARR_INT_DOUBLE:
            return "RARRAYOP_DARR_INT_DOUBLE";
        case RARRAYOP_SARR_INT_STR:
            return "RARRAYOP_SARR_INT_STR";
        case RARRAYOP_SARR_CINT_STR:
            return "RARRAYOP_SARR_CINT_STR";
        case GOTOOP_ANY_ANY_LABEL:
            return "GOTOOP_ANY_ANY_LABEL";
        case IFOP_ANY:
            return "IFOP_ANY";
        case UNLESSOP_ANY:
            return "UNLESSOP_ANY";
        case IFLESSOP_INT_INT:
            return "IFLESSOP_INT_INT";
        case IFLESSOP_DOUBLE_DOUBLE:
            return "IFLESSOP_DOUBLE_DOUBLE";
        case IFLESSOP_STR_STR:
            return "IFLESSOP_STR_STR";
        case IFGREATEROP_INT_INT:
            return "IFGREATEROP_INT_INT";
        case IFGREATEROP_DOUBLE_DOUBLE:
            return "IFGREATEROP_DOUBLE_DOUBLE";
        case IFGREATEROP_STR_STR:
            return "IFGREATEROP_STR_STR";
        case IFLEQOP_INT_INT:
            return "IFLEQOP_INT_INT";
        case IFLEQOP_DOUBLE_DOUBLE:
            return "IFLEQOP_DOUBLE_DOUBLE";
        case IFLEQOP_STR_STR:
            return "IFLEQOP_STR_STR";
        case IFGEQOP_INT_INT:
            return "IFGEQOP_INT_INT";
        case IFGEQOP_DOUBLE_DOUBLE:
            return "IFGEQOP_DOUBLE_DOUBLE";
        case IFGEQOP_STR_STR:
            return "IFGEQOP_STR_STR";
        case IFEQOP_INT_INT:
            return "IFEQOP_INT_INT";
        case IFEQOP_DOUBLE_DOUBLE:
            return "IFEQOP_DOUBLE_DOUBLE";
        case IFEQOP_STR_STR:
            return "IFEQOP_STR_STR";
        case IFNEQOP_INT_INT:
            return "IFNEQOP_INT_INT";
        case IFNEQOP_DOUBLE_DOUBLE:
            return "IFNEQOP_DOUBLE_DOUBLE";
        case IFNEQOP_STR_STR:
            return "IFNEQOP_STR_STR";
        case PARAMOP_ANY:
            return "PARAMOP_ANY";
        case PROCEDUREOP_ANY:
            return "PROCEDUREOP_ANY";
        case FUNCTIONOP_ANY:
            return "FUNCTIONOP_ANY";
        case RETURNOP_ANY:
            return "RETURNOP_ANY";
        case ADDRESSOP_ANY:
            return "ADDRESSOP_ANY";
        case STAROP_ANY:
            return "STAROP_ANY";
        case STARASSIGNOP_ANY:
            return "STARASSIGNOP_ANY";
        case NOTOP_CINT:
            return "NOTOP_CINT";
        case NOTOP_INT:
            return "NOTOP_INT";
        case MINUSOP_INT:
            return "MINUSOP_INT";
        case PRINTOP_ANY_ANY_INT:
            return "PRINTOP_ANY_ANY_INT";
        case PRINTOP_ANY_ANY_DOUBLE:
            return "PRINTOP_ANY_ANY_DOUBLE";
        case PRINTOP_ANY_ANY_STR:
            return "PRINTOP_ANY_ANY_STR";
        case PRINTOP_ANY_ANY_IARR:
            return "PRINTOP_ANY_ANY_IARR";
        case PRINTOP_ANY_ANY_DARR:
            return "PRINTOP_ANY_ANY_DARR";
        case PRINTOP_ANY_ANY_SARR:
            return "PRINTOP_ANY_ANY_SARR";
        case LABELOP_ANY_ANY_LABEL:
            return "LABELOP_ANY_ANY_LABEL";
        default:
            return "???";
            // for eliminating warnings
        }