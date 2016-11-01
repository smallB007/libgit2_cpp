#pragma once
#include "stdafx.h"

template<class c_git_class>
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
			c_git_class_deleter_(c_git_guts_);
			c_git_guts_ = nullptr;
		}
	}
};
