#pragma once
#include "precompiled.hpp"

//#include "Singleton.hpp"
#include "Git_Repo.hpp"
//find a way to name a repo
/***
VERY, VERY IMPORTANT
Unless the docs specifically say otherwise, any non-const pointer that’s filled in by libgit2 needs to be freed by the caller.
*/

//class Git_Root;

//extern Git_Root* git_root_inst_;

class LIBGIT2_CPP_API Git_Root
{
	//friend LIBGIT2_CPP_API Git_Root* create_git();
	shared_ptr_t<Git_Repo> active_repo_;
	vector_t<shared_ptr_t<Git_Repo>> repositories_;

public:
	shared_ptr_t<Git_Repo> get_active_repo()const;
	void set_active_repo(shared_ptr_t<Git_Repo>);
	static Git_Root* GetInstance()
	{
		static Git_Root git_root;

		return &git_root;
		//return git_root_inst_;
	}
	void DeleteInstance()
	{
#pragma message("Warning hack in order to have destructor of libgit called from Client")
		delete this;
	}
private:
~Git_Root();
Git_Root();
	shared_ptr_t<Git_Repo> find_c_git_repository(git_repository*)const;
public:
	const auto get_repositories()const;
	LIBGIT2_REPO_INTERFACE
	shared_ptr_t<Git_Repo> create_repository(const string_t& path_to_repo, const bool is_bare);
	shared_ptr_t<Git_Repo> open_repository(const std::string_view& path_to_repo);
	string_t discover(const std::string_view& start_path)const;

};

/***
Creation 
*/
//LIBGIT2_CPP_API Git_Root* create_git();



