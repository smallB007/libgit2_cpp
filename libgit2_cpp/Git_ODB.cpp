#include "Git_ODB.hpp"
#include "Git_Repo.hpp"


Git_ODB::Git_ODB(git_odb* c_git_odb) : Provider(c_git_odb,git_odb_free)
{
	//const auto& non_const = c_guts_;
	
	check_for_error(git_repository_odb(&c_guts_, c_parent_guts()));
}
