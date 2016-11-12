#pragma once
#include "stdafx.h"
class Git_Filter : public Guts_Provider<git_filter,Memory_Management<NO>>
{
public:
	Git_Filter(git_filter);
	~Git_Filter()=default;
};

