#include "Git_Config.hpp"
#include "Git_Config_Backend.hpp"


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

void Git_Config::add_backend(const Git_Config_Backend& config_backend, const Git_Config_Level& config_level, bool force)
{
	int res = git_config_add_backend(c_git_guts_, const_cast<git_config_backend*>(&config_backend.c_git_config_backend_), config_level, force);
	
	if (FAILED(res) || GIT_EEXISTS == res)
	{
		throw - 1;
	}
}

void Git_Config::add_file_on_disk(const file_path_t& path, const Git_Config_Level& config_level, bool force)
{
	int res = git_config_add_file_ondisk(c_git_guts_, path.c_str(), config_level, force);

	if (FAILED(res) 
		||	GIT_EEXISTS == res 
		||	GIT_ENOTFOUND == res)
	{
		throw - 1;
	}
}


