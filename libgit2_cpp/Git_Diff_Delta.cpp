#include "Git_Diff_Delta.hpp"



Git_Diff_Delta::Git_Diff_Delta(git_diff_delta c_git_diff_delta)
{
	c_git_guts_ = c_git_diff_delta;
}

git_delta_t 	Git_Diff_Delta::status()const
{
	return c_git_guts_.status;
}
uint32_t 	Git_Diff_Delta::flags()const
{
	return c_git_guts_.flags;
}

uint16_t 	Git_Diff_Delta::similarity()const
{
	return c_git_guts_.similarity;
}
uint16_t 	Git_Diff_Delta::nfiles()const
{
	return c_git_guts_.nfiles;
}
Git_Diff_File 	Git_Diff_Delta::old_file()const
{
	return c_git_guts_.old_file;
}
Git_Diff_File 	Git_Diff_Delta::new_file()const
{
	return c_git_guts_.new_file;
}


