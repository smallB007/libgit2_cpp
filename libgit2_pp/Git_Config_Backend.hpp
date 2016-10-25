#pragma once
#include "stdafx.h"

class Git_Config_Backend : public Parent_Provider
{
	friend class Git_Config;
	git_config_backend c_git_config_backend_{ GIT_CONFIG_BACKEND_VERSION };
public:
	Git_Config_Backend();
	~Git_Config_Backend();
	LIBGIT2_CONFIG_BACKEND_INTERFACE
	unsigned version()const;
	bool is_read_only()const;
	const Git_Config config()const;
	shared_ptr_t<Git_Config> open(const Git_Config_Backend& config_backend, const Git_Config_Level& config_level)const;
	
};

