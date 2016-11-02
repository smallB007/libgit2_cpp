#pragma once
#include "stdafx.h"
class Parent_Provider 
{
	static shared_ptr_t<Git_Repo> parent_;
public:
	shared_ptr_t<Git_Repo> get_parent()const;
	git_repository* c_parent_guts()const; 
};

//Git_Repo* Parent_Provider::Git_Repo_ = Git_Repo::GetInstance();