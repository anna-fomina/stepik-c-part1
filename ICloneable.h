#pragma once

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
	T data_;
	ValueHolder(const T &value) : data_(value) {}
	ICloneable* clone() const {
		ICloneable * ptr = new ValueHolder(data_);
		return ptr;
	}
};

// Это класс, который вам нужно реализовать
class Any
{
public:
	Any() : obj_(0) {}

	template <class Type>
	Any(Type const & other) {
		obj_ = new ValueHolder<Type>(other);
	}

	~Any() {
		delete obj_;
	}

	Any(Any const & other) {
		obj_ = (other.obj_ != 0) ? other.obj_->clone() : 0;
	}

	template <class Type>
	Any& operator= (Type const &other) {
			delete obj_;
			obj_ = new ValueHolder<Type>(other);
			return *this;
	}

	Any& operator= (Any const &other) {
		if (other.obj_ != obj_) {
			delete obj_;
			obj_ = other.obj_->clone();
		}
		return *this;
	}

	template <class Type>
	Type * cast() {
		ValueHolder<Type> * ptr = dynamic_cast<ValueHolder<Type>*>(obj_);
		return (ptr != 0) ? &ptr->data_ : 0;
	}
private: 
	ICloneable * obj_;
};
