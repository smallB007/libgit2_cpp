#pragma once
#include "precompiled.hpp"
#include <string_view>
class Git_Remote : public Provider<git_remote>
{
public:
	Git_Remote(const string_t& name, const string_t& url);
	Git_Remote(git_remote*);
	~Git_Remote()=default;
	LIBGIT2_REMOTE_INTERFACE
	void add_fetch(const string_t& remote_name, const string_t& refspec)const;
	void add_push(const string_t& remote_name, const string_t& refspec)const;
	git_remote_autotag_option_t autotag()const;
	bool connected()const;
	Git_Remote create_anonymous(const string_t& url)const;
	Git_Remote create_with_fetchspec(const string_t& remote_name, const string_t& url,const string_t& fetch)const;
	string_t default_branch()const;
	void remove(const string_t& remote_name)const;
	void disconnect(const Git_Remote&)const;
	Git_Remote duplicate()const;
	Git_Refspec get_refspec(size_t inx);
	bool is_valid_name(const std::string_view&)const;
	template<class Result = set_t<string_t>>
	Result list()const;
	Git_Remote lookup(const std::string_view&)const;
	string_t name()const;
	shared_ptr_t<Git_Repo> owner()const;
	int prune_refs()const;
	void push(const Git_Strarray& refspecs, const Git_Push_Options& opts) const;
	string_t push_url()const;
	void set_url(const std::string_view& url) const;
	void stop()const;
	string_t url()const;
#ifdef _FULL_IMPLEMENTATION_
	git_remote_connect
		git_remote_download
		git_remote_fetch
		git_remote_get_fetch_refspecs
		git_remote_get_push_refspecs
		git_remote_init_callbacks
		git_remote_ls
		git_remote_prune
		git_remote_stats
		git_remote_update_tips
		git_remote_upload
#endif
};

