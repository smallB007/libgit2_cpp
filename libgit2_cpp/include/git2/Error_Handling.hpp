#pragma once
template<class T>
inline constexpr bool FAILED(T val)
{
	return (val < 0);
}

template<class T>
inline constexpr bool FAILED(T* ptr)
{
	return nullptr == ptr;
}

