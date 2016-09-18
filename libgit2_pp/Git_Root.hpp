#pragma once
#include "stdafx.h"

#include "Singleton.hpp"
#include "Git_Repo.hpp"
//find a way to name a repo
/***
VERY, VERY IMPORTANT
Unless the docs specifically say otherwise, any non-const pointer that’s filled in by libgit2 needs to be freed by the caller.
*/
class Git_Root : public Singleton<Git_Root>
{
	BEFRIEND_SINGLETON(Git_Root);
	friend Git_Root* create_git();
	friend void destroy_git();
	NMS::array<NMS::shared_ptr<Git_Repo>,1> active_repo_;
	NMS::set<NMS::shared_ptr<Git_Repo>> repositories_;
public:
	NMS::shared_ptr<Git_Repo> get_active_repo()const;
private:
~Git_Root();
Git_Root();
/*PUBLIC GIT INTERFACE*/	
public:
	NMS::shared_ptr<Git_Repo> create_repository(const repo_path_t& path_to_repo, const bool is_bare);
	NMS::shared_ptr<Git_Repo> find_c_git_repository(git_repository*)const;
};

/***
Creation and destruction
*/
inline Git_Root* create_git()
{
	static Git_Root& git_root = Git_Root::Create();
	return &git_root;
}

inline void destroy_git()
{
	Git_Root::Destroy();
}