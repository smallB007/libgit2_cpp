#pragma once
#include "stdafx.h"
#include "Guts_Provider.hpp"
#include "Parent_Provider.hpp"
template<class T>
class Git_Object : public Guts_Provider<T>, public Parent_Provider
{
public:
	Git_Object(const T* c_git_object, c_git_deleter_t<T> c_git_class_deleter);

	shared_ptr_t<Git_Object> duplicate()const;
	shared_ptr_t<Git_Object_ID> id()const;
	shared_ptr_t<Git_Object> lookup(const Git_Object_ID&, git_otype)const;
	shared_ptr_t<Git_Object> lookup_by_path(const Git_Object&, const path_name_t& path, git_otype)const;
	shared_ptr_t<Git_Object<T>> Git_Object<T>::lookup_by_prefix(const Git_Object_ID& id, size_t len, git_otype type)const;
	shared_ptr_t<Git_Repo> owner()const;
	shared_ptr_t<Git_Object> peel(git_otype target_type)const;
	shared_ptr_t<Git_Buf> short_id()const;
	git_otype string_2_type(const string_t&)const;
	git_otype type()const;
	string_t type_2_string()const;
	bool is_loose_type()const;
};


