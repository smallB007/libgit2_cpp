#include "Git_Message.hpp"



Git_Message::Git_Message(git_repository* c_git_repo):c_git_repo_{c_git_repo}
{
	auto res = git_repository_message(c_git_buf_, c_git_repo_);
	if (GIT_ENOTFOUND == res)
	{
		throw - 1;
	}
	else if (FAILED(res))
	{
		throw - 1;
	}

}


Git_Message::~Git_Message()
{
	/*do we need to free git_buf?*/
	git_repository_message_remove(c_git_repo_);
	c_git_repo_ = nullptr;
}
