#include "Git_Diff_Stats.hpp"



Git_Diff_Stats::Git_Diff_Stats(git_diff_stats* c_git_diff_stats):Provider(c_git_diff_stats,git_diff_stats_free)
{
}


Git_Diff_Stats::~Git_Diff_Stats()
{
}
