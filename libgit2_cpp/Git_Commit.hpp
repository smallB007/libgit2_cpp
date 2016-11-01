#pragma once
#include "stdafx.h"
#include "Provider.hpp"

class Git_Commit : public Provider<git_commit>
{
private:
	
public:
	Git_Commit(const NMS::vector<NMS::string>& files_to_commit, const NMS::string& msg);
	Git_Commit(git_commit*);
	
	NMS::vector<git_commit*> get_parents()const;

LIBGIT2_COMMIT_INTERFACE
	shared_ptr_t<Git_Commit_Author> author()const;
	NMS::string body()const;
	shared_ptr_t<Git_Signature> commiter()const;
	shared_ptr_t<Git_Commit_ID> id()const;

		
	shared_ptr_t<Git_Signature> signature()const;
	
	NMS::string message()const;
	shared_ptr_t<Git_Commit> nth_gen_ancestor(const unsigned nth_generation)const;
	shared_ptr_t<Git_Repo> owner()const;
	shared_ptr_t<Git_Commit> parent(const unsigned parent_pos = 0)const;
	shared_ptr_t<Git_Object_ID> parent_id(const unsigned parent_pos = 0)const;
	unsigned parent_count()const;
	NMS::string raw_header()const;
	NMS::string summary()const;
	shared_ptr_t<Git_Time> time()const;
	int time_offset()const;
	shared_ptr_t<Git_Tree> tree()const;
	shared_ptr_t<Git_Object_ID> tree_id()const;

#ifdef _FULL_IMPLEMENTATION_
	void amend();
	git_commit_create_buffer
		git_commit_create_from_callback
		git_commit_create_v
		git_commit_create_with_signature
		shared_ptr_t<Git_Commit> duplicate()const;
	git_commit_header_field
		git_commit_message_encoding
		git_commit_message_raw
#endif
};

