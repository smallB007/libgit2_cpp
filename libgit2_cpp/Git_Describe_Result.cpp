#include "Git_Describe_Result.hpp"
#include "Git_Commit.hpp"
#include "Git_Describe_Options.hpp"
#include "Git_Describe_Format_Options.hpp"
#include "Git_Buf.hpp"
Git_Describe_Result::Git_Describe_Result(git_describe_result* c_git_describe_result):Provider(c_git_describe_result,git_describe_result_free)
{
}

shared_ptr_t<Git_Describe_Result> Git_Describe_Result::describe_commit(const shared_ptr_t<const Git_Commit>& commit, Git_Describe_Options describe_options)const
{
	git_describe_result* c_git_describe_result_out;
	check_for_error(git_describe_commit(&c_git_describe_result_out, reinterpret_cast<git_object*>(commit->c_guts()), describe_options.c_guts()));
#pragma message("Idea: perhaps there is a possibility to have c_guts(Git_Object) instead of Git_Object->c_guts()")
	return make_shared_ver<Git_Describe_Result>(c_git_describe_result_out);
}

shared_ptr_t<Git_Buf> Git_Describe_Result::describe_format(Git_Describe_Format_Options describe_format_options)const
{
	git_buf* c_git_buf_out;
	check_for_error(git_describe_format(c_git_buf_out, c_guts_, describe_format_options.c_guts()));
	
	return make_shared_ver<Git_Buf>(c_git_buf_out);
}

shared_ptr_t<Git_Describe_Result> Git_Describe_Result::describe_workdir(Git_Describe_Options describe_options) 
{
	git_describe_result* c_git_describe_result_out;
	check_for_error(git_describe_workdir(&c_git_describe_result_out, c_parent_guts(), describe_options.c_guts()));
	
	return make_shared_ver<Git_Describe_Result>(c_git_describe_result_out);
}

