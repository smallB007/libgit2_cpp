#include "Git_Push_Options.hpp"



Git_Push_Options::Git_Push_Options()
{
	git_push_init_options(&c_guts_, GIT_PUSH_OPTIONS_VERSION);
}

