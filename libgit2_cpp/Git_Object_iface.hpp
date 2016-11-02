#pragma once
#include "stdafx.h"
#include "Guts_Provider.hpp"
#include "Parent_Provider.hpp"
template<class T>
class Git_Object : public Guts_Provider<T>, public Parent_Provider
{
public:
	Git_Object(T* c_git_object, c_git_deleter_t<T> c_git_class_deleter);
};


