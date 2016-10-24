#pragma once
#include "stdafx.h"
class Git_Checkout_Options
{
	git_checkout_options c_git_checkout_options_{ GIT_CHECKOUT_OPTIONS_INIT };
public:
#pragma message("ToDo [Git_Checkout_Options] - implement setters and getters")
	Git_Checkout_Options(unsigned ver = GIT_CHECKOUT_OPTIONS_INIT);
	git_checkout_options c_guts() const { return c_git_checkout_options_; }
	void set_default();
};

