#pragma once
#include "precompiled.hpp"
class Git_Object_ID : public Provider<git_oid>
{
	DECLARE_CREATION_AND_DESTRUCTION_PRIVILEGES
	friend class Git_Commit_ID;
	Git_Object_ID(const git_oid* c_git_oid);
	Git_Object_ID( const git_oid& c_git_oid);
public:
	~Git_Object_ID() = default;
};

