#include "Git_Signature.hpp"
#include "Git_Commit_Author.hpp"
#include "Git_Commit_Time.hpp"


Git_Signature::Git_Signature(const git_signature* c_git_signature):c_git_signature_{c_git_signature}
{
}


Git_Signature::~Git_Signature()
{
}

std::shared_ptr<Git_Commit_Author> Git_Signature::author()const
{
	return std::make_shared<Git_Commit_Author>(c_git_signature_);
}

std::string Git_Signature::email()const
{
	return c_git_signature_->email;
}

std::shared_ptr<Git_Commit_Time> Git_Signature::time()const
{
	return std::make_shared<Git_Commit_Time>(c_git_signature_->when);
}