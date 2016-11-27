#pragma once
#include "precompiled.hpp"
class Git_Filter_Source : public Provider<git_filter_source>
{
public:
	Git_Filter_Source(git_filter_source*);
	~Git_Filter_Source()=default;
	
	LIBGIT2_FILTER_SOURCE_INTERFACE
	shared_ptr_t<Git_Repo> repo()const;
	

	/**
	* Get the path that the source data is coming from.
	*/
	path_name_t path()const;

	/**
	* Get the file mode of the source file
	* If the mode is unknown, this will return 0
	*/
	uint16_t filemode()const;

	/**
	* Get the OID of the source
	* If the OID is unknown (often the case with GIT_FILTER_CLEAN) then
	* this will return NULL.
	*/
	shared_ptr_t<Git_Object_ID> id()const;

	/**
	* Get the git_filter_mode_t to be used
	*/
	git_filter_mode_t mode()const;

	/**
	* Get the combination git_filter_flag_t options to be applied
	*/
	uint32_t flags()const;

};

