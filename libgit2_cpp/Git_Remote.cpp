#include "Git_Remote.hpp"
#include "Git_Refspec.hpp"


Git_Remote::Git_Remote(const string_t& name, const string_t& url):Provider(c_guts_,git_remote_free)
{
#pragma message("Idea this should be the preferred way to create Git_objects")
	check_for_error(git_remote_create(&c_guts_, c_parent_guts(), name.c_str(), url.c_str()));
}

Git_Remote::Git_Remote(git_remote * c_git_remote):Provider(c_git_remote,git_remote_free)
{
#pragma message("Idea I wonder if in case transporting only, nullptr should be passed as a deleter?")
}

void Git_Remote::add_fetch(const string_t & remote_name, const string_t & refspec) const
{
	check_for_error(git_remote_add_fetch(c_parent_guts(), remote_name.c_str(), refspec.c_str()));
}

void Git_Remote::add_push(const string_t & remote_name, const string_t & refspec) const
{
	check_for_error(git_remote_add_push(c_parent_guts(), remote_name.c_str(), refspec.c_str()));
}

git_remote_autotag_option_t Git_Remote::autotag() const
{
#pragma message("Warning native libgit2 type returned")
	return git_remote_autotag(c_guts_);
}

bool Git_Remote::connected() const
{
	return git_remote_connected(c_guts_);
}

Git_Remote Git_Remote::create_anonymous(const string_t & url) const
{
	git_remote* c_git_remote_out;
	check_for_error(git_remote_create_anonymous(&c_git_remote_out, c_parent_guts(), url.c_str()));

	return Git_Remote(c_git_remote_out);
}

Git_Remote Git_Remote::create_with_fetchspec(const string_t & remote_name, const string_t & url, const string_t & fetch) const
{
	git_remote* c_git_remote_out;
	check_for_error(git_remote_create_with_fetchspec(&c_git_remote_out, c_parent_guts(), remote_name.c_str(), url.c_str(), fetch.c_str()));

	return Git_Remote(c_git_remote_out);
}

branch_name_t Git_Remote::default_branch() const
{
	git_buf c_git_buf_out;
#pragma message("Idea perhaps Git_Buf is either unnecessary or can not be exposed as a return type, because always the data it contains is transformed into other type")
	check_for_error(git_remote_default_branch(&c_git_buf_out, c_guts_));
	branch_name_t result(c_git_buf_out.ptr, c_git_buf_out.ptr + c_git_buf_out.size);
#pragma message("Warning check if the size is correct or have to be oned(+-1)")
	return result;
}

void Git_Remote::remove(const string_t& remote_name) const
{
	check_for_error(git_remote_delete(c_parent_guts(),remote_name.c_str()));
}

void Git_Remote::disconnect(const Git_Remote & remote) const
{
	git_remote_disconnect(remote.c_guts_);
}

Git_Remote Git_Remote::duplicate() const
{
	git_remote* c_git_remote_out;
	check_for_error(git_remote_dup(&c_git_remote_out, c_guts_));

	return Git_Remote(c_git_remote_out);
}

Git_Refspec Git_Remote::get_refspec(size_t inx)
{
	const git_refspec * c_git_refspec = git_remote_get_refspec(c_guts_,inx);
	check_for_nullptr(c_git_refspec);

	return Git_Refspec(c_git_refspec);
}
