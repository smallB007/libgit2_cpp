#pragma once
#include "precompiled.hpp"
template<class Git_Class>
class Factory_Git_Object
{
public:
	template<class... Args>
	static shared_ptr_t<Git_Class> create_ptr(Args... args)
	{
		typedef typename Git_Class::Git_Deleter deleter;
		auto ptr = new Git_Class(args...);
		shared_ptr_t<Git_Class> shared;
		shared.reset(ptr,deleter());

		return shared;
	}

	template<class... Args>
	static Git_Class create(Args... args)
	{
		return Git_Class(args...);
	}
};