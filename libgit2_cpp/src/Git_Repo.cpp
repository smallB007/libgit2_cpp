#include "Git_Repo.hpp"

#include "Copied_From_libgit2.hpp"
#include "Git_Branch.hpp"
#include "Git_Checkout.hpp"
#include "Git_Commit_ID.hpp"
#include "Git_Config.hpp"
#include "Git_Index.hpp"
#include "Git_ODB.hpp"
#include "Git_RefDB.hpp"
#include "Git_Signature.hpp"
#include "Git_Commit.hpp"
#include "Git_CherryPick_Options.hpp"
#include "Git_Clone_Options.hpp"
/*Proper CADRe - [C]onstructor [A]cquires, [D]estructor [Re]leses*/
Git_Repo::Git_Repo(/*git_repository* c_git_repository,*/const string_t& path_to_repo, const bool is_bare) :Provider(c_guts_, git_repository_free)
{
	check_for_error(git_repository_init(&c_guts_, path_to_repo.c_str(), static_cast<unsigned int>(is_bare)));
	//repo_path_ = path_to_repo;
}

Git_Repo::Git_Repo(git_repository* c_git_repository) :Provider(c_git_repository, git_repository_free)
{
}

void Git_Repo::create_initial_commit_()
{
	create_initial_commit(c_guts_);
	git_reference* git_branch_ref_out;
	check_for_error(git_repository_head(&git_branch_ref_out, c_guts_));

	shared_ptr_t<Git_Branch> master_branch = Factory_Git_Object<Git_Branch>::create_ptr(git_branch_ref_out);
	branches_.insert(master_branch);
}

const shared_ptr_t<Git_Commit> Git_Repo::get_head_commit()const
{
	git_oid git_oid_out;
	check_for_error(git_reference_name_to_id(&git_oid_out, c_guts_, "HEAD"));

	git_commit* git_commit_out{ nullptr };
	check_for_error(git_commit_lookup(&git_commit_out, c_guts_, &git_oid_out));

	return Factory_Git_Object<Git_Commit>::create_ptr(git_commit_out);
}

vector_t<string_t> Git_Repo::get_files_to_commit()
{
	return vector_t<string_t>();
#pragma message("ToDo fix that")
}

string_t Git_Repo::get_msg_to_commit()
{
	return string_t();
#pragma message("ToDo fix that")
}

string_t Git_Repo::get_current_branch()
{
	return string_t();
#pragma message("ToDo fix that")
}

pair_t<bool,shared_ptr_t<Git_Branch>> Git_Repo::find_branch(const string_t& branch_name)const
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

shared_ptr_t<Git_Branch> Git_Repo::create_branch(const string_t& branch_name)
{
	auto result = find_branch(branch_name);
	/*Check if branch with that name already find_branch and if not create it*/
	if (!result.first)
	{
		shared_ptr_t<Git_Branch> new_branch = Factory_Git_Object<Git_Branch>::create_ptr(branch_name);
		branches_.insert(new_branch);
		return new_branch;
	}
	else
	{
		return result.second;
	}
}

void Git_Repo::delete_branch(const string_t& branch_name)
{
	auto aPair = find_branch(branch_name);
	if (aPair.first)
	{
		check_for_error(git_branch_delete(*(aPair.second.get())));
		
		branches_.erase(aPair.second);
		
	}
}



bool Git_Repo::is_my_path(const string_t& path_to_some_repo)const
{
	const char* const c_path = git_repository_path(c_guts_);
	return (0 == strcmp(path_to_some_repo.c_str(),c_path));
}

//void Git_Repo::rename(const NMS::string& repo_name)
//{
//	repo_path_ = repo_name;
//}


//shared_ptr_t<Git_Branch> Git_Repo::get_branch(const string_t& branch_name)const
//{
//	return nullptr;
//}

const shared_ptr_t<Git_Commit> Git_Repo::commit_lookup(const Git_Commit_ID& commit_id)const
{/*Most likely here it is better to simply look through commits in branches but who knows?
 possibly if they are in unordered set and placed into buckets by oid?
 */
	git_commit* commit_out{ nullptr };
	auto res = git_commit_lookup(&commit_out, c_guts_, commit_id.c_guts());
	if(LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
	else
	{
		return Factory_Git_Object<Git_Commit>::create_ptr(commit_out);
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

shared_ptr_t<Git_Branch> Git_Repo::branch_lookup(const string_t& branch_name, git_branch_t branch_type)const
{
	//UNUSED(branch_type);
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
	//auto res = git_branch_lookup(&git_reference_branch_out, c_guts_, branch_name.c_str(),branch_type);
	//if (LIBGIT2_CPP_FAIL_CHECK(res))
	//{
	//	throw - 1;
	//}
	//return make_shared_ver<Git_Branch>(git_reference_branch_out);
}

void Git_Repo::checkout_head() const
{
	Git_Checkout checkout;
	checkout.head();
}

void Git_Repo::checkout_index() const
{
	Git_Checkout checkout;
	checkout.index();
}

void Git_Repo::checkout_tree() const
{
	Git_Checkout checkout;
	checkout.tree();
}

void Git_Repo::cherrypick(const Git_Commit& commit, const Git_CherryPick_Options& cherrypick_options)
{
	check_for_error(git_cherrypick(c_guts_, 
								commit.c_guts() , 
								cherrypick_options.c_guts()));
}

LIBGIT2_CLONE_INTERFACE shared_ptr_t<Git_Repo> Git_Repo::clone(const string_t & remote_repo_path, const string_t & local_target_dir, const Git_Clone_Options & clone_options) const
{
	git_repository* c_git_repo_out{};
	check_for_error( git_clone(&c_git_repo_out,remote_repo_path.c_str(), local_target_dir.c_str(), clone_options.c_guts()));
	shared_ptr_t<Git_Repo> repo_dud = Factory_Git_Object<Git_Repo>::create_ptr(c_git_repo_out);
#pragma message("ToDo make sure that this works as intended, that is the clone of the repo is correct one and doesn't need to be created/written on hdd etc")
#pragma message("ToDo it would be nice from the safety perspective that only factory could create object")
	return repo_dud;
}

void Git_Repo::cleanup()
{
	git_repository__cleanup(c_guts_);
}

shared_ptr_t<Git_Config> Git_Repo::config()const
{
	git_config* config_out;
	auto res = git_repository_config(&config_out,c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
	return make_shared_ver<Git_Config>(config_out);
}

shared_ptr_t<Git_Config> Git_Repo::config_snapshot()const
{
	git_config* config_snapshot_out;
	auto res = git_repository_config_snapshot(&config_snapshot_out, c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
	return make_shared_ver<Git_Config>(config_snapshot_out);
}

string_t Git_Repo::discover(const string_t start_path)const
{
	git_buf buf = GIT_BUF_INIT_CONST(NULL, 0);
	auto res = git_repository_discover(&buf, start_path.c_str(), 0, NULL);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
	string_t repo_path = buf.ptr;
	return repo_path;
}

string_t Git_Repo::get_namespace()const
{
	const char* repo_namespace = git_repository_get_namespace(c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(repo_namespace))
	{
		throw - 1;
	}
	return string_t(repo_namespace);
}

shared_ptr_t<Git_Branch> Git_Repo::head()const
{
	/*0 on success, GIT_EUNBORNBRANCH when HEAD points to a non existing branch, GIT_ENOTFOUND when HEAD is missing; an error code otherwise*/
	git_reference* c_git_branch_ref_out;
	auto res = git_repository_head(&c_git_branch_ref_out,c_guts_);
	if (!LIBGIT2_CPP_FAIL_CHECK(res))
	{/*find that ref amongst those branches */
		auto aSharedPtr = find_branch_by_c_git_reference_(c_git_branch_ref_out);
		git_reference_free(c_git_branch_ref_out);
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

shared_ptr_t<Git_Branch> Git_Repo::find_branch_by_c_git_reference_(git_reference*const c_git_branch_ref)const
{
	for (const auto& aSharedPtr : branches_)
	{
		if (aSharedPtr->c_guts() == c_git_branch_ref)
		{
			return aSharedPtr;
		}
	}

	return nullptr;
}

bool Git_Repo::is_head_detached()const
{//1 if HEAD is detached, 0 if it's not; error code if there was an error.
	auto res = git_repository_head_detached(c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}

	return res;
}

bool Git_Repo::is_head_unborn()const
{//1 if the current branch is unborn, 0 if it's not; error code if there was an error
	auto res = git_repository_head_unborn(c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}

	return res;
}

shared_ptr_t<Git_Commit_Author> Git_Repo::identitiy() const
{//The memory is owned by the repository and must not be freed by the user.
	const char* name_out;
	const char* email_out;
	auto res = git_repository_ident(&name_out, &email_out, c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}

	return nullptr;
}

shared_ptr_t<Git_Index> Git_Repo::index()const
{
	git_index* c_git_index_out;
	auto res = git_repository_index(&c_git_index_out,c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}

	return make_shared_ver<Git_Index>(c_git_index_out);
}

bool Git_Repo::is_bare()const
{
	int is_repo_bare = git_repository_is_bare(c_guts_);
	return is_repo_bare;
}

bool Git_Repo::is_empty()const
{
	auto res = git_repository_is_empty(c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}

	return res;
}

bool Git_Repo::is_shallow()const
{
	int res = git_repository_is_shallow(c_guts_);

	return res;
}

shared_ptr_t<Git_ODB> Git_Repo::odb()const
{
	git_odb* tmp;
#pragma message("Error Fix that")
	return make_shared_ver<Git_ODB>(tmp);
}

string_t Git_Repo::path() const
{
	return git_repository_path(c_guts_);
}

shared_ptr_t<Git_RefDB> Git_Repo::ref_db() const
{
	return make_shared_ver<Git_RefDB>(c_guts_);
}

void Git_Repo::set_bare()
{
	int res = git_repository_set_bare(c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
	git_repository_set_index(c_guts_, NULL);
}

void Git_Repo::set_config(const Git_Config& config)
{
	git_repository_set_config(c_guts_, config.c_guts());
}

void Git_Repo::set_identity(const Git_Signature& signature)
{
	int res = git_repository_set_ident(c_guts_, signature.name().c_str(), signature.email().c_str());
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
}

void Git_Repo::set_index(const Git_Index& index)
{
	git_repository_set_index(c_guts_, index);
}

void Git_Repo::set_namespace(const string_t& namespace_name)
{
	int res = git_repository_set_namespace(c_guts_, namespace_name.c_str());
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
}

void Git_Repo::set_odb(const Git_ODB& odb)
{
	git_repository_set_odb(c_guts_, odb.c_guts());
}

void Git_Repo::set_ref_db(const Git_RefDB & ref_db)
{
	git_repository_set_refdb(c_guts_, ref_db);
}

void Git_Repo::set_working_dir(const string_t & working_dir, bool update_gitlink)
{
	int res = git_repository_set_workdir(c_guts_, working_dir.c_str(), update_gitlink);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
}

const string_t Git_Repo::get_working_dir() const
{
	if (is_bare())
	{
		return string_t();
	}
	else
	{
		const char * working_dir = git_repository_workdir(c_guts_);
		return working_dir;
	}
}

git_repository_state_t Git_Repo::get_state() const
{
	auto res = git_repository_state(c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
	return static_cast<git_repository_state_t>(res);
}

void Git_Repo::cleanup_state()
{
	int res = git_repository_state_cleanup(c_guts_);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
}

void Git_Repo::unset_identity()
{
	int res = git_repository_set_ident(c_guts_, NULL, NULL);
	if (LIBGIT2_CPP_FAIL_CHECK(res))
	{
		throw - 1;
	}
}
