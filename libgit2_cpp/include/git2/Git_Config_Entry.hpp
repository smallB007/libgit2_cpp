#pragma once
#include "precompiled.hpp"
class Git_Config_Entry : public Provider<git_config_entry>
{
public:
//	Git_Config_Entry();
	Git_Config_Entry(git_config_entry*);
	LIBGIT2_CONFIG_ENTRY_INTERFACE
	string_t name()const;
	string_t value()const;
	Git_Config_Level level()const;
	/**
	free
	payload
	*/
};

