/*
 * JumpStatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef JUMPSTATEMENTNODE_H_
#define JUMPSTATEMENTNODE_H_

#include "ExpressionNode.h"
#include "IdentifierNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class JumpStatementNode : public Node
{

public:

	enum JumpStatementType
	{
		Goto,
		Continue,
		Break,
		Return
	};

	JumpStatementNode( ExpressionNode* _expression );
	JumpStatementNode( IdentifierNode* _identifier );
	JumpStatementNode( JumpStatementType _type );
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	IdentifierNode* identifier;
	ExpressionNode* expression;
	JumpStatementType type;

};


#endif /* JUMPSTATEMENTNODE_H_ */
