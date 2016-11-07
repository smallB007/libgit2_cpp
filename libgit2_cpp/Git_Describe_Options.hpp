#pragma once
#include "stdafx.h"
class Git_Describe_Options : public Guts_Provider<git_describe_options, Memory_Management<NO>>
{
public:
	Git_Describe_Options();
	~Git_Describe_Options() = default;
#pragma message("ToDo perhaps there is a way to make the desig of Guts_Provider that actually can cope with non ptr types of c_git_class")
	LIBGIT2_DESCRIBE_OPTIONS_INTERFACE
	unsigned int 	version()const;
	unsigned int 	max_candidates_tags()const;
	unsigned int 	describe_strategy()const;
	string_t 	pattern()const;
	bool 	only_follow_first_parent()const;
	bool 	show_commit_oid_as_fallback()const;

	
};

