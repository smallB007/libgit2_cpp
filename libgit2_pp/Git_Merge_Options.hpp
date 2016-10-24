#pragma once
#include "stdafx.h"
class Git_Merge_Options
{
	git_merge_options c_git_merge_options_{ GIT_MERGE_OPTIONS_INIT };
public:
#pragma message("ToDo [Git_Merge_Options] - implement setters and getters")
	Git_Merge_Options(unsigned ver = GIT_MERGE_OPTIONS_INIT);
	git_merge_options c_guts() const { return c_git_merge_options_; }
	void set_default();
};

