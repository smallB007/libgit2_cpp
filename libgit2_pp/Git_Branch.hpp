#pragma once
#include "stdafx.h"
#include "Git_Commit.hpp"

class Git_Repo;

class Git_Branch
{
private:
	git_reference* c_git_reference_branch_{nullptr};
	Git_Repo* parent_{nullptr};
	std::set<std::shared_ptr<Git_Commit>> commits_;

	git_repository* get_owner()const;
public:
	Git_Branch(const branch_name_t& branch_name, Git_Repo* parent);
	~Git_Branch();
	branch_name_t name()const;
	std::shared_ptr<Git_Commit> create_commit();
};

