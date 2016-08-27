#pragma once
#include <git2.h>

void create_initial_commit(git_repository *repo)
{
	//https://libgit2.github.com/libgit2/ex/HEAD/init.html#git_repository_init-7
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree;

	//	First use the config to initialize a commit signature for the user.


	if (git_signature_default(&sig, repo) < 0)
	{
		throw -1;
		//	"Perhaps 'user.name' and 'user.email' are not set");
	}

	/* Now let's create an empty tree for this commit */

	if (git_repository_index(&index, repo) < 0)
	{
		throw - 1;
		//fatal("Could not open repository index", NULL);
	}
	//	Outside of this example, you could call gitindexadd_bypath() here to put actual files into the index.For our purposes, we'll leave it empty for now.

	if (git_index_write_tree(&tree_id, index) < 0)
	{
		//fatal("Unable to write initial tree from index", NULL);
		git_index_free(index);
		throw -1;
	}

	if (git_tree_lookup(&tree, repo, &tree_id) < 0)
	{
		//fatal("Could not look up initial tree", NULL);
		throw -1;
	}

	//	Ready to create the initial commit.
	//
	//	Normally creating a commit would involve looking up the current HEAD commit and making that be the parent of the initial commit, but here this is the first commit so there will be no parent.
	if (git_commit_create_v(
		&commit_id, repo, "HEAD", sig, sig,
		NULL, "Initial commit", tree, 0) < 0)
	{
		//fatal("Could not create the initial commit", NULL);
		//throw -1;
	}

	//	Clean up so we don't leak memory.
	git_tree_free(tree);
	git_signature_free(sig);
}