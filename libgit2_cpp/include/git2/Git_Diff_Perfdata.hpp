#pragma once
#include "precompiled.hpp"

class Git_Diff_Perfdata : public Guts_Provider<git_diff_perfdata,Memory_Management<NO>>
{
public:
	Git_Diff_Perfdata(git_diff_perfdata);
	~Git_Diff_Perfdata()=default;
	LIBGIT2_DIFF_PERFDATA_INTERFACE
	unsigned int 	version()const;
	size_t 	stat_calls()const;
	size_t 	oid_calculations()const;
};

