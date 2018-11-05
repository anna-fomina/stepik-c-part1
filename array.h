#pragma once

#include <cstddef>

template <typename T>
class Array
{
public:

	explicit Array(size_t size, const T& value = T()) : size_(size), data_((T*) new char[size_ * sizeof(T)]) {
		for (size_t i = 0; i < size_; ++i) {
			new (data_ + i) T(value);
		}
	}

	Array() : size_(0), data_(0) {}

	Array(const Array & other) : size_(other.size_), data_((T*) new char[size_ * sizeof(T)]) {
		for (size_t i = 0; i < size_; ++i) {
			new (data_ + i) T(other.data_[i]);
		}
	}

	~Array() {
		for (size_t i = 0; i < size_; ++i) {
			data_[i].~T();
		}
		delete[](char*) data_;
	}
	Array& operator= (const Array & other) {
		if (data_ != other.data_) {
			delete[](char*) data_;
			size_ = other.size_;
			data_ = (T*) new char[size_ * sizeof(T)];
			for (size_t i = 0; i < size_; ++i) {
				new (data_ + i) T(other.data_[i]);
			}
		}
		return *this;
	}
	size_t size() const {
		return size_;
	}
	T& operator[](size_t n) {
		return data_[n];
	}
	const T& operator[](size_t n) const {
		return data_[n];
	}
	void prnt()
	{
		for (size_t i = 0; i < size_; ++i)
			cout << *(data_ + i);
		cout << endl;
	}
private:
	size_t size_;
	T * data_;
};
