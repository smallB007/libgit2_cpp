#pragma once
#include "precompiled.hpp"
class Git_RefDB
{
	git_refdb* c_git_refdb_{};
public:
	operator git_refdb*()const { return c_git_refdb_; }
	git_refdb* c_guts()const { return c_git_refdb_; }
	Git_RefDB(git_repository* c_git_repo);
	~Git_RefDB();
};

