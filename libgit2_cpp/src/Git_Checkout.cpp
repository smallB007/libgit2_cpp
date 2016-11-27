#include "Git_Checkout.hpp"



Git_Checkout::Git_Checkout(GIT_PP_CHECKOUT_OPTIONS_INIT init_opts) 
{
	/*c_git_checkout_options_.{ GIT_CHECKOUT_OPTIONS_VERSION }
	{ GIT_CHECKOUT_OPTIONS_INIT }*/
}

void Git_Checkout::head()const
{
	const git_checkout_options* c_git_checkout_opt = c_git_checkout_options_.c_guts();
	
	check_for_error(git_checkout_head(c_parent_guts(), c_git_checkout_opt));
}

void Git_Checkout::index() const
{
	const git_checkout_options* c_git_checkout_opt = c_git_checkout_options_.c_guts();
	check_for_error(git_checkout_index(c_parent_guts(), nullptr/*index to be checked out (or NULL to use repository index)*/, c_git_checkout_opt));
#pragma message("ToDo nullptr passed as arg")
	//this		^^^ can return non-zero from notify_cb from c_git_checkout_opt
}

void Git_Checkout::set_checkout_options(Git_Checkout_Options && checkout_options)
{
	c_git_checkout_options_ = NMS::move(checkout_options);
}

void Git_Checkout::tree()const
{
	const git_checkout_options* c_git_checkout_opt = c_git_checkout_options_.c_guts();
	check_for_error(git_checkout_tree(c_parent_guts(), nullptr, c_git_checkout_opt));
#pragma message("ToDo nullptr passed as arg")
	//this		^^^ can return non-zero from notify_cb from c_git_checkout_opt
}