#pragma once
#include "precompiled.hpp"
class Git_Config_Level : public Parent_Provider
{
	git_config_level_t c_git_config_level_{ GIT_CONFIG_HIGHEST_LEVEL };
public:
	Git_Config_Level(git_config_level_t config_level = GIT_CONFIG_HIGHEST_LEVEL);
	~Git_Config_Level() = default;
	operator git_config_level_t()const { return c_git_config_level_; }
	Git_Config_Level get_level() const { return c_git_config_level_; }
	void set_level(const Git_Config_Level& config_level);
};

