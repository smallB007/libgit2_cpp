#include "Git_Strarray.hpp"



Git_Strarray::Git_Strarray(git_strarray* c_git_strarray):Provider(c_git_strarray,git_strarray_free)
{
}

Git_Strarray::Git_Strarray(const git_strarray & c_git_strarray_src): Provider(new git_strarray,git_strarray_free)
{
	check_for_error(git_strarray_copy(c_git_guts_, &c_git_strarray_src));
#pragma message("ToDo Requires checking if this does")
}

size_t Git_Strarray::size() const
{
	return c_git_guts_->count;
}


