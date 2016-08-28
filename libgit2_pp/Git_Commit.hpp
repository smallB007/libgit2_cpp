#pragma once
#include "stdafx.h"
class Git_Repo;
class Git_Commit_Author;
class Git_Signature;

class Git_Commit
{
	git_commit* c_git_commit_{nullptr};
	Git_Repo* my_repo_{nullptr};
public:
	Git_Commit(Git_Repo*,std::vector<std::string> files_to_commit, std::string msg);
	~Git_Commit();
	git_commit* get_head_commit()const;
	std::vector< git_commit*> get_parents()const;

//Wrapped libgit2 methods
	void amend();
	std::shared_ptr<Git_Commit_Author> author()const;
	std::string body()const;
	std::shared_ptr<Git_Signature> commiter()const;
#ifdef _FULL_IMPLEMENTATION_
	git_commit_create_buffer
		git_commit_create_from_callback
		git_commit_create_v
#endif



	std::string message()const;
};

