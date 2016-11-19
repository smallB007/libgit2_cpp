#include "Git_Object_ID.hpp"



Git_Object_ID::Git_Object_ID(const git_oid* c_git_oid): Provider(/*const_cast<git_oid*>*/(c_git_oid),nullptr)
{
#pragma message("Warning nullptr as a deleter")
}

Git_Object_ID::Git_Object_ID(const git_oid & c_git_oid): Provider(c_guts_,nullptr)
{
#pragma message("Warning nullptr as a deleter")
	*c_guts_ = c_git_oid;
#pragma message("Error this will blow^^^")
}

