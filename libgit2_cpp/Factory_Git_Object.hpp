#pragma once
#include "stdafx.h"
template<class Git_Class>
class Factory_Git_Object
{
public:
	template<class... Args>
	static shared_ptr_t<Git_Class> create(Args... args)
	{
		typename Git_Class::c_git_class* c_git_class_out;
		return make_shared_ver<Git_Class>(c_git_class_out, args...);
	}
};