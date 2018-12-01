#include <iostream>
#include "SameType.h"

struct Dummy { };
typedef int type;

void task_6_3() {
	std::cout << SameType<int, int>::value << std::endl; // ������� 1, �. �. true
	std::cout << SameType<int, type>::value << std::endl; // 1, type == int
	std::cout << SameType<int, int&>::value << std::endl; // 0, int � ������ �� int - ��������� ����
	std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
	std::cout << SameType<int, const int>::value << std::endl; // 0, const - ����� ����
	return;
}