#include "Git_Config_Level.hpp"

Git_Config_Level::Git_Config_Level(git_config_level_t config_level) : c_git_config_level_{config_level}
{
}

void Git_Config_Level::set_level(const Git_Config_Level & config_level)
{
	c_git_config_level_ = config_level.c_git_config_level_;
}

