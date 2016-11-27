#pragma once
#include "precompiled.hpp"
#include "Git_Diff_File.hpp"
class Git_Diff_Delta : Guts_Provider<git_diff_delta,Memory_Management<NO>>
{
public:
	Git_Diff_Delta(git_diff_delta);
#pragma message("ToDo each class that doesn't have mem management should have the above ctor instead of the one with ptr")
	~Git_Diff_Delta()=default;
	LIBGIT2_DIFF_DELTA_INTERFACE
	git_delta_t 	status()const;
	uint32_t 	flags()const;
	uint16_t 	similarity()const;
	uint16_t 	nfiles()const;
	Git_Diff_File 	old_file()const;
	Git_Diff_File 	new_file()const;
};