#include "Git_Buf.hpp"



Git_Buf::Git_Buf(git_buf* c_git_buf) :Provider(git_buf_free)
{
	c_git_guts_ = c_git_buf;
}


Git_Buf::~Git_Buf()
{
}

bool Git_Buf::contains_null()const
{
	return git_buf_contains_nul(c_git_guts_);
}

void Git_Buf::grow(const NMS::size_t target_size)
{
	auto res = git_buf_grow(c_git_guts_, target_size);
	if (FAILED(res))
	{
		throw - 1;
	}
}

bool Git_Buf::is_binary()const
{
	return git_buf_is_binary(c_git_guts_);
}

void Git_Buf::set_data(const NMS::vector<char>& data)
{
	auto res = git_buf_set(c_git_guts_, &data, NMS::size(data));
	if (FAILED(res))
	{
		throw - 1;
	}
}
