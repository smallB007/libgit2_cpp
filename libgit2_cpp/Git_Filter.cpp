#include "Git_Filter.hpp"



Git_Filter::Git_Filter(git_filter c_git_filter)
{
	c_guts_ = c_git_filter;
#pragma message("Warning nullptr as a deleter")
}

