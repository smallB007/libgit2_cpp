#include "Git_Transport.hpp"



Git_Transport::Git_Transport(git_transport* c_git_transport):Provider(c_git_transport,nullptr)
{
#pragma message("Warning nullptr as a deleter passed")
}

