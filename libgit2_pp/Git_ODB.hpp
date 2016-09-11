#pragma once
#include "stdafx.h"
class Git_ODB
{
 	git_odb* c_git_odb_{};
public:
	operator git_odb*()const { return c_git_odb_; }
	git_odb* c_guts()const { return c_git_odb_; }
	Git_ODB(git_repository*);
	~Git_ODB();
};

