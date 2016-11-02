#pragma once
#include "stdafx.h"

class Git_Describe : public Provider<git_describe_result>
{
	Git_Describe(git_describe_result*);
	shared_ptr_t<Git_Describe> describe_commit();
};

