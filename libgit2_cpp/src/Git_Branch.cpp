#include "Git_Branch.hpp"
#include "Git_Repo.hpp"
#include "Git_Commit.hpp"

Git_Branch::Git_Branch(git_reference* c_git_branch_ref) : Provider(c_git_branch_ref,git_reference_free)
{
}

Git_Branch::Git_Branch(const branch_name_t& branch_name, bool force):Provider(c_guts_, git_reference_free)
{
	const git_commit* git_commit_in = get_parent()->get_head_commit()->c_guts();
	
	check_for_error(git_branch_create(&c_guts_, c_parent_guts(), branch_name.c_str(), git_commit_in, force));
}





branch_name_t Git_Branch::name()const
{
	const char* name_out{};
	check_for_error(git_branch_name(&name_out, c_guts_));
	
	return name_out;
	
}

shared_ptr_t<Git_Commit> Git_Branch::create_commit()
{
	const vector_t<string_t> files_to_commit;
	const string_t msg;
	
#pragma message("ToDo THIS ^^^ should be a method of Repo: create on active branch a commit")
	

	auto new_commit = Factory_Git_Object<Git_Commit>::create(files_to_commit, msg);
	commits_.insert(new_commit);
	
	return new_commit;
}

git_repository* Git_Branch::get_owner_()const
{
	git_repository* c_git_repo = git_reference_owner(c_guts_);
	check_for_nullptr(c_git_repo);

	return c_git_repo;
}

bool Git_Branch::is_head()const
{
	auto res = git_branch_is_head(c_guts_);
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
#pragma message("ToDo What to do with it^^^?")
	check_for_error(git_branch_move(&git_branch_ref_out, c_guts_, new_branch_name.c_str(), force));
}

void Git_Branch::rename(const branch_name_t& new_branch_name)
{
	move_(new_branch_name,true);
#pragma message("ToDo with the force argument - next iteration")
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