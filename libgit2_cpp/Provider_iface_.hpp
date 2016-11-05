#pragma once
//#include "Parent_Provider.hpp"
//#include "Guts_Provider.hpp"
//#include "Git_Object.hpp"

#include "Git_Object.hpp"

template<class c_git_class_t>
class Provider : public Git_Object<c_git_class_t>
{
public:
	typedef c_git_class_t c_git_class;
	Provider(c_git_class_t* c_git_class_object, c_git_deleter_t<c_git_class_t> c_git_class_deleter);
};


