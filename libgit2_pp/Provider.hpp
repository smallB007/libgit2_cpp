#pragma once
#include "Parent_Provider.hpp"
#include "Guts_Provider.hpp"

template<class c_git_class>
class Provider : public Guts_Provider<c_git_class>, public Parent_Provider
{
public:
	Provider(c_git_deleter_t<c_git_class> c_git_class_deleter):Guts_Provider(NMS::move(c_git_class_deleter))
	{}
};