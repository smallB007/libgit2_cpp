#include "Git_Describe_Options.hpp"



Git_Describe_Options::Git_Describe_Options() 
{
	c_git_describe_options_ = GIT_DESCRIBE_OPTIONS_INIT;
}

git_describe_options * Git_Describe_Options::c_guts()
{
	return &c_git_describe_options_;
}

unsigned int 	Git_Describe_Options::version()const
{
	return c_git_describe_options_.version;
}

unsigned int 	Git_Describe_Options::max_candidates_tags()const
{
	return c_git_describe_options_.max_candidates_tags;
}

unsigned int 	Git_Describe_Options::describe_strategy()const
{
	return c_git_describe_options_.describe_strategy;
}

string_t 	Git_Describe_Options::pattern()const
{
	return c_git_describe_options_.pattern;
}

bool 	Git_Describe_Options::only_follow_first_parent()const
{
	return c_git_describe_options_.only_follow_first_parent;
}

bool 	Git_Describe_Options::show_commit_oid_as_fallback()const
{
	return c_git_describe_options_.show_commit_oid_as_fallback;
}