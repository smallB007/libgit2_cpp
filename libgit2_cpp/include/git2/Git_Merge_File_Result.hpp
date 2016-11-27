#pragma once
#include "precompiled.hpp"
class Git_Merge_File_Result : public Provider<git_merge_file_result>
{

public:
	Git_Merge_File_Result(git_merge_file_result*);
	~Git_Merge_File_Result()=default;
#pragma message("ToDo implement interface")
};

