#pragma once
#include "stdafx.h"
#include "Diff_File_Stats.hpp"

class Git_Diff_Stats : public Provider<git_diff_stats>
{
public:
	Git_Diff_Stats(git_diff_stats*);
	~Git_Diff_Stats();
	LIBGIT2_DIFF_STATS_INTERFACE
	shared_ptr_t<Git_Diff> diff()const;
	Diff_File_Stats filestats()const;
	size_t files_changed;
	size_t insertions;
	size_t deletions;
	size_t renames;

	size_t max_name;
	size_t max_filestat;
	int max_digits;
};

