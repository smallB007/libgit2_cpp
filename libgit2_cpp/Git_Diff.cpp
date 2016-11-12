#include "Git_Diff.hpp"
#include "Git_Blob.hpp"
#include "Git_Buf.hpp"
#include "Git_Diff_Options.hpp"
#include "Git_Diff_Find_Options.hpp"
#include "Git_Diff_Delta.hpp"
#include "Git_Diff_Perfdata.hpp"
#include "Git_Diff_Stats.hpp"
#include "Git_Index.hpp"
#include "Git_Delta.hpp"
#include "Git_Tree.hpp"
Git_Diff::Git_Diff(git_diff *c_git_diff):Provider(c_git_diff,git_diff_free)
{
}

shared_ptr_t<Git_Buf> Git_Diff::diff_blob_to_buffer(const Git_Blob& gitBlob, 
												const string_t& old_blob_as_path, 
												const Git_Buf& gitBuf,
												const string_t& buffer_as_path, 
												const Git_Diff_Options& diff_options, Git_Diff_Callback_Pack callback_pack)
{
	

	check_for_error(git_diff_blob_to_buffer(gitBlob.c_guts(), old_blob_as_path.c_str(), reinterpret_cast<const char *>(gitBuf.head()),
					gitBuf.size(), buffer_as_path.c_str(), diff_options.c_guts(), callback_pack.file_cb_, callback_pack.binary_cb_, callback_pack.hunk_cb_, callback_pack.line_cb_, callback_pack.payload_));
	return shared_ptr_t<Git_Buf>();
#pragma message("ToDo return something here for the love of God Artie")
}

shared_ptr_t<Git_Buf> Git_Diff::diff_blobs(const Git_Blob& gitBlob_Old,
											const string_t& old_blob_as_path, 
											const Git_Blob& gitBlob_New,
											const string_t& new_blob_as_path,
											const Git_Diff_Options& diff_options, Git_Diff_Callback_Pack callback_pack)
{
	check_for_error(git_diff_blobs(gitBlob_Old.c_guts(), old_blob_as_path.c_str(), gitBlob_New.c_guts(), new_blob_as_path.c_str(),
					diff_options.c_guts(),
					callback_pack.file_cb_,
					callback_pack.binary_cb_,
					callback_pack.hunk_cb_,
					callback_pack.line_cb_,
					callback_pack.payload_));
	return shared_ptr_t<Git_Buf>();
#pragma message("ToDo return something here for the love of God Artie")

}

shared_ptr_t<Git_Buf> Git_Diff::diff_buffers(const Git_Buf & gitBuf_Old, const string_t & old_buffer_as_path, const Git_Buf & gitBuf_New, const string_t & new_buffer_as_path, const Git_Diff_Options & diff_options, Git_Diff_Callback_Pack callback_pack)
{
	check_for_error(git_diff_buffers(gitBuf_Old.c_guts(), gitBuf_Old.size(), old_buffer_as_path.c_str(),
					gitBuf_New.c_guts(), gitBuf_New.size(), new_buffer_as_path.c_str(), 
					diff_options.c_guts(),
					callback_pack.file_cb_, 
					callback_pack.binary_cb_, 
					callback_pack.hunk_cb_, 
					callback_pack.line_cb_, 
					callback_pack.payload_));
#pragma message("ToDo return something here for the love of God Artie")
	return shared_ptr_t<Git_Buf>();
}

void Git_Diff::find_similar(Git_Diff& gitDiff, const Git_Diff_Find_Options& gitDiffFingOptions)
{
	check_for_error(git_diff_find_similar(gitDiff.c_guts(), gitDiffFingOptions.c_guts()));
}

void Git_Diff::diff_foreach(const Git_Diff& gitDiff,const Git_Diff_Callback_Pack callback_pack)
{
	check_for_error(git_diff_foreach(gitDiff.c_guts(), callback_pack.file_cb_,
													   callback_pack.binary_cb_,
													   callback_pack.hunk_cb_,
													   callback_pack.line_cb_,
													   callback_pack.payload_));
}

#ifdef GIT_DIFF_FROM_BUFFER
shared_ptr_t<Git_Diff> Git_Diff::diff_from_buffer(const string_t & content) const
{
	git_diff* c_git_diff_out;
	check_for_error(git_diff_from_buffer(&c_git_diff_out, content.c_str(), content.size()));
	return shared_ptr_t<Git_Diff>();
}

#endif
Git_Diff_Delta Git_Diff::get_delta(const Git_Diff &diff, const size_t idx)const
{
	const git_diff_delta * c_git_delta = git_diff_get_delta(diff.c_guts(), idx);
	return *c_git_delta;
}

Git_Diff_Perfdata Git_Diff::get_perfdata(const Git_Diff & diff) const
{
	git_diff_perfdata c_git_diff_perfdata_out;
	check_for_error(git_diff_get_perfdata(&c_git_diff_perfdata_out, diff.c_guts_));
	return c_git_diff_perfdata_out;
}

shared_ptr_t<Git_Diff_Stats> Git_Diff::get_stats(const Git_Diff & diff) const
{
	git_diff_stats* c_git_diff_stats;
	check_for_error(git_diff_get_stats(&c_git_diff_stats, diff.c_guts_));
	return make_shared_ver<Git_Diff_Stats>(c_git_diff_stats);
}

shared_ptr_t<Git_Diff> Git_Diff::diff_index_to_index(const Git_Index & oldIndex, const Git_Index & newIndex, const Git_Diff_Options & diffOptions)
{
	git_diff* c_git_diff_out;

	check_for_error(git_diff_index_to_index(&c_git_diff_out, c_parent_guts(), oldIndex.c_guts(), newIndex.c_guts(), diffOptions.c_guts()));

	return make_shared_ver<Git_Diff>(c_git_diff_out);
}

shared_ptr_t<Git_Diff> Git_Diff::diff_index_to_workdir(const Git_Index & index, const Git_Diff_Options & diffOptions)
{
	git_diff* c_git_diff_out;

	check_for_error(git_diff_index_to_workdir(&c_git_diff_out, c_parent_guts(), index.c_guts(), diffOptions.c_guts()));

	return make_shared_ver<Git_Diff>(c_git_diff_out);
}

bool Git_Diff::is_sorted_icase(const Git_Diff & gitDiff) const
{
	return  1 == git_diff_is_sorted_icase(gitDiff.c_guts_);
}

shared_ptr_t<Git_Diff> Git_Diff::diff_merge(const Git_Diff & diffFrom)
{
	check_for_error(git_diff_merge(c_guts_, diffFrom.c_guts_));
	return make_shared_ver<Git_Diff>(c_guts_);
}

size_t Git_Diff::number_of_deltas(const Git_Diff & gitDiff) const
{
	return git_diff_num_deltas(gitDiff.c_guts_);
}

size_t Git_Diff::number_of_deltas_of_type(const Git_Diff & gitDiff, const Git_Delta & gitDelta) const
{
	return git_diff_num_deltas_of_type(gitDiff.c_guts_, *(gitDelta.c_guts()));
}

size_t Git_Diff::deletions() const
{
	auto stats = get_stats(*this);
	
	return git_diff_stats_deletions(stats->c_guts());
}

size_t Git_Diff::files_changed() const
{
	auto stats = get_stats(*this);

	return git_diff_stats_files_changed(stats->c_guts());
}

size_t Git_Diff::insertions() const
{
	auto stats = get_stats(*this);

	return git_diff_stats_insertions(stats->c_guts());
}

shared_ptr_t<Git_Buf> Git_Diff::stats_to_buf(git_diff_stats_format_t statsFormat, size_t width) const
{
#pragma message("ToDo native libgit2 enum used")
	git_buf c_git_buf_out;
	auto stats = get_stats(*this);

check_for_error(git_diff_stats_to_buf(&c_git_buf_out, stats->c_guts(), statsFormat, width));
	return make_shared_ver<Git_Buf>(std::move(c_git_buf_out));
#pragma messate("Error this is highly doubious")
}

char Git_Diff::status_char(git_delta_t status) const
{
#pragma message("ToDo native libgit2 enum used")

	return git_diff_status_char(status);
}

#ifdef GIT_DIFF_TO_BUFFER
shared_ptr_t<Git_Buf> Git_Diff::diff_to_buf(const Git_Diff & diff, git_diff_format_t format) const
{
#pragma message("ToDo native libgit2 enum used")

	git_buf* c_git_buf_out;
	check_for_error(git_diff_to_buf(&c_git_buf_out, diff.c_guts_, format));
	return make_shared_ver<Git_Buf>(c_git_buf_out);
}
#endif

shared_ptr_t<Git_Diff> Git_Diff::diff_tree_to_index(const Git_Tree& oldTree,const Git_Index& index, const Git_Diff_Options& diffOptions) const
{
	git_diff* c_git_diff_out;
	check_for_error(git_diff_tree_to_index(&c_git_diff_out, c_parent_guts(), oldTree.c_guts(), index.c_guts(), diffOptions.c_guts()));
	return make_shared_ver<Git_Diff>(c_git_diff_out);
}

shared_ptr_t<Git_Diff> Git_Diff::diff_tree_to_tree(const Git_Tree & oldTree, const Git_Tree & newTree, const Git_Diff_Options & diffOptions) const
{
	git_diff* c_git_diff_out;

	check_for_error(git_diff_tree_to_tree(&c_git_diff_out, c_parent_guts(), oldTree.c_guts(), newTree.c_guts(), diffOptions.c_guts()));

	return make_shared_ver<Git_Diff>(c_git_diff_out);
}

shared_ptr_t<Git_Diff> Git_Diff::diff_tree_to_workdir(const Git_Tree & oldTree, const Git_Diff_Options & diffOptions) const
{
	git_diff* c_git_diff_out;

	check_for_error(git_diff_tree_to_workdir(&c_git_diff_out, c_parent_guts(), oldTree.c_guts(), diffOptions.c_guts()));
	
	return make_shared_ver<Git_Diff>(c_git_diff_out);
}

shared_ptr_t<Git_Diff> Git_Diff::diff_tree_to_workdir_with_index(const Git_Tree & oldTree, const Git_Diff_Options & diffOptions) const
{
	git_diff* c_git_diff_out;

	check_for_error(git_diff_tree_to_workdir_with_index(&c_git_diff_out, c_parent_guts(), oldTree.c_guts(), diffOptions.c_guts()));
	
	return make_shared_ver<Git_Diff>(c_git_diff_out);
}
