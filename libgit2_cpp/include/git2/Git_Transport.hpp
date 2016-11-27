#pragma once
#include "precompiled.hpp"
class Git_Transport : public Provider<git_transport>
{
public:
	Git_Transport(git_transport*);
	~Git_Transport()=default;
	LIBGIT2_TRANSPORT_INTERFACE
};

