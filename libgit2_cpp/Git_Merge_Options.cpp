#include "Git_Merge_Options.hpp"



Git_Merge_Options::Git_Merge_Options(unsigned ver) :c_git_merge_options_{ ver }
{
	if (GIT_MERGE_OPTIONS_VERSION == ver)
	{
		set_default();
	}
}

void Git_Merge_Options::set_default()
{
	int res = git_merge_init_options(&c_git_merge_options_, GIT_MERGE_OPTIONS_VERSION);
	if (FAILED(res))
	{
		throw - 1;
	}
}
