#pragma once
#include "precompiled.hpp"
class Git_Index_Entry : public Guts_Provider<git_index_entry,Memory_Management<NO>>
{
public:
	Git_Index_Entry(git_index_entry );
	~Git_Index_Entry()=default;
	LIBGIT2_INDEX_ENTRY_INTERFACE
		git_index_time 	ctime()const;
	git_index_time 	mtime()const;
	uint32_t 	dev()const;
	uint32_t 	ino()const;
	uint32_t 	mode()const;
	uint32_t 	uid()const;
	uint32_t 	gid()const;
	uint32_t 	file_size()const;
	git_oid 	id()const;
	uint16_t 	flags()const;
	uint16_t 	flags_extended()const;
	string_t 	path()const;
};

