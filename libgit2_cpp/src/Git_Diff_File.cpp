#include "Git_Diff_File.hpp"
#include "Git_Object_ID.hpp"


Git_Diff_File::Git_Diff_File(git_diff_file c_git_diff_file) 
{
	c_guts_ = c_git_diff_file;
}

Git_Object_ID     Git_Diff_File::id()const
{
	return Factory_Git_Object<Git_Object_ID>::create(&c_guts_.id);
}
string_t		  Git_Diff_File::path()const
{
	return c_guts_.path;
}
git_off_t		  Git_Diff_File::size()const
{
	return c_guts_.size;
}
uint32_t		  Git_Diff_File::flags()const
{
	return c_guts_.flags;
}
uint16_t		  Git_Diff_File::mode()const
{
	return c_guts_.mode;
}