#include "Git_Ignore.hpp"

void Git_Ignore::add_rule(const string_t & rules) 
{
	check_for_error(git_ignore_add_rule(c_parent_guts(), rules.c_str()));
}

void Git_Ignore::clear_internal_rules() 
{
	check_for_error(git_ignore_clear_internal_rules(c_parent_guts()));
}

bool Git_Ignore::is_path_ignored(const std::string_view & path)
{
	int is_ignored;
	check_for_error(git_ignore_path_is_ignored(&is_ignored, c_parent_guts(), path.data()));

	return is_ignored;
}

