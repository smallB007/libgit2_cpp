#include "Git_Message.hpp"



Git_Message::Git_Message(git_repository* c_git_repo):c_git_repo_{c_git_repo}
{
	check_for_error(git_repository_message(c_git_buf_, c_git_repo_));
}


Git_Message::~Git_Message()
{
	/*do we need to free git_buf?*/
	git_repository_message_remove(c_git_repo_);
	c_git_repo_ = nullptr;
	git_buf_free(c_git_buf_);
	c_git_buf_ = nullptr;
#pragma message("Warning Why is this done manually?")
}
