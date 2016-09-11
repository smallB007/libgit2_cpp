#pragma once
#include "stdafx.h"
#include "Git_Commit.hpp"

class Git_Branch
{
	friend class Git_Repo;
private:
	git_reference* c_git_reference_branch_{nullptr};
	Git_Repo* m_parent_repo_{nullptr};
	NMS::set<NMS::shared_ptr<Git_Commit>> commits_;

	git_repository* get_owner_()const;
	
	void move_(const branch_name_t& new_branch_name, bool force = true);
	Git_Branch(git_reference*,Git_Repo* parent);
public:
	git_reference* guts()const { return c_git_reference_branch_; };
	Git_Branch(const branch_name_t& branch_name, Git_Repo* parent);
	~Git_Branch();
	
	operator git_reference*() { return c_git_reference_branch_; }
	NMS::shared_ptr<Git_Repo> parent_repo()const;
	branch_name_t name()const;
	//git_branch_t type()const;
	NMS::shared_ptr<Git_Commit> create_commit();
	NMS::shared_ptr<Git_Commit> get_head_commit()const;

	bool is_head()const;
	void rename(const branch_name_t& new_branch_name);
	void move(const branch_name_t& new_branch_name);
	
private:	

public:
	decltype(commits_)::iterator begin()const;
	decltype(commits_)::iterator end()const;

#ifdef _FULL_IMPLEMENTATION_
	git_branch_set_upstream
		git_branch_upstream
		git_branch_create_from_annotated->in Git_Repo
#endif
};
