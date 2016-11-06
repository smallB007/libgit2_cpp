#pragma once
#include "stdafx.h"

class Git_Describe_Format_Options : public Guts_Provider<git_describe_format_options,false>
{
public:
	Git_Describe_Format_Options();
	~Git_Describe_Format_Options()=default;
	LIBGIT2_DESCRIBE_FORMAT_OPTIONS_INTERFACE
	unsigned int 	version()const;
	unsigned int 	abbreviated_size()const;
	int 	always_use_long_format()const;
	string_t 	dirty_suffix()const;
};

