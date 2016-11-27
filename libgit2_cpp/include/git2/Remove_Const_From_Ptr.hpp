#pragma once
template<class Const_Pointer>
struct Remove_Const_From_Ptr
{
	/*In order to get:
	int from const int*
	First you have to remove pointer and then remove const and then add back pointer.
	Step by step:
	1. We've got const int* applying std::remove_pointer gives us const int
	2. On const int applying std::remove_const give us int
	3. On int applying std::add_pointer give us int*
	*/
	using type = typename std::add_pointer<typename std::remove_const<typename std::remove_pointer<Const_Pointer>::type>::type>::type;
};

template<class T>
using non_const_generic_ptr_ = typename Remove_Const_From_Ptr<T>::type;