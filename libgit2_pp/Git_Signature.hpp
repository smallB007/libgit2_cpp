#pragma once
#include "stdafx.h"
class Git_Commit_Author;
class Git_Commit_Time;

class Git_Signature
{
 	const git_signature* c_git_signature_;
public:
	Git_Signature(const git_signature* c_git_signature);
	~Git_Signature();
	std::shared_ptr<Git_Commit_Author> author()const;
	std::string email()const;
	std::shared_ptr<Git_Commit_Time> time()const;
};

