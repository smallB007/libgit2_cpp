#pragma once
#include "precompiled.hpp"
class Git_Diff_Options : public Guts_Provider<git_diff_options,Memory_Management<NO>>
{
public:
	Git_Diff_Options();
	~Git_Diff_Options() = default;
	LIBGIT2_DIFF_OPTIONS_INTERFACE
		unsigned int 	version()const;
	uint32_t 	flags()const;
	git_submodule_ignore_t 	ignore_submodules()const;
	git_strarray 	pathspec()const;
	git_diff_notify_cb 	notify_cb;
	git_diff_progress_cb 	progress_cb;
#pragma message("ToDo make those callbacks work")
	void * 	payload()const;
	uint32_t 	context_lines()const;
	uint32_t 	interhunk_lines()const;
	uint16_t 	id_abbrev()const;
	git_off_t 	max_size()const;
	string_t 	old_prefix()const;
	string_t 	new_prefix()const;
#pragma message("ToDo add getters and setters to it")
	
};

