#include "Git_Merge_File_Result.hpp"



Git_Merge_File_Result::Git_Merge_File_Result(git_merge_file_result* c_git_file_result):Provider(c_git_file_result,git_merge_file_result_free)
{
}
