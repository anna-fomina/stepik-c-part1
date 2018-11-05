#include "expression.h"
#include <iostream>

bool check_equals(Expression const *left, Expression const *right)
{
	std::cout << *((void **)left) << std::endl;
	std::cout << *((void **)left) << std::endl;
	return (*((void **)left) == *((void **)right));
}

void task_4_4() {
	Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	// потом используем его в выражении для +
	Expression * expr = new BinaryOperation(new Number(3), '+', sube);
	Expression * numb = new Number(8);

	check_equals(sube, numb);

	// вычисляем и выводим результат: 25.5
	std::cout << expr->evaluate() << std::endl;

	delete expr;

	return;
}