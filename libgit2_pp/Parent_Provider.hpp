#pragma once
#include "stdafx.h"

class Parent_Provider
{
	static NMS::shared_ptr<Git_Repo> parent_;
public:
	NMS::shared_ptr<Git_Repo> get_parent()const;
	git_repository* c_parent_guts()const; 
};

//Git_Repo* Parent_Provider::Git_Repo_ = Git_Repo::GetInstance();