#pragma once
#include "precompiled.hpp"
class Git_Transfer_Progress : Guts_Provider<git_transfer_progress,Memory_Management<NO>>
{
public:
	Git_Transfer_Progress();
	
	~Git_Transfer_Progress()=default;
	LIBGIT2_TRANSFER_PROGRESS_INTERFACE
	unsigned int 	total_objects()const;
	unsigned int 	indexed_objects()const;
	unsigned int 	received_objects()const;
	unsigned int 	local_objects()const;
	unsigned int 	total_deltas()const;
	unsigned int 	indexed_deltas()const;
	size_t 	received_bytes()const;
};

