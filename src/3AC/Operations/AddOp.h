/*
 * Add.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef ADDOP_H_
#define ADDOP_H_

#include "Operation.h"

#include "AdditiveExpressionNode.h"

class AddOp: public Operation {

public:

	inline AddOp( Operand* result , Operand* first , Operand* second , AdditiveExpressionNode::AdditiveExpressionType _type )
		: Operation( result, first, second ), type(_type)
	{

	}

	std::string to3AC()
	{

		if( type == AdditiveExpressionNode::Add )

			return op1->getId() + " = " + op2->getId() + " + " + op3->getId();

		else

			return op1->getId() + " = " + op2->getId() + " - " + op3->getId();

	}

	AdditiveExpressionNode::AdditiveExpressionType type;

};

#endif /* ADDOP_H_ */