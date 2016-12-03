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
	git_buf_free(signature_block_);
	git_buf_free(signed_data_);
#pragma message("ToDo why this is done manually?")
}

shared_ptr_t<Git_Commit_Author> Git_Signature::author()const
{
	return make_shared_ver<Git_Commit_Author>(c_git_signature_);
}

NMS::string Git_Signature::name()const
{
	return c_git_signature_->name;
}

NMS::string Git_Signature::email()const
{
	return c_git_signature_->email;
}

shared_ptr_t<Git_Time> Git_Signature::time()const
{
	return make_shared_ver<Git_Time>(c_git_signature_->when);
}

shared_ptr_t<Git_Buf> Git_Signature::signature_block()const
{
	return make_shared_ver<Git_Buf>(signature_block_);
}

shared_ptr_t<Git_Buf> Git_Signature::signed_data()const
{
	return make_shared_ver<Git_Buf>(signed_data_);
}