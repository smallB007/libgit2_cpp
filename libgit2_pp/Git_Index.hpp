#pragma once
#include "stdafx.h"
class Git_Index
{
	git_index* c_git_index_{};
public:
	git_index* c_guts()const { return c_git_index_; }
	operator git_index*()const { return c_git_index_; }
	Git_Index(git_index*);
	~Git_Index();
};

