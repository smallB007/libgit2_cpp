#include "Git_Filter_Source.hpp"
#include "Git_Repo.hpp"
#include "Git_Object_ID.hpp"


Git_Filter_Source::Git_Filter_Source(git_filter_source* c_git_filter_source):Provider(c_git_filter_source,nullptr)
{
#pragma message("Warning nullptr as a deleter")
}

shared_ptr_t<Git_Repo> Git_Filter_Source::repo() const
{
	git_repository * c_git_repo = git_filter_source_repo(c_guts_);
	return make_shared_ver<Git_Repo>(c_git_repo);
}

file_path_t Git_Filter_Source::path() const
{
	return git_filter_source_path(c_guts_);
}

uint16_t Git_Filter_Source::filemode() const
{
	return git_filter_source_filemode(c_guts_);
}

shared_ptr_t<Git_Object_ID> Git_Filter_Source::id() const
{
	const git_oid * c_git_oid_out = git_filter_source_id(c_guts_);

	return make_shared_ver<Git_Object_ID>(const_cast<git_oid*>(c_git_oid_out));
}

git_filter_mode_t Git_Filter_Source::mode() const
{
#pragma message("Warning native libgit2 type returned")
	return git_filter_source_mode(c_guts_);
}

uint32_t Git_Filter_Source::flags() const
{
	return git_filter_source_flags(c_guts_);
}


