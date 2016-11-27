#include "Git_Checkout_Options.hpp"



Git_Checkout_Options::Git_Checkout_Options()
{
		set_default();
}

void Git_Checkout_Options::set_default()
{
	check_for_error(git_checkout_init_options(&c_guts_, GIT_CHECKOUT_OPTIONS_INIT));
}