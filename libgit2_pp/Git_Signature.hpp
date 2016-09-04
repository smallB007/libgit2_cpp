#pragma once
#include "stdafx.h"
class Git_Commit_Author;
class Git_Time;
class Git_Buf;
class Git_Signature
{
	const git_signature* c_git_signature_{nullptr};

	git_buf* signature_block_{nullptr};//the signature block
	git_buf* signed_data_{nullptr};

public:
	Git_Signature(const git_signature* c_git_signature);
	Git_Signature(git_buf* signature_block, git_buf* signed_data);
	~Git_Signature();
	NMS::shared_ptr<Git_Commit_Author> author()const;
	NMS::string name()const;
	NMS::string email()const;
	NMS::shared_ptr<Git_Time> time()const;
	NMS::shared_ptr<Git_Buf> signature_block()const;
	NMS::shared_ptr<Git_Buf> signed_data()const;
};

