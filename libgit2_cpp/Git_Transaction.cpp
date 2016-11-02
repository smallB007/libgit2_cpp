#include "Git_Transaction.hpp"

Git_Transaction::Git_Transaction(git_transaction* c_git_transaction):Provider(c_git_transaction,git_transaction_free)
{
	git_transaction_new(&c_git_guts_,c_parent_guts());
}
