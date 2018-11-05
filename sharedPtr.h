#pragma once
#include "expression.h"

struct CountPtr {
	CountPtr(int count = 0) : count_(count) {}
	void add() {
		++count_;
	}
	void sub()
	{
		--count_;
	}
	int get() {
		return count_;
	}
private:
	int count_;
};

struct SharedPtr
{
	explicit SharedPtr(Expression *ptr = 0) : ptr_(ptr) {
		count_ = new CountPtr(1);
	}
	~SharedPtr() {
		count_->sub();
		if (count_->get() == 0) {
			delete ptr_;
			delete count_;
		}
	}
	SharedPtr(const SharedPtr & sptr) {
		ptr_ = sptr.ptr_;
		count_ = sptr.count_;
		count_->add();
	}
	SharedPtr& operator=(const SharedPtr & sptr) {
		if (ptr_ != sptr.ptr_) {
			count_->sub();
			if (count_->get() == 0) {
				delete ptr_;
				delete count_;
			}
			ptr_ = sptr.ptr_;
			count_ = sptr.count_;
			count_->add();
		}
		return *this;
	}
	Expression* get() const {
		return ptr_;
	}
	void reset(Expression *ptr = 0) {
		if (ptr_ != ptr) {
			count_->sub();
			if (count_->get() == 0) {
				delete ptr_;
				delete count_;
			}
			ptr_ = ptr;
			count_ = new CountPtr(1);
		}
	}
	Expression& operator*() const {
		return *ptr_;
	}
	Expression* operator->() const {
		return ptr_;
	}
private:
	Expression * ptr_;
	CountPtr * count_;
};