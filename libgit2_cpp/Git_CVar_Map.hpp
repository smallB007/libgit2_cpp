#pragma once
#include "stdafx.h"

class Git_CVar_Map 
{
	friend class Git_Config;
	vector_t<git_cvar_map> c_git_cvar_map_vec;
public:
	git_cvar_t get_type(const size_t inx)const;
	string_t get_match(const size_t inx)const;
	int get_value(const size_t inx)const;
	operator git_cvar_map*();
	std::size_t size()const;

};
