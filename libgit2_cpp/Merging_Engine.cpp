#include "Merging_Engine.hpp"
#include "Git_Repo.hpp"
#include "Git_Annotated_Commit.hpp"
#include "Git_Merge_Options.hpp"
#include "Git_Checkout_Options.hpp"
#include "Git_Object_ID.hpp"
#include "Git_Commit.hpp"
#include "Git_Index.hpp"
#include "Git_Merge_File_Input.hpp"
#include "Git_Merge_File_Result.hpp"
#include "Git_Merge_File_Options.hpp"
#include "Git_Index_Entry.hpp"
#include "Git_Tree.hpp"
#include "Converters.hpp"


void Merging_Engine::merge(const vector_t<Git_Annotated_Commit>& theirHeads,const Git_Merge_Options& mergeOpts, const Git_Checkout_Options& checkoutOpts)
{
	/*For compatibility with git, the repository is put into a merging state. 
	Once the commit is done (or if the uses wishes to abort), you should clear this state by calling git_repository_state_cleanup()*/
	const git_annotated_commit * c_git_annotated_commit_array =	(convert_to_libgit2_type(theirHeads))[0];
	check_for_error(git_merge(parent_->c_guts(), &c_git_annotated_commit_array, std::size(theirHeads), mergeOpts.c_guts() , checkoutOpts.c_guts()));
}

git_merge_analysis_t Merging_Engine::merge_analysis(git_merge_preference_t& preference_out, const vector_t<Git_Annotated_Commit>& theirHeads)
{
	git_merge_analysis_t c_git_merge_analysis_out;
	const git_annotated_commit * c_git_annotated_commit_array = (convert_to_libgit2_type(theirHeads))[0];
	check_for_error(git_merge_analysis(&c_git_merge_analysis_out, &preference_out, parent_->c_guts(), &c_git_annotated_commit_array, std::size(theirHeads)));
	
	return c_git_merge_analysis_out;
}

shared_ptr_t<Git_Object_ID> Merging_Engine::merge_base(const Git_Object_ID& first, const Git_Object_ID& second)
{
	git_oid c_git_oid_out;
	check_for_error(git_merge_base(&c_git_oid_out, parent_->c_guts(), first.c_guts(), second.c_guts()));
	
	return shared_ptr_t<Git_Object_ID>();
}

vector_t<shared_ptr_t<Git_Object_ID>> Merging_Engine::merge_bases(const Git_Object_ID & first, const Git_Object_ID & second)
{
	git_oidarray c_git_oidarray_out;
	check_for_error(git_merge_bases(&c_git_oidarray_out, parent_->c_guts(), first.c_guts(), second.c_guts()));
	vector_t<shared_ptr_t<Git_Object_ID>> result;
	for (size_t beg{ 0 }, end{ c_git_oidarray_out.count }; beg != end; ++beg)
	{
		result.push_back(make_shared_ver<Git_Object_ID>(c_git_oidarray_out.ids[beg]));
	}

	return result;
}

shared_ptr_t<Git_Index> Merging_Engine::merge_commits(const Git_Commit & ourCommit, const Git_Commit & theirCommit, const Git_Merge_Options & mergeOpts)
{
	git_index* c_git_index_out{};
	check_for_error(git_merge_commits(&c_git_index_out, parent_->c_guts(), ourCommit.c_guts(), theirCommit.c_guts(), mergeOpts.c_guts()));

	return make_shared_ver<Git_Index>(c_git_index_out);
}

shared_ptr_t<Git_Merge_File_Result> Merging_Engine::merge_file(const Git_Merge_File_Input & ancestor, const Git_Merge_File_Input & ours, const Git_Merge_File_Input & theirs, const Git_Merge_File_Options & mergeFileOpts)
{
	git_merge_file_result* c_git_merge_file_result_out{};
	check_for_error(git_merge_file(c_git_merge_file_result_out, ancestor.c_guts(), ours.c_guts(), theirs.c_guts(), mergeFileOpts.c_guts()));

	return make_shared_ver<Git_Merge_File_Result>(c_git_merge_file_result_out);
}

shared_ptr_t<Git_Merge_File_Result> Merging_Engine::merge_file_from_index(const Git_Index_Entry & ancestor, const Git_Index_Entry & ours, const Git_Index_Entry & theirs, const Git_Merge_File_Options &mergeFileOpts)
{
	git_merge_file_result* c_git_merge_file_result_out{};
	check_for_error(git_merge_file_from_index(c_git_merge_file_result_out, parent_->c_guts(), ancestor.c_guts(), ours.c_guts(), theirs.c_guts(), mergeFileOpts.c_guts()));

	return make_shared_ver<Git_Merge_File_Result>(c_git_merge_file_result_out);
}

shared_ptr_t<Git_Index> Merging_Engine::merge_trees(const Git_Tree & ancestorTree, const Git_Tree &ourTree, const Git_Tree & theirTree, const Git_Merge_Options &mergeOpts)
{
	git_index* c_git_index_out{};
	check_for_error(git_merge_trees(&c_git_index_out, parent_->c_guts(), ancestorTree.c_guts(), ourTree.c_guts(), theirTree.c_guts(), mergeOpts.c_guts()));

	return make_shared_ver<Git_Index>(c_git_index_out);
}
