/*
 * ConditionalExpressionNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#include "ConditionalExpressionNode.h"

ConditionalExpressionNode::ConditionalExpressionNode( LogicalOrExpressionNode* _logicalOrExpression ) : logicalOrExpression( _logicalOrExpression )
{

}

ConditionalExpressionNode::ConditionalExpressionNode(
		LogicalOrExpressionNode* _logicalOrExpression,
		ExpressionNode* _expression,
		ConditionalExpressionNode* _conditionalExpression
	) : logicalOrExpression( _logicalOrExpression ), expression(_expression), conditionalExpression(_conditionalExpression)
{

}


std::vector< Operation* >* ConditionalExpressionNode::toOperations()
{
	std::vector< Operation* >* operations;

	return operations;
}

std::string ConditionalExpressionNode::getNodeTypeAsString()
{

	return std::string( "conditional expression" );

}

ConditionalExpressionNode::~ConditionalExpressionNode()
{

}

