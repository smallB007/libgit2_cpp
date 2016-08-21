#pragma once
#include "stdafx.h"
#include <git2.h>
#include "Singleton.hpp"

class Git_Repo
{
private:
	git_repository* c_git_repository_;
public:
	Git_Repo(const repo_path_t& path_to_repo, const bool is_bare);
	~Git_Repo();
	
};
