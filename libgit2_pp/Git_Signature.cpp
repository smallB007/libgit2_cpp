#include "Git_Signature.hpp"
#include "Git_Commit_Author.hpp"
#include "Git_Time.hpp"
#include "Git_Buf.hpp"

Git_Signature::Git_Signature(const git_signature* c_git_signature):c_git_signature_{c_git_signature}
{
}

Git_Signature::Git_Signature(git_buf* signature_block, git_buf* signed_data):signature_block_{signature_block}
																			,signed_data_{signed_data}
{

}


Git_Signature::~Git_Signature()
{
}

NMS::shared_ptr<Git_Commit_Author> Git_Signature::author()const
{
	return NMS::make_shared<Git_Commit_Author>(c_git_signature_);
}

NMS::string Git_Signature::name()const
{
	return c_git_signature_->name;
}

NMS::string Git_Signature::email()const
{
	return c_git_signature_->email;
}

NMS::shared_ptr<Git_Time> Git_Signature::time()const
{
	return NMS::make_shared<Git_Time>(c_git_signature_->when);
}

NMS::shared_ptr<Git_Buf> Git_Signature::signature_block()const
{
	return NMS::make_shared<Git_Buf>(signature_block_);
}

NMS::shared_ptr<Git_Buf> Git_Signature::signed_data()const
{
	return NMS::make_shared<Git_Buf>(signed_data_);
}