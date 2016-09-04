#pragma once
#include "stdafx.h"
class Git_Repo;
class Git_Commit_Author;
class Git_Signature;
class Git_Commit_ID;
class Git_Object_ID;
class Git_Time;
class Git_Tree;

class Git_Commit
{
	git_commit* c_git_commit_{nullptr};
	const Git_Repo* m_parent_repo_{nullptr};
private:
	git_commit* get_head_commit_()const;
public:
	Git_Commit(const Git_Repo*const parent, const std::vector<std::string>& files_to_commit, const std::string& msg);
	Git_Commit(const Git_Repo*const,git_commit*);
	~Git_Commit();
	std::vector<git_commit*> get_parents()const;
	operator git_commit*() { return c_git_commit_; }
	/*LIBGIT2 INTERFACE*/
	
	std::shared_ptr<Git_Commit_Author> author()const;
	std::string body()const;
	std::shared_ptr<Git_Signature> commiter()const;
#ifdef _FULL_IMPLEMENTATION_
		void amend();
		git_commit_create_buffer
		git_commit_create_from_callback
		git_commit_create_v
		git_commit_create_with_signature
		std::shared_ptr<Git_Commit> duplicate()const;
		git_commit_header_field
		git_commit_message_encoding
		git_commit_message_raw
#endif
		
	std::shared_ptr<Git_Signature> signature()const;
	std::shared_ptr<Git_Commit_ID> id()const;
	
	std::string message()const;
	std::shared_ptr<Git_Commit> nth_gen_ancestor(const unsigned nth_generation)const;
	std::shared_ptr<Git_Repo> owner()const;
	std::shared_ptr<Git_Commit> parent(const unsigned parent_pos = 0)const;
	std::shared_ptr<Git_Object_ID> parent_id(const unsigned parent_pos = 0)const;
	unsigned parent_count()const;
	std::string raw_header()const;
	std::string summary()const;
	std::shared_ptr<Git_Time> time()const;
	int time_offset()const;
	std::shared_ptr<Git_Tree> tree()const;
	std::shared_ptr<Git_Object_ID> tree_id()const;
};

