/*
 * CompoundStatementNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef COMPOUNDSTATEMENTNODE_H_
#define COMPOUNDSTATEMENTNODE_H_

#include "DeclarationListNode.h"
#include "StatementListNode.h"

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

class DeclarationListNode;
class StatementListNode;

class CompoundStatementNode : public Node
{

public:

	CompoundStatementNode( DeclarationListNode* _declarationList );

	CompoundStatementNode( StatementListNode* _statementList );

	CompoundStatementNode( DeclarationListNode* _declarationList , StatementListNode* _statementList);

	std::vector< Operation* >* toOperations();

	std::string getNodeTypeAsString();

	DeclarationListNode* declarationList;

	StatementListNode* statementList;

};


#endif /* COMPOUNDSTATEMENTNODE_H_ */