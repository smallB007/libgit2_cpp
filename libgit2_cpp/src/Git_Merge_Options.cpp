#include "Git_Merge_Options.hpp"



Git_Merge_Options::Git_Merge_Options() 
{
		set_default();
}

void Git_Merge_Options::set_default()
{
	check_for_error(git_merge_init_options(&c_guts_, GIT_MERGE_OPTIONS_VERSION));
}
