#include "Git_Commit.hpp"



Git_Commit::Git_Commit(git_repository* c_git_repository)
{
	git_signature *sig;
	if (git_signature_default(&sig, c_git_repository) < 0)
	{
		throw - 1;
		//	"Perhaps 'user.name' and 'user.email' are not set");
	}
	git_oid* git_oid_out = new git_oid;
	git_reference_name_to_id(git_oid_out, c_git_repository, "HEAD");

	git_commit* git_commit_out{ nullptr };
	git_commit_lookup(&git_commit_out, c_git_repository, git_oid_out);

	const git_oid * git_oid_tree = git_commit_tree_id(git_commit_out);
	git_tree* git_tree_out;
	git_tree_lookup(&git_tree_out, c_git_repository, git_oid_tree);
}


Git_Commit::~Git_Commit()
{
	git_commit_free(c_git_commit);
}
