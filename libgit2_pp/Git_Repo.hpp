#pragma once
#include "stdafx.h"



#include "Singleton.hpp"
#include "Git_Branch.hpp"

class Git_Repo 
{
private:
	git_repository* c_git_repository_{nullptr};
	NMS::set<NMS::shared_ptr<Git_Branch>> branches_;
	const NMS::string repo_name_;
	mutable NMS::array<NMS::pair<git_oid*, git_commit*>, 1> head_commit_;
protected:
	NMS::pair<bool, NMS::shared_ptr<Git_Branch>> find_branch(const branch_name_t& branch_name)const;
public:
	Git_Repo(const repo_path_t& path_to_repo, const bool is_bare);
	Git_Repo(git_repository* c_git_repository);
	~Git_Repo();
	operator git_repository*() { return c_git_repository_; }
	NMS::shared_ptr<Git_Branch> create_branch(const branch_name_t& branch_name);
	bool is_my_path(const repo_path_t& path_to_some_repo)const;
	void rename(const NMS::string& repo_name);

	const NMS::shared_ptr<Git_Commit> get_head_commit()const;
	NMS::shared_ptr<Git_Branch> get_branch(const branch_name_t& branch_name)const;

	/*LIBGIT2 INTERFACE*/
#pragma LIBGIT2_COMMIT
	const NMS::shared_ptr<Git_Commit> commit_lookup(const Git_Commit_ID&)const;
#ifdef _FULL_IMPLEMENTATION_
	git_commit_lookup_prefix
#endif

};
