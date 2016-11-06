#pragma once
#include "stdafx.h"
class Git_Buf : public Provider<git_buf>
{
public:
	Git_Buf(git_buf* c_git_buf);
	~Git_Buf()=default;
LIBGIT2_BUF_INTERFACE
	bool contains_null()const;
	void grow(const NMS::size_t target_size);
	bool is_binary()const;
	void set_data(const NMS::vector<char>& data);
};

