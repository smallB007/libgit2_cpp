#pragma once
#include "precompiled.hpp"
class Git_Fetch_Options : public Guts_Provider<git_fetch_options,Memory_Management<NO>>
{
public:
	Git_Fetch_Options();
	~Git_Fetch_Options()=default;
	LIBGIT2_FETCH_OPTIONS_INTERFACE
		int 	version()const;
		git_remote_callbacks 	callbacks()const;
		git_fetch_prune_t 	prune()const;
		int 	update_fetchhead()const;
		git_remote_autotag_option_t 	download_tags()const;
#ifdef _FULL_IMPLEMENTATION_
		git_proxy_options 	proxy_opts()const;
#endif
		Git_Strarray 	custom_headers()const;
};

