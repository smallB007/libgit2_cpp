#include "Git_Merge_File_Options.hpp"



Git_Merge_File_Options::Git_Merge_File_Options()
{
	check_for_error(git_merge_file_init_options(&c_guts_, GIT_MERGE_FILE_OPTIONS_VERSION));
}


