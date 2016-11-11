#pragma once
#include "stdafx.h"
class Git_Diff_Find_Options : public Guts_Provider<git_diff_find_options, Memory_Management<NO>>
{
public:
	Git_Diff_Find_Options(git_diff_find_options = GIT_DIFF_FIND_OPTIONS_INIT);
	~Git_Diff_Find_Options()=default;
	LIBGIT2_DIFF_FIND_OPTIONS_INTERFACE
	unsigned int 	version()const;
	uint32_t 	flags()const;
	uint16_t 	rename_threshold()const;
	uint16_t 	rename_from_rewrite_threshold()const;
	uint16_t 	copy_threshold()const;
	uint16_t 	break_rewrite_threshold()const;
	size_t 	rename_limit()const;
	shared_ptr_t<Git_Diff_Similarity_Metric> 	metric()const;
};

