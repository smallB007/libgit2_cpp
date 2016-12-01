#include "Git_Submodule.hpp"
#include "Git_Object_ID.hpp"
#include "Git_Repo.hpp"
#include "Converters.hpp"
Git_Submodule::Git_Submodule():Provider(c_guts_,git_submodule_free)
{
	check_for_error(git_submodule_init(c_guts_, true /*overwrite*/));
#pragma message("ToDo true shouldn't be here")
}

Git_Submodule::Git_Submodule(git_submodule * c_git_submodule):Provider(c_git_submodule,git_submodule_free)
{
}

void Git_Submodule::add_finalize() const
{
	check_for_error(git_submodule_add_finalize(c_guts_));

}

shared_ptr_t<Git_Submodule> Git_Submodule::add_setup(const std::string_view& url, const std::string_view& path, bool use_gitlink) const
{
	git_submodule* c_git_submodule_out;
	check_for_error(git_submodule_add_setup(&c_git_submodule_out, c_parent_guts(), url.data(), path.data(), use_gitlink));

	return make_shared_ver<Git_Submodule>(c_git_submodule_out);
}

void Git_Submodule::add_to_index(int write_index) const
{
	check_for_error(git_submodule_add_to_index(c_guts_, write_index));
}

string_t Git_Submodule::branch() const
{
	const char * c_str_branch = git_submodule_branch(c_guts_);
	check_for_nullptr(c_str_branch);

	return c_str_branch;
}

git_submodule_recurse_t Git_Submodule::fetch_recurse_submodules() const
{
	git_submodule_recurse_t c_git_submodule_recurse_t = git_submodule_fetch_recurse_submodules(c_guts_);

	return c_git_submodule_recurse_t;
#pragma message("Warning native libgit2")
}

shared_ptr_t<Git_Object_ID> Git_Submodule::head_id() const
{
	const git_oid * c_git_oid = git_submodule_head_id(c_guts_);

	return Factory_Git_Object<Git_Object_ID>::create_ptr(c_git_oid);
}

git_submodule_ignore_t Git_Submodule::ignore() const
{
	git_submodule_ignore_t result = git_submodule_ignore(c_guts_);
#pragma message("Warning probably should be in different class")
	return result;
}

shared_ptr_t<Git_Object_ID> Git_Submodule::index_id() const
{
	const git_oid * c_git_oid = git_submodule_index_id(c_guts_);

	return Factory_Git_Object<Git_Object_ID>::create_ptr(c_git_oid);
}

unsigned int Git_Submodule::location() const
{
	unsigned int location_status;
	check_for_error(git_submodule_location(&location_status, c_guts_));

	return location_status;
}

shared_ptr_t<Git_Submodule> Git_Submodule::lookup(const std::string_view & name) const
{
	git_submodule *c_git_submodule_out;
	check_for_error(git_submodule_lookup(&c_git_submodule_out, c_parent_guts(), name.data()));

	return shared_ptr_t<Git_Submodule>();
}

string_t Git_Submodule::name() const
{
	const char * c_name = git_submodule_name(c_guts_);
	check_for_nullptr(c_name);

	return c_name;
}

shared_ptr_t<Git_Repo> Git_Submodule::open() const
{
	git_repository * c_git_repository_out;
	check_for_error(git_submodule_open(&c_git_repository_out, c_guts_));

	return Factory_Git_Object<Git_Repo>::create_ptr(c_git_repository_out);
}

shared_ptr_t<Git_Repo> Git_Submodule::owner() const
{
	git_repository * c_git_repository  = git_submodule_owner(c_guts_);
	check_for_nullptr(c_git_repository);

	return Factory_Git_Object<Git_Repo>::create_ptr(c_git_repository);

}

string_t Git_Submodule::path() const
{
	const char * c_path = git_submodule_path(c_guts_);
	check_for_nullptr(c_path);

	return c_path;
}

void Git_Submodule::reload(bool force) const
{
	check_for_error(git_submodule_reload(c_guts_, force));
}

shared_ptr_t<Git_Repo> Git_Submodule::repo_init(bool use_gitlink) const
{
	git_repository * c_git_repository_out;
	check_for_error(git_submodule_repo_init(&c_git_repository_out, c_guts_, use_gitlink));
	check_for_nullptr(c_git_repository_out);

	return shared_ptr_t<Git_Repo>();
}

string_t Git_Submodule::resolve_url(const std::string_view & relativeUrl) const
{
	git_buf c_git_buf_out;
	check_for_error(git_submodule_resolve_url(&c_git_buf_out, c_parent_guts(), relativeUrl.data()));

	return git_buf_to_string(c_git_buf_out);
}

void Git_Submodule::set_branch(const std::string_view & branchName) const
{
	check_for_error(git_submodule_set_branch(c_parent_guts(), git_submodule_name(c_guts_), branchName.data()));
}

void Git_Submodule::set_url(const std::string_view & url) const
{
	check_for_error(git_submodule_set_url(c_parent_guts(), git_submodule_name(c_guts_), url.data()));
}

void Git_Submodule::sync() const
{
	check_for_error(git_submodule_sync(c_guts_));
}

string_t Git_Submodule::get_url() const
{
	const char * c_url = git_submodule_url(c_guts_);
	
	return c_url;
}

shared_ptr_t<Git_Object_ID> Git_Submodule::wd_id() const
{
	const git_oid * c_git_oid = git_submodule_wd_id(c_guts_);

	return Factory_Git_Object<Git_Object_ID>::create_ptr(c_git_oid);
}

