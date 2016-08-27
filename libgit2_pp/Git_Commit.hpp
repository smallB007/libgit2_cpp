#pragma once
#include "stdafx.h"
class Git_Commit
{
	git_commit* c_git_commit;
public:
	Git_Commit(git_repository* c_git_repository);
	~Git_Commit();
};

