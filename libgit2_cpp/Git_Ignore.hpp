#pragma once
#include "precompiled.hpp"
class Git_Ignore : public Parent_Provider
{
public:
	Git_Ignore()=delete;
	~Git_Ignore()=delete;
	LIBGIT2_IGNORE_INTERFACE
	static void add_rule(const string_t&);
	static void clear_internal_rules();
	static bool is_path_ignored(const std::string_view&);
};

