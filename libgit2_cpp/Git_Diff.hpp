#pragma once
#include "stdafx.h"
class Git_Diff : public Provider<git_diff>
{
public:
	Git_Diff(git_diff*);
	~Git_Diff()=default;
	LIBGIT2_DIFF_INTERFACE
		//shared_ptr_t<Git_Buf>	blob_to_buffer();
};

