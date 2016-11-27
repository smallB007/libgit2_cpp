#pragma once
#include "precompiled.hpp"

enum E_MEM_MANAGEMENT{NO,YES};
template<E_MEM_MANAGEMENT>
struct Memory_Management
{};

template<class c_git_class, class mem_management = Memory_Management<YES>>
class Guts_Provider 
{
		c_git_deleter_t<c_git_class> c_git_class_deleter_;
protected:
	c_git_class* c_guts_{};
public:
	c_git_class* c_guts() const { return c_guts_; }
	operator c_git_class*() const { return c_guts_; }
	
	Guts_Provider(c_git_class* c_ptr, c_git_deleter_t<c_git_class> c_git_class_deleter) :c_guts_{c_ptr},
																							c_git_class_deleter_(NMS::move(c_git_class_deleter))
	{
	}
	~Guts_Provider()
	{
		if (c_git_class_deleter_)
		{
			c_git_class_deleter_((c_guts_));
			c_guts_ = nullptr;
		}
	}
};

template<class c_git_class>
class Guts_Provider<c_git_class, Memory_Management<NO>>
{
protected:
	c_git_class c_guts_;
public:
	const c_git_class* c_guts() const { return &c_guts_; }
	c_git_class* c_guts() { return &c_guts_; }
	operator c_git_class*(){ return &c_guts_; }
	operator const c_git_class*()const { return &c_guts_; }
};

template<class T>
T c_guts(const Guts_Provider<T>& git_object)
{
	return git_object.c_guts();
}