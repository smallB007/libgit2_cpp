#pragma once
#include "stdafx.h"

//#include "Git_Branch.hpp"

class Git_Repo : public Provider<git_repository>
{
	BEFRIEND_SINGLETON(Git_Repo);
	friend class Git_Root;
private:
	NMS::set<shared_ptr_t<Git_Branch>> branches_;
	const NMS::string repo_name_;
private:
	shared_ptr_t<Git_Branch> find_branch_by_c_git_reference_(git_reference*const)const;
	void create_initial_commit_();
protected:
	NMS::pair<bool, shared_ptr_t<Git_Branch>> find_branch(const branch_name_t& branch_name)const;
public:
	Git_Repo(const Git_Repo&)=delete;
	Git_Repo& operator=(const Git_Repo&) = delete;
	Git_Repo(const repo_path_t& path_to_repo, const bool is_bare);
	
	bool is_my_path(const repo_path_t& path_to_some_repo)const;
	void rename(const NMS::string& repo_name);

	const shared_ptr_t<Git_Commit> get_head_commit()const;
	//shared_ptr_t<Git_Branch> get_branch(const branch_name_t& branch_name)const;
LIBGIT2_REPO_INTERFACE
	void cleanup();
	shared_ptr_t<Git_Config> config()const;
	shared_ptr_t<Git_Config> config_snapshot()const;
	repo_path_t discover(const repo_path_t = ".")const;
	namespace_name_t get_namespace()const;
	shared_ptr_t<Git_Branch> head()const;
	bool is_head_detached()const;
	bool is_head_unborn()const;
	shared_ptr_t<Git_Commit_Author> identitiy()const;
	shared_ptr_t<Git_Index> index()const;
	bool is_bare()const;
	bool is_empty()const;
	bool is_shallow()const;
	shared_ptr_t<Git_ODB> odb()const;
	repo_path_t path()const;
	shared_ptr_t<Git_RefDB> ref_db()const;
	void set_bare();
	void set_config(const Git_Config&);
	void set_identity(const Git_Signature&);
	void unset_identity();
	void set_index(const Git_Index&);
	void set_namespace(const namespace_name_t&);
	void set_odb(const Git_ODB&);
	void set_ref_db(const Git_RefDB&);
	void set_working_dir(const repo_path_t&, bool = true);
	const repo_path_t get_working_dir()const;
	git_repository_state_t get_state()const;
	void cleanup_state();
LIBGIT2_COMMIT_INTERFACE
	const shared_ptr_t<Git_Commit> commit_lookup(const Git_Commit_ID&)const;


LIBGIT2_BRANCH_INTERFACE
	shared_ptr_t<Git_Branch> create_branch(const branch_name_t& branch_name);
	void delete_branch(const branch_name_t& branch_name);
	decltype(branches_)::iterator begin()const;
	decltype(branches_)::iterator end()const;
	shared_ptr_t<Git_Branch> branch_lookup(const branch_name_t&,git_branch_t)const;
LIBGIT2_CHECKOUT_INTERFACE
	void checkout_head()const;
	void checkout_index()const;
	void checkout_tree()const;
LIBGIT2_CHERRYPICK_INTERFACE
	void cherrypick(const Git_Commit&,const Git_CherryPick_Options&);
LIBGIT2_CLONE_INTERFACE
	shared_ptr_t<Git_Repo> clone(const repo_path_t& remote_repo_path,const repo_path_t& local_target_dir,const Git_Clone_Options& clone_options)const;
	
#ifdef _FULL_IMPLEMENTATION_
	git_branch_create_from_annotated
	git_commit_lookup_prefix
	git_repository_detach_head
	git_repository_fetchhead_foreach
	git_repository_hashfile
	git_repository_init_ext
	git_repository_init_init_options
		git_repository_mergehead_foreach
		git_repository_new
		git_repository_open
		git_repository_open_bare
		git_repository_open_ext
		git_repository_reinit_filesystem
		git_repository_set_head
		git_repository_set_head_detached
		git_repository_set_head_detached_from_annotated
		git_repository_wrap_odb
		git_cherrypick_commit
#endif	
};