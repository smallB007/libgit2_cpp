#pragma once
#include "precompiled.hpp"
class LIBGIT2_CPP_API Git_Buf : public Provider<git_buf>
{
	git_buf c_git_buf_;
public:
	Git_Buf();
	Git_Buf(git_buf* c_git_buf);
	Git_Buf(git_buf&);
	~Git_Buf()=default;
	size_t size()const;
	size_t capacity()const;
	git_buf* head()const;
	string_t get_string()const;
LIBGIT2_BUF_INTERFACE
	bool contains_null()const;
	void grow(const NMS::size_t target_size);
	bool is_binary()const;
	void set_data(const NMS::vector<char>& data);
};

