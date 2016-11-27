#pragma once
#include "precompiled.hpp"

class Git_Signature
{
	const git_signature* c_git_signature_{nullptr};

	git_buf* signature_block_{};
	git_buf* signed_data_{};
#pragma message("ToDo review this design")
public:
	Git_Signature(const git_signature* c_git_signature);
	Git_Signature(git_buf* signature_block, git_buf* signed_data);
	~Git_Signature();
	shared_ptr_t<Git_Commit_Author> author()const;
	NMS::string name()const;
	NMS::string email()const;
	shared_ptr_t<Git_Time> time()const;
	shared_ptr_t<Git_Buf> signature_block()const;
	shared_ptr_t<Git_Buf> signed_data()const;
};

