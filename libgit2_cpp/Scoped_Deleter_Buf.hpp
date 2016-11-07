#pragma once
template<class T>
class Scoped_Deleter_Buf
{
	T* c_git_type_;
public:
	Scoped_Deleter_Buf(const size_t size)
	{
		c_git_type_ = new T[size];
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
};