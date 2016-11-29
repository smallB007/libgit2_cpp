#pragma once
#include "precompiled.hpp"
class Git_Tree_Entry :  public Provider<git_tree_entry>
{
public:
	Git_Tree_Entry(const git_tree_entry*);
	~Git_Tree_Entry()=default;
	LIBGIT2_TREE_ENTRY_INTERFACE
	uint16_t attr()const;
	uint16_t filename_len()const;
	const Git_Object_ID oid()const;
	string_t filename()const;
};

