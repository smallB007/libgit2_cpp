#pragma once
#include "precompiled.hpp"
class Git_Diff_File: public Guts_Provider<git_diff_file,Memory_Management<NO>>
{
public:
	Git_Diff_File(git_diff_file);
	~Git_Diff_File()=default;
	LIBGIT2_DIFF_FILE_INTERFACE
	Git_Object_ID     id()const;
	string_t		  path()const;
	git_off_t		  size()const;
	uint32_t		  flags()const;
	uint16_t		  mode()const;
};

