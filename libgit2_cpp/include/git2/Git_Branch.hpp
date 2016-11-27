#pragma once
#include "precompiled.hpp"
//#include "Provider.hpp"

class LIBGIT2_CPP_API Git_Branch : public Provider<git_reference>
{
	DECLARE_CREATION_AND_DESTRUCTION_PRIVILEGES
private:
	Git_Branch(git_reference*);
	Git_Branch(const branch_name_t& branch_name, bool force = false);
#ifdef _DEBUG
	~Git_Branch()
	{
		std::cout << "~Git_Branch\n";
	}
#endif

	set_t<shared_ptr_t<Git_Commit>> commits_;

	git_repository* get_owner_()const;
	
	void move_(const branch_name_t& new_branch_name, bool force = true);
public:
	shared_ptr_t<Git_Commit> create_commit();

LIBGIT2_BRANCH_INTERFACE
	bool is_head()const;
	void rename(const branch_name_t& new_branch_name);
	void move(const branch_name_t& new_branch_name);
	branch_name_t name()const;
	
private:	

public:
	decltype(commits_)::iterator begin()const;
	decltype(commits_)::iterator end()const;

#ifdef _FULL_IMPLEMENTATION_
	git_branch_set_upstream
		git_branch_upstream
		git_branch_create_from_annotated->in Git_Repo
#endif
};
