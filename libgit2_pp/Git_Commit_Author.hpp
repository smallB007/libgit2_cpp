#pragma once
#include "stdafx.h"
class Git_Commit_Author
{
	const git_signature* c_git_signature_;
public:
	Git_Commit_Author(const git_signature*);
	~Git_Commit_Author();
	std::string name()const;
	std::string email()const;
};

