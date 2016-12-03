#include "Git_RefDB.hpp"


Git_RefDB::Git_RefDB(git_repository * c_git_repo)
{
	int res = git_repository_refdb(&c_git_refdb_, c_git_repo);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
}

Git_RefDB::~Git_RefDB()
{
	if (c_git_refdb_)
	{
		git_refdb_free(c_git_refdb_);
		c_git_refdb_ = nullptr;
	}
}
