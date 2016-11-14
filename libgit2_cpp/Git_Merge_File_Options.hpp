#pragma once
#include "stdafx.h"
class Git_Merge_File_Options : public Guts_Provider<git_merge_file_options,Memory_Management<NO>>
{
public:
	Git_Merge_File_Options();
	~Git_Merge_File_Options()=default;
#pragma message("ToDo implement interface")
};

