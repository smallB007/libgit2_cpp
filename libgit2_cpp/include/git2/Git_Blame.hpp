#pragma once
#include "precompiled.hpp"

class Git_Blame : public Provider<git_blame>
{
public:
	Git_Blame(git_blame* c_git_blame);
	LIBGIT2_BLAME_INTERFACE
#ifdef _FULL_IMPLEMENTATION_
		git_blame_buffer
		git_blame_file
		git_blame_get_hunk_byindex
		git_blame_get_hunk_byline
		git_blame_get_hunk_count
		git_blame_init_options
#endif
};

