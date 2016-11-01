#include "Git_Object_ID.hpp"



Git_Object_ID::Git_Object_ID(const git_oid* c_git_oid): Provider(nullptr)
{
	c_git_guts_ = { const_cast<git_oid*>(c_git_oid) };
}

