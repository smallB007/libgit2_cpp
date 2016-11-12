#include "Git_Buf.hpp"




Git_Buf::Git_Buf(git_buf* c_git_buf ) :Provider(c_git_buf,git_buf_free)
{
}

Git_Buf::Git_Buf(git_buf & c_git_buf):Provider(c_guts_,git_buf_free)
{
	check_for_error(git_buf_set(c_guts_, &c_git_buf, c_git_buf.size));
}

size_t Git_Buf::size() const
{
	return c_guts_->size;
}

size_t Git_Buf::capacity() const
{
	return c_guts_->asize;
}

git_buf* Git_Buf::head() const
{
	return c_guts_;
}

bool Git_Buf::contains_null()const
{
	return git_buf_contains_nul(c_guts_);
}

void Git_Buf::grow(const NMS::size_t target_size)
{
	check_for_error(git_buf_grow(const_cast<git_buf*>(c_guts_), target_size));
#pragma message("ToDo ^^^ const_cast on type of c_guts_ should be used here")
}

bool Git_Buf::is_binary()const
{
	return git_buf_is_binary(c_guts_);
}

void Git_Buf::set_data(const NMS::vector<char>& data)
{
	check_for_error(git_buf_set(const_cast<git_buf*>(c_guts_), &data, NMS::size(data)));
#pragma message("ToDo ^^^ const_cast on type of c_guts_ should be used here")
}
