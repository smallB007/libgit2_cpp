#include "Git_Root.hpp"



Git_Root::Git_Root()
{
	git_libgit2_init();
}

Git_Root::~Git_Root()
{
	git_libgit2_shutdown();
}

std::shared_ptr<Git_Repo> Git_Root::create_repository(const repo_path_t& path_to_repo, const bool is_bare)
{
	/*As a side note and something to put into your KB Artie, 'smart' ptrs should be returned by value so the proper counter incrementation
	can take place*/
	//Find out if such repo already find_branch in db
	for (const auto aSharedPtr : repositories_)
	{
		//auto Git_Repo_ptr = aSharedPtr.get();
		if (aSharedPtr->is_my_path(path_to_repo))
		{
			return aSharedPtr;
		}
	}
	
	//no repo found, create it then
	auto _git_repo = std::make_shared<Git_Repo>(path_to_repo,is_bare);
	repositories_.insert(_git_repo);
	return _git_repo;
}