#include "Git_Root.hpp"
#include "Git_Buf.hpp"
#pragma message("ToDo include-what-you-use")
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

const auto Git_Root::get_repositories() const
{
	return repositories_;
}

string_t Git_Root::discover(const std::string_view& start_path)const
{
	//git_buf buf = GIT_BUF_INIT_CONST(NULL, 0);
	Git_Buf _git_buf_;
#pragma message("Error each git_buf must be inited before it can be used")
	//check_for_error(git_repository_discover(&buf, start_path.c_str(), 0, NULL));
	check_for_error(git_repository_discover(_git_buf_.c_guts(), start_path.data(), 0, NULL));

	//string_t repo_path = buf.ptr;
	string_t repo_path ( _git_buf_.get_string());
#pragma message("Error each git_buf must be released!!!")
	return repo_path;
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
