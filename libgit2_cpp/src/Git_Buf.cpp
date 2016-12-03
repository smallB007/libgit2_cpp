#include "Git_Buf.hpp"




Git_Buf::Git_Buf():Provider(c_guts_, git_buf_free)
{
	c_git_buf_ =  GIT_BUF_INIT_CONST(NULL, 0) ;
	c_guts_ = &c_git_buf_;
}

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

string_t Git_Buf::get_string() const
{
	return string_t(c_guts_->ptr, c_guts_->ptr + c_guts_->size);
#pragma message("Warning check for oned")
}

bool Git_Buf::contains_null()const
{
	return git_buf_contains_nul(c_guts_);
}

void Git_Buf::grow(const NMS::size_t target_size)
{
	check_for_error(git_buf_grow(c_guts_, target_size));
}

bool Git_Buf::is_binary()const
{
	return git_buf_is_binary(c_guts_);
}

void Git_Buf::set_data(const NMS::vector<char>& data)
{
	check_for_error(git_buf_set(c_guts_, &data, NMS::size(data)));
}
