#pragma once
#include "stdafx.h"
class Git_Merge_Options : public Guts_Provider<git_merge_options,Memory_Management<NO>>
{
public:
#pragma message("ToDo  [Git_Merge_Options] - implement setters and getters")
	Git_Merge_Options();
	void set_default();
};

