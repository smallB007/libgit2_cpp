#pragma once
#include "stdafx.h"
#include "Git_Config_Level.hpp"
class Git_Config : public Provider<git_config>
{
private:
	enum E_Path_Type {GLOBAL,PROGRAM,SYSTEM,XDG};
	template<E_Path_Type e>
	file_path_t find_path_helper_()const;
public:
	Git_Config(git_config*);
	Git_Config();
LIBGIT2_CONFIG_INTERFACE
	void add_backend(const Git_Config_Backend& config_backend, const Git_Config_Level& config_level, bool force = false);
	void add_file_on_disk(const file_path_t& path, const Git_Config_Level& config_level = GIT_CONFIG_HIGHEST_LEVEL, bool force = false);
	void delete_entry(const string_t& name);
	file_path_t find_global_path()const;
	file_path_t find_program_data_path()const;
	file_path_t find_system_path()const;
#ifdef _FULL_IMPLEMENTATION_
	git_config_backend_foreach_match
		git_config_delete_multivar
		git_config_entry_free
		git_config_find_programdata
#endif
};

