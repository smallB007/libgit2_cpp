#include "Git_Root.hpp"


inline Git_Root* create_git()
{
	static Git_Root git_root;

	return &git_root;
}

Git_Root* git_root_inst_ = create_git();

Git_Root::Git_Root()
{
	git_libgit2_init();
}

Git_Root::~Git_Root()
{
	git_libgit2_shutdown();
}

shared_ptr_t<Git_Repo> Git_Root::create_repository(const string_t& path_to_repo, const bool is_bare)
{
#pragma message("Idea make all string_t string_view_t")
	/**As a side note and something to put into your KB Artie, 'smart' ptrs should be returned by value so the proper counter incrementation
	can take place*/
	/**Find out if such repo already exists*/
	auto iter = NMS::find_if(NMS::begin(repositories_), NMS::end(repositories_),
																				[&path_to_repo](shared_ptr_t<Git_Repo> const& i) { return i->path() == path_to_repo; });
	if (iter != NMS::end(repositories_))
	{
		return *iter;
	}
	
	/**no repo found, create it then*/
	auto _git_repo = Factory_Git_Object<Git_Repo>::create_ptr(path_to_repo.c_str(), is_bare);
	repositories_.push_back(_git_repo);
	///**always make just created repo active*/
	active_repo_ = _git_repo;
	///**initial commit must be created 'AFTER' active_repo_ has been set*/
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
	return active_repo_;
}

void Git_Root::set_active_repo(shared_ptr_t<Git_Repo> repo)
{
	active_repo_ = repo;
}
