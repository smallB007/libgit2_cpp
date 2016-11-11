#include "Git_Diff_Options.hpp"

Git_Diff_Options::Git_Diff_Options() 
{
	check_for_error(git_diff_init_options(&c_git_guts_, GIT_DIFF_OPTIONS_VERSION));
}

unsigned int 	Git_Diff_Options::version()const
{
	return c_git_guts_.version;
}
uint32_t 	Git_Diff_Options::flags()const
{
	return c_git_guts_.flags;
}
git_submodule_ignore_t 	Git_Diff_Options::ignore_submodules()const
{
	return c_git_guts_.ignore_submodules;
}
git_strarray 	Git_Diff_Options::pathspec()const
{
	return c_git_guts_.pathspec;
}
void * 	Git_Diff_Options::payload()const
{
	return c_git_guts_.payload;
}
uint32_t 	Git_Diff_Options::context_lines()const
{
	return c_git_guts_.context_lines;
}
uint32_t 	Git_Diff_Options::interhunk_lines()const
{
	return c_git_guts_.interhunk_lines;
}
uint16_t 	Git_Diff_Options::id_abbrev()const
{
	return c_git_guts_.id_abbrev;
}
git_off_t 	Git_Diff_Options::max_size()const
{
	return c_git_guts_.max_size;
}
string_t 	Git_Diff_Options::old_prefix()const
{
	return c_git_guts_.old_prefix;
}
string_t 	Git_Diff_Options::new_prefix()const
{
	return c_git_guts_.new_prefix;
}