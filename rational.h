#pragma once
#include "nod_nok.h"

struct Rational
{
	Rational(int numerator = 0, int denominator = 1) : 
		numerator_(numerator), denominator_(denominator) {}

	void add(Rational rational);
	void sub(Rational rational);
	void mul(Rational rational);
	void div(Rational rational);

	void neg();
	void inv();
	double to_double() const;

	int get_numerator() const;
	int get_denominator() const;

	Rational& operator+=(Rational rational);
	Rational& operator-=(Rational rational);
	Rational& operator*=(Rational rational);
	Rational& operator/=(Rational rational);

	Rational operator-() const;
	Rational operator+() const;
	operator double() const;

private:
	int numerator_;
	int denominator_;
};

void Rational::add(Rational rational) {
	int nok = NOK(denominator_, rational.denominator_);
	numerator_ = numerator_ * nok / denominator_ + rational.numerator_ * nok / rational.denominator_;
	denominator_ = nok;
}

void Rational::sub(Rational rational) {
	int nok = NOK(denominator_, rational.denominator_);
	numerator_ = numerator_ * nok / denominator_ - rational.numerator_ * nok / rational.denominator_;
	denominator_ = nok;
}

void Rational::mul(Rational rational) {
	numerator_ *= rational.numerator_;
	denominator_ *= rational.denominator_;
	int nod = NOD(numerator_, denominator_);
	numerator_ /= nod;
	denominator_ /= nod;
}

void Rational::div(Rational rational) {
	if (rational.numerator_) {
		Rational inv_rational = rational;
		inv_rational.inv();
		this->mul(inv_rational);
	}
}

int Rational::get_numerator() const{
	return numerator_;
}

int Rational::get_denominator() const {
	return denominator_;
}

void Rational::neg() {
	numerator_ = -numerator_;
}

void Rational::inv() {
	int temp = numerator_;
	numerator_ = denominator_;
	denominator_ = temp;
}

Rational& Rational::operator+= (Rational rational) {
	this->add(rational);
	return *this;
}

Rational& Rational::operator-= (Rational rational) {
	this->sub(rational);
	return *this;
}

Rational& Rational::operator*= (Rational rational) {
	this->mul(rational);
	return *this;
}

Rational& Rational::operator/= (Rational rational) {
	this->div(rational);
	return *this;
}

Rational Rational::operator- () const {
	Rational temp = *this;
	temp.neg();
	return temp;
}

Rational Rational::operator+ () const {
	return *this;
}

Rational operator+ (Rational r1, Rational const& r2) {
	return r1 += r2;
}

Rational operator- (Rational r1, Rational const& r2) {
	return r1 -= r2;
}

Rational operator* (Rational r1, Rational const& r2) {
	return r1 *= r2;
}

Rational operator/ (Rational r1, Rational const& r2) {
	return r1 /= r2;
}

bool operator== (Rational const& r1, Rational const& r2) {
	return (r1.get_numerator() == r2.get_numerator()) && (r1.get_denominator() == r2.get_denominator());
}

bool operator!= (Rational const& r1, Rational const& r2) {
	return !(r1 == r2);
}

bool operator< (Rational const& r1, Rational const& r2) {
	return ((r1 - r2).get_numerator() < 0);
}

bool operator> (Rational const& r1, Rational const& r2) {
	return (r2 < r1);
}

bool operator<= (Rational const& r1, Rational const& r2) {
	return !(r2 < r1);
}

bool operator>= (Rational const& r1, Rational const& r2) {
	return !(r1 < r2);
}

double Rational::to_double() const {
	return (double)numerator_ / denominator_;
}

Rational::operator double() const {
	return this->to_double();
}