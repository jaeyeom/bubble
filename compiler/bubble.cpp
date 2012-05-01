#include <iostream>
#include <stdio.h>
#include <string>
#include "token.hpp"
#include "parseTree.hpp"
#include "bubbleParser.hpp"
#include "bubbleLexer.hpp"
#include "symbolTable.hpp"
#include "quadruple.hpp"
#include "function_table.hpp"
#include "line_no.hpp"

Bubble::ParseTreeNode<Bubble::Token>* root_node = 0;
Bubble::SymbolTable symbol_tbl;
Bubble::FunctionTable function_tbl;

int main(int argc, char **argv)
{
    std::cerr << "Reading line number information. . ." << std::endl << std::endl;
    if (argc < 2) {
        std::cerr << "Error! Should provide input file name." << std::endl;
        exit(1);
    }
    std::string line_filename(argv[1]);
    line_filename += ".line";
    Bubble::read_line_no(line_filename.c_str());
    yyin = fopen(argv[1], "r");
    
    std::cerr << "Building parse tree. . . Building quadruples. . ." << std::endl << std::endl;

    yyparse();

    std::cerr << "Done." << std::endl << "Starting tree traversing. . ." << std::endl;

    Bubble::ParseTree<Bubble::Token> parseTree(root_node);

    parseTree.TraversePostOrder();
    function_tbl.GenReturn();
    function_tbl.GenType();
    function_tbl.GenList();

    std::cerr << "Done." << std::endl << "Generating code. . ." << std::endl;

    std::cout << "\t.file\t\"" << argv[1] << "\"\n";
    std::cout << function_tbl.ToASMCodeAll() << std::endl;

    std::cerr << "Done. Destroying parse tree. Each . denotes one node destruction." << std::endl;

    return 0;
}
	
