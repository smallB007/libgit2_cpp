#pragma once
#include "stdafx.h"
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
	branch_name_t default_branch()const;
	void remove(const string_t& remote_name)const;
	void disconnect(const Git_Remote&)const;
	Git_Remote duplicate()const;
	Git_Refspec get_refspec(size_t inx);
#ifdef _FULL_IMPLEMENTATION_
	git_remote_connect
		git_remote_download
		git_remote_fetch
		git_remote_get_fetch_refspecs
		git_remote_get_push_refspecs
		git_remote_init_callbacks
#endif
};

