#include "Git_Buf.hpp"



Git_Buf::Git_Buf(git_buf* c_git_buf) :Provider(c_git_buf,git_buf_free)
{
}

bool Git_Buf::contains_null()const
{
	return git_buf_contains_nul(c_git_guts_);
}

void Git_Buf::grow(const NMS::size_t target_size)
{
	check_for_error(git_buf_grow(const_cast<git_buf*>(c_git_guts_), target_size));
#pragma message("ToDo ^^^ const_cast on type of c_git_guts_ should be used here")
}

bool Git_Buf::is_binary()const
{
	return git_buf_is_binary(c_git_guts_);
}

void Git_Buf::set_data(const NMS::vector<char>& data)
{
	check_for_error(git_buf_set(const_cast<git_buf*>(c_git_guts_), &data, NMS::size(data)));
#pragma message("ToDo ^^^ const_cast on type of c_git_guts_ should be used here")
}
