#pragma once
#include "precompiled.hpp"
template<class Git_Class>
class Factory_Git_Object
{
public:
	template<class... Args>
	static shared_ptr_t<Git_Class> create(Args... args)
	{
		return make_shared_ver<Git_Class>(args...);
	}
};