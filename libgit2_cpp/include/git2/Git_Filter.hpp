#pragma once
#include "precompiled.hpp"
class Git_Filter : public Guts_Provider<git_filter,Memory_Management<NO>>
{
public:
	Git_Filter(git_filter);
	~Git_Filter()=default;
};

