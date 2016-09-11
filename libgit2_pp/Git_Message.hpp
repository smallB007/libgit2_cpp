#pragma once
#include "stdafx.h"
class Git_Message
{
	git_repository* c_git_repo_{};
	git_buf* c_git_buf_{};

public:
	Git_Message(git_repository* c_git_repo);
	~Git_Message();
};

