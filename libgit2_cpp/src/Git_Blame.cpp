#include "Git_Blame.hpp"



Git_Blame::Git_Blame(git_blame* c_git_blame): Provider(c_git_blame,git_blame_free)
{
}



