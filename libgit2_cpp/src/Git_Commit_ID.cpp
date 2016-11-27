#include "Git_Commit_ID.hpp"



Git_Commit_ID::Git_Commit_ID(const git_oid* c_git_oid):Git_Object_ID(/*const_cast<git_oid*>*/(c_git_oid))
{
}

