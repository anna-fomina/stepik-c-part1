#include <iostream>
#include "sharedPtr.h"



void task_5_3() {
	Expression * sube = new BinaryOperation(new Number(4.5), '+', new Number(5));
	// ����� ���������� ��� � ��������� ��� +
	Expression * expr = new BinaryOperation(new Number(3), '*', sube);
	Expression * numb = new Number(8);

	SharedPtr a(expr);
	SharedPtr b(a);
	SharedPtr c = a;

	return;
}