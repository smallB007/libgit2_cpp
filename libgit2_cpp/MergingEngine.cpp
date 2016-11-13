#include "MergingEngine.hpp"
#include "Git_Repo.hpp"
void MergingEngine::merge()
{
	/*For compatibility with git, the repository is put into a merging state. 
	Once the commit is done (or if the uses wishes to abort), you should clear this state by calling git_repository_state_cleanup()*/
	//check_for_error(git_merge(parent_->c_guts(), const git_annotated_commit **their_heads, size_t their_heads_len, const git_merge_options *merge_opts, const git_checkout_options *checkout_opts));
}
