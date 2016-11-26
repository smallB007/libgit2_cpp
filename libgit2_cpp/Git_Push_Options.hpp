#pragma once
#include "stdafx.h"
class Git_Push_Options : public Guts_Provider<git_push_options,Memory_Management<NO>>
{
public:
	Git_Push_Options();
	~Git_Push_Options()=delete;
};

