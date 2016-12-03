#pragma once
#include "Error_Handling.hpp"
//struct check_for_error
//{
#pragma message("ToDo Perhaps instead of struct only function would suffice?")
#pragma message("ToDo Also, perhaps adding type to throw in form of an enum would be useful?")
	inline void check_for_error(const int res)
	{
		if (LIBGIT2_CPP_FAIL_CHECK(res))
		{
			throw static_cast<git_error_code>(res);
		}
	}
	template<class T>
	inline void check_for_nullptr(T* p)
	{
		if (LIBGIT2_CPP_FAIL_CHECK(p))
		{
			throw nullptr_t();
		}
	}
//};