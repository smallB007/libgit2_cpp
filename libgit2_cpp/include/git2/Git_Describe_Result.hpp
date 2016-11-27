#pragma once
#include "precompiled.hpp"

class Git_Describe_Result : public Provider<git_describe_result>
{
public:
	Git_Describe_Result(git_describe_result*);
	LIBGIT2_DESCRIBE_INTERFACE
	shared_ptr_t<Git_Describe_Result> describe_commit(const shared_ptr_t<const Git_Commit>&, Git_Describe_Options)const;
	shared_ptr_t<Git_Buf> describe_format(Git_Describe_Format_Options )const;
	shared_ptr_t<Git_Describe_Result> describe_workdir(Git_Describe_Options );
};

