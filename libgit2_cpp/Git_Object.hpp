#pragma once
#include "Git_Object_iface.hpp"

template<class T>
inline Git_Object<T>::Git_Object(T * c_git_object, c_git_deleter_t<T> c_git_class_deleter):Guts_Provider(c_git_object,NMS::move(c_git_class_deleter))
{
	/*c_guts_ = c_git_object ;*/
}


