#include "Git_Branch.hpp"
#include "Git_Repo.hpp"


Git_Branch::Git_Branch(const branch_name_t& branch_name, Git_Repo* parent) : m_parent_repo_{parent}
{
	git_commit* git_commit_out = *(get_head_commit().get());
	
	auto res = git_branch_create(&c_git_reference_branch_, *parent, branch_name.c_str(), git_commit_out, false);
	if (FAILED(res))
	{
		throw - 1;
	}
}


std::shared_ptr<Git_Commit> Git_Branch::get_head_commit()const
{
	return m_parent_repo_->get_head_commit();
}

Git_Branch::~Git_Branch()
{
	git_reference_free(c_git_reference_branch_);
	c_git_reference_branch_ = nullptr;
}

branch_name_t Git_Branch::name()const
{
	const char* name_out;
	auto res = git_branch_name(&name_out, c_git_reference_branch_);
	if (FAILED(res))
	{
		throw - 1;
	}
	else
	{
		return name_out;
	}
}

std::shared_ptr<Git_Commit> Git_Branch::create_commit()
{
	/*git_repository* c_git_repo = get_owner();*/
	std::vector<std::string> files_to_commit{"a.cpp","b.cpp"};
	std::string msg = "How is it going Artie? ;)";
	auto new_commit = std::make_shared<Git_Commit>(m_parent_repo_, files_to_commit,msg);
	commits_.insert(new_commit);

	return new_commit;
}

git_repository* Git_Branch::get_owner()const
{
	git_repository* c_git_repo = git_reference_owner(c_git_reference_branch_);
	if (FAILED(c_git_repo))
	{
		throw - 1;
	}
	else
	{
		return c_git_repo;
	}
}