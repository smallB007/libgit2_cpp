#pragma once
#include "stdafx.h"
class Git_Buf
{
	const git_buf* c_git_buf_{nullptr};
public:
	Git_Buf(const git_buf* c_git_buf);
	~Git_Buf();
};

