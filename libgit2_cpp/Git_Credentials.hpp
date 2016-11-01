#pragma once
#include "stdafx.h"
#include "Provider.hpp"

class Git_Credentials : Provider<git_cred>
{
public:
	Git_Credentials();
	Git_Credentials(git_cred*);
	LIBGIT2_CREDENTIALS_INTERFACE
	bool has_username()const;
	shared_ptr_t<Git_Credentials> ssh_key_from_agent(const string_t&);
	shared_ptr_t<Git_Credentials> ssh_key_from_memory(const string_t&, const string_t&, const string_t&, const string_t&);
	shared_ptr_t<Git_Credentials> ssh_key_create(const string_t&, const string_t&, const string_t&, const string_t&);
	shared_ptr_t<Git_Credentials> create_username(const string_t&);
	shared_ptr_t<Git_Credentials> create_userpass_plain_text(const string_t&, const string_t&);

#ifdef _FULL_IMPLEMENTATION_
	git_cred_ssh_custom_new
		git_cred_ssh_interactive_new
		git_cred_userpass
#endif
};
