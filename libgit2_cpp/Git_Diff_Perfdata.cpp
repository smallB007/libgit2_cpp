#include "Git_Diff_Perfdata.hpp"

//Git_Diff_Perfdata::Git_Diff_Perfdata(git_diff_perfdata * c_git_diff_perfdata)
//{
//	c_guts_ = *c_git_diff_perfdata;
//}

Git_Diff_Perfdata::Git_Diff_Perfdata(git_diff_perfdata  c_git_perfdata)
{
	c_guts_ = c_git_perfdata;
}

unsigned int 	Git_Diff_Perfdata::version()const
{
	return c_guts_.version;
}
size_t 	Git_Diff_Perfdata::stat_calls()const
{
	return c_guts_.stat_calls;
}
size_t 	Git_Diff_Perfdata::oid_calculations()const
{
	return c_guts_.oid_calculations;
}

