#include "Git_ODB.hpp"
#include "Git_Repo.hpp"


Git_ODB::Git_ODB() : Provider(git_odb_free)
{
	auto res = git_repository_odb(&c_git_guts_, c_parent_guts());
	if (FAILED(res))
	{
		throw - 1;
	}
}
