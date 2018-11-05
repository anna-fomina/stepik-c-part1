#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include "string.h"
#include "rational.h"


void task_5_1() {
	//Rational a(1, 2);
	//Rational b(1, 4);
	//Rational c = 7 + 2;
	////a = b;
	//std::cout << c.get_numerator() << " " << c.get_denominator() << std::endl;
	//std::cout << ((double)a) << std::endl;

	String const hello("hello");
	std::cout << hello.str << std::endl;
	String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
	String const ell = hello[1][1]; // теперь в ell хранится подстрока "ell"
	std::cout << hell.str << " " << ell.str << std::endl;
	return;
}