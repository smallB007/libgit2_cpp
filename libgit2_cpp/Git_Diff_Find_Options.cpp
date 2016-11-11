#include "Git_Diff_Find_Options.hpp"
#include "Git_Diff_Similarity_Metric.hpp"

Git_Diff_Find_Options::Git_Diff_Find_Options(git_diff_find_options git_diff_find_options)
{
	c_git_guts_ = git_diff_find_options;
}

unsigned int 	Git_Diff_Find_Options::version()const
{
	return c_git_guts_.version;
}
uint32_t 	Git_Diff_Find_Options::flags()const
{
	return c_git_guts_.flags;
}
uint16_t 	Git_Diff_Find_Options::rename_threshold()const
{
	return c_git_guts_.rename_threshold;
}
uint16_t 	Git_Diff_Find_Options::rename_from_rewrite_threshold()const
{
	return c_git_guts_.rename_from_rewrite_threshold;
}
uint16_t 	Git_Diff_Find_Options::copy_threshold()const
{
	return c_git_guts_.copy_threshold;

}
uint16_t 	Git_Diff_Find_Options::break_rewrite_threshold()const
{
	return c_git_guts_.break_rewrite_threshold;
}
size_t 	Git_Diff_Find_Options::rename_limit()const
{
	return c_git_guts_.rename_limit;
}
shared_ptr_t<Git_Diff_Similarity_Metric> 	Git_Diff_Find_Options::metric()const
{
	return make_shared_ver<Git_Diff_Similarity_Metric>(c_git_guts_.metric);
}