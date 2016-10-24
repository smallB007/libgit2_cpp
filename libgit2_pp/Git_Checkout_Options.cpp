#include "Git_Checkout_Options.hpp"



Git_Checkout_Options::Git_Checkout_Options(unsigned ver) :c_git_checkout_options_{ ver }
{
	if (GIT_CHECKOUT_OPTIONS_VERSION == ver)
	{
		set_default();
	}
}

void Git_Checkout_Options::set_default()
{
	int res = git_checkout_init_options(&c_git_checkout_options_, GIT_CHECKOUT_OPTIONS_INIT);
	if (FAILED(res))
	{
		throw - 1;
	}
}