#pragma once

#include <algorithm> // std::swap
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct StringCut;

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
	~String();

	String &operator=(const String &other);

	void append(const String &other);
	void swap(String &other);

	StringCut operator[] (size_t n) const;

	size_t size;
	char *str;
};

String::String(const char *str) {
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy(this->str, str);
}

String::String(size_t n, char c) : size(n), str(new char[size + 1]) {
	for (size_t i = 0; i < n; ++i) {
		*(str + i) = c;
	}
	*(str + n) = '\0';
}

String::~String() {
	delete[] str;
}

void String::append(const String &other) {
	size += other.size;

	char* temp = new char[size + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
}

String::String(const String &other) : String(other.str)
{}

String& String::operator=(const String &other) {
	String(other).swap(*this);
	return *this;
}

void String::swap(String &other) {
	std::swap(size, other.size);
	std::swap(str, other.str);
}

struct StringCut {
	StringCut(String str, size_t n) : s(str), begin(n) {}

	String operator[] (size_t n) const {
		char * str = new char[n - begin + 1];
		for (int i = 0; i < n - begin; ++i) {
			str[i] = s.str[i];
		}
		str[n - begin] = '\0';
		String cut(str);
		delete[] str;
		return cut;
	}

	size_t begin;
	String s;
};

StringCut String::operator[] (size_t n) const {
	char * cut = new char[size - n + 1];
	for (int i = n; i < size; ++i) {
		cut[i - n] = str[i];
	}
	cut[size - n] = '\0';
	
	String sCut(cut);
	delete[] cut;
	return StringCut(sCut, n);
}
