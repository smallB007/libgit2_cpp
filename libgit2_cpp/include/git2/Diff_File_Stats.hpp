#pragma once
#include "precompiled.hpp"
/*Copied from libgit2 diff_stats.c */
typedef struct {
	size_t insertions;
	size_t deletions;
} diff_file_stats;

class Diff_File_Stats : Guts_Provider<diff_file_stats,Memory_Management<NO>>
{
public:
	Diff_File_Stats(diff_file_stats);
	~Diff_File_Stats()=default;

	size_t insertions()const;
	size_t deletions()const;
};

