#pragma once
#include "precompiled.hpp"
class Git_Delta : public Guts_Provider<git_delta_t,Memory_Management<NO>>
{
#pragma message("ToDo does it really need to be a class instead of simply enum?")
public:
	Git_Delta();
	~Git_Delta()=default;
};

