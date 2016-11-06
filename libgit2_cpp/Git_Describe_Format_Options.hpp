#pragma once
#include "stdafx.h"
class Git_Describe_Format_Options
{
	git_describe_format_options c_git_describe_format_options_;
public:
	git_describe_format_options* c_guts() { return &c_git_describe_format_options_; };
	Git_Describe_Format_Options();
	~Git_Describe_Format_Options()=default;
	LIBGIT2_DESCRIBE_FORMAT_OPTIONS_INTERFACE
	unsigned int 	version()const;
	unsigned int 	abbreviated_size()const;
	int 	always_use_long_format()const;
	string_t 	dirty_suffix()const;
};

