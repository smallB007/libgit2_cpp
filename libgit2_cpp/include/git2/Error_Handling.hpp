#pragma once
template<class T>
inline constexpr bool LIBGIT2_CPP_FAIL_CHECK(T val)
{
	return (val < 0);
}

template<class T>
inline constexpr bool LIBGIT2_CPP_FAIL_CHECK(T* ptr)
{
	return nullptr == ptr;
}

