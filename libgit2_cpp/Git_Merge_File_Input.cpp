#include "Git_Merge_File_Input.hpp"



Git_Merge_File_Input::Git_Merge_File_Input()
{
	check_for_error(git_merge_file_init_input(&c_guts_, GIT_MERGE_FILE_INPUT_VERSION));
}


