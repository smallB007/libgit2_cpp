#pragma once
#include "precompiled.hpp"
class Git_Attr : Parent_Provider
{
public:
	void add_macro(const std::string_view&, const std::string_view&)const;
	void cache_flush()const;
	string_t get(uint32_t, const string_t&,const string_t&)const;
	git_attr_t value(const string_t&)const;
#ifdef _FULL_IMPLEMENTATION_
	git_attr_foreach
	git_attr_get_many
#endif
};

