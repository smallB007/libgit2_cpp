#include "Git_Config_Backend.hpp"
#include "Git_Config.hpp"
#include "Git_Config_Level.hpp"

Git_Config_Backend::Git_Config_Backend()
{
	int res = git_config_init_backend(&c_git_config_backend_, GIT_CONFIG_BACKEND_INIT);
	if (FAILED(res))
	{
		throw - 1;
	}
}


Git_Config_Backend::~Git_Config_Backend()
{
}

unsigned Git_Config_Backend::version()const
{
	return c_git_config_backend_.version;
}

bool Git_Config_Backend::is_read_only() const
{
	return c_git_config_backend_.readonly;
}

const Git_Config Git_Config_Backend::config() const
{
	return Git_Config(c_git_config_backend_.cfg);
}

shared_ptr_t<Git_Config> Git_Config_Backend::open(const Git_Config_Backend& config_backend, const Git_Config_Level& config_level ) const
{
	c_git_config_backend_.open((const_cast<git_config_backend*>(&config_backend.c_git_config_backend_)), config_level.get_level());
	return shared_ptr_t<Git_Config>();
}
