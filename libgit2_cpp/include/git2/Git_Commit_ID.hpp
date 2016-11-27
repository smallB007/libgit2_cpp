#pragma once
#include "precompiled.hpp"
#include "Git_Object_ID.hpp"

class Git_Commit_ID : public Git_Object_ID
{
	
public:
	Git_Commit_ID(const git_oid*);
	~Git_Commit_ID() = default;
};

