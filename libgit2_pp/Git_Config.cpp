#include "Git_Config.hpp"



Git_Config::Git_Config(git_config* git_config) :c_git_config_{ git_config }
{
}


Git_Config::~Git_Config()
{
	git_config_free(c_git_config_);
}
