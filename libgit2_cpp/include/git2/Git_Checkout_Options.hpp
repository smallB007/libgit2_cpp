#pragma once
#include "precompiled.hpp"
class Git_Checkout_Options : public Guts_Provider<git_checkout_options,Memory_Management<NO>>
{
public:
#pragma message("ToDo  [Git_Checkout_Options] - implement setters and getters")
	Git_Checkout_Options();
	void set_default();
};

