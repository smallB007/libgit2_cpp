#pragma once
#include "stdafx.h"
class Git_Annotated_Commit;
class Git_Merge_File_Input;
class Git_Merge_File_Result;
class Git_Merge_File_Options;

class MergingEngine : public Parent_Provider
{
public:
	static void merge(const vector_t<Git_Annotated_Commit>& theirHeads, const Git_Merge_Options& mergeOpts, const Git_Checkout_Options& checkoutOpts);
	static git_merge_analysis_t merge_analysis(git_merge_preference_t& preference_out, const vector_t<Git_Annotated_Commit>& theirHeads);
	static shared_ptr_t<Git_Object_ID> MergingEngine::merge_base(const Git_Object_ID& first, const Git_Object_ID& second);
	static vector_t<shared_ptr_t<Git_Object_ID>> MergingEngine::merge_bases(const Git_Object_ID & first, const Git_Object_ID & second);
	static shared_ptr_t<Git_Index> merge_commits(const Git_Commit&, const Git_Commit&,const Git_Merge_Options&);
	static shared_ptr_t<Git_Merge_File_Result> merge_file(const Git_Merge_File_Input&, const Git_Merge_File_Input&, const Git_Merge_File_Input&,const Git_Merge_File_Options&);
	static shared_ptr_t<Git_Merge_File_Result> merge_file_from_index(const Git_Index_Entry&, const Git_Index_Entry&, const Git_Index_Entry&, const Git_Merge_File_Options&);
	static shared_ptr_t<Git_Index> merge_trees(const Git_Tree&, const Git_Tree&, const Git_Tree&,const Git_Merge_Options&);
#ifdef _FULL_IMPLEMENTATION_
	git_merge_base_many
		git_merge_base_octopus
		git_merge_bases_many
#endif
};

