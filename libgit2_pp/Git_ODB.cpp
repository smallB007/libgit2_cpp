#include "Git_ODB.hpp"



Git_ODB::Git_ODB(git_repository* c_git_repo) 
{
	auto res = git_repository_odb(&c_git_odb_, c_git_repo);
	if (FAILED(res))
	{
		throw - 1;
	}
}


Git_ODB::~Git_ODB()
{
	if (c_git_odb_)
	{
		git_odb_free(c_git_odb_);
		c_git_odb_ = nullptr;
	}
}
