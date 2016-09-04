#include "Git_Repo.hpp"
#include "Copied_From_libgit2.hpp"
#include "Git_Commit_ID.hpp"
/*Proper CADRe - [C]onstructor [A]cquires, [D]estructor [Re]leses*/
Git_Repo::Git_Repo(const repo_path_t& path_to_repo, const bool is_bare)
{
	auto err = git_repository_init(&c_git_repository_, path_to_repo.c_str(), static_cast<unsigned int>(is_bare));

	if (FAILED(c_git_repository_) || FAILED(err))
	{
		throw - 1;
	}
	else
	{
		create_initial_commit(c_git_repository_);
	}
}

Git_Repo::Git_Repo(git_repository* c_git_repository):c_git_repository_{c_git_repository}
{
	/*empty*/
}

Git_Repo::~Git_Repo()
{
	git_repository_free(c_git_repository_);
	c_git_repository_ = nullptr;
}
 
const NMS::shared_ptr<Git_Commit> Git_Repo::get_head_commit()const
{
	if (nullptr != head_commit_[0].first)
	{
		delete head_commit_[0].first;
		git_commit_free(head_commit_[0].second);

		head_commit_[0].first = nullptr;
		head_commit_[0].second = nullptr;
	}

	git_oid* git_oid_out = new git_oid;
	git_reference_name_to_id(git_oid_out, c_git_repository_, "HEAD");

	git_commit* git_commit_out{ nullptr };
	git_commit_lookup(&git_commit_out, c_git_repository_, git_oid_out);
	auto aPair = NMS::make_pair(git_oid_out,git_commit_out);
	head_commit_[0] = aPair;

	return NMS::make_shared<Git_Commit>(this,git_commit_out);
}

NMS::pair<bool,NMS::shared_ptr<Git_Branch>> Git_Repo::find_branch(const branch_name_t& branch_name)const
{
	for (auto aSharedPtr : branches_)
	{
		if ((aSharedPtr->name() == branch_name))
		{
			return NMS::make_pair(true,aSharedPtr);
		}
	}

	return NMS::make_pair(false,nullptr);
}

NMS::shared_ptr<Git_Branch> Git_Repo::create_branch(const branch_name_t& branch_name)
{
	auto result = find_branch(branch_name);
	/*Check if branch with that name already find_branch and if not create it*/
	if (!result.first)
	{
		NMS::shared_ptr<Git_Branch> new_branch = NMS::make_shared<Git_Branch>(branch_name,this);
		branches_.insert(new_branch);
		return new_branch;
	}
	else
	{
		return result.second;
	}
}

bool Git_Repo::is_my_path(const repo_path_t& path_to_some_repo)const
{
	const char* const c_path = git_repository_path(c_git_repository_);
	return (0 == strcmp(path_to_some_repo.c_str(),c_path));
}

void Git_Repo::rename(const NMS::string& repo_name)
{
	const_cast<NMS::string&>(repo_name_) = repo_name;
}


NMS::shared_ptr<Git_Branch> Git_Repo::get_branch(const branch_name_t& branch_name)const
{
	return nullptr;
}

const NMS::shared_ptr<Git_Commit> Git_Repo::commit_lookup(const Git_Commit_ID& commit_id)const
{
	git_commit* commit_out{ nullptr };
	auto res = git_commit_lookup(&commit_out, c_git_repository_, commit_id.id());
	if(FAILED(res))
	{
		throw - 1;
	}
	else
	{
		return NMS::make_shared<Git_Commit>(this,commit_out);
	}
}