#pragma once
#include "stdafx.h"
class Git_Merge_File_Input : public Guts_Provider<git_merge_file_input,Memory_Management<NO>>
{
public:
	Git_Merge_File_Input();
	~Git_Merge_File_Input()=default;
#pragma message("ToDo implement interface")
};

