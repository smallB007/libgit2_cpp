#include "Git_Commit_Author.hpp"



Git_Commit_Author::Git_Commit_Author(const git_signature* c_git_signature) :c_git_signature_{c_git_signature}
																							 ,should_free_{false}
{
}

Git_Commit_Author::Git_Commit_Author(const char* name, const char* email):should_free_{true}
{
	git_signature* c_git_signature_out;
	git_signature_now(&c_git_signature_out, name, email);
	c_git_signature_ = c_git_signature_out;
}

Git_Commit_Author::~Git_Commit_Author()
{
	if (should_free_)
	{
		git_signature_free(const_cast<git_signature*>(c_git_signature_));
		c_git_signature_ = nullptr;
	}
}
 

NMS::string Git_Commit_Author::name()const
{
	return c_git_signature_->name;
}

NMS::string Git_Commit_Author::email()const
{
	return c_git_signature_->email;
}