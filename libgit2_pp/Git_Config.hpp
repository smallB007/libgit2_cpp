#pragma once
#include "stdafx.h"
#include "Git_Config_Level.hpp"
class Git_Config : public Provider<git_config>
{
public:
	Git_Config(git_config*);
	Git_Config();
LIBGIT2_CONFIG_INTERFACE
	void add_backend(const Git_Config_Backend& config_backend, const Git_Config_Level& config_level, bool force = false);
	void add_file_on_disk(const file_path_t& path, const Git_Config_Level& config_level = GIT_CONFIG_HIGHEST_LEVEL, bool force = false);
};

