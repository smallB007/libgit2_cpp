#include "Git_Diff_File.hpp"
#include "Git_Object_ID.hpp"


Git_Diff_File::Git_Diff_File(git_diff_file c_git_diff_file) 
{
	c_git_guts_ = c_git_diff_file;
}

Git_Object_ID     Git_Diff_File::id()const
{
	return const_cast<git_oid*>(&c_git_guts_.id);
}
file_path_t		  Git_Diff_File::path()const
{
	return c_git_guts_.path;
}
git_off_t		  Git_Diff_File::size()const
{
	return c_git_guts_.size;
}
uint32_t		  Git_Diff_File::flags()const
{
	return c_git_guts_.flags;
}
uint16_t		  Git_Diff_File::mode()const
{
	return c_git_guts_.mode;
}