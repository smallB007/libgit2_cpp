#pragma once
#include "Error_Handling.hpp"
//struct check_for_error
//{
#pragma message("ToDo Perhaps instead of struct only function would suffice?")
#pragma message("ToDo Also, perhaps adding type to throw in form of an enum would be useful?")
	inline void check_for_error(int res)
	{
		if (FAILED(res))
		{
			throw - 1;
		}
	}
	template<class T>
	inline void check_for_nullptr(T* p)
	{
		if (FAILED(p))
		{
			throw - 1;
		}
	}
//};