#include "Diff_File_Stats.hpp"


Diff_File_Stats::Diff_File_Stats(diff_file_stats c_diff_file_stats)
{
	c_guts_ = c_diff_file_stats;
}

size_t Diff_File_Stats::insertions()const
{
	return c_guts_.insertions;
}

size_t Diff_File_Stats::deletions()const
{
	return c_guts_.deletions;
}

