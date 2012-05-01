CC=g++
CXX=g++
LIBS=-ly -lfl
LEX=flex
YACC=bison
LFILE=bubble.l
YFILE=bubble.y
BPLC=./bplc
EXAMPLE_SRCS=./fibonacci.src ./quicksort-num.src ./quicksort-str.src
CFLAGS=-Wall -g
CXXFLAGS=-Wall -g

all: bubble

bubble: bubbleLexer.o bubbleParser.o token.o bubble.y bubble.o treeHelper.o symbolTable.o function_table.o quadruple.o 
	$(CC) $(CFLAGS) -o "$@" bubble.o bubbleLexer.o bubbleParser.o token.o treeHelper.o symbolTable.o quadruple.o function_table.o $(LIBS)

test: all
	rm -f fibonacci.s quicksort-num.s quicksort-str.s
	$(BPLC) fibonacci.src > fibonacci.s
	$(BPLC) quicksort-num.src > quicksort-num.s
	$(BPLC) quicksort-str.src > quicksort-str.s

clean:
	rm -rf bubbleParser.hpp bubbleParser.cpp bubbleLexer.cpp bubble bubble.r15 bubble.r19 position.hh stack.hh location.hh lex.yy.cc *.o guess_type.inc to_c_code.inc to_asm_code.inc inference_type.inc operator_to_str.inc # bubble.y

rebuild: clean all

bubble.y: bubble.y.cfg yaccc bubbleLexer.hpp token.hpp parseTree.hpp treeHelper.hpp quadruple.hpp symbolTable.hpp function_table.hpp
#	rm -f bubble.y
#	./yaccc < bubble.y.cfg > bubble.y

bubbleParser.cpp: $(YFILE) bubbleLexer.hpp bubble.y parseTree.hpp treeHelper.hpp symbolTable.hpp function_table.hpp
	$(YACC) --define -obubbleParser.cpp $(YFILE)

bubbleLexer.cpp: $(LFILE) bubbleLexer.hpp bubble.l
	$(LEX) -obubbleLexer.cpp $(LFILE)

bubbleLexer.o: bubbleLexer.cpp bubbleParser.cpp

bubbleParser.o: bubbleParser.cpp

bubble.o: bubble.cpp token.hpp parseTree.hpp bubbleParser.hpp bubbleLexer.hpp treeHelper.hpp function_table.hpp line_no.hpp

token.o: token.hpp token.cpp

quadruple.o: quadruple.cpp guess_type.inc to_c_code.inc to_asm_code.inc inference_type.inc operator_to_str.inc quadruple.hpp symbolTable.hpp

symbolTable.o: symbolTable.hpp symbolTable.cpp

parseTree.hpp: itr_utils.hpp

bubbleLexer.hpp: token.hpp

quadruple.hpp: token.hpp

symbolTable.hpp: token.hpp

treeHelper.o: treeHelper.hpp treeHelper.cpp

treeHelper.hpp: token.hpp parseTree.hpp symbolTable.hpp quadruple.hpp function_table.hpp

function_table.o: function_table.cpp function_table.hpp quadruple.hpp

function_table.hpp: token.hpp quadruple.hpp

guess_type.inc: quadruple.hpp guess_gen
	rm -f guess_type.inc
	./guess_gen < quadruple.hpp > guess_type.inc

to_c_code.inc: quadruple.hpp to_c_code_gen
	rm -f to_c_code.inc
	./to_c_code_gen < quadruple.hpp > to_c_code.inc

to_asm_code.inc: quadruple.hpp to_asm_code_gen
	rm -f to_asm_code.inc
	./to_asm_code_gen < quadruple.hpp > to_asm_code.inc

inference_type.inc: quadruple.hpp inference_type_gen
	rm -f inference_type.inc
	./inference_type_gen < quadruple.hpp > inference_type.inc

operator_to_str.inc: quadruple.hpp operator_to_str_gen
	rm -f operator_to_str.inc
	./operator_to_str_gen < quadruple.hpp > operator_to_str.inc
