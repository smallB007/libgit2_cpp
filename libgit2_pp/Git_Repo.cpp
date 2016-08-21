#include "Git_Repo.hpp"
/*Proper CADRe - [C]onstructor [A]cquires, [D]estructor [Re]leses*/
Git_Repo::Git_Repo(const repo_path_t& path_to_repo, const bool is_bare):c_git_repository_{nullptr}
{
	git_repository_init(&c_git_repository_, path_to_repo.c_str(), static_cast<unsigned int>(is_bare));
	
	if (!c_git_repository_)
	{
		throw - 1;
	}
}

Git_Repo::~Git_Repo()
{
	git_repository_free(c_git_repository_);
	c_git_repository_ = nullptr;
}
