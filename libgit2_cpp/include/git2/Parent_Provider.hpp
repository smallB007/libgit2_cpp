#pragma once
#include "precompiled.hpp"
class Parent_Provider 
{
	friend class Merging_Engine;
	static shared_ptr_t<Git_Repo> parent_;
public:
	static shared_ptr_t<Git_Repo> get_parent();
	static git_repository* c_parent_guts(); 
};

//Git_Repo* Parent_Provider::Git_Repo_ = Git_Repo::GetInstance();