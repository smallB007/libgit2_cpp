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
	NMS::shared_ptr<Git_Commit_Author> author()const;
	NMS::string body()const;
	NMS::shared_ptr<Git_Signature> commiter()const;
	NMS::shared_ptr<Git_Commit_ID> id()const;

		
	NMS::shared_ptr<Git_Signature> signature()const;
	
	NMS::string message()const;
	NMS::shared_ptr<Git_Commit> nth_gen_ancestor(const unsigned nth_generation)const;
	NMS::shared_ptr<Git_Repo> owner()const;
	NMS::shared_ptr<Git_Commit> parent(const unsigned parent_pos = 0)const;
	NMS::shared_ptr<Git_Object_ID> parent_id(const unsigned parent_pos = 0)const;
	unsigned parent_count()const;
	NMS::string raw_header()const;
	NMS::string summary()const;
	NMS::shared_ptr<Git_Time> time()const;
	int time_offset()const;
	NMS::shared_ptr<Git_Tree> tree()const;
	NMS::shared_ptr<Git_Object_ID> tree_id()const;

#ifdef _FULL_IMPLEMENTATION_
	void amend();
	git_commit_create_buffer
		git_commit_create_from_callback
		git_commit_create_v
		git_commit_create_with_signature
		NMS::shared_ptr<Git_Commit> duplicate()const;
	git_commit_header_field
		git_commit_message_encoding
		git_commit_message_raw
#endif
};

