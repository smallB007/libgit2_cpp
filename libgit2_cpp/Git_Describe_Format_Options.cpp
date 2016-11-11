#include "Git_Describe_Format_Options.hpp"

Git_Describe_Format_Options::Git_Describe_Format_Options(git_describe_format_options c_git_describe_format_options)
{
	c_git_guts_ = c_git_describe_format_options;
}

unsigned int 	Git_Describe_Format_Options::version()const
{
	return c_git_guts_.version;
}
unsigned int 	Git_Describe_Format_Options::abbreviated_size()const
{
	return c_git_guts_.abbreviated_size;
}
int 	Git_Describe_Format_Options::always_use_long_format()const
{
	return c_git_guts_.always_use_long_format;
}
string_t 	Git_Describe_Format_Options::dirty_suffix()const
{
	return c_git_guts_.dirty_suffix;
}
