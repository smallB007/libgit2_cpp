#include "Git_Config_Backend.hpp"
#include "Git_Config.hpp"
#include "Git_Config_Level.hpp"
#include "Git_Config_Entry.hpp"

Git_Config_Backend::Git_Config_Backend()
{
	int res = git_config_init_backend(&c_git_config_backend_, GIT_CONFIG_BACKEND_INIT);
	if (FAILED(res))
	{
		throw - 1;
	}
}

Git_Config_Backend& Git_Config_Backend::operator=(const git_config_backend * c_git_config_backend)
{
	c_git_config_backend_ = *c_git_config_backend;
	return *this;
}

Git_Config_Backend::Git_Config_Backend(git_config_backend* c_git_config_backend) :c_git_config_backend_{ *c_git_config_backend }
{
	
}

Git_Config_Backend::~Git_Config_Backend()
{
	c_git_config_backend_.free(&c_git_config_backend_);
}

void Git_Config_Backend::add_backend(const Git_Config & cfg, const Git_Config_Backend & file, const Git_Config_Level & level, bool force)
{
	int res = git_config_add_backend(const_cast<git_config*>(cfg.c_guts()), const_cast<git_config_backend*>(&file.c_git_config_backend_), level.get_level(), force);
#pragma message("ToDo ^^^ const_cast on type of c_git_guts_ should be used here")
	if (FAILED(res) || GIT_EEXISTS == res)
	{
		throw - 1;
	}
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

void Git_Config_Backend::open(const Git_Config_Level& config_level ) 
{
	int res = c_git_config_backend_.open(&c_git_config_backend_, config_level.get_level());
	if (FAILED(res))
	{
		throw - 1;
	}
}

shared_ptr_t<Git_Config_Entry> Git_Config_Backend::get(const string_t& key)
{
	git_config_entry* c_git_config_entry_out;
	int res = c_git_config_backend_.get(&c_git_config_backend_, key.c_str(), &c_git_config_entry_out);
	if (FAILED(res))
	{
		throw - 1;
	}

	return make_shared_ver<Git_Config_Entry>(c_git_config_entry_out);
}

void Git_Config_Backend::set(const string_t & key, const string_t & value)
{
	int res = c_git_config_backend_.set(&c_git_config_backend_, key.c_str(), value.c_str());
	if (FAILED(res))
	{
		throw - 1;
	}
}

void Git_Config_Backend::del(const string_t & key)
{
	int res = c_git_config_backend_.del(&c_git_config_backend_,key.c_str());
	if (FAILED(res))
	{
		throw - 1;
	}
}

shared_ptr_t<Git_Config_Backend> Git_Config_Backend::snapshot()
{
	git_config_backend* c_git_config_backend_out;
	int res = c_git_config_backend_.snapshot(&c_git_config_backend_out, &c_git_config_backend_);
	if (FAILED(res))
	{
		throw - 1;
	}

	return make_shared_ver<Git_Config_Backend>(c_git_config_backend_out);
}

bool Git_Config_Backend::lock()
{
	int res = c_git_config_backend_.lock(&c_git_config_backend_);

	return FAILED(res) ? false : true;
}

bool Git_Config_Backend::unlock()
{
	int success{};
	int res = c_git_config_backend_.unlock(&c_git_config_backend_, success);
	if (FAILED(res))
	{
		throw - 1;
	}

	return success;
}




