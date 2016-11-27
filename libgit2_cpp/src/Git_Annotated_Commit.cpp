#include "Git_Annotated_Commit.hpp"
#include "Git_Object_ID.hpp"
#include "Git_Reference.hpp"

Git_Annotated_Commit::Git_Annotated_Commit(git_annotated_commit * c_git_annotated_commit ):Provider(c_git_annotated_commit,git_annotated_commit_free)
{
}

shared_ptr_t<Git_Annotated_Commit> Git_Annotated_Commit::commit_from_fetchhead(const branch_name_t& branchName, const string_t& remoteUrl,const Git_Object_ID& objectID) const
{
	git_annotated_commit *c_git_annotated_commit_out;
	check_for_error(git_annotated_commit_from_fetchhead(&c_git_annotated_commit_out, c_parent_guts(), branchName.c_str(), remoteUrl.c_str(), objectID.c_guts()));

	return make_shared_ver<Git_Annotated_Commit>(c_git_annotated_commit_out);
}

shared_ptr_t<Git_Annotated_Commit> Git_Annotated_Commit::commit_from_ref(const Git_Reference & ref) const
{
	git_annotated_commit *c_git_annotated_commit_out;
	check_for_error(git_annotated_commit_from_ref(&c_git_annotated_commit_out,c_parent_guts(), ref.c_guts()));

	return make_shared_ver<Git_Annotated_Commit>(c_git_annotated_commit_out);
}

shared_ptr_t<Git_Annotated_Commit> Git_Annotated_Commit::commit_from_revspec(const string_t &revspec) const
{
	git_annotated_commit *c_git_annotated_commit_out;
	check_for_error(git_annotated_commit_from_revspec(&c_git_annotated_commit_out, c_parent_guts(), revspec.c_str()));

	return make_shared_ver<Git_Annotated_Commit>(c_git_annotated_commit_out);
}

shared_ptr_t<Git_Object_ID> Git_Annotated_Commit::commit_id() const
{
	const git_oid * c_git_oid = git_annotated_commit_id(c_guts_);
	check_for_nullptr(c_git_oid);
#pragma message("ToDo find every place where Git_Object_ID is const_cast and rem that cast")
	return make_shared_ver<Git_Object_ID>(c_git_oid);
}

shared_ptr_t<Git_Annotated_Commit> Git_Annotated_Commit::commit_lookup(const Git_Object_ID &id) const
{
	git_annotated_commit *c_git_annotated_commit_out;
	check_for_error(git_annotated_commit_lookup(&c_git_annotated_commit_out, c_parent_guts(), id.c_guts()));

	return make_shared_ver<Git_Annotated_Commit>(c_git_annotated_commit_out);
}

