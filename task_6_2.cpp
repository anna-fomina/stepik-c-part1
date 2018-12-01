#include <cstddef>
#include <iostream>
#include "array.h"
#include "ICloneable.h"


template <typename T, typename U>
void copy_n(T * ar1, U * ar2, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		ar1[i] = (T) ar2[i];
	}
}

template<class T, class Comp>
T minimum(const Array<T> & ar, Comp less) {
	T min = ar[0];
	for (size_t i = 1; i < ar.size(); ++i) {
		if (less(ar[i], min)) {
			min = ar[i];
		}
	}
	return min;
}

template <typename T>
void flatten(const T &array, std::ostream& out) {
	out << array << " ";
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out) {
	for (size_t i = 0; i < array.size(); ++i) {
		flatten(array[i], out);
	}
}


void task_6_2() {
	//int ints[] = { 1, 2, 3, 4 };
	//double doubles[4] = {1.1, 2.2, 3.3, 5.8};
	//for (size_t i = 0; i < 4; ++i) {
	//	std::cout << doubles[i] << std::endl;
	//}
	//copy_n(ints, doubles, 4); // теперь в массиве doubles содержатся элементы 1.0, 2.0, 3.0 и 4.0
	//for (size_t i = 0; i < 4; ++i) {
	//	std::cout << ints[i] << std::endl;
	//}

	//Array<int> ints(2, 0);
	//ints[0] = 10;
	//ints[1] = 20;
	////flatten(ints, std::cout); // выводит на экран строку "10 20"
	//Array< Array<int> > array_of_ints(2, ints);
	//flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"

	Any i(10);
	Any empty;
	Any a(22.5);
	Any copy(i); // copy хранит 10, как и i
	empty = copy; // empty хранит 10, как и copy
	empty = 0; // а теперь empty хранит 0
	int *iptr = i.cast<int>(); // *iptr == 10
	char *cptr = i.cast<char>(); // cptr == 0,
	Any empty2;
	int *p = empty2.cast<int>(); // p == 0
	return;
}