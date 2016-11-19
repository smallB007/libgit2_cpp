#pragma once
#include "stdafx.h"
#include "Git_Config_Level.hpp"
#include "Git_Config_Backend.hpp"
class Git_Config : public Provider<git_config>
{
public:
	class Git_Config_Iterator
	{
		git_config_iterator* c_git_config_iterator_;
		const Git_Config& git_config_parent_;
	public:
		Git_Config_Iterator(const Git_Config& gitConfig);
		Git_Config_Iterator(git_config_iterator*, const Git_Config& gitConfig);
		~Git_Config_Iterator();
		Git_Config_Iterator operator++()const;
	};
private:
	mutable	Git_Config_Iterator* git_config_iterator_{};
	Git_Config_Backend git_config_backend_;
	enum E_Path_Type {GLOBAL,PROGRAM,SYSTEM,XDG};
	template<E_Path_Type e>
	path_name_t find_path_helper_()const;
	template<class T>
	class parse_int_helper_;
public:
	Git_Config(git_config*);
	//Git_Config();
LIBGIT2_CONFIG_INTERFACE
	void add_backend(const Git_Config_Backend& config_backend, const Git_Config_Level& config_level, bool force = false);
	void add_file_on_disk(const path_name_t& path, const Git_Config_Level& config_level = GIT_CONFIG_HIGHEST_LEVEL, bool force = false);
	void delete_entry(const string_t& name);
	path_name_t find_global_path()const;
	path_name_t find_program_data_path()const;
	path_name_t find_system_path()const;
	bool get_bool(const string_t&);
	shared_ptr_t<Git_Config_Entry> get_entry(const string_t& varName);
	int32_t get_int32(const string_t& varName);
	int64_t get_int64(const string_t& varName);
	int get_mapped(const string_t & varName)const;
	path_name_t get_path(const string_t & varName)const;
	string_t get_string(const string_t& varName)const;
	string_t get_string_buf(const string_t& varName)const;
	void init_backend();
	Git_Config_Iterator begin()const;
	void lock();
	Git_Config_Iterator next()const;
	shared_ptr_t<Git_Config> open_default()const;
	shared_ptr_t<Git_Config> open_global()const;
	shared_ptr_t<Git_Config> open_level(const Git_Config_Level& configLevel)const;
	shared_ptr_t<Git_Config> open_on_disk(const path_name_t&)const;
	bool parse_bool(const string_t& bool_val)const;
	
	template<class T>
	T parse_int(const string_t&)const;

	path_name_t parse_path(const string_t&)const;

	void set(const string_t& varName, const bool val);
	void set(const string_t& varName, const int32_t val);
	void set(const string_t& varName, const int64_t val);
	void set(const string_t& varName, const string_t& val);
	shared_ptr_t<Git_Config> snapshot()const;
	//int32_t parse()
#ifdef _FULL_IMPLEMENTATION_
	git_config_backend_foreach_match
		git_config_delete_multivar
		git_config_entry_free
		git_config_find_programdata
		git_config_foreach
		git_config_foreach_match
		git_config_get_multivar_foreach
		git_config_iterator_free
		git_config_iterator_glob_new
		git_config_iterator_new
		git_config_lookup_map_value
		git_config_multivar_iterator_new
		git_config_set_multivar
#endif
};

