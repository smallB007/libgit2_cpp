#include "Git_Commit_Author.hpp"



Git_Commit_Author::Git_Commit_Author(const git_signature* c_git_signature) :c_git_signature_{c_git_signature}
{
}


Git_Commit_Author::~Git_Commit_Author()
{
}
 

NMS::string Git_Commit_Author::name()const
{
	return c_git_signature_->name;
}

NMS::string Git_Commit_Author::email()const
{
	return c_git_signature_->email;
}