/*
 * ASTNodes.h
 *
 *  Created on: Apr 3, 2013
 *      Author: njordan
 */

#ifndef ASTNODES_H_
#define ASTNODES_H_

#include "ParserError.h"
#include "Node.h"
#include <cfloat>

//Forward Declarations
class ExpressionNode;
class CastExpressionNode;
class TypeNameNode;

//Definitions

class IdentifierNode : public Node
{

public:

	inline IdentifierNode( std::string _id ) : id( _id )
	{

	}

	inline std::string getId()
	{
		return id;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "identifier" );

	}

	//~IdentifierNode(){}

protected:

	std::string id;

};


class StringNode : public Node
{

public:

	inline StringNode( std::string _value ) : value( _value )
	{

	}

	inline std::string getValue()
	{
		return value;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "string" );

	}

	//~StringNode(){}

protected:

	std::string value;

};


class IntegerConstantNode : public Node
{

public:

	inline IntegerConstantNode( long long int _value ) : value( _value )
	{

	}

	inline long long int getValue()
	{
		return value;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "integer constant" );

	}

	//These handle the issue of overflow when casting
	// or performing operations
	bool canBeShort() { return ( value < 128 ) ? true : false; }
	bool canBeInt() { return ( value < 2147483648 ) ? true : false; }
	bool canBeLong() { return ( value < 2147483648 ) ? true : false; }
	//Long long is still going to be 32 bits on MIPS
	bool canBeLongLong() { return ( value < 2147483648 ) ? true : false; }

	bool canBeUnsignedShort() { return ( value < 256 ) ? true : false; }
	bool canBeUnsignedInt() { return ( value < 4294967296 ) ? true : false; }
	bool canBeUnsignedLong() { return ( value < 4294967296 ) ? true : false; }
	bool canBeUnsignedLongLong() { return ( value < 4294967296 ) ? true : false; }

	//~IntegerConstantNode(){}

protected:

	long long int value;

};


class FloatConstantNode : public Node
{

public:

	inline FloatConstantNode( double _value ) : value( _value )
	{

	}

	inline double getValue()
	{
		return value;
	}

	//These handle the issue of overflow when casting
	// or performing operations

	bool canBeFloat() { return ( value < FLT_MAX ) ? true : false; }

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "float constant" );

	}

	//~FloatConstantNode(){}

protected:

	double value;

};


class CharConstantNode : public Node
{

public:

	inline CharConstantNode( char _value ) : value( _value )
	{

	}

	inline char getValue()
	{
		return value;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "char constant" );

	}

	//~CharConstantNode(){}

protected:

	char value;

};

class ConstantNode : public Node
{

public:

	inline ConstantNode( IntegerConstantNode* _intConstant ) : intConstant( _intConstant )
	{

	}

	inline ConstantNode( FloatConstantNode* _floatConstant ) : floatConstant( _floatConstant )
	{

	}

	inline ConstantNode( CharConstantNode* _charConstant ) : charConstant( _charConstant )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "constant" );

	}

protected:

	IntegerConstantNode* intConstant;
	FloatConstantNode* floatConstant;
	CharConstantNode* charConstant;

	// TODO Enumeration constant
	// EnumerationConstantNode* enumConstant;

	//~CharConstantNode(){}

};


class AssignmentExpressionNode : public Node
{

public:

	inline AssignmentExpressionNode( )
	{



	}


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "assignment expression" );

	}

	//~ArgExpressionListNode(){}

};

class ArgExpressionListNode : public Node
{

public:

	inline ArgExpressionListNode( AssignmentExpressionNode* _assignmentExpression )
		: assignmentExpression( _assignmentExpression )
	{



	}

	inline ArgExpressionListNode( ArgExpressionListNode* _argumentExpressionList, AssignmentExpressionNode* _assignmentExpression )
		: assignmentExpression( _assignmentExpression ), argumentExpressionList( _argumentExpressionList )
	{

	}

	AssignmentExpressionNode* assignmentExpression;

	ArgExpressionListNode* argumentExpressionList;


	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "argument expression list" );

	}

	//~ArgExpressionListNode(){}

};


class PrimaryExpressionNode : public Node
{

public:

	inline PrimaryExpressionNode( IdentifierNode* _identifier ) : identifier( _identifier )
	{

	}

	inline PrimaryExpressionNode( ConstantNode* _constant ) : constant( _constant )
	{

	}

	inline PrimaryExpressionNode( StringNode* _string ) : string( _string )
	{

	}

	inline PrimaryExpressionNode( ExpressionNode* _expression ) : expression( _expression )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "primary expression" );

	}

	IdentifierNode* identifier;
	ConstantNode* constant;
	StringNode* string;
	ExpressionNode* expression;

};

class PostfixExpressionNode : public Node
{

public:

	enum PostfixExpressionType
	{
		PrimaryExpression,
		ArrayAccess,
		FunctionCall,
		DirectMemberAccess,
		PointerMemberAccess,
		Increment,
		Decrement
	};

	//Primary Expression
	inline PostfixExpressionNode( PrimaryExpressionNode* _primaryExpression )
		: primaryExpression( _primaryExpression )
	{
		type = PrimaryExpression;
	}

	//Array Access
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ExpressionNode* arrayExpression )
		: postfixExpression( _postfixExpression )
	{
		type = ArrayAccess;
	}

	//Function Call, No arguments =OR= Increment =OR= Dcrement
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , PostfixExpressionType _type )
		: postfixExpression( _postfixExpression ), type(_type)
	{

	}

	//Function Call, w/ arguments
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , ArgExpressionListNode* _argExpressionList )
		: postfixExpression( _postfixExpression ), argExpressionList( _argExpressionList )
	{
		type = FunctionCall;
	}

	//Direct Member Access
	inline PostfixExpressionNode( PostfixExpressionNode* _postfixExpression , IdentifierNode* _memberIdentifier , PostfixExpressionType _type )
		: postfixExpression( _postfixExpression ), memberIdentifier( _memberIdentifier ), type( _type )
	{
		type = DirectMemberAccess;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "postfix expression" );

	}

	PostfixExpressionType type;

	PrimaryExpressionNode* primaryExpression;
	PostfixExpressionNode* postfixExpression;
	ArgExpressionListNode* argExpressionList;
	IdentifierNode* memberIdentifier;
	ExpressionNode* arrayExpression;


};

class UnaryOperatorNode : public Node
{

public:

	enum UnaryOperatorType
	{
		Address,
		Indirection,
		Positive,
		Negative,
		BitwiseNot,
		LogicalNot

	};

	inline UnaryOperatorNode( UnaryOperatorType _type ) : type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "unary operator" );

	}

	UnaryOperatorType type;

};

class UnaryExpressionNode : public Node
{

public:

	enum UnaryExpressionType
	{
		Postfix,
		Increment,
		Decrement,
		Cast,
		SizeofExpression,
		SizeofType
	};

	inline UnaryExpressionNode( PostfixExpressionNode* _postfixExpression ) : postfixExpression( _postfixExpression )
	{
		type = Postfix;
	}

	inline UnaryExpressionNode( UnaryExpressionNode* _unaryExpression , UnaryExpressionType _type )
		: unaryExpression( _unaryExpression ), type(_type)
	{

	}

	inline UnaryExpressionNode( UnaryOperatorNode* _unaryOperator , CastExpressionNode* _castExpression )
				: unaryOperator( _unaryOperator ), castExpression(_castExpression)
	{
		type = Cast;
	}

	inline UnaryExpressionNode( TypeNameNode* _typeName )
					: typeName( _typeName )
	{
		type = SizeofType;
	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "unary operator" );

	}

	PostfixExpressionNode* postfixExpression;
	UnaryExpressionNode* unaryExpression;
	UnaryOperatorNode* unaryOperator;
	CastExpressionNode* castExpression;
	TypeNameNode* typeName;

	UnaryExpressionType type;

};

class CastExpressionNode : public Node
{

public:

	inline CastExpressionNode( UnaryExpressionNode* _unaryExpression ) : unaryExpression( _unaryExpression )
	{

	}

	inline CastExpressionNode( TypeNameNode* _typeName , CastExpressionNode* _castExpression )
		: typeName( _typeName ), castExpression(_castExpression)
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "unary operator" );

	}

	UnaryExpressionNode* unaryExpression;

	TypeNameNode* typeName;
	CastExpressionNode* castExpression;

};

class MultiplicativeExpressionNode : public Node
{

public:

	enum MultiplicativeExpressionType
	{
		Multiply,
		Divide,
		Modulo
	};

	inline MultiplicativeExpressionNode( CastExpressionNode* _castExpression ) : castExpression( _castExpression )
	{

	}

	inline MultiplicativeExpressionNode( MultiplicativeExpressionNode* _multiplicativeExpression ,
			CastExpressionNode* _castExpression ,
			MultiplicativeExpressionType _type
			)
		: multiplicativeExpression( _multiplicativeExpression ), castExpression(_castExpression), type( _type )
	{

	}

	inline std::vector< Operation > toOperations()
	{
		std::vector< Operation > operations;

		return operations;
	}

	//~PrimaryExpressionNode(){}

	inline std::string getNodeTypeAsString()
	{

		return std::string( "unary operator" );

	}

	CastExpressionNode* castExpression;
	MultiplicativeExpressionNode* multiplicativeExpression;
	MultiplicativeExpressionType type;


};

// TODO: This is temporary
class ExpressionNode : public Node
{

};

// TODO: This is temporary
class TypeNameNode : public Node
{

};


// ---------------------------------------------------------------------------
//

// TODO
static const size_t specs_size = 13;
const std::string specs[specs_size] = {
"void",
"char",
"short",
"int",
"long",
"float",
"double",
"signed",
"unsigned",
"struct",
"union",
"enum",
"typedef"
};

// Should be a singleton?
class TypeSpecifierNode : public Node {

private:
	// typedef int TypeSpecEnum;
	// TypeSpecEnum specifier;
	size_t specifier;
	// std::string specifier;

public:

	enum TypeSpecifierEnum {
		Void     = 0, TypeSpecifierStart = 0,
		Char     = 1, IntegralStart = 1,
		Short    = 2,
		Int      = 3,
		Long     = 4,
		Float    = 5,
		Double   = 6,
		Signed   = 7, IntegralEnd   = 7,
		Unsigned = 8,
		Struct   = 9,
		Union    = 10,
		Enum     = 11,
		Typedef  = 12,
		TypeSpecifierEnd
	};

public:

	std::vector<Operation> toOperations()
	{
		std::vector<Operation> emptyHack;
		return emptyHack;
	}

	std::string getNodeTypeAsString()
	{
		return "TypeSpecifier";
	}

	TypeSpecifierNode()
		: specifier(TypeSpecifierEnd)
	{}

	TypeSpecifierNode(const TypeSpecifierNode& o)
		: specifier(o.specifier)
	{}

	TypeSpecifierNode(std::string type) 
	{

		// std::cerr << "addTypeSpecifier(string): TODO" << std::endl;
		bool success = false;
		for (size_t spec = 0 ; spec<specs_size ; spec++) {
			if ( specs[ spec ] == type ) {
				success = true;
				this->specifier = (TypeSpecifierEnum) spec ;
				break;
			}
		}

		// error
		if ( ! success ) {
			error("TypeSpecifier is invalid. <" + type + "> given.");
		}
	}	
	
	TypeSpecifierNode(size_t specifier)
	{
		bool success = false;
		for ( size_t spec = TypeSpecifierStart ; spec < TypeSpecifierEnd; spec++ ) {
			if (specifier == spec) {
				success = true;
				this->specifier = (TypeSpecifierEnum) spec;
				break;
			}
		}
		// Error
		if ( ! success ) {
			std::string s( std::to_string( specifier ) );
			if ( specifier < specs_size ) {
				s = s + " " + specs[specifier];
			}
			error("TypeSpecifier is invalid. <" + s + "> given.");
		}
	}

	bool isIntegral()
	{
		for ( size_t integral = IntegralStart ; integral<IntegralEnd ; integral++ ) {
			if ( specifier == integral ) {
				return true;
			}
		}
		return false;
	}

	std::string toString()
	{	
		for (size_t spec = TypeSpecifierStart; spec < TypeSpecifierEnd; spec++ ) {
			if ( specifier == spec ) {
				return specs[spec];
			}
		}
		return "";
	}

private:
	void error(std::string error) 
	{
		std::cout << "TypeSpecifier Error : " << error << std::endl;
	}

};

// ---------------------------------------------------------------------------

// typedef std::string StorageSpecifierNode;
class StorageSpecifierNode {
private:
	int specifier;

const char specs[5][10] = {
	"auto",
	"register",
	"static",
	"extern",
	"typedef"
};

public:

	enum StorageSpecifierKind {
		Auto = 0,  StorageSpecifierKindStart = 0,
		Register,
		Static,
		Extern,
		Typedef, StorageSpecifierKindEnd = Typedef,
	};


	StorageSpecifierNode() {}
	// StorageSpecifierNode(const std::string& s) : s(s) {}
	StorageSpecifierNode(int storageSpecKind ) 
	{
		if ( StorageSpecifierKindStart  <= storageSpecKind && storageSpecKind <= StorageSpecifierKindEnd ) {
			specifier = storageSpecKind;
		}
		else {
			throw ParserError(ParserError::Whatever, "StorageSpecifierNode");
		}
	}

};

class TypeQualifierNode : public Node {
};

// ---------------------------------------------------------------------------

class DeclarationSpecifiersNode {

	typedef std::string TypeQualifierSymbol;

	std::vector<TypeSpecifierNode*> tSpecs;
	std::vector<StorageSpecifierNode*> sSpecs;
	std::vector<TypeQualifierNode*> qSpecs;
	
public:

	DeclarationSpecifiersNode( StorageSpecifierNode* s )
	{
		sSpecs.push_back(s);
	}

	DeclarationSpecifiersNode( StorageSpecifierNode* s, DeclarationSpecifiersNode* ds )
	{
		*this = *ds;		
		sSpecs.push_back(s);	
	}

	DeclarationSpecifiersNode( TypeSpecifierNode* ts  )
	{
		tSpecs.push_back( ts );
	}

	DeclarationSpecifiersNode( TypeSpecifierNode* ts, DeclarationSpecifiersNode* ds )
	{
		*this = *ds;
		tSpecs.push_back(ts);
	}

	DeclarationSpecifiersNode( TypeQualifierNode* ts )
	{
		qSpecs.push_back(ts);	
	}

	DeclarationSpecifiersNode( TypeQualifierNode*tq, DeclarationSpecifiersNode* ds)
	{
		*this = *ds;
		qSpecs.push_back(tq);
	}


// 	DeclarationSpecifiersNode() {}

// 	void addTypeSpecifier(TypeSpecifierNode t)
// 	{
// 		tSpecs.push_back(t);
// 	}

// 	void addStorageSpecifier(StorageSpecifierNode s)
// 	{
// 		sSpecs.push_back(s);
// 	}

// 	void addTypeQualifier(std::string s)
// 	{
// 		qSpecs.push_back(s);
// 	}

// 	bool determineType()
// 	{
// 		// TODO
// 		return true;
// 	}

	
};

#endif /* ASTNODES_H_ */
