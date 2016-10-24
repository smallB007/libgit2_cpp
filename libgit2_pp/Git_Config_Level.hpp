#pragma once
#include "stdafx.h"
class Git_Config_Level : public Parent_Provider
{
	git_config_level_t c_git_config_level_{ GIT_CONFIG_HIGHEST_LEVEL };
public:
	Git_Config_Level();
	Git_Config_Level(git_config_level_t);
	~Git_Config_Level() = default;

	git_config_level_t get_level() const { return c_git_config_level_; }
};

