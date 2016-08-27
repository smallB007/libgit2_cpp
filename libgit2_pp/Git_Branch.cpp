#include "Git_Branch.hpp"
#include "Git_Repo.hpp"


Git_Branch::Git_Branch(const branch_name_t& branch_name, Git_Repo* parent) : parent_{parent}
{

	git_commit* git_commit_out = parent_->get_head_commit();
	
	git_branch_create(&c_git_reference_branch_, *parent, branch_name.c_str(), git_commit_out, false);
	git_commit_out = parent_->get_head_commit();
	
}


Git_Branch::~Git_Branch()
{
	git_reference_free(c_git_reference_branch_);
}

branch_name_t Git_Branch::name()const
{
	const char* name_out;
	git_branch_name(&name_out, c_git_reference_branch_);
	return name_out;
}

std::shared_ptr<Git_Commit> Git_Branch::create_commit()
{
	git_repository* c_git_repo = get_owner();

	auto new_commit = std::make_shared<Git_Commit>(c_git_repo);
	commits_.insert(new_commit);

	return new_commit;
}

git_repository* Git_Branch::get_owner()const
{
	git_repository* c_git_repo = git_reference_owner(c_git_reference_branch_);
	return c_git_repo;
}