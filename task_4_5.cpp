#include <iostream>
#include "expression.h"

struct PrintBinaryOperationsVisitor : Visitor {
	void visitNumber(Number const * number)
	{ }

	void visitBinaryOperation(BinaryOperation const * bop)
	{
		bop->get_left()->visit(this);
		std::cout << bop->get_op() << " ";
		bop->get_right()->visit(this);
	}
};

struct PrintVisitor : Visitor {
	void visitNumber(Number const * number)
	{
		std::cout << number->get_value() << " ";
	}

	void visitBinaryOperation(BinaryOperation const * bop)
	{
		std::cout << "( ";
		bop->get_left()->visit(this);
		std::cout << bop->get_op() << " ";
		bop->get_right()->visit(this);
		std::cout << ") ";
	}
};

void task_4_5() {
	Expression * sube = new BinaryOperation(new Number(4.5), '+', new Number(5));
	// потом используем его в выражении для +
	Expression * expr = new BinaryOperation(new Number(3), '*', sube);
	Expression * numb = new Number(8);

	PrintVisitor visitor;
	expr->visit(&visitor);

	return;
}