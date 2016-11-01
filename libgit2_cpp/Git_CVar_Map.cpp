#include "Git_CVar_Map.hpp"


git_cvar_t Git_CVar_Map::get_type(const size_t inx)const
{
	return c_git_cvar_map_vec[inx].cvar_type;
}
string_t Git_CVar_Map::get_match(const size_t inx)const
{
	return c_git_cvar_map_vec[inx].str_match;
}
int Git_CVar_Map::get_value(const size_t inx)const
{
	return c_git_cvar_map_vec[inx].map_value;
}

Git_CVar_Map::operator git_cvar_map*() 
{
	git_cvar_map* c_git_cvar_map = c_git_cvar_map_vec.data();
	return c_git_cvar_map;

}

std::size_t Git_CVar_Map::size() const
{
	return c_git_cvar_map_vec.size();
}
