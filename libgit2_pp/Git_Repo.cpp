#include "Git_Repo.hpp"

#include "Copied_From_libgit2.hpp"
#include "Git_Commit_ID.hpp"
#include "Git_Config.hpp"

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
		git_reference* git_branch_ref_out;
		auto res = git_repository_head(&git_branch_ref_out, c_git_repository_);
		if (FAILED(res))
		{
			throw -1;
		}
		NMS::shared_ptr<Git_Branch> master_branch{ new Git_Branch(git_branch_ref_out, this) };// = std::make_shared<Git_Branch>(git_branch_ref_out, this);
		branches_.insert(master_branch);
	}
}

//Git_Repo::Git_Repo(git_repository* c_git_repository):c_git_repository_{c_git_repository}
//{
//	/*empty*/
//}

Git_Repo::~Git_Repo()
{
	git_repository_free(c_git_repository_);
	c_git_repository_ = nullptr;
}
 
const NMS::shared_ptr<Git_Commit> Git_Repo::get_head_commit()const
{
	git_oid* git_oid_out = new git_oid;
	git_reference_name_to_id(git_oid_out, c_git_repository_, "HEAD");

	git_commit* git_commit_out{ nullptr };
	git_commit_lookup(&git_commit_out, c_git_repository_, git_oid_out);

	delete git_oid_out;

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

void Git_Repo::delete_branch(const branch_name_t& branch_name)
{
	auto aPair = find_branch(branch_name);
	if (aPair.first)
	{
		auto res = git_branch_delete(*(aPair.second.get()));
		if (FAILED(res))
		{
			throw - 1;
		}
		else
		{
			branches_.erase(aPair.second);
		}
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


//NMS::shared_ptr<Git_Branch> Git_Repo::get_branch(const branch_name_t& branch_name)const
//{
//	return nullptr;
//}

const NMS::shared_ptr<Git_Commit> Git_Repo::commit_lookup(const Git_Commit_ID& commit_id)const
{/*Most likely here it is better to simply look through commits in branches but who knows?*/
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

decltype(Git_Repo::branches_)::iterator Git_Repo::begin()const
{
	return std::begin(branches_);
}

decltype(Git_Repo::branches_)::iterator Git_Repo::end()const
{
	return std::end(branches_);
}

NMS::shared_ptr<Git_Branch> Git_Repo::branch_lookup(const branch_name_t& branch_name, git_branch_t branch_type)const
{
	/*The above signature is 1:1 with libgit2 but for the momment type of branch will be ommited*/
	for (auto aSharedPtr : branches_)
	{
		if (aSharedPtr->name() == branch_name /*&& aSharedPtr->type() == branch_type*/)
		{
			return aSharedPtr;
		}
	}
	return nullptr;
	//git_reference* git_reference_branch_out;
	//auto res = git_branch_lookup(&git_reference_branch_out, c_git_repository_, branch_name.c_str(),branch_type);
	//if (FAILED(res))
	//{
	//	throw - 1;
	//}
	//return NMS::make_shared<Git_Branch>(git_reference_branch_out);
}

void Git_Repo::cleanup()
{
	git_repository__cleanup(c_git_repository_);
}

NMS::shared_ptr<Git_Config> Git_Repo::config()const
{
	git_config* config_out;
	auto res = git_repository_config(&config_out,c_git_repository_);
	if (FAILED(res))
	{
		throw - 1;
	}
	return NMS::make_shared<Git_Config>(config_out);
}

NMS::shared_ptr<Git_Config> Git_Repo::config_snapshot()const
{
	git_config* config_snapshot_out;
	auto res = git_repository_config_snapshot(&config_snapshot_out, c_git_repository_);
	if (FAILED(res))
	{
		throw - 1;
	}
	return NMS::make_shared<Git_Config>(config_snapshot_out);
}

repo_path_t Git_Repo::discover(const repo_path_t start_path)const
{
	git_buf buf = GIT_BUF_INIT_CONST(NULL, 0);
	auto res = git_repository_discover(&buf, start_path.c_str(), 0, NULL);
	if (FAILED(res))
	{
		throw - 1;
	}
	repo_path_t repo_path = buf.ptr;
	return repo_path;
}

namespace_name_t Git_Repo::get_namespace()const
{
	const char* repo_namespace = git_repository_get_namespace(c_git_repository_);
	if (FAILED(repo_namespace))
	{
		throw - 1;
	}
	return namespace_name_t(repo_namespace);
}

NMS::shared_ptr<Git_Branch> Git_Repo::head()const
{
	/*0 on success, GIT_EUNBORNBRANCH when HEAD points to a non existing branch, GIT_ENOTFOUND when HEAD is missing; an error code otherwise*/
	git_reference* git_branch_ref_out;
	auto res = git_repository_head(&git_branch_ref_out,c_git_repository_);
	if (!FAILED(res))
	{/*find that ref amongst those branches */
		auto aSharedPtr = find_branch_by_git_reference_(git_branch_ref_out);
		git_reference_free(git_branch_ref_out);
		return aSharedPtr;
	}
	else if (GIT_EUNBORNBRANCH == res)
	{/*non existing branch*/
		throw - 1;
	}
	else if (GIT_ENOTFOUND == res)
	{/*head is missing*/
		throw - 1;
	}
	else
	{
		throw - 1;
	}
}

NMS::shared_ptr<Git_Branch> Git_Repo::find_branch_by_git_reference_(git_reference*const c_git_branch_ref)const
{
	for (const auto& aSharedPtr : branches_)
	{
		if (aSharedPtr->guts() == c_git_branch_ref)
		{
			return aSharedPtr;
		}
	}

	return nullptr;
}