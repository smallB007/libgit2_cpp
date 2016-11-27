#pragma once
#include "precompiled.hpp"
#include "Parent_Provider.hpp"
#include "Git_Checkout_Options.hpp"
class Git_Checkout : public Parent_Provider
{
	Git_Checkout_Options c_git_checkout_options_;
public:
	enum GIT_PP_CHECKOUT_OPTIONS_INIT{ DEFAULT = GIT_CHECKOUT_OPTIONS_VERSION};
	void head()const;
	void index()const;
	void tree()const;
	void set_checkout_options(Git_Checkout_Options&&);
	Git_Checkout(GIT_PP_CHECKOUT_OPTIONS_INIT init_opts = GIT_PP_CHECKOUT_OPTIONS_INIT::DEFAULT);
	~Git_Checkout()=default;
};

