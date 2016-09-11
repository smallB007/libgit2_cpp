#pragma once
#include "stdafx.h"
class Git_Config
{
	git_config* c_git_config_;
public:
	Git_Config(git_config*);
	~Git_Config();
};

