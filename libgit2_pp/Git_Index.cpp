#include "Git_Index.hpp"

Git_Index::Git_Index(git_index* c_git_index): Provider(git_index_free)
{
	c_git_guts_ = c_git_index ;
}


