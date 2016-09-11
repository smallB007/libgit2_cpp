#include "Git_Index.hpp"



Git_Index::Git_Index(git_index* c_git_index):c_git_index_{c_git_index}
{
}


Git_Index::~Git_Index()
{
	if (c_git_index_)
	{
		git_index_free(c_git_index_);
		c_git_index_ = nullptr;
	}
}
