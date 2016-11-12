#include "Git_Fetch_Options.hpp"
#include "Git_Strarray.hpp"


Git_Fetch_Options::Git_Fetch_Options()
{
	c_git_guts_ = GIT_FETCH_OPTIONS_INIT;
}

int 	Git_Fetch_Options::version()const
{
	return c_git_guts_.version;
}
git_remote_callbacks 	Git_Fetch_Options::callbacks()const
{
	return c_git_guts_.callbacks;
}
git_fetch_prune_t 	Git_Fetch_Options::prune()const
{
	return c_git_guts_.prune;
}
int 	Git_Fetch_Options::update_fetchhead()const
{
	return c_git_guts_.update_fetchhead;
}
git_remote_autotag_option_t 	Git_Fetch_Options::download_tags()const
{
	return c_git_guts_.download_tags;
}
#ifdef _FULL_IMPLEMENTATION_
git_proxy_options 	proxy_opts()const;
#endif
Git_Strarray 	Git_Fetch_Options::custom_headers()const
{
	return c_git_guts_.custom_headers;
}