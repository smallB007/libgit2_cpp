#pragma once
#include "Provider_iface_.hpp"
template<class c_git_class>
inline Provider<c_git_class>::Provider(c_git_class* c_git_class_object, c_git_deleter_t<c_git_class> c_git_class_deleter) : Git_Object(c_git_class_object, c_git_class_deleter)
{}
