#pragma once
#include "stdafx.h"
class Git_Commit_Time
{
	const git_time c_git_time_;
public:
	Git_Commit_Time(const git_time);
	~Git_Commit_Time();
};

