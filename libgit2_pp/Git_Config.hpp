#pragma once
#include "stdafx.h"
class Git_Config : public Provider<git_config>
{
public:
	Git_Config(git_config*);
	Git_Config();
LIBGIT2_CONFIG_INTERFACE
	void add_backend();
};

