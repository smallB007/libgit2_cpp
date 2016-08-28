// libgit2_pp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Git_Root.hpp"

int main()
{
		auto git = create_git();
		auto git1 = create_git();
		auto repo = git->create_repository("C:\\Users\\Artie\\Desktop\\tmp_repo", false);
		repo->get_master_branch();
		auto branch = repo->create_branch("branch_A");
		auto commit = branch->create_commit();
		auto author = commit->author();
		auto body = commit->body();
		auto msg = commit->message();
		
	destroy_git();
    return 0;
}

