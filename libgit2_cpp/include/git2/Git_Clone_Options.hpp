#pragma once
#include "precompiled.hpp"
class Git_Clone_Options
{
	git_clone_options c_git_clone_options_{ GIT_CLONE_OPTIONS_VERSION };
public:
#pragma message("ToDo  [Git_Clone_Options] - implement setters and getters")
	Git_Clone_Options(unsigned ver = GIT_CLONE_OPTIONS_VERSION);
	const git_clone_options* c_guts() const { return &c_git_clone_options_; }
	void set_default();
};

