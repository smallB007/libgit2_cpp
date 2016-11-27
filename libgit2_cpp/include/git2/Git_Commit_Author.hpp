#pragma once
#include "precompiled.hpp"
class Git_Commit_Author
{
	const git_signature* c_git_signature_{};
	bool should_free_ = false;
public:
	Git_Commit_Author(const git_signature*);
	Git_Commit_Author(const char* name,const char* email);
	~Git_Commit_Author();
	NMS::string name()const;
	NMS::string email()const;
};

