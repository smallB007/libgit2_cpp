#include "Git_ODB.hpp"



Git_ODB::Git_ODB() : Provider(git_odb_free)
{
	auto res = git_repository_odb(&c_git_guts_, get_parent()->c_guts());
	if (FAILED(res))
	{
		throw - 1;
	}
}
