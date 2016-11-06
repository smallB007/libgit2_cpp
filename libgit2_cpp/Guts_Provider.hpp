#pragma once
#include "stdafx.h"
#include <type_traits>

//template<class c_git_class, bool management>
//class Guts
//{
//protected:
//	std::conditional<management, c_git_class*,c_git_class>::type  c_git_guts_;
//public:
//	c_git_class* c_guts() { return &c_git_guts_; }
//	operator c_git_class*() const { return &c_git_guts_; }
//};

template<class c_git_class, bool mem_management = true>
class Guts_Provider 
{
		c_git_deleter_t<c_git_class> c_git_class_deleter_;
protected:
	c_git_class* c_git_guts_{};
public:
	c_git_class* c_guts() const { return c_git_guts_; }
	operator c_git_class*() const { return c_git_guts_; }
	
	Guts_Provider(c_git_deleter_t<c_git_class> c_git_class_deleter):
																c_git_class_deleter_(NMS::move(c_git_class_deleter))
	{

	}
	~Guts_Provider()
	{
		if (c_git_class_deleter_)
		{
			c_git_class_deleter_(const_cast<c_git_class*>(c_git_guts_));
			c_git_guts_ = nullptr;
		}
	}
};
//struct No_Mem_Management
//{};
template<class c_git_class>
class Guts_Provider<c_git_class,false>//: public Guts<c_git_class>
{
protected:
	c_git_class c_git_guts_;
public:
	c_git_class* c_guts() { return &c_git_guts_; }
	operator c_git_class*() const { return &c_git_guts_; }
};