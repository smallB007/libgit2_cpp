#pragma once
#include "stdafx.h"
#include "Git_Commit.hpp"

class Git_Repo;

class Git_Branch
{
private:
	git_reference* c_git_reference_branch_{nullptr};
	Git_Repo* m_parent_repo_{nullptr};
	NMS::set<NMS::shared_ptr<Git_Commit>> commits_;

	git_repository* get_owner()const;
public:
	Git_Branch(const branch_name_t& branch_name, Git_Repo* parent);
	~Git_Branch();
	operator git_reference*() { return c_git_reference_branch_; }
	branch_name_t name()const;
	NMS::shared_ptr<Git_Commit> create_commit();
	NMS::shared_ptr<Git_Commit> get_head_commit()const;
#pragma LIBGIT2_BRANCH
	bool is_head()const;

};

