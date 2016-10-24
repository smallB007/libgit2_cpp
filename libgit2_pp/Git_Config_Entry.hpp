#pragma once
#include "stdafx.h"
class Git_Config_Entry : public Provider<git_config_entry>
{
public:
	Git_Config_Entry();
	LIBGIT2_CONFIG_ENTRY_INTERFACE
	string_t name()const;
	string_t value()const;
	Git_Config_Level level()const;
	/**
	free
	payload
	*/
};

