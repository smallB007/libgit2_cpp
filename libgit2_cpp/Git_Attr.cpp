#include "Git_Attr.hpp"

void Git_Attr::add_macro(const std::string_view & name, const std::string_view &values)const
{
	check_for_error(git_attr_add_macro(c_parent_guts(), name.data(), values.data()));
}

void Git_Attr::cache_flush() const
{
	git_attr_cache_flush(c_parent_guts());
}

string_t Git_Attr::get(uint32_t flags, const string_t & path, const string_t & name) const
{
	const char* c_value_out;
	check_for_error(git_attr_get(&c_value_out, c_parent_guts(), flags, path.c_str(), name.c_str()));

	return c_value_out;
}

git_attr_t Git_Attr::value(const string_t & attr) const
{
	return git_attr_value(attr.c_str());
#pragma message("Warning native libgit2 type returned")
}
