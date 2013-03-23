//============================================================================
// Name        : c_compiler.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C Compiler
//============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Parser.h"
#include "SymbolTable.h"

int main( int argc , char** argv ) {
	
	// erro handling
	if( argc < 2 )
	{

		std::cerr << "specify file" << std::endl;

		exit(1);

	}

	// Try open file
	std::fstream inf;

	inf.open( argv[1] , std::fstream::in );

	if( !inf.good() )
	{
	
		std::cerr << "cannot open file" << std::endl;

		exit(2);
	
	}


	SymbolTable* table = new SymbolTable();

	Scanner scanner(table, inf, std::cout); 
	scanner.setDebugLines(std::cout);

	Parser p(scanner, table);

	// Parser p( inf , table );
	
	p.setDebug( false );

	p.parse();

	return 0;
}
