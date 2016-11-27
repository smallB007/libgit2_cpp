#pragma once
#include "precompiled.hpp"

class Git_Config_Backend : public Parent_Provider
{
	friend class Git_Config;
	git_config_backend c_git_config_backend_{ GIT_CONFIG_BACKEND_VERSION };
	/*^^^ may need to be changed int ptr*/
public:
	Git_Config_Backend(git_config_backend*);
	Git_Config_Backend();
	Git_Config_Backend& operator=(const git_config_backend*);
	~Git_Config_Backend();
	operator git_config_backend() { return c_git_config_backend_; }
	LIBGIT2_CONFIG_BACKEND_INTERFACE
		/*All or parts of this interface may need to be moved into Git_Config*/
	void add_backend(const Git_Config& cfg,const Git_Config_Backend& file, const Git_Config_Level& level, bool force);
	unsigned version()const;
	bool is_read_only()const;
	const Git_Config config()const;
	void open(const Git_Config_Level& config_level);
	shared_ptr_t<Git_Config_Entry> get(const string_t& key);
	void set(const string_t& key, const string_t& value);
	void del(const string_t& key);
	shared_ptr_t<Git_Config_Backend> snapshot();
	bool lock();
	bool unlock();
#ifdef _FULL_IMPLEMENTATION_
	set_multivar
	del_multivar
		iterator
		free
#endif
	
};

