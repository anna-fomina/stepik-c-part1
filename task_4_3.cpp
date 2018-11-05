#include <iostream>
#include "expression.h"


void task_4_3() {
	std::cout << "Task 3" << std::endl;

	// ������� ������ ������� ��� ������������ 4.5 * 5
	Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	// ����� ���������� ��� � ��������� ��� +
	Expression * expr = new BinaryOperation(new Number(3), '+', sube);

	// ��������� � ������� ���������: 25.5
	std::cout << expr->evaluate() << std::endl;

	// ��� ������������� *���* ���������� �������
	// (��������, sube ����� ������ ��������� expr, ������� ��� ������� �� �����)
	delete expr;

	return;
}

