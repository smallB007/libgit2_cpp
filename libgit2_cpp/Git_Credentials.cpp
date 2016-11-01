#include "Git_Credentials.hpp"

Git_Credentials::Git_Credentials():Provider(git_cred_free)
{
	check_for_error(git_cred_default_new(&c_git_guts_));
}

Git_Credentials::Git_Credentials(git_cred * c_git_cred):Provider(git_cred_free)
{
	c_git_guts_ = c_git_cred;
}

bool Git_Credentials::has_username() const
{
	return git_cred_has_username(c_git_guts_);
}

shared_ptr_t<Git_Credentials> Git_Credentials::ssh_key_from_agent(const string_t &username)
{
	git_cred* c_git_cred_out;
	check_for_error(git_cred_ssh_key_from_agent(&c_git_cred_out, username.c_str()));

	return make_shared_ver<Git_Credentials>(c_git_cred_out);
}

shared_ptr_t<Git_Credentials> Git_Credentials::ssh_key_from_memory(const string_t& username, const string_t & public_key, const string_t & private_key, const string_t & passphrase)
{
	git_cred* c_git_cred_out;
	check_for_error(git_cred_ssh_key_memory_new(&c_git_cred_out, username.c_str(),public_key.c_str(),private_key.c_str(),passphrase.c_str()));

	return make_shared_ver<Git_Credentials>(c_git_cred_out);
}

shared_ptr_t<Git_Credentials> Git_Credentials::ssh_key_create(const string_t& username, const string_t & public_key, const string_t & private_key, const string_t & passphrase)
{
	git_cred* c_git_cred_out;
	check_for_error(git_cred_ssh_key_new(&c_git_cred_out, username.c_str(), public_key.c_str(), private_key.c_str(), passphrase.c_str()));

	return make_shared_ver<Git_Credentials>(c_git_cred_out);
}

shared_ptr_t<Git_Credentials> Git_Credentials::create_username(const string_t& username)
{
	git_cred* c_git_cred_out;
	check_for_error(git_cred_username_new(&c_git_cred_out, username.c_str()));

	return make_shared_ver<Git_Credentials>(c_git_cred_out);
}

shared_ptr_t<Git_Credentials> Git_Credentials::create_userpass_plain_text(const string_t & username, const string_t& pass)
{
	git_cred* c_git_cred_out;
	check_for_error(git_cred_userpass_plaintext_new(&c_git_cred_out, username.c_str(),pass.c_str()));

	return make_shared_ver<Git_Credentials>(c_git_cred_out);
}
