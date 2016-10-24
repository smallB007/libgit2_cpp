#include "Git_Config.hpp"



Git_Config::Git_Config(git_config* git_config):Provider(git_config_free)
{
	c_git_guts_ = git_config;
}

Git_Config::Git_Config():Provider(git_config_free)
{
	int res = git_config_new(&c_git_guts_);
	/*
	This object is empty, so you have to add a file to it before you can do anything with it.
	*/
	if (FAILED(res) || FAILED(c_git_guts_))
	{
		throw - 1;
	}
}

void Git_Config::add_backend()
{
	int res = git_config_add_backend(c_git_guts_, nullptr/*git_config_backend *file*/, git_config_level_t(-1)/*git_config_level_t level*/, 0/*int force*/);
	if (FAILED(res))
	{
		throw - 1;
	}
}


