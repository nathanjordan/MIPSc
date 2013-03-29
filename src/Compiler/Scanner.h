// Generated by Flexc++ V0.98.00 on Tue, 26 Feb 2013 15:00:00 -0800

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"
#include "SymbolTable.h"
#include "SymbolLocation.h"
#include <string>
#include <fstream>

class Parser;

// $insert classHead
class Scanner: public ScannerBase
{
    public:

		//
		//      Base Constructor 
		//
		//      for constructors of the form : Scanner(istream, ostream, ...)
		//
		// This is the constructor that takes the largest number of arguments.
		// This can be used as a base constructor by all the other
		// constructors for member initialization. I.e., all the other
		// constructors delegate to this base constructor for consistency.
		Scanner(std::istream &in, std::ostream &out, SymbolTable* tab, Parser* p);


		explicit Scanner(std::istream &in = std::cin, std::ostream &out = std::cout);

		Scanner(SymbolTable* tab, std::istream &in = std::cin, std::ostream &out = std::cout);

		Scanner(Parser* p, std::istream &in, std::ostream &out);

		// explicit Scanner(SymbolTable*);

		Scanner(std::string const &infile, std::string const &outfile);

		// ~Scanner if defined outside of the braces of this class here, it
		// causes a compiler error : multiple definition ...
		~Scanner() {
			// Dump Symbol Table
			if (debug.symbol_table_dump) {
				if (stab) {
					stab->dumpTable(debug.symbol_table_dump_file);
				}
				else {
					std::cerr << "~Scanner() : bad symbol table" << std::endl;
				}
			}
		}

	public : 

		void run();

		// Prints the line the bad lexeme is on and points to to the bad lexeme.
		//  
		// Call this function when a bad lexeme is found.
		// This function assumes updateLocation() keeps track of
		// lnum,cnum,lastNewlinePos. Don't call updateLocation() when bad
		// lexeme is found since that updates the location to the next lexeme.
        void scannerError();

        void commentHandler();

		// This function keeps track of the location of lexeme.
		//
		// After callling this function, location (member variable) refers to
		// the location of the next lexeme to be consumed by line number and
		// column number :
		//
		//	locatoin.lnum  and location.cnum
		//
		// lastNewlinePos is the zero-indexed offset of the last newline
		// character from the beginning of the file.
		//
		//	lastNewlinePos and numBytesRead
		// 
		void updateLocation();

		// This is a wrapper function that handles all the updates on each
		// token extraction. 
		void update();

		std::string nextLine();

		std::string lastLine();

		SymbolLocation& getLoc() { return location; }

		void dumpSymbolTable();

		static const int tabWidth = 4;

		// $insert lexFunctionDecl
		int lex();

		void setDebugLineByLine(std::ostream& lineOutputTo);

		void setDebugSymbolTableDump(std::ostream& symbolTableDumpTo);

		// void setDebugSymbolTableDump(const std::string filename);

		void setDebugSymbolTableDump(const std::string& filename);

		void setDebugLexer(std::ostream& lexerDumpTo);

		void setDebugToken(const std::string& filename);
		
		// any cleanup after the scanner is done with eof.
		void cleanup();

    private: // member functions

		int lex__();

		int executeAction__(size_t ruleNr);

		void print();

		void preCode();     // re-implement this function for code that must 
							// be exec'ed before the patternmatching starts

	private: // member variables

		struct ScannerDebug {
			ScannerDebug() 
				: output_line_by_line(false), lineOutputTo(NULL),
					symbol_table_dump(false)// , symbolTableDumpTo(NULL)
			{}

			bool output_line_by_line;
			std::ostream* lineOutputTo;
			bool lexer_dump;
			std::ostream* lexerDumpTo;
			bool symbol_table_dump;
			std::string symbol_table_dump_file;
			bool token_dump;
			std::string token_dump_file;
			std::ofstream token_file_stream;
			// std::ostream* symbolTableDumpTo;
		};

		std::istream* ref_istream;
		SymbolTable* stab;
		Parser* parser;

		ScannerDebug debug;
		SymbolLocation location; // current location

};

inline Scanner::Scanner(std::istream &in, std::ostream &out, SymbolTable* tab, Parser* p)
	: ScannerBase(in, out), ref_istream(&in), stab(tab), parser(p)
	{}

// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out)
: Scanner(in, out, NULL, NULL)
{}

inline Scanner::Scanner(SymbolTable* tab, std::istream &in, std::ostream &out )
: Scanner(in, out, tab, NULL)
{}

// $insert scannerConstructors
inline Scanner::Scanner(Parser* p, std::istream &in, std::ostream &out)
: Scanner(in, out, NULL, p)
{}

inline Scanner::Scanner(std::string const &infile, std::string const &outfile)
: ScannerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex__();
}

inline void Scanner::preCode() 
{
    // optionally replace by your own code
	// std::cout << "preCode() " << std::endl;
}

inline void Scanner::print() 
{
    print__();
}


#endif // Scanner_H_INCLUDED_

