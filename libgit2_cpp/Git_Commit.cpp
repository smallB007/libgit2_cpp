#include "Git_Commit.hpp"
#include "Git_Repo.hpp"
#include "Git_Commit_Author.hpp"
#include "Git_Signature.hpp"
#include "Git_Commit_ID.hpp"
#include "Git_Time.hpp"
#include "Git_Tree.hpp"
#include "Git_Root.hpp"
 Git_Commit::Git_Commit(git_commit* c_git_commit, const NMS::vector<NMS::string>& files_to_commit, const NMS::string& msg):Provider(c_git_commit, git_commit_free)
{
	git_repository* rep = c_parent_guts();
	git_signature *sig;//must be freed
	if (git_signature_default(&sig, rep) < 0)
	{
		throw - 1;
		//	"Perhaps 'user.name' and 'user.email' are not vector");
	}
	git_index *index;//must be freed
	if (git_repository_index(&index, rep) < 0)
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
	
	

	git_commit* git_commit_out = get_parent()->get_head_commit()->c_guts();
	
	const git_commit* c_parents[] { git_commit_out };
	const git_oid * git_oid_tree = git_commit_tree_id(git_commit_out);

	if (git_index_write_tree(const_cast<git_oid *>(git_oid_tree), index) < 0)
	{
		git_index_free(index);
		throw - 1;
	}

	git_tree* git_tree_out;
#pragma message("ToDo put git_tree_out and sig into scoped deleter");
	check_for_error(git_tree_lookup(&git_tree_out, rep, git_oid_tree));

	//	Normally creating a commit would involve looking up the current HEAD commit and making that be the parent of the initial commit, but here this is the first commit so there will be no parent.
	git_oid commit_id;
	check_for_error(git_commit_create(&commit_id, rep, "HEAD", sig, sig, "UTF-8", msg.c_str(), git_tree_out, sizeof(c_parents) / sizeof(c_parents[0]), c_parents));
	git_signature_free(sig);
	/*assign the newly created commit to c_git_guts_*/
	c_git_guts_ = get_parent()->get_head_commit()->c_guts();
}


Git_Commit::Git_Commit(git_commit* c_git_commit) : Provider(c_git_commit, git_commit_free)
{/*Only for passing around*/}

NMS::vector<git_commit*> Git_Commit::get_parents()const
{
	NMS::vector<git_commit*> result;

	for (unsigned int i{ 0 }, count{ git_commit_parentcount(c_git_guts_) };
																			i < count; 
																					 ++i)
	{
		git_commit* parent;
		check_for_error(git_commit_parent(&parent, c_git_guts_, i));
		result.push_back(parent);
	}
	return result;
}

shared_ptr_t<Git_Commit_Author> Git_Commit::author()const
{
	const git_signature* c_git_signature = git_commit_author(c_git_guts_);
	auto git_commit_author = make_shared_ver<Git_Commit_Author>(c_git_signature);
	return git_commit_author;
}

NMS::string Git_Commit::body()const
{
	const char * c_commit_body = git_commit_body(c_git_guts_);
	if (nullptr != c_commit_body)
	{
		return c_commit_body;
	}
	else
	{
		return "";
	}
}

shared_ptr_t<Git_Signature> Git_Commit::commiter()const
{
	const git_signature* c_git_signature = git_commit_committer(c_git_guts_);
	auto signature = make_shared_ver<Git_Signature>(c_git_signature);

	return signature;
}

#ifdef _FULL_IMPLEMENTATION_
shared_ptr_t<Git_Commit> Git_Commit::duplicate()const
{
	git_commit* c_git_commit_out;
//	git_commit_dup(&c_git_commit_out, c_git_guts_);
	throw - 1;
	return nullptr;
}
#endif

shared_ptr_t<Git_Signature> Git_Commit::signature()const
{
	git_buf* signature_block{};//the signature block
	git_buf* signed_data{}; //this is the commit contents minus the signature block
	
		
	const git_oid * 	commit_id = git_commit_id(c_git_guts_);
	const char * 	field = nullptr;// the name of the header field containing the signature block; pass `NULL` to extract the default 'gpgsig'
	check_for_error(git_commit_extract_signature(signature_block, signed_data, c_parent_guts(), const_cast<git_oid *>(commit_id), field));

	return make_shared_ver<Git_Signature>(signature_block, signed_data);
}

shared_ptr_t<Git_Commit_ID> Git_Commit::id()const
{
	const git_oid * commit_id = git_commit_id(c_git_guts_);
	return make_shared_ver<Git_Commit_ID>(const_cast<git_oid*>(commit_id));
}

NMS::string Git_Commit::message()const
{
	const char * c_git_commit_msg =	git_commit_message(c_git_guts_);
	if (FAILED(c_git_commit_msg))
	{
		throw - 1;
	}
	else
	{
		return c_git_commit_msg;
	}
}

shared_ptr_t<Git_Commit> Git_Commit::nth_gen_ancestor(const unsigned nth_generation)const
{
	git_commit* ancestor_out;
	auto res = git_commit_nth_gen_ancestor(&ancestor_out, c_git_guts_, nth_generation);
	if (FAILED(res))
	{
		throw - 1;
	}
	else
	{
		return make_shared_ver<Git_Commit>(ancestor_out);
	}
}

shared_ptr_t<Git_Repo> Git_Commit::owner()const
{
	
	git_repository* c_git_repo = git_commit_owner(c_git_guts_);
	//Will this^^^ leak???
	auto git_root = create_git();
	auto repo = git_root->find_c_git_repository(c_git_repo);
	return repo;
		
	/*In Git_Root find that repo and return it*/
	//if (FAILED(c_git_repo))
	//{
	//	throw - 1;
	//}
	//else
	//{
	//
	//	return make_shared_ver<Git_Repo>(c_git_repo);
	//}
}

shared_ptr_t<Git_Commit> Git_Commit::parent(const unsigned parent_pos)const
{
	/*After implementing parent count check that parent_pos is <= parent_count*/
	if (parent_pos > parent_count())
	{
		throw - 1;
	}
	git_commit* commit_out;
	auto res = git_commit_parent(&commit_out, c_git_guts_, parent_pos);
	if (FAILED(res))
	{
		throw - 1;
	}
	else
	{
		return make_shared_ver<Git_Commit>(commit_out);
	}
}

shared_ptr_t<Git_Object_ID> Git_Commit::parent_id(const unsigned parent_pos)const
{
	const git_oid * c_git_oid = git_commit_parent_id(c_git_guts_, parent_pos);
	if (FAILED(c_git_oid))
	{
		throw - 1;
	}
	else
	{
		return make_shared_ver<Git_Object_ID>(const_cast<git_oid *>(c_git_oid));
	}
}

unsigned Git_Commit::parent_count()const
{
	return git_commit_parentcount(c_git_guts_);
}

NMS::string Git_Commit::raw_header()const
{
	const char * raw_header = git_commit_raw_header(c_git_guts_);
	if (FAILED(raw_header))
	{
		throw - 1;
	}
	else
	{
		return raw_header;
	}
}

NMS::string Git_Commit::summary()const
{
	const char * c_commit_summary = git_commit_summary(c_git_guts_);
	if (FAILED(c_commit_summary))
	{
		throw - 1;
	}
	else
	{
		return c_commit_summary;
	}
}

shared_ptr_t<Git_Time> Git_Commit::time()const
{
	git_time_t c_git_time_t = git_commit_time(c_git_guts_);
	git_time c_git_time{ c_git_time_t };
	c_git_time.offset = git_commit_time_offset(c_git_guts_);
	return make_shared_ver<Git_Time>(c_git_time);
}

int Git_Commit::time_offset()const
{
	return git_commit_time_offset(c_git_guts_);
}

shared_ptr_t<Git_Tree> Git_Commit::tree()const
{
	git_tree* c_tree_out;
	auto res = git_commit_tree(&c_tree_out,c_git_guts_);
	if (FAILED(res))
	{
		throw - 1;
	}
	else
	{
		return make_shared_ver<Git_Tree>(c_tree_out);
	}
}

shared_ptr_t<Git_Object_ID> Git_Commit::tree_id()const
{
	const git_oid * c_git_oid = git_commit_tree_id(c_git_guts_);
	if (FAILED(c_git_oid))
	{
		throw - 1;
	}
	else
	{
		return make_shared_ver<Git_Object_ID>(const_cast<git_oid*>(c_git_oid));
	}
}
