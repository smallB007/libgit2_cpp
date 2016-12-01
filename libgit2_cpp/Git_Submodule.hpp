#pragma once
#include "precompiled.hpp"
class Git_Submodule :  public Provider<git_submodule>
{
public:
	Git_Submodule();
	Git_Submodule(git_submodule*);
	~Git_Submodule()=default;
	LIBGIT2_SUBMODULE_INTERFACE
		void add_finalize()const;
	shared_ptr_t<Git_Submodule> Git_Submodule::add_setup(const std::string_view& url, const std::string_view& path, bool use_gitlink) const;
	void add_to_index(int write_index)const;
	string_t branch()const;
	git_submodule_recurse_t fetch_recurse_submodules()const;
	shared_ptr_t<Git_Object_ID> head_id()const;
	git_submodule_ignore_t ignore()const;
	shared_ptr_t<Git_Object_ID> index_id()const;
	unsigned int location()const;
	shared_ptr_t<Git_Submodule> lookup(const std::string_view&)const;
	string_t name()const;
	shared_ptr_t<Git_Repo> open()const;
	shared_ptr_t<Git_Repo> owner()const;
	string_t path()const;
	void reload(bool force)const;
	shared_ptr_t<Git_Repo> repo_init(bool use_gitlink)const;
	string_t resolve_url(const std::string_view&)const;
	void set_branch(const std::string_view&)const;
	void set_url(const std::string_view&)const;
	void sync()const;
	string_t get_url()const;
	shared_ptr_t<Git_Object_ID> wd_id()const;
#ifdef _FULL_IMPLEMENTATION_
	git_submodule_foreach
	git_submodule_set_fetch_recurse_submodules

		git_submodule_set_ignore
		git_submodule_set_update
		git_submodule_status
		git_submodule_update
		git_submodule_update_init_options
		git_submodule_update_strategy
#endif
};

