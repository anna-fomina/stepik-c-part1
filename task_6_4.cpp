#include <cstddef> // size_t

// ���������� ��������� ������� array_size,
// ������� ���������� �������� ���� size_t.

// put your code here
template <class T, size_t N>
size_t array_size(T(&array)[N]) {
	return N;
}

void task_6_4() {
	int ints[] = { 1, 2, 3, 4 };
	int *iptr = ints;
	double doubles[] = { 3.14 };
	array_size(ints); // ������ 4
	array_size(doubles); // ������ 1
	//array_size(iptr); // ��� ������ ��������� ������ ����������
	return;
}