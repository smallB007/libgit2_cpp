#include "Git_Index.hpp"

Git_Index::Git_Index(git_index* c_git_index): Provider(c_git_index,git_index_free)
{
}


