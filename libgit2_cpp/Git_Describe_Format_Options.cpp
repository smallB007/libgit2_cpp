#include "Git_Describe_Format_Options.hpp"



Git_Describe_Format_Options::Git_Describe_Format_Options()
{
	c_git_describe_format_options_ = GIT_DESCRIBE_FORMAT_OPTIONS_INIT;
}

unsigned int 	Git_Describe_Format_Options::version()const
{
	return c_git_describe_format_options_.version;
}
unsigned int 	Git_Describe_Format_Options::abbreviated_size()const
{
	return c_git_describe_format_options_.abbreviated_size;
}
int 	Git_Describe_Format_Options::always_use_long_format()const
{
	return c_git_describe_format_options_.always_use_long_format;
}
string_t 	Git_Describe_Format_Options::dirty_suffix()const
{
	return c_git_describe_format_options_.dirty_suffix;
}
