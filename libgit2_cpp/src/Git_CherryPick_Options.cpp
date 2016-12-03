#include "Git_CherryPick_Options.hpp"

#include "Git_Merge_Options.hpp"
#include "Git_Checkout_Options.hpp"

Git_CherryPick_Options::Git_CherryPick_Options(unsigned ver) :c_git_cherrypick_options_{ ver }
{
	if (GIT_CHERRYPICK_OPTIONS_VERSION == ver)
	{
		set_default();
	}
}

void Git_CherryPick_Options::set_default()
{
	int res = git_cherrypick_init_options(&c_git_cherrypick_options_, GIT_CHERRYPICK_OPTIONS_VERSION);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
}

void Git_CherryPick_Options::set_version(unsigned int version)
{
	c_git_cherrypick_options_.version = version;
}
void Git_CherryPick_Options::set_mainline(unsigned int mainline)
{
	c_git_cherrypick_options_.mainline = mainline;
}

void Git_CherryPick_Options::set_merge_options(const Git_Merge_Options& merge_options)
{
	c_git_cherrypick_options_.merge_opts = *merge_options.c_guts();
}
void Git_CherryPick_Options::set_checkout_options(const Git_Checkout_Options& checkout_options)
{
	c_git_cherrypick_options_.checkout_opts = *checkout_options.c_guts();
}