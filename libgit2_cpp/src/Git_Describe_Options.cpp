#include "Git_Describe_Options.hpp"



Git_Describe_Options::Git_Describe_Options(git_describe_options c_git_describe_options)
{
	c_guts_ = c_git_describe_options;
}

unsigned int 	Git_Describe_Options::version()const
{
	return c_guts_.version;
}

unsigned int 	Git_Describe_Options::max_candidates_tags()const
{
	return c_guts_.max_candidates_tags;
}

unsigned int 	Git_Describe_Options::describe_strategy()const
{
	return c_guts_.describe_strategy;
}

string_t 	Git_Describe_Options::pattern()const
{
	return c_guts_.pattern;
}

bool 	Git_Describe_Options::only_follow_first_parent()const
{
	return c_guts_.only_follow_first_parent;
}

bool 	Git_Describe_Options::show_commit_oid_as_fallback()const
{
	return c_guts_.show_commit_oid_as_fallback;
}