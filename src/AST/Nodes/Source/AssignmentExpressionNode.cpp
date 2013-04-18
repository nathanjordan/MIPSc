/*
 * AssignmentExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "AssignmentExpressionNode.h"
#include "IdTracker.h"
#include "AssignOp.h"

AssignmentExpressionNode::AssignmentExpressionNode( ConditionalExpressionNode* _conditionalExpression ) : conditionalExpression( _conditionalExpression )
{

}

AssignmentExpressionNode::AssignmentExpressionNode(
		UnaryExpressionNode* _unaryExpression,
		AssignmentOperatorNode* _assignmentOperator,
		AssignmentExpressionNode* _assignmentExpression
	) : unaryExpression( _unaryExpression ), assignmentOperator(_assignmentOperator), assignmentExpression(_assignmentExpression)
{

}


ASTData* AssignmentExpressionNode::toOperations()
{
	ASTData* data = new ASTData();

	if( assignmentOperator == 0 )

		return conditionalExpression->toOperations();

	if( assignmentOperator->type == AssignmentOperatorNode::Assign )
	{

		ASTData* data = new ASTData();

		std::vector< Operation* >* operations = new std::vector< Operation* >();

		//Gets the data for the first parameter
		ASTData* unaryData = unaryExpression->toOperations();

		//gets the data for the second parameter
		ASTData* assignmentExpressionData = assignmentExpression->toOperations();

		//create a new temporary name
		std::string tempName = std::string("t") + std::to_string( IdTracker::getInstance()->getId() );

		//get the name of the first parameters temporary
		Symbol* unaryResult = unaryData->result;

		//get the name of the second parameters temporary
		Symbol* assignmentExpressionResult = assignmentExpressionData->result;

		//create a new temporary for our result
		Symbol* temporary = new Symbol( tempName , *new SymbolLocation() , unaryResult->symbolType );

		//create a new operation to compute the addition
		AssignOp* op = new AssignOp( temporary , assignmentExpressionResult , assignmentOperator->type );

		//Add the multiplicative operations to what we will return
		operations->insert( operations->end() , unaryData->code->begin() , unaryData->code->end() );

		//add the additive the multiplicative operations to what we will return
		operations->insert( operations->end() , assignmentExpressionData->code->begin() , assignmentExpressionData->code->end() );

		//Add our 'add' operation to the end of the list
		operations->push_back( op );

		//add the result of this expression to the data
		data->result = temporary;

		//add the code used to compute this result
		data->code = operations;

		//return the result
		return data;

	}

	return data;
}

std::string AssignmentExpressionNode::getNodeTypeAsString()
{

	return std::string( "conditional expression" );

}

AssignmentExpressionNode::~AssignmentExpressionNode() {}

