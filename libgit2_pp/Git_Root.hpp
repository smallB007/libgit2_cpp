#pragma once
#include "stdafx.h"
#include <git2.h>
//#include <map>
#include <unordered_map>
#include <string>
#include <memory>

#include "Singleton.hpp"
#include "Git_Repo.hpp"
class Git_Root : private Singleton<Git_Root>
{
	//friend class Singleton<Git_Root>;
	BEFRIEND_SINGLETON(Git_Root);
	friend Git_Root* create_git();
	friend void destroy_git();
	
	std::unordered_map<repo_path_t, std::shared_ptr<Git_Repo>> repositories_;
public:
private:
~Git_Root();
Git_Root();
/*PUBLIC GIT INTERFACE*/	
public:
	std::shared_ptr<Git_Repo> create_repository(const repo_path_t& path_to_repo, const bool is_bare);
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