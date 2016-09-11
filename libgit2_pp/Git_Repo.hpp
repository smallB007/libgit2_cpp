#pragma once
#include "stdafx.h"

#include "Git_Branch.hpp"

class Git_Repo 
{
private:
	git_repository* c_git_repository_{};
	NMS::set<NMS::shared_ptr<Git_Branch>> branches_;
	const NMS::string repo_name_;
private:
	NMS::shared_ptr<Git_Branch> find_branch_by_git_reference_(git_reference*const)const;
protected:
	NMS::pair<bool, NMS::shared_ptr<Git_Branch>> find_branch(const branch_name_t& branch_name)const;
public:
	git_repository* guts()const { return c_git_repository_; }
	//Git_Repo(const Git_Repo&)=delete;
	Git_Repo(const repo_path_t& path_to_repo, const bool is_bare);
	//Git_Repo(git_repository* c_git_repository);
	~Git_Repo();
	operator git_repository*() { return c_git_repository_; }
	
	bool is_my_path(const repo_path_t& path_to_some_repo)const;
	void rename(const NMS::string& repo_name);

	const NMS::shared_ptr<Git_Commit> get_head_commit()const;
	//NMS::shared_ptr<Git_Branch> get_branch(const branch_name_t& branch_name)const;
LIBGIT2_REPO_INTERFACE
	void cleanup();
	NMS::shared_ptr<Git_Config> config()const;
	NMS::shared_ptr<Git_Config> config_snapshot()const;
	repo_path_t discover(const repo_path_t = ".")const;
	namespace_name_t get_namespace()const;
	NMS::shared_ptr<Git_Branch> head()const;
LIBGIT2_COMMIT_INTERFACE
	const NMS::shared_ptr<Git_Commit> commit_lookup(const Git_Commit_ID&)const;


LIBGIT2_BRANCH_INTERFACE
	NMS::shared_ptr<Git_Branch> create_branch(const branch_name_t& branch_name);
	void delete_branch(const branch_name_t& branch_name);
	decltype(branches_)::iterator begin()const;
	decltype(branches_)::iterator end()const;
	NMS::shared_ptr<Git_Branch> branch_lookup(const branch_name_t&,git_branch_t)const;

	
	
#ifdef _FULL_IMPLEMENTATION_
	git_branch_create_from_annotated
	git_commit_lookup_prefix
	git_repository_detach_head
	git_repository_fetchhead_foreach
	git_repository_hashfile
#endif	
};
