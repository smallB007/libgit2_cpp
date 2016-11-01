#include "Git_Branch.hpp"
#include "Git_Repo.hpp"
#include "Git_Commit.hpp"
/*used when creating initial commit in Git_Repo*/
Git_Branch::Git_Branch(git_reference* git_branch_ref) : Provider(git_reference_free)
{/*add commit and name*/
	c_git_guts_ = git_branch_ref;
	auto head_commit = get_parent()->get_head_commit();
	commits_.insert(head_commit);
}

Git_Branch::Git_Branch(const branch_name_t& branch_name) : Provider(git_reference_free)
{
	git_commit* git_commit_out = get_parent()->get_head_commit()->c_guts();
	
	auto res = git_branch_create(&c_git_guts_, c_parent_guts(), branch_name.c_str(), git_commit_out, false);
	if (FAILED(res))
	{
		throw - 1;
	}
}

branch_name_t Git_Branch::name()const
{
	const char* name_out;
	auto res = git_branch_name(&name_out, c_git_guts_);
	if (FAILED(res))
	{
		throw - 1;
	}
	else
	{
		return name_out;
	}
}

shared_ptr_t<Git_Commit> Git_Branch::create_commit()
{/*THIS ^^^ should be a method of Repo: create on active branch a commit*/
	/*git_repository* c_git_repo = get_owner();*/
	NMS::vector<NMS::string> files_to_commit{"a.cpp","b.cpp"};
	NMS::string msg = "How is it going Artie? ;)";
	auto new_commit = make_shared_ver<Git_Commit>(files_to_commit, msg);
	commits_.insert(new_commit);

	return new_commit;
}

git_repository* Git_Branch::get_owner_()const
{
	git_repository* c_git_repo = git_reference_owner(c_git_guts_);
	if (FAILED(c_git_repo))
	{
		throw - 1;
	}
	else
	{
		return c_git_repo;
	}
}

bool Git_Branch::is_head()const
{
	auto res = git_branch_is_head(c_git_guts_);
	return res == 1 ? true :
			res == 0 ? false :
			throw - 1;
}


decltype(Git_Branch::commits_)::iterator Git_Branch::begin()const
{
	return std::begin(commits_);
}

decltype(Git_Branch::commits_)::iterator Git_Branch::end()const
{
	return std::end(commits_);
}
void Git_Branch::move_(const branch_name_t& new_branch_name, bool force)
{
	git_reference* git_branch_ref_out;
	auto res = git_branch_move(&git_branch_ref_out, c_git_guts_, new_branch_name.c_str(), force);
	if (FAILED(res))
	{
		throw - 1;
	}
	//if (force)
	//{
		git_reference_free(c_git_guts_);
		c_git_guts_ = git_branch_ref_out;
	//}
}

void Git_Branch::rename(const branch_name_t& new_branch_name)
{/*with the force argument - next iteration*/
	move_(new_branch_name,true);
}

void Git_Branch::move(const branch_name_t& new_branch_name)
{
	move_(new_branch_name, false);
}

//git_branch_t Git_Branch::type()const
//{
//
//}

struct Beta {
	int ab;
	int const& getAB() const& { return ab; }
	int && getAB() && { return std::move(ab); }
};