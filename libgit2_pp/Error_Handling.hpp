#pragma once
template<class T>
inline bool FAILED(T val)
{
	return (val < 0);
}

template<class T>
inline bool FAILED(T* ptr)
{
	return nullptr == ptr;
}

