#pragma once
#include "precompiled.hpp"
template<class T = git_buf>
class Scoped_Deleter_Buf
{
	T* c_git_type_;
	size_t size_;
#pragma message("Warning perhaps instead of using this class simply create object of buf class on stack(non-ptr)")
public:
	Scoped_Deleter_Buf(const size_t size)
	{
		size_ = size;
		c_git_type_ = new T[size_];
	}

	operator T*()const { return c_git_type_; }

	~Scoped_Deleter_Buf()
	{
		delete[] c_git_type_;
		c_git_type_ = nullptr;
	}

	string_t get_string()const
	{
		char* char_ptr = reinterpret_cast<char*>(c_git_type_);
		return char_ptr;
	}

	const T* const get_raw_data()const
	{
		return c_git_type_;
	}

	template<class A = T>
	const A* const get_type()const
	{
		return reinterpret_cast<A*>(c_git_type_);
	}
	size_t size()const
	{
		return size_;
	}
};