#pragma once
#include "stdafx.h"
class Git_Index:public Provider<git_index>
{
public:
	Git_Index(git_index*);
};

