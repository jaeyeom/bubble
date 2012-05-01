
/*
 * quadruple.hpp
 * 
 */
#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_

#include <vector>
#include <sstream>
#include <set>
#include "token.hpp"

namespace Bubble {
    typedef Token* pToken;
    typedef pToken Operands[3];

    enum Operator {
		// No operation
        NOP,				// ;
		// a = b & c
        ANDOP,				// a = Token::T_INT;
		// a = b | c
        OROP,				// a = Token::T_INT;
		// a = b + c
        ADDOP,				// a = b;
		// a = b - c
        SUBOP,				// a = b;
		// a = b * c
        MULOP,				// a = b;
		// a = b / c
        DIVOP,				// a = b;
		// a = b == c
        EQOP,				// a = b;
		// a = b != c
        NEQOP,				// a = Token::T_INT;
		// a = b < c
        LESSOP,				// a = Token::T_INT;
		// a = b > c
        GREATEROP,			// a = Token::T_INT;
		// a = b <= c
        LEQOP,				// a = Token::T_INT;
		// a = b >= c
        GEQOP,				// a = Token::T_INT;
		// a = b
        ASSIGNOP,			// a = b;
		// a[b] = c
        LARRAYOP,			// a = (Token::TYPE)(c | Token::T_ARRAY);
		// a = b[c]
        RARRAYOP,			// a = (Token::TYPE)(b & ~Token::T_ARRAY);
		// goto a
        GOTOOP,				// ;
		// goto a if b
        IFOP,				// ;
		// goto a unless b
        UNLESSOP,			// ;
		// goto a if b < c
        IFLESSOP,			// ;
		// goto a if b > c
        IFGREATEROP,		// ;
		// goto a if b <= c
        IFLEQOP,			// ;
		// goto a if b >= c
        IFGEQOP,			// ;
		// goto a if b == c
        IFEQOP,				// ;
		// goto a if b != c
        IFNEQOP,			// ;
		// param a
        PARAMOP,			// ;
		// call b(함수이름), c(인자 개수)
        PROCEDUREOP,		// ;
		// a = call b(함수이름), c(인자 개수)
        FUNCTIONOP,			// a = Token::T_INT;
		// return a
        RETURNOP,			// ;
		// a = &b
        ADDRESSOP,			// ;
		// a = *b
        STAROP,				// ;
		// *a = b
        STARASSIGNOP,		// ;
		// a = !b
        NOTOP,				// a = Token::T_INT;
		// a = -b
        MINUSOP,			// a = Token::T_INT;
		// print a
        PRINTOP,			// ;
		// label a: goto a comes here
        LABELOP,			// ;

        // These are typed operators
        // 이용될 수도 있고 되지 않은 수도 있음.
        // 내부 생성용임.
        // 아래쪽에 있는 것은 규칙을 지킬 것.
        // 오른쪽에 붙은 주석의 모양대로 코드를 생성해주는 생성기가 있음.
        // 왼쪽에 있는 토큰의 이름 역시 중요함. GuessType을 생성해주는 생성기가 있음.
        // 인자 순서는 밑줄로 구분하여 b, c, a의 타입을 나타내고 생략 가능하고 ANY로 역시 생략 가능.
        // IARR과 SARR이 INT_ARRAY와 STR_ARRAY를 나타냄.
        NOP_ANY,                   // ;
        /* NOP */
        ADDOP_INT_INT,             // a = b + c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           add r0, r1, r0
           str r0, [fp, #a]
         */
        ADDOP_CINT_INT,             // a = b + c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           add r0, r1, r0
           str r0, [fp, #a]
         */
        ADDOP_INT_CINT,             // a = b + c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           add r0, r1, r0
           str r0, [fp, #a]
         */
        ADDOP_CINT_CINT,             // a = b + c;
        /* mov r0, #b
           mov r1, #c
           add r0, r1, r0
           str r0, [fp, #a]
         */

        ADDOP_DOUBLE_DOUBLE,       // a = b + c;
        ADDOP_STR_STR,             // strcpy(a, b); strcat(a, c);
        SUBOP_INT_INT,             // a = b - c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           sub r0, r0, r1
           str r0, [fp, #a]
         */
        SUBOP_CINT_INT,             // a = b - c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           sub r0, r0, r1
           str r0, [fp, #a]
         */
        SUBOP_INT_CINT,             // a = b - c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           sub r0, r0, r1
           str r0, [fp, #a]
         */
        SUBOP_CINT_CINT,             // a = b - c;
        /* mov r0, #b
           mov r1, #c
           sub r0, r0, r1
           str r0, [fp, #a]
         */
        SUBOP_DOUBLE_DOUBLE,       // a = b - c;
        MULOP_INT_INT,             // a = b * c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           mul r0, r1, r0
           str r0, [fp, #a]
         */
        MULOP_INT_CINT,             // a = b * c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           mul r0, r1, r0
           str r0, [fp, #a]
         */
        MULOP_CINT_INT,             // a = b * c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           mul r0, r1, r0
           str r0, [fp, #a]
         */
        MULOP_CINT_CINT,             // a = b * c;
        /* mov r0, #b
           mov r1, #c
           mul r0, r1, r0
           str r0, [fp, #a]
         */
        MULOP_DOUBLE_DOUBLE,       // a = b * c;
        DIVOP_INT_INT,             // a = b / c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           bl __divsi3
           str r0, [fp, #a]
         */
        DIVOP_INT_CINT,             // a = b / c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           bl __divsi3
           str r0, [fp, #a]
         */
        DIVOP_CINT_INT,             // a = b / c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           bl __divsi3
           str r0, [fp, #a]
         */
        DIVOP_CINT_CINT,             // a = b / c;
        /* mov r0, #b
           mov r1, #c
           bl __divsi3
           str r0, [fp, #a]
         */
        DIVOP_DOUBLE_DOUBLE,       // a = b / c;
        ANDOP_INT_INT,             // a = b && c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           and r0, r1, r0
           str r0, [fp, #a]
         */
        ANDOP_INT_CINT,             // a = b && c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           and r0, r1, r0
           str r0, [fp, #a]
         */
        ANDOP_CINT_INT,             // a = b && c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           and r0, r1, r0
           str r0, [fp, #a]
         */
        ANDOP_CINT_CINT,             // a = b && c;
        /* mov r0, #b
           mov r1, #c
           and r0, r1, r0
           str r0, [fp, #a]
         */
        OROP_INT_INT,              // a = b || c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           orr r0, r1, r0
           str r0, [fp, #a]
         */
        OROP_INT_CINT,              // a = b || c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           orr r0, r1, r0
           str r0, [fp, #a]
         */
        OROP_CINT_INT,              // a = b || c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           orr r0, r1, r0
           str r0, [fp, #a]
         */
        OROP_CINT_CINT,              // a = b || c;
        /* mov r0, #b
           mov r1, #c
           orr r0, r1, r0
           str r0, [fp, #a]
         */
        EQOP_INT_INT,              // a = b == c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           cmp r0, r1
           movne r0, #0
           moveq r0, #1
           str r0, [fp, #a]
         */
        EQOP_INT_CINT,              // a = b == c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           cmp r0, r1
           movne r0, #0
           moveq r0, #1
           str r0, [fp, #a]
         */
        EQOP_CINT_INT,              // a = b == c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           cmp r0, r1
           movne r0, #0
           moveq r0, #1
           str r0, [fp, #a]
         */
        EQOP_CINT_CINT,              // a = b == c;
        /* mov r0, #b
           mov r1, #c
           cmp r0, r1
           movne r0, #0
           moveq r0, #1
           str r0, [fp, #a]
         */
        EQOP_DOUBLE_DOUBLE,        // a = b == c;
        EQOP_STR_STR,              // a = strcmp(b, c) == 0;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           bl compare_str
           cmp r0, #0
           movne r0, #0
           moveq r0, #1
         */
        EQOP_STR_CSTR,              // a = strcmp(b, c) == 0;
        EQOP_CSTR_STR,              // a = strcmp(b, c) == 0;
        EQOP_CSTR_CSTR,              // a = strcmp(b, c) == 0;
        NEQOP_INT_INT,             // a = b != c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           cmp r0, r1
           movne r0, #1
           moveq r0, #0
           str r0, [fp, #a]
         */
        NEQOP_INT_CINT,             // a = b != c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           cmp r0, r1
           movne r0, #1
           moveq r0, #0
           str r0, [fp, #a]
         */
        NEQOP_CINT_INT,             // a = b != c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           cmp r0, r1
           movne r0, #1
           moveq r0, #0
           str r0, [fp, #a]
         */
        NEQOP_CINT_CINT,             // a = b != c;
        /* mov r0, #b
           mov r1, #c
           cmp r0, r1
           movne r0, #1
           moveq r0, #0
           str r0, [fp, #a]
         */
        NEQOP_DOUBLE_DOUBLE,       // a = b != c;
        NEQOP_STR_STR,             // a = strcmp(b, c) != 0;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           bl compare_str
           cmp r0, #0
           movne r0, #1
           moveq r0, #0
         */
        NEQOP_STR_CSTR,             // a = strcmp(b, c) != 0;
        NEQOP_CSTR_STR,             // a = strcmp(b, c) != 0;
        NEQOP_CSTR_CSTR,             // a = strcmp(b, c) != 0;
        LESSOP_INT_INT,            // a = b < c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           cmp r0, r1
           movge r0, #0
           movlt r0, #1
           str r0, [fp, #a]
         */
        LESSOP_INT_CINT,            // a = b < c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           cmp r0, r1
           movge r0, #0
           movlt r0, #1
           str r0, [fp, #a]
         */
        LESSOP_CINT_INT,            // a = b < c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           cmp r0, r1
           movge r0, #0
           movlt r0, #1
           str r0, [fp, #a]
         */
        LESSOP_CINT_CINT,            // a = b < c;
        /* mov r0, #b
           mov r1, #c
           cmp r0, r1
           movge r0, #0
           movlt r0, #1
           str r0, [fp, #a]
         */
        LESSOP_DOUBLE_DOUBLE,      // a = b < c;
        LESSOP_STR_STR,            // a = strcmp(b, c) < 0;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           bl compare_str
           cmp r0, #0
           movlt r0, #1
           movge r0, #0
         */
        LESSOP_STR_CSTR,            // a = strcmp(b, c) < 0;
        LESSOP_CSTR_STR,            // a = strcmp(b, c) < 0;
        LESSOP_CSTR_CSTR,            // a = strcmp(b, c) < 0;
        GREATEROP_INT_INT,         // a = b > c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           cmp r0, r1
           movle r0, #0
           movgt r0, #1
           str r0, [fp, #a]
         */
        GREATEROP_INT_CINT,         // a = b > c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           cmp r0, r1
           movle r0, #0
           movgt r0, #1
           str r0, [fp, #a]
         */
        GREATEROP_CINT_INT,         // a = b > c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           cmp r0, r1
           movle r0, #0
           movgt r0, #1
           str r0, [fp, #a]
         */
        GREATEROP_CINT_CINT,         // a = b > c;
        /* mov r0, #b
           mov r1, #c
           cmp r0, r1
           movle r0, #0
           movgt r0, #1
           str r0, [fp, #a]
         */
        GREATEROP_DOUBLE_DOUBLE,   // a = b > c;
        GREATEROP_STR_STR,         // a = strcmp(b, c) > 0;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           bl compare_str
           cmp r0, #0
           movgt r0, #1
           movle r0, #0
         */
        GREATEROP_STR_CSTR,         // a = strcmp(b, c) > 0;
        GREATEROP_CSTR_STR,         // a = strcmp(b, c) > 0;
        GREATEROP_CSTR_CSTR,         // a = strcmp(b, c) > 0;
        LEQOP_INT_INT,             // a = b <= c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           cmp r0, r1
           movgt r0, #0
           movle r0, #1
           str r0, [fp, #a]
         */
        LEQOP_INT_CINT,             // a = b <= c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           cmp r0, r1
           movgt r0, #0
           movle r0, #1
           str r0, [fp, #a]
         */
        LEQOP_CINT_INT,             // a = b <= c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           cmp r0, r1
           movgt r0, #0
           movle r0, #1
           str r0, [fp, #a]
         */
        LEQOP_CINT_CINT,             // a = b <= c;
        /* mov r0, #b
           mov r1, #c
           cmp r0, r1
           movgt r0, #0
           movle r0, #1
           str r0, [fp, #a]
         */
        LEQOP_DOUBLE_DOUBLE,       // a = b <= c;
        LEQOP_STR_STR,             // a = strcmp(b, c) <= 0;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           bl compare_str
           cmp r0, #0
           movle r0, #1
           movgt r0, #0
         */
        LEQOP_STR_CSTR,             // a = strcmp(b, c) <= 0;
        LEQOP_CSTR_STR,             // a = strcmp(b, c) <= 0;
        LEQOP_CSTR_CSTR,             // a = strcmp(b, c) <= 0;
        GEQOP_INT_INT,             // a = b >= c;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           cmp r0, r1
           movlt r0, #0
           movge r0, #1
           str r0, [fp, #a]
         */
        GEQOP_INT_CINT,             // a = b >= c;
        /* ldr r0, [fp, #b]
           mov r1, #c
           cmp r0, r1
           movlt r0, #0
           movge r0, #1
           str r0, [fp, #a]
         */
        GEQOP_CINT_INT,             // a = b >= c;
        /* mov r0, #b
           ldr r1, [fp, #c]
           cmp r0, r1
           movlt r0, #0
           movge r0, #1
           str r0, [fp, #a]
         */
        GEQOP_CINT_CINT,             // a = b >= c;
        /* mov r0, #b
           mov r1, #c
           cmp r0, r1
           movlt r0, #0
           movge r0, #1
           str r0, [fp, #a]
         */
        GEQOP_DOUBLE_DOUBLE,       // a = b >= c;
        GEQOP_STR_STR,             // a = strcmp(b, c) >= 0;
        /* ldr r0, [fp, #b]
           ldr r1, [fp, #c]
           bl compare_str
           cmp r0, #0
           movge r0, #1
           movlt r0, #0
         */
        GEQOP_STR_CSTR,             // a = strcmp(b, c) >= 0;
        GEQOP_CSTR_STR,             // a = strcmp(b, c) >= 0;
        GEQOP_CSTR_CSTR,             // a = strcmp(b, c) >= 0;
        ASSIGNOP_INT_ANY_INT,      // a = b;
        /* ldr r0, [fp, #b]
           str r0, [fp, #a]
         */
        ASSIGNOP_CINT_ANY_INT,     // a = b;
        /* mov r0, #b
           str r0, [fp, #a]
         */
        ASSIGNOP_DOUBLE_DOUBLE,    // a = b;
        ASSIGNOP_STR_ANY_STR,      // strcpy(a, b);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           bl assign_str
         */
        ASSIGNOP_CSTR_ANY_STR,     // strcpy(a, b);
        /* add r0, fp, #a
           ldr r1, b
           bl assign_str_const
         */
        ASSIGNOP_IARR_ANY_IARR,    // int_array_assign(a, b);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           bl assign_int_array
         */
        ASSIGNOP_DARR_ANY_DARR,    // double_array_assign(a, b);
        ASSIGNOP_SARR_ANY_SARR,    // str_array_assign(a, b);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           bl assign_str_array
         */
        LARRAYOP_INT_INT_IARR,     // int_array_set(a, b, c);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           ldr r2, [fp, #c]
           bl set_element_int_array
         */
        LARRAYOP_CINT_INT_IARR,     // int_array_set(a, b, c);
        /* add r0, fp, #a
           mov r1, #b
           ldr r2, [fp, #c]
           bl set_element_int_array
         */
        LARRAYOP_INT_CINT_IARR,     // int_array_set(a, b, c);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           mov r2, #c
           bl set_element_int_array
         */
        LARRAYOP_CINT_CINT_IARR,     // int_array_set(a, b, c);
        /* add r0, fp, #a
           mov r1, #b
           mov r2, #c
           bl set_element_int_array
         */
        LARRAYOP_INT_DOUBLE_DARR,  // double_array_set(a, b, c);
        LARRAYOP_INT_STR_SARR,     // str_array_set(a, b, c);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           ldr r2, [fp, #c]
           bl set_element_str_array
         */
        LARRAYOP_CINT_STR_SARR,     // str_array_set(a, b, c);
        /* add r0, fp, #a
           mov r1, #b
           ldr r2, [fp, #c]
           bl set_element_str_array
         */
        LARRAYOP_INT_CSTR_SARR,     // str_array_set(a, b, c);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           ldr r2, c
           bl set_element_str_array_const
         */
        LARRAYOP_CINT_CSTR_SARR,     // str_array_set(a, b, c);
        /* add r0, fp, #a
           mov r1, #b
           ldr r2, c
           bl set_element_str_array_const
         */
        RARRAYOP_IARR_INT_INT,     // a = b->data[c];
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           ldr r2, [fp, #c]
           bl get_element_int_array
         */
        RARRAYOP_IARR_CINT_INT,     // a = b->data[c];
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           mov r2, #c
           bl get_element_int_array
         */
        RARRAYOP_DARR_INT_DOUBLE,  // a = b->data[c];
        RARRAYOP_SARR_INT_STR,     // strcpy(a, b->data[c]);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           ldr r2, [fp, #c]
           bl get_element_str_array
         */
        RARRAYOP_SARR_CINT_STR,     // strcpy(a, b->data[c]);
        /* add r0, fp, #a
           ldr r1, [fp, #b]
           mov r2, #c
           bl get_element_str_array
         */
        GOTOOP_ANY_ANY_LABEL,      // goto a;
        /* beq .a
           bne .a
         */
        IFOP_ANY,                  // if (b) goto a;
        /* ldr r0, [fp, #b]
           cmp r0, #0
           bne .a
         */
        UNLESSOP_ANY,              // if (!(b)) goto a;
        /* ldr r0, [fp, #b]
           cmp r0, #0
           beq .a
         */
        IFLESSOP_INT_INT,          // if (b < c) goto a;
        IFLESSOP_DOUBLE_DOUBLE,    // if (b < c) goto a;
        IFLESSOP_STR_STR,          // if (strcmp(b, c) < 0) goto a;
        IFGREATEROP_INT_INT,       // if (b > c) goto a;
        IFGREATEROP_DOUBLE_DOUBLE, // if (b > c) goto a;
        IFGREATEROP_STR_STR,       // if (strcmp(b, c) > 0) goto a;
        IFLEQOP_INT_INT,           // if (b <= c) goto a;
        IFLEQOP_DOUBLE_DOUBLE,     // if (b <= c) goto a;
        IFLEQOP_STR_STR,           // if (strcmp(b, c) <= 0) goto a;
        IFGEQOP_INT_INT,           // if (b >= c) goto a;
        IFGEQOP_DOUBLE_DOUBLE,     // if (b >= c) goto a;
        IFGEQOP_STR_STR,           // if (strcmp(b, c) >= 0) goto a;
        IFEQOP_INT_INT,            // if (b == c) goto a;
        IFEQOP_DOUBLE_DOUBLE,      // if (b == c) goto a;
        IFEQOP_STR_STR,            // if (strcmp(b, c) == 0) goto a;
        IFNEQOP_INT_INT,           // if (b != c) goto a;
        IFNEQOP_DOUBLE_DOUBLE,     // if (b != c) goto a;
        IFNEQOP_STR_STR,           // if (strcmp(b, c) != 0) goto a;
        PARAMOP_ANY,               // param a
        /* param a
         */
        PROCEDUREOP_ANY,           // call 0 b c
        /* bl b
         */
        FUNCTIONOP_ANY,            // call a b c
        /* bl b
           str r0, [fp, #a]
         */
        RETURNOP_ANY,              // return a;
        /* ldr r0, [fp, #a]
         */
        ADDRESSOP_ANY,             // a = &b;
        STAROP_ANY,                // a = *b;
        STARASSIGNOP_ANY,          // *a = b;
        NOTOP_CINT,                // a = !(b);
        /* ldr r0, #b
           cmp r0, #0
           movne r0, #0
           moveq r0, #1
           str r0, [fp, #a]
        */
        NOTOP_INT,                 // a = !(b);
        /* ldr r0, [fp, #b]
           cmp r0, #0
           movne r0, #0
           moveq r0, #1
           str r0, [fp, #a]
        */
        MINUSOP_INT,               // a = -(b);
        PRINTOP_ANY_ANY_INT,       // printf(\"%d\\n\", a);
        /* ldr r0, [fp, #a]
           bl print_int
         */
        PRINTOP_ANY_ANY_DOUBLE,    // printf(\"%f\\n\", a);
        PRINTOP_ANY_ANY_STR,       // printf(\"%s\\n\", a);
        /* ldr r0, [fp, #a]
           bl print_str
         */
        PRINTOP_ANY_ANY_IARR,      // print_int_array(a);
        /* ldr r0, [fp, #a]
           bl print_int_array
         */
        PRINTOP_ANY_ANY_DARR,      // print_double_array(a);
        PRINTOP_ANY_ANY_SARR,      // print_str_array(a);
        /* ldr r0, [fp, #a]
           bl print_str_array
         */
        LABELOP_ANY_ANY_LABEL      // a: ;
        /* \n.a: 
         */
    };

    struct Quadruple {
        Operator opr;
        Operands operands;

        Quadruple();
        Quadruple(Operator, pToken, pToken, pToken);
        std::string OperatorToStr() const;
        void InferenceType();
        void GuessType();
        Quadruple Clone() const;
        std::string ToCCode() const;
        std::string ToASMCode() const;
        std::string toString() const;
    };

    typedef std::vector<Quadruple> QuadrupleVector;
    typedef std::set<IDToken*> IDTokenSet;

    QuadrupleVector QuadrupleVectorClone(const QuadrupleVector& q);
    void QuadrupleVectorInferenceType(QuadrupleVector& q);
    void QuadrupleVectorGuessType(QuadrupleVector& q);
    std::string QuadrupleVectorToCCode(const QuadrupleVector& q);
    std::string QuadrupleVectorToASMCode(const QuadrupleVector& q);
    IDTokenSet QuadrupleVectorToIDTokenSet(const QuadrupleVector& q);
    std::string QuadrupleVectorToCDeclaration(const QuadrupleVector& q, const std::vector<IDToken*>& p);
    std::string QuadrupleVectorToString(const QuadrupleVector& q);

    int lastAssignIndex(const QuadrupleVector & q);
    std::string label();
}

#endif
