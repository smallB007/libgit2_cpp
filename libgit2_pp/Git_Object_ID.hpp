#pragma once
#include "stdafx.h"
class Git_Object_ID
{
	const git_oid* git_oid_;
public:
	Git_Object_ID(const git_oid* git_oid);
	~Git_Object_ID();

	operator const git_oid*() { return git_oid_; }
	const git_oid* id()const { return git_oid_; }
};

