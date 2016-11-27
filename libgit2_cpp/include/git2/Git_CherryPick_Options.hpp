#pragma once
#include "precompiled.hpp"

class Git_CherryPick_Options : public Guts_Provider<git_cherrypick_options,Memory_Management<NO>>
{
	git_cherrypick_options c_git_cherrypick_options_{ GIT_CHERRYPICK_OPTIONS_VERSION };
public:
#pragma message("ToDo  [Git_CherryPick_Options] - implement setters and getters")
	Git_CherryPick_Options(unsigned ver = GIT_CHERRYPICK_OPTIONS_VERSION);
	const git_cherrypick_options* c_guts() const { return &c_git_cherrypick_options_; }
	void set_default();
	void set_version(unsigned int version);
	void set_mainline(unsigned int mainline);
	void set_merge_options(const Git_Merge_Options&);
	void set_checkout_options(const Git_Checkout_Options&);
};

