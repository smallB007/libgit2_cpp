#pragma once
#include "stdafx.h"
#include "Git_Object_ID.hpp"

class Git_Commit_ID : public Git_Object_ID
{
	
public:
	Git_Commit_ID(git_oid* git_oid);
	~Git_Commit_ID();

	
};

