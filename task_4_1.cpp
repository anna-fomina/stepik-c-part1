#include <iostream>


struct Foo {
     void say() const { std::cout << "Foo says: " << msg << "\n"; }
 protected:
	 Foo(const char *msg) : msg(msg) { std::cout << "Foo constructor" << std::endl; }
 private:
     const char *msg;
 };

void foo_says(const Foo &foo) { foo.say(); }

struct NewFoo : Foo {
	NewFoo(const char *msg) : Foo(msg) { }
	~NewFoo() {
		std::cout << "NewFoo destructor" << std::endl;
	}
};



Foo get_foo(const char *msg) {
	return NewFoo(msg);
}


void task_4_1() {
	std::cout << "Task 1" << std::endl;

	//NewFoo a("Hello");

	foo_says(get_foo("Hello!"));

	return;
}