#pragma once
#include "stdafx.h"
class Git_Config
{
	git_config* c_git_config_{};
public:
	git_config* c_guts() const { return c_git_config_; };
	operator git_config*()const { return c_git_config_; }
	Git_Config(git_config*);
	~Git_Config();
};

