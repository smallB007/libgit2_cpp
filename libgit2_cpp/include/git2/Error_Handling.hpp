#pragma once
template<class T>
inline constexpr bool LIBGIT2_CPP_FAIL_CHECK(const T val)
{
	return (val < 0);
}

template<class T>
inline constexpr bool LIBGIT2_CPP_FAIL_CHECK(const T* const ptr)
{
	return nullptr == ptr;
}

