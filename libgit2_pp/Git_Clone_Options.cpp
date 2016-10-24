#include "Git_Clone_Options.hpp"



Git_Clone_Options::Git_Clone_Options(unsigned ver) :c_git_clone_options_{ ver }
{
	if (GIT_CLONE_OPTIONS_VERSION == ver)
	{
		set_default();
	}
}

void Git_Clone_Options::set_default()
{
	int res = git_clone_init_options(&c_git_clone_options_, GIT_CLONE_OPTIONS_VERSION);
	if (FAILED(res))
	{
		throw - 1;
	}
}
