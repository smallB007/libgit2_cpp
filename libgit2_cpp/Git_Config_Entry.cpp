#include "Git_Config_Entry.hpp"

#include "Git_Config_Level.hpp"

//Git_Config_Entry::Git_Config_Entry():Provider(git_config_entry_free)
//{
//}

Git_Config_Entry::Git_Config_Entry(git_config_entry * c_git_config_entry):Provider(c_git_config_entry, git_config_entry_free)
{
	c_guts_ = c_git_config_entry;
}


string_t Git_Config_Entry::name() const
{
	return c_guts_->name;
}

string_t Git_Config_Entry::value() const
{
	return c_guts_->value;
}

Git_Config_Level Git_Config_Entry::level() const
{
	return c_guts_->level;
}
