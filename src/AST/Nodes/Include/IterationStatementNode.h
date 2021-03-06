/*
 * IterationStatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ITERATIONSTATEMENTNODE_H_
#define ITERATIONSTATEMENTNODE_H_

#include "ExpressionNode.h"
#include "StatementNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class StatementNode;

class IterationStatementNode : public Node
{
public:

	enum IterationStatementType
	{
		While,
		DoWhile,
		For
	};

	IterationStatementNode( ExpressionNode* _condition , StatementNode* _statement, IterationStatementType _type );
	IterationStatementNode( ExpressionNode* _initialization ,ExpressionNode* _condition ,ExpressionNode* _increment ,StatementNode* _statement );
	ASTData* toOperations();
	std::string getNodeTypeAsString();
	~IterationStatementNode();

	ExpressionNode* condition = 0;

	ExpressionNode* initialization = 0;

	ExpressionNode* increment = 0;

	StatementNode* statement = 0;

	IterationStatementType type;

};


#endif /* ITERATIONSTATEMENTNODE_H_ */
