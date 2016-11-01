#include "Git_Root.hpp"



Git_Root::Git_Root()
{
	git_libgit2_init();
}

Git_Root::~Git_Root()
{
	git_libgit2_shutdown();
}

shared_ptr_t<Git_Repo> Git_Root::create_repository(const repo_path_t& path_to_repo, const bool is_bare)
{
	/*As a side note and something to put into your KB Artie, 'smart' ptrs should be returned by value so the proper counter incrementation
	can take place*/
	//Find out if such repo already exists
	for (const auto aSharedPtr : repositories_)
	{
		if (aSharedPtr->is_my_path(path_to_repo))
		{
			return aSharedPtr;
		}
	}
	
	//no repo found, create it then
	auto _git_repo = make_shared_ver<Git_Repo>(path_to_repo,is_bare);
	repositories_.insert(_git_repo);
	//always make just created repo active
	active_repo_[0] = _git_repo;
	/*initial commit must be created after active_repo_ has been set*/
	_git_repo->create_initial_commit_();
	return _git_repo;
}

shared_ptr_t<Git_Repo> Git_Root::find_c_git_repository(git_repository* c_git_repo)const
{
	for (const auto& aSharedPtr : repositories_)
	{
		if (aSharedPtr->c_guts() == c_git_repo)
		{
			return aSharedPtr;
		}
	}

	return nullptr;
}

shared_ptr_t<Git_Repo> Git_Root::get_active_repo()const
{
	return active_repo_[0];
}