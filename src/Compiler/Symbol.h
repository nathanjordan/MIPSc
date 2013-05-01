/*
 * Symbol.h
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#include <string>
#include "SymbolLocation.h"

#ifndef SYMBOL_H_
#define SYMBOL_H_

class Type;

class Symbol
{

public:

	std::string id;

	SymbolLocation location;
	
	Type* symbolType;

	Symbol() 
	{}

	Symbol(std::string id, SymbolLocation location, Type* symbolType )
		: id(id), location(location), symbolType(symbolType)
	{}

	Symbol(std::string s, SymbolLocation location)
			: id(s), location(location)
		{}

	Symbol(std::string s, int l, int c)
		: id(s), location(l,c)
	{}

	std::string getId()
	{
		return id;
	}

	std::string getValueAsString()
	{
		//return symbolType->getType()->
		//return "implement getValueAsString";
		return "[a value]";
	}

	std::string getTypeAsString()
	{

		return "";
		//return symbolType->getTypeAsString();

	}

};

inline std::ostream& operator<< (std::ostream &out, Symbol& sym)
{
	std::cout << sym.getId() << " : " << sym.getValueAsString();
	return out;
}


#endif /* SYMBOL_H_ */
