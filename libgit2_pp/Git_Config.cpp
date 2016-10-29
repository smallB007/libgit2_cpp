#include "Git_Config.hpp"
#include "Git_Config_Backend.hpp"
#include "Scoped_Deleter.hpp"

template<Git_Config::E_Path_Type e_path>
file_path_t Git_Config::find_path_helper_() const
{
	typedef int(*git_config_find_t)(git_buf*);
	git_config_find_t git_config_find{};
	switch (e_path)
	{
	case GLOBAL:
		git_config_find = git_config_find_global;
		break;
	case PROGRAM:
		git_config_find = git_config_find_programdata;
		break;
	case SYSTEM:
		git_config_find = git_config_find_system;
		break;
	case XDG:
		git_config_find = git_config_find_xdg;
		break;
	}

	size_t file_path_length{ 256 };
	Scoped_Deleter<git_buf> c_git_buf_out(file_path_length);
	int res = git_config_find(c_git_buf_out);

	if (!FAILED(res))
	{

		file_path_t file_path(c_git_buf_out.get_string());
		return file_path;
	}
	else
	{
		throw - 1;
	}
}

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

void Git_Config::delete_entry(const string_t & name)
{
	int res = git_config_delete_entry(c_git_guts_, name.c_str());
	if (FAILED(res))
	{
		throw - 1;
	}
}

file_path_t Git_Config::find_global_path() const
{
	return find_path_helper_<GLOBAL>();
}

file_path_t Git_Config::find_program_data_path() const
{
	return find_path_helper_<PROGRAM>();
}

file_path_t Git_Config::find_system_path() const
{
	return find_path_helper_<SYSTEM>();
}


