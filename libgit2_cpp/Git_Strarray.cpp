#include "Git_Strarray.hpp"



Git_Strarray::Git_Strarray(git_strarray* c_git_strarray):Provider(c_git_strarray,git_strarray_free)
{
}

Git_Strarray::Git_Strarray(const git_strarray & c_git_strarray_src): Provider(c_guts_,git_strarray_free)
{
	check_for_error(git_strarray_copy(c_guts_, &c_git_strarray_src));
}

size_t Git_Strarray::size() const
{
	return c_guts_->count;
}

void Git_Strarray::push_back(const string_t & str)
{
	git_strarray *tgt{};
	const git_strarray *src{};
	check_for_error(git_strarray_copy(tgt, src));
#pragma message("Error fix it Artie")
}

template<class Container>
Git_Strarray::Git_Strarray(const Container &)
{
#pragma message("ToDo implement that")
}


