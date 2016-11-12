#include "Git_Object_ID.hpp"



Git_Object_ID::Git_Object_ID( git_oid* c_git_oid): Provider(c_git_oid,nullptr)
{
#pragma message("Warning nullptr as a deleter")
}

