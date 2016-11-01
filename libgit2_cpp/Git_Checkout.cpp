#include "Git_Checkout.hpp"



Git_Checkout::Git_Checkout(GIT_PP_CHECKOUT_OPTIONS_INIT init_opts):c_git_checkout_options_(init_opts)
{
}

void Git_Checkout::head()const
{
	git_checkout_options c_git_checkout_opt = c_git_checkout_options_.c_guts();
	
	int res = git_checkout_head(c_parent_guts(), &c_git_checkout_opt);
	//this		^^^ can return non-zero from notify_cb from c_git_checkout_opt
	if (GIT_EUNBORNBRANCH == res)
	{
		throw - 1;
	}
	else if (FAILED(res))
	{
		// const git_error* c_git_error = giterr_last();
		throw - 1;
	}
}

void Git_Checkout::index() const
{
	git_checkout_options c_git_checkout_opt = c_git_checkout_options_.c_guts();
	int res = git_checkout_index(c_parent_guts(), nullptr/*index to be checked out (or NULL to use repository index)*/, &c_git_checkout_opt);
	//this		^^^ can return non-zero from notify_cb from c_git_checkout_opt
	if (FAILED(res))
	{
		throw - 1;
	}
}

void Git_Checkout::set_checkout_options(Git_Checkout_Options && checkout_options)
{
	c_git_checkout_options_ = NMS::move(checkout_options);
}

void Git_Checkout::tree()const
{
	git_checkout_options c_git_checkout_opt = c_git_checkout_options_.c_guts();
	int res = git_checkout_tree(c_parent_guts(), nullptr, &c_git_checkout_opt);
	//this		^^^ can return non-zero from notify_cb from c_git_checkout_opt
	if (FAILED(res))
	{
		throw - 1;
	}
}