#include "Git_Transaction.hpp"

Git_Transaction::Git_Transaction():Provider(git_transaction_free)
{
	git_transaction_new(&c_git_guts_,c_parent_guts());
}
