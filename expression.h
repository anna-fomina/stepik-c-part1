#pragma once

struct Number;
struct BinaryOperation;

struct Visitor {
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
	virtual ~Visitor() { }
};

struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor * vistitor) const = 0;
	virtual ~Expression() {}
};

struct Number : Expression
{
	Number(double value) : value(value) {}
	double evaluate() const {
		return value;
	}
	double get_value() const { return value; }
	void visit(Visitor * visitor) const { visitor->visitNumber(this); }
private:
	double value;
};

struct BinaryOperation : Expression
{
	BinaryOperation(Expression const * left, char op, Expression const * right)
		: left(left), op(op), right(right)
	{ }
	double evaluate() const {
		switch (op) {
		case '+': {
			return left->evaluate() + right->evaluate();
		}
		case '-': {
			return left->evaluate() - right->evaluate();
		}
		case '*': {
			return left->evaluate() * right->evaluate();
		}
		case '/': {
			return left->evaluate() / right->evaluate();
		}
		default: return 0;
		}
	}
		Expression const * get_left() const { return left; }
		Expression const * get_right() const { return right; }
		char get_op() const { return op; }

		void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }
	~BinaryOperation() {
		delete left;
		delete right;
	}

private:
	Expression const * left;
	Expression const * right;
	char op;
};
