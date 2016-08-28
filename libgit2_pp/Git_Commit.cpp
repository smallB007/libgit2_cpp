#include "Git_Commit.hpp"
#include "Git_Repo.hpp"
#include "Git_Commit_Author.hpp"
#include "Git_Signature.hpp"

Git_Commit::Git_Commit(Git_Repo* parent, std::vector<std::string> files_to_commit, std::string msg):my_repo_{parent}
{
	git_signature *sig;//must be freed
	if (git_signature_default(&sig, *my_repo_) < 0)
	{
		throw - 1;
		//	"Perhaps 'user.name' and 'user.email' are not vector");
	}
	git_index *index;//must be freed
	if (git_repository_index(&index, *my_repo_) < 0)
	{
		throw - 1;
		//fatal("Could not open repository index", NULL);
	}
	
	
	for (auto aString : files_to_commit)
	{
		if (git_index_add_bypath(index, aString.c_str()) < 0)
		{
			throw - 1;
		}
	}
	
	

	git_commit* git_commit_out = get_head_commit();
	
	const git_commit* c_parents[] { git_commit_out  };
	const git_oid * git_oid_tree = git_commit_tree_id(git_commit_out);

	if (git_index_write_tree(const_cast<git_oid *>(git_oid_tree), index) < 0)
	{
		git_index_free(index);
		throw - 1;
	}

	git_tree* git_tree_out;
	git_tree_lookup(&git_tree_out, *my_repo_, git_oid_tree);

	//	Normally creating a commit would involve looking up the current HEAD commit and making that be the parent of the initial commit, but here this is the first commit so there will be no parent.
	git_oid commit_id;
	if (
		git_commit_create(&commit_id, *my_repo_, "HEAD", sig, sig, "UTF-8", msg.c_str(), git_tree_out, sizeof(c_parents) / sizeof(c_parents[0]), c_parents) < 0)
	{
		int e = 0;
	}
	
	git_commit_lookup(&c_git_commit_, *my_repo_, &commit_id);
}

std::vector<git_commit*> Git_Commit::get_parents()const
{
	std::vector<git_commit*> result;

	for (unsigned int i{ 0 }, count{ git_commit_parentcount(c_git_commit_) };
																			i < count; 
																					  ++i)
	{
		git_commit* parent;
		git_commit_parent(&parent, c_git_commit_, i);
		result.push_back(parent);
	}
	return result;
}

Git_Commit::~Git_Commit()
{
	git_commit_free(c_git_commit_);
	c_git_commit_ = nullptr;
}


git_commit* Git_Commit::get_head_commit()const
{
	return my_repo_->get_head_commit();
}

void Git_Commit::amend()
{
	//git_commit_amend(git_oid *id, const git_commit *commit_to_amend, const char *update_ref, const git_signature *author, const git_signature *committer, const char *message_encoding, const char *message, const git_tree *tree);
}

std::shared_ptr<Git_Commit_Author> Git_Commit::author()const
{
	const git_signature* c_git_signature = git_commit_author(c_git_commit_);
	auto git_commit_author = std::make_shared<Git_Commit_Author>(c_git_signature);
	return git_commit_author;
}

std::string Git_Commit::body()const
{
	const char *  c_commit_body = git_commit_body(c_git_commit_);
	if (nullptr != c_commit_body)
	{
		return c_commit_body;
	}
	else
	{
		return "";
	}
}

std::shared_ptr<Git_Signature> Git_Commit::commiter()const
{
	const git_signature* c_git_signature = git_commit_committer(c_git_commit_);
	auto signature = std::make_shared<Git_Signature>(c_git_signature);
	return signature;
}












std::string Git_Commit::message()const
{
	const char * c_git_commit_msg =	git_commit_message(c_git_commit_);
	return c_git_commit_msg;
}